/// @file meta/container_size.h
/// 
/// The ContainerSize construct returns the size of a type container.
/// 
/// The ContainerSize type construct will return the size of any 
/// **type_container** type. A type qualifies as a type_container if it has a 
/// specialization of the type_container<T> where T evaluates to true.
/// 
/// By default, T is false for all types with no specialization.
/// 
/// If one of these types is used with ContainerSize, a compile-time
/// error will be thrown due to the type_check<> below.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef CONTAINER_SIZE_H_INCLUDED
#define CONTAINER_SIZE_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/length.h>

namespace Hg
{

// This namespace contains specialized versions of the ContainerSize implementation
// to help differentiate between type_containers and vector_value types.
namespace detail
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


// Parameterized implementation of ContainerSize *******************************
template <typename T, bool use_format_type = has_format_type<T>::value>
struct ContainerSize_Impl
  : std::integral_constant< size_t, 
                            OffsetOf< Hg::length<T>::value, T>::value
                          >
{ };

template <typename T>
struct ContainerSize_Impl<T, true>
  : std::integral_constant< size_t, 
                            OffsetOf< Hg::length< typename T::format_type>::value, 
                                                  typename T::format_type
                                    >::value
                          >
{ };

} // namespace detail

//  ****************************************************************************
/// Calculates the static size of the container passed in.
/// This value is equivalent to the offset of the "end" item in the container.
///             
/// @note       type_check: ContainerT must be a type_container
///             Intrinsic value types such as char, float, int as well as
///             user-defined classes will trigger this assertion.
///             
template <typename ContainerT>
struct ContainerSize
  : type_check<type_container<ContainerT>::value>
  , detail::ContainerSize_Impl< ContainerT>
{ };

} // namespace Hg

#endif
