/// @file Pb/detail/static_assert.h
/// Tests for compiler support for static_assert.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef STATIC_ASSERT_H_INCLUDED
#define STATIC_ASSERT_H_INCLUDED
//  Includes *******************************************************************
#include <utility>
#include <type_traits>

// static assert supported in these compilers:
#if _MSC_VER >= 1600 

# define    ALCHEMY_STATIC_ASSERT_SUPPORTED    1 

// Test for GCC > 4.3.0
#elif  __GNUC__ >  4 || \
      (__GNUC__ == 4 && (__GNUC_MINOR__ >  3 || \
                        (__GNUC_MINOR__ == 3 && \
                         __GNUC_PATCHLEVEL__ > 0)))
#   define  ALCHEMY_STATIC_ASSERT_SUPPORTED    1    

#else 

# define     ALCHEMY_STATIC_ASSERT_SUPPORTED 0

# ifndef static_assert
// The Compiler does not support static assert
// implementing an empty MACRO for now.
#   define static_assert(expr, msg)

# endif

#endif // Static_assert support



#endif 
