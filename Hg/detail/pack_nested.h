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
          typename MessageT,
          typename BufferT
        >
struct PackDatum<IdxT, MessageT, BufferT, nested_trait>
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
  void operator()(MessageT &msg,
                  BufferT  &buffer,
                  size_t   &dynamic_offset)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type
                                  >::type                               proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    value_type &value  = msg.template FieldAt<IdxT>().get();
    size_t     offset = Hg::OffsetOf<IdxT, typename MessageT::format_type>::value
                      + dynamic_offset;
    pack_message< value_type, 
                  BufferT,
                  typename message_size_trait<typename value_type::format_type>::type
                >(value, buffer, offset);
  }
};

} // namespace detail

} // namespace Hg

#endif 
