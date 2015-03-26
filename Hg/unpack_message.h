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
#include <Hg/msg_fwd.h>
#include <Hg/detail/unpack_message_detail.h>
#include <Hg/detail/unpack_array.h>
#include <Hg/detail/unpack_nested.h>
#include <Hg/detail/unpack_vector.h>
#include <Hg/detail/unpack_stream.h>

namespace Hg
{

//  ****************************************************************************
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
/// @param buffer             The buffer this data should be read from.
///
/// @return                   The message object populated by the input buffer.
///                           This is simply the same message object reference
///                           passed as input for expressive syntax.
///
template< typename MsgT,
          typename BufferT,
          typename SizeTraitT
        >
MsgT& unpack_message(       MsgT &msg_values,
                          const BufferT  &buffer)
{
  return detail::unpack_message ( msg_values,
                                  buffer,
                                  SizeTraitT());
}


//  ****************************************************************************
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
/// @param buffer             The buffer this data should be read from.
/// @param offset             The offset the reading should occur.
///
/// @return                   The number of bytes that were read in from the buffer.
///
template< typename MsgT,
          typename BufferT,
          typename SizeTraitT
        >
size_t unpack_message(       MsgT  &msg_values,
                       const BufferT   &buffer,
                             size_t    offset)
{
  return detail::unpack_message ( msg_values,
                                  buffer,
                                  offset,
                                  SizeTraitT());
}


//  ****************************************************************************
/// Reads the values of a message from an istream object.
///
/// @param is                 The input stream that will provide the data
///                           to populate the message.
/// @param msg                The message to be serialized.
///
/// @return                   A reference to is will be returned to allow these
///                           calls to be chained.
///
template< typename T >
std::istream& operator>>(std::istream& is, T& msg)
{
  if (Hg::has_dynamic< typename T::format_type >::value)
  {
    detail::unpack_stream_dynamic(is, msg);  
  }
  else
  {
    detail::unpack_stream_static(is, msg);
  }
  
  return is;
}

} // namespace Hg

#endif 
