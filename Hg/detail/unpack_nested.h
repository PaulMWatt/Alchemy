/// @file detail/unpack_nested.h
/// 
/// Unpacks the bytes from a raw memory buffer into a nested message field.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef UNPACK_NESTED_H_INCLUDED
#define UNPACK_NESTED_H_INCLUDED
//  Private Usage Include Guard ************************************************
//  Only allow this header file to be included through unpack_message.h
#ifndef UNPACK_MESSAGE_H_INCLUDED
# error Do not include this file directly. Use <detail/unpack_message.h> instead
#endif

namespace Hg
{

namespace detail
{

//  ****************************************************************************
//  A specialized functor to read nested types.
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
struct UnpackDatum<IdxT, MessageT, BufferT, nested_trait>
{
  //  **************************************************************************
  //  Reads a nested field to the specified buffer.
  // 
  //  @param msg            The message object to receive the data to be read.
  //  @param buffer         The buffer object to read from.
  //  @param dynamic_offset An additional offset for messages with dynamically 
  //                        sized fields. If this nested value contains additional
  //                        dynamically-sized fields, this length will be added 
  //                        to this input value to report how much larger the
  //                        message has become. 
  //
  void operator()(      MessageT &msg,
                  const BufferT  &buffer,
                        size_t   &dynamic_offset)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type,
                                    MessageT::k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    value_type value  = value_type();
    size_t     offset = Hg::OffsetOf<IdxT, MessageT::format_type>::value
                      + dynamic_offset;
    unpack_message< value_type, 
                    BufferT,
                    typename message_size_trait<value_type::format_type>::type
                  >(value, buffer, offset);
    msg.template FieldAt<IdxT>().set(value);
  }
};

} // namespace detail

} // namespace Hg

#endif 