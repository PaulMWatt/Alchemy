/// @file detail/unpack_stream.h
/// 
/// A specialization to unpack the bytes from an input stream.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef UNPACK_STREAM_H_INCLUDED
#define UNPACK_STREAM_H_INCLUDED
//  Private Usage Include Guard ************************************************
//  Only allow this header file to be included through unpack_message.h
#ifndef UNPACK_MESSAGE_H_INCLUDED
# error Do not include this file directly. Use <detail/unpack_message.h> instead
#endif
//  Includes *******************************************************************
#include <sstream>


namespace Hg
{

namespace detail
{
//  Forward Declarations *******************************************************
//  ****************************************************************************



//  ****************************************************************************
/// Reads the values of a message from an istream object.
///
/// @param is                 The input stream that will provide the data
///                           to populate the message.
/// @param msg                The message to be serialized.
///
template< typename T >
void unpack_stream_static(std::istream& is, T& msg)
{
  const size_t k_len = Hg::SizeOf<typename T::format_type>::value;
  byte_t buffer[k_len];
  is.read(reinterpret_cast<char*>(buffer), k_len);

  msg.assign(buffer, k_len);
}

//  ****************************************************************************
/// Reads the values of a message into an istream object for a dynamic buffer.
///
/// @param is                 The input stream that will provide the data
///                           to populate the message.
/// @param msg                The message to be serialized.
///
template< typename T >
void unpack_stream_dynamic(std::istream& is, T& msg)
{
  // TODO: IN order to do this properly, incremental processing must be done to properly read the dynamically sized field.
  //       This form will only work for formats that have one dynamic field and it is at the end of the message.
  //       Essentially, read in the body of the message, then read the data buffer at the end.
  const size_t k_static_len = Hg::SizeOf<typename T::format_type>::value;
  byte_t body[k_static_len];
  is.read(reinterpret_cast<char*>(body), k_static_len);

  msg.assign(body, k_static_len);

  // Now read the dynamic data.
  size_t len = msg.size();
  std::vector<byte_t> data(len);
  ::memcpy(&data[0], body, k_static_len);
  
  is.read(reinterpret_cast<char*>(&data[k_static_len]), len - k_static_len);

  msg.assign(&data[0], len);
}


} // namespace detail

} // namespace Hg

#endif 
