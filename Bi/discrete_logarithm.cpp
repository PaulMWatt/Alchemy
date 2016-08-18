#include "stdafx.h"
#include "discrete_logarithm.h"
#include "gcd.h"

#include <map>
#include <iostream>
#include <algorithm>


//  Forware Declarations ******************************************************
uint64_t square_and_multiply(uint64_t x, uint64_t c, uint64_t n);
void decode_seq(const uint16_t value, char(&seq)[4]);



//  ***************************************************************************
uint64_t shanks_algorithm(uint64_t  n, 
                          uint64_t  alpha,
                          uint64_t  beta)
{
  std::map<uint64_t, uint32_t>   L1;
  std::map<uint64_t, uint32_t>   L2;

  uint32_t m    = std::ceil(std::sqrt(n));
  uint64_t base = square_and_multiply(alpha, m, n);

  // Precalculate all of the products a^1, a^2, ... a^m-1
  // The items will also be sorted as they are added to the map.
  int inverse = multiplicative_inverse(alpha, n);

  for (uint32_t i = 0; i < m; ++i)
  {
    L1[square_and_multiply(base, i, n)] = i;
    
    uint64_t a = square_and_multiply(inverse, i, n);
    L2[(beta * a) % n] = i;
  }

  // Search for the collision.
  std::map<uint64_t, uint32_t>::iterator big_step     = L1.begin();
  std::map<uint64_t, uint32_t>::iterator little_step  = L2.begin();
  while (big_step != L1.end()
      && little_step != L2.end())
  {
    if (big_step->first == little_step->first)
    {
      // This is the match.
      uint64_t result = (m * big_step->second + little_step->second) % n;

      uint64_t verify = square_and_multiply(alpha, result, n);

      return result;
    }

    // Only increment the iterator that has the lower value.
    if (big_step->first < little_step->first)
      big_step++;
    else
      little_step++;
  }

  return 0;
}


//  ***************************************************************************
std::string decrypt_ElGamal(const std::vector<ElGamal_cipher>& ciphertext,
                            uint64_t a, 
                            uint64_t p)
{
  // A block consists of 3 characters from the message.
  const size_t  k_blocks = ciphertext.size();

  std::string plaintext;

  std::cout << "Text <- decode<-cipher\n"
    << "----    ------  ------\n";

  // Decrypt the text, one block at a time.
  for (size_t index = 0; index < k_blocks; ++index)
  {
    uint64_t exp      = square_and_multiply(ciphertext[index].first, a, p);
    int      inverse  = multiplicative_inverse(exp, p);
    uint64_t value    = (ciphertext[index].second * inverse) % p;

    char              seq[4] = {0};
    decode_seq(static_cast<uint16_t>(value), seq);

    plaintext.append(seq);

    std::cout << seq << "\t" << value << "\t(" << ciphertext[index].first << ", " << ciphertext[index].second << ")\n";
  }

  std::cout << "\n";

  return plaintext;
}




////  ***************************************************************************
//std::vector<Pt> points_on_elliptic_curve( int64_t a,
//                                          int64_t b,
//                                          int64_t p)
//{
//  std::vector<Pt> pts;
//
//  // Calculate the test and root exponents.
//  uint64_t test_exp = (p-1)/2;
//  uint64_t root_exp = (p+1)/4;
//
//  std::cout << "  Test exponent: " << test_exp << "\n";
//  std::cout << "  Root exponent: " << root_exp << "\n\n";
//
//  // Test each number from 0 to p-1 for quadratic residue over Z_p.
//  // If the result is 1, then add this entry as a point on the curve.
//  for (uint64_t x = 0; x < p; ++x)
//  {
//    // Quadratic residue test:
//    uint64_t is_residue = square_and_multiply(x, test_exp, p);
//
//    std::cout << "\t[" << x << "] r{" << is_residue << "}:\t";
//
//    if (1 == is_residue)
//    {
//      // Evaluate x for the polynomial:
//      uint64_t x_3          = square_and_multiply(x, 3, p);
//      uint64_t ax_1_plus_b  = a * x + b;
//      uint64_t z            = (x_3 + ax_1_plus_b) % p;
//
//      // Calculate the roots:
//      Pt point;
//      point.x = square_and_multiply(z, root_exp, p);
//      point.y = (-point.x + p) % p;
//
//      std::cout << "z=" << z << ", y=" << point.x << ", -y=" << point.y;
//
//      pts.emplace_back(point);
//    }
//
//    std::cout << "\n";
//  }
//
//  return pts;
//}


