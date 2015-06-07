/// @file detail/deduce_type_trait.h
/// 
/// The declaration and definition of deduce_type_trait.
///           
/// A template meta-function that selects the appropriate trait tag for 
/// automatic type deduction of other processing constructs. One particularly
/// important system that depends on this is the DataProxy abstraction.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DEDUCE_TYPE_TRAIT_H_INCLUDED
#define DEDUCE_TYPE_TRAIT_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/meta_util.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A convenience meta-function to define the type trait tag that is best 
/// suited for specified type.
/// The constructed type can be accessed through the public typedef *type*. 
/// 
/// @tparam ValueT      [typename] The value to identify the traits.
/// 
template< typename  ValueT >
struct deduce_type_trait
{
private:
  //  **************************************************************************
  using value_type = ValueT;

  //  **************************************************************************
  //  There are four distinct types of proxy objects required:
  //  Search from most general to most restrictive.
  //  Propagate the type info forward until the last test.
  //  The remaining trait at the end will be the most specific type role
  //  the index_type satisfies.
  // 
  //    1: datum proxy:          Fundamental and nested heterogenous types.
  //                             - This is the catch all type for fields that
  //                               do not require any special processing.
  //    2: bit field proxy       Bit-field types
  //    3: dynamic array proxy   Dynamically sized nested homogenous types
  //    4: fixed array proxy     Fixed sized nested homogenous types 
  // 
  using basic_type = typename 
    std::conditional< packed_value<value_type>::value,
                      packed_trait,
                      fundamental_trait
                    >::type;

  //  **************************************************************************
  //  Defines the nested-type trait to use for compound structures.  
  //
  using nested_type = typename 
    std::conditional< nested_value<value_type>::value,
                      nested_trait,
                      basic_type
                    >::type;

  //  **************************************************************************
  //  Specifies a sequence type trait to use if a sequence_value is selected.  
  //
  using dynamic_type = typename 
    std::conditional< vector_value<value_type>::value,
                      vector_trait,
                      nested_type
                    >::type;

  //  **************************************************************************
  //  Differentiates between an array and a vector type sequence.  
  //
  using deduced_trait = typename 
    std::conditional< array_value<value_type>::value, 
                      array_trait,
                      dynamic_type
                    >::type;

public:

  //  **************************************************************************
  /// The type trait tag deduced for the specified parameter type.
  ///
  using type = deduced_trait;
};

//  **************************************************************************
/// Template alias to access the meta-operation, deduce_type_trait.
///
template <typename value_type>
using deduce_type_trait_t = typename deduce_type_trait<value_type>::type;



//  ****************************************************************************
/// A specialization that will deduce the traits from an index in a type_list.
/// 
/// @tparam IdxT
/// @tparam FormatT
/// 
template< size_t    IdxT,
          typename  FormatT
        >
struct deduce_type_trait_at
{
private:
  using value_type    = typename type_at< IdxT, FormatT >::type;

public:
  //  **************************************************************************
  /// The type trait tag deduced for the specified parameter type.
  ///
  using type = deduce_type_trait_t<value_type>;
};



} // namespace detail

} // namespace Hg

#endif
