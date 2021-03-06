/// @file meta/meta_util.h
/// 
/// Template Meta-Programming Utility Definitions
/// 
/// This file contains small object toolkit constructs useful for TMP
/// as well as basic Code Generation MACROS to simplify the 
/// declaration and appearance of repetitive entries.
/// 
/// Remember, these constructs are required to allow the compiler to 
/// inspect and deduce values at compile-time. Otherwise many of these
/// constructs would appear to be over complicated to simply define 
/// a value, such as a boolean true.
///
/// For meta-programming constructs, the compile-time equivalent to a 
/// runtime variable is a type. Therefore, many constructs that provide
/// calculations and behave like function calls are implemented as 
/// new types, typically structs.
///
/// Contains: instance_of       Base class used to declare a type
///           type_equal        Sets an internal ::value to true if two types are equal
///           value_if          A ternary operation to select a value
///           one_or_zero       Casts a boolean value to an integer 1 or 0
///           value_type_of     Extracts the value_type of a data value.
///                            
///
/// @note:    TAGGING:  Deriving from a type that reports desired traits.
///           Tagging is an important technique in meta-template programming because
///           it simplifies the instantiation of more complex constructs and 
///           encourages reuse.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef META_UTIL_H_INCLUDED
#define META_UTIL_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/compiler.h>
#include <type_traits>
#include <array>
#include <vector>

namespace Hg
{

//  ****************************************************************************
/// A type to represent an MT type for defining type lists and type arrays.
/// 
struct MT { };

//  ****************************************************************************
/// An alias that may be more readable.
/// 
using empty = MT;


//  ****************************************************************************
/// A short alias for the 'unsigned char'.
/// 
using byte_t = unsigned char;

//  ****************************************************************************
/// Affirmative Type for use in SFINAE selection templates.
/// 
template < typename T > 
struct yes_t 
{ char buffer[2]; }; 
 
//  ****************************************************************************
/// Negative Type for use in SFINAE selection templates.
/// 
using no_t = char; 

//  ****************************************************************************
/// This construct provides mechanism to declare and 
/// initialize compile-time global constants.
///               
/// @note           This template type is very inexpensive to instantiate for 
///                 the compiler. Therefore it is used extensively when possible.
/// 
template <typename T>
struct instance_of
{
  using type = T;

