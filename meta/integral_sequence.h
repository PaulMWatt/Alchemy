/// @file meta/integral_sequence.h
/// 
/// A parameterized integral sequence construct.
/// 
/// The IntegralSequence can be used to hold a sequence of numbers in a list.
/// Operations are provided to get the first element from the sequence and
/// the remainder of the sequence. With these two operations the entire 
/// sequence can be traversed at compile-time.
/// 
/// @note           This header file must not be included directly and the 
///                 MACROS defined in this file should not be accessed
///                 directly. Include and used the definitions from the file
///                 **<alchemy.h>** instead.
///           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef INTEGRAL_SEQUENCE_H_INCLUDED
#define INTEGRAL_SEQUENCE_H_INCLUDED
// Includes *******************************************************************
#include <meta/meta_fwd.h>
#include <meta/meta_macros.h>

namespace Hg
{

//  Generic Integral Node ******************************************************
template <size_t H, typename T>
struct IntegralNode
  : std::integral_constant<size_t, H>
{
  typedef IntegralNode<H, T>        type;
  typedef size_t                    value_type;

  typedef size_t                    head;
  typedef T                         tail;
};

// ****************************************************************************
/// A parameterized type that is a sequence of integer values.
/// 
/// ~~~{.cpp}
/// template  < size_t T0,      size_t T1  = 0, size_t T2  = 0, size_t T3  = 0,
///             size_t T4  = 0, size_t T5  = 0, size_t T6  = 0, size_t T7  = 0,
///             size_t T8  = 0, size_t T9  = 0, size_t T10 = 0, size_t T11 = 0,
///             size_t T12 = 0, size_t T13 = 0, size_t T14 = 0, size_t T15 = 0,
///             size_t T16 = 0, size_t T17 = 0, size_t T18 = 0, size_t T19 = 0,
///             size_t T20 = 0, size_t T21 = 0, size_t T22 = 0, size_t T23 = 0,
///             size_t T24 = 0, size_t T25 = 0, size_t T26 = 0, size_t T27 = 0,
///             size_t T28 = 0, size_t T29 = 0, size_t T30 = 0, size_t T31 = 0
///           >
/// struct IntegralSequence
/// {  
///   typedef IntegralNode<T1, 
///           IntegralNode<T2, 
///           IntegralNode<T3, 
///           IntegralNode<T4, 
///           IntegralNode<T5, 
///           IntegralNode<T6, 
///           IntegralNode<T7, 
///           IntegralNode<T8, 
///           IntegralNode<T9, 
///           IntegralNode<T10,
///           IntegralNode<T11,
///           IntegralNode<T12,
///           IntegralNode<T13, 
///           IntegralNode<T14, 
///           IntegralNode<T15,  
///           IntegralNode<T16,  
///           IntegralNode<T17,  
///           IntegralNode<T18,  
///           IntegralNode<T19,  
///           IntegralNode<T20,  
///           IntegralNode<T21,  
///           IntegralNode<T22,  
///           IntegralNode<T23,  
///           IntegralNode<T24,  
///           IntegralNode<T25,  
///           IntegralNode<T26,  
///           IntegralNode<T27,  
///           IntegralNode<T28,  
///           IntegralNode<T29,  
///           IntegralNode<T30,  
///           IntegralNode<T31, 
///           IntegralNode<T32, empty> 
///         > > > > > > > > > > > > > > > 
///         > > > > > > > > > > > > > > > >                type;
/// };
/// ~~~
/// 
template  < size_t T0,      size_t T1  = 0, size_t T2  = 0, size_t T3  = 0,
            size_t T4  = 0, size_t T5  = 0, size_t T6  = 0, size_t T7  = 0,
            size_t T8  = 0, size_t T9  = 0, size_t T10 = 0, size_t T11 = 0,
            size_t T12 = 0, size_t T13 = 0, size_t T14 = 0, size_t T15 = 0,
            size_t T16 = 0, size_t T17 = 0, size_t T18 = 0, size_t T19 = 0,
            size_t T20 = 0, size_t T21 = 0, size_t T22 = 0, size_t T23 = 0,
            size_t T24 = 0, size_t T25 = 0, size_t T26 = 0, size_t T27 = 0,
            size_t T28 = 0, size_t T29 = 0, size_t T30 = 0, size_t T31 = 0
          >
struct IntegralSequence
{
  // This typedef and MACRO declaration results in the definition
  // listed in the comments for this type.

