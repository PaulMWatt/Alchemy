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
// Includes ********************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/container_size.h>
#include <Pb/dynamic.h>

namespace Hg
{

//  Forward Declaraions ********************************************************
template <typename T>
struct SizeOf;

template< class   T,
          size_t  N
        >
struct BitFieldArray;

template< class T,
          class A
        >
struct BitFieldVector;


// This namespace contains specialized versions of the SizeOf implementation
// to help differentiate between type_containers and intrinsic types.
namespace detail
{

//  ****************************************************************************
//  Parameterized implementation of SizeOf 
//
template <typename T, bool isContainer = false >
struct SizeOf_Impl
  : std::integral_constant<size_t, sizeof(T)>
{ };

//  ****************************************************************************
//  Arrays size should only include the elements in the array.
//  However, if the array contains a dynamically sized field, the size cannot
//  be determined at compile-time and must be performed at runtime.
//
template< typename T,
          size_t   N
        >
struct SizeOf_Impl<Hg::BitFieldArray<T,N>, true>
  : std::integral_constant< size_t, Hg::SizeOf<T>::value * N>
{ };

//  ****************************************************************************
//  Arrays size should only include the elements in the array. 
//
template< typename T,
          size_t   N
        >
struct SizeOf_Impl<std::array<T,N>, true>
  : std::integral_constant< size_t, Hg::SizeOf<T>::value * N>
{ };

//  ****************************************************************************
//  The size of BitFieldVectors must be determined at runtime.
//
template< class T,
          class A
        >
struct SizeOf_Impl<Hg::BitFieldVector<T,A>, false>
  : std::integral_constant< size_t, 0>
{ };

//  ****************************************************************************
//  Vectors size is dynamically determined at runtime. 
//
template< class T,
          class A
        >
struct SizeOf_Impl<std::vector<T,A>, false>
  : std::integral_constant< size_t, 0>
{ };

//  ****************************************************************************
//  SizeOf implementation for type_containers
//
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
