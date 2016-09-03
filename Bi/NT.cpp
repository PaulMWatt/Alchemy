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
///// Creates a binary reflection of the input.
///// Returns the number of bits used to represent the original number.
/////
//uint8_t reflect_bits(uint16_t &c)
//{
//  // Represents the binary reflection value
//  // and the number of bits in the original value.
//  struct Bit_entry
//  {
//    uint16_t reflection;
//    uint8_t  count;
//  };
//
//  static const uint16_t  refl_mask = 0x000F;
//  static const Bit_entry reflection_table[16] =
//  {
//    {0x0,0},{0x8,1},{0x4,2},{0xC,2},{0x2,3},{0xA,3},{0x6,3},{0xE,3},
//    {0x1,4},{0x9,4},{0x5,4},{0xD,4},{0x3,4},{0xB,4},{0x7,4},{0xF,4}
//  };
//
//  uint32_t reflected = 0;
//
//  // There are four chunks of bits to reflect (16-bits):
//  std::pair<uint8_t, uint8_t> last_nibble = {0,0};
//  for (int index = 0; index < 4; ++index)
//  {
//    uint8_t nibble = c & refl_mask;
//
//    reflected = (reflected | reflection_table[nibble].reflection) << 4;
//
//    if (nibble > 0)
//    {
//      last_nibble.first = index;
//      last_nibble.second = nibble;
//    }
//
//    c = c >> 4;
//  }
//
//  // Lookup table for the number of bits 
//  // contained in the previous nibbles.
//  static const uint8_t chunk_bits[4] = {0, 4, 8, 12};
//
//  // Determine the bit count and shift the number to the right
//  // so the highest order bit is the last bit.
//  uint8_t l = chunk_bits[last_nibble.first]
//    + reflection_table[last_nibble.second].count;
//
//  c = static_cast<uint16_t>(reflected >> (20 - l));
//
//  return l;
//}
//
////  ***************************************************************************
///// Square and multiply from Stinson
/////
//uint16_t square_and_multiply(uint16_t x, uint16_t c, uint16_t n)
//{
//  uint16_t z = 1;
//
//  uint16_t l = reflect_bits(c);
//  for (int i = l - 1; i >= 0; --i)
//  {
//    z = (z*z) % n;
//
//    if (c & 0x00000001)
//    {
//      z = (z*x) % n;
//    }
//
//    // Shift the bits of C to the right to 
//    // simplify the process of locating the
//    // current binary digit for the algorithm.
//    c >>= 1;
//  }
//
//  return z;
//}
//
////  ***************************************************************************
//uint64_t square_and_multiply(uint64_t x, uint64_t c, uint64_t n)
//{
//  uint64_t z = 1;
//
//  uint16_t c_ref = static_cast<uint16_t>(c);
//  uint64_t l = reflect_bits(c_ref);
//
//
//  for (int i = l - 1; i >= 0; --i)
//  {
//    z = (z*z) % n;
//
//    if (c_ref & 0x00000001)
//    {
//      z = (z*x) % n;
//    }
//
//    // Shift the bits of C to the right to 
//    // simplify the process of locating the
//    // current binary digit for the algorithm.
//    c_ref >>= 1;
//  }
//
//  return z;
//}
//
//
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
