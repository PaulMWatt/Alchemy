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
/// @param T        [typename] The Hg::MessageT format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::MessageT object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in network byte-order.
///                 
///                 If the input format was already in network byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
MessageT< typename T::message_type,
          NetByteOrder,
          typename T::storage_type
        >
  to_network(T& from)
{
  MessageT< typename T::message_type,
            NetByteOrder,
            typename T::storage_type> to;

  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      typename T::storage_type,
                                      NetByteOrder
                                    >(from, to);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to host byte-order.
///
/// @param T        [typename] The Hg::MessageT format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::MessageT object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in host byte-order.
///                 
///                 If the input format was already in host byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
MessageT< typename T::message_type,
          HostByteOrder,
          typename T::storage_type
        >
  to_host(T& from)
{
  MessageT< typename T::message_type,
            HostByteOrder,
            typename T::storage_type> to;
  
  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      typename T::storage_type,
                                      HostByteOrder
                                    >(from, to);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to bit endian byte-order.
///
/// @param T        [typename] The Hg::MessageT format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::MessageT object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in big endian byte-order.
///                 
///                 If the input format was already in big endian byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
MessageT< typename T::message_type,
          BigEndian,
          typename T::storage_type
        >
  to_big_endian(T& from)
{
  MessageT< typename T::message_type,
            BigEndian,
            typename T::storage_type> to;

  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      typename T::storage_type,
                                      BigEndian
                                    >(from, to);
}

//  ****************************************************************************
/// Parameterized function to convert a Hg::Message to little endian byte-order.
///
/// @param T        [typename] The Hg::MessageT format definition of the 
///                 message to be converted.
/// @param from     The message object to convert from.
///                 Ownership of the memory that belongs to the input type will 
///                 be transferred to the returned instance, and the conversion 
///                 will occur in-place.
///                           
/// @return         A Hg::MessageT object using the same format and data type as the 
///                 input buffer will be returned. The data in the buffer will 
///                 be in little endian byte-order.
///                 
///                 If the input format was already in little endian byte-order,
///                 no conversion operations will be performed.
///
template< typename T >
MessageT< typename T::message_type,
          LittleEndian,
          typename T::storage_type
        >
  to_little_endian(T& from)
{
  MessageT< typename T::message_type,
            LittleEndian,
            typename T::storage_type> to;

  // convert the values of the message parameters.
  return detail::convert_byte_order < typename T::message_type,
                                      typename T::byte_order_type,
                                      typename T::storage_type,
                                      LittleEndian
                                    >(from, to);
}

} // namespace Hg

#endif

