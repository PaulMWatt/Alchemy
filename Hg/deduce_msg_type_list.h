/// @file detail/deduce_msg_type_list.h
/// 
/// The declaration and definition of DeduceMsgtype_list.
///           
/// A template meta-function that composes a typelist definition from
/// a specified object that contains a collection of meta-functions that 
/// indicate the type of a parameter at a specified index.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DEDUCE_MSG_TYPE_LIST_H_INCLUDED
#define DEDUCE_MSG_TYPE_LIST_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/meta_util.h>

namespace Hg
{

namespace detail
{


//  ****************************************************************************
//  Invariant: PosT must be < LimitT
//
//  This function builds the typelist starting from the rear.
//
template< typename  T,
          size_t    PosT,
          size_t    LimitT
        >
struct DeduceMsgtype_list_Worker
{ 
  static_assert(PosT < LimitT, "PosT must be less than LimitT");

  using format_type = typename T::format_type;

  using type = 
    push_front_t
    < typename DeduceMsgtype_list_Worker<T,PosT+1, LimitT>::type, 
      Hg::type_at_t<PosT, format_type>
    >;
};

//  ****************************************************************************
template< typename  T,
          size_t    PosT
        >
struct DeduceMsgtype_list_Worker<T, PosT, PosT>
{ 
  using format_type = typename T::format_type;
  using type        = type_list<Hg::type_at_t<PosT, format_type>>;
};

//  ****************************************************************************
/// A convenience meta-function to define the typelist of a message object 
/// that is derived from the specified field-types.
///
/// The constructed type can be accessed through the public alias *type*. 
/// 
/// @tparam T           [typename] The msg type that contains the sub-fields.
/// @param  SizeT       [size_t]   The number of sub-fields to index.
/// 
template< typename  T,
          size_t    SizeT
        >
struct DeduceMsgtype_list
{ 
  using type = typename DeduceMsgtype_list_Worker<T,0, SizeT>::type; 
};

} // namespace detail

} // namespace Hg

#endif