  // This typedef and MACRO declaration results in the definition
  // listed in the comments for this type.
  // The DECLARE_INTEGER_SEQUENCE MACRO us an indirection because the generated
  // code contains a comma.
  #define DECLARE_INTEGER_SEQUENCE  TMP_ARRAY_32(IntegralNode<T), empty TMP_REPEAT_32(>)
  typedef DECLARE_INTEGER_SEQUENCE                                type;
  typedef size_t                                                  value_type;
  typedef empty                                                   tail;
  static const size_t value = T0;
};


#define META_INT_SEQUENCE_DEF(S)                                              \
template <TMP_ARRAY_##S(size_t T)>                                            \
struct IntegralSequence<TMP_ARRAY_##S(T)>                                     \
{                                                                             \
  typedef TMP_ARRAY_##S(IntegralNode<T), empty TMP_REPEAT_##S(>)  type;       \
  typedef size_t                                                  value_type; \
  typedef typename type::tail                                     tail;       \
  static const size_t value = type::value;                                    \
}

// Define specializations of this array from 1 to 31 elements *****************
META_INT_SEQUENCE_DEF(1);
META_INT_SEQUENCE_DEF(2);
META_INT_SEQUENCE_DEF(3);
META_INT_SEQUENCE_DEF(4);
META_INT_SEQUENCE_DEF(5);
META_INT_SEQUENCE_DEF(6);
META_INT_SEQUENCE_DEF(7);
META_INT_SEQUENCE_DEF(8);
META_INT_SEQUENCE_DEF(9);
META_INT_SEQUENCE_DEF(10);
META_INT_SEQUENCE_DEF(11);
META_INT_SEQUENCE_DEF(12);
META_INT_SEQUENCE_DEF(13);
META_INT_SEQUENCE_DEF(14);
META_INT_SEQUENCE_DEF(15);
META_INT_SEQUENCE_DEF(16);
META_INT_SEQUENCE_DEF(17);
META_INT_SEQUENCE_DEF(18);
META_INT_SEQUENCE_DEF(19);
META_INT_SEQUENCE_DEF(20);
META_INT_SEQUENCE_DEF(21);
META_INT_SEQUENCE_DEF(22);
META_INT_SEQUENCE_DEF(23);
META_INT_SEQUENCE_DEF(24);
META_INT_SEQUENCE_DEF(25);
META_INT_SEQUENCE_DEF(26);
META_INT_SEQUENCE_DEF(27);
META_INT_SEQUENCE_DEF(28);
META_INT_SEQUENCE_DEF(29);
META_INT_SEQUENCE_DEF(30);
META_INT_SEQUENCE_DEF(31);

// Undefining the declaration MACRO to prevent its further use. ****************
#undef META_INT_SEQUENCE_DEF

// A few utility operations and specializations for the IntegralSequence ******
//  ***************************************************************************
template <typename SeqT>
struct Front
  : std::integral_constant< size_t, SeqT::value>
{ };

//  ***************************************************************************
template <>
struct Front< empty >
  : std::integral_constant< size_t, 0>
{ };

//  ***************************************************************************
template <typename SeqT>
struct PopFront
{
  typedef typename SeqT::tail           type;
};

//  ***************************************************************************
template <>
struct PopFront <empty>
{
  typedef empty                         type;
};

//  ***************************************************************************
/// Safely extracts the last value in an integral sequence.
///
template <typename SeqT>
struct TailValue
  : Front <typename PopFront<SeqT>::type>
{ };

//  ***************************************************************************
/// Specialization to TailValue for the empty type node.
///
template <>
struct TailValue <empty>
  : std::integral_constant<size_t, 0>
{ };

//  ***************************************************************************
/// Compares the tail-type of the sequence and indicates if the type is empty.
///
template <typename SeqT>
struct IsTailEmpty
  : std::integral_constant< bool,
                              empty_type < typename PopFront<SeqT>::type>::value
                           || 0 == TailValue<SeqT>::value
                          >
{ };

//  ***************************************************************************
/// Specialization for an empty type sequence..
///
template <>
struct IsTailEmpty <empty>
  : std::true_type
{};

//  ***************************************************************************
/// Returns the Tail of an Integral Sequence.
/// This is similar to PopFront, however, as soon as a 0 is encountered, 
/// empty will be returned, rather than the remainder of the list.
///
template <typename SeqT>
struct GetTail
{
  typedef typename PopFront<SeqT>::type type;

  //typedef typename
  //std::conditional
  //<
  //  0 != TailValue<SeqT>::value,
  //  typename PopFront<SeqT>::type,
  //  IntegralNode< Front<SeqT>::value, empty>
  //>::type                             type;

};

//  ***************************************************************************
/// Specialization of GetTail for the empty node type.
///
template <>
struct GetTail<empty>
{ 
  typedef empty               type;
};

} // namespace Hg



#endif