//  ***************************************************************************
std::vector<Pt> points_on_elliptic_curve(int64_t a,
                                         int64_t b,
                                         int64_t p)
{
  std::vector<Pt> pts;

  // Calculate the test and root exponents.
  uint64_t test_exp = (p - 1) / 2;
  uint64_t root_exp = (p + 1) / 4;

  std::cout << "  Test exponent: " << test_exp << "\n";
  std::cout << "  Root exponent: " << root_exp << "\n\n";

  // Calculate the set of quadratic residue.
  std::vector<uint64_t> residue;
  for (uint64_t x = 0; x < p; ++x)
  {
    uint64_t res = square_and_multiply(x, test_exp, p);
    if (1 == res)
      residue.push_back(x);
  }
  
  // Print the set of quadratic residue.
  std::cout << "Quadratic Residue {";
  for (size_t i = 0; i < residue.size(); ++i)
  {
    if (0 != i)
      std::cout << ", ";

    std::cout << residue[i];
  }
  std::cout << "}\n\n";

  // Test each number from 0 to p-1 for quadratic residue over Z_p.
  // If the result is 1, then add this entry as a point on the curve.
  for (uint64_t x = 0; x < p; ++x)
  {
    // Evaluate x for the polynomial:
    uint64_t x_3 = square_and_multiply(x, 3, p);
    uint64_t ax_1_plus_b = a * x + b;
    uint64_t z = (x_3 + ax_1_plus_b) % p;

    // Quadratic residue test:
    bool has_residue = std::find(residue.begin(), residue.end(), z) != residue.end();

    std::cout << "\t[" << x << "] z=" << z << ", ";

    if (1 == has_residue)
    {
      // Calculate the roots:
      Pt point;
      point.x = square_and_multiply(z, root_exp, p);
      point.y = (-point.x + p) % p;

      std::cout << "y=" << point.x << ", -y=" << point.y;

      pts.emplace_back(point);
    }

    std::cout << "\n";
  }

  return pts;
}

//  ***************************************************************************
Pt add_other_pt_over_Z(const Pt& lhs, const Pt& rhs, int64_t p)
{
  Pt result;

  int64_t lambda_num = rhs.y - lhs.y;
  int64_t lambda_den = multiplicative_inverse(rhs.x - lhs.x, p); 

  int64_t lambda  = (lambda_num * lambda_den) % p;

  if (lambda < 0)
    lambda = (lambda + p) % p;

  result.x  = square_and_multiply(lambda, 2ull, p);
  result.x  = (result.x - lhs.x - rhs.x + p) % p;

  result.y  = (lhs.x - result.x + p) % p;
  result.y  = (lambda * result.y - lhs.y + p) % p;

  return result;
}

//  ***************************************************************************
Pt add_pt_to_self_over_Z(const  Pt&     rhs, 
                                int64_t a,
                                int64_t p)
{
  Pt result;

  int64_t lambda_num= square_and_multiply(rhs.x, 2ull, p);
  lambda_num        = (3 * lambda_num + a + p) % p; 

  int64_t lambda_den= multiplicative_inverse(rhs.y + rhs.y, p);

  int64_t lambda = (lambda_num * lambda_den) % p;

  if (lambda < 0)
    lambda = (lambda + p) % p;

  result.x = square_and_multiply(lambda, 2ull, p);
  result.x = (result.x - rhs.x - rhs.x + p) % p;

  result.y = (rhs.x - result.x + p) % p;
  result.y = (lambda * result.y - rhs.y + p) % p;

  return result;
}

//  ***************************************************************************
Pt inverse_pt_over_Z(const Pt& rhs, int64_t p)
{
  return make_pt(rhs.x, p-rhs.y);
}

//  ***************************************************************************
Pt add_pt_over_Z( const Pt&     lhs, 
                  const Pt&     rhs, 
                        int64_t a,
                        int64_t b,
                        int64_t p)
{
  Pt result = {0, 0};

  // There are three valid cases.
  if (lhs.x != rhs.x)
    result = add_other_pt_over_Z(lhs, rhs, p);
  else if (lhs.y == rhs.y)
    result = add_pt_to_self_over_Z(lhs, a, p);
  else if (lhs.y == -rhs.y)
    result = inverse_pt_over_Z(lhs, p);

  return result;
}

//  ***************************************************************************
Pt double_and_add(const Pt& lhs, const Pt& rhs, int64_t p)
{
  Pt result;

  //uint64_t lambda =


  return result;
}




