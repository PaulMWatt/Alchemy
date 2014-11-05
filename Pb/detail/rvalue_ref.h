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

//MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
//MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
//MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
//MSVC++ 9.0  _MSC_VER == 1500 (Visual Studio 2008)

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
