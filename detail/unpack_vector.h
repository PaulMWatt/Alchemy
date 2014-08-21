/// @file detail/unpack_vector.h
/// 
/// Unpacks the bytes from a raw memory buffer into a dynamically sized vector field.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef UNPACK_VECTOR_H_INCLUDED
#define UNPACK_VECTOR_H_INCLUDED
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
template< typename ValueT,
          typename BufferT
        >
size_t DeserializeInBulk( ValueT&, size_t, BufferT&, size_t);

template< typename ValueT,
          typename BufferT
        >
size_t DeserializeByItem( ValueT&, size_t, BufferT&, size_t);


namespace Vector
{

//  ****************************************************************************
//  Exports data from the vector for fixed-size POD types.
//
template< typename ValueT,
          typename AllocatorT,
          typename BufferT,
          typename TraitT
        >
struct Deserializer
{
  typedef typename
    std::vector<ValueT, 
                AllocatorT>             vector_type;
  typedef typename
    vector_type::value_type             value_type;

  typedef BufferT                       buffer_type;

  typedef TraitT                        data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( vector_type  &value, 
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


  ////  **************************************************************************
  ////  Imports data into the vector for fixed-size POD types.
  ////
  //template<typename TraitT>
  //size_t Import(      value_type &value, 
  //                    size_t      count, 
  //              const BufferT    &buffer,
  //                    size_t      offset)
  //{
  //  return  buffer.get_range(&value[0], count * sizeof(data_type), offset)
  //          ? count * sizeof(data_type)
  //          : 0;
  //}

  ////  **************************************************************************
  ////  This version reads each item from the raw buffer individually.
  ////  These fields may be because they are distinct fields of a nested definition,
  ////  or variable length items.
  ////
  //template< >
  //size_t Import<nested_trait>(      
  //                    value_type &value, 
  //                    size_t      count, 
  //              const BufferT    &buffer,
  //                    size_t      offset)
  //{
  //  // TODO:  Will need to modify the definitions for:
  //  //          data_type::format_type
  //  //        To be a more robust version to properly support
  //  //        vectors of vectors and vectors of arrays.

  //  // An important typedef for selecting the proper
  //  // version of the unpack function for the sub-elements.
  //  typedef typename
  //    message_size_trait<data_type::format_type>::type     size_trait;


  //  size_t bytes_read = 0;

  //  // Process each item individually.
  //  for (size_t index = 0; index < count; ++index)
  //  {
  //    // The offset for each item progressively increases
  //    // by the number of bytes read from the input buffer.
  //    size_t item_offset = offset + bytes_read;

  //    size_t last_read =
  //      unpack_message< data_type,
  //                      BufferT,
  //                      size_trait
  //                    >(value[index], buffer, item_offset);

  //    bytes_read += last_read;
  //  }

  //  return bytes_read;
  //}



//  ****************************************************************************
//  Exports a vector of nested types with each sub-item written individually.
//
template< typename ValueT,
          typename AllocatorT,
          typename BufferT
        >
struct Deserializer <ValueT, AllocatorT, BufferT, nested_trait>
{
  typedef typename
    std::vector<ValueT, 
                AllocatorT>             vector_type;
  typedef typename
    vector_type::value_type             value_type;

  typedef BufferT                       buffer_type;

  typedef nested_trait                  data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( vector_type    &value, 
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
//  Exports a vector of arrays with each sub-item written individually.
//
template< typename ValueT,
          typename AllocatorT,
          typename BufferT
        >
struct Deserializer <ValueT, AllocatorT, BufferT, array_trait>
{
  typedef typename
    std::vector<ValueT, 
                AllocatorT>             vector_type;
  typedef typename
    vector_type::value_type             value_type;

  typedef BufferT                       buffer_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( vector_type    &value, 
                size_t          count, 
                buffer_type    &buffer,
                size_t          offset)
  {
    return DeserializeInBulk(value, buffer, offset);
//    return 0;
  }  

  //  **************************************************************************
  size_t Read ( vector_type  &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return DeserializeByItem(value, buffer, offset);
//    return 0;
  }  
};
    
//  ****************************************************************************
//  Exports a vector of vectors with each sub-item written individually.
//
template< typename ValueT,
          typename AllocatorT,
          typename BufferT
        >
struct Deserializer <ValueT, AllocatorT, BufferT, vector_trait>
{
  typedef typename
    std::vector<ValueT, 
                AllocatorT>             vector_type;
  typedef typename
    vector_type::value_type             value_type;

  typedef BufferT                       buffer_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Read ( vector_type  &value, 
                size_t        count, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return DeserializeInBulk(value, count, buffer, offset);
  }  

  //  **************************************************************************
  template <>
  size_t Read <vector_trait>( vector_type  &value, 
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

    typedef typename
      value_type::allocator_type        allocator_type;

    // Since this is the vector handler, 
    // all single value entries passed in will
    // be vectors themselves.
    size_t bytes_written = 
      DeserializeVector < data_type,
                        allocator_type,
                        buffer_type
                      >(value, value.size(), buffer, offset);

    return bytes_written;
  }  
};
    
} // namespace Vector

//  **************************************************************************
//  This version reads all of the items to the buffer at once.
//
template< typename ValueT,
          typename BufferT
        >
size_t DeserializeInBulk( ValueT     &value, 
                        size_t      count, 
                        BufferT    &buffer,
                        size_t      offset)
{
  typedef ValueT                        vector_type;

  typedef typename
    vector_type::value_type             data_type;
  typedef typename
    vector_type::allocator_type         allocator_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < data_type >::type               data_type_trait;

  Vector::Deserializer< vector_type, 
                        BufferT, 
                        data_type_trait>  deserializer;

  size_t bytes_written = 0;
// TODO: Return and add this optimization for bulk reads if possible.

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
                        size_t      count, 
                        BufferT    &buffer,
                        size_t      offset)
{
  typedef ValueT                        vector_type;

  typedef typename
    vector_type::value_type             data_type;
  typedef typename
    vector_type::allocator_type         allocator_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < data_type >::type               data_type_trait;

  Vector::Deserializer< data_type, 
                      allocator_type,
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
template< typename ValueT,
          typename AllocatorT,
          typename BufferT
        >
size_t DeserializeVector (std::vector<ValueT, AllocatorT> &value,
                          size_t            count,
                          BufferT          &buffer,
                          size_t            offset)
{
  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef typename
    std::vector<ValueT, AllocatorT>     vector_type;

  typedef typename
    vector_type::value_type             value_type;

  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              value_type_trait;


  // Define the correct type of deserialize functor 
  // based on the type contained within the vector.
  typedef Vector::Deserializer< ValueT,
                                AllocatorT,
                                BufferT,
                                value_type_trait
                              >         deserializer_t;

  typedef typename
    deserializer_t::data_type_trait     data_type_trait;

  deserializer_t deserializer;
  return deserializer.Read<data_type_trait>(value, count, buffer, offset);
}



//  ****************************************************************************
//  A specialized functor to read vector types.
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
struct UnpackDatum<IdxT, MessageT, BufferT, vector_trait>
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
    value_type::allocator_type                    allocator_type;

  typedef MessageT                                message_type;

  typedef BufferT                                 buffer_type;
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
    size_t      count = msg.Size(buffer, msg.template FieldAt<IdxT>());

    // For zero-size move on.
    if (0 == count)
    {
      return;
    }

    // Allocate space for the incoming data.
    value.resize(count);

    size_t bytes_read = 
      DeserializeVector < data_type,
                          allocator_type,
                          BufferT
                        >(value, count, buffer, offset);

    // TODO: Look into reading directly into the vector without the copy.
    msg.template FieldAt<IdxT>().set(value);

    dynamic_offset += bytes_read;
  }
};

} // namespace detail

} // namespace Hg

#endif 
