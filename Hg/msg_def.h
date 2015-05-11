// @file Hg/msg_def.h
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


//  ****************************************************************************
//  Declaration MACROs used for converting from the generic Alchemy definition.
//  ****************************************************************************

//  ****************************************************************************
//  Helps convert generic ALCHEMY datum declarations to elemental declarations.  
//
#define ELEMENTAL_PARAM(r, data, i, x) \
   , BOOST_PP_CAT(data, x)

// TODO: It's possible, GCC may accept this form. If not, refer to the EACH_PARAM MACRO below.

//  ****************************************************************************
//  Iterates through each parameter declared in an Alchemy struct declaration.
//  This for-loop uses the ELEMENTAL_PARAM MACRO above to prepend the 
//  supplied element prefix to the parameter declaration.
//
#define STRUCT_PARAMS(NAME, EL,S) \
  (NAME BOOST_PP_SEQ_FOR_EACH_I(ELEMENTAL_PARAM, EL, S))

//  ****************************************************************************
//  The generic Alchemy struct definition.
//  This definition can be converted into any elemental type definition 
//  that is defined for Alchemy.
//
#define DECLARE_STRUCT(NAME, EL, ...)                                          \
  EL##DECLARE_STRUCT_HEADER                                                    \
    STRUCT_PARAMS(NAME, EL, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))



//  ****************************************************************************
//  Helps convert generic ALCHEMY datum declarations to elemental declarations.  
//
#define ELEMENTAL_BITS(r, data, i, x) \
    , BOOST_PP_CAT(data, x)

//  ****************************************************************************
//  Iterates through each parameter declared in an Alchemy struct declaration.
//  This for-loop uses the ELEMENTAL_PARAM MACRO above to prepend the 
//  supplied element prefix to the parameter declaration.
//
#define PACKED_PARAMS(TYPE, NAME, EL,S)                                        \
  (TYPE, NAME BOOST_PP_SEQ_FOR_EACH_I(ELEMENTAL_BITS, EL, S))

//  ****************************************************************************
//  The generic Alchemy struct definition.
//  This definition can be converted into any elemental type definition 
//  that is defined for Alchemy.
//
#define DECLARE_PACKED(TYPE, NAME, EL, ...)                                    \
  EL##DECLARE_PACKED_HEADER                                                    \
    PACKED_PARAMS(TYPE, NAME, EL,BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))


//  ****************************************************************************
//  The version of MACROs defined below are dependent upon the language.
//
#ifdef __cplusplus 

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
#define DO_REMOVE(...)   __VA_ARGS__
#define REMOVE_PARENS(N) DO_REMOVE N

#define BOOST_PP_REMOVE_PARENS(param) \
    BOOST_PP_IIF \
      ( \
      BOOST_PP_IS_BEGIN_PARENS(param), \
      DO_REMOVE, \
      BOOST_PP_IDENTITY \
      ) \
    (param)() \

//  ****************************************************************************
#define EACH_TYPE(r, data, i, x) \
  REMOVE_PARENS(BOOST_PP_TUPLE_ELEM(3,0,x)), 

#define EACH_PARAM(r, data, i, x) \
  BOOST_PP_TUPLE_ELEM(3,1,x)(BOOST_PP_TUPLE_ELEM(3,2,x)); 

#define DEFINE_TYPELIST(N,...)\
  typedef TypeList < __VA_ARGS__ > N;


#if defined(_MSC_VER)
#define DEFINE_STRUCT_TYPELIST(N, S) \
  DEFINE_TYPELIST(N, \
    BOOST_PP_SEQ_FOR_EACH_I(EACH_TYPE, unused, BOOST_PP_VARIADIC_TO_SEQ(S)) Hg::MT)


#define DEFINE_STRUCT_PARAMS(S) \
  BOOST_PP_SEQ_FOR_EACH_I(EACH_PARAM, unused, BOOST_PP_VARIADIC_TO_SEQ(S))

#else

#define DEFINE_STRUCT_TYPELIST(N, ...) \
  DEFINE_TYPELIST(N, \
    BOOST_PP_SEQ_FOR_EACH_I(EACH_TYPE, unused, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)) Hg::MT)


