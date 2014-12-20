/// @file Pb/detail/decltype.h
/// Tests for compiler support of the decltype keyword.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DECLTYPE_H_INCLUDED
#define DECLTYPE_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// decltype is supported in these compilers:

#if _MSC_VER >= 1600 

# define    ALCHEMY_DECLTYPE_SUPPORTED    1 

// Test for GCC > 4.3.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  3 || \
                        (__GNUC_MINOR__ == 3 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_DECLTYPE_SUPPORTED    1    

#else 
  // Compiler does not support rvalue references
//# define    ALCHEMY_DECLTYPE_SUPPORTED    0
#endif


#endif 
