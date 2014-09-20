/// @file Hg.h
/// 
/// Contains the Hg (Mercury) Message template definition.
/// This format is used to access data fields in formatted message buffers.
/// 
/// The MIT License(MIT)
/// 
/// @copyright 2014 Paul M Watt
/// 
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files(the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions :
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
/// 
//  ****************************************************************************
#ifndef HG_H_INCLUDED
#define HG_H_INCLUDED
//  Includes *******************************************************************
#include <alchemy.h>
#include <Hg/msg_buffer.h>
#include <Hg/pack_message.h>
#include <Hg/unpack_message.h>
#include <meta/dynamic.h>

namespace Hg
{

//  ****************************************************************************
template< typename T >
size_t dynamic_size_of(const T& msg);

//  ****************************************************************************
/// An object that defines and manages access to a formatted message buffer.
///                 
/// @paramt MessageT         A message description that has 
///                           defined the format and utilities for field access.
///                           The MessageT must define these member-types:
///                             format_type:    TypeList defines the format
///                             storage_type:   StoragePolicy that manages
///                                             access rules for the buffer.
///                           @note The HG declaration MACROs define a template
///                                 format that is compatible with Hg::Message.
/// @paramt ByteOrderT      The specified byte-order for this
///                           message definition. HostByteOrderfi is the default.
/// 
template< typename MessageT,
          typename ByteOrderT = Hg::HostByteOrder,
          typename StorageT   = Hg::BufferedStoragePolicy
        >
class Message
  : public MessageT
{
public:
  //  Typedefs *****************************************************************
  typedef MessageT                            message_type;

  typedef typename 
    MessageT::format_type                     format_type;
  typedef StorageT                            storage_type;

  typedef typename 
    storage_type::data_type                   data_type;
  typedef data_type*                          pointer;
  typedef const data_type*                    const_pointer;
  typedef MessageT&                           reference;
  typedef const MessageT&                     const_reference;

  typedef ByteOrderT                          byte_order_type;

  typedef Message 
          < MessageT, 
            ByteOrderT,
            StorageT
          >                                   this_type;

  typedef MsgBuffer<storage_type>             buffer_type;
  typedef std::shared_ptr<buffer_type>        buffer_sptr;

  typedef typename
    message_size_trait<format_type>::type     size_trait;

  //  Constants ****************************************************************
  enum { k_size = SizeOf<format_type>::value };
                                        ///< Indicates the size in bytes of the
                                        ///  data buffer managed by this message.
  static const
    bool k_has_dynamic = has_dynamic<format_type>::value;
                                        ///< Indicates if the format of this 
                                        ///  message contains fields that are
                                        ///  potentially dynamically allocated.

  //  Construction *************************************************************
  //  **************************************************************************
  /// Default Constructor
  ///
  Message()
    : m_spMsgBuffer(new MsgBuffer<storage_type>)
  { }

  //  **************************************************************************
  /// Copy Constructor
  /// 
  /// @param rhs              The Hg message object from which data is copied. 
  ///
  Message(const Message& rhs)
  {
    *static_cast<message_type*>(this) = rhs;
  }

  //  **************************************************************************
  /// Value constructor. Constructs an initialized message from a raw data buffer.
  ///               
  /// @param p                The initialization data. The contents will only 
  ///                         be verified for validity of the pointer if the
  ///                         size n is larger than zero.
  /// @param n                The size of the buffer in sp.
  ///
  Message(const_pointer p, size_t n)
    : m_spMsgBuffer(new MsgBuffer<storage_type>)
  {
    assign(p,n);
  }

  //  Operations ***************************************************************
  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// @param rhs              The object from which data is assigned to this.
  ///
  Message& operator=(const Message& rhs)
  {
    if (this != &rhs)
    {
      m_spMsgBuffer = rhs.m_spMsgBuffer;
      *static_cast<message_type*>(this) = rhs;
    }

    return *this;
  }

  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// @param rhs              Basic message values to initialize this instance.
  ///
  Message& operator=(const message_type& rhs)
  {
    if (this != &rhs)
    {
      m_spMsgBuffer.reset();
      *static_cast<message_type*>(this) = rhs;
    }

    return *this;
  }

  //  Status *******************************************************************
  //  **************************************************************************
  /// Indicates if the buffer has allocated space.
  ///
  /// @return       true  -   Buffer space has been allocated for the message.
  ///               false -   There is no buffer space allocated.
  ///               
  bool empty() const
  {
    return !m_spMsgBuffer
        || m_spMsgBuffer->empty();
  }

  //  **************************************************************************
  /// Indicates the number of bytes required by this message.
  ///
  /// @return       The number of bytes that are used to pack this message.
  ///               
  size_t size() const
  {
    return calc_size<k_has_dynamic>();
  }


  //  **************************************************************************
  /// Indicates if the byte-order of the message is host-order.
  /// 
  /// @return       true  -   The message is defined in host byte-order.
  ///               false -   The mesage is not in host byte-order.
  ///                         Most likely net byte-order.
  ///
  bool is_host_order() const
  {
    return ByteOrderT::is_host;
  }

  //  Methods ******************************************************************
  //  **************************************************************************
  /// Assigns the contents of an incoming raw memory buffer to the message.
  /// 
  /// @param pBuffer         A memory buffer whose contents will be assigned to
  ///                        this message object. The values of the buffer are 
  ///                        copied into the message.
  /// @param n               The number of bytes held in p_buffer.
  ///
  void assign(const_pointer pBuffer, size_t n)
  {
    // TODO: Throw an exception if p is invalid with n > 0
    if ( pBuffer
      && n > 0)
    {
      m_spMsgBuffer->assign(pBuffer, n);

      // Casting this object to the base object MessageT.
      // This pointer will accept the data read in from the buffer.
      Message &refThis = *static_cast<Message*>(this);
      refThis = unpack_message< message_type, 
                                buffer_type,
                                size_trait
                              >(*this, *m_spMsgBuffer.get());
    }
  }

  //  **************************************************************************
  /// Releases any reference to internal memory buffers.
  /// The message will be MT after this call.
  ///
  void clear()
  {
    m_spMsgBuffer->clear();
  }

  //  **************************************************************************
  /// Returns a clone of this message object.
  /// 
  /// A new memory buffer will be allocated to accept the stored data for the
  /// clone operation.
  ///
  Message clone() const
  {
    // Clone and assign the new message buffer to the return message object.
    return Message(data(), size());
  }

  //  **************************************************************************
  /// Returns a const reference to the underlying collection of value objects.
  ///
  const_reference values() const
  {
    return *this;
  }

  //  **************************************************************************
  /// Returns a reference to the underlying collection of value objects.
  ///
  reference values()
  {
    return *this;
  }

  //  **************************************************************************
  /// Returns a pointer to the memory buffer that contains the packed message.
  ///
  const_pointer data() const
  {
    Message *pThis = const_cast<Message*>(this);
    pThis->pack_data();

    return m_spMsgBuffer->data();
  }


private:
  //  Private Data Members *****************************************************
  buffer_sptr       m_spMsgBuffer;

  //  **************************************************************************
  /// Returns a pointer to the memory buffer that contains the packed message.
  ///
  void pack_data()
  {
// TODO: Add code to determine of the data has changed from the Datum obects, and only allocate adn write if teh buffer is dirty.
    m_spMsgBuffer = pack_message < message_type, 
                                   buffer_type,
                                   size_trait
                                 >(values(), size());
  }

  //  **************************************************************************
  /// Reports the number of bytes this message object occupies.
  /// This instance of size calculates the size for dynamically sized messages.
  /// 
  /// @return       The number of bytes that are used to pack this message.
  ///
  template<bool has_dynamic>
  size_t calc_size() const
  {
    size_t fixed_size   = Hg::SizeOf<format_type>::value;
    size_t dynamic_size = dynamic_size_of<message_type, byte_order_type, storage_type>(*this);
    return fixed_size + dynamic_size;
  }

  //  **************************************************************************
  /// Reports the number of bytes this message object occupies.
  /// 
  /// @return       The number of bytes that are used to pack this message.
  ///
  template<>
  size_t calc_size<false>() const
  {
    return Hg::SizeOf<format_type>::value;
  }


  // Give friendship to message instantiations of other types for conversion.
  // Conversion between ByteOrderT has been provided.
  template <typename other_MessageT,
            typename other_ByteOrderT,
            typename other_StorageT
            >
  friend 
  class Message;
};




} // namespace Hg

//  Includes *******************************************************************
#include <Hg/message_byte_order.h>
#include <Hg/message_dynamic.h>

#endif
