/// @file test_helper.h
///
/// This is a utility class that provides common functions for
/// testing constructs in the Hg API.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TEST_HELPER_H_INCLUDED
#define TEST_HELPER_H_INCLUDED
//  Includes *******************************************************************
#include <alchemy.h>

//  ****************************************************************************
/// @brief          This helper class provides a common set of basic operations
///                 that are used for testing Hg constructs.
///
/// @param T                  [typename] The default type used to create a
///                           message buffer for testing.
/// @param buffer_type        [typename] This is the type of pointer that will
///                           be referenced with the buffer management functions.
///
template <typename T,
          typename storage_t>
struct HgTestHelper
{
  //  Typedefs *******************************************************************
  typedef storage_t                                             storage_type;
  typedef typename storage_type::data_type                      data_type;
  typedef typename storage_type::s_pointer                      s_pointer;
  typedef typename storage_type::w_pointer                      w_pointer;

  //  Data Members ***************************************************************
  s_pointer              m_sp_buffer;

  //  Methods ********************************************************************
  template <typename FormatT>
  s_pointer create_data_bufferT()
  {
    const size_t k_len = Hg::SizeOf<FormatT>::value;
    return s_pointer(new(std::nothrow) data_type[k_len]);
  }

  //  ****************************************************************************
  s_pointer get_buffer()
  {
    if (!m_sp_buffer)
    {
      m_sp_buffer = create_data_bufferT<T>();
    }
    
    return m_sp_buffer;
  }

  //  ****************************************************************************
  size_t get_length()
  {
    return Hg::SizeOf<T>::value;
  }

  //  ****************************************************************************
  void clear_buffer()
  {
    m_sp_buffer.reset();
  }

  //  ****************************************************************************
  template <typename value_t>
  value_t read_from_offset(s_pointer& spBuffer, size_t offset)
  {
    if (!spBuffer)
      return value_t();

    value_t  result;
    ::memcpy( &result,
              &(spBuffer.get())[offset],
              sizeof(value_t));
    return result;
  }

  //  ****************************************************************************
  template <typename value_t>
  void write_to_offset(s_pointer& spBuffer, size_t offset, const value_t& value)
  {
    if (!spBuffer)
      return;

    ::memcpy( &(spBuffer.get())[offset],
              &value,
              sizeof(value_t));
  }


};

#endif
