/// @file meta/dynamic.h
/// 
/// Provides utility functions for dynamically sized field-types.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DYNAMIC_H_INCLUDED
#define DYNAMIC_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/optional.h>
#include <Pb/type_list.h>
#include <Pb/integer_sequence.h>

namespace Hg
{


//  Forward Declarations *******************************************************
template <typename T>
struct has_dynamic;

namespace detail
{

// Parameterized implementation of HasDynamic **********************************
template< typename  T, 
          bool      isContainerT = false 
        >
struct HasDynamic_Impl
  : std::false_type
{ };

// HasDynamic implementation for type_containers *******************************
template <typename T>
struct HasDynamic_Impl<T, true>
  : value_if< Or< vector_value<front_t<T>>,
                  optional_value<front_t<T>>
                >::value,
              bool,
              true,
              has_dynamic<pop_front_t<T>>::value
            >
{ };

// Explicit HasDynamic implementation for vectors ******************************
template< typename  T,
          typename  A,
          bool      isContainerT
        >
struct HasDynamic_Impl<std::vector<T,A>, isContainerT>
  : std::true_type
{ };

// Explicit HasDynamic implementation for optional data fields *****************
template< typename  T,
          bool      isContainerT
        >
struct HasDynamic_Impl<Hg::optional<T>, isContainerT>
  : std::true_type
{ };

//  ****************************************************************************
template< typename ListT,
          typename SeqT,
          size_t   IdxT
        >
struct DynamicFieldSequence
{
  using NextSeqT = typename
    std::conditional< Or< vector_value<front_t<ListT>>,
                          optional_value<front_t<ListT>>
                        >::value,
                      typename IntegralNode<IdxT, SeqT>::type,
                      SeqT
                    >::type;

  using type = typename
    DynamicFieldSequence< pop_front_t<ListT>,
                          NextSeqT,
                          IdxT+1
                        >::type;
};

//  ****************************************************************************
//  Terminating case for an MT typelist simply becomes the specified sequence.
//  The final list that is received in SeqT will be reveresed. Therefore a 
//  call to reverse is made to correct the order before the result is defined.
//
template< typename SeqT,
          size_t   IdxT
        >
struct DynamicFieldSequence<MT, SeqT, IdxT>
  : reverse<SeqT>
{
  using NextSeqT = SeqT;
};


// Parameterized implementation of HasDynamic **********************************
template <typename T, bool IsHaveDynamicT = false >
struct DynamicFields_Impl
{ 
  using type = MT;
};

// HasDynamic implementation for type_containers *******************************
template <typename T>
struct DynamicFields_Impl<T, true>
  : DynamicFieldSequence<T, MT, 0>
{ };

} // namespace detail

//  ****************************************************************************
/// Template to determine if a container has any dynamically sized entry types.
///    
/// This template will test the type T to determine if it is a type_container. 
/// If so a specialize version of the dynamic type test will be used.
///             
/// Sequential types that contain dynamically sized elements are considered 
/// dynamic.
/// 
/// 
template <typename T>
struct has_dynamic
  : detail::HasDynamic_Impl<T, type_container<T>::value>
{ };

//  ****************************************************************************
/// Extracts index values of the vector types in a  message.
/// 
template <typename T>
struct dynamic_fields
  : detail::DynamicFields_Impl<T, has_dynamic<T>::value>
{ };

//  ****************************************************************************
/// Extracts the number of fields that are dynamically sized in the message.
/// 
template <typename T>
struct dynamic_field_count
  : std::integral_constant< size_t,
                            Size<typename dynamic_fields<T>::type>::value
                          >
{ };

} // namespace Hg

#endif
