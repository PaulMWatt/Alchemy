/// @file Hg/msg_view_iterator.h
/// 
/// The msg_view iterator type for working with opaque types.
///           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef msg_view_ITERATOR_H_INCLUDED
#define msg_view_ITERATOR_H_INCLUDED
//  Includes ******************************************************************
#include <Hg/static_msg_buffer.h>

namespace Hg
{

template< typename MsgT,
          typename StorageT
        >
class basic_msg;

//  **************************************************************************
/// Iterator for nonmutable msg_view.
///
template< typename T >
class msg_view_const_iterator 
{      
public:
  using iter_t            = msg_view_const_iterator<T>;
  using iterator_category = std::random_access_iterator_tag;
  using value_type        = basic_msg<T,BufferedStaticStoragePolicy>;
  using difference_type   = ptrdiff_t;
  using pointer           = const value_type*;
  using reference         = const value_type&;
  using Tptr              = value_type*;

  //  **************************************************************************
  /// Default constructor with a pointer to a NULL msg_view.
  ///
  msg_view_const_iterator()
    : m_pBuffer()
    , m_ptr()
  { }

  //  **************************************************************************
  /// Initialized constructor with a pointer to a msg_view.
  ///
  msg_view_const_iterator(byte_t *pArg)
    : m_pBuffer(pArg)
    , m_ptr()
  { }

  //  **************************************************************************
  /// Return designated object.
  ///
  reference operator*() const
  {    
    return (*Realize());
  }

  //  **************************************************************************
  /// Return pointer to class object.
  ///
  pointer operator->() const
  {    
    return Realize();
  }

  //  **************************************************************************
  /// Preincrement.
  ///
  iter_t& operator++()
  {    
    m_ptr = 0;
    m_pBuffer += k_size;
    return (*this);
  }

  //  **************************************************************************
  /// Postincrement.
  ///
  iter_t operator++(int)
  {
    iter_t tmp = *this;

    m_ptr = 0;
    m_pBuffer += k_size;

    return (tmp);
  }

  //  **************************************************************************
  /// Predecrement.
  ///
  iter_t& operator--()
  {
    m_ptr = 0;
    m_pBuffer -= k_size;
    return (*this);
  }

  //  **************************************************************************
  /// Postdecrement.
  ///
  iter_t operator--(int)
  {    
    iter_t tmp = *this;

    m_ptr = 0;
    m_pBuffer -= k_size;

    return (tmp);
  }

  //  **************************************************************************
  /// Increment by integer.
  ///
  iter_t& operator+=(difference_type offset)
  {    
    m_ptr = 0;
    m_pBuffer += k_size * offset;
    return (*this);
  }

  //  **************************************************************************
  /// Return this + integer.
  ///
  iter_t operator+(difference_type offset) const
  {      
    iter_t tmp = *this;
    return (tmp += offset);
  }

  //  **************************************************************************
  /// Decrement by integer.
  ///
  iter_t& operator-=(difference_type offset)
  {    
    m_ptr = 0;
    m_pBuffer -= k_size * offset;
    return (*this);
  }

  //  **************************************************************************
  /// Return this - integer.
  ///
  iter_t operator-(difference_type offset) const
  {    
    iter_t tmp = *this;
    return (tmp -= offset);
  }

  //  **************************************************************************
  /// Return difference of iterators.
  ///
  difference_type operator-(const iter_t& rhs) const
  {    
    return (this->m_pBuffer - rhs.m_pBuffer) / k_size;
  }

  //  **************************************************************************
  /// Subscript.
  ///
  reference operator[](difference_type offset) const
  {    
    return (*(*this + offset));
  }

  //  **************************************************************************
  /// Test for iterator equality.
  ///
  bool operator==(const iter_t& rhs) const
  {    
    return (this->m_pBuffer == rhs.m_pBuffer);
  }

  //  **************************************************************************
  /// Test for iterator inequality.
  ///
  bool operator!=(const iter_t& rhs) const
  {    
    return (!(*this == rhs));
  }

  //  **************************************************************************
  /// Test if this < rhs.
  ///
  bool operator<(const iter_t& rhs) const
  {    
    return (this->m_pBuffer < rhs.m_pBuffer);
  }

  //  **************************************************************************
  /// Test if this > rhs.
  ///
  bool operator>(const iter_t& rhs) const
  {    
    return (rhs < *this);
  }

  //  **************************************************************************
  /// Test if this <= rhs.
  ///
  bool operator<=(const iter_t& rhs) const
  {    
    return (!(rhs < *this));
  }

