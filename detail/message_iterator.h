/// @file message_terator.h
/// 
/// message field iterator utility functions.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MESSAGE_ITERATOR_H_INCLUDED
#define MESSAGE_ITERATOR_H_INCLUDED
//  Includes *******************************************************************
//#include <detail/message_iterator_detail.h>

namespace Hg
{

//  ****************************************************************************
/// Provides access to the field at the beginning of the message.
/// 
//template<>
//struct front<TypeList<TMP_ARRAY_32(T)> >
//{
//  typedef T0 type;            ///< Type of the first element in the list
//};
//
////  ****************************************************************************
///// Specialization for a TypeNode
///// 
//template<typename T1, typename T2>
//struct pop_front< TypeNode<T1, T2> >
//{
//  typedef T2 type;
//};
//
////  ****************************************************************************
///// Specialization for an empty TypeList: results with type T and empty.
///// 
//template<typename T>
//struct push_front<empty, T>
//{
//  typedef TypeNode<T, empty> type;
//};
//
////  ****************************************************************************
///// Specialization for a TypeNode: TypeList
///// 
//template<typename T1, typename T2, typename T>
//struct push_front< TypeNode<T1, T2>, T>
//{
//  typedef TypeNode< T, TypeNode<T1, T2> > type;
//};

}

} // namespace Hg

#endif

