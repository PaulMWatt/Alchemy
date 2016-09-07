/// @file Bi/detail/Z_operators.h
/// 
/// Integer-based number theory operations.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_Z_OPERATORS_H_INCLUDED
#define BI_Z_OPERATORS_H_INCLUDED

#include <Bi/Z.h>

namespace Bi
{

//  Integer Z Operators ********************************************************
//  ****************************************************************************
inline
Z operator+(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val += rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator+(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val += rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator-(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val -= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator-(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val -= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator*(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val *= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator*(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val *= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator/(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val /= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator/(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val /= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator%(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val %= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator%(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val %= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator&(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val &= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator&(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val &= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator|(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val |= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator|(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val |= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator^(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val ^= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator^(const Z& lhs, int rhs)
{
  Z ret_val(lhs);
  ret_val ^= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator<<(const Z& lhs, uint64_t offset)
{
  Z ret_val(lhs);
  ret_val <<= offset;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator>>(const Z& lhs, uint64_t offset)
{
  Z ret_val(lhs);
  ret_val >>= offset;

  return ret_val;
}

} // namespace Bi


#endif