#define DEFINE_STRUCT_PARAMS(...) \
  BOOST_PP_SEQ_FOR_EACH_I(EACH_PARAM, unused, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#endif

// TODO: Temporarily will try to put the source back together the way it is currently 
//       structured. Then will move the placement of the definitions to 
//       solve some of the incompatibilities for duplicate types.

//  ****************************************************************************
//  Defines the outer value container as well as the formatted type-list.
//
#define Hg_DECLARE_STRUCT_HEADER(F, ...)                                       \
  BEGIN_NAMESPACE(Hg)                                                          \
  DEFINE_STRUCT_TYPELIST(F##_tl, __VA_ARGS__)                                  \
  typedef Hg::make_Hg_type_list<F##_tl>::type               F##_Hg;            \
                                                                               \
  struct F                                                                     \
    : nested_trait                                                             \
  {                                                                            \
    typedef F                           this_type;                             \
    typedef F##_tl                      format_type;                           \
    enum { k_size = SizeOf<format_type>::value };                              \
    enum { k_length                   = length<format_type>::value };          \
                                                                               \
    template< size_t IDX>                                                      \
    Datum<IDX, format_type>& FieldAt()                                         \
    {                                                                          \
      typedef Datum   < IDX,                                                   \
                        format_type>    datum_type_t;                          \
      return this_type::FieldAtIndex((datum_type_t*)0);                        \
    }                                                                          \
    template< size_t IDX>                                                      \
    const Datum<IDX, format_type>& const_FieldAt() const                       \
    {                                                                          \
      return const_cast<this_type*>(this)->FieldAt<IDX>();                     \
    }                                                                          \
    BEGIN_COUNTER                                                              \
                                                                               \
    DEFINE_STRUCT_PARAMS(__VA_ARGS__)                                          \
  Hg_DECLARE_STRUCT_FOOTER(F)
    

//  ****************************************************************************
#define Hg_DECLARE_STRUCT_FOOTER(F)                                            \
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
  BEGIN_NAMESPACE(detail)                                                      \
  template <>                                                                  \
  struct field_data_t <F##_Hg>                                                 \
  {                                                                            \
    typedef F                           value_type;                            \
  };                                                                           \
  END_NAMESPACE(detail)                                                        \
  END_NAMESPACE(Hg)                                                            


//  ****************************************************************************
#define DECLARE_DATUM_ENTRY_IDX(IDX,P)                                         \
    typedef                                                                    \
      Hg::detail::DeduceProxyType < IDX,                                       \
                                    format_type>::type        Proxy##P;        \
    typedef Proxy##P::datum_type                              datum_##P;       \
    Proxy##P   P;                                                              \
                                                                               \
    datum_##P& FieldAtIndex(const datum_##P*)                                  \
    { return *static_cast<datum_##P*>(&P); }                                   \
                                                                               \
    const char* FieldName(const Proxy##P&)                    { return #P; }   

//  ****************************************************************************
#define DECLARE_DATUM_ENTRY_X(P)                                               \
  INC_COUNTER                                                                  \
  DECLARE_DATUM_ENTRY_IDX((COUNTER_VALUE), P)

//  ****************************************************************************
#define D_FUNDAMENTAL(...)              DECLARE_DATUM_ENTRY_X __VA_ARGS__ 
#define D_DATUM_X(T,P)                  (T,D_FUNDAMENTAL,(P))

//  ****************************************************************************
#define DECLARE_ARRAY(T,N)              std::array<T,N>

//  ****************************************************************************
#define DECLARE_VECTOR(T)               std::vector<T>

//  ****************************************************************************
#define DECLARE_VECTOR_ALLOCATED(T,A)   std::vector<T,A>

//  ****************************************************************************
#define D_ARRAY(T, N, P)                D_DATUM_X((DECLARE_ARRAY(T,N)), P)

//  ****************************************************************************
#define D_DYNAMIC(N,P)                                                         \
    DECLARE_DATUM_ENTRY_X(P)                                                   \
  public:                                                                      \
    template <typename U>                                                      \
    size_t Size(U& buffer, datum_##P*)  { return DatumSize(N, &buffer); }


#define D_DYNAMIC2(...)  D_DYNAMIC __VA_ARGS__
#define D_VECTOR(T,N,P) ((DECLARE_VECTOR(T)),D_DYNAMIC2,(N,P))


//  ****************************************************************************
#define Hg_DECLARE_DATUM(T,P)                  D_DATUM_X((T),P)
#define Hg_DECLARE_ARRAY_DATUM(T, N, P)        D_ARRAY(T, N, P) 
#define Hg_DECLARE_VECTOR_DATUM(T, N, P)       D_VECTOR(T, N, P)
#define Hg_DECLARE_ALLOCATOR_DATUM(T, A, N, P) D_VECTOR(DECLARE_VECTOR_ALLOCATED(T,A), N, P)



//  ****************************************************************************
//  Packed Bit Fields **********************************************************
//  ****************************************************************************
#define Eval_Hg(x) x
#define Hg_EACH_BIT_FIELD(r, data, i, x) \
  BOOST_PP_CAT(data, x)
  

#if defined(_MSC_VER)

#define Hg_DEFINE_PACKED_FIELDS(S) \
  BOOST_PP_SEQ_FOR_EACH_I(Hg_EACH_BIT_FIELD, Eval_, BOOST_PP_VARIADIC_TO_SEQ(S))

#else

#define Hg_DEFINE_PACKED_FIELDS(...) \
  BOOST_PP_SEQ_FOR_EACH_I(C_EACH_BIT_FIELD, unused, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#endif


//  ****************************************************************************
#define Hg_DECLARE_PACKED_HEADER(T,C,...)                                      \
  BEGIN_NAMESPACE(Hg)                                                          \
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
    Hg_DEFINE_PACKED_FIELDS(__VA_ARGS__)                                       \
  };                                                                           \
  END_NAMESPACE(Hg)

// *****************************************************************************
#define Eval_Hg_DECLARE_BIT_FIELD(IDX,P,N)                                      \
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


#else

//  ****************************************************************************
//  Declare empty Hg MACROS for non-C++ builds.
//
#define Hg_DECLARE_STRUCT_HEADER(NAME, ...)
#define Hg_DECLARE_DATUM(TYPE,NAME)
#define Hg_DECLARE_ARRAY_DATUM(TYPE,COUNT,NAME)
#define Hg_DECLARE_VECTOR_DATUM(TYPE,COUNT,NAME)
#define Hg_DECLARE_ALLOCATOR_DATUM(TYPE,ALLOCATOR,COUNT,NAME)
#define Hg_DECLARE_STRUCT_FOOTER(TYPE_LIST)

#define Hg_DECLARE_PACKED_HEADER(TYPE,NAME, ...)
#define Hg_DECLARE_BIT_FIELD(INDEX, NAME, COUNT)
#define Hg_DECLARE_PACKED_FOOTER

#endif // __cplusplus

#endif
