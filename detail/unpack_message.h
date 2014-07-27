/// @file detail/unpack_message.h
/// 
/// Unpacks the bytes from a raw memory buffer into Hg (Mercury).
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef UNPACK_MESSAGE_H_INCLUDED
#define UNPACK_MESSAGE_H_INCLUDED
//  Includes *******************************************************************
#include <detail/msg_def.h>
#include <detail/msg_buffer.h>

namespace Hg
{

//  Forward Declarations *******************************************************
//  ****************************************************************************
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
std::shared_ptr<BufferT>
  unpack_message(MessageT& msg_values);


//  ****************************************************************************
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
/// @param buffer             The buffer this data should be read from.
/// @param offset             The offset the reading should occur.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
size_t unpack_message(MessageT &msg_values,
                      BufferT  &buffer,
                      size_t    offset);


//  ****************************************************************************
namespace detail
{

//  ****************************************************************************
/// A functor to assist in the reading of fundamental types from the message buffer.
/// This is also the most basic reader, therefore it will act as the default.
///
/// @tparam IdxT              [size_t] The index of the field to read.
/// @tparam MessageT          [typename] The message defintition used to parse the
///                           buffer.
/// @tparam BufferT           [typename] The buffer type that provides the data
///                           to read into the message.  
/// @tparam TraitT            [typename] Specifies the type trait of T.
///                           This field acts as a descriminator for selecting
///                           the most appropriate construct to read the current
///                           value type from the buffer.
/// 
template< size_t   IdxT,      
          typename MessageT, 
          typename BufferT,
          typename TraitT
        >
struct UnpackDatum
{
  void operator()(MessageT &msg,
                  BufferT  &buffer)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type,
                                    MessageT::k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    value_type value = value_type();

    buffer.get_data(value, Hg::OffsetOf<IdxT, typename MessageT::format_type>::value);
    msg.template FieldAt<IdxT>().set(value);
  }
};

//  ****************************************************************************
/// A specialized functor to read nested types.
///
/// @tparam IdxT              [size_t] The index of the field to read.
/// @tparam MessageT          [typename] The message defintition used to parse the
///                           buffer.
/// @tparam BufferT           [typename] The buffer type that provides the data
///                           to read into the message.  
/// 
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
struct UnpackDatum<IdxT, MessageT, BufferT, nested_trait>
{
  void operator()(      MessageT &msg,
                  const BufferT  &buffer)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type,
                                    MessageT::k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    value_type value = value_type();
    size_t     offset= Hg::OffsetOf<IdxT, MessageT::format_type>::value;
    unpack_message< value_type, 
                    BufferT,
                    typename message_size_trait<value_type::format_type>::type
                  >(value, buffer, offset);
    msg.template FieldAt<IdxT>().set(value);
  }
};

//  ****************************************************************************
/// A specialized functor to read vector types.
///
/// @tparam IdxT              [size_t] The index of the field to read.
/// @tparam MessageT          [typename] The message defintition used to parse the
///                           buffer.
/// @tparam BufferT           [typename] The buffer type that provides the data
///                           to read into the message.  
/// 
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
struct UnpackDatum<IdxT, MessageT, BufferT, vector_trait>
{
  void operator()(      MessageT &msg,
                  const BufferT  &buffer)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    typename MessageT::format_type,
                                    MessageT::k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                            value_type;

    // TODO: Need to specify how the size is determined. The user will define this with the type in the message definition.
    //value_type value = value_type();
    //size_t     offset= Hg::OffsetOf<IdxT, MessageT::format_type>::value;
    //unpack_message<value_type, BufferT>(value, buffer, offset);
    //msg.template FieldAt<IdxT>().set(value);
  }
};

//  ****************************************************************************
/// Creates a serializer object to read a single datum from the message buffer.
///
template< size_t   IdxT,      
          typename MessageT,
          typename BufferT
        >
