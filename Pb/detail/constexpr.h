/// @file Pb/detail/constexpr.h
/// Tests for compiler support of the constexpr keyword.
///
/// The MIT License(MIT)
/// @copyright 2017 Paul M Watt
//  ****************************************************************************
#ifndef CONSTEXPR_H_INCLUDED
#define CONSTEXPR_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// constexpr is supported in these compilers:

#if _MSC_VER >= 1900 

# define    ALCHEMY_CONSTEXPR_SUPPORTED    1 

// Test for GCC > 4.3.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  6 || \
                        (__GNUC_MINOR__ == 6 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_CONSTEXPR_SUPPORTED    1    

#else 
  // Compiler does not support constexpr
//# define    ALCHEMY_CONSTEXPR_SUPPORTED    0
#endif


#endif 
