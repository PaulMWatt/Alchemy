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
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type,
                                    MessageT::k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

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
    // Size() from the value is the number of elements that are contained.
    size_t count= value.size();
    // Adjust with the size of the actual elements in the container.
    size_t size = count * Hg::SizeOf<value_type::value_type>::value;
    
    value_type::value_type *pFirst = &value[0];
    value_type::value_type *pLast  = pFirst;
    std::advance(pLast, size);
    buffer.set_range( pFirst, 
                      pLast, 
                      offset);
  }
};

} // namespace detail

} // namespace Hg

#endif 
