/// @file Hg/msg_buffer.h
/// 
/// A packet buffer structure suitable for processing network
/// and interprocess communication messages.
///           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MSG_BUFFER_H_INCLUDED
#define MSG_BUFFER_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/byte_order.h>
#include <Pb/meta_foreach.h>
#include <Hg/storage_policy.h>

#include <cstddef>
#include <algorithm>


namespace Hg
{

//  ****************************************************************************
/// MsgBuffer Template Definition. 
/// This abstracts the behavior of the buffer with respect to the Byte-Order of the message.
/// 
/// @tparam StorageT          [typename] The storage_t that manages the
///                           type of object used in the underlying buffer for 
///                           the packet data. This policy also provides 
///                           the capabilities to read/write to the buffer.
///
template< typename StorageT>
class MsgBuffer
{
public:
  //  Typedefs *****************************************************************
  typedef StorageT                                          storage_type;
  typedef typename storage_type::data_type                  data_type;
  typedef typename storage_type::s_pointer                  s_pointer;
  typedef typename storage_type::w_pointer                  w_pointer;

  typedef data_type*                                        pointer;
  typedef const data_type*                                  const_pointer;

  //  Construction *************************************************************
  //  **************************************************************************
  /// Default Constructor
  ///
  MsgBuffer()
    : m_offset(0)
  {
    // No current operations
  }

  //  **************************************************************************
  /// Fill Constructor
  ///
  /// @param n      The number of bytes to allocate for the buffer.
  /// @param val    The value to fill each item in the allocated buffer if supplied.
  ///      
  explicit 
    MsgBuffer(size_t n)
      : m_data(n)
      , m_offset(0)
  {
    // No current operations
  }

  MsgBuffer(size_t n, byte_t val)
    : m_offset(0)
  {
    m_data.resize(n, val);
  }


  //  **************************************************************************
  /// Copy Constructor
  ///
  /// @param rhs    The input object to be copied.
  /// @note         This object's copy constructor only performs a shallow 
  ///               copy of the message buffer. Use the clone operation
  ///               to make a separate copy of the buffer.
  ///               
  MsgBuffer(const MsgBuffer& rhs)
    : m_offset(rhs.offset())
  {
    assign(rhs.data(), rhs.size());
  }

  //  **************************************************************************
  /// Destructor
  ///
  ~MsgBuffer()
  {
    m_data.clear();
  }

  //  Operators ****************************************************************
  //  **************************************************************************
  /// Assignment Operator
  ///
  /// @param rhs    (right-hand side) The input object to be copied.
  /// @note         This object's copy constructor only performs a shallow 
  ///               copy of the message buffer. Use the clone operation
  ///               to make a separate copy of the buffer.
  ///               
  MsgBuffer& operator=(const MsgBuffer& rhs)
  {
    assign(rhs.data(), rhs.size());
    return *this;
  }

  //  Status *******************************************************************
  //  **************************************************************************
  /// Indicates if memory is currently managed by this buffer.
  /// 
  /// @return       true -    The buffer is empty.
  ///               false-    There is memory allocated and managed by this buffer.
  ///
  bool empty() const
  {
    return m_data.empty();
  }

  //  **************************************************************************
  /// Return the number of bytes reserved for use by this buffer.
  /// 
  /// @return       The allocated buffer size is returned. This packet buffer
  ///               must be valid for a non-zero value to be returned.
  ///
  size_t capacity() const
  {
    return  m_data.capacity();
  }

  //  **************************************************************************
  /// Reports the current size of the buffer in use.
  /// 
  /// @return       The number of bytes in use in the allocated buffer.
  ///               If there is no internal buffer, 0 is returned.
  ///
  size_t size() const
  {
    return  m_data.size();
  }

  //  Methods ******************************************************************
  //  **************************************************************************
  /// Releases any resources associated with this object.
  ///
  void clear()
  {
    m_data.clear();
    m_offset = 0;
  }

  // TODO: When offsets are considered, how should this affect items like resize.
  //  **************************************************************************
  /// Resizes the buffer to contain n elements.
  ///
  /// @param n        The number of elements to allocate for the buffer.
  /// @param val      Optional value to be copied into each element allocated.
  ///
  void resize(size_t n)
  {
    m_data.resize(n);
  }

  //  **************************************************************************
  void resize(size_t n, byte_t val)
  {
    m_data.resize(n, val);
  }

