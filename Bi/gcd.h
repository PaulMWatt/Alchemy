/// @file Bi/gcd.h
/// 
/// Greatest Common Denominator (GCD) algorithms.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_GCD_H_INCLUDED
#define BI_GCD_H_INCLUDED
//  Includes *******************************************************************
#include <Bi/Bi_defs.h>

namespace Bi
{

//  Forward Declarations ******************************************************
class Z;

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

using value_t     = std::pair<int, int>;


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


} // namespace Bi

#endif
