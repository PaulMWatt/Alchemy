// @file detail/msg_def.h
// 
// Internal implementation MACROS for message format definitions.
// 
// Contains declaration MACROs implementation to define message buffer formats.
// The implementations are hidden behind a second layer to simplify the 
// header file the user will interact with.
// 
// @note           This header file must not be included directly and the 
//                 MACROS defined in this file should not be accessed
//                 directly. Include and used the definitions from the file
//                 **<alchemy.h>** instead.
//           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MSG_DEF_H_INCLUDED
#define MSG_DEF_H_INCLUDED
//  Private Usage Include Guard ************************************************
//  Only allow this header file to be included through alchemy.h
#ifndef ALCHEMY_H_INCLUDED
# error Do not include this file directly. Use <alchemy.h> instead
#endif

//  ****************************************************************************
//  We're potentially using some pretty long type definitions.
//  For any moderately complex message format, we will almost certainly
//  trigger this warning with Visual C++.
#if defined(_MSC_VER)
#pragma warning(disable : 4503) // decorated name length exceeded, name was truncated
#endif

//  Includes *******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/auto_index.h>
#include <Pb/byte_order.h>
#include <Pb/length.h>
#include <Pb/offset_of.h>
#include <Pb/size_at.h>
#include <Pb/size_of.h>
#include <Pb/meta_math.h>
#include <Pb/dynamic.h>
#include <Hg/deduce_msg_type_list.h>
#include <Hg/make_Hg_type_list.h>
#include <Hg/proxy/deduce_proxy_type.h>

#include <cstddef>

//  ****************************************************************************
//  Utility Constructs For Use With Hg Message Types ***************************
//  ****************************************************************************

namespace Hg
{

//  Typedefs *******************************************************************
typedef size_t (*pfnGetDatumSize)(const uint8_t*, size_t);


//  ****************************************************************************
/// Indicates the type size the specified message is, static or dynamic.
///
/// @paramt T     A TypeList definition.
///
/// @return       A typedef called *type* is defined to return the size trait.
///               - static_size_trait indicates a fixed-size message whose
///                                   size is completely known at compile-time.
///               - dynamic_size_trait indicates a dyanmically sized message.
///                                    At least some part of the message requires
///                                    runtime processing to determine the size
///                                    of the message.
///
template< typename T >
struct message_size_trait
  : std::conditional
    < has_dynamic<T>::value,
      dynamic_size_trait,
      static_size_trait
    >
{ };


} // namespace Hg

//  ****************************************************************************
//  Abstracted Message Definition MACROS ***************************************
//  Simplified user MACROS use these definitions.
//  These definitions have been abstracted to simplify the user header files.
//  ****************************************************************************


//  ****************************************************************************


#define EACH_TYPE(r, data, i, x) \
  BOOST_PP_TUPLE_ELEM(3,0,x), 

#define EACH_PARAM(r, data, i, x) \
  BOOST_PP_TUPLE_ELEM(3,1,x)(BOOST_PP_TUPLE_ELEM(3,2,x)); 


#define DEFINE_TYPELIST(N,...)\
  typedef TypeList < __VA_ARGS__ > N;

#define DEFINE_PARAMLIST(...)\
  __VA_ARGS__


#define DEFINE_STRUCT_TYPELIST(N, S) \
  DEFINE_TYPELIST(N, \
    BOOST_PP_SEQ_FOR_EACH_I(EACH_TYPE, unused, BOOST_PP_VARIADIC_TO_SEQ(S)) Hg::MT)

#define DEFINE_STRUCT_PARAMS(S) \
  BOOST_PP_SEQ_FOR_EACH_I(EACH_PARAM, unused, BOOST_PP_VARIADIC_TO_SEQ(S))

#define PAUL_PARAM(T,P) (T,HG_DATUM,P)
#define PAUL_DATUM(T,P) PAUL_PARAM(T,P)

// TODO: Temporarily will try to put the source back together the way it is currently 
//       structured. Then will move the placement of the definitions to 
//       solve some of the incompatibilities for duplicate types.

