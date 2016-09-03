/// @file Bi/detail/N_functions.h
/// 
/// Large number theory functions.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_N_FUNCTIONS_H_INCLUDED
#define BI_N_FUNCTIONS_H_INCLUDED

#include <cstdint>

namespace Bi
{

//  Forward Declarations *******************************************************
class Z;

//  ****************************************************************************
/// Returns the absolute value of specified value.
///
template <typename T>
T abs(const T& lhs)
{
  T retval(lhs);
  retval.abs( );

  return retval;
}

//  ****************************************************************************
/// Returns an inverted copy of the specified value.
///
template <typename T>
T negate(const T& lhs)
{
  T retval(lhs);
  retval.negate( );

  return retval;
}

//  ****************************************************************************
//  TODO: Add pow, sqrt, sqr ...




//  ****************************************************************************
/// Computes the binary representation of the reciprocal for the integer value.
///
/// @param[in] value  The big-integer value to use in the reciprocal calculation.
///                   The only value that is not valid is zero. Zero will result
///                   in an exception or selected error handling response.
///
/// @return     The reciprocal of value is returned in a normalized form of the
///             binary fixed-point integer format, with the point placed at
///             the bit position word-size + 1 of the most significant word
///             in the integer Z. This position will have an  implied value of 1 
///             so the entire representation will fit in the available space.
///
Z reciprocal(const Z& value);

//  ****************************************************************************
uint64_t reciprocal(const uint64_t& value);




} // namespace Bi


#endif

