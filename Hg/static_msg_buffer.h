/// @file Hg/static_msg_buffer.h
/// 
/// A fixed-size messagge buffer that uses memory allocated by the user.
/// This message buffer is compatible with the Hg message.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef STATIC_MSG_BUFFER_H_INCLUDED
#define STATIC_MSG_BUFFER_H_INCLUDED
//  Includes *******************************************************************
#include <Hg/msg_buffer.h>
#include <Hg/static_storage_policy.h>

namespace Hg
{

//  ****************************************************************************
/// (Static) MsgBuffer Template Definition. 
/// This class is a specialization of the template MsgBuffer, and uses
/// a static_storage_policy.
///
template<>
class MsgBuffer <BufferedStaticStoragePolicy>
{
public:
  //  Aliases ******************************************************************
  using storage_type  = BufferedStaticStoragePolicy;
  using data_type     = storage_type::data_type;
  using s_pointer     = storage_type::s_pointer;
  using w_pointer     = storage_type::w_pointer;
  using pointer       = data_type*;
  using const_pointer = const data_type*;

  //  Construction *************************************************************
  //  **************************************************************************
  /// Default Constructor
  ///
  MsgBuffer()
    : m_pData(0)
    , m_size(0)
    , m_offset(0)
  {
    // No current operations
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
    return !m_pData
        || !size();
  }

  //  **************************************************************************
  /// Return the number of bytes reserved for use by this buffer.
  /// 
  /// @return       The allocated buffer size is returned. This packet buffer
  ///               must be valid for a non-zero value to be returned.
  ///
  size_t capacity() const
  {
    return  size();
  }

  //  **************************************************************************
  /// Reports the current size of the buffer in use.
  /// 
  /// @return       The number of bytes in use in the allocated buffer.
  ///               If there is no internal buffer, 0 is returned.
  ///
  size_t size() const
  {
    return  m_size;
  }

  //  Methods ******************************************************************
  //  **************************************************************************
  /// Releases any resources associated with this object.
  ///
  void clear()
  {
    m_pData  = 0;
    m_size   = 0;
    m_offset = 0;
  }

  //  **************************************************************************
  /// Resizes the buffer to contain n elements.
  /// This function is not supported for this fixed size buffer.
  ///
  /// @param n        The number of elements to allocate for the buffer.
  /// @param val      Optional value to be copied into each element allocated.
  ///
  void resize(size_t n)
  {
    // Not supported
  }

  //  **************************************************************************
  void resize(size_t n, byte_t val)
  {
    // Not supported
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
    return m_pData;
  }

  //  **************************************************************************
  /// Zeroes the contents of the buffer if they have been assigned.
  /// 
  void zero()
  {
    std::fill(m_pData, m_pData + size(), 0);
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
    m_pData = const_cast<pointer>(pBuffer);
    m_size  = n;
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

private:
  // Private Member Data *******************************************************
  pointer           m_pData;              ///< A pointer to the static memory 
                                          ///  buffer supplied by the user. 
  size_t            m_size;               ///< The size if the buffer.
  std::ptrdiff_t    m_offset;             ///< The number of bytes from the 
                                          ///  beginning of the buffer that 
                                          ///  all data reads should occur from.

  //  **************************************************************************
  /// Provides access to the packed memory buffer.
  /// 
  /// @return       A pointer to the buffer that contains the packed memory.
  ///               0 is returned if there is no memory associated with the buffer.
  ///
  pointer raw_data()
  {
    return m_pData;
  }

  // Let all message buffer objects be friends for data transfer.
  template< typename T>
  friend
  class MsgBuffer;
};

} // namespace Hg


#endif
