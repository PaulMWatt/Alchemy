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
struct PackedBits
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
  PackedBits      bits;
  Unaligned       unaligned;
};
#pragma pack(push)

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


HG_BEGIN_BIT_SET (uint32_t, SetA)
  HG_BIT_FIELD   (SetA, 0,   fifteen, 15)
  HG_BIT_FIELD   (SetA, 1,   two,     2)
  HG_BIT_FIELD   (SetA, 2,   five,    5)
  HG_BIT_FIELD   (SetA, 3,   eight,   8)
  HG_BIT_FIELD   (SetA, 4,   one,     1)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint16_t, SetB)
  HG_BIT_FIELD   (SetB, 0,   first,   4)
  HG_BIT_FIELD   (SetB, 1,   second,  4)
  HG_BIT_FIELD   (SetB, 2,   third,   4)
  HG_BIT_FIELD   (SetB, 3,   fourth,  4)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint8_t, SetC)
  HG_BIT_FIELD   (SetC, 0,   a, 1)
  HG_BIT_FIELD   (SetC, 1,   b, 1)
  HG_BIT_FIELD   (SetC, 2,   c, 1)
  HG_BIT_FIELD   (SetC, 3,   d, 1)
  HG_BIT_FIELD   (SetC, 4,   e, 1)
  HG_BIT_FIELD   (SetC, 5,   f, 1)
  HG_BIT_FIELD   (SetC, 6,   g, 1)
  HG_BIT_FIELD   (SetC, 7,   h, 1)
HG_END_BIT_SET


//  ****************************************************************************
typedef TypeList
<
  SetA,
  SetB,
  SetC
> PackedBits;



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
  PackedBits,
  Unaligned
> Complex;

//  ****************************************************************************
HG_BEGIN_FORMAT(Basic)
  HG_DATUM(int32_t,         i32)
  HG_DATUM(uint32_t,        u32)
  HG_DATUM(int16_t,         i16)
  HG_DATUM(uint16_t,        u16)
  HG_DATUM(char,            ch)
  HG_DATUM(uint8_t,         u8)
HG_END_FORMAT(Basic);

//  ****************************************************************************
HG_BEGIN_FORMAT(PackedBits)
  HG_DATUM(SetA,            set_a)
  HG_DATUM(SetB,            set_b)
  HG_DATUM(SetC,            set_c)
HG_END_FORMAT(PackedBits);

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
