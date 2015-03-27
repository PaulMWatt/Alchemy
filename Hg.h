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
#include <Hg/msg_view.h>
#include <Hg/pack_message.h>
#include <Hg/unpack_message.h>
#include <Pb/dynamic.h>


namespace Hg
{

//  Forward Declarations *******************************************************
template< typename T >
size_t dynamic_size_of(const T& msg);

//  ****************************************************************************
template< typename MsgT,
          typename StorageT
        >
class basic_msg;

//  ****************************************************************************
template< class HgMsgT,
          bool  has_dynamic
        >
struct msg_size;


//  ****************************************************************************
/// An object that defines and manages access to a formatted message buffer.
///                 
/// @paramt HgT             A message description that has 
///                           defined the format and utilities for field access.
/// @paramt ByteOrderT      The specified byte-order for this
///                           message definition. HostByteOrder is the default.
/// 
template< typename HgT,
          typename ByteOrderT = Hg::HostByteOrder
        >
class Message
  : public HgT
{
public:
  //  Typedefs *****************************************************************
  typedef HgT                                 base_type;

  typedef typename
    base_type::message_type                   message_type;

  typedef typename
    base_type::format_type                    format_type;

  typedef typename
    base_type::storage_type                   storage_type;

  typedef typename
    base_type::const_pointer                  const_pointer;

  typedef ByteOrderT                          byte_order_type;


  //  Construction *************************************************************
  //  **************************************************************************
  /// Default Constructor
  ///
  Message()
    : basic_msg()
  { }

  //  **************************************************************************
  /// Copy Constructor
  /// 
  /// @param rhs              The Hg message object from which data is copied. 
  ///
  Message(const message_type& rhs)
  { 
    *static_cast<message_type*>(this) = rhs;  
  }

  //  **************************************************************************
  /// Copy Constructor
  /// 
  /// @param rhs              The Hg message object from which data is copied. 
  ///
  Message(const basic_msg& rhs)
    : basic_msg(rhs)
  { }

  //  **************************************************************************
  /// Value constructor. Constructs an initialized message from a raw data buffer.
  ///               
  /// @param p                The initialization data. The contents will only 
  ///                         be verified for validity of the pointer if the
  ///                         size n is larger than zero.
  /// @param n                The size of the buffer in sp.
  ///
  Message(const_pointer p, size_t n)
    : basic_msg(p,n)
  { }

  //  Operations ***************************************************************
  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// @param rhs              Basic message values to initialize this instance.
  ///
  Message& operator=(const message_type& rhs)
  {
    if (this != &rhs)
    {
      *static_cast<message_type*>(this) = rhs;
    }

    return *this;
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
    return byte_order_type::is_host;
  }

  // Give friendship to message instantiations of other types for conversion.
  template< typename other_MsgT,
            typename other_ByteOrderT
          >
  friend 
  class Message;
};



//  ****************************************************************************
/// An object that defines and manages access to a formatted message buffer.
///                 
/// @paramt MsgT            A message description that has 
///                           defined the format and utilities for field access.
///                           The MsgT must define these member-types:
///                             format_type:    TypeList defines the format
/// @paramt StorageT        StoragePolicy that manages access rules for the buffer.
///
///                           @note The HG declaration MACROs define a template
///                                 format that is compatible with Hg::basic_msg.
/// 
template< typename MsgT,
          typename StorageT   = Hg::BufferedStoragePolicy
        >
class basic_msg
  : public MsgT
{
public:
  //  Typedefs *****************************************************************
  typedef MsgT                                message_type;

  typedef typename 
    MsgT::format_type                         format_type;
  typedef StorageT                            storage_type;

  typedef MsgBuffer<storage_type>             buffer_type;

  typedef typename
    message_size_trait<format_type>::type     size_trait;

  typedef typename 
    storage_type::data_type                   data_type;
  typedef data_type*                          pointer;
  typedef const data_type*                    const_pointer;
  typedef MsgT&                               reference;
  typedef const MsgT&                         const_reference;

  typedef basic_msg< MsgT, StorageT >         this_type;

  typedef Message<this_type, 
                  Hg::HostByteOrder>          host_t;

  typedef Message<this_type, 
                  Hg::NetByteOrder>           net_t;

  typedef Message<this_type, 
                  Hg::BigEndian>              big_t;

  typedef Message<this_type, 
                  Hg::LittleEndian>           little_t;

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
  basic_msg()
  { }

  //  **************************************************************************
  /// Copy Constructor
  /// 
  /// @param rhs              The Hg message object from which data is copied. 
  ///
  basic_msg(const basic_msg& rhs)
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
  basic_msg(const_pointer p, size_t n)
  {
    assign(p,n);
  }

  //  Operations ***************************************************************
  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// @param rhs              Basic message values to initialize this instance.
  ///
  basic_msg& operator=(const message_type& rhs)
  {
    if (this != &rhs)
    {
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
    return m_msgBuffer.empty();
  }

  //  **************************************************************************
  /// Indicates the number of bytes required by this message.
  ///
  /// @return       The number of bytes that are used to pack this message.
  ///               
  size_t size() const
  {
    return msg_size<this_type, 
                    k_has_dynamic>::calculate(*this); 
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
    if ( pBuffer
      && n > 0)
    {
      m_msgBuffer.assign(pBuffer, n);

      // Casting this object to the base object MsgT.
      // This pointer will accept the data read in from the buffer.
      basic_msg &refThis = *static_cast<basic_msg*>(this);
      refThis = unpack_message< message_type, 
                                buffer_type,
                                size_trait
                              >(*this, m_msgBuffer);
    }
    else
    {
#if ALCHEMY_HAS_EXCEPTIONS
      throw std::invalid_argument("Hg::basic_msg<>::assign() - pBuffer is invalid or length n is 0");
#endif
    }
  }

#ifdef ALCHEMY_RVALUE_REF_SUPPORTED
// TODO: Opportunity, add move assignment to populate the message. 
//       Return and complete this if possible. Try to focus on iterator logic.
//  //  **************************************************************************
//  /// Assigns the contents of an incoming raw memory buffer to the message.
//  /// 
//  /// @param pBuffer         A memory buffer whose contents will be assigned to
//  ///                        this message object. The values of the buffer are 
//  ///                        copied into the message.
//  /// @param n               The number of bytes held in p_buffer.
//  ///
//  void assign(const_pointer pBuffer, size_t n)
//  {
//    if ( pBuffer
//      && n > 0)
//    {
//      m_msgBuffer.assign(pBuffer, n);
//
//      // Casting this object to the base object MsgT.
//      // This pointer will accept the data read in from the buffer.
//      basic_msg &refThis = *static_cast<Message*>(this);
//      refThis = unpack_message< message_type, 
//                                buffer_type,
//                                size_trait
//                              >(*this, m_msgBuffer);
//    }
//    else
//    {
//#if ALCHEMY_HAS_EXCEPTIONS
//      throw std::invalid_argument("Hg::basic_msg<>::assign() - pBuffer is invalid or length n is 0");
//#endif
//    }
//  }
#endif


  //  **************************************************************************
  /// Releases any reference to internal memory buffers.
  /// The message will be MT after this call.
  ///
  void clear()
  {
    m_msgBuffer.clear();
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
    basic_msg *pThis = const_cast<basic_msg*>(this);
    pThis->pack_data();

    return m_msgBuffer.data();
  }


  //  **************************************************************************
  /// Copies the data from this object 
  ///
  void data(pointer pBuffer, size_t n)
  {
    pack_data(pBuffer, n);
  }


private:
  //  Private Data Members *****************************************************
  buffer_type       m_msgBuffer;

  //  **************************************************************************
  void pack_data()
  {
    pack_message< message_type, 
                  buffer_type,
                  size_trait
                >(values(), size(), m_msgBuffer);
  }


  //  **************************************************************************
  void pack_data(pointer pBuffer, size_t n)
  {
    buffer_type msg_buffer;
    msg_buffer.assign(pBuffer, n);

    pack_message< message_type, 
                  buffer_type,
                  size_trait
                >(values(), msg_buffer);
  }

  // Give friendship to message instantiations of other types for conversion.
  template <typename other_MsgT,
            typename other_StorageT
            >
  friend 
  class basic_msg;
};


//  ****************************************************************************
/// Reports the number of bytes this message object occupies.
/// This instance of size calculates the size for dynamically sized messages.
/// 
/// @return       The number of bytes that are used to pack this message.
///
template< typename T,
          bool  has_dynamic
        >
struct msg_size
{
  static size_t calculate(const T &msg)
  {
    size_t fixed_size   = Hg::SizeOf<typename T::format_type>::value;
    size_t dynamic_size = dynamic_size_of<typename T::message_type, 
                                          typename T::storage_type>(msg);
    return fixed_size + dynamic_size; 
  }
};

//  ****************************************************************************
/// Specialization returns the size of a fixed size message.
/// 
/// @return       The number of bytes that are used to pack this message.
///
template< typename T >
struct msg_size<T, false>
{
  static size_t calculate(const T &msg)
  {
    return Hg::SizeOf<typename T::format_type>::value;
  }
};


} // namespace Hg

//  Includes *******************************************************************
#include <Hg/message_byte_order.h>
#include <Hg/message_dynamic.h>

#endif
