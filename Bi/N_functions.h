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

// TODO: Need to return and add constraints to these functions for integral types only.

//  ****************************************************************************
/// Indicates if the specified value is odd.
///
/// @param[in] value  The value to test for odd.
///
/// @return   true if the value is odd,
///           false if the value is even.
///
template <typename T>
bool odd(const T& value)
{
  return bool(value.low_word() & 0x01);
}

//  ****************************************************************************
/// Indicates if the specified value is even.
///
/// @param[in] value  The value to test for even.
///
/// @return   true if the value is even,
///           false if the value is odd.
///
template <typename T>
bool even(const T& value)
{
  return !odd(value);
}

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
//  TODO: sqr


//  ****************************************************************************
//  TODO: These utility functions will be moved into a detail sub-namespace.
template <typename T>
T& power_accumulate(T& rval, T& base, T& exp)
{
  if (0 == exp.low_word())
    return rval;

  while (true)
  {
    if (odd(exp))
    {
      rval *= base;
      if (1 == exp.low_word())
        return rval;
    }

    exp >>= 1;

    // TODO: Again, need to revisit when efficient square algorithm that does not copy.
    base *= base;
  }
}

//  ****************************************************************************
/// Calculates base^n, i.e., lhs raised to the xth power.
///
/// @param[in] base   The base value to multiply by an exponent.
/// @param[in] x      The exponent in the calculation.
///
/// @return           The calculation base^n is returned.
///
/// @note: source for algorithm, 
///         A. Stepanov, D. Rose, "From Mathematics to Generic Programming," 2014
///
template <typename T>
T pow(const T& base, const T& x)
{
  // TODO: Need to add support for negative exponents. Will do this when I have better support for integer reciprocals.
  T exp(x);
  T rval(base);

  while (even(exp))
  {
    // TODO: Add optimized implementation for squaring
    rval *= rval;
    exp >>= 1;
  }

  if (1 == exp.low_word())
    return rval;

  exp -=  1;
  exp >>= 1;
  return power_accumulate(rval, rval*rval, exp);
}

//  ****************************************************************************
//  TODO: sqrt

//  ****************************************************************************
//  TODO: cbrt



//  Function Objects ***********************************************************
//  TODO: Add a complete set that complements what is found in the C++ Standard Library
//  ****************************************************************************
/// Function object to negate the value of a Bi type.
///
struct negate { 
  template <typename T>
  constexpr T operator()(const T& rhs) const
  {
    return -T(rhs);
  }
};


//  ****************************************************************************
/// Computes the binary representation of the reciprocal for the integer value.
///
/// @param[in] rhs  The big-integer value to use in the reciprocal calculation.
///                 The only value that is not valid is zero. Zero will result
///                 in an exception or selected error handling response.
///
/// @return     The reciprocal of value is returned in a normalized form of the
///             binary fixed-point integer format, with the point placed at
///             the bit position word-size + 1 of the most significant word
///             in the integer Z. This position will have an  implied value of 1 
///             so the entire representation will fit in the available space.
///
struct reciprocal { 
  template <typename T>
  constexpr T operator()(const T& rhs) const
  {
    return T(1/rhs);
  }
};




} // namespace Bi


#endif

