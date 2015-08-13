/// @file detail/pack_nested.h
/// 
/// Packs a nested message field into Hg Message buffer.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_NESTED_H_INCLUDED
#define PACK_NESTED_H_INCLUDED
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
//  A specialized functor to write nested types.
// 
//  @tparam T       [typename] The value_type for this specialization
//                  is actually a format_type for the nested structure.
//  
template< size_t   IdxT,      
          typename MsgT,
          typename BufferT
        >
struct PackDatum<IdxT, MsgT, BufferT, nested_trait>
{
  //  **************************************************************************
  //  Writes a nested field to the specified buffer.
  // 
  //  @param msg            The message object to supply the data to be written.
  //  @param buffer         The buffer object to write into.
  //  @param dynamic_offset An additional offset for messages with dynamically 
  //                        sized fields. If this nested value contains additional
  //                        dynamically-sized fields, this length will be added 
  //                        to this input value to report how much larger the
  //                        message has become. 
  //
  //  @return               The number of bytes written to the buffer.
  //
  size_t operator()(MsgT &msg,
                    BufferT  &buffer,
                    size_t   &dynamic_offset)
  {
    using format_type= typename MsgT::format_type;
    using proxy_type = Hg::detail::deduce_proxy_type_t<IdxT, format_type>;
    using value_type = typename proxy_type::value_type;
    using value_format_type = typename value_type::format_type;

    auto    &value = msg.template FieldAt<IdxT>().get();
    size_t  offset = Hg::offset_of<IdxT, format_type>::value
                      + dynamic_offset;

    return pack_message < value_type, 
                          BufferT,
                          message_size_trait_t<value_format_type>
                        >(value, buffer, offset);
  }
};

} // namespace detail

} // namespace Hg

#endif 
