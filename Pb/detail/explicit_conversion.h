/// @file Pb/detail/explicit_conversion.h
/// Tests for compiler support of the explicit conversion operator support.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef EXPLICIT_CONVERSION_H_INCLUDED
#define EXPLICIT_CONVERSION_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// Explicit conversion operators are supported in these compilers:

#if _MSC_VER >= 1800 

# define    ALCHEMY_EXPLICIT_CONVERSION_SUPPORTED    1 

// Test for GCC > 4.3.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  5 || \
                        (__GNUC_MINOR__ == 5 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_EXPLICIT_CONVERSION_SUPPORTED    1    

#else 
  // Compiler does not support rvalue references
//# define    ALCHEMY_EXPLICIT_CONVERSION_SUPPORTED    0
#endif


#endif 
