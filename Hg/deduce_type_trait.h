/// @file detail/deduce_type_trait.h
/// 
/// The declaration and definition of DeduceTypeTrait.
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
#include <meta/meta_util.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A convenience meta-function to define the type trait tag that is best 
/// suited for specified type.
/// The constructed type can be accessed through the public typedef *type*. 
/// 
/// @paramt ValueT      [typename] The value to identify the traits.
/// 
template< typename  ValueT >
struct DeduceTypeTrait
{
private:
  //  **************************************************************************
  typedef ValueT                        value_type;

  //  **************************************************************************
  /// There are four distinct types of proxy objects required:
  /// Search from most general to most restrictive.
  /// Propagate the type info forward until the last test.
  /// The remaining trait at the end will be the most specific type role
  /// the index_type satisfies.
  ///
  ///   1: datum proxy:          Fundamental and nested heterogenous types.
  ///                            - This is the catch all type for fields that
  ///                              do not require any special processing.
  ///   2: bit field proxy       Bit-field types
  ///   3: dynamic array proxy   Dynamically sized nested homogenous types
  ///   4: fixed array proxy     Fixed sized nested homogenous types 
  ///
  typedef typename 
    std::conditional< bitfield_value<value_type>::value,
                      bitfield_trait,
                      fundamental_trait
                    >::type                     basic_type;

  //  **************************************************************************
  //  Defines the nested-type trait to use for compound structures.  
  //
  typedef typename 
    std::conditional< nested_value<value_type>::value,
                      nested_trait,
                      basic_type
                    >::type                     nested_type;

  //  **************************************************************************
  //  Specifies a sequence type trait to use if a sequence_value is selected.  
  //
  typedef typename
    std::conditional< vector_value<value_type>::value,
                      vector_trait,
                      nested_type
                    >::type                     dynamic_type;

  //  **************************************************************************
  //  Differentiates between an array and a vector type sequence.  
  //
  typedef typename
    std::conditional< array_value<value_type>::value, 
                      array_trait,
                      dynamic_type
                    >::type                     deduced_type_trait;

public:

  //  **************************************************************************
  /// The type trait tag deduced for the specified parameter type.
  ///
  typedef deduced_type_trait                    type;
};

//  ****************************************************************************
/// A specialization that will deduce the traits from an index in a TypeList.
/// 
/// @paramt IdxT
/// @paramt FormatT
/// 
template< size_t    IdxT,
          typename  FormatT
        >
struct DeduceTypeAtTrait
{
private:
  typedef typename 
    TypeAt< IdxT, FormatT >::type           value_type;

  typedef typename
    DeduceTypeTrait<value_type>::type       deduced_type_trait;

public:
  //  **************************************************************************
  /// The type trait tag deduced for the specified parameter type.
  ///
  typedef deduced_type_trait                type;
};


} // namespace detail

} // namespace Hg

#endif
