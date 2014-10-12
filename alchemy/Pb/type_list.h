/// @file meta/type_list.h
/// 
/// Defines the TypeList construct.
/// 
/// The TypeList can be used to hold a collection of ordered types.
/// The template declaration syntax more closely resembles an array. 
/// However, it is still a Typelist.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TYPE_LIST_H_INCLUDED
#define TYPE_LIST_H_INCLUDED
// Includes *******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/type_node.h>
#include <Pb/meta_macros.h>

namespace Hg
{

// ****************************************************************************
/// A template-type list that is composed from a collection of types.
/// 
/// A TypeList contains a collection of types that can be referenced
/// programmatically by their position in the container.
/// 
/// ~~~{.cpp}
/// template  < typename T0, typename T1, typename T2, typename T3, 
///             typename T4, typename T5, typename T6, typename T7, 
///             typename T8, typename T9, typename T10,typename T11,
///             typename T12,typename T13,typename T14,typename T15,
///             typename T16,typename T17,typename T18,typename T19,
///             typename T20,typename T21,typename T22,typename T23,
///             typename T24,typename T25,typename T26,typename T27,
///             typename T28,typename T29,typename T30,typename T31
///           >
/// struct TypeList
///   : container_trait
/// {  
///   typedef TypeNode<T1, 
///           TypeNode<T2, 
///           TypeNode<T3, 
///           TypeNode<T4, 
///           TypeNode<T5, 
///           TypeNode<T6, 
///           TypeNode<T7, 
///           TypeNode<T8, 
///           TypeNode<T9, 
///           TypeNode<T10,
///           TypeNode<T11,
///           TypeNode<T12,
///           TypeNode<T13, 
///           TypeNode<T14, 
///           TypeNode<T15,  
///           TypeNode<T16,  
///           TypeNode<T17,  
///           TypeNode<T18,  
///           TypeNode<T19,  
///           TypeNode<T20,  
///           TypeNode<T21,  
///           TypeNode<T22,  
///           TypeNode<T23,  
///           TypeNode<T24,  
///           TypeNode<T25,  
///           TypeNode<T26,  
///           TypeNode<T27,  
///           TypeNode<T28,  
///           TypeNode<T29,  
///           TypeNode<T30,  
///           TypeNode<T31, 
///           TypeNode<T32, MT> 
///         > > > > > > > > > > > > > > > 
///         > > > > > > > > > > > > > > > >                type;
/// };
/// ~~~
/// 
template <typename T0,       typename T1 = MT,  typename T2 = MT,  typename T3 = MT,
  	      typename T4 = MT,  typename T5 = MT,  typename T6 = MT,  typename T7 = MT,
	        typename T8 = MT,  typename T9 = MT,  typename T10 = MT, typename T11 = MT,
	        typename T12 = MT, typename T13 = MT, typename T14 = MT, typename T15 = MT,
	        typename T16 = MT, typename T17 = MT, typename T18 = MT, typename T19 = MT,
	        typename T20 = MT, typename T21 = MT, typename T22 = MT, typename T23 = MT,
	        typename T24 = MT, typename T25 = MT, typename T26 = MT, typename T27 = MT,
	        typename T28 = MT, typename T29 = MT, typename T30 = MT, typename T31 = MT
>
struct TypeList
  : container_trait
{
	// This typedef and MACRO declaration results in the definition
	// listed in the comments for this type.

	// This typedef and MACRO declaration results in the definition
	// listed in the comments for this type.
	// The DECLARE_TYPE_LIST MACRO us an indirection because the generated
	// code contains a comma.
#define DECLARE_TYPE_LIST  TMP_ARRAY_32(TypeNode<T), MT TMP_REPEAT_32(>)
	typedef DECLARE_TYPE_LIST  type;
};

//  ***************************************************************************
/// Defines each Specialization TypeList object.
/// 
/// This macro will generate a set of code for type definitions that looks like 
/// the following, where 3 has been used for the input I.
///           
/// ~~~{.cpp}
/// tmp_ALCHEMY_TYPELIST_DEF(3);
/// 
/// template< typename T0,  typename T1,  typename T2> 
/// struct TypeList< T0,  T1,  T2>
///   : container_trait
/// { 
///   typedef TypeNode<T1, 
///           TypeNode<T2, 
///           TypeNode<T3, MT> 
///         > >                                            type;
/// };
/// ~~~
///
#define tmp_ALCHEMY_TYPELIST_DEF(S)                                           \
template <TMP_ARRAY_##S(typename T)>                                          \
struct TypeList<TMP_ARRAY_##S(T)>                                             \
  : container_trait                                                           \
{                                                                             \
typedef TMP_ARRAY_##S(TypeNode<T), MT TMP_REPEAT_##S(>)  type;             \
}

// Define specializations of this array from 1 to 31 elements *****************
tmp_ALCHEMY_TYPELIST_DEF(1);
tmp_ALCHEMY_TYPELIST_DEF(2);
tmp_ALCHEMY_TYPELIST_DEF(3);
tmp_ALCHEMY_TYPELIST_DEF(4);
tmp_ALCHEMY_TYPELIST_DEF(5);
tmp_ALCHEMY_TYPELIST_DEF(6);
tmp_ALCHEMY_TYPELIST_DEF(7);
tmp_ALCHEMY_TYPELIST_DEF(8);
tmp_ALCHEMY_TYPELIST_DEF(9);
tmp_ALCHEMY_TYPELIST_DEF(10);
tmp_ALCHEMY_TYPELIST_DEF(11);
tmp_ALCHEMY_TYPELIST_DEF(12);
tmp_ALCHEMY_TYPELIST_DEF(13);
tmp_ALCHEMY_TYPELIST_DEF(14);
tmp_ALCHEMY_TYPELIST_DEF(15);
tmp_ALCHEMY_TYPELIST_DEF(16);
tmp_ALCHEMY_TYPELIST_DEF(17);
tmp_ALCHEMY_TYPELIST_DEF(18);
tmp_ALCHEMY_TYPELIST_DEF(19);
tmp_ALCHEMY_TYPELIST_DEF(20);
tmp_ALCHEMY_TYPELIST_DEF(21);
tmp_ALCHEMY_TYPELIST_DEF(22);
tmp_ALCHEMY_TYPELIST_DEF(23);
tmp_ALCHEMY_TYPELIST_DEF(24);
tmp_ALCHEMY_TYPELIST_DEF(25);
tmp_ALCHEMY_TYPELIST_DEF(26);
tmp_ALCHEMY_TYPELIST_DEF(27);
tmp_ALCHEMY_TYPELIST_DEF(28);
tmp_ALCHEMY_TYPELIST_DEF(29);
tmp_ALCHEMY_TYPELIST_DEF(30);
tmp_ALCHEMY_TYPELIST_DEF(31);

#undef tmp_ALCHEMY_TYPELIST_DEF

} // namespace Hg



#endif
