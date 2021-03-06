/// @file Hg/msg_view.h
/// 
/// The msg_view type for working with opaque buffers.
///           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MSG_VIEW_H_INCLUDED
#define MSG_VIEW_H_INCLUDED
//  Includes ******************************************************************
#include <Hg/msg_view_iterator.h>

namespace Hg
{

template< typename MsgT,
          typename StorageT
        >
class Message;

//  **************************************************************************
/// The MsgView object to manage structured access over an opaque buffer.
///
template< typename MsgT,
          typename ByteOrderT = Hg::HostByteOrder
        >
class msg_view
{      
public:
  //  Aliases ******************************************************************
  using message_type    = MsgT;
  using format_type     = typename MsgT::format_type;
  using storage_type    = Hg::BufferedStoragePolicy;
  using byte_order_type = ByteOrderT;

  using value_type      = Message < MsgT, byte_order_type>;
  using raw_pointer     = byte_t*;
  using pointer         = value_type*;
  using const_pointer   = const value_type*;
  using reference       = value_type&;
  using const_reference = const value_type&;

  //  Constants ****************************************************************
  enum { k_size = size_of<format_type>::value };
                                        ///< Indicates the size in bytes of the
                                        ///  data buffer managed by this message.

  // TODO: For this type, this must be false. Add static assertion.
  static const
    bool k_has_dynamic = has_dynamic<format_type>::value;
                                        ///< Indicates if the format of this 
                                        ///  message contains fields that are
                                        ///  potentially dynamically allocated.

  using iterator        = msg_view_iterator<MsgT>;
  using const_iterator  = msg_view_const_iterator<MsgT>;


  //  **************************************************************************
  /// Default constructor.
  ///
  msg_view()
  { }

  //  **************************************************************************
  /// Value constructor
  ///
  /// Create a view from an array of bytes.
  ///
  /// @param view            A reference to an array of bytes, to which this
  ///                        view will be mapped.
  /// 
  template <size_t SizeT>
  msg_view(std::array<byte_t,SizeT>& data)
  {
    m_pFirst = &data[0];

    // Configure the last pointer to be the byte
    // passed the last valid message that fits
    // into the buffer specified by the caller.
    size_t count = SizeT / k_size;
    m_pLast = m_pFirst + (count * k_size);
  }

  //  **************************************************************************
  /// Value constructor
  ///
  /// Create a view from an vector of bytes.
  ///
  /// @param view            A reference to a vector of bytes, to which this
  ///                        view will be mapped.
  /// 
  msg_view(std::vector<byte_t>& data)
  {
    m_pFirst = &data[0];

    // Configure the last pointer to be the byte
    // passed the last valid message that fits
    // into the buffer specified by the caller.
    size_t count = data.size() / k_size;
    m_pLast = m_pFirst + (count * k_size);
  }

  //  **************************************************************************
  /// Value constructor
  ///
  /// Create a view from an existing array of bytes.
  ///
  /// @param pData          A pointer to an array of bytes, to which this
  ///                       view will be mapped.
  /// @param length         The number of bytes in the buffer.
  /// 
  msg_view(const byte_t* pData, size_t length)
  {
    m_pFirst = pData;

    // Configure the last pointer to be the byte
    // passed the last valid message that fits
    // into the buffer specified by the caller.
    size_t count = length / k_size;
    m_pLast = m_pFirst + (count * k_size);
  }

  //  **************************************************************************
  /// Returns the number of valid objects managed by this array structure.
  /// 
  size_t size() const                             
  { 
    return (m_pLast - m_pFirst) 
          / k_size; 
  }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the array.
  /// 
  iterator begin()                                { return msg_view_iterator<MsgT>(m_pFirst);       }
  const_iterator begin()  const                   { return msg_view_const_iterator<MsgT>(m_pFirst); }
  const_iterator cbegin() const                   { return msg_view_const_iterator<MsgT>(m_pFirst); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the array.
  /// 
  iterator end()                                  { return msg_view_iterator<MsgT>(m_pLast);       }
  const_iterator end()  const                     { return msg_view_const_iterator<MsgT>(m_pLast); }
  const_iterator cend() const                     { return msg_view_const_iterator<MsgT>(m_pLast); }

  // TODO: Revisit and complete.
  ////  **************************************************************************
  ///// Returns an iterator to the last item of the array moving in reverse.
  ///// 
  //reverse_iterator rbegin()                       { return this->get().rbegin(); }
  //const_reverse_iterator rbegin()  const          { return this->get().rbegin(); }
  //const_reverse_iterator crbegin() const          { return this->get().crbegin();}

  ////  **************************************************************************
  ///// Returns an iterator to the item one passed the beginning of the array,
  ///// moving in reverse.
  ///// 
  //reverse_iterator rend()                         { return this->get().rend();   }
  //const_reverse_iterator rend()  const            { return this->get().rend();   }
  //const_reverse_iterator crend() const            { return this->get().crend();  } 
protected:
  //  Member Variables *********************************************************
  raw_pointer   m_pFirst;     ///< A pointer to the first element.
  raw_pointer   m_pLast;      ///< A pointer to the last element + 1.

};


//  **************************************************************************
//  Opaque-type functions ****************************************************
//  These functions are only present for buffers to bytes.

//  **************************************************************************
template< typename MsgT,
          typename T
        >
typename
  std::enable_if< is_opaque<T>::value,
                  msg_view<MsgT> >::type
make_view(T& buffer)
{
  return msg_view<MsgT>(buffer);
}


} // namespace Hg

#endif
