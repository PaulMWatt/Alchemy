/// @file Hg/detail/pack_message_detail.h
/// 
/// The primary implementation templates for packing Hg Message buffers.
/// Specializations for more complex types such as nested messages and vectors
/// depend upon the constructs in this header.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_MESSAGE_DETAIL_H_INCLUDED
#define PACK_MESSAGE_DETAIL_H_INCLUDED
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
//  A functor to assist in the writting of fundamental types to the message buffer.
//  This implementation is suitable to all fundamental types, BitList Fields,
//  and fixed-size arrays.
// 
//  @tparam T                 [typename] The fundamental type to be written.
//  @tparam IsNestedT         [bool = false] Indicates this structure writes
//                            fundamental types.
//  
template< size_t   IdxT,      
          typename MessageT, 
          typename BufferT,
          typename TraitT
        >
struct PackDatum
{
  //  **************************************************************************
  //  Writes a fixed size field to the specified buffer.
  // 
  //  @param msg          The message object to supply the data to be written.
  //  @param buffer       The buffer object to write into.
  //  @param dynamic_size An additional offset for messages with dynamically 
  //                      sized fields.
  //
  void operator()(MessageT &msg,
                  BufferT  &buffer,
                  size_t    dynamic_offset)
  {
    typedef typename
      Hg::detail::DeduceProxyType 
        < IdxT,
          typename MessageT::format_type
        >::type                                   proxy_type;

    typedef typename
      proxy_type::value_type                      value_type;

    value_type value  = msg.template FieldAt<IdxT>().get();
    size_t     offset = Hg::OffsetOf<IdxT, typename MessageT::format_type>::value
                      + dynamic_offset;
    buffer.set_data(value, offset);
  }

};


//  ****************************************************************************
//  Creates a serializer object to write a single datum to the message buffer.
// 
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
void WriteDatum(MessageT& message, 
                BufferT&  buffer, 
                size_t&   dynamic_offset)
{
  typedef typename
    Hg::detail::DeduceProxyType < IdxT,
                                  typename MessageT::format_type
                                >::type                               proxy_type;
  typedef typename
    proxy_type::value_type                                            value_type;

  PackDatum < IdxT,
              MessageT,
              BufferT, 
              typename DeduceTypeTrait<value_type>::type
            > pack;
  pack(message, buffer, dynamic_offset);
}

//  ****************************************************************************
//  Writes the data of the specified field to the message buffer.
// 
//  @tparam Idx                 [size_t] The index of this Datum in the container.
//  @tparam Count               [size_t] The number of fields in the container.
//  @tparam MessageT            [typename] The message type, which is a 
//                              collection of Datum fields.
//  @param msg                  A reference to the msg instance with the data fields.
//  @param buffer               A reference to the buffer that data will be written.
//  
template <size_t    Idx,
          size_t    Count,
          typename  MessageT,
          typename  BufferT
         >
struct PackMessageWorker
{ 
  void operator()(MessageT &message,
                  BufferT  &buffer)
  {
    // Write the current value, then move to the next value for the message.
    size_t dynamic_offset = 0;
    WriteDatum< Idx, MessageT, BufferT>(message, buffer,dynamic_offset);

    PackMessageWorker < Idx+1, Count, MessageT, BufferT> pack;
    pack(message, buffer);
  }

  void operator()(MessageT &message,
                  BufferT  &buffer,
                  size_t   &dynamic_offset)
  {
    // Write the current value, then move to the next value for the message.
    WriteDatum< Idx, MessageT, BufferT>(message, buffer, dynamic_offset);

    PackMessageWorker < Idx+1, Count, MessageT, BufferT> pack;
    pack(message, buffer, dynamic_offset);
  }
};

//  ****************************************************************************
//  Terminating specialization for the PackMessageWorker recursive function.
//  This function captures the case when the index = count.
// 
template <size_t    Idx,
          typename  MessageT,
          typename  BufferT
         >
struct PackMessageWorker< Idx, 
                          Idx, 
                          MessageT, 
                          BufferT
                        >
{ 
  void operator()(MessageT& msg, 
                  BufferT& buffer)
  { }

  void operator()(MessageT& msg, 
                  BufferT& buffer,
                  size_t   dynamic_offset)
  { }
};

//  ****************************************************************************
//  Writes the values of a message structure into a packed memory buffer.
// 
//  @param msg_values         The message structure that contains the values
//                            to be written.
//  @param fixed_buffer       A Fixed-size MessageBuffer that will accept the
//                            output text from the packed message.
// 
//  @return                   True on success, false otherwise.
// 
template< typename MessageT,
          typename BufferT
        >
