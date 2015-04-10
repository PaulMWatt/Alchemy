/// @file Hg/pack_message.h
/// 
/// The implementation to pack a Hg Message into a packed byte-buffer.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PACK_MESSAGE_H_INCLUDED
#define PACK_MESSAGE_H_INCLUDED
//  Includes *******************************************************************
#include <Hg/msg_fwd.h>
#include <Hg/detail/pack_message_detail.h>
#include <Hg/detail/pack_array.h>
#include <Hg/detail/pack_nested.h>
#include <Hg/detail/pack_packed_bits.h>
#include <Hg/detail/pack_vector.h>

namespace Hg
{

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
BufferT&
  pack_message( MessageT& msg_values,
                size_t    size,
                BufferT & buffer
              )
{
  detail::pack_message < MessageT, 
                         BufferT
                       >(msg_values, 
                         size, 
                         buffer, 
                         SizeTraitT());
  return  buffer;
}

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
                    size_t    offset)
{
  return detail::pack_message < MessageT, 
                                BufferT
                              >(msg_values, 
                                buffer,
                                offset,
                                SizeTraitT());
}


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
bool
  pack_message( MessageT& msg_values,
                BufferT & fixed_buffer)
{
  return   detail::pack_fixed_size_message( msg_values,
                                            fixed_buffer,
                                            SizeTraitT());
}


//  ****************************************************************************
/// Writes the values of a message into an ostream object.
///
/// @param os                 The output stream that will accept the serialized
///                           form of the message.
/// @param msg                The message to be serialized.
///
/// @return                   A reference to os will be returned to allow these
///                           calls to be chained.
///
template< typename T >
std::ostream& operator<<(std::ostream& os, const T& msg)
{
  Hg::Message<typename T::message_type, 
              typename T::byte_order_type, 
              Hg::BufferedStoragePolicy> outMsg;

  outMsg = msg;

  os.write(reinterpret_cast<const char*>(outMsg.data()), outMsg.size());
  return os;
}

} // namespace Hg

#endif 
