/// @file meta/type_list/length.h
/// 
/// Defines a construct that reports the number of types in a **type_container**.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TYPE_LIST_LENGTH_H_INCLUDED
#define TYPE_LIST_LENGTH_H_INCLUDED
//  Includes ******************************************************************
#include <meta/type_list.h>

namespace Hg
{

//  ***************************************************************************
/// Calculate the number of elements in the specified type container.
/// One definition is required for every specialization of the list.
/// The list currently supports 32 index entries. The hand written
/// version of this function for the list is 500 lines longs.
/// Therefore, the following MACRO will be used to create the
/// required definitions:
///           
///         tmp_TYPE_LIST_LENGTH(...)
/// 
///         More details further below.
///

#define tmp_TYPE_LIST_LENGTH(I)                                               \
template <TMP_ARRAY_##I(typename T)>                                          \
struct length<TypeList<TMP_ARRAY_##I(T)> >                                    \
  : std::integral_constant<size_t, (I)>                                       \
{ }

// MACRO Declarations for each ENTRY that is supported for the TypeList size 
  //template <typename T0>
  //struct length<TypeList<T0> >
  //  : std::integral_constant<size_t, (1)>
  //{ };

  
tmp_TYPE_LIST_LENGTH(1);
tmp_TYPE_LIST_LENGTH(2);
tmp_TYPE_LIST_LENGTH(3);
tmp_TYPE_LIST_LENGTH(4);
tmp_TYPE_LIST_LENGTH(5);
tmp_TYPE_LIST_LENGTH(6);
tmp_TYPE_LIST_LENGTH(7);
tmp_TYPE_LIST_LENGTH(8);
tmp_TYPE_LIST_LENGTH(9);
tmp_TYPE_LIST_LENGTH(10);
tmp_TYPE_LIST_LENGTH(11);
tmp_TYPE_LIST_LENGTH(12);
tmp_TYPE_LIST_LENGTH(13);
tmp_TYPE_LIST_LENGTH(14);
tmp_TYPE_LIST_LENGTH(15);
tmp_TYPE_LIST_LENGTH(16);
tmp_TYPE_LIST_LENGTH(17);
tmp_TYPE_LIST_LENGTH(18);
tmp_TYPE_LIST_LENGTH(19);
tmp_TYPE_LIST_LENGTH(20);
tmp_TYPE_LIST_LENGTH(21);
tmp_TYPE_LIST_LENGTH(22);
tmp_TYPE_LIST_LENGTH(23);
tmp_TYPE_LIST_LENGTH(24);
tmp_TYPE_LIST_LENGTH(25);
tmp_TYPE_LIST_LENGTH(26);
tmp_TYPE_LIST_LENGTH(27);
tmp_TYPE_LIST_LENGTH(28);
tmp_TYPE_LIST_LENGTH(29);
tmp_TYPE_LIST_LENGTH(30);
tmp_TYPE_LIST_LENGTH(31);
tmp_TYPE_LIST_LENGTH(32);

// Undefining the declaration MACRO to prevent its further use. ***************
#undef tmp_TYPE_LIST_LENGTH

} // namespace Hg

#endif
