/// @file detail/pack_array.h
/// 
/// The implementation to pack a fixed-size array into a Hg Message buffer.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_ARRAY_H_INCLUDED
#define PACK_ARRAY_H_INCLUDED
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
template< typename T,
          size_t   N,
          typename BufferT
        >
size_t SerializeInBulk( std::array<T,N>&, BufferT&, size_t);

template< typename T,
          size_t   N,
          typename BufferT
        >
size_t SerializeByItem( std::array<T,N>&, BufferT&, size_t);


namespace Array
{


//  ****************************************************************************
//  Exports data from the vector for fixed-size POD types.
//
template< typename ArrayT,
          typename BufferT,
          typename TraitT
        >
struct Serializer
{
  typedef ArrayT                        array_type;
  
  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  typedef TraitT                        data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Write( array_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    // Calculate the size of data to write in bytes.
    size_t size = value.size() * sizeof(value_type);

    value_type *pFirst = &value[0];
    value_type *pLast  = pFirst;

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
//  Exports arrays of bit-field values into a packed buffer.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Serializer <Hg::BitFieldArray<T,N>, BufferT, bitfield_trait>
{
  typedef Hg::BitFieldArray<T,N>        array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  typedef bitfield_trait                data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Write( array_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    // Calculate the size of data to write in bytes.
    size_t size = value.size() * sizeof(value_type);

    value_type *pFirst = value.data();
    value_type *pLast  = pFirst;

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
//  Exports a nested_trait with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Serializer <std::array<T,N>, BufferT, nested_trait>
{
  typedef std::array<T,N>               array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  typedef nested_trait                  data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Write( array_type     &value, 
                buffer_type    &buffer,
                size_t          offset)
  {
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

      size_t write_len =
        pack_message< value_type,
                      buffer_type,
                      size_trait
                    >(value[index], buffer, item_offset);

      bytes_written += write_len;
    }

    return bytes_written;
  }  
};



//  ****************************************************************************
//  Exports an array with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Serializer <std::array<T,N>, BufferT, array_trait>
{
  typedef std::array<T,N>               array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Write( array_type     &value, 
                buffer_type    &buffer,
                size_t          offset)
  {
    return SerializeInBulk(value, buffer, offset);
  }  

  //  **************************************************************************
  size_t Write( value_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return SerializeByItem(value, buffer, offset);
  }  
};
    
//  ****************************************************************************
//  Exports an array with each sub-item written individually.
//
template< typename T,
          size_t   N,
          typename BufferT
        >
struct Serializer <std::array<T,N>, BufferT, vector_trait>
{
  typedef std::array<T,N>               array_type;

  typedef typename
    array_type::value_type              value_type;

  typedef BufferT                       buffer_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              data_type_trait;

  //  **************************************************************************
  template <typename TraitT>
  size_t Write( array_type   &value, 
                buffer_type  &buffer,
                size_t        offset)
  {
    return SerializeInBulk(value, buffer, offset);
  }  

  //  **************************************************************************
  template <>
  size_t Write<vector_trait>( array_type   &value, 
                              buffer_type  &buffer,
                              size_t        offset)
  {
    return SerializeByItem(value, buffer, offset);
  }  

  //  **************************************************************************
  size_t Write( value_type   &value, 
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
      SerializeVector < data_type,
                        allocator_type,
                        buffer_type
                      >(value, 
                        value.size(), 
                        buffer, 
                        offset);

    return bytes_written;
  }  
};
    

} // namespace Array

//  **************************************************************************
//  This version writes all of the items to the buffer at once.
//
template< typename ValueT,
          typename BufferT
        >
size_t SerializeInBulk( ValueT     &value, 
                        BufferT    &buffer,
                        size_t      offset)
{
  typedef ValueT                        array_type;

  typedef typename
    array_type::value_type              data_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < data_type >::type               data_type_trait;

  Array::Serializer < array_type,
                      BufferT, 
                      data_type_trait>  serializer;

  size_t bytes_written = 0;

  // Process each item individually.
  for (size_t index = 0; index < value.size(); ++index)
  {
    // The offset for each item progressively increases
    // by the number of bytes read from the input buffer.
    size_t item_offset = offset + bytes_written;

    // Export sub-values one item at a time.
    size_t write_len = 
      serializer.Write( value[index], 
                        buffer, 
                        item_offset);

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
template< typename ValueT,
          typename BufferT
        >
size_t SerializeByItem( ValueT     &value, 
                        BufferT    &buffer,
                        size_t      offset)
{
  typedef ValueT                        array_type;

  typedef typename
    array_type::value_type              data_type;

  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < data_type >::type               data_type_trait;

  Array::Serializer < data_type, 
                      allocator_type,
                      BufferT, 
                      data_type_trait>  serializer;

  size_t bytes_written = 0;

  // Process each item individually.
  for (size_t index = 0; index < count; ++index)
  {
    // The offset for each item progressively increases
    // by the number of bytes read from the input buffer.
    size_t item_offset = offset + bytes_written;

    // Export sub-values one item at a time.
    size_t write_len = 
      serializer.Write( value[index], 
                        buffer, 
                        item_offset);

    bytes_written += write_len;
  }

  return bytes_written;
}

//  ****************************************************************************
//  Adapter function to simplify serializing a buffer from a vector-field.
//
template< typename T,
          size_t   N,
          typename BufferT,
          template <typename, size_t> class ArrayT
        >
size_t SerializeArray(ArrayT<T,N> &value,
                      BufferT     &buffer,
                      size_t      offset)
{
  // The next step discriminates on the value_type managed
  // by the vector to select the most efficient and correct
  // method of serializing the data.
  typedef ArrayT<T,N>                   array_type;

  typedef T                             value_type;

  typedef typename 
    Hg::detail::DeduceTypeTrait
      < value_type >::type              value_type_trait;

  // Define the correct type of serialize functor 
  // based on the type contained within the vector.
  typedef Array::Serializer < array_type,
                              BufferT, 
                              value_type_trait
                            >           serializer_t;
  typedef typename
    serializer_t::data_type_trait       data_type_trait;

  serializer_t serializer;
  return serializer.Write<data_type_trait>(value, buffer, offset);
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
          typename MessageT,
          typename BufferT
        >
struct PackDatum< IdxT, 
                  MessageT, 
                  BufferT, 
                  array_trait>
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
  //  Writes a fixed-size field of items to the specified buffer.
  // 
  //  @param msg          The message object to supply the data to be written.
  //  @param buffer       The buffer object to write into.
  //  @param dynamic_size An additional offset for messages with dynamically 
  //                      sized fields. The length of the dynamic field written 
  //                      will be added to this input value to report how much 
  //                      larger the message has become. 
  //
  void operator()(const MessageT& msg,
                        BufferT&  buffer,
                        size_t&   dynamic_offset)
  {
    value_type value = const_cast<MessageT&>(msg).template FieldAt<IdxT>().get();
    
    // Exit if there are no entries in this dynamic value.
    if (value.empty())
    {
      return;
    }

    // Calculate the total size of this dynamic-field.
    size_t length = dynamic_size(value);


    size_t     offset = Hg::OffsetOf<IdxT, MessageT::format_type>::value
                      + dynamic_offset;

    // The remaining size must be determined on an element-by-element basis.

    size_t bytes_written = 
      SerializeArray(value, buffer, offset);

    // Update the accumulated dynamic size with the 
    // new length added by the size of this field.
    dynamic_offset += bytes_written;
  }
};

} // namespace detail

} // namespace Hg

#endif 
