/// @file Pb/detail/conditional.h
/// 
/// Provides std::conditional for tr1 implementations that do not support it.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef PB_DETAIL_CONDITIONAL_H_INCLUDED
#define PB_DETAIL_CONDITIONAL_H_INCLUDED

namespace Pb
{

//  ***************************************************************************
/// Provides an implementation of a compile-time conditional when the local
/// library does not support it.
///
template< bool  Predicate, 
          class TrueType, 
          class FalseType
        >
struct conditional
{ 
  using type = TrueType;
};

//  ***************************************************************************
/// Specialization for the false condition of the conditional.
///
template< class TrueType, 
          class FalseType
        >
struct conditional<false, TrueType, FalseType>
{ 
  using type =FalseType;
};

} // namespace Pb

#endif
