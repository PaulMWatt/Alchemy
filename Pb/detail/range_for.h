/// @file Pb/detail/range_for.h
/// Contains compiler version tests that indicate if range-based for loops are supported.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef RANGE_FOR_H_INCLUDED
#define RANGE_FOR_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// Range-based for loops are supported in these compilers:

#if _MSC_VER >= 1700 

# define    ALCHEMY_RANGE_FOR_SUPPORTED    1 

// Test for GCC > 4.6.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  6 || \
                        (__GNUC_MINOR__ == 6 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_RANGE_FOR_SUPPORTED    1    

#else 
  // Compiler does not support rvalue references
//# define    ALCHEMY_RANGE_FOR_SUPPORTED    0
#endif


#endif 
