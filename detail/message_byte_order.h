/// @file message_byte_order.h
/// 
/// An extraction of the Network to Host conversion functions.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MESSAGE_BYTE_ORDER_H_INCLUDED
#define MESSAGE_BYTE_ORDER_H_INCLUDED
//  Includes *******************************************************************
#include <detail/message_byte_order_detail.h>

namespace Hg
{

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to network byte-order.
///
/// @param T        [typename] The Hg::Message format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                           
/// @return         A Hg::Message object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in network byte-order.
///                 
///                 If the input format was already in network byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
Message<typename T::message_type,
        NetByteOrder>
  to_network(const T& from)
{
  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      NetByteOrder
                                    >(from);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to host byte-order.
///
/// @param T        [typename] The Hg::Message format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                           
/// @return         A Hg::Message object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in host byte-order.
///                 
///                 If the input format was already in host byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
Message<typename T::message_type,
        HostByteOrder>
  to_host(const T& from)
{
  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      HostByteOrder
                                    >(from);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to bit endian byte-order.
///
/// @param T        [typename] The Hg::Message format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                           
/// @return         A Hg::Message object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in big endian byte-order.
///                 
///                 If the input format was already in big endian byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
Message<typename T::message_type,
        BigEndian>
  to_big_endian(const T& from)
{
  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      BigEndian
                                    >(from);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to little endian byte-order.
///
/// @param T        [typename] The Hg::Message format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                           
/// @return         A Hg::Message object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in little endian byte-order.
///                 
///                 If the input format was already in little endian byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
Message<typename T::message_type,
        LittleEndian>
  to_little_endian(const T& from)
{
  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      LittleEndian
                                    >(from);
}

} // namespace Hg

#endif