void ReadDatum(MessageT& message, const BufferT& buffer)
{
  typedef typename
    Hg::detail::DeduceProxyType < IdxT,
                                  typename MessageT::format_type,
                                  MessageT::k_base_offset>::type      proxy_type;
  typedef typename
    proxy_type::value_type                                            value_type;

  UnpackDatum < IdxT,
                MessageT,
                const BufferT, 
                DeduceTypeTrait<value_type>::type
              > unpack;
  unpack(message, buffer);
}

//  ****************************************************************************
/// Reads the data of the specified field from the message buffer.
///
/// @tparam Idx                 [size_t] The index of this Datum in the container.
/// @tparam Count               [size_t] The number of fields in the container.
/// @tparam MessageT            [typename] The message type, which is a 
///                             collection of Datum fields.
/// @param msg                  A reference to the msg instance with the data fields.
/// @param buffer               A reference to the buffer that data will be read from.
/// 
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
    ReadDatum< Idx, MessageT, BufferT>(msg, buffer);

    UnpackMessageWorker < Idx+1, Count, MessageT, BufferT> unpack;
    unpack(msg, buffer);
  }
};

//  ****************************************************************************
/// Terminating specialization for the UnpackMessageWorker recursive function.
/// This function captures the case when the index = count.
///
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
};


//  ****************************************************************************
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
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
    // TODO: When exception handling is added placeone here
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
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
/// @param buffer             The buffer this data should be read from.
/// @param offset             The offset the reading should occur.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT
        >
size_t unpack_message (       MessageT  &msg_values,
                        const BufferT   &buffer,
                               size_t    offset,
                        const static_size_trait&   )
{
  typedef std::remove_const<BufferT>::type        MutableBuffer;

  // Calculate the number of bytes that is expected to be read for this message.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();
  MutableBuffer working(buffer);
  working.offset(offset);
  detail::UnpackMessageWorker < 0, 
                                Hg::length<typename MessageT::format_type>::value,
                                MessageT,
                                BufferT
                              > unpack;
  unpack(msg_values, working);

  return length;
}


//  ****************************************************************************
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT
        >
MessageT& unpack_message(       MessageT &msg_values,
                          const BufferT  &buffer,
                          const dynamic_size_trait&  )
{
// TODO: Return an implement once the size information is known.
  const size_t k_msg_size = Hg::SizeOf<typename MessageT::format_type>::value;
  // Verify the input buffer contains enough data to populate the message.
  if ( buffer.empty()
    || buffer.size() < k_msg_size)
  {
    // TODO: When exception handling is added placeone here
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
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
/// @param buffer             The buffer this data should be read from.
/// @param offset             The offset the reading should occur.
///
/// @return                   The buffer that has been allocated to store the 
///                           message.
///
template< typename MessageT,
          typename BufferT
        >
size_t unpack_message (       MessageT  &msg_values,
                        const BufferT   &buffer,
                               size_t    offset,
                        const dynamic_size_trait&   )
{
// TODO: Return an implement once the size information is known.
  typedef std::remove_const<BufferT>::type        MutableBuffer;

  // Calculate the number of bytes that is expected to be read for this message.
  size_t length = Hg::SizeOf<typename MessageT::format_type>::value;

  size_t org_offset = buffer.offset();
  MutableBuffer working(buffer);
  working.offset(offset);
  detail::UnpackMessageWorker < 0, 
                                Hg::length<typename MessageT::format_type>::value,
                                MessageT,
                                BufferT
                              > unpack;
  unpack(msg_values, working);

  return length;
}


} // namespace detail


//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
MessageT& unpack_message(       MessageT &msg_values,
                          const BufferT  &buffer)
{
  return detail::unpack_message ( msg_values,
                                  buffer,
                                  SizeTraitT());
}


//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
size_t unpack_message(       MessageT  &msg_values,
                       const BufferT   &buffer,
                             size_t    offset)
{
  return detail::unpack_message ( msg_values,
                                  buffer,
                                  offset,
                                  SizeTraitT());
}

} // namespace Hg

#endif 
