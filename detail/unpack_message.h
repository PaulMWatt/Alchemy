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
#include <detail/msg_fwd.h>
#include <detail/unpack_message_detail.h>
#include <detail/unpack_array.h>
#include <detail/unpack_nested.h>
#include <detail/unpack_vector.h>

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
/// Reads the values of a message structure from a packed memory buffer.
///
/// @param msg_values         The message structure that contains the values
///                           to be read.
/// @param buffer             The buffer this data should be read from.
/// @param offset             The offset the reading should occur.
///
/// @return                   The number of bytes that were read in from the buffer.
///
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