  // This constructor allows global constants to be declared and initialized.
  instance_of(int = 0)
  { }
};

//  ***************************************************************************
/// This construct provides the compile-time equivalent of 
/// the ternary operator ?: for value selection.
///
template <bool predicate, typename T, T trueValue, T falseValue>
struct value_if
  : std::integral_constant<T, trueValue>
{ };

//  ***************************************************************************
/// Specialization for the false condition of the value selector.
///
template <typename T, T trueValue, T falseValue>
struct value_if<false, T, trueValue, falseValue>
  : std::integral_constant<T, falseValue>
{ };

//  ***************************************************************************
/// Casts a static const boolean to an int of one or a zero.
///
template <bool Predicate>
struct one_or_zero
  : std::integral_constant<int, 1>
{ };

//  ***************************************************************************
/// Specialization for the false condition of the bool selector.
///
template <>
struct one_or_zero<false>
  : std::integral_constant<int, 0>
{ };

//  ***************************************************************************
/// Static Assertion Base Template to verify type constraints for an object. 
///               
/// Privately inherit an object from this struct, and supply the compile-time 
/// check that reduces to a boolean value as the specialization type.
/// This instance of the template will compile properly.
///
template <bool T>
struct type_check
{  };

//  ***************************************************************************
/// A false specialization for the type_check template.
/// This struct contains no definition to force a compiler error
/// if the input boolean type resolves to false.
///               
/// If a compiler error occurs, inspect the class that triggered 
/// the compiler error. This error indicates that the type
/// passed in for the derived class does not meet criteria 
/// established for proper functionality.
///
template<>
struct type_check<false>;

//  ***************************************************************************
/// Compares types against the MT type.
///
template <typename T>
struct empty_type
  : std::is_same<T, MT>
{ };

//  Boolean Operations ********************************************************
//  ***************************************************************************
/// Takes the logical not of the type.
/// The type passed in must have a static boolean value named "value".
///
template <typename T>
struct Not
  : std::integral_constant<bool, !T::value>
{  };

//  ***************************************************************************
/// Takes the logical and of the two input types.
/// The types passed in must have a static boolean value named "value".
///
template <typename T,
          typename U>
struct And
  : std::integral_constant<bool, T::value && U::value>
{  };

//  ***************************************************************************
/// Takes the logical or of the input types.
/// The types passed in must have a static boolean value named "value".
///
template <typename T,
          typename U>
struct Or
  : std::integral_constant<bool, T::value || U::value>
{  };

//  Type tags for differentiating objects *************************************
//  ***************************************************************************
/// Indicates the field or message has a fixed static size at compile-time.
///
struct static_size_trait { };

//  ***************************************************************************
/// Indicates the field or message has a dynamic size determined at run-time.
///
struct dynamic_size_trait { };

//  ***************************************************************************
/// fundamental_trait identifies fundamental integral types.
///
struct fundamental_trait 
  : static_size_trait
{ };

//  ***************************************************************************
/// packed_trait identifies fundamental integral types, that automatically
/// perform bit-shift and mask operations to simulate bit-fields.
///
struct packed_trait 
  : static_size_trait
{ };

//  ***************************************************************************
/// A container_trait describes any type that is not a fundamental type or 
/// bitfield. These types facilitate more complex data structures.
///
struct container_trait{ };


//  ***************************************************************************
/// A nested type indicates that the data that is contained within, 
/// possibly requires an internal inspection to facilitate correct behavior.
///
struct nested_trait 
  : container_trait   { };


//  ***************************************************************************
/// Sequence types are a class of types that contain more than one element
/// of the same type in series.
///
struct sequence_trait
  : nested_trait      { };

//  ***************************************************************************
/// Any field type that is not required to appear in a message format.
///
struct optional_trait
  : dynamic_size_trait
{ };

//  ***************************************************************************
/// Indicates the fields format is undefined and will be determined by context.
///
struct opaque_trait 
  : sequence_trait { };

//  ***************************************************************************
/// A sequence type that represents a dynamically sized field.
///
struct vector_trait
  : sequence_trait
  , dynamic_size_trait
{ };


//  ***************************************************************************
/// A sequence type that has a fixed size.
///
struct array_trait
  : sequence_trait    
  , static_size_trait
{ };


//  ***************************************************************************
/// Indicates the format of the vector data is undefined, opaque.
///
struct opaque_vector_trait 
  : vector_trait
  , opaque_trait
{ };

//  ***************************************************************************
/// Indicates the format of the array data is undefined, opaque.
///
struct opaque_array_trait 
  : array_trait
  , opaque_trait
{ };


//  BitField Message Field Discriminators *************************************
//  Objects derived from the packed_trait are considered bitlist containers.
template <typename T>
struct packed_value
  : std::integral_constant< bool,
                            std::is_base_of<packed_trait, T>::value>
{  };


//  Type Container Discriminators *********************************************
//  Objects derived from the container_trait are considered type containers.
template <typename T>
struct type_container
  : std::integral_constant<bool, 
                            std::is_base_of<container_trait, T>::value>
{  };


//  A specialization of the emtpy type because it acts as a teminator. ********
template<>
struct type_container<MT>
  : std::integral_constant<bool, false>
{  };


//  Fundamental field type discriminators *************************************
template <typename T>
struct fundamental_value
  : std::integral_constant< bool,
                            !type_container<T>::value>
{  };


//  Nested Value Discriminators ***********************************************
template <typename T>
struct nested_value
  : std::integral_constant < bool,
                             type_container<T>::value && !packed_value<T>::value>
{  };


//  A specialization of the emtpy type because it acts as a teminator. ********
template<>
struct nested_value<MT>
  : std::integral_constant<bool, false>
{ };

//  Detects types that are optionally present *********************************
//  ***************************************************************************
/// Detect types that are defined as optionally available.
///
template< typename T>
struct optional_value
  : std::is_base_of<optional_trait, T>
{ };


//  Variable Length Homogenous Containers are considered vector_values *******
//  ***************************************************************************
/// Detect a std::vector type. This is the default false case.
///
template< typename T >
struct is_std_vector
  : std::false_type
{ };


//  ***************************************************************************
/// Detect a std::vector type. This version identifies the std::vector.
/// T is the type the vector contains,
/// A is the allocator.
///
template< typename T,
          typename A
        >
struct is_std_vector<std::vector<T,A> > 
  : std::true_type
{ };

//  ***************************************************************************
template <typename T>
struct vector_value
  : And < Or < std::is_base_of<vector_trait, T>,
               is_std_vector<T>
             >,
          Not < std::is_base_of<array_trait, T> > 
        >
{ };

//  ***************************************************************************
template<>
struct vector_value<MT>
  : std::integral_constant<bool, false>
{ };

//  Fixed Length Homogenous Containers are considered array_values ************
//  ***************************************************************************
/// Detect a std::array type. This is the default false case.
///
template< typename T >
struct is_std_array
  : std::false_type
{ };

//  ***************************************************************************
/// Detect a std::array type. This version identifies the std::array.
///
template< typename T,
          size_t   N
        >
struct is_std_array<std::array<T,N> > 
  : std::true_type
{ };

//  ***************************************************************************
//  Detect native array types.
template< typename T>
struct array_value
  : And < Or < std::is_base_of<array_trait, T>,
               is_std_array<T>
             >,
          Not < std::is_base_of<vector_trait, T> >
        >
{ };

//  Multi-variable types are containers of homogenous entries *****************
template <typename T>
struct sequence_value
  : std::integral_constant< bool,
                            Or< typename std::is_base_of<sequence_trait, T>,
                                Or< vector_value<T>,
                                    array_value<T>
                                  >
                              >::value 
                          >
{ };

//  ***************************************************************************
template<>
struct sequence_value<MT>
  : std::integral_constant<bool, false>
{ };


//  Reports if a data type is opaque ******************************************
//  ***************************************************************************
/// Detect a sequence type that uses an unsigned char (byte_t).
///
template< typename T >
struct is_opaque
  : std::false_type
{ };


//  ***************************************************************************
/// Detect a std::vector opaque type.
/// A is the allocator.
///
template< typename A >
struct is_opaque<std::vector<byte_t,A> > 
  : std::true_type
{ };


//  ***************************************************************************
/// Detect a std::array opaque type. 
/// N is the number of entries.
///
template< size_t   N >
struct is_opaque<std::array<byte_t,N> > 
  : std::true_type
{ };


//  ***************************************************************************
/// Detect if the current value type is opaque.
///
template< typename T >
struct opaque_value 
  : std::integral_constant< bool, is_opaque<T>::value >
{ };


} // namespace Hg

#endif
