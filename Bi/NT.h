/// @file Bi/NT.h
/// 
/// Number Theory related algorithms.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_NT_H_INCLUDED
#define BI_NT_H_INCLUDED
//  Includes *******************************************************************
#include <Bi/Bi_defs.h>

#include <Bi/gcd.h>

//  ***************************************************************************
//  Follow naming convention of functions included in C++ 11 or greater
//
//  (Possibly include Z_)
//  - div (quotient and remainder)
//  - remainder
//  - remquo
//  - fma (fused multiply add)
//  - min / max / minmax
//  - exp, exp2, expm1
//  - log, log10, log2, loglp
//  - pow, sqrt, cbrt, hypot
//  - ceil, floor, trunc, copysign
//  - signbit
//
//  Functors
//  - isgreater, isgreaterequal, isless, islessequal, islessgreater
//


// Also planning on adding:
//
// Fibonacci number
// Factorial
// Generators: Fibonacci Sequence, primes, etc.
// Discrete Probability: Discrete Random Variables, 
//                       Probability Distribution Functions
//                       Cumulative Distribution Functions
//                       Binomial Coefficients
//
// Matrix
// Vector
//
// Modular Artithmetic:
//    Modular Exponentiation
//
//




namespace Bi
{


//  Fundamental ***************************************************************
//  ***************************************************************************
/// TODO: Working on a parameterized mechanism to return the identity element.

//  ***************************************************************************
/// Returns the identity element for the additive type.
///
//template <typename T>
//T identity_element<T, T::plus>()
//{
//  return T(0);
//}

//  ***************************************************************************
/// Returns the identity element for the multiplicative type.
///
//template <typename T>
//T identity_element<T, T::multiplies>()
//{
//  return T(1);
//}


//  Modulus Operations ********************************************************
//  ***************************************************************************
/// Calculates the multiplicative inverse of a mod(n).
///
template <typename T>
T multiplicative_inverse(T a, T n)
{
  std::pair<T, T> p = gcd_ex(a, n);

  if (p.second != 1)
    return 0;

  if (p.first < 0)
    return p.first + n;

  return p.first;
}

//  ***************************************************************************
/// Calculates the chinese remainder from two lists of pairwise coprime values.
/// The input vectors must be the same length as the algorithm interprets 
/// these values pairwise matches.
///
/// param[in] a   The first list of coprime values.
/// param[in] n   The second list of coprime values. 
///
///
///
template <typename T>
T chinese_remainder(const std::vector<T> &a,
                    const std::vector<T> &m)
{
  if (a.size() != m.size())
    return 0;

  // This value is the product of all of the elements in m.
  T M = 1;
  for (auto i : m)
  {
    M *= i;
  }

  T sum = 0;
  const size_t r = a.size();

  for (size_t i = 0; i < r; ++i)
  {
    T Mi  = M / m[i];
    T yi  = multiplicative_inverse(Mi, m[i]);

    sum  += a[i] * Mi * yi;
  }

  // The result is the accumulated sum modulo M.
  return sum % M;
}


//  ***************************************************************************
int pollard_rho_factorization(int n, uint64_t x);


//  Primality Testing *********************************************************

//  Number Generators *********************************************************
//  TODO: Fibonacci Numbers
//        Prime Numbers
//        Sequences
//        Jacobi Number
//        Legendre Number



//  Alias definitions for call convenience ************************************
//  ***************************************************************************
namespace mod
{ 

//  ***************************************************************************
/// Calculates the multiplicative inverse of a mod(n).
/// This is a instance created for convenience.
///   Refer to: multiplicative_inverse
///
template <typename T>
T mul_inv(T a, T n)
{
  return multiplicative_inverse(a, n);
}

//  ***************************************************************************
/// Calculates the chinese remainder from two lists of pairwise coprime values.
/// This is a instance created for convenience.
///   Refer to: chinese_remainder
///
template <typename T>
T CRT(const std::vector<T> &a,
      const std::vector<T> &m)
{
  return chinese_remainder(a, m);
}

} // namespace mod

} // namespace Bi

#endif