  //  **************************************************************************
  /// Test if this >= rhs.
  ///
  bool operator>=(const iter_t& rhs) const
  {    
    return (!(*this < rhs));
  }

protected:
  //  Member Data **************************************************************
  static const 
    size_t  k_size = Hg::size_of<typename T::format_type>::value; 


  byte_t     *m_pBuffer;      ///< pointer to the raw data buffer.

  mutable
  value_type  m_msg;          ///< Instance of message to realize the 
                              ///  msg_view for each piece of data.
                              ///  The message is realized each time the 
                              ///  iterator is dereferenced.

  mutable
  Tptr        m_ptr;          ///< pointer to element in the msg_view

  //  Member functions *********************************************************
  //  ************************************************************************
  /// Indicates if this position has been dereferenced.
  ///
  bool is_referenced()
  {
    return m_ptr != 0;
  }

  //  ************************************************************************
  /// Reads the current data into the message context for interaction.
  ///
  Tptr Realize() const
  {
    if (m_ptr)
      return m_ptr;

    m_msg.assign(m_pBuffer, k_size);
    m_ptr = &m_msg;

    return m_ptr;
  }

};


//  ****************************************************************************
/// Iterator for a mutable msg_view.
///
template< typename T >
class msg_view_iterator
       : public msg_view_const_iterator<T>
{
public:
  using iter_t            = msg_view_iterator<T>;
  using base_t            = msg_view_const_iterator<T>;
  using iterator_category = std::random_access_iterator_tag;
  using value_type        = basic_msg< T,BufferedStaticStoragePolicy>;
  using difference_type   = ptrdiff_t;
  using pointer           = value_type*;
  using reference         = value_type&;

  //  **************************************************************************
  /// Default constructor for an iterator with a NULL msg_view pointer.
  ///
  msg_view_iterator()
  { }

  //  **************************************************************************
  /// Constructor for an initialized iterator with a valid msg_view pointer.
  ///
  msg_view_iterator(byte_t* pArg)
    : base_t(pArg)
  { }

  //  **************************************************************************
  /// Destructor
  ///
  ~msg_view_iterator()
  {    
    Store();
  }

  //  **************************************************************************
  /// Return designated object.
  ///
  reference operator*() const
  {    
    return ((reference)**(base_t *)this);
  }

  //  **************************************************************************
  /// Return pointer to class object.
  ///
  pointer operator->() const
  {   
    return ((pointer)*(base_t *)this);
  }

  //  **************************************************************************
  /// Preincrement.
  ///
  iter_t& operator++()
  {    
    Store();
    ++*(base_t *)this;
    return *this;
  }

  //  **************************************************************************
  /// Postincrement.
  ///
  iter_t operator++(int)
  {    
    iter_t tmp = *this;
    ++*this;
    return tmp;
  }

  //  **************************************************************************
  /// Predecrement.
  ///
  iter_t& operator--()
  {    
    Store();
    --*(base_t *)this;
    return *this;
  }

  //  **************************************************************************
  /// Postdecrement.
  ///
  iter_t operator--(int)
  {    
    iter_t tmp = *this;
    --*this;
    return tmp;
  }

  //  **************************************************************************
  /// Increment by integer.
  ///
  iter_t& operator+=(difference_type offset)
  {    
    Store();
    *(base_t *)this += offset;
    return *this;
  }

  //  **************************************************************************
  /// Return this + integer.
  ///
  iter_t operator+(difference_type offset) const
  {    
    iter_t tmp = *this;
    return tmp += offset;
  }

  //  **************************************************************************
  /// Decrement by integer.
  ///
  iter_t& operator-=(difference_type offset)
  {    
    return *this += -offset;
  }

  //  **************************************************************************
  /// Return this - integer.
  ///
  iter_t operator-(difference_type offset) const
  {
    iter_t tmp = *this;
    return tmp -= offset;
  }

  //  **************************************************************************
  /// Return difference of iterators.
  ///
  difference_type operator-(const base_t& rhs) const
  {
    return (*(base_t *)this - rhs);
  }

  //  **************************************************************************
  /// Subscript
  ///
  reference operator[](difference_type offset) const
  {
    return (*(*this + offset));
  }

private:
  //  Member Functions *******************************************************
  //  ************************************************************************
  /// Stores the current message context back into the data buffer.
  ///
  void Store()
  {
    if (base_t::is_referenced())
    {
      base_t::m_msg.data( base_t::m_pBuffer, 
                          base_t::k_size);
    }
  }
};


} // namespace Hg

#endif
