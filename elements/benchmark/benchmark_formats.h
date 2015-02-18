/// @file benchmark_formats.h
/// 
/// The formats of the structures used in the benchmark tests. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BENCHMARK_FORMATS_H_INCLUDED
#define BENCHMARK_FORMATS_H_INCLUDED
//  Includes *******************************************************************
#include <Hg.h>


namespace alchemy
{
namespace benchmark
{

#pragma pack(push)
#pragma pack(1)

//  ****************************************************************************
struct Basic
{
  int32_t         i32;
  uint32_t        u32;
  int16_t         i16;
  uint16_t        u16;
  char            ch;
  uint8_t         u8;
};


//  ****************************************************************************
//
//  Set A:    15-bits     fifteen
//            2-bits      two
//            5-bits      five
//            8-bits      eight
//            1-bit       one
//
//  Set B:    4-bits      first
//            4-bits      second
//            4-bits      third
//            4-bits      fourth
//
//  Set C:    1-bit       a
//            1-bit       b
//            1-bit       c
//            1-bit       d
//            1-bit       e
//            1-bit       f
//            1-bit       g
//            1-bit       h
//
struct Packed
{
  uint32_t        set_a;
  uint16_t        set_b;
  uint8_t         set_c;
};


//  ****************************************************************************
struct Unaligned
{
  char            ch;
  uint32_t        u32_a;
  uint32_t        u32_b;
  uint32_t        u32_c;
  int16_t         i16_a;
  int16_t         i16_b;
  int16_t         i16_c;
};


//  ****************************************************************************
struct Complex
{
  uint32_t        seq;
  Basic           basic[3];
  Packed          bits;
  Unaligned       unaligned;
};
#pragma pack(pop)

} // benchmark
} // alchemy


