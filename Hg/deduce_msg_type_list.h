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
  typedef typename
    push_front
    < typename DeduceMsgtype_list_Worker<T,PosT+1, LimitT>::type, 
      typename Hg::type_at<PosT, typename T::format_type>::type
    >::type                                                     type;
};

//  ****************************************************************************
template< typename  T,
          size_t    PosT
        >
struct DeduceMsgtype_list_Worker<T, PosT, PosT>
{ 
  typedef 
    type_list<typename Hg::type_at<PosT, typename T::format_type>::type>      type;
};

//  ****************************************************************************
/// A convenience meta-function to define the typelist of a message object 
/// that is derived from the specified field-types.
///
/// The constructed type can be accessed through the public typedef *type*. 
/// 
/// @tparam T           [typename] The msg type that contains the sub-fields.
/// @param  SizeT       [size_t]   The number of sub-fields to index.
/// 
template< typename  T,
          size_t    SizeT
        >
struct DeduceMsgtype_list
{ 
  typedef typename
    DeduceMsgtype_list_Worker<T,0, SizeT>::type                  type; 
};

} // namespace detail

} // namespace Hg

#endif
