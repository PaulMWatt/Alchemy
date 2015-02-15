/// @file detail/deduce_msg_type_list.h
/// 
/// The declaration and definition of DeduceMsgTypeList.
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
struct DeduceMsgTypeList_Worker
{ 
  typedef typename
    push_front
    < typename DeduceMsgTypeList_Worker<T,PosT+1, LimitT>::type, 
      typename T::template TypeAtIndex<PosT>::type
    >::type                                                     type;
};

//  ****************************************************************************
template< typename  T,
          size_t    PosT
        >
struct DeduceMsgTypeList_Worker<T, PosT, PosT>
{ 
  typedef 
    TypeList<typename T::template TypeAtIndex<PosT>::type>      type;
};

//  ****************************************************************************
/// A convenience meta-function to define the typelist of a message object 
/// that is derived from the specified field-types.
///
/// The constructed type can be accessed through the public typedef *type*. 
/// 
/// @paramt T           [typename] The msg type that contains the sub-fields.
/// @param  SizeT       [size_t]   The number of sub-fields to index.
/// 
template< typename  T,
          size_t    SizeT
        >
struct DeduceMsgTypeList
{ 
  typedef typename
    DeduceMsgTypeList_Worker<T,0, SizeT>::type                  type; 
};

} // namespace detail

} // namespace Hg

#endif
