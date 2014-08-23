/// @file detail/unpack_array.h
/// 
/// A specialization to unpack a raw buffer of bytes into an array.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef UNPACK_ARRAY_H_INCLUDED
#define UNPACK_ARRAY_H_INCLUDED
//  Private Usage Include Guard ************************************************
//  Only allow this header file to be included through unpack_message.h
#ifndef UNPACK_MESSAGE_H_INCLUDED
# error Do not include this file directly. Use <detail/unpack_message.h> instead
#endif

namespace Hg
{

namespace detail
{

//  Forward Declarations *******************************************************
template< typename T,
          size_t   N,
          typename BufferT
        >
size_t DeserializeInBulk( std::array<T,N>&, BufferT&, size_t);

template< typename T,
          size_t   N,
          typename BufferT
        >
size_t DeserializeByItem( std::array<T,N>&, BufferT&, size_t);


namespace Array
{

//  ****************************************************************************
//  Exports data from the aryy for fixed-size POD types.
//
template< typename ArrayT,
          typename BufferT,
          typename TraitT
        >
struct Deserializer
{
  typedef ArrayT                        array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  typedef TraitT                        data_type_trait;

  // TODO: This is not guaranteed to be the correct size. Work towards getting the array size deduction method to work.
  static 
    const size_t value = sizeof(array_type)/sizeof(value_type);

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( array_type   &value, 
                size_t        count, 
                buffer_type  &buffer,
                size_t        offset)
  {
    if (0 == count)
    {
      return 0;
    }

    // TODO: Currently it appears that the full-length in bytes is required 
    //       rather than the count, like an iterator would require.
    //       Revisit and verify this is correct.
    size_t size = count * sizeof(value_type);


    value_type *pFirst = &value[0];

    // TODO: Make the interfaces consistent between the set and get.
    //value_type *pLast  = pFirst;
    //std::advance(pLast, size);

    return buffer.get_range(pFirst, size, offset);
  }


  //  **************************************************************************
  size_t Read ( value_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return buffer.get_data( value, offset);
  }

};


//  ****************************************************************************
//  Exports a array of nested types with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Deserializer <std::array<T,N>, BufferT, nested_trait>
  : public std::integral_constant<size_t, N>
{
  typedef std::array<T,N>               array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  typedef nested_trait                  data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( array_type     &value, 
                size_t          count, 
                buffer_type    &buffer,
                size_t          offset)
  {
    if (0 == count)
    {
      return 0;
    }

    // An important typedef for selecting the proper
    // version of the unpack function for the sub-elements.
    typedef typename
      message_size_trait<value_type::format_type>::type     size_trait;

    size_t bytes_written = 0;

    // Process each item individually.
    for (size_t index = 0; index < count; ++index)
    {
      // The offset for each item progressively increases
      // by the number of bytes read from the input buffer.
      size_t item_offset = offset + bytes_written;

      size_t read_len =
        unpack_message< value_type,
                        buffer_type,
                        size_trait
                      >(value[index], buffer, item_offset);

      bytes_written += read_len;
    }

    return bytes_written;
  }  
};



//  ****************************************************************************
//  Exports a array of arrays with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Deserializer <std::array<T,N>, BufferT, array_trait>
  : public std::integral_constant<size_t, N>
{
  typedef typename
    std::array<T,N>                     array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  // The next step discriminates on the value_type managed
  // by the array to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( array_type     &value, 
                buffer_type    &buffer,
                size_t          offset)
  {
    return DeserializeInBulk(value, N, buffer, offset);
  }  

  //  **************************************************************************
  size_t Read ( array_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return DeserializeByItem(value, buffer, offset);
  }  
};
    
//  ****************************************************************************
//  Exports a array of vectors with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Deserializer <std::array<T,N>, BufferT, vector_trait>
  : public std::integral_constant<size_t, N>
{
  typedef std::array<T,N>               array_type;
  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  // The next step discriminates on the value_type managed
  // by the array to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( array_type   &value, 
                size_t        count, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return DeserializeInBulk(value, count, buffer, offset);
  }  

  //  **************************************************************************
  template <>
  size_t Read <vector_trait>( array_type  &value, 
                              size_t        count, 
                              buffer_type  &buffer,
                              size_t        offset)
  {
    return DeserializeByItem(value, count, buffer, offset);
  }  

  //  **************************************************************************
  size_t Read ( value_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    typedef typename
      value_type::value_type            data_type;

    // Since this is the vector handler, 
    // all single value entries passed in will
    // be vectors themselves.
    size_t bytes_written = 
      DeserializeVector< data_type,
                        buffer_type
                      >(value, value.size(), buffer, offset);

    return bytes_written;
  }  
};
    
} // namespace Array

