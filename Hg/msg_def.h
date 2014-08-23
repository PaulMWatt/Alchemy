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
#include <meta/meta_fwd.h>
#include <meta/auto_index.h>
#include <meta/byte_order.h>
#include <meta/length.h>
#include <meta/offset_of.h>
#include <meta/size_at.h>
#include <meta/size_of.h>
#include <meta/meta_math.h>
#include <meta/dynamic.h>
#include <Hg/proxy/deduce_proxy_type.h>

//  ****************************************************************************
//  Utility Constructs For Use With Hg Message Types ***************************
//  ****************************************************************************

namespace Hg
{

//  Typedefs *******************************************************************
typedef size_t (*pfnGetDatumSize)(uint8_t*, size_t);


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

// *****************************************************************************
//  Abstracted Message Definition MACROS ***************************************
//  Simplified user MACROS use these definitions.
//  These definitions have been abstracted to simplify the user header files.
// *****************************************************************************

// *****************************************************************************
//  Primary Message Declaration MACROS *****************************************
// *****************************************************************************
#define DECLARE_FORMAT_HEADER(F)                                               \
  template< size_t   kt_offset >                                               \
  struct F##Format;                                                            \
                                                                               \
  template <>                                                                  \
  struct detail::field_data_t <F>                                              \
  {                                                                            \
  typedef F##Format<0>      value_type;                                        \
  };                                                                           \
                                                                               \
  template< size_t   kt_offset >                                               \
  struct detail::FieldTypes <F,kt_offset>                                      \
      : F##Format<kt_offset>                                                   \
  {                                                                            \
    typedef F                           index_type;                            \
    typedef F##Format < kt_offset >     value_type;                            \
    FieldTypes()                                                               \
        : m_shadow_data(This())         { }                                    \
                                                                               \
    value_type& This()                  {return *this;}                        \
    value_type                         &m_shadow_data;                         \
  };                                                                           \
                                                                               \
  template< size_t   kt_offset >                                               \
  struct F##Format                                                             \
    : nested_trait                                                             \
  {                                                                            \
    typedef F                           format_type;                           \
    enum { k_size = SizeOf<format_type>::value };                              \
    enum { k_length                   = length<format_type>::value };          \
    enum { k_base_offset              = kt_offset };                           \
                                                                               \
    template< size_t IDX>                                                      \
    Datum<IDX, format_type, k_base_offset>&                                    \
      FieldAt()                                                                \
    {                                                                          \
      typedef Datum   < IDX,                                                   \
                        format_type,                                           \
                        k_base_offset>  datum_type_t;                          \
      return FieldAtIndex(datum_type_t());                                     \
    }                                                                          \
    BEGIN_COUNTER

// *****************************************************************************
#define DECLARE_DATUM_FORMAT_IDX(IDX,T,P)                                      \
  typedef typename                                                             \
    Hg::detail::DeduceProxyType < IDX,                                         \
                                  format_type,                                 \
                                  k_base_offset>::type      Proxy##P;          \
  typedef typename Proxy##P::datum_type                     datum_##P;         \
  Proxy##P   P;                                                                \
                                                                               \
  datum_##P& FieldAtIndex(const datum_##P&)                                    \
  { return *static_cast<datum_##P*>(&P); }                                     \
                                                                               \
  const char* FieldName(const Proxy##P&)                    { return #P; }


// *****************************************************************************
#define DECLARE_DATUM_FORMAT(T, P)                                             \
  INC_COUNTER                                                                  \
  DECLARE_DATUM_FORMAT_IDX(COUNTER_VALUE, T, P)


// *****************************************************************************
#define DECLARE_ARRAY_FORMAT_IDX(IDX,T,N,P)                                    \
  DECLARE_DATUM_FORMAT_IDX(IDX,(std::array<T,N>),P)


// *****************************************************************************
#define DECLARE_ARRAY_FORMAT(T, N, P)                                          \
  INC_COUNTER                                                                  \
  DECLARE_ARRAY_FORMAT_IDX(COUNTER_VALUE, T, N, P)


// *****************************************************************************
#define DECLARE_DYNAMIC_FORMAT_IDX(IDX,T,N,P)                                  \
  DECLARE_DATUM_FORMAT_IDX(IDX,(std::vector<T>),P)                             \
  template <typename U>                                                        \
  size_t Size(U& buffer, datum_##P&)  { return DatumSize(N, buffer); }


// *****************************************************************************
#define DECLARE_DYNAMIC_FORMAT(T, N, P)                                        \
  INC_COUNTER                                                                  \
  DECLARE_DYNAMIC_FORMAT_IDX(COUNTER_VALUE, T, N, P)


// *****************************************************************************
#define DECLARE_ALLOCATOR_FORMAT_IDX(IDX,T,N,P)                                \
  DECLARE_DATUM_FORMAT_IDX(IDX,(std::vector<T,A>),P)                           \
  template <typename U>                                                        \
  size_t Size(U& buffer, datum_##P&)  { return DatumSize(N, buffer); }


// *****************************************************************************
#define DECLARE_ALLOCATOR_FORMAT(T, A, N, P)                                   \
  INC_COUNTER                                                                  \
  DECLARE_ALLOCATOR_FORMAT_IDX(COUNTER_VALUE, T, A, N, P)


// *****************************************************************************
#define DECLARE_FORMAT_FOOTER                                                  \
  private:                                                                     \
    template <typename T, typename U>                                          \
    size_t DatumSize(T value, U&)                                              \
    {                                                                          \
      return value;                                                            \
    }                                                                          \
                                                                               \
    template <typename U>                                                      \
    size_t DatumSize(pfnGetDatumSize ftor, U& buffer)                          \
    {                                                                          \
      if (buffer.empty()) { return 0; }                                        \
      return ftor(buffer.data(), buffer.size());                               \
    }                                                                          \
  };


// ****************************************************************************
//  Bit Fields ****************************************************************
// ****************************************************************************
#define DECLARE_BIT_SET_HEADER(T,C)                                            \
  struct C;                                                                    \
  template <>                                                                  \
  struct ContainerSize<C>                                                      \
    : std::integral_constant<size_t, sizeof(T)>         { };                   \
                                                                               \
  template <>                                                                  \
  struct detail::field_data_t<C>  { typedef T value_type; };                   \
                                                                               \
  struct C                                                                     \
    : public BasicBitList<T,C>                                                 \
  {                                                                            \
    typedef C                                     this_type;                   \
    typedef T                                     value_type;                  \
    typedef BitField<0,0,value_type>              nil_bits_t;                  \
    typedef BasicBitList<T,C>                     base_type;                   \
                                                                               \
    C()                                                                        \
      : base_type()                                                            \
    { }                                                                        \
                                                                               \
    C(value_type &data_field)                                                  \
      : base_type(data_field)                                                  \
    { }                                                                        \
                                                                               \
    C& operator=(const C &rhs)                                                 \
    { m_data = rhs.m_data;                                                     \
      return *this;                                                            \
    }                                                                          \
    C& operator=(const value_type &data_field)                                 \
    { m_data = data_field;                                                     \
      return *this;                                                            \
    }                                                                          \
                                                                               \
    enum { k_offset_0 = 0 };                                                   \
                                                                               \
    template <typename IndexT,                                                 \
              typename BitT>                                                   \
    BitT& GetField(const BitT &)                                               \
    { return GetFieldAddress(BitT()); }                                        \
                                                                               \
    nil_bits_t& GetFieldAddress(const nil_bits_t&)                             \
    {                                                                          \
      static nil_bits_t nil_bits;                                              \
      return nil_bits;                                                         \
    }

 
// *****************************************************************************
#define DECLARE_BIT_FIELD(IDX,P,N)                                             \
  typedef FieldIndex< IDX, this_type,N> idx_##IDX;                             \
  typedef BitField  < k_offset_##IDX, N, value_type > P##_t;                   \
  enum { TMP_PASTE(k_offset_, TMP_INC(IDX)) = k_offset_##IDX + N };            \
                                                                               \
  P##_t P;                                                                     \
  P##_t& GetFieldAddress(const P##_t&)               { return P; }


// *****************************************************************************
#define DECLARE_BIT_SET_FOOTER          };


#endif