  //  **************************************************************************
  /// Provides access to the packed memory buffer.
  /// 
  /// @return       Returns a constant pointer to the buffer that contains the 
  ///               packed memory.
  ///               0 is returned if there is no memory associated with the buffer.
  ///
  const_pointer data() const
  {
    if (m_data.empty())
    {
      return 0;
    }

    return const_cast<const_pointer>(&m_data[0]);
  }

  //  **************************************************************************
  /// Zeroes the contents of the buffer if they have been assigned.
  /// 
  void zero()
  {
    std::fill(m_data.begin(), m_data.end(), 0);
  }

  //  **************************************************************************
  /// Assigns the contents of an incoming raw memory buffer to the message buffer.
  /// 
  /// @param pBuffer         A memory buffer whose contents will be assigned to
  ///                        this message object. The values of the buffer are 
  ///                        copied into the message.
  /// @param n               The number of bytes held in p_buffer.
  ///
  void assign(const_pointer pBuffer, size_t n)
  {
    // Verify inputs.
    if ( !pBuffer
      || 0 == n)
    {
      m_data.clear();
      return;
    }

    // Assign the input values to the internal buffer.
    const_pointer pFirst = pBuffer;
    const_pointer pLast  = &pBuffer[n];

    m_data.assign(pFirst, pLast);
  }
  
  //  **************************************************************************
  /// Returns the offset used to access the buffer.
  /// 
  /// Returns the offset used to access the buffer relative to the first index
  /// in the buffer. The default offset is zero. Alternate offsets are allowed
  /// to facilitate nested packet structures as well as dynamically formatted
  /// structures.
  /// 
  /// @return       A number of bytes greater than 0 is returned.
  ///
  std::ptrdiff_t offset() const                        
  { 
    return m_offset; 
  }

  //  **************************************************************************
  /// Assigns a new base offset for memory access to this object.
  /// 
  /// @param new_offset       The offset from the beginning of the supplied buffer.
  ///
  void offset(std::ptrdiff_t new_offset)         
  { 
    m_offset = new_offset; 
  }

  //  **************************************************************************
  /// Parameterized function that returns data from a specified offset in the buffer.
  ///               
  /// @tparam T               [typename] The parameterized type to be returned 
  ///                         to the caller.
  /// @param value            Accepts the value read from the packet buffer.
  /// @param pos              The offset from the beginning of the buffer to
  ///                         read the output value.
  ///                         
  /// @return       The number of bytes read from the buffer is returned.
  ///               It is possible for a successful case to return 0.
  /// 
  template <typename T>
  size_t get_data(T& value, std::ptrdiff_t pos) const
  {
    if (empty())
    {
      return 0;
    }

    // Read from the user supplied offset as well as the base offset 
    // configured for this Packet Buffer.
    std::ptrdiff_t total_offset = offset() + pos;

    // Verify the requested data can be read from the buffer.
    size_t bytes_read = 0;
    if ( total_offset >= 0
      && total_offset + sizeof(value) <= size())
    {
      bytes_read =
        storage_type::read( data(),
                            &value,
                            sizeof(T),
                            total_offset)
        ? sizeof(T)
        : 0;
    }

    return bytes_read;
  }

  //  **************************************************************************
  /// Parameterized function that reads a range of data from the buffer.
  ///               
  /// @tparam T               [typename] The parameterized type to be read 
  ///                         by the caller.
  /// @param pBuffer          Pointer to the first element in the array to 
  ///                         be written into.
  ///
  /// @param length           The number of bytes to read in.
  ///                         pBuffer must contain at least length number of
  ///                         bytes.
  ///
  /// @param pos              The offset from the beginning of the buffer to
  ///                         read the input value.
  ///                         
  /// @return       The number of bytes read from the buffer is returned.
  ///               It is possible for a successful case to return 0.
  ///
  size_t get_range(void* pBuffer, size_t length, size_t pos) const
  {
    if ( empty()
      || 0 == pBuffer
      || 0 == length)
    {
      return 0;
    }

    // Read from the user supplied offset as well as the base offset 
    // configured for this Packet Buffer.
    size_t total_offset = static_cast<size_t>(offset()) + pos;

    // Verify the data can be safely written within the bounds of the buffer.
    size_t bytes_read = 0;
    size_t total_size = this->size();
    if ( (total_offset >= 0)
      && (total_offset + length) <= total_size)
    {
      bytes_read = 
        storage_type::read( data(),
                            pBuffer,
                            length,
                            total_offset)
        ? length
        : 0;
    }

    return bytes_read;
  }

