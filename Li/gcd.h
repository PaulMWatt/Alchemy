/// @file Bi/gcd.h
/// 
/// Greatest Common Denominator related algorithms.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_GCD_H_INCLUDED
#define BI_GCD_H_INCLUDED

#include <vector>
#include <utility>


namespace Bi
{

typedef std::pair<int, int> value_t;


//  ***************************************************************************
/// Calculates the gcd of a and b using the extended euclidean method.
///
/// The first parameter contains the solution to 'x' in the expression:
///
///       ax + by = gcd(a,b)
///
/// The second parameter contains the gcd(a,b)
/// 
value_t extended_gcd(int a, int b);

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
/// Calculates the multiplicative inverse of a mod(n).
///
int multiplicative_inverse(int a, int n);

//  ***************************************************************************
/// Calculates the chinese remainder from two lists of pairwise coprime values.
///
int chinese_remainder(const std::vector<int> &a,
                      const std::vector<int> &m);

//  ***************************************************************************
/// Square and multiply from Stinson
///
uint16_t square_and_multiply(uint16_t x, uint16_t c, uint16_t n);

//  ***************************************************************************
uint64_t square_and_multiply(uint64_t x, uint64_t c, uint64_t n);

//  ***************************************************************************
int pollard_rho_factorization(int n, uint64_t x);

} // namespace Bi

#endif
