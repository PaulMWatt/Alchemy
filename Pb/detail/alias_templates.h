/// @file Pb/detail/alias_templates.h
/// Compiler version tests that indicate if alias templates are supported.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef ALIAS_TEMPLATES_H_INCLUDED
#define ALIAS_TEMPLATES_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// template aliases are supported in these compilers:

#if _MSC_VER >= 1800 

# define    ALCHEMY_ALIAS_TEMPLATES_SUPPORTED    1 

// Test for GCC > 4.7.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  7 || \
                        (__GNUC_MINOR__ == 7 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_ALIAS_TEMPLATES_SUPPORTED    1    

#else 
  // Compiler does not support template aliases
//# define    ALCHEMY_ALIAS_TEMPLATES_SUPPORTED    0
#endif


#endif 
