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
struct PackDatum<IdxT, MessageT, BufferT, vector_trait>
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
  typedef typename 
    Hg::detail::DeduceTypeTrait
      < data_type >::type                         data_type_trait;


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

    // Calculate the full size of the buffer that will be written.
    // Query the value directly for the number of elements.
    size_t count= value.size();

    // The remaining size must be determined on an element-by-element basis.

    size_t bytes_written = 
      Export< data_type_trait>( value, 
                                count, 
                                buffer, 
                                offset);

    // Update the accumulated dynamic size with the 
    // new length added by the size of this field.
    dynamic_offset += bytes_written;
  }
private:
  //  **************************************************************************
  //  Exports data from the vector for fixed-size POD types.
  //
  template<typename TraitT>
  size_t Export ( value_type &value, 
                  size_t      count, 
                  BufferT    &buffer,
                  size_t      offset)
  {
    value_type::value_type *pFirst = &value[0];
    value_type::value_type *pLast  = pFirst;
    std::advance(pLast, count);
    buffer.set_range( pFirst, 
                      pLast, 
                      offset);

    return count * sizeof(value_type);
  }

  //  **************************************************************************
  //  Exports a nested_trait with each sub-item written individually.
  //
  template< >
  size_t Export < nested_trait  >
                ( value_type &value, 
                  size_t      count, 
                  BufferT    &buffer,
                  size_t      offset)
  {
    // An important typedef for selecting the proper
    // version of the unpack function for the sub-elements.
    typedef typename
      message_size_trait<data_type::format_type>::type       size_trait;

    size_t bytes_written = 0;

    // Process each item individually.
    for (size_t index = 0; index < count; ++index)
    {
      // The offset for each item progressively increases
      // by the number of bytes read from the input buffer.
      size_t item_offset = offset + bytes_written;

      size_t write_len =
        pack_message< data_type,
                      BufferT,
                      size_trait
                    >(value[index], buffer, item_offset);

      bytes_written += write_len;
    }

    return bytes_written;
  }  
    
  //  **************************************************************************
  //  Exports an array with each sub-item written individually.
  //
  template< >
  size_t Export < array_trait >
                ( value_type &value, 
                  size_t      count, 
                  BufferT    &buffer,
                  size_t      offset)
  {
    return ExportEachDatum( value, count, buffer, offset );
  }  
    
  //  **************************************************************************
  //  Exports a vector with each sub-item written individually.
  //
  template< >
  size_t Export < vector_trait  >
                ( value_type &value, 
                  size_t      count, 
                  BufferT    &buffer,
                  size_t      offset)
  {
    return ExportEachDatum( value, count, buffer, offset );
  }  
    
  //  **************************************************************************
  //  This version writes each item from the raw buffer individually.
  //  These fields may be because they are distinct fields of a nested definition,
  //  or variable length items.
  //
  size_t ExportEachDatum( value_type &value, 
                          size_t      count, 
                          BufferT    &buffer,
                          size_t      offset)
  {
    // An important typedef for selecting the proper
    // version of the unpack function for the sub-elements.
    typedef typename
      message_size_trait<value_type>::type       size_trait;

    size_t bytes_written = 0;

    // Process each item individually.
    for (size_t index = 0; index < count; ++index)
    {
// TODO: Refactor these export functions into an external class.
//       This will allow the class to be reused for the sub-elements 
//       of the vector.

      //// The offset for each item progressively increases
      //// by the number of bytes read from the input buffer.
      //size_t item_offset = offset + bytes_written;

      //// Export sub-values one item at a time.
      //size_t write_len = 
      //Export< data_type_trait>( value[index], 
      //                          1, 
      //                          buffer, 
      //                          offset);

      //bytes_written += write_len;
    }

    return bytes_written;
  }
};

} // namespace detail

} // namespace Hg

#endif 
