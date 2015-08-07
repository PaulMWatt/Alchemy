/// @file detail/pack_optional.h
/// 
/// Packs an optional message field into Hg Message buffer.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_OPTIONAL_H_INCLUDED
#define PACK_OPTIONAL_H_INCLUDED
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
//  A specialized functor to write valid optional types.
// 
//  @tparam T       [typename] The value_type for this specialization
//                  is actually a format_type for the optional type.
//  
template< size_t   IdxT,      
          typename MsgT,
          typename BufferT
        >
struct PackDatum<IdxT, MsgT, BufferT, optional_trait>
{
  //  **************************************************************************
  //  Writes a *valid* optional field to the specified buffer.
  // 
  //  @param msg            The message object to supply the data to be written.
  //  @param buffer         The buffer object to write into.
  //  @param dynamic_offset An additional offset for messages with dynamically 
  //                        sized fields. If this nested value contains additional
  //                        dynamically-sized fields, this length will be added 
  //                        to this input value to report how much larger the
  //                        message has become. 
  //
  void operator()(MsgT     &msg,
                  BufferT  &buffer,
                  size_t   &dynamic_offset)
  {
    using format_type= typename MsgT::format_type;
    using proxy_type = Hg::detail::deduce_proxy_type_t<IdxT, format_type>;

    auto &optional_value = msg.template FieldAt<IdxT>().get();

    if (optional_value.is_valid())
    { 
      // This field is valid.
      // Send it to the actual proxy handler to complete the data pack.
      PackDatum<IdxT, MsgT, BufferT, typename proxy_type::base_trait> pack;
      pack(msg, buffer, dynamic_offset);
    }
  }
};

} // namespace detail

} // namespace Hg

#endif 
