#pragma once

#include <utility>
#include <string>
#include <vector>

typedef std::pair<uint64_t, uint64_t>   ElGamal_cipher;


//  ***************************************************************************
struct Pt
{
  int64_t x;
  int64_t y;
};

//  ***************************************************************************
inline
Pt make_pt(int64_t in_x, int64_t in_y)
{
  Pt result;
  result.x = in_x;
  result.y = in_y;

  return result;
}


//  ***************************************************************************
uint64_t shanks_algorithm(uint64_t  n,
                          uint64_t  alpha,
                          uint64_t  beta);

//  ***************************************************************************
std::string decrypt_ElGamal(const std::vector<ElGamal_cipher>& ciphertext,
                            uint64_t a,
                            uint64_t p);



//  ***************************************************************************
std::vector<Pt> points_on_elliptic_curve( int64_t a,
                                          int64_t b,
                                          int64_t p);

//  ***************************************************************************
Pt inverse_pt_over_Z(const Pt& rhs, int64_t p);

//  ***************************************************************************
Pt add_pt_over_Z(const Pt&     lhs,
                 const Pt&     rhs,
                       int64_t a,
                       int64_t b,
                       int64_t p);
