/// @file meta/length.h
/// 
/// Defines a construct that reports the number of types in a **type_container**.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef LENGTH_H_INCLUDED
#define LENGTH_H_INCLUDED
#include <meta/meta_fwd.h>

namespace Hg
{


//  ****************************************************************************
/// Count the number of elements in the specified type container. 
/// 
/// @note   
/// If this version is being used, Length is being instantiated for an invalid
/// type. Also, this generic implementation intentionally does not supply 
/// a value member to report length.
/// 
template <typename ContainerT>
struct length
  : std::integral_constant<size_t, 1>
{ };

// Specialization to handle the case of an MT container. *******************
template <>
struct length< MT > 
  : std::integral_constant<size_t, 1>
{ };

} // namespace Hg

// Include Type Container specific implementations.
#include <meta/type_list/length.h>

#endif
