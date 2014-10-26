/// @file meta/meta_math.h
/// 
/// Math functions implemented in template meta-program style 
/// that will be resolved at compile-time.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef META_MATH_H_INCLUDED
#define META_MATH_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/meta_util.h>

namespace tmp
{

namespace math
{

//  ***************************************************************************
/// Static calculation of power function.
/// 
/// This is a collection of functions that provides that ability to calculate
/// the value of a number raised to an exponent. The calculation is performed
/// at compile-time, and the result can be used in further static calculations
/// and as template parameters.
///               
/// @param T      [typename] The type to use as the result value.
/// @param var    [T] A value of type T to act as the base of the value.
/// @param exp    [unsigned char] The value of the exponent. 
///               The max exponent can be number 
/// 
/// @note         T must be an integral type otherwise the static const 
///               initialization becomes illegal.
/// @note         Supplying a exponent that is <= to the number of bits
///               in T will truncate the result.
///                  
/// usage:
/// ~~~{.cpp}
///     // Calculate 10^3:
///     int result = tmp::math::pow<int, 10, 3>::value
///     
///     // Use the pow<> type to create a bit-mask constant:
///     // Use the pow<> type to create a bit-mask constant.
///     // The BitField Mask can be described with this formula:
///     //   Mask = (2 ^ (number of bits))-1 
///     //        << shifted to the left by offset bits.
///     //
///     static const
///       size_t k_size   = 3;  ///< 3-bits in the mask
///     static const
///       size_t k_offset = 5;  ///< Offset the mask 5-bits
///       
///     static const 
///       T k_mask = T(((tmp::math::pow<T, 2, k_size>::value)-1) << k_offset);
///      
///     // k_mask is now equal to: 0xE0
///     // binary equivalent:      11100000
/// ~~~
///     
template<typename T, T var, unsigned char exp>
struct pow
{
  static const T value = var * pow<T, var, exp-1>::value;
};

//  ***************************************************************************
/// Static calculation of power function.
/// 
template<typename T, T var>
struct pow<T, var, 1>
{
  static const T value = var;
};

//  ***************************************************************************
/// Static calculation of power function.
///
template<typename T, T var>
struct pow<T, var, 0>
{
  static const T value = 1;
};


//  Template Meta implementation to accumulate values of indexed templates. ***

template< size_t index_t, 
          template<size_t> class T
        >
struct accumulate_value
{
  static const size_t value = T<index_t>::value 
                            + accumulate_value<index_t-1,T>::value;
};

template<template<size_t> class T>
struct accumulate_value<0,T>
{
  static const size_t value = T<0>::value;
};

} // namespace math

} // namespace tmp

#endif
