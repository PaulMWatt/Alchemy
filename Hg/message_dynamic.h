/// @file message_dynamic.h
/// 
/// Provides utility functions related to messages with dynamic fields.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MESSAGE_DYNAMIC_H_INCLUDED
#define MESSAGE_DYNAMIC_H_INCLUDED
//  Includes *******************************************************************
#include <Hg/detail/message_dynamic_detail.h>

namespace Hg
{

//  ****************************************************************************
/// Query for the amount of dynamic memory required by a specified Hg::basic_msg.
///
/// @tparam T       [typename] The Hg::basic_msg format definition of the 
///                 message to be converted.
/// @param msg      The message object to be queried.
///                           
/// @return         The number of bytes required to populate the dynamically
///                 sized fields from the message is returned.
///                 0 is returned when there is no dynamic data.
///
template< typename T >
size_t dynamic_size_of(const T& msg)
{
  return detail::DynamicSizeWorker<T, has_dynamic<T>::value>().size(msg);
}


//  ****************************************************************************
/// Reports the total size of the dynamic buffers required for this message.
///    
template< typename MsgT,
          typename StorageT
        >
size_t dynamic_size_of(const basic_msg<MsgT, StorageT>& msg)
{
  return detail::DynamicSizeWorker< MsgT, 
                                    has_dynamic<typename MsgT::format_type>::value
                                  >().size(msg);
}

} // namespace Hg

#endif