  //  **************************************************************************
  /// Parameterized function that writes data to a specified offset in the buffer.
  ///               
  /// @tparam T               [typename] The parameterized type to be written 
  ///                         by the caller.
  /// @param value            Contains the value to write to the packet buffer.
  /// @param pos              The offset from the beginning of the buffer to
  ///                         write the input value.
  ///                         
  /// @return       The number of bytes written to the buffer is returned.
  ///               It is possible for a successful case to return 0.
  ///
  template <typename T>
  size_t set_data(const T& value, size_t pos)
  {
    if (empty())
    {
      return 0;
    }

    // Read from the user supplied offset as well as the base offset 
    // configured for this Packet Buffer.
    size_t total_offset = static_cast<size_t>(offset()) + pos;

    // Verify the data can be safely written within the bounds of the buffer.
    size_t bytes_written = 0;
    size_t total_size = size();
    if ( (total_offset >= 0)
      && (total_offset + Hg::size_of<T>::value) <= total_size)
    {
      bytes_written = 
        storage_type::write ( raw_data(),
                              &value,
                              Hg::size_of<T>::value,
                              total_offset)
        ? Hg::size_of<T>::value
        : 0;
    }

    return bytes_written;
  }

  //  **************************************************************************
  /// Parameterized function that writes a range of data to the buffer.
  ///               
  /// @tparam T               [typename] The parameterized type to be written 
  ///                         by the caller.
  /// @param first            Contains the first item to write to the buffer.
  ///
  /// @param last             Contains the item one past the last item to write.
  ///                         This item may point to an element that is not 
  ///                         valid to de-reference. Similar to C+++ Standard Library.
  ///
  ///                         Last must be greater than than the first time,
  ///                         and they must be part of the same range of elements
  ///                         otherwise the behavior is undefined.
  ///
  /// @param pos              The offset from the beginning of the buffer to
  ///                         write the input value.
  ///                         
  /// @return       The number of bytes written to the buffer is returned.
  ///               It is possible for a successful case to return 0.
  ///
  template <typename InputIt>
  size_t set_range(InputIt first, InputIt last, size_t pos)
  {
    if (empty())
    {
      return 0;
    }

    // Return if first and last are the same.
    if (first == last)
    {
      return 0;
    }

    // Read from the user supplied offset as well as the base offset 
    // configured for this Packet Buffer.
    size_t total_offset = static_cast<size_t>(offset()) + pos;
    size_t range_size   = std::distance(first, last);

    // Verify the data can be safely written within the bounds of the buffer.
    size_t bytes_written = 0;
    size_t total_size = size();
    if ( (total_offset >= 0)
      && (total_offset + range_size) <= total_size)
    {
      bytes_written = 
        storage_type::write ( raw_data(),
                              first,
                              range_size,
                              total_offset)
        ? range_size
        : 0;
    }

    return bytes_written;
  }

  //  **************************************************************************
  /// Creates a full copy of the message buffer.
  /// 
  /// @return       A deep copy of this objects packet buffer. 
  /// 
  /// @note         clone performs a buffer allocation according to the 
  ///               storage policy provided to the MsgBuffer. Therefore a
  ///               new memory buffer is created for the cloned copy to exist 
  ///               within.
  ///
  MsgBuffer clone() const
  {
    MsgBuffer retBuffer;
    if (empty())
    {
      return retBuffer;
    }

    // Create a new buffer to accept a clone of the data.
    // Allocate a buffer that matches this buffers capacity.
    retBuffer.assign(data(), size());
    retBuffer.m_offset    = m_offset;

    return retBuffer;
  }

private:
  //  Typedefs *****************************************************************
  typedef std::vector<data_type>          DataVector;


  // Private Member Data *******************************************************
  DataVector        m_data;               ///< The storage medium managed by
                                          ///  this message buffer.
  std::ptrdiff_t    m_offset;             ///< The number of bytes from the 
                                          ///  beginning of the buffer that 
                                          ///  all data reads should occur from.

  //  **************************************************************************
  //  Provides access to the packed memory buffer.
  //  
  //  @return       Returns a constant pointer to the buffer that contains the 
  //                packed memory.
  //                0 is returned if there is no memory associated with the buffer.
  // 
  pointer raw_data()
  {
    return &m_data[0];
  }



  // Let all message buffer objects be friends for data transfer.
  template< typename T>
  friend
  class MsgBuffer;
};


//  ****************************************************************************
template <typename pkt_buffer_t>
pkt_buffer_t& make_nil_buffer()
{
  static pkt_buffer_t nilBuffer;
  return nilBuffer;
}

} // namespace Hg


#endif
