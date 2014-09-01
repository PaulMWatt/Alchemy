/// @file detail/deduce_array_type.h
/// 
/// A type function to deduce the correct definition for a Hg array.
///           
/// A template meta-function that selects the appropriate type of declaration
/// required for an array of types. In order to provide an interface that
/// feels transparent and natural to the application programmer, it is sometimes
/// necessary to introduce proxy-types to provide the natural interface.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DEDUCE_PROXY_TYPE_H_INCLUDED
#define DEDUCE_PROXY_TYPE_H_INCLUDED
//  Includes ******************************************************************
#include <Hg/deduce_type_trait.h>
#include <Hg/datum/basic_datum.h>
#include <meta/bit_field/bit_field_array.h>


namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A convenience meta-function to define the correct type of array for a msg field.
/// The deduced type can be accessed through the public typedef *type*. 
/// 
/// @paramt IdxT
/// @paramt FormatT
/// @paramt OffsetT
/// 
template< typename  T,
          size_t    N
        >
struct DeduceArrayType
{
  //  **************************************************************************
  //  Identify the traits of the value type for selection of the best array type.
  typedef typename 
    DeduceTypeTrait < T >::type         selected_type;

  //  **************************************************************************
  //  The selected array type definition for the specified input type.
  typedef typename
    std::conditional< std::is_same< selected_type, 
                                    bitfield_trait
                                  >::value,
                      BitFieldArray<T,N>,
                      std::array<T,N>
                    >::type             type;            
};


} // namespace detail

} // namespace Hg

#endif
