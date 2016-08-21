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

namespace Bi
{
  enum Z_relation
  {
    k_cmp_less_sign_diff    = -3,
    k_cmp_less_sign_same    = -2,
    k_cmp_less              = -1,
    k_cmp_equal             =  0,
    k_cmp_greater           =  1,
    k_cmp_greater_sign_same =  2,
    k_cmp_greater_sign_diff =  3,
  };


  //  ****************************************************************************
  template <typename T>
  struct OpNull
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
  struct OpNegate
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
