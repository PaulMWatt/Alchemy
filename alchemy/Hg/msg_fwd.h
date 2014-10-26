/// @file detail/msg_fwd.h
/// 
/// Forward declarations for message processing functions.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MSG_FWD_H_INCLUDED
#define MSG_FWD_H_INCLUDED
//  Includes *******************************************************************
#include <memory>

namespace Hg
{

//  Forward Declarations *******************************************************
//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
std::shared_ptr<BufferT>
  pack_message( MessageT &msg_values, 
                size_t    size);

//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
size_t pack_message(MessageT &msg_values,
                    BufferT  &buffer,
                    size_t    offset);


//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
MessageT& unpack_message(       MessageT &msg_values,
                          const BufferT  &buffer);


//  ****************************************************************************
template< typename MessageT,
          typename BufferT,
          typename SizeTraitT
        >
size_t unpack_message(MessageT &msg_values,
                      BufferT  &buffer,
                      size_t    offset);


} // namespace Hg

#endif 
