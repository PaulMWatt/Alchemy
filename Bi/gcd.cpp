/// @file Bi/gcd.h
/// 
/// Greatest Common Denominator related algorithms.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************

#include "discrete_logarithm.h"
#include "gcd.h"
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
/// Calculates the gcd of a and b using the extended euclidean method.
///
/// The first parameter contains the solution to 'x' in the expression:
///
///       ax + by = gcd(a,b)
///
/// The second parameter contains the gcd(a,b)
/// 
value_t extended_gcd(int a, int b)
{
  int x0 = 1;
  int x1 = 0;

  while (b != 0)
  {
    std::div_t result = std::div(a, b);

    int x2 = x0 - (result.quot * x1);

    x0 = x1;
    x1 = x2;

    a = b;
    b = result.rem;
  }

  return {x0, a};
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
value_t solve_gcd_coefficients(int a, int b)
{
  value_t result = extended_gcd(a,b);

  // If the gcd != 1, then there was a common factor
  // and both a and b need to be divided to coprime values.
  if (result.second != 1)
  { 
    a /= result.second;
    b /= result.second;

    // The gcd is now 1.
    result.second = 1;
  }

  int gcd = result.second;
  int x   = result.first;
  int y   = (gcd - a * x) / b;

  // This step ensures that both values are reported 
  // as positive coefficients.
  return {(x+b)%b, (y+a)%a};
}



//  ***************************************************************************
/// Calculates the multiplicative inverse of a mod(n).
///
int multiplicative_inverse(int a, int n)
{
  value_t p = extended_gcd(a, n);

  if (p.second != 1)
    return 0;

  if (p.first < 0)
    return p.first + n;

  return p.first;
}


//  ***************************************************************************
/// Calculates the chinese remainder from two lists of pairwise coprime values.
///
int chinese_remainder(const vector<int> &a, 
                      const vector<int> &m)
{
  if (a.size() != m.size())
    return 0;

  // This value is the product of all of the elements in m.
  int M = 1;
  for (auto i : m)
  {
    M *= i;
  }

  long long     sum = 0;
  const size_t  r   = a.size();

  for (size_t i = 0; i < r; ++i)
  {
    int Mi  = M / m[i];
    int yi  = multiplicative_inverse(Mi, m[i]);

    sum    += a[i] * Mi * yi;
  }

  // The result is the accumulated sum modulo M.
  return sum % M;
}


//  ***************************************************************************
/// Creates a binary reflection of the input.
/// Returns the number of bits used to represent the original number.
///
uint8_t reflect_bits(uint16_t &c)
{
  // Represents the binary reflection value
  // and the number of bits in the original value.
  struct Bit_entry
  {
    uint16_t reflection;
    uint8_t  count;
  };

  static const uint16_t  refl_mask = 0x000F;
  static const Bit_entry reflection_table[16] =
  {
    {0x0,0},{0x8,1},{0x4,2},{0xC,2},{0x2,3},{0xA,3},{0x6,3},{0xE,3},
    {0x1,4},{0x9,4},{0x5,4},{0xD,4},{0x3,4},{0xB,4},{0x7,4},{0xF,4}
  };

  uint32_t reflected = 0;

  // There are four chunks of bits to reflect (16-bits):
  std::pair<uint8_t, uint8_t> last_nibble = {0,0};
  for (int index = 0; index < 4; ++index)
  {
    uint8_t nibble = c & refl_mask;

    reflected = (reflected | reflection_table[nibble].reflection) << 4;

    if (nibble > 0)
    {
      last_nibble.first = index;
      last_nibble.second = nibble;
    }

    c = c >> 4;
  }

  // Lookup table for the number of bits 
  // contained in the previous nibbles.
  static const uint8_t chunk_bits[4] = {0, 4, 8, 12};

  // Determine the bit count and shift the number to the right
  // so the highest order bit is the last bit.
  uint8_t l = chunk_bits[last_nibble.first]
    + reflection_table[last_nibble.second].count;

  c = static_cast<uint16_t>(reflected >> (20 - l));

  return l;
}

//  ***************************************************************************
/// Square and multiply from Stinson
///
uint16_t square_and_multiply(uint16_t x, uint16_t c, uint16_t n)
{
  uint16_t z = 1;

  uint16_t l = reflect_bits(c);
  for (int i = l - 1; i >= 0; --i)
  {
    z = (z*z) % n;

    if (c & 0x00000001)
    {
      z = (z*x) % n;
    }

    // Shift the bits of C to the right to 
    // simplify the process of locating the
    // current binary digit for the algorithm.
    c >>= 1;
  }

  return z;
}

//  ***************************************************************************
uint64_t square_and_multiply(uint64_t x, uint64_t c, uint64_t n)
{
  uint64_t z = 1;

  uint16_t c_ref = static_cast<uint16_t>(c);
  uint64_t l = reflect_bits(c_ref);


  for (int i = l - 1; i >= 0; --i)
  {
    z = (z*z) % n;

    if (c_ref & 0x00000001)
    {
      z = (z*x) % n;
    }

    // Shift the bits of C to the right to 
    // simplify the process of locating the
    // current binary digit for the algorithm.
    c_ref >>= 1;
  }

  return z;
}


//  ***************************************************************************
/// Factors a large composite integer with the Pollard Rho algorithm.
///
int pollard_rho_factorization(int n, uint64_t x)
{
  int coefficient = 1;
  int p           = 1;
  int step        = 0;

  //srand(time(NULL));

  uint64_t base_x = 1;
  p = n;
  //while (p == n)
  //{
    uint64_t x_prime = x;
    p = 1;
    while (1 == p)
    {
      step++;

      x       = (square_and_multiply(x, 2, n)       + coefficient + n) % n;
      x_prime = (square_and_multiply(x_prime, 2, n) + coefficient + n) % n;
      x_prime = (square_and_multiply(x_prime, 2, n) + coefficient + n) % n;

      p = extended_gcd((x - x_prime + n)%n, n).second;
    }

  //  base_x += 2;
  //  x = base_x;
  //}

  cout << "Steps: " << step << "\n";

  return p;
}



//  ***************************************************************************
//int main()
//{
//  value_t result = extended_gcd(240, 46);
//
//  int p5_3_a = multiplicative_inverse(17,   101);
//  cout << "5.3 a) 17^-1 (mod 101):\n\t" << p5_3_a << "\n\n";
//    
//  int p5_3_b = multiplicative_inverse(357,  1234);
//  cout << "5.3 b) 357^-1 (mod 1234):\n\t" << p5_3_b << "\n\n";
//
//  int p5_3_c = multiplicative_inverse(3125, 9987);
//  cout << "5.3 c) 3125^-1 (mod 9987):\n\t" << p5_3_c << "\n\n";
//
//
//  value_t p_5_4 = solve_gcd_coefficients(57, 93); 
//
//  cout  << "The solution to 57x + 93y = gcd(57, 93) is:"
//        << "\n\tx = " << p_5_4.first
//        << "\n\ty = " << p_5_4.second << "\n\n";
//
//
//  int p5_6_1 = multiplicative_inverse(702, 25);
//  cout << "702^-1 (mod 25):\n\t" << p5_6_1 << "\n\n";
//
//  int p5_6_2 = multiplicative_inverse(675, 26);
//  cout << "675^-1 (mod 26):\n\t" << p5_6_2 << "\n\n";
//
//  int p5_6_3 = multiplicative_inverse(650, 27);
//  cout << "650^-1 (mod 27):\n\t" << p5_6_3 << "\n\n";
//
//  int p5_6 = chinese_remainder({12, 9, 23}, {25, 26, 27});
//  cout << p5_6 << " = chinese_remainder(a,m)\n"
//       << "\twhere:\ta = {12, 9, 23}, and m = {25, 26, 27}.\n\n";
//
//  int x = chinese_remainder({2, 3, 1}, {3, 4, 5});
//  cout << x << " = chinese_remainder(a,m)\n\n"
//       << "where:\ta = {2, 3, 1}, and m = {3, 4, 5}.\n\n";
//
//  int x2 = chinese_remainder({2, 3, 2}, {3, 5, 7});
//  cout << x2 << " = chinese_remainder(a,m)\n\n";
//
//
//  RSA_key key = make_RSA_key(139, 173);
//  cout << "RSA.n    = " << key.n    << "\n";
//  cout << "RSA.pub  = " << key.pub  << "\n";
//  cout << "RSA.priv = " << key.priv << "\n\n";
//
//  string            plaintext     = "rsaiseasynow";
//  vector<uint16_t>  ciphertext    = encrypt_RSA(plaintext, key);
//  string            decoded_text  = decrypt_RSA(ciphertext, key);
//
//  cout << "The decoded text is '" << decoded_text << "'\n";
//
//
//  RSA_key key12 = make_RSA_key_ex(173, 181, 4913);
//
//  
//  string            ex512_text = decrypt_RSA(ex_5_12, key12);
//
//  cout << "Factor:   10403      => {" << pollard_rho_factorization(10403,    2) << "\n";
//
//  cout << "Factor:   262063     => " << pollard_rho_factorization(262063,    2) << "\n";
//  cout << "Factor:   9420457    => " << pollard_rho_factorization(9420457,   2) << "\n";
//  cout << "Factor:   181937053  => " << pollard_rho_factorization(181937053, 2) << "\n";
//
//  
//  cout << "Shanks Alg: log3(525) in Z809 is " << shanks_algorithm(809, 3, 525) << "\n";
//
//  cout << "Shanks Alg: log106(12375) in Z24691 is  " << shanks_algorithm(24691, 106, 12375) << "\n";
//  cout << "Shanks Alg: log6(248388)  in Z458009 is " << shanks_algorithm(458009, 6, 248388) << "\n";
//
//  Exercise_6_6();
//
//  string ex6_9_text = decrypt_ElGamal(table_6_3, 7899, 31847);
//
//  cout << "The 6.9 decoded text is:\n\n" << ex6_9_text << "\n";
//
//  cout << "Calculate the points on the elliptic curve:\n"
//    << "  y^2 = x^3 + x + 6    over Z_11\n\n";
//  std::vector<Pt> pts = points_on_elliptic_curve(1, 6, 11);
//
//  Pt p1;
//  Pt p2;
//
//  p1.x = 11;
//  p1.y = 15;
//  Pt inv = inverse_pt_over_Z(p1, 127);
//
//  p1.x = 9;
//  p1.y = 16;
//
//  p2.x = 6;
//  p2.y = 11;
//  Pt sum = add_pt_over_Z(p1, p2, 1, 26, 127);
//
//  p1.x = 4;
//  p1.y = 27;
//  Pt sum2 = add_pt_over_Z(p1, p1, 1, 26, 127);
//
//
//  cout << "Calculate the points on the elliptic curve:\n"
//    << "  y^2 = x^3 + 2x + 7    over Z_31\n\n";
//  points_on_elliptic_curve(2, 7, 31);
//
//  cout << "Calculate the points on the elliptic curve:\n"
//    << "  y^2 = x^3 + x + 28    over Z_71\n\n";
//  std::vector<Pt> pts1 = points_on_elliptic_curve(1, 28, 71);
//
//
//  std::cout << "\n"<<"\n";
//  for (int a = 1; a < 131; ++a)
//  {
//    std::cout << a << "^-1 mod 131 = " << multiplicative_inverse(a, 131) << "\n";
//  }
//
//
//  uint64_t q = 101;
//  uint64_t p = 7879;
//  uint64_t beta = 4567;
//  uint64_t alpha = 170;
//  uint64_t a = 75;
//
//
//  // Example 7.4
//  //uint64_t k = 50;
//  //uint64_t x_ = 22;
//
//
//  uint64_t k    = 49;
//  uint64_t x_   = 52;
//
//  uint64_t k_inv = multiplicative_inverse(k, q);
//  std::cout << k << "^-1 mod " << q << " = " << k_inv << "\n";
//
//  uint64_t gamma_sub = square_and_multiply(alpha, k, p);
//  std::cout << alpha << "^" << k << " mod " << p << " = " << gamma_sub << "\n";
//
//  uint64_t gamma = gamma_sub % q;
//  std::cout << gamma_sub << " mod " << q << " = " << gamma << "\n";
//
//  uint64_t delta = ((x_ + (a*gamma))*k_inv ) % q;
//  std::cout << "Signature = ( " << gamma << ", " << delta << ")\n";
//
//
//  uint64_t delta_inv = multiplicative_inverse(delta, q);
//  std::cout << delta << "^-1 mod " << q << " = " << delta_inv << "\n";
//
//  uint64_t e1 = (x_ * delta_inv) % q;
//  uint64_t e2 = (gamma * delta_inv) % q;
//  std::cout << "e1 = " << e1 << ", e2 = " << e2 << "\n";
//
//  uint64_t verify_a = square_and_multiply(alpha, e1, p);
//  uint64_t verify_b = square_and_multiply(beta, e2, p);
//  uint64_t verify_c = (verify_a*verify_b)% p;
//
//  uint64_t verify   = verify_c % q;
//
//
//  std::cout << "(" << alpha << "^" << e1 <<  " * " << beta << "^" << e2 << " mod " << p << ") mod " << q << "=>\n";
//  std::cout << "(" << verify_a << " * " << verify_b << " mod " << p << ") mod " << q << "=>\n";
//  std::cout << verify_c << " mod " << q << "=>\n\n";
//  std::cout << "verify = " << verify << "\n";
//
//  return 0;
//}

} // namespace Bi
