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
//  ****************************************************************************
template< typename T,
          size_t   N,
          typename BufferT
        >
size_t DeserializeInBulk( std::array<T,N>&, BufferT&, size_t);

//  ****************************************************************************
template< typename T,
          size_t   N,
          typename BufferT
        >
size_t DeserializeByItem( std::array<T,N>&, BufferT&, size_t);

//  ****************************************************************************
//  Adapter function to simplify deserializing a buffer from a vector-field.
//
template< class T,
          class A,
          class BufferT,
          template <typename, typename> class VectorT
        >
size_t DeserializeVector (VectorT<T, A>  &value,
                          size_t          count,
                          BufferT        &buffer,
                          size_t          offset);

//  ****************************************************************************
template< class     T,
          size_t    N,
          class     BufferT,
          template <typename, size_t> class ArrayT
        >
size_t DeserializeArray ( ArrayT<T, N> &value,
                          BufferT  &buffer,
                          size_t    offset);


//  ****************************************************************************
//  Array Implementation *******************************************************
namespace Array
{

//  ****************************************************************************
//  Imports data from the array for fixed-size POD types.
//
template< typename ArrayT,
          typename BufferT,
          typename TraitT
        >
struct Deserializer
{
  using array_type      = ArrayT;
  using value_type      = typename array_type::value_type;
  using buffer_type     = BufferT;
  using data_type_trait = TraitT;

  static 
    const size_t value = Hg::detail::array_size<array_type>::value;

