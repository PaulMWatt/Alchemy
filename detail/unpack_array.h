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

// TODO: Complete conversion for an array. This is the vector implementation.

//  ****************************************************************************
//  A specialized functor to read array types.
// 
//  @tparam IdxT              [size_t] The index of the field to read.
//  @tparam MessageT          [typename] The message defintition used to parse the
//                            buffer.
//  @tparam BufferT           [typename] The buffer type that provides the data
//                            to read into the message.  
//  
//template< size_t   IdxT,      
//          typename MessageT,
//          typename BufferT
//        >
//struct UnpackDatum<IdxT, MessageT, BufferT, array_trait>
//{
//  //  Typedefs *****************************************************************
//  typedef typename
//    Hg::detail::DeduceProxyType 
//      < IdxT,
//        typename MessageT::format_type,
//        MessageT::k_base_offset
//      >::type                                     proxy_type;
//
//  typedef typename
//    proxy_type::value_type                        value_type;
//  typedef typename
//    value_type::value_type                        data_type;
//  typedef typename
//    value_type::allocator_type                    allocator_type;
//  typedef typename 
//    Hg::detail::DeduceTypeTrait
//      < data_type >::type                         data_type_trait;
//
//
//  //  **************************************************************************
//  //  Reads a dynamically-size field from the specified buffer.
//  // 
//  //  @param msg            The message object to accept the data to be read.
//  //  @param buffer         The buffer object to read from.
//  //  @param dynamic_offset An additional offset for messages with dynamically 
//  //                        sized fields. The length of the dynamic field read 
//  //                        will be added to this input value to report how much 
//  //                        larger the message has become. 
//  //
//  void operator()(      MessageT &msg,
//                  const BufferT  &buffer,
//                        size_t   &dynamic_offset)
//  {
//
//    value_type value  = value_type();
//    size_t     offset = Hg::OffsetOf<IdxT, MessageT::format_type>::value
//                      + dynamic_offset;
//    
//    // Query the message object for the number of elements in the buffer;
//    size_t      count = msg.Size(buffer, msg.template FieldAt<IdxT>());
//
//    // For zero-size move on.
//    if (0 == count)
//    {
//      return;
//    }
//
//    // Allocate space for the incoming data.
//    value.resize(count);
//
//    size_t bytes_read = 
//      Import< data_type_trait>( value, 
//                                count, 
//                                buffer, 
//                                offset);
//    
//    // TODO: Look into reading directly into the vector without the copy.
//    msg.template FieldAt<IdxT>().set(value);
//
//    dynamic_offset += bytes_read;
//  }
//
//private:
//  //  **************************************************************************
//  //  Imports data into the vector for fixed-size POD types.
//  //
//  template<typename TraitT>
//  size_t Import(      value_type &value, 
//                      size_t      count, 
//                const BufferT    &buffer,
//                      size_t      offset)
//  {
//    return  buffer.get_range(&value[0], count * sizeof(data_type), offset)
//            ? count * sizeof(data_type)
//            : 0;
//  }
//
//  //  **************************************************************************
//  //  This version reads each item from the raw buffer individually.
//  //  These fields may be because they are distinct fields of a nested definition,
//  //  or variable length items.
//  //
//  template< >
//  size_t Import<nested_trait>(      
//                      value_type &value, 
//                      size_t      count, 
//                const BufferT    &buffer,
//                      size_t      offset)
//  {
//    // TODO:  Will need to modify the definitions for:
//    //          data_type::format_type
//    //        To be a more robust version to properly support
//    //        vectors of vectors and vectors of arrays.
//
//    // An important typedef for selecting the proper
//    // version of the unpack function for the sub-elements.
//    typedef typename
//      message_size_trait<data_type::format_type>::type     size_trait;
//
//
//    size_t bytes_read = 0;
//
//    // Process each item individually.
//    for (size_t index = 0; index < count; ++index)
//    {
//      // The offset for each item progressively increases
//      // by the number of bytes read from the input buffer.
//      size_t item_offset = offset + bytes_read;
//
//      size_t last_read =
//        unpack_message< data_type,
//                        BufferT,
//                        size_trait
//                      >(value[index], buffer, item_offset);
//
//      bytes_read += last_read;
//    }
//
//    return bytes_read;
//  }
//};

} // namespace detail

} // namespace Hg

#endif 