//  **************************************************************************
//  This version reads all of the items to the buffer at once.
//
template< typename ValueT,
          typename BufferT
        >
size_t DeserializeInBulk( ValueT     &value, 
                          BufferT    &buffer,
                          size_t      offset)
{
  typedef ValueT                        array_type;

  typedef typename
    array_type::value_type              data_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < data_type >::type               data_type_trait;

  typedef 
    Array::Deserializer 
      < array_type, 
        BufferT, 
        data_type_trait>                deserializer_t;

  const size_t      k_count = value.size();
  deserializer_t    deserializer;
  size_t bytes_written = 0;
// TODO: Return and add this optimization for bulk reads if possible.

  // Process each item individually.
  for (size_t index = 0; index < k_count; ++index)
  {
    // The offset for each item progressively increases
    // by the number of bytes read from the input buffer.
    size_t item_offset = offset + bytes_written;

    // Export sub-values one item at a time.
    size_t read_len = 
      deserializer.Read( value[index], buffer, item_offset);

    bytes_written += read_len;
  }

  return bytes_written;
}


//  **************************************************************************
//  This version reads each item from the raw buffer individually.
//  These fields may be because they are distinct fields of a nested definition,
//  or variable length items.
//
//  ValueT        Must be a type that contains a sub-type defined as value_type.
//                Such as std::vector or std::array
//
template< typename ValueT,
          typename BufferT
        >
size_t DeserializeByItem( ValueT     &value, 
                          BufferT    &buffer,
                          size_t      offset)
{
  typedef ValueT                        array_type;

  typedef typename
    array_type::value_type              data_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < data_type >::type               data_type_trait;

  Array::Deserializer < data_type, 
                        BufferT, 
                        data_type_trait>  deserializer;

  size_t bytes_written = 0;

  // Process each item individually.
  for (size_t index = 0; index < count; ++index)
  {
    // The offset for each item progressively increases
    // by the number of bytes read from the input buffer.
    size_t item_offset = offset + bytes_written;

    // Export sub-values one item at a time.
    size_t read_len = 
      deserializer.Read( value[index], buffer, item_offset);

    bytes_written += read_len;
  }

  return bytes_written;
}

//  ****************************************************************************
//  Adapter function to simplify deserializing a buffer from a vector-field.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
size_t DeserializeArray ( std::array<T, N> &value,
                          BufferT  &buffer,
                          size_t    offset)
{
  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef std::array<T,N>               array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              value_type_trait;


  // Define the correct type of deserialize functor 
  // based on the type contained within the vector.
  typedef Array::Deserializer < array_type,
                                BufferT, 
                                value_type_trait
                              >           deserializer_t;
  typedef typename
    deserializer_t::data_type_trait       data_type_trait;

  deserializer_t deserializer;
  return deserializer.Read<data_type_trait>(value, N, buffer, offset);
}



//  ****************************************************************************
//  A specialized functor to read array types.
// 
//  @tparam IdxT              [size_t] The index of the field to read.
//  @tparam MessageT          [typename] The message defintition used to parse the
//                            buffer.
//  @tparam BufferT           [typename] The buffer type that provides the data
//                            to read into the message.  
//  
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
struct UnpackDatum<IdxT, MessageT, BufferT, array_trait>
{
  //  Typedefs *****************************************************************
  typedef typename
    Hg::detail::DeduceProxyType 
      < IdxT,
        typename MessageT::format_type,
        MessageT::k_base_offset
      >::type                                     proxy_type;

  typedef typename
    proxy_type::value_type                        value_type;
  typedef typename
    value_type::value_type                        data_type;

  typedef typename
    Hg::detail::DeduceTypeTrait
      < data_type >::type                         data_type_trait;


  //  **************************************************************************
  //  Reads a dynamically-size field from the specified buffer.
  // 
  //  @param msg            The message object to accept the data to be read.
  //  @param buffer         The buffer object to read from.
  //  @param dynamic_offset An additional offset for messages with dynamically 
  //                        sized fields. The length of the dynamic field read 
  //                        will be added to this input value to report how much 
  //                        larger the message has become. 
  //
  void operator()(      MessageT &msg,
                  const BufferT  &buffer,
                        size_t   &dynamic_offset)
  {

    value_type value  = value_type();
    size_t     offset = Hg::OffsetOf<IdxT, MessageT::format_type>::value
                      + dynamic_offset;
    
    // Query the message object for the number of elements in the buffer;
    size_t      count = value.size();

    // For zero-size move on.
    if (0 == count)
    {
      return;
    }

    size_t bytes_read = 
      DeserializeArray(value, buffer, offset);

    // TODO: Look into reading directly into the array without the copy.
    msg.template FieldAt<IdxT>().set(value);

    dynamic_offset += bytes_read;
  }
};

} // namespace detail

} // namespace Hg

#endif 
