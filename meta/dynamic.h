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
#include <meta/meta_fwd.h>
#include <meta/type_list.h>
#include <meta/type_at.h>
#include <meta/integer_sequence.h>

namespace Hg
{


//  Forward Declarations *******************************************************
template <typename T>
struct has_dynamic;

namespace detail
{

// Parameterized implementation of HasDynamic **********************************
template <typename T, bool isContainer = false >
struct HasDynamic_Impl
  : std::false_type
{ };

// HasDynamic implementation for type_containers *******************************
template <typename T>
struct HasDynamic_Impl<T, true>
  : value_if< vector_value<typename front<T>::type>::value,
              bool,
              true,
              has_dynamic<typename pop_front<T>::type>::value
            >
{ };


//  ****************************************************************************
template< typename ListT,
          typename SeqT,
          size_t   IdxT
        >
struct DynamicFieldSequence
{
  typedef typename
    std::conditional< vector_value<typename front<ListT>::type>::value,
                      typename IntegralNode<IdxT, SeqT>::type,
                      SeqT
                    >::type             NextSeqT;

  typedef typename
    DynamicFieldSequence< typename pop_front<ListT>::type,
                          NextSeqT,
                          IdxT+1
                        >::type         type;
};

//  ****************************************************************************
//  Terminating case for an empty typelist simply becomes the specified sequence.
//  The final list that is received in SeqT will be reveresed. Therefore a 
//  call to reverse is made to correct the order before the result is defined.
//
template< typename SeqT,
          size_t   IdxT
        >
struct DynamicFieldSequence<empty, SeqT, IdxT>
  : reverse<SeqT>
{
  typedef SeqT                          NextSeqT;
};


// Parameterized implementation of HasDynamic **********************************
template <typename T, bool IsHaveDynamicT = false >
struct DynamicFields_Impl
{ 
  typedef empty       type;
};

// HasDynamic implementation for type_containers *******************************
template <typename T>
struct DynamicFields_Impl<T, true>
  : DynamicFieldSequence<T, empty, 0>
{ };

} // namespace detail

//  ****************************************************************************
/// Template to determine if a container has any dynamically sized entry types.
///    
/// This template will test the type T to determine if it is a type_container. 
/// If so a specialize version of the dynamic type test will be used.
///             
/// A dynamically sized type itself is not considered dynamic. 
/// Sequential types that contain dynamically sized elements is considered 
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

} // namespace Hg

#endif
