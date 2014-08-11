/// @file detail/multival_data.h
/// 
/// Declarations for the class of data fields that can store multiple entries.
///           
/// A parameterized type that abstracts the details of accessing a set of
/// homogenous Datum entries.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#define MULTIVAL_DATA_H_INCLUDED



#ifndef MULTIVAL_DATA_H_INCLUDED
#define MULTIVAL_DATA_H_INCLUDED
//  Includes ******************************************************************
#include <meta/meta_fwd.h>
#include <meta/type_node.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A utilty type defintion to facilitate variable length sequences in Hg.
///
template <typename  T,
          size_t    kt_lower,
          size_t    kt_upper>
struct n_to_n
  : std::conditional< kt_lower == kt_upper,
                      array_trait,
                      vector_trait>::type
{
  static const                size_t k_min = kt_lower;
  static const                size_t k_max = kt_upper;

  typedef T                   data_type;

private:
  // Define an array that will cause this type to accurately report its size.
  T   m_data[k_max];

  // Prevent the instantiation of an object of this type.
  ~n_to_n();
};

//  ****************************************************************************
/// Undefined Specialization for an invalid type declaration.
///
template <typename  T>
struct n_to_n<T,0,0>; 


} // namespace detail


//  ****************************************************************************
/// A type container that holds between zero to n instances of T. 
///
template <typename  T,
          size_t    kt_max>
struct zero_to_n
  : detail::n_to_n<T, 0, kt_max>
{ 
private:
  // Prevent the instantiation of an object of this type.
  ~zero_to_n();
};

//  ****************************************************************************
/// A type container that holds a minimum of one item, and at most n instances of T.
///
template <typename  T,
          size_t    kt_max>
struct one_to_n
  : detail::n_to_n<T, 1, kt_max>
{
private:
  // Prevent the instantiation of an object of this type.
  ~one_to_n();
};

//  ****************************************************************************
/// A type container that holds a fixed size of n instances of T.
///
template <typename  T,
  size_t    kt_max>
struct array_n
  : detail::n_to_n<T, kt_max, kt_max>
{
private:
  // Prevent the instantiation of an object of this type.
  ~array_n();
};

} // namespace Hg

#endif
