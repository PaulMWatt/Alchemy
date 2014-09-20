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
  typedef std::integral_constant<int, __LINE__>  enum_base;  

//  ****************************************************************************
#define INC_COUNTER        ADD_ENUM_H(__LINE__ - enum_base::value)

//  ****************************************************************************
#define COUNTER_VALUE      (auto_index<__LINE__- enum_base::value>::value)

//  ****************************************************************************
#define END_ENUM

} // namespace Hg

#endif

