/// @file detail/pack_packed_bits.h
/// 
/// Packs a packed-bits message field into Hg Message buffer.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_PACKED_BITS_H_INCLUDED
#define PACK_PACKED_BITS_H_INCLUDED
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
//  A specialized functor to write packed-bits.
// 
//  @tparam T       [typename] The value_type for this specialization.
//  
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
struct PackDatum<IdxT, MessageT, BufferT, packed_trait>
{
  //  **************************************************************************
  //  Writes a packed-bits field to the specified buffer.
  // 
  //  @param msg            The message object to supply the data to be written.
  //  @param buffer         The buffer object to write into.
  //  @param dynamic_offset An additional offset for messages with dynamically 
  //                        sized fields. 
  //
  void operator()(MessageT &msg,
                  BufferT  &buffer,
                  size_t   &dynamic_offset)
  {
    typedef typename
      Hg::detail::DeduceProxyType 
        < IdxT,
          typename MessageT::format_type
        >::type                                   proxy_type;

    typedef typename
      proxy_type::value_type                      packed_type;

    typedef typename
      packed_type::value_type                     value_type;

    packed_type &packed_value = msg.template FieldAt<IdxT>().get();
    value_type  value         = packed_value;
    size_t      offset        = Hg::OffsetOf<IdxT, typename MessageT::format_type>::value
                              + dynamic_offset;
    buffer.set_data(value, offset);
  }
};

} // namespace detail

} // namespace Hg

#endif 
