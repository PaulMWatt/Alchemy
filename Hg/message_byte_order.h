/// @file Hg/message_byte_order.h
/// 
/// An extraction of the Network to Host conversion functions.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MESSAGE_BYTE_ORDER_H_INCLUDED
#define MESSAGE_BYTE_ORDER_H_INCLUDED
//  Includes *******************************************************************
#include <Hg/detail/message_byte_order_detail.h>

namespace Hg
{

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to network byte-order.
///
/// @param T        [typename] The Hg::basic_msg format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::basic_msg object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in network byte-order.
///                 
///                 If the input format was already in network byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
typename
  T::base_type::net_t
  to_network(T& from)
{
  T::base_type::net_t                         to;

  return detail::convert_byte_order < T,
                                      NetByteOrder
                                    >(from, to);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to host byte-order.
///
/// @param T        [typename] The Hg::basic_msg format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::basic_msg object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in host byte-order.
///                 
///                 If the input format was already in host byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
typename
  T::base_type::host_t
  to_host(T& from)
{
  T::base_type::host_t                        to;
  
  return detail::convert_byte_order < T,
                                      HostByteOrder
                                    >(from, to);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to bit endian byte-order.
///
/// @param T        [typename] The Hg::basic_msg format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::basic_msg object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in big endian byte-order.
///                 
///                 If the input format was already in big endian byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
  typename T::base_type::big_t
  to_big_endian(T& from)
{
  typename T::base_type::big_t                    to;

  return detail::convert_byte_order < T,
                                      BigEndian
                                    >(from, to);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to little endian byte-order.
///
/// @param T        [typename] The Hg::basic_msg format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::basic_msg object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in little endian byte-order.
///                 
///                 If the input format was already in little endian byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
  typename T::base_type::little_t
  to_little_endian(T& from)
{
  typename T::base_type::little_t               to;

  // convert the values of the message parameters.
  return detail::convert_byte_order < T,
                                      LittleEndian
                                    >(from, to);
}

} // namespace Hg

#endif

