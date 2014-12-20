/// @file Pb/detail/auto.h
/// Tests for compiler support of the auto keyword.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// auto is supported in these compilers:

#if _MSC_VER >= 1600 

# define    ALCHEMY_AUTO_SUPPORTED    1 

// Test for GCC > 4.4.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  4 || \
                        (__GNUC_MINOR__ == 4 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_AUTO_SUPPORTED    1    

#else 
  // Compiler does not support rvalue references
//# define    ALCHEMY_AUTO_SUPPORTED    0
#endif


#endif 
