/// @file Bi/NT.h
/// 
/// Number Theory related algorithms.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************

#include <Bi/discrete_logarithm.h>
#include <Bi/NT.h>
#include <iostream>
#include <numeric>
#include <string>
#include <time.h>

using std::cout;
using std::string;
using std::vector;

namespace Bi
{

//  ***************************************************************************
std::pair<int, int> gcd_ex(int lhs, int rhs)
{
  int x0 = 1;
  int x1 = 0;

  while (rhs != 0)
  {
    div_t result = std::div(lhs, rhs);
    
    int x2 = x0 - (result.quot * x1);

    x0 = x1;
    x1 = x2;

    lhs = rhs;
    rhs = result.rem;
  }

  return {x0, lhs};
}

//  ***************************************************************************
std::pair<int64_t, int64_t> gcd_ex(int64_t lhs, int64_t rhs)
{
  int64_t x0 = 1;
  int64_t x1 = 0;

  while (rhs != 0)
  {
    lldiv_t result = std::lldiv(lhs, rhs);
    
    int64_t x2 = x0 - (result.quot * x1);

    x0 = x1;
    x1 = x2;

    lhs = rhs;
    rhs = result.rem;
  }

  return {x0, lhs};
}


////  ***************************************************************************
///// Factors a large composite integer with the Pollard Rho algorithm.
/////
//int pollard_rho_factorization(int n, uint64_t x)
//{
//  int coefficient = 1;
//  int p           = 1;
//  int step        = 0;
//
//  //srand(time(NULL));
//
//  uint64_t base_x = 1;
//  p = n;
//  //while (p == n)
//  //{
//    uint64_t x_prime = x;
//    p = 1;
//    while (1 == p)
//    {
//      step++;
//
//      x       = (square_and_multiply(x, 2, n)       + coefficient + n) % n;
//      x_prime = (square_and_multiply(x_prime, 2, n) + coefficient + n) % n;
//      x_prime = (square_and_multiply(x_prime, 2, n) + coefficient + n) % n;
//
//      p = gcd_ex((x - x_prime + n)%n, n).second;
//    }
//
//  //  base_x += 2;
//  //  x = base_x;
//  //}
//
//  cout << "Steps: " << step << "\n";
//
//  return p;
//}


} // namespace Bi
