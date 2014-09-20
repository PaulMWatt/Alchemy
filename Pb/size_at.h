/// @file meta/size_at.h
/// 
/// Calculates the size in bytes of the type at the specified index in the Type Container.
/// 
/// This construct depends on the SizeOf meta processing construct.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef SIZE_AT_H_INCLUDED
#define SIZE_AT_H_INCLUDED
// Includes *******************************************************************
#include <meta/type_at.h>
#include <meta/size_of.h>

namespace Hg
{

//  ****************************************************************************
/// Calculate the size in bytes for the specified type.
/// 
// Forward Declaration of Template *********************************************
template <size_t index,
  typename ContainerT>
struct SizeAt;

//  The generic form of this template returns the result of sizeof. ************
template <size_t Index,
  typename TypeT>
struct SizeAt
  : std::integral_constant<size_t, sizeof(TypeT)>
{ };

} // namespace Hg

// Include Type Container specific implementations.
#include <meta/type_list/size_at.h>

#endif