  //  **************************************************************************
  size_t Read ( array_type   &value, 
                size_t        count, 
                buffer_type  &buffer,
                size_t        offset)
  {
    if (0 == count)
    {
      return 0;
    }

    // Calculate the size of data to write in bytes.
    size_t size = count * sizeof(value_type);

    value_type *pFirst = &value[0];
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
//  Imports an array of nested types with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Deserializer <std::array<T,N>, BufferT, nested_trait>
  : public std::integral_constant<size_t, N>
{
  using array_type        = std::array<T,N>;
  using buffer_type       = BufferT;
  using data_type_trait   = nested_trait;
  using value_type        = T;
  using value_format_type = typename value_type::format_type;

  //  **************************************************************************
  size_t Read ( array_type     &value, 
                size_t          count, 
                buffer_type    &buffer,
                size_t          offset)
  {
    if (0 == count)
    {
      return 0;
    }

    size_t bytes_read = 0;

    // Process each item individually.
    for (size_t index = 0; index < count; ++index)
    {
      // The offset for each item progressively increases
      // by the number of bytes read from the input buffer.
      size_t item_offset = offset + bytes_read;

      bytes_read += Read(value[index], buffer, item_offset);
    }

    return bytes_read;
  }  

  //  **************************************************************************
  size_t Read ( value_type     &value, 
                buffer_type    &buffer,
                size_t          offset)
  {
    return  unpack_message< value_type,
                            buffer_type,
                            message_size_trait_t<value_format_type>
                          >(value, buffer, offset);
  }
};



//  ****************************************************************************
//  Imports a array of arrays with each sub-item written individually.
//
template< class   T,
          size_t  N,
          class   BufferT
        >
struct Deserializer <std::array<T,N>, BufferT, array_trait>
  : public std::integral_constant<size_t, N>
{
  using array_type = std::array<T,N>;

  using value_type = typename array_type::value_type;
  using buffer_type= BufferT;

  // The next step discriminates on the value_type managed
  // by the array to select the most efficient and correct
  // method of deserializing the data.
  using data_type_trait = typename Hg::detail::deduce_type_trait_t<value_type>;

  //  **************************************************************************
  size_t Read ( array_type     &value, 
                size_t          count, 
                buffer_type    &buffer,
                size_t          offset)
  {
    return DeserializeByItem(value, buffer, offset);
  }  

  //  **************************************************************************
template< class    SubT,
          size_t   SubN,
          class    buffer_type,
          template <class, size_t> class ArrayT
        >
  size_t Read ( ArrayT<SubT,SubN> &value, 
                buffer_type       &buffer,
                size_t            offset)
  {
    using sub_array_type = ArrayT<SubT,SubN>;
    using data_type      = typename sub_array_type::value_type;

    const size_t  k_sub_count = Hg::detail::array_size<sub_array_type>::value;

    // Since this is the array handler, 
    // all single value entries passed in will
    // be arrays themselves.
    // Recurse, and start a new decomposition 
    // of array deserialization.
    size_t bytes_written = 
      DeserializeArray( value, buffer, offset);

    return bytes_written;
  }  
};
    
//  ****************************************************************************
//  Imports a array of vectors with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Deserializer <std::array<T,N>, BufferT, vector_trait>
  : public std::integral_constant<size_t, N>
{
  using array_type = std::array<T,N>;
  using value_type = T;
  using buffer_type= BufferT;

  // The next step discriminates on the value_type managed
  // by the array to select the most efficient and correct
  // method of deserializing the data.
  using data_type_trait = typename Hg::detail::deduce_type_trait_t<value_type>;

  //  **************************************************************************
  size_t Read ( array_type  &value, 
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
    using data_type = typename value_type::value_type;

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
template< class   T,
          size_t  N,
          class   BufferT
        >
size_t DeserializeInBulk( std::array<T,N> &value, 
                          BufferT         &buffer,
                          size_t          offset)
{
  using array_type = std::array<T,N>;
  using data_type  = typename array_type::value_type;
  using buffer_type= BufferT;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  using data_type_trait = typename Hg::detail::deduce_type_trait<data_type>;

  using deserializer_t  = Array::Deserializer < array_type, 
                                                buffer_type, 
                                                data_type_trait>;

  const size_t    k_count = value.size();
  deserializer_t  deserializer;
  size_t          bytes_written = 0;

  // TODO: (Optimiztion) Return and add this optimization for bulk reads if possible.
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
template< class   T,
          size_t  N,
          class   BufferT
        >
size_t DeserializeByItem( std::array<T,N> &value, 
                          BufferT         &buffer,
                          size_t          offset)
{
  using array_type = std::array<T,N>;
  using data_type  = typename array_type::value_type;
  using buffer_type= BufferT;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  using data_type_trait = typename Hg::detail::deduce_type_trait_t<data_type>;

  Array::Deserializer < data_type, 
                        buffer_type, 
                        data_type_trait>  deserializer;

  size_t bytes_written = 0;

  // Process each item individually.
  for (size_t index = 0; index < N; ++index)
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
//  Adapter function to simplify deserializing a buffer from an array-field.
//
template< class     T,
          size_t    N,
          class     BufferT,
          template <typename, size_t> class ArrayT
        >
size_t DeserializeArray ( ArrayT<T, N> &value,
                          BufferT  &buffer,
                          size_t    offset)
{
  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  using array_type = ArrayT<T,N>;
  using value_type = T;
  using buffer_type= BufferT;
  using value_type_trait = typename Hg::detail::deduce_type_trait_t<value_type>;

  // Define the correct type of deserialize functor 
  // based on the type contained within the vector.
  using deserializer_t = Array::Deserializer< array_type,
                                              buffer_type,
                                              value_type_trait
                                            >;

  deserializer_t deserializer;
  return deserializer.Read(value, N, buffer, offset);
}

//  ****************************************************************************
//  A specialized functor to read array types.
// 
//  @tparam IdxT              [size_t] The index of the field to read.
//  @tparam MsgT          [typename] The message defintition used to parse the
//                            buffer.
//  @tparam BufferT           [typename] The buffer type that provides the data
//                            to read into the message.  
//  
template< size_t   IdxT,      
          typename MsgT,
          typename BufferT
        >
struct UnpackDatum< IdxT, 
                    MsgT, 
                    BufferT, 
                    array_trait>
{
  //  Aliases ******************************************************************
  using message_type= MsgT;
  using buffer_type = BufferT;
  using format_type = typename MsgT::format_type;


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
  //  @return               The number of bytes read from the buffer.
  //
  size_t operator()(      message_type  &msg,
                    const buffer_type   &buffer,
                          size_t        &dynamic_offset)
  {
    size_t     offset = Hg::offset_of<IdxT, format_type>::value
                      + dynamic_offset;

    // Read directly into the output array.
    size_t bytes_read = 
      DeserializeArray(msg.template FieldAt<IdxT>().get(), buffer, offset);

    dynamic_offset += bytes_read;

    return bytes_read;
  }
};

} // namespace detail

} // namespace Hg

#endif 
