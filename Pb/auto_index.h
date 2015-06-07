/// @file meta/auto_index_MACROS.h
/// 
/// Provides a construct to auto-increment an index at compile-time.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef AUTO_INDEX_H_INCLUDED
#define AUTO_INDEX_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_util.h>

namespace Hg
{

#define HAS_COUNTER
#if defined(HAS_COUNTER)
  
//  ****************************************************************************
//  This version is not portable because it depends upon the __COUNTER__ macro.
//  However, until a more portable implementation for the version above can
//  be implemented, this version is simple, and works for many compilers.
//

//  ****************************************************************************
#define BEGIN_COUNTER         static const size_t k_enum_base = __COUNTER__ + 1;

//  ****************************************************************************
#define INC_COUNTER        

//  ****************************************************************************
#define COUNTER_VALUE         (__COUNTER__ - k_enum_base)

//  ****************************************************************************
#define END_ENUM

#elif defined(_WIN32)

  //  **************************************************************************
  //  It turns out that the way this implementation is integrated with the
  //  Hg objects is not portable because the standard does not allow template
  //  specialization to occur within a class scope.
  //
  //  This version will still be used for WIN32 builds.
  //  The __COUNTER__ MACRO will be used for other compilers that support it.
  //  When a compiler is encountered that does not support either possibility, 
  //  this issue will be revisited.
  //

  //  Forward Declarations *****************************************************
#define FORWARD_DECLARE_AUTO_INDEX                                             \
  template <int L>                                                             \
  struct decrement_until_match;

  //  **************************************************************************
#define ENUM_BEGIN                                                             \
  template<int N>                                                              \
  struct enum_begin                                                            \
    : std::integral_constant<int, N>                                           \
  { };

  //  **************************************************************************
#define ENUM_ENTRY_INVALID                                                     \
  template<int N, bool IsValidT = false>                                       \
  struct enum_entry                                                            \
    : std::integral_constant<bool, IsValidT>                                   \
  { };

  //  **************************************************************************
#define ENUM_ENTRY_VALID                                                       \
  template<int N>                                                              \
  struct enum_entry<N, true>                                                   \
    : std::true_type                                                           \
  {};

  //  **************************************************************************
#define ENUM_ENTRY_ZERO                                                        \
  template<>                                                                   \
  struct enum_entry<0, true>                                                   \
    : std::true_type                                                           \
  {};

  //  **************************************************************************
#define AUTO_INDEX_BEFORE                                                      \
  template <int L>                                                             \
  struct index_before                                                          \
    : std::integral_constant< int,                                             \
                              decrement_until_match<L - 1>::value              \
                            >                                                  \
  { };

  //  **************************************************************************
#define AUTO_INDEX_NEXT                                                        \
  template <int L>                                                             \
  struct auto_index                                                            \
    : std::integral_constant< int, index_before<L>::value + 1 >                \
  { };

  //  **************************************************************************
#define AUTO_INDEX_ZERO                                                        \
  template <>                                                                  \
  struct auto_index<0>                                                         \
    : std::integral_constant< int, -1>                                         \
  { };

  //  **************************************************************************
#define DECREMENT_UNTIL_MATCH                                                  \
  template <int L>                                                             \
  struct decrement_until_match                                                 \
  : std::integral_constant< int,                                               \
                            value_if< enum_entry<L>::value,                    \
                                      int,                                     \
                                      auto_index<L>::value,                    \
                                      decrement_until_match<L - 1>::value      \
                                    >::value                                   \
                          >                                                    \
  { };

  //  **************************************************************************
#define DECREMENT_UNTIL_ZERO                                                   \
  template <>                                                                  \
  struct decrement_until_match<0>                                              \
    : std::integral_constant <int, -1>                                         \
  { };

  //  **************************************************************************
#define ADD_ENUM_H(ID)                                                         \
  template<>                                                                   \
  struct enum_entry<(ID)>                                                      \
    : std::true_type                                                           \
  { };


  //  **************************************************************************
#define BEGIN_COUNTER                                                          \
  FORWARD_DECLARE_AUTO_INDEX                                                   \
  ENUM_BEGIN                                                                   \
  ENUM_ENTRY_INVALID                                                           \
  ENUM_ENTRY_VALID                                                             \
  ENUM_ENTRY_ZERO                                                              \
  AUTO_INDEX_BEFORE                                                            \
  AUTO_INDEX_NEXT                                                              \
  AUTO_INDEX_ZERO                                                              \
  DECREMENT_UNTIL_MATCH                                                        \
  DECREMENT_UNTIL_ZERO                                                         \
  using enum_base = std::integral_constant<int, __LINE__>;  

//  ****************************************************************************
#define INC_COUNTER        ADD_ENUM_H(__LINE__ - enum_base::value)

//  ****************************************************************************
#define COUNTER_VALUE      (auto_index<__LINE__- enum_base::value>::value)

//  ****************************************************************************
#define END_ENUM

#else

#error "An auto-incrementing index is not available for this compiler. Manual index items will be required."

#endif


} // namespace Hg

#endif