//  ****************************************************************************
//  Defines the outer value container as well as the formatted type-list.
//
#define DEFINE_HG_STRUCT(NAME, ...)                                            \
  DEFINE_STRUCT_TYPELIST(NAME##_tl, __VA_ARGS__)                               \
  struct NAME                                                                  \
    : nested_trait                                                             \
  {                                                                            \
    typedef NAME                        this_type;                             \
    typedef NAME##_tl                   format_type;                           \
    enum { k_size = SizeOf<format_type>::value };                              \
    enum { k_length                   = length<format_type>::value };          \
                                                                               \
    template< size_t IDX>                                                      \
    Datum<IDX, format_type>& FieldAt()                                         \
    {                                                                          \
      typedef Datum   < IDX,                                                   \
                        format_type>    datum_type_t;                          \
      return FieldAtIndex((datum_type_t*)0);                                   \
    }                                                                          \
    template< size_t IDX>                                                      \
    const Datum<IDX, format_type>& const_FieldAt() const                       \
    {                                                                          \
      return const_cast<F##Format*>(this)->FieldAt();                          \
    }                                                                          \
    template<size_t I> struct TypeAtIndex;                                     \
    BEGIN_COUNTER                                                              \
                                                                               \
    DEFINE_STRUCT_PARAMS(__VA_ARGS__)                                          \
    DECLARE_STRUCT_FOOTER(NAME)
  


//  ****************************************************************************
//  Primary Message Declaration MACROS *****************************************
//  ****************************************************************************
#define DEFINE_HG_STRUCT_HEADER(F)                                             \
  struct F##Format                                                             \
    : nested_trait                                                             \
  {                                                                            \
    typedef F##Format                   this_type;                             \
    typedef F                           format_type;                           \
    enum { k_size = SizeOf<format_type>::value };                              \
    enum { k_length                   = length<format_type>::value };          \
                                                                               \
    template< size_t IDX>                                                      \
    Datum<IDX, format_type>& FieldAt()                                         \
    {                                                                          \
      typedef Datum   < IDX,                                                   \
                        format_type>    datum_type_t;                          \
      return FieldAtIndex((datum_type_t*)0);                                   \
    }                                                                          \
    template< size_t IDX>                                                      \
    const Datum<IDX, format_type>& const_FieldAt() const                       \
    {                                                                          \
      return const_cast<F##Format*>(this)->FieldAt();                          \
    }                                                                          \
    template<size_t I> struct TypeAtIndex;            \
    BEGIN_COUNTER

//  ****************************************************************************
#define DECLARE_STRUCT_HEADER(F)                                               \
  typedef Hg::make_Hg_type_list<F>::type                    F##_Hg;            \
  DEFINE_HG_STRUCT_HEADER(F##_Hg)

//  ****************************************************************************
#define DECLARE_DATUM_ENTRY_IDX(IDX,T,P)                                       \
    typedef                                                                    \
      Hg::detail::DeduceProxyType < IDX,                                       \
                                    format_type>::type        Proxy##P;        \
    typedef Proxy##P::datum_type                              datum_##P;       \
    Proxy##P   P;                                                              \
                                                                               \
    datum_##P& FieldAtIndex(const datum_##P*)                                  \
    { return *static_cast<datum_##P*>(&P); }                                   \
                                                                               \
    const char* FieldName(const Proxy##P&)                    { return #P; }   \
    template<> struct TypeAtIndex<IDX> { typedef T type; };              


//  ****************************************************************************
#define DECLARE_DATUM_ENTRY(T, P)                                              \
  INC_COUNTER                                                                  \
  DECLARE_DATUM_ENTRY_IDX((COUNTER_VALUE), T, P)


//  ****************************************************************************
#define DECLARE_ARRAY_ENTRY_IDX(IDX,A,P)                                       \
  DECLARE_DATUM_ENTRY_IDX(IDX,A,P)


//  ****************************************************************************
#define DECLARE_ARRAY(T,N)                std::array<T,N>

//  ****************************************************************************
#define DECLARE_ARRAY_ENTRY(T, N, P)                                           \
  INC_COUNTER                                                                  \
  DECLARE_ARRAY_ENTRY_IDX((COUNTER_VALUE), DECLARE_ARRAY(T, N), P)


//  ****************************************************************************
#define DECLARE_DYNAMIC_ENTRY_IDX(IDX,V,N,P)                                   \
    DECLARE_DATUM_ENTRY_IDX(IDX,V,P)                                           \
  public:                                                                      \
    template <typename U>                                                      \
    size_t Size(U& buffer, datum_##P*)  { return DatumSize(N, &buffer); }


//  ****************************************************************************
#define DECLARE_VECTOR(T)                 std::vector<T>

//  ****************************************************************************
#define DECLARE_DYNAMIC_ENTRY(T, N, P)                                         \
    INC_COUNTER                                                                \
    DECLARE_DYNAMIC_ENTRY_IDX((COUNTER_VALUE), DECLARE_VECTOR(T), N, P)


//  ****************************************************************************
#define DECLARE_ALLOCATED_VECTOR(T,A)     std::vector<T,A>

//  ****************************************************************************
#define DECLARE_ALLOCATOR_ENTRY(T, A, N, P)                                    \
    INC_COUNTER                                                                \
    DECLARE_DYNAMIC_ENTRY_IDX((COUNTER_VALUE), DECLARE_ALLOCATED_VECTOR(T,A), N, P)


//  ****************************************************************************
#define DECLARE_STRUCT_FOOTER(NAME)                                            \
  private:                                                                     \
    template <typename T, typename U>                                          \
    size_t DatumSize(T value, U*)                                              \
    {                                                                          \
      return value;                                                            \
    }                                                                          \
                                                                               \
    template <typename U>                                                      \
    size_t DatumSize(pfnGetDatumSize ftor, U* buffer)                          \
    {                                                                          \
      if (buffer->empty()) { return 0; }                                       \
      return ftor(buffer->data(), buffer->size());                             \
    }                                                                          \
  };                                                                           \
  namespace detail {                                                           \
  template <>                                                                  \
  struct field_data_t <NAME##_tl>                                              \
  {                                                                            \
  typedef NAME                          value_type;                            \
  };                                                                           \
  } // namespace detail


//  ****************************************************************************
//  Bit Fields *****************************************************************
//  ****************************************************************************
#define DECLARE_PACKED_HEADER(T,C)                                             \
  struct C;                                                                    \
  template <>                                                                  \
  struct ContainerSize<C>                                                      \
    : std::integral_constant<size_t, sizeof(T)>         { };                   \
                                                                               \
  struct C                                                                     \
    : public PackedBits<T>                                                     \
  {                                                                            \
    typedef C                                     this_type;                   \
    typedef T                                     value_type;                  \
    typedef PackedBits<T>                         base_type;                   \
                                                                               \
    C()                                                                        \
      : base_type()                                                            \
    { }                                                                        \
                                                                               \
    C(const value_type &data_field)                                            \
      : base_type()                                                            \
    { value(data_field); }                                                     \
                                                                               \
    C(value_type &data_field)                                                  \
      : base_type(data_field)                                                  \
    { }                                                                        \
                                                                               \
    C& operator=(const C &rhs)                                                 \
    { value(rhs.value());                                                      \
      return *this;                                                            \
    }                                                                          \
    C& operator=(const value_type &data_field)                                 \
    { value(data_field);                                                       \
      return *this;                                                            \
    }                                                                          \
                                                                               \
    enum { k_offset_0 = 0 };                                                   \

// *****************************************************************************
#define DECLARE_BIT_FIELD(IDX,P,N)                                             \
  typedef FieldIndex< IDX, this_type,N> idx_##IDX;                             \
  struct P##_tag                                                               \
  { static ptrdiff_t offset()                                                  \
    { return offsetof(this_type, P); }                                         \
  };                                                                           \
                                                                               \
  typedef BitField  < this_type, P##_tag, k_offset_##IDX, N, value_type > P##_t; \
  enum { TMP_PASTE(k_offset_, TMP_INC(IDX)) = k_offset_##IDX + N };            \
                                                                               \
  P##_t P;

// *****************************************************************************
#define DECLARE_PACKED_FOOTER                                                  \
  };

#endif

