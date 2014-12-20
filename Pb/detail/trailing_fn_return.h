/// @file Pb/detail/trailing_fn_return.h
/// Tests for compiler support of trailing function return declarations.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TRAILING_FN_RETURN_H_INCLUDED
#define TRAILING_FN_RETURN_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// Trailing function returns are supported in these compilers:

#if _MSC_VER >= 1600 

# define    ALCHEMY_TRAILING_FN_RETURN_SUPPORTED    1 

// Test for GCC > 4.4.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  4 || \
                        (__GNUC_MINOR__ == 4 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_TRAILING_FN_RETURN_SUPPORTED    1    

#else 
  // Compiler does not support trailing function return definitions.
//# define    ALCHEMY_TRAILING_FN_RETURN_SUPPORTED    0
#endif


#endif 
