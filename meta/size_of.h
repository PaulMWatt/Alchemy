/// @file meta/size_of.h
/// 
/// Calculates the size in bytes of the type at the specified index in the 
/// Type Container.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef SIZE_OF_H_INCLUDED
#define SIZE_OF_H_INCLUDED
/* Includes ******************************************************************/
#include <meta/meta_fwd.h>
#include <meta/container_size.h>

namespace Hg
{

// This namespace contains specialized versions of the SizeOf implementation
// to help differentiate between type_containers and intrinsic types.
namespace detail
{

// Parameterized implementation of SizeOf **************************************
template <typename T, bool isContainer = false >
struct SizeOf_Impl
  : std::integral_constant<size_t, sizeof(T)>
{ };

//  Vectors size is dynamically determined at runtime. ************************
template< typename T,
          typename A
        >
struct SizeOf_Impl<std::vector<T,A>, false>
  : std::integral_constant< size_t, 0>
{ };

// SizeOf implementation for type_containers ***********************************
template <typename T>
struct SizeOf_Impl<T, true>
  : std::integral_constant< size_t,
                            ContainerSize<T>::value
                          >
{ };

} // namespace detail


//  ****************************************************************************
/// Template to determine the size of a type or type container.
///    
/// This template will test the type T to determine if it is a type_container. 
/// If so a specialize version of the size calculator will be used.
///             
/// The default implementation uses the sizeof operator on type T.
/// 
template <typename T>
struct SizeOf
  : detail::SizeOf_Impl<T, type_container<T>::value>
{ };

} // namespace Hg

#endif
