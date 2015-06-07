/// @file detail/pack_vector.h
/// 
/// The implementation to pack dynamically sized field in a message buffer.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_VECTOR_H_INCLUDED
#define PACK_VECTOR_H_INCLUDED
//  Private Usage Include Guard ************************************************
//  Only allow this header file to be included through pack_message.h
#ifndef PACK_MESSAGE_H_INCLUDED
# error Do not include this file directly. Use <detail/pack_message.h> instead
#endif

namespace Hg
{

namespace detail
{

//  Forward Declarations *******************************************************
template< typename ValueT,
          typename BufferT
        >
size_t SerializeInBulk( ValueT  &value, 
                        BufferT &buffer,
                        size_t  offset);

template< class T,
          class A,
          class BufferT
        >
size_t SerializeByItem( std::vector<T,A>  &value, 
                        BufferT           &buffer,
                        size_t             offset);

namespace Vector
{

//  ****************************************************************************
//  Exports data from the vector for fixed-size POD types.
//
template< typename VectorT,
          typename BufferT,
          typename SerializerTraitT
        >
struct Serializer;
//  ****************************************************************************
//  Exports data from the vector for fixed-size fundamental types.
//
template< typename VectorT,
          typename BufferT
        >
struct Serializer <VectorT, BufferT, fundamental_trait>
{
  using vector_type     = VectorT;
  using value_type      = typename vector_type::value_type;
  using buffer_type     = BufferT;
  using data_type_trait = fundamental_trait;

  //  **************************************************************************
  size_t Write( vector_type   &value, 
                buffer_type   &buffer,
                size_t        offset)
  {
    // Calculate the size of data to write in bytes.
    size_t size = value.size() * sizeof(value_type);

    const value_type *pFirst = &value[0];
    const value_type *pLast  = pFirst;

    std::advance(pLast, size);
    buffer.set_range( pFirst, 
                      pLast, 
                      offset);

    return size;
  }

  //  **************************************************************************
  size_t Write( value_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    buffer.set_data( value, offset);
    return sizeof(value_type);
  }

};



//  ****************************************************************************
//  Exports a vector of nested types with each sub-item written individually.
//
template< typename ValueT,
          typename AllocatorT,
          typename BufferT
        >
struct Serializer <std::vector<ValueT, AllocatorT>, BufferT, nested_trait>
{
  using vector_type       = std::vector<ValueT, AllocatorT>;
  using buffer_type       = BufferT;
  using data_type_trait   = nested_trait;
  using value_type        = typename vector_type::value_type;
  using value_format_type = typename value_type::format_type;

