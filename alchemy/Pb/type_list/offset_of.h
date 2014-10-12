/// @file meta/type_list/offset_of.h
/// 
/// Calculates the offset in bytes of the type at the specified index in the 
/// Type Container.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef OFFSET_OF_H_INCLUDED
# error "Do not include this file directly. Use <Pb/offset_of.h> instead"
#endif


namespace Hg
{

//  ****************************************************************************
/// Defines each type offset lookup 
/// 
/// This macro will generate a set of code for type definitions that looks like 
/// this, where 3 has been used for the input I.
///            
/// ~~~{.cpp}
/// tmp_ALCHEMY_TYPELIST_OFFSETOF(3);
/// 
/// template <TypeList < typename T0,  typename T1,  typename T2,  typename T3, 
///                      typename T4,  typename T5,  typename T6,  typename T7, 
///                      typename T8,  typename T9,  typename T10, typename T11, 
///                      typename T12, typename T13, typename T14, typename T15, 
///                      typename T16, typename T17, typename T18, typename T19, 
///                      typename T20, typename T21, typename T22, typename T23, 
///                      typename T24, typename T25, typename T26, typename T27, 
///                      typename T28, typename T29, typename T30, typename T31>, 
///           ErrorT
///          > 
/// ptrdiff_t OffsetOf< (3),
///                     TypeList < T0,  T1,  T2,  T3,  T4,  T5,  T6,  T7, 
///                                T8,  T9,  T10, T11, T12, T13, T14, T15, 
///                                T16, T17, T18, T19, T20, T21, T22, T23, 
///                                T24, T25, T26, T27, T28, T29, T30, T31
///                              >;
///                   > 
/// { 
///   typedef TypeList < T0,  T1,  T2,  T3,  T4,  T5,  T6,  T7, 
///                      T8,  T9,  T10, T11, T12, T13, T14, T15, 
///                      T16, T17, T18, T19, T20, T21, T22, T23, 
///                      T24, T25, T26, T27, T28, T29, T30, T31
///                    > ContainerT;
///   static const size_t value = SizeOf  <3-1, ContainerT>() 
///                             + OffsetOf<3-1, ContainerT>();
/// };
/// ~~~
/// 
/// @note:          This is a locally defined MACRO. After the list of entries 
///                 have been defined to generate the required function calls,
///                 the MACRO will be undefined.
//  ****************************************************************************
#define tmp_ALCHEMY_TYPELIST_OFFSETOF(I)                                      \
template <TMP_ARRAY_32(typename T)>                                           \
struct OffsetOf< (I), TypeList<TMP_ARRAY_32(T)> >                             \
{                                                                             \
  typedef TypeList<TMP_ARRAY_32(T)>   container;                              \
                                                                              \
  enum { value = OffsetOf<(I)-1, container>::value                            \
               + SizeAt  <(I)-1, container>::value };                         \
}



//  Declarations for each ENTRY that is supported for the TypeList  size *******
//  Offset for zero is handled as a special case above *************************
tmp_ALCHEMY_TYPELIST_OFFSETOF(1);
tmp_ALCHEMY_TYPELIST_OFFSETOF(2);
tmp_ALCHEMY_TYPELIST_OFFSETOF(3);
tmp_ALCHEMY_TYPELIST_OFFSETOF(4);
tmp_ALCHEMY_TYPELIST_OFFSETOF(5);
tmp_ALCHEMY_TYPELIST_OFFSETOF(6);
tmp_ALCHEMY_TYPELIST_OFFSETOF(7);
tmp_ALCHEMY_TYPELIST_OFFSETOF(8);
tmp_ALCHEMY_TYPELIST_OFFSETOF(9);
tmp_ALCHEMY_TYPELIST_OFFSETOF(10);
tmp_ALCHEMY_TYPELIST_OFFSETOF(11);
tmp_ALCHEMY_TYPELIST_OFFSETOF(12);
tmp_ALCHEMY_TYPELIST_OFFSETOF(13);
tmp_ALCHEMY_TYPELIST_OFFSETOF(14);
tmp_ALCHEMY_TYPELIST_OFFSETOF(15);
tmp_ALCHEMY_TYPELIST_OFFSETOF(16);
tmp_ALCHEMY_TYPELIST_OFFSETOF(17);
tmp_ALCHEMY_TYPELIST_OFFSETOF(18);
tmp_ALCHEMY_TYPELIST_OFFSETOF(19);
tmp_ALCHEMY_TYPELIST_OFFSETOF(20);
tmp_ALCHEMY_TYPELIST_OFFSETOF(21);
tmp_ALCHEMY_TYPELIST_OFFSETOF(22);
tmp_ALCHEMY_TYPELIST_OFFSETOF(23);
tmp_ALCHEMY_TYPELIST_OFFSETOF(24);
tmp_ALCHEMY_TYPELIST_OFFSETOF(25);
tmp_ALCHEMY_TYPELIST_OFFSETOF(26);
tmp_ALCHEMY_TYPELIST_OFFSETOF(27);
tmp_ALCHEMY_TYPELIST_OFFSETOF(28);
tmp_ALCHEMY_TYPELIST_OFFSETOF(29);
tmp_ALCHEMY_TYPELIST_OFFSETOF(30);
tmp_ALCHEMY_TYPELIST_OFFSETOF(31);

//  Undefining the declaration MACRO to prevent its further use. ***************
#undef tmp_ALCHEMY_TYPELIST_OFFSETOF

} // namespace Hg

