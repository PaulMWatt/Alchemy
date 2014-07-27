/// @file detail/pack_message.h
/// 
/// The implementation to pack a Hg Message into a packed byte-buffer.
/// There are two versions of the *pack_message* function provided, one to
/// 
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_MESSAGE_H_INCLUDED
#define PACK_MESSAGE_H_INCLUDED
//  Includes *******************************************************************
#include <detail/msg_def.h>
#include <detail/msg_buffer.h>

namespace Hg
{

//  Forward Declarations *******************************************************
//  ****************************************************************************
/// Writes the values of a message into a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be written.
/// @param size               The calculated size required for this message.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
std::shared_ptr<BufferT>
  pack_message(MessageT& msg_values, size_t size);

//  ****************************************************************************
/// Writes the values of a message into a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be written.
/// @param size               The calculated size required for this message.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
std::shared_ptr<BufferT>
  pack_message(MessageT& msg_values, size_t size);

//  ****************************************************************************
/// Writes the values of a variable-sized message into a packed memory buffer.
/// A separate instance exists to eliminate dynamic size tests from messages
/// that are completely fixed in size.
///
/// @param msg_values         The message structure that contains the values
///                           to be written.
/// @param buffer             The buffer this data should be written into.
/// @param offset             The offset the writing should be at.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
size_t pack_message(MessageT &msg_values,
                    BufferT  &buffer,
                    size_t    offset);

//  ****************************************************************************
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
  void operator()(const MessageT &msg,
                        BufferT  &buffer)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type,
                                    MessageT::k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    value_type value = const_cast<MessageT&>(msg).template FieldAt<IdxT>().get();
    buffer.set_data(value, Hg::OffsetOf<IdxT, typename MessageT::format_type>::value);
  }
};

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
  void operator()(const MessageT &msg,
                        BufferT  &buffer)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type,
                                    MessageT::k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    value_type value = const_cast<MessageT&>(msg).template FieldAt<IdxT>().get();
    size_t     offset= Hg::OffsetOf<IdxT, MessageT::format_type>::value;
    pack_message< value_type, 
                  BufferT,
                  typename message_size_trait<value_type::format_type>::type
                >(value, buffer, offset);
  }
};

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
  size_t operator()(const MessageT &msg,
                          BufferT  &buffer,
                          size_t   dynamic_offset)
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

    size_t     size   = value.size();
    size_t     offset = Hg::OffsetOf<IdxT, MessageT::format_type>::value
                      + dynamic_offset;
   
    value_type::value_type 
    buffer.set_range( &(*value.begin()), 
                      &(*value.end()), 
                      offset);
    size_t datum_size = size * sizeof(value_type::value_type);
    return offset + size;
  }
};

//  ****************************************************************************
//  Creates a serializer object to write a single datum to the message buffer.
// 
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
void WriteDatum(const MessageT& message, BufferT& buffer, size_t offset)
{
  typedef typename
    Hg::detail::DeduceProxyType < IdxT,
                                  typename MessageT::format_type,
                                  MessageT::k_base_offset>::type      proxy_type;
  typedef typename
    proxy_type::value_type                                            value_type;

  PackDatum < IdxT,
              MessageT,
              BufferT, 
              DeduceTypeTrait<value_type>::type
            > pack;
  pack(message, buffer, offset);
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
  void operator()(const MessageT &msg,
                        BufferT  &buffer,
                        size_t    offset)
  {
    // Write the current value, then move to the next value for the message.
    size_t last_pos = WriteDatum< Idx, MessageT, BufferT>(msg, buffer, offset);

    PackMessageWorker < Idx+1, Count, MessageT, BufferT> pack;
    pack(msg, buffer);
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
  void operator()(const MessageT& msg, 
                        BufferT& buffer)
  { }
};


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
                size_t    size,
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
size_t pack_message(MessageT &msg_values,
                    BufferT  &buffer,
                    size_t    offset, 
                    const static_size_trait&)
{
  // Calculate the number of bytes that is expected to be written.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();
  buffer.offset(offset);
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
  pack_message( MessageT& msg_values, 
                size_t    size,
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
  pack(msg_values, *spBuffer.get());
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
size_t pack_message(MessageT &msg_values,
                    BufferT  &buffer,
                    size_t    offset,
                    const dynamic_size_trait&)
{
  // Calculate the number of bytes that is expected to be written.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();
  buffer.offset(offset);
  detail::PackMessageWorker < 0, 
                              Hg::length<typename MessageT::format_type>::value,
                              MessageT,
                              BufferT
                            > pack;
//  pack(msg_values, buffer);
  // Restore the orignal offset of this buffer.
  buffer.offset(org_offset);

  return length;
}

} // namespace detail


//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
std::shared_ptr<BufferT>
  pack_message( MessageT& msg_values,
                size_t    size)
{
  return detail::pack_message<MessageT, BufferT>(msg_values, size, SizeTraitT());
}

//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
size_t pack_message(MessageT &msg_values,
                    BufferT  &buffer,
                    size_t    offset)
{
  return detail::pack_message < MessageT, 
                                BufferT
                              >(msg_values, 
                                buffer,
                                offset,
                                SizeTraitT());
}




} // namespace Hg

#endif 
