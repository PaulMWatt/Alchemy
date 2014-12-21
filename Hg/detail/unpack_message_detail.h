/// @file detail/unpack_message.h
/// 
/// Unpacks the bytes from a raw memory buffer into Hg (Mercury).
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef UNPACK_MESSAGE_DETAIL_H_INCLUDED
#define UNPACK_MESSAGE_DETAIL_H_INCLUDED
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
//  A functor to assist in the reading of fundamental types from the message buffer.
//  This is also the most basic reader, therefore it will act as the default.
// 
//  @tparam IdxT              [size_t] The index of the field to read.
//  @tparam MessageT          [typename] The message defintition used to parse the
//                            buffer.
//  @tparam BufferT           [typename] The buffer type that provides the data
//                            to read into the message.  
//  @tparam TraitT            [typename] Specifies the type trait of T.
//                            This field acts as a descriminator for selecting
//                            the most appropriate construct to read the current
//                            value type from the buffer.
//  
template< size_t   IdxT,      
          typename MessageT, 
          typename BufferT,
          typename TraitT
        >
struct UnpackDatum
{
  //  **************************************************************************
  //  Reads a fixed size field from the specified buffer.
  // 
  //  @param msg            The message object to supply the data to be read.
  //  @param buffer         The buffer object to read from.
  //  @param dynamic_offset An additional offset for messages with dynamically 
  //                        sized fields.
  //
  void operator()(MessageT &msg,
                  BufferT  &buffer,
                  size_t    dynamic_offset)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type
                                  >::type                               proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    size_t offset = Hg::OffsetOf<IdxT, typename MessageT::format_type>::value
                  + dynamic_offset;

    buffer.get_data(msg.template FieldAt<IdxT>().get(), 
                    offset);
  }
};

//  ****************************************************************************
//  ****************************************************************************
//  Creates a serializer object to read a single datum from the message buffer.
//
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
void ReadDatum(       MessageT& message, 
                const BufferT&  buffer, 
                      size_t&   dynamic_offset)
{
  typedef typename
    Hg::detail::DeduceProxyType < IdxT,
                                  typename MessageT::format_type
                                >::type                               proxy_type;
  typedef typename
    proxy_type::value_type                                            value_type;

  UnpackDatum < IdxT,
                MessageT,
                const BufferT, 
                typename DeduceTypeTrait<value_type>::type
              > unpack;
  unpack(message, buffer, dynamic_offset);
}

//  ****************************************************************************
//  Reads the data of the specified field from the message buffer.
// 
//  @tparam Idx                 [size_t] The index of this Datum in the container.
//  @tparam Count               [size_t] The number of fields in the container.
//  @tparam MessageT            [typename] The message type, which is a 
//                              collection of Datum fields.
//  @param msg                  A reference to the msg instance with the data fields.
//  @param buffer               A reference to the buffer that data will be read from.
//  
template <size_t    Idx,
          size_t    Count,
          typename  MessageT,
          typename  BufferT
         >
struct UnpackMessageWorker
{ 
  void operator()(      MessageT &msg,
                  const BufferT  &buffer )
  {
    // Read the current value, then move to the next value for the message.
    size_t dynamic_offset = 0;
    ReadDatum< Idx, MessageT, BufferT>(msg, buffer, dynamic_offset);

    UnpackMessageWorker < Idx+1, Count, MessageT, BufferT> unpack;
    unpack(msg, buffer);
  }

  void operator()(      MessageT &msg,
                  const BufferT  &buffer,
                        size_t   &dynamic_offset)
  {
    // Read the current value, then move to the next value for the message.
    ReadDatum< Idx, MessageT, BufferT>(msg, buffer, dynamic_offset);

    UnpackMessageWorker < Idx+1, Count, MessageT, BufferT> unpack;
    unpack(msg, buffer, dynamic_offset);
  }

};

//  ****************************************************************************
//  Terminating specialization for the UnpackMessageWorker recursive function.
//  This function captures the case when the index = count.
// 
template <size_t    Idx,
          typename  MessageT,
          typename  BufferT
         >
struct UnpackMessageWorker< Idx, 
                            Idx, 
                            MessageT, 
                            BufferT
                          >
{ 
  void operator()(      MessageT& msg, 
                  const BufferT& buffer)
  { }

  void operator()(      MessageT& msg, 
                  const BufferT& buffer,
                        size_t   dynamic_offset)
  { }
};


