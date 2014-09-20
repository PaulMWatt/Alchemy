/// @file meta/type_at.h
/// 
/// Provides utility functions for use with type_containers.
/// 
/// This file provides these utility access functions for use with the
/// 
/// - **TypeList**
///     This provides a form of reflection upon the data type. Reflection is not
///     a feature provided by C++. **TypeAt** works upon a **TypeList** 
///     definition to query the type of parameter at the specified index.
///
/// - **front**
///     Returns the type for the element at the beginning of the **TypeList**.
///     
/// - **pop_front**
///     Removes the type for the element at the beginning of the 
///     **TypeList**. The TypeList defined in the resulting
///     meta-structure is the original TypeList with the first element removed.
///     
/// - **push_front**
///     Pushes a new type at the beginning of the **TypeList**.
///     The TypeList defined in the resulting meta-structure is the original 
///     TypeList with the new element added to the front of the array.
///     
/// - **back**
///     Returns the type for the element at the end of the **TypeList**.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TYPE_AT_H_INCLUDED
#define TYPE_AT_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/type_list.h>

namespace Hg
{

//  ****************************************************************************
/// Return the type at the specified array index. 
/// 
/// @note   
/// If the type at Index does not exist, a compiler error will occur.
/// 
template <size_t Index,
  typename ContainerT,
  typename ErrorT = error::Undefined_Type>
struct TypeAt;

//  ****************************************************************************
/// The generic form of this template simply returns an error. 
///
template <size_t Index,
          typename ContainerT, 
          typename ErrorT> 
struct TypeAt 
{
  typedef ErrorT    type;
};

//  ****************************************************************************
/// Specialization for an MT Type Container
///
template<>
struct front< MT >
{ 
  typedef MT     type;
};

//  ****************************************************************************
/// Specialization for a TypeNode
/// 
template<typename T1, typename T2>
struct pop_front< TypeNode<T1, T2> >
{
  typedef T2 type;
};

//  ****************************************************************************
/// Specialization for an MT TypeList: results with type T and empty.
/// 
template<typename T>
struct push_front<MT, T>
{
  typedef TypeNode<T, MT> type;
};

//  ****************************************************************************
/// Specialization for a TypeNode: TypeList
/// 
template<typename T1, typename T2, typename T>
struct push_front< TypeNode<T1, T2>, T>
{
  typedef TypeNode< T, TypeNode<T1, T2> > type;
};

//  ****************************************************************************
/// Specialization for an MT TypeList
/// 
template<>
struct back< MT >
{ };


} // namespace Hg

// Include Type Container specific implementations.
#include <Pb/type_list/type_at.h>

#endif
