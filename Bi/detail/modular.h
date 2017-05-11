/// @file Bi/detail/modular.h
/// 
/// Modular arithmetic algorithms.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_DETAIL_MODULAR_H_INCLUDED
#define BI_DETAIL_MODULAR_H_INCLUDED
//  Includes *******************************************************************
#include <Bi/Bi_defs.h>

namespace Bi
{
namespace detail
{ 


//  ***************************************************************************
/// Stores the return value for a call to the extended GCD function.
/// 
//template <typename T>
//struct NT_gcd_ex_t
//{
//  T coef;     ///< The coefficient for the lhs parameter
//  T denom;    ///< The GCD between the lhs and rhs parameters
//};


//  ***************************************************************************
/// This type is a templated parallel for the version in std:: called div_t.
///
template <typename T>
struct NT_div_t
{
  T quot;
  T rem;
};



//  Explicit Instantitation ***************************************************
using gcd_ex_Z_t  = std::pair<Z, Z>;
using div_Z_t     = NT_div_t<Z>;
using coef_Z_t    = std::pair<Z, Z>;

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


//  Factorization *************************************************************
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
///           return.coef contains the solution to 'x' in the expression:
///
///              ax + by = gcd(a,b)
///
///           return.denom contains the gcd(a,b). 
///           A value of 1 indicates they are coprime.
/// 
template <typename T>
std::pair<T, T> gcd_ex(T lhs, T rhs)
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
/// Calculates the gcd of a and b using the extended euclidean method.
/// This implementation specifically handles types: int and int64_t
///
/// @param[in] lhs  The first parameter to use in the GCD calculation.
/// @param[in] rhs  The second parameter to use in the GCD calculation.
/// 
/// @return   A pair that indicates results.
///           return.coef contains the solution to 'x' in the expression:
///
///              ax + by = gcd(a,b)
///
///           return.denom contains the gcd(a,b). 
///           A value of 1 indicates they are coprime.
/// 
std::pair<int, int> gcd_ex(int lhs, int rhs);
std::pair<int64_t, int64_t> gcd_ex(int64_t lhs, int64_t rhs);

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

} // namespace detail
} // namespace Bi

#endif
