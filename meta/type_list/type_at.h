/// @file meta/type_list/type_at.h
/// 
/// Provides utility functions for use with type_containers.
/// 
/// This file provides these utility access functions for use with the
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
///     TypeList with the new element added to the front of the list.
///     
/// - **back**
///     Returns the type for the element at the end of the **TypeList**.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TYPE_LIST_TYPE_AT_H_INCLUDED
#define TYPE_LIST_TYPE_AT_H_INCLUDED
//  Includes ******************************************************************
#include <meta/type_list.h>

namespace Hg
{
//  ****************************************************************************
/// Defines each type index lookup.
/// 
/// This macro will generate a set of code for type definitions that looks like 
/// this, where 3 has been used for the input I.
///           
/// Generated Output:
/// ~~~{.cpp}
/// tmp_ALCHEMY_TYPELIST_AT(3);
/// 
/// template <typename 
///             TypeList < typename T0,  typename T1,  typename T2,  typename T3, 
///                        typename T4,  typename T5,  typename T6,  typename T7, 
///                        typename T8,  typename T9,  typename T10, typename T11, 
///                        typename T12, typename T13, typename T14, typename T15, 
///                        typename T16, typename T17, typename T18, typename T19, 
///                        typename T20, typename T21, typename T22, typename T23, 
///                        typename T24, typename T25, typename T26, typename T27, 
///                        typename T28, typename T29, typename T30, typename T31>, 
///           typename ErrorT = error::Undefined_Type> 
/// struct TypeAt<(3), TypeList < T0,  T1,  T2,  T3,  T4,  T5,  T6,  T7, 
///                               T8,  T9,  T10, T11, T12, T13, T14, T15, 
///                               T16, T17, T18, T19, T20, T21, T22, T23, 
///                               T24, T25, T26, T27, T28, T29, T30, T31>
///                             > 
/// { 
///   typedef T3 type; 
/// };
/// ~~~
///
/// @note           
/// This is a locally defined MACRO. After the list of entries have been defined 
/// to generate the required function calls, the MACRO will be undefined.
/// 
#define tmp_ALCHEMY_TYPELIST_AT(I)                                            \
template <TMP_ARRAY_32(typename T),                                           \
          typename ErrorT>                                                    \
struct TypeAt<(I),                                                            \
              TypeList<TMP_ARRAY_32(T)>,                                      \
              ErrorT                                                          \
             >                                                                \
{                                                                             \
  typedef TypeList <TMP_ARRAY_32(T)>  container;                              \
  typedef T##I                        type;                                   \
}

//  ****************************************************************************
//  MACRO Declarations for each ENTRY that is supported for the TypeList size 
tmp_ALCHEMY_TYPELIST_AT(0);
tmp_ALCHEMY_TYPELIST_AT(1);
tmp_ALCHEMY_TYPELIST_AT(2);
tmp_ALCHEMY_TYPELIST_AT(3);
tmp_ALCHEMY_TYPELIST_AT(4);
tmp_ALCHEMY_TYPELIST_AT(5);
tmp_ALCHEMY_TYPELIST_AT(6);
tmp_ALCHEMY_TYPELIST_AT(7);
tmp_ALCHEMY_TYPELIST_AT(8);
tmp_ALCHEMY_TYPELIST_AT(9);
tmp_ALCHEMY_TYPELIST_AT(10);
tmp_ALCHEMY_TYPELIST_AT(11);
tmp_ALCHEMY_TYPELIST_AT(12);
tmp_ALCHEMY_TYPELIST_AT(13);
tmp_ALCHEMY_TYPELIST_AT(14);
tmp_ALCHEMY_TYPELIST_AT(15);
tmp_ALCHEMY_TYPELIST_AT(16);
tmp_ALCHEMY_TYPELIST_AT(17);
tmp_ALCHEMY_TYPELIST_AT(18);
tmp_ALCHEMY_TYPELIST_AT(19);
tmp_ALCHEMY_TYPELIST_AT(20);
tmp_ALCHEMY_TYPELIST_AT(21);
tmp_ALCHEMY_TYPELIST_AT(22);
tmp_ALCHEMY_TYPELIST_AT(23);
tmp_ALCHEMY_TYPELIST_AT(24);
tmp_ALCHEMY_TYPELIST_AT(25);
tmp_ALCHEMY_TYPELIST_AT(26);
tmp_ALCHEMY_TYPELIST_AT(27);
tmp_ALCHEMY_TYPELIST_AT(28);
tmp_ALCHEMY_TYPELIST_AT(29);
tmp_ALCHEMY_TYPELIST_AT(30);
tmp_ALCHEMY_TYPELIST_AT(31);

//  Undefining the declaration MACRO to prevent its further use. ***************
#undef tmp_ALCHEMY_TYPELIST_AT

//  ****************************************************************************
/// This allows the first type of the list to be returned.
/// 
template<TMP_ARRAY_32(typename T)>
struct front<TypeList<TMP_ARRAY_32(T)> >
{
  typedef T0 type;            ///< Type of the first element in the list
};


//  ****************************************************************************
/// This allows the first type of the list to be removed, and
/// the remainder of the list will become the type typedef.
/// 
template<typename TPop, TMP_ARRAY_31(typename T)>
struct pop_front<TypeList<TPop, TMP_ARRAY_31(T)> >
{
  typedef TypeList<TMP_ARRAY_31(T)> type;
};

template<TMP_ARRAY_31(typename T)>
struct pop_front<TypeList<MT, TMP_ARRAY_31(T)> >
{
  typedef MT type;
};

//  ****************************************************************************
/// This allows the a new type to be pushed at the front of the list.
/// The new list will become the typedef of the pushed type and
/// the existing type list.
/// 
template<TMP_ARRAY_32(typename T), typename T>
struct push_front<TypeList<TMP_ARRAY_32(T)>, T>
{
  typedef TypeList<T, TMP_ARRAY_31(T)> type;
};

//  ****************************************************************************
/// This allows the last type of the list to be returned.
/// 
template<TMP_ARRAY_32(typename T)>
struct back<TypeList<TMP_ARRAY_32(T)> >
{
  typedef TypeList<TMP_ARRAY_32(T)>                       container;
  typedef TypeAt<length<container>::value-1, container>    type;
};

} // namespace Hg

#endif
