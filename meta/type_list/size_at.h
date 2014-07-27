/// @file meta/type_list/size_at.h
/// 
/// Calculates the size in bytes of the type at the specified index in the 
/// type Container.
/// 
/// This construct depends on the SizeOf meta processing construct.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef SIZE_AT_H_INCLUDED
# error "Do not include this file directly. Use <meta/size_at.h> instead"
#endif

namespace Hg
{

//  ****************************************************************************
/// Defines each type SizeAt lookup
/// 
/// This macro will generate a set of code for type definitions.
/// Generated output for 3 as the input value:
///
/// Generated Output:
/// ~~~{.cpp}
/// tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(3);
/// 
/// template <TypeList < typename T0,  typename T1,  typename T2,  typename T3, 
///                      typename T4,  typename T5,  typename T6,  typename T7, 
///                      typename T8,  typename T9,  typename T10, typename T11, 
///                      typename T12, typename T13, typename T14, typename T15, 
///                      typename T16, typename T17, typename T18, typename T19, 
///                      typename T20, typename T21, typename T22, typename T23, 
///                      typename T24, typename T25, typename T26, typename T27, 
///                      typename T28, typename T29, typename T30, typename T31> > 
/// struct SizeAt<(3),
///               TypeList < T0,  T1,  T2,  T3,  T4,  T5,  T6,  T7, 
///                          T8,  T9,  T10, T11, T12, T13, T14, T15, 
///                          T16, T17, T18, T19, T20, T21, T22, T23, 
///                          T24, T25, T26, T27, T28, T29, T30, T31
///                        >
///              > 
/// { 
///   typedef TypeList < T0,  T1,  T2,  T3,  T4,  T5,  T6,  T7, 
///                      T8,  T9,  T10, T11, T12, T13, T14, T15, 
///                      T16, T17, T18, T19, T20, T21, T22, T23, 
///                      T24, T25, T26, T27, T28, T29, T30, T31
///                    > Container;
///   static const size_t value = sizeof(TypeAt<3,Container>::type);
/// };
/// ~~~
///           
/// @note           
/// This is a locally defined MACRO. After the list of entries have been defined 
/// to generate the required function calls, the MACRO will be undefined.
///           
#define tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(I)                                  \
template <TMP_ARRAY_32(typename T)>                                           \
struct SizeAt<(I), TypeList<TMP_ARRAY_32(T)> >                                \
{                                                                             \
  typedef TypeList<TMP_ARRAY_32(T)>  Container;                               \
  typedef typename TypeAt<(I),Container>::type TypeAtIndex;                   \
  enum { value = SizeOf<TypeAtIndex>::value };                                \
}

// MACRO Declarations for each ENTRY that is supported for the TypeList  size **
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(0);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(1);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(2);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(3);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(4);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(5);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(6);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(7);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(8);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(9);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(10);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(11);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(12);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(13);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(14);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(15);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(16);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(17);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(18);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(19);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(20);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(21);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(22);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(23);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(24);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(25);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(26);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(27);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(28);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(29);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(30);
tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY(31);

// Undefining the declaration MACRO to prevent its further use. ****************
#undef tmp_ALCHEMY_TYPELIST_SIZEOF_ENTRY

} // namespace Hg

