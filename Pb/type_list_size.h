/// @file Pb/type_list_size.h
/// 
/// Provides utility functions that calculate the size and location of
/// types within a type_list.
///
//  
//  - **size_at**
//      Determines the size of the element at the specified index in the **type_list**.
// 
//  - **size_of**
//      Determines the size of all of the elements in the **type_list**.
// 
//  - **offset_of**
//      Determines the offset in bytes of the specified element in the **type_list**.
// 
//
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef TYPE_LIST_SIZE_H_INCLUDED
#define TYPE_LIST_SIZE_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/type_list.h>
#include <Pb/dynamic.h>

namespace Hg
{

//  Forward Declarations *******************************************************
template< std::size_t IdxT, typename T>
struct size_at;

template< typename T>
struct size_of;

template< std::size_t IdxT, typename T>
struct offset_of;

namespace detail
{

template <typename, bool>
struct element_size;

template< typename T>
struct container_size;

} // namespace detail

//  ****************************************************************************
/// Meta-function indicates the size of type_list elements.
/// 
/// @tparam T     The type_list to be queried.
///
/// @return       A type declaration called 'value' is the size of the type in bytes.
///
/// Usage:
/// ~~~{.cpp}
/// using TL = type_list<int, char, float, long>;
/// 
/// // 32-bit system
/// static_assert(std::is_same<13, size_of<TL>::value>::value, "");
/// 
/// ~~~
///
/// @note: This function should be used when dealing with type_lists because it 
/// calculates sizes based upon the actual types contained withing type_lists, 
/// sub-types, and sequence containers like arrays and vectors.
/// 
/// @note: The built in sizeof operator calculates sizes based on the amount of 
/// memory that a type requires to store when instantiated. A type_list 
/// does not contain any data fields, therefore it will return a sizeof(type_list):= 1.
///
template< typename T >
struct size_of
  : detail::element_size<T, type_container<T>::value>
{ };



//  ****************************************************************************
/// Meta-function indicates the size of an element at a specific type_list index.
/// 
/// @tparam IdxT  The zero-based index to reference in the type_list.
///               This value must be < the number of elements in the type_list.
/// @tparam T     The type_list to be queried.
///
/// @return       A type declaration called 'value' is the size of the type in bytes.
///
/// Usage:
/// ~~~{.cpp}
/// using TL = type_list<int, char, float, long>;
///
/// static_assert(std::is_same<1, size_at<1, TL>::value>::value, "");
/// 
/// ~~~
///
template< std::size_t IdxT, 
          typename    T
        >
struct size_at
  : std::integral_constant<std::size_t, size_of<type_at_t<IdxT,T>>::value>
{ };



//  ****************************************************************************
/// Meta-function indicates the offset of an element from the start of a type_list.
/// 
/// @tparam IdxT  The zero-based index to reference in the type_list.
///               This value must be < the number of elements in the type_list.
/// @tparam T     The type_list to be queried.
///
/// @return       A type declaration called 'value' is the number of bytes of the offset.
///
/// Usage:
/// ~~~{.cpp}
/// using TL = type_list<int, char, float, long>;
///
/// // on a 32-bit system
/// static_assert(std::is_same<5, offset_of<2, TL>::value>::value, "");
/// 
/// ~~~
///
template< std::size_t IdxT,
          typename    T>
struct offset_of
  : std::integral_constant<std::size_t, offset_of<IdxT-1, T>::value
                                      + size_at  <IdxT-1, T>::value>
{ };


//  ****************************************************************************
/// Meta-function indicates the offset of the zero-index element.
/// 
/// @tparam T     The type_list to be queried.
///
/// @return       The offset for the item at index 0 will always be 0.
///
template< typename T>
struct offset_of<0, T>
  : std::integral_constant<std::size_t, 0>
{ };



//  ****************************************************************************
namespace detail
{
//  ****************************************************************************
//  Default implementation of the element_size meta-function. 
//
template <typename T, bool IsContainerT = false >
struct element_size
  : std::integral_constant<size_t, sizeof(T)>
{ };


//  ****************************************************************************
//  Calculates the size of an array of types.
//
template< typename T,
          size_t   N,
          bool     IsNestedT
        >
struct size_of_array
  : std::integral_constant< size_t, Hg::size_of<T>::value * N>
{ };

//  ****************************************************************************
//  Calculates the size of an array of nested_types.
//
template< typename T,
          size_t   N
        >
struct size_of_array<T,N,true>
  : std::integral_constant< size_t, Hg::size_of<typename T::format_type>::value * N>
{ };

//  ****************************************************************************
//  Arrays size should only include the elements in the array. 
//
template< typename T,
          size_t   N
        >
struct element_size<std::array<T,N>, false>
  : size_of_array<T, N, std::is_base_of<nested_trait, T>::value>
{ };

//  ****************************************************************************
//  Vectors size is dynamically determined at runtime. 
//
template< typename T,
          typename A
        >
struct element_size<std::vector<T,A>, false>
  : std::integral_constant< size_t, 0>
{ };

//  ****************************************************************************
//  element_size implementation for type_containers.
//
template <typename T>
struct element_size<T, true>
  : std::integral_constant< size_t,
                            container_size<T>::value
                          >
{ };

namespace impl
{

//  ***************************************************************************
/// Detect if the specified type has a type member called 'format_type'.
///
template < typename T > 
struct has_format_type
{ 
private: 
  // Identify by using a pointer to a member 
  template < typename U > 
  static yes_t  <typename U::format_type> selector(U); 
  static no_t selector(...); 

  static T* this_t(); 
public: 
  static const bool value = 
    sizeof(selector(*this_t())) != sizeof(no_t);  
}; 

// Parameterized implementation of container_size ******************************
template <typename T, bool use_format_type = has_format_type<T>::value>
struct container_size
  : std::integral_constant< size_t, 
                            offset_of< Hg::length<T>::value, T>::value
                          >
{ };

template <typename T>
struct container_size<T, true>
  : std::integral_constant< size_t, 
                            offset_of< Hg::length< typename T::format_type>::value, 
                                                   typename T::format_type
                                     >::value
                          >
{ };

} // namespace impl

//  ****************************************************************************
/// Calculates the static size of the container passed in.
///             
template< typename T>
struct container_size
  : impl::container_size<T>
{
  static_assert(true, // TODO: Replace with: type_container<T>::value
                "Type 'T' does not have the 'container_trait' type-trait.");
};

} // namespace detail

} // namespace Hg

#endif
