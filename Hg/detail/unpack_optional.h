/// @file detail/unpack_optional.h
/// 
/// Unpacks the bytes from a raw memory buffer into an optional message field.
/// 
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef UNPACK_OPTIONAL_H_INCLUDED
#define UNPACK_OPTIONAL_H_INCLUDED
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
//  A specialized functor to read optional types.
// 
//  @tparam IdxT              [size_t] The index of the field to read.
//  @tparam MsgT              [typename] The message defintition used to parse the
//                                buffer.
//  @tparam BufferT           [typename] The buffer type that provides the data
//                                to read into the message.  
//  
template< size_t   IdxT,      
          typename MsgT,
          typename BufferT
        >
struct UnpackDatum<IdxT, MsgT, BufferT, optional_trait>
{
  //  **************************************************************************
  //  Reads an optional field to the specified buffer.
  // 
  //  @param msg            The message object to receive the data to be read.
  //  @param buffer         The buffer object to read from.
  //  @param dynamic_offset An additional offset for messages with dynamically 
  //                        sized fields. If this nested value contains additional
  //                        dynamically-sized fields, this length will be added 
  //                        to this input value to report how much larger the
  //                        message has become. 
  //
  //  @return               The number of bytes read from the buffer.
  //
  size_t operator()(      MsgT     &msg,
                    const BufferT  &buffer,
                          size_t   &dynamic_offset)
  {
    using format_type= typename MsgT::format_type;
    using proxy_type = Hg::detail::deduce_proxy_type_t<IdxT, format_type>;

    size_t bytes_read = 0;

    // Query the message object for the validity of this field.
    if (msg.IsValid(buffer, &msg.template FieldAt<IdxT>()))
    { 
      auto &optional_value = msg.template FieldAt<IdxT>().get();

      // This field is valid.
      // The actual proxy handler will to complete the data unpack.
      UnpackDatum<IdxT, MsgT, BufferT, typename proxy_type::base_trait> unpack;
      bytes_read = unpack(msg, buffer, dynamic_offset);

      // The entire size of the field is considered 
      // part of the dynamic size with optional fields.
      dynamic_offset += bytes_read;
    }

    return bytes_read;
  }
};

} // namespace detail

} // namespace Hg

#endif 