bool
  pack_fixed_size_message(MessageT& msg_values,
                          BufferT & fixed_buffer,
                          const static_size_trait&)
{
  if (fixed_buffer.size() < Hg::SizeOf<typename MessageT::format_type>::value)
  {
    return false;
  }

  detail::PackMessageWorker < 0, 
                              Hg::length<typename MessageT::format_type>::value,
                              MessageT,
                              BufferT
                            > pack;
  pack(msg_values, fixed_buffer);

  return true;
}


//  ****************************************************************************
//  Writes the values of a message structure into a packed memory buffer.
// 
//  @param msg_values         The message structure that contains the values
//                            to be written.
//  @param size               The calculated size of the buffer required to 
//                            hold all of the data for the packed message.
// 
//  @return                   The buffer that has been allocated to store the 
//                            message.
// 
template< typename MessageT,
          typename BufferT
        >
std::shared_ptr<BufferT>
  pack_message( MessageT& msg_values, 
                size_t          size,
                const static_size_trait&)
{
  // Allocate a new buffer manager.
  std::shared_ptr<BufferT> spBuffer(new BufferT);
  // Resize the buffer.
  spBuffer->resize(Hg::SizeOf<typename MessageT::format_type>::value);

  detail::PackMessageWorker < 0, 
                              Hg::length<typename MessageT::format_type>::value,
                              MessageT,
                              BufferT
                            > pack;
  pack(msg_values, *spBuffer.get());
  return spBuffer;
}

//  ****************************************************************************
//  Writes the values of a message structure into a packed memory buffer.
// 
//  @param msg_values         The message structure that contains the values
//                            to be written.
//  @param buffer             The buffer this data should be written into.
//  @param offset             The offset the writing should be at.
// 
//  @return                   The buffer that has been allocated to store the 
//                            message.
// 
template< typename MessageT,
          typename BufferT
        >
size_t pack_message(MessageT  &msg_values,
                    BufferT   &buffer,
                    size_t     offset, 
                    const static_size_trait&)
{
  // Calculate the number of bytes that is expected to be written.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();

  // The new adjusted offset must be cumulative in order to 
  // avoid deep nested sub-structures from writing over
  // previously written material.
  //
  // Writing constantly progresses further into the buffer.
  buffer.offset(offset + org_offset);
  detail::PackMessageWorker < 0, 
                              Hg::length<typename MessageT::format_type>::value,
                              MessageT,
                              BufferT
                            > pack;
  pack(msg_values, buffer);
  // Restore the orignal offset of this buffer.
  buffer.offset(org_offset);

  return length;
}


//  ****************************************************************************
//  Writes the values of a variable-sized message into a packed memory buffer.
//  A separate instance exists to eliminate dynamic size tests from messages
//  that are completely fixed in size.
// 
//  @param msg_values         The message structure that contains the values
//                            to be written.
//  @param size               The calculated size of the buffer required to 
//                            hold all of the data for the packed message.
// 
//  @return                   The buffer that has been allocated to store the 
//                            message.
// 
template< typename MessageT,
          typename BufferT
        >
std::shared_ptr<BufferT>
  pack_message( MessageT  &msg_values, 
                size_t          size,
                const dynamic_size_trait&)
{
  // Allocate a new buffer manager.
  std::shared_ptr<BufferT> spBuffer(new BufferT);
  // Resize the buffer.
  spBuffer->resize(size);

  detail::PackMessageWorker < 0, 
                              Hg::length<typename MessageT::format_type>::value,
                              MessageT,
                              BufferT
                            > pack;
  size_t dynamic_offset = 0;
  pack(msg_values, *spBuffer.get(), dynamic_offset);
  return spBuffer;
}

//  ****************************************************************************
//  Writes the values of a variable-sized message into a packed memory buffer.
//  A separate instance exists to eliminate dynamic size tests from messages
//  that are completely fixed in size.
// 
//  @param msg_values         The message structure that contains the values
//                            to be written.
//  @param buffer             The buffer this data should be written into.
//  @param offset             The offset the writing should be at.
// 
//  @return                   The buffer that has been allocated to store the 
//                            message.
// 
template< typename MessageT,
          typename BufferT
        >
size_t pack_message(MessageT  &msg_values,
                    BufferT   &buffer,
                    size_t    offset,
                    const dynamic_size_trait&)
{
  // Calculate the number of bytes that is expected to be written.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();
  // The new adjusted offset must be cumulative in order to 
  // avoid deep nested sub-structures from writing over
  // previously written material.
  //
  // Writing constantly progresses further into the buffer.
  buffer.offset(org_offset + offset);
  detail::PackMessageWorker < 0, 
                              Hg::length<typename MessageT::format_type>::value,
                              MessageT,
                              BufferT
                            > pack;
  pack(msg_values, buffer);
  // Restore the orignal offset of this buffer.
  buffer.offset(org_offset);

  return length;
}

} // namespace detail

} // namespace Hg

#endif 
