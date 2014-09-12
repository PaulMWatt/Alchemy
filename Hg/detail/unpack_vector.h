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
//  Includes *******************************************************************
#include <meta/bit_field/bit_field_vector.h>

namespace Hg
{

namespace detail
{

//  Forward Declarations *******************************************************
template< class T,
          class A,
          class BufferT
        >
size_t DeserializeInBulk( std::vector<T,A>&, BufferT&, size_t);

template< class T,
          class A,
          class BufferT
        >
size_t DeserializeByItem( std::vector<T,A>&, BufferT&, size_t);


namespace Vector
{

//  ****************************************************************************
//  Imports data from the vector for fixed-size POD types.
//
template< typename VectorT,
          typename BufferT,
          typename TraitT
        >
struct Deserializer;



//  ****************************************************************************
//  Imports data from the vector for fixed-size fundamental types.
//
template< typename VectorT,
          typename BufferT
        >
struct Deserializer <VectorT, BufferT, fundamental_trait>
{
  typedef VectorT                       vector_type;

  typedef typename
    vector_type::value_type             value_type;

  typedef BufferT                       buffer_type;

  typedef fundamental_trait             data_type_trait;

  // TODO: These types should appear in this version:
  //       - fundamental_trait

  //  **************************************************************************
  size_t Read ( vector_type   &value, 
                size_t        count,
                buffer_type   &buffer,
                size_t        offset)
  {
    if (0 == count)
    {
      return 0;
    }

    // Calculate the size of data to write in bytes.
    size_t size = count * sizeof(value_type);


    value_type *pFirst = &value[0];

    // TODO: Make the interfaces consistent between the set and get.
    //value_type *pLast  = pFirst;
    //std::advance(pLast, size);

    return buffer.get_range(pFirst, size, offset);
  }
};

//  ****************************************************************************
//  Imports an vector of bit-list fields.
//
template< typename T,
          typename A,
          typename BufferT
        >
struct Deserializer <Hg::BitFieldVector<T,A>, BufferT, bitfield_trait>
{
  typedef Hg::BitFieldVector<T,A>       vector_type;
  typedef T                             value_type;
  typedef BufferT                       buffer_type;
  typedef bitfield_trait                data_type_trait;

  //  **************************************************************************
  size_t Read ( vector_type  &value, 
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

    value_type *pFirst = value.data();

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
//  Exports a vector of nested types with each sub-item written individually.
//
template< typename T,
          typename A,
          typename BufferT
        >
struct Deserializer <std::vector<T, A>, BufferT, nested_trait>
{
  typedef std::vector<T,A>              vector_type;
  typedef T                             value_type;
  typedef BufferT                       buffer_type;
  typedef nested_trait                  data_type_trait;

  //  **************************************************************************
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
template< typename T,
          typename A,
          typename BufferT
        >
struct Deserializer <std::vector<T, A>, BufferT, array_trait>
{
  typedef std::vector<T,A>              vector_type;
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
  size_t Read ( vector_type    &value, 
                size_t          count, 
                buffer_type    &buffer,
                size_t          offset)
  {
    return DeserializeByItem(value, buffer, offset);
  }  

  //  **************************************************************************
  size_t Read ( value_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return DeserializeArray(value, buffer, offset);
  }  
};
    
//  ****************************************************************************
//  Exports a vector of vectors with each sub-item written individually.
//
template< typename T,
          typename A,
          typename BufferT
        >
struct Deserializer <std::vector<T, A>, BufferT, vector_trait>
{
  typedef std::vector<T, A>             vector_type;
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
  size_t Read ( vector_type  &value, 
                size_t        count, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return DeserializeByItem(value, buffer, offset);
  }  

  //  **************************************************************************
  size_t Read ( value_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    size_t bytes_written = 
      DeserializeVector(value, value.size(), buffer, offset);

    return bytes_written;
  }  
};
    
} // namespace Vector

//  **************************************************************************
//  This version reads all of the items to the buffer at once.
//
template< class T,
          class A,
          class BufferT
        >
size_t DeserializeInBulk( std::vector<T,A> &value, 
                          size_t            count, 
                          BufferT          &buffer,
                          size_t            offset)
{
  typedef std::vector<T,A>              vector_type;

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

  typedef 
    Vector::Deserializer
      < vector_type, 
        BufferT, 
        data_type_trait
      >                                 deserializer_t;

  deserializer_t  deserializer;
  size_t          bytes_written = 0;
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
template< class T,
          class A,
          class BufferT
        >
size_t DeserializeByItem( std::vector<T,A>  &value, 
                          BufferT           &buffer,
                          size_t            offset)
{
  typedef std::vector<T,A>              vector_type;

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

  size_t count = value.size();
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
template< class T,
          class A,
          class BufferT,
          template <typename, typename> class VectorT
        >
size_t DeserializeVector (VectorT<T, A>  &value,
                          size_t          count,
                          BufferT        &buffer,
                          size_t          offset)
{
  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of deserializing the data.
  typedef VectorT<T, A>                 vector_type;

  typedef T                             value_type;

  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              value_type_trait;


  // Define the correct type of deserialize functor 
  // based on the type contained within the vector.
  typedef Vector::Deserializer< vector_type,
                                BufferT,
                                value_type_trait
                              >         deserializer_t;

  deserializer_t deserializer;
  return deserializer.Read(value, count, buffer, offset);
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
struct UnpackDatum< IdxT, 
                    MessageT, 
                    BufferT, 
                    vector_trait>
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

  typedef MessageT                                message_type;

  typedef BufferT                                 buffer_type;

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
  void operator()(      message_type &msg,
                  const buffer_type  &buffer,
                        size_t   &dynamic_offset)
  {
    value_type value  = value_type();
    size_t     offset = Hg::OffsetOf<IdxT, typename message_type::format_type>::value
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
      DeserializeVector(value, count, buffer, offset);

    // TODO: Look into reading directly into the vector without the copy.
    msg.template FieldAt<IdxT>().set(value);

    dynamic_offset += bytes_read;
  }
};

} // namespace detail

} // namespace Hg

#endif 
