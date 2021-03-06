/// @file Pb/detail/rvalue_ref.h
/// Contains compiler version tests that indicate if rvalue references are supported.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef RVALUE_REF_H_INCLUDED
#define RVALUE_REF_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// RValue references are supported in these compilers:
// Visual Studio 2010
#if _MSC_VER >= 1600 

# define    ALCHEMY_RVALUE_REF_SUPPORTED    1 

// Test for GCC > 4.3.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  3 || \
                        (__GNUC_MINOR__ == 3 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_RVALUE_REF_SUPPORTED    1    

#else 
  // Compiler does not support rvalue references
//# define    ALCHEMY_RVALUE_REF_SUPPORTED    0
#endif


#endif 
