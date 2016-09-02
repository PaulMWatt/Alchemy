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

//  ***************************************************************************
//  Follow naming convention of functions included in C++ 11 or greater
//
//  (Possibly include Z_)
//  - abs
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




namespace Bi
{

typedef std::pair<int, int> value_t;

//  ***************************************************************************
template <typename T>
struct NT_gcd_ex_t
{
  T coef;
  T denom;
};


//  ***************************************************************************
template <typename T>
struct NT_div_t
{
  T quot;
  T rem;
};



//  Explicit Instantitation ***************************************************
using gcd_ex_Z_t  = NT_gcd_ex_t<Z>;
using div_Z_t     = NT_div_t<Z>;


//  Factorization *************************************************************
//  TODO: 

//  ***************************************************************************
/// Calculates the gcd of a and b.
///
/// @param[in] lhs  The first parameter to use in the GCD calculation.
/// @param[in] rhs  The second parameter to use in the GCD calculation.
///                 This value must not be 0.
/// 
/// @return   The largest factor that both input parameter have in common.
///           Returning a value of 1 indicates they are coprime.
///           
///           If rhs is 0, lhs is returned as the result. This may lead
///           to undefined behavior in your calculations. 
/// 
template <typename T>
T gcd(T lhs, T rhs)
{
  while (rhs != 0)
  {
    lhs = lhs % rhs;
    lhs.swap(rhs);
  }

  return lhs;
}

//  ***************************************************************************
/// Calculates the gcd of a and b using the extended euclidean method.
///
/// @param[in] lhs  The first parameter to use in the GCD calculation.
/// @param[in] rhs  The second parameter to use in the GCD calculation.
/// 
/// @return   A pair that indicates results.
///           The first parameter contains the solution to 'x' in the expression:
///
///              ax + by = gcd(a,b)
///
///           The second parameter contains the gcd(a,b)
/// 
template <typename T>
NT_gcd_ex_t<T> gcd_ex(T lhs, T rhs)
{
  T x0 = 1;
  T x1 = 0;

  while (rhs != 0)
  {
    // TODO: Need to add a function that captures the remainder when a number is divided.
    NT_div_t<T> result = {0};
    
    result.quot = lhs / rhs;
    result.rem  = lhs % rhs;

    T x2 = x0 - (result.quot * x1);

    x0.swap(x1);
    x1.swap(x2);

    lhs.swap(rhs);
    rhs = result.rem;
  }

  return {x0, lhs};
}

//  ***************************************************************************
/// This algorithm uses Bezout's Identity to solve for the coefficients (x,y)
/// in the following equation:
///
///     ax + by = gcd(a,b)  ->   ax = 1 mod(b)
///                         ->    y = (gcd(a,b)-ax) / b
///
/// Source: "From Mathematics to Generic Programming", pg 225
/// 
value_t solve_gcd_coefficients(int a, int b);

//  ***************************************************************************
/// Square and multiply from Stinson
///
uint16_t square_and_multiply(uint16_t x, uint16_t c, uint16_t n);

//  ***************************************************************************
uint64_t square_and_multiply(uint64_t x, uint64_t c, uint64_t n);

//  Primality Testing *********************************************************

//  Modulus Operations ********************************************************
//  TODO: Chinese Remainder Theorem
//        Modular Inverse
//
//  ***************************************************************************
/// Calculates the multiplicative inverse of a mod(n).
///
int multiplicative_inverse(int a, int n);

//  ***************************************************************************
/// Calculates the chinese remainder from two lists of pairwise coprime values.
///
int chinese_remainder(const std::vector<int> &a,
                      const std::vector<int> &m);


//  Number Generators *********************************************************
//  TODO: Fibonacci Numbers
//        Prime Numbers
//        Sequences
//        Jacobi Number
//        Legendre Number

//  ***************************************************************************
int pollard_rho_factorization(int n, uint64_t x);



} // namespace Bi

#endif