//  ****************************************************************************
//  Reads the values of a message structure from a packed memory buffer.
// 
//  @param msg_values         The message structure that contains the values
//                            to be read.
// 
//  @return                   The buffer that has been allocated to store the 
//                            message.
// 
template< typename MessageT,
          typename BufferT
        >
MessageT& unpack_message(       MessageT &msg_values,
                          const BufferT  &buffer,
                          const static_size_trait&  )
{
  const size_t k_msg_size = Hg::SizeOf<typename MessageT::format_type>::value;
  // Verify the input buffer contains enough data to populate the message.
  if ( buffer.empty()
    || buffer.size() < k_msg_size)
  {
#ifdef ALCHEMY_USES_EXCEPTIONS
    throw std::length_error("Static unpack_message does not have enough space to complete its operation.");
#endif

    return msg_values;
  }

  detail::UnpackMessageWorker < 0, 
                                Hg::length<typename MessageT::format_type>::value,
                                MessageT,
                                BufferT
                              > unpack;
  unpack(msg_values, buffer);
  return msg_values;
}


//  ****************************************************************************
//  Reads the values of a message structure from a packed memory buffer.
// 
//  @param msg_values         The message structure that contains the values
//                            to be read.
//  @param buffer             The buffer this data should be read from.
//  @param offset             The offset the reading should occur.
// 
//  @return                   The buffer that has been allocated to store the 
//                            message.
// 
template< typename MessageT,
          typename BufferT
        >
size_t unpack_message (       MessageT  &msg_values,
                        const BufferT   &buffer,
                               size_t    offset,
                        const static_size_trait&   )
{
  typedef typename
    std::remove_const<BufferT>::type              MutableBuffer;

  // Calculate the number of bytes that is expected to be read for this message.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();
  MutableBuffer working(buffer);
  working.offset(offset+org_offset);
  detail::UnpackMessageWorker < 0, 
                                Hg::length<typename MessageT::format_type>::value,
                                MessageT,
                                BufferT
                              > unpack;
  unpack(msg_values, working);

  return length;
}


//  ****************************************************************************
//  Reads the values of a message structure from a packed memory buffer.
// 
//  @param msg_values         The message structure that contains the values
//                            to be read.
//  @param buffer               The buffer to read from.
// 
//  @return                   The populated message values are returned.
// 
template< typename MessageT,
          typename BufferT
        >
MessageT& unpack_message(       MessageT &msg_values,
                          const BufferT  &buffer,
                          const dynamic_size_trait&  )
{
  const size_t k_msg_size = Hg::SizeOf<typename MessageT::format_type>::value;
  // Verify the input buffer contains enough data to populate the minimum size
  // required by the message.
  if ( buffer.empty()
    || buffer.size() < k_msg_size)
  {
#ifdef ALCHEMY_USES_EXCEPTIONS
    throw std::length_error("Dynamic unpack_message does not have enough space to complete its operation.");
#endif

    return msg_values;
  }

  detail::UnpackMessageWorker < 0, 
                                Hg::length<typename MessageT::format_type>::value,
                                MessageT,
                                BufferT
                              > unpack;
  size_t dynamic_offset = 0;
  unpack(msg_values, buffer, dynamic_offset);
  return msg_values;
}


//  ****************************************************************************
//  Reads the values of a message structure from a packed memory buffer.
// 
//  @param msg_values         The message structure that contains the values
//                            to be read.
//  @param buffer             The buffer this data should be read from.
//  @param offset             The offset the reading should occur.
// 
//  @return                   The buffer that has been allocated to store the 
//                            message.
// 
template< typename MessageT,
          typename BufferT
        >
size_t unpack_message (       MessageT  &msg_values,
                        const BufferT   &buffer,
                               size_t    offset,
                        const dynamic_size_trait&   )
{
  typedef typename
    std::remove_const<BufferT>::type              MutableBuffer;

  // Calculate the number of bytes that is expected to be read for this message.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();
  MutableBuffer working(buffer);
  working.offset(offset+org_offset);
  detail::UnpackMessageWorker < 0, 
                                Hg::length<typename MessageT::format_type>::value,
                                MessageT,
                                BufferT
                              > unpack;
  size_t dynamic_offset = 0;
  unpack(msg_values, working, dynamic_offset);

  return length + dynamic_offset;
}

} // namespace detail

} // namespace Hg

#endif 
