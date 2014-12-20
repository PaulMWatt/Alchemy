/// @file Pb/detail/variadic_templates.h
/// Compiler version tests that indicate if variadic templates are supported.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef VARIADIC_TEMPLATES_H_INCLUDED
#define VARIADIC_TEMPLATES_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// Variadic template are supported in these compilers:

#if _MSC_VER >= 1800 

# define    ALCHEMY_VARIADIC_TEMPLATES_SUPPORTED    1 

// Test for GCC > 4.7.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  4 || \
                        (__GNUC_MINOR__ == 4 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_VARIADIC_TEMPLATES_SUPPORTED    1    

#else 
  // Compiler does not support template aliases
//# define    ALCHEMY_VARIADIC_TEMPLATES_SUPPORTED    0
#endif


#endif 
