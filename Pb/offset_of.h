/// @file meta/offset_of.h
/// 
/// Calculates the offset in bytes of the type at the specified index in the 
/// Type Container.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef OFFSET_OF_H_INCLUDED
#define OFFSET_OF_H_INCLUDED
//  Includes ******************************************************************
#include <meta/size_at.h>

namespace Hg
{

//  ****************************************************************************
/// Calculate the pointer offset in bytes for the specified type. 
/// 
/// One definition is required for every specialization of the array.
/// The array currently supports 32 index entries. The hand written version of 
/// this function for the array is 500 lines longs. Therefore, the following 
/// MACRO will be used to create the required definitions:
///         
///         tmp_ALCHEMY_TYPELIST_OFFSETOF(...)
///         
///         More details further below.
/// 
//  Forward Declaration ********************************************************
template <size_t Index,
          typename ContainerT>
struct OffsetOf
{
  enum { value = 0 };
};

//  ****************************************************************************
/// The item at index 0 will always have an offset of 0. 
/// 
template <typename ContainerT>
struct OffsetOf<0, ContainerT>
{
  enum { value = 0 };
};

} // namespace Hg

// Include Type Container specific implementations.
#include <meta/type_list/offset_of.h>

#endif