//  The Hg equivalent definitions of the structures defined above. *************
namespace Hg
{

//  ****************************************************************************
typedef TypeList
<
  int32_t,
  uint32_t,
  int16_t,
  uint16_t,
  char,
  uint8_t
> Basic;


HG_BEGIN_PACKED (uint32_t, SetA)
  HG_BIT_FIELD   (0,   fifteen, 15)
  HG_BIT_FIELD   (1,   two,     2)
  HG_BIT_FIELD   (2,   five,    5)
  HG_BIT_FIELD   (3,   eight,   8)
  HG_BIT_FIELD   (4,   one,     1)
HG_END_PACKED

HG_BEGIN_PACKED (uint16_t, SetB)
  HG_BIT_FIELD   (0,   first,   4)
  HG_BIT_FIELD   (1,   second,  4)
  HG_BIT_FIELD   (2,   third,   4)
  HG_BIT_FIELD   (3,   fourth,  4)
HG_END_PACKED

HG_BEGIN_PACKED (uint8_t, SetC)
  HG_BIT_FIELD   (0,   a, 1)
  HG_BIT_FIELD   (1,   b, 1)
  HG_BIT_FIELD   (2,   c, 1)
  HG_BIT_FIELD   (3,   d, 1)
  HG_BIT_FIELD   (4,   e, 1)
  HG_BIT_FIELD   (5,   f, 1)
  HG_BIT_FIELD   (6,   g, 1)
  HG_BIT_FIELD   (7,   h, 1)
HG_END_PACKED


//  ****************************************************************************
typedef TypeList
<
  SetA,
  SetB,
  SetC
> Packed;



//  ****************************************************************************
typedef TypeList
<
  char,
  uint32_t,
  uint32_t,
  uint32_t,
  int16_t,
  int16_t,
  int16_t
> Unaligned;


//  ****************************************************************************
typedef TypeList
<
  uint32_t,
  std::array<Basic,3>,
  Packed,
  Unaligned
> Complex;

typedef TypeList
<
  uint32_t,
  uint32_t,
  uint32_t,
  std::array<uint32_t,20>
> no_dyn_format_t;

//  ****************************************************************************
//HG_BEGIN_FORMAT(Basic)
//  HG_DATUM(int32_t,         i32)
//  HG_DATUM(uint32_t,        u32)
//  HG_DATUM(int16_t,         i16)
//  HG_DATUM(uint16_t,        u16)
//  HG_DATUM(char,            ch)
//  HG_DATUM(uint8_t,         u8)
//HG_END_FORMAT(Basic);

typedef Hg::make_Hg_type_list<Basic>::type Basic_Hg; struct Basic_HgFormat : nested_trait { typedef Basic_HgFormat this_type; typedef Basic_Hg format_type; enum { k_size = SizeOf<format_type>::value }; enum { k_length = length<format_type>::value }; template< size_t IDX> Datum<IDX, format_type>& FieldAt() { typedef Datum < IDX, format_type> datum_type_t; return FieldAtIndex((datum_type_t*)0); } template< size_t IDX> const Datum<IDX, format_type>& const_FieldAt() const { return const_cast<Basic_HgFormat*>(this)->FieldAt(); } template<size_t I> struct TypeAtIndex; static const size_t k_enum_base = 0 + 1;
   typedef Hg::detail::DeduceProxyType < ((1 - k_enum_base)), format_type>::type Proxyi32; typedef Proxyi32::datum_type datum_i32; Proxyi32 i32; datum_i32& FieldAtIndex(const datum_i32*) { return *static_cast<datum_i32*>(&i32); } const char* FieldName(const Proxyi32&) { return "i32"; } template<> struct TypeAtIndex<((1 - k_enum_base))> { typedef int32_t type; };
   typedef Hg::detail::DeduceProxyType < ((2 - k_enum_base)), format_type>::type Proxyu32; typedef Proxyu32::datum_type datum_u32; Proxyu32 u32; datum_u32& FieldAtIndex(const datum_u32*) { return *static_cast<datum_u32*>(&u32); } const char* FieldName(const Proxyu32&) { return "u32"; } template<> struct TypeAtIndex<((2 - k_enum_base))> { typedef uint32_t type; };
   typedef Hg::detail::DeduceProxyType < ((3 - k_enum_base)), format_type>::type Proxyi16; typedef Proxyi16::datum_type datum_i16; Proxyi16 i16; datum_i16& FieldAtIndex(const datum_i16*) { return *static_cast<datum_i16*>(&i16); } const char* FieldName(const Proxyi16&) { return "i16"; } template<> struct TypeAtIndex<((3 - k_enum_base))> { typedef int16_t type; };
   typedef Hg::detail::DeduceProxyType < ((4 - k_enum_base)), format_type>::type Proxyu16; typedef Proxyu16::datum_type datum_u16; Proxyu16 u16; datum_u16& FieldAtIndex(const datum_u16*) { return *static_cast<datum_u16*>(&u16); } const char* FieldName(const Proxyu16&) { return "u16"; } template<> struct TypeAtIndex<((4 - k_enum_base))> { typedef uint16_t type; };
   typedef Hg::detail::DeduceProxyType < ((5 - k_enum_base)), format_type>::type Proxych; typedef Proxych::datum_type datum_ch; Proxych ch; datum_ch& FieldAtIndex(const datum_ch*) { return *static_cast<datum_ch*>(&ch); } const char* FieldName(const Proxych&) { return "ch"; } template<> struct TypeAtIndex<((5 - k_enum_base))> { typedef char type; };
   typedef Hg::detail::DeduceProxyType < ((6 - k_enum_base)), format_type>::type Proxyu8; typedef Proxyu8::datum_type datum_u8; Proxyu8 u8; datum_u8& FieldAtIndex(const datum_u8*) { return *static_cast<datum_u8*>(&u8); } const char* FieldName(const Proxyu8&) { return "u8"; } template<> struct TypeAtIndex<((6 - k_enum_base))> { typedef uint8_t type; };
private: 
  template <typename T, typename U> size_t DatumSize(T value, U*) { return value; } 
  template <typename U> size_t DatumSize(pfnGetDatumSize ftor, U* buffer) { if (buffer->empty()) { return 0; } return ftor(buffer->data(), buffer->size()); } 

public: 
  typedef 
    detail::DeduceMsgTypeList 
    < this_type, 
      ((7 - k_enum_base) - 1) 
    >::type                     format_type_2; 
}; 

namespace detail { template <> struct field_data_t <Basic> { typedef Basic_HgFormat value_type; }; };


//  ****************************************************************************
HG_BEGIN_FORMAT(Packed)
  HG_DATUM(SetA,            set_a)
  HG_DATUM(SetB,            set_b)
  HG_DATUM(SetC,            set_c)
HG_END_FORMAT(Packed);

//  ****************************************************************************
HG_BEGIN_FORMAT(Unaligned)
  HG_DATUM(char,            ch)
  HG_DATUM(uint32_t,        u32_a)
  HG_DATUM(uint32_t,        u32_b)
  HG_DATUM(uint32_t,        u32_c)
  HG_DATUM(int16_t,         i16_a)
  HG_DATUM(int16_t,         i16_b)
  HG_DATUM(int16_t,         i16_c)
HG_END_FORMAT(Unaligned);

//  ****************************************************************************
HG_BEGIN_FORMAT(Complex)
  HG_DATUM(uint32_t,        seq)
  HG_ARRAY(Basic, 3,        basic)
  HG_DATUM(PackedBits,      bits)
  HG_DATUM(Unaligned,       unaligned)
HG_END_FORMAT(Complex);

} // namespace Hg






#endif  
