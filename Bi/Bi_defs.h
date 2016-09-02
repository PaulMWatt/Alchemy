/// @file Bi_defs.h
/// 
/// Common definitions used throughout Bismuth, big-integer library.
/// 
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_DEFS_H_INCLUDED
#define BI_DEFS_H_INCLUDED
//  Includes *******************************************************************
#include <vector>
#include <utility>

namespace Bi
{
  
  //  ****************************************************************************
  /// Represents the relative relationship of two integers in both sign and magnitude.
  ///
  enum Z_relation
  {
    k_cmp_less_sign_diff    = -4,
    k_cmp_less_sign_same    = -3,
    k_cmp_less              = -2,
    k_cmp_less_or_equal     = -1,
    k_cmp_equal             =  0,
    k_cmp_greater_or_equal  =  1,
    k_cmp_greater           =  2,
    k_cmp_greater_sign_same =  3,
    k_cmp_greater_sign_diff =  4,
  };


  //  ****************************************************************************
  template <typename T>
  struct OpPositive
  {
    bool adjust_sign(bool param)
    {
      return param;
    }

    void adjust_sign(T& param)
    { }
  };

  //  ****************************************************************************
  template <typename T>
  struct OpNegative
  {
    bool adjust_sign(bool param)
    {
      return !param;
    }

    void adjust_sign(T& param)
    {
      param = -param;
    }
  };


} // namespace Bi


#endif