  //  **************************************************************************
  size_t Write( vector_type   &value, 
                buffer_type   &buffer,
                size_t         offset)
  {
    size_t bytes_written = 0;

    // Process each item individually.
    for (size_t index = 0; index < value.size(); ++index)
    {
      // The offset for each item progressively increases
      // by the number of bytes read from the input buffer.
      size_t item_offset = offset + bytes_written;

      size_t write_len =
        pack_message< value_type,
                      buffer_type,
                      message_size_trait_t<value_format_type>
                    >(value[index], buffer, item_offset);

      bytes_written += write_len;
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
struct Serializer <std::vector<ValueT, AllocatorT>, BufferT, array_trait>
{
  using vector_type = std::vector<ValueT, AllocatorT>;
  using value_type  = typename vector_type::value_type;
  using buffer_type = BufferT;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  using data_type_trait = typename Hg::detail::deduce_type_trait_t<value_type>;

  //  **************************************************************************
  size_t Write( vector_type   &items, 
                buffer_type   &buffer,
                size_t         offset)
  {
    return SerializeByItem(items, buffer, offset);
  }  

  //  **************************************************************************
  size_t Write( value_type  &value, 
                buffer_type &buffer,
                size_t       offset)
  {
    return SerializeArray(value, buffer, offset);
  }  

};
    
//  ****************************************************************************
//  Exports a vector of vectors with each sub-item written individually.
//
template< typename ValueT,
          typename AllocatorT,
          typename BufferT
        >
struct Serializer <std::vector<ValueT, AllocatorT>, BufferT, vector_trait>
{
  using vector_type = std::vector<ValueT, AllocatorT>;
  using value_type  = typename vector_type::value_type;
  using buffer_type = BufferT;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  using data_type_trait = typename Hg::detail::deduce_type_trait_t<value_type>;

  //  **************************************************************************
  size_t Write( vector_type  &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return SerializeByItem(value, buffer, offset);
  }  

  //  **************************************************************************
  size_t Write( value_type  &value, 
                buffer_type       &buffer,
                size_t            offset)
  {
    size_t bytes_written = 
      SerializeVector(value, buffer, offset);

    return bytes_written;
  }
};
    
} // namespace Vector

//  **************************************************************************
//  This version writes all of the items to the buffer at once.
//
template< class T,
          class A,
          class BufferT
        >
size_t SerializeInBulk( const std::vector<T,A>  &value, 
                        BufferT                 &buffer,
                        size_t                  offset)
{
  using vector_type     = std::vector<T,A>;
  using data_type       = typename vector_type::value_type;
  using allocator_type  = typename vector_type::allocator_type;
  using buffer_type     = BufferT;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  using data_type_trait = Hg::detail::deduce_type_trait_t<data_type>;

  Vector::Serializer< vector_type,
                      buffer_type, 
                      data_type_trait>  serializer;

  size_t bytes_written = 0;
// TODO: (Optimization) Return and add this optimization for bulk writes for types that are possible.
  // Process each item individually.
  for (size_t index = 0; index < value.size(); ++index)
  {
    // The offset for each item progressively increases
    // by the number of bytes read from the input buffer.
    size_t item_offset = offset + bytes_written;

    // Export sub-values one item at a time.
    size_t write_len = 
      serializer.Write( value[index], buffer, item_offset);

    bytes_written += write_len;
  }

  return bytes_written;
}


//  **************************************************************************
//  This version writes each item from the raw buffer individually.
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
size_t SerializeByItem( std::vector<T,A>  &value, 
                        BufferT           &buffer,
                        size_t             offset)
{
  using vector_type     = std::vector<T,A>;
  using data_type       = typename vector_type::value_type;
  using allocator_type  = typename vector_type::allocator_type;
  using buffer_type     = BufferT;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  using data_type_trait = typename Hg::detail::deduce_type_trait_t<data_type>;

  Vector::Serializer< vector_type, 
                      buffer_type, 
                      data_type_trait>  serializer;

  size_t bytes_written = 0;

  // Process each item individually.
  for (size_t index = 0; index < value.size(); ++index)
  {
    // The offset for each item progressively increases
    // by the number of bytes read from the input buffer.
    auto item_offset = offset + bytes_written;

    // Export sub-values one item at a time.
    auto write_len = 
      serializer.Write( value[index], buffer, item_offset);

    bytes_written += write_len;
  }

  return bytes_written;
}

//  ****************************************************************************
//  Adapter function to simplify serializing a buffer from a vector-field.
//
template< class T,
          class A,
          class BufferT,
          template <class, class> class VectorT
        >
size_t SerializeVector (VectorT<T, A> &value,
                        BufferT       &buffer,
                        size_t         offset)
{
  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  using vector_type       = VectorT<T, A>;
  using value_type        = T;
  using value_type_trait  = typename Hg::detail::deduce_type_trait_t<value_type>;
  using buffer_type       = BufferT;

  // Define the correct type of serialize functor 
  // based on the type contained within the vector.
  using serializer_t = Vector::Serializer < vector_type,
                                            buffer_type, 
                                            value_type_trait
                                          >;
  serializer_t serializer;
  return serializer.Write(value, buffer, offset);
}


//  ****************************************************************************
//  A specialized functor to write a vector type.
// 
//  @tparam T       [typename] The value_type for this specialization
//                  is actually a format_type for the dyanmically sized vectors.
//  
//  @return         Returns the item after the last element written by this call.
//
template< size_t   IdxT,      
          typename MsgT,
          typename BufferT
        >
struct PackDatum< IdxT, 
                  MsgT, 
                  BufferT, 
                  vector_trait>
{
  //  Aliases ******************************************************************
  using message_type= MsgT;
  using buffer_type = BufferT;
  using format_type = typename MsgT::format_type;


  //  **************************************************************************
  //  Writes a dynamically-size field to the specified buffer.
  // 
  //  @param msg          The message object to supply the data to be written.
  //  @param buffer       The buffer object to write into.
  //  @param dynamic_size An additional offset for messages with dynamically 
  //                      sized fields. The length of the dynamic field written 
  //                      will be added to this input value to report how much 
  //                      larger the message has become. 
  //
  void operator()(message_type& msg,
                  buffer_type&  buffer,
                  size_t&       dynamic_offset)
  {
    auto &value = msg.template FieldAt<IdxT>().get();
    
    // Exit if there are no entries in this dynamic value.
    if (value.empty())
    {
      return;
    }

    // Calculate the total starting offset.
    size_t offset = Hg::offset_of<IdxT, format_type>::value
                  + dynamic_offset;

    size_t bytes_written = 
      SerializeVector(value, buffer, offset);

    // Update the accumulated dynamic size with the 
    // new length added by the size of this field.
    dynamic_offset += bytes_written;
  }
};

} // namespace detail

} // namespace Hg

#endif 
