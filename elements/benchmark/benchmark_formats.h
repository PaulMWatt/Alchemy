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

const size_t k_complex_basic_count = 4;
const size_t k_array_test_count    = 256;



#pragma pack(push)
#pragma pack(1)

//  ****************************************************************************
struct NoConversion
{
  uint32_t            ch_0;
  uint32_t            ch_1;
  uint32_t            ch_2;
  uint32_t            ch_3;
  uint32_t            ch_4;
  uint32_t            ch_5;
  uint32_t            ch_6;
  uint32_t            ch_7;
  uint32_t            ch_8;
  uint32_t            ch_9;
  uint32_t            ch_10;
  uint32_t            ch_11;
  uint32_t            ch_12;
  uint32_t            ch_13;
  uint32_t            ch_14;
  uint32_t            ch_15;
};

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
  Basic           basic[k_complex_basic_count];
  Packed          bits;
  Unaligned       unaligned;
};


//  ****************************************************************************
struct Array
{
  uint32_t        items[k_array_test_count];
};


#pragma pack(pop)

} // benchmark
} // alchemy


//  The Hg equivalent definitions of the structures defined above. *************
namespace Hg
{

//  ****************************************************************************
HG_BEGIN_PACKED (uint32_t, SetA)
  HG_BIT_FIELD   (0,   fifteen, 15)
  HG_BIT_FIELD   (1,   two,     2)
  HG_BIT_FIELD   (2,   five,    5)
  HG_BIT_FIELD   (3,   eight,   8)
  HG_BIT_FIELD   (4,   one,     1)
HG_END_PACKED

//  ****************************************************************************
HG_BEGIN_PACKED (uint16_t, SetB)
  HG_BIT_FIELD   (0,   first,   4)
  HG_BIT_FIELD   (1,   second,  4)
  HG_BIT_FIELD   (2,   third,   4)
  HG_BIT_FIELD   (3,   fourth,  4)
HG_END_PACKED

//  ****************************************************************************
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


HG_BEGIN_FORMAT(NoConversion,
  HG_DATUM(uint32_t, ch_0),
  HG_DATUM(uint32_t, ch_1),
  HG_DATUM(uint32_t, ch_2),
  HG_DATUM(uint32_t, ch_3),
  HG_DATUM(uint32_t, ch_4),
  HG_DATUM(uint32_t, ch_5),
  HG_DATUM(uint32_t, ch_6),
  HG_DATUM(uint32_t, ch_7),
  HG_DATUM(uint32_t, ch_8),
  HG_DATUM(uint32_t, ch_9),
  HG_DATUM(uint32_t, ch_10),
  HG_DATUM(uint32_t, ch_11),
  HG_DATUM(uint32_t, ch_12),
  HG_DATUM(uint32_t, ch_13),
  HG_DATUM(uint32_t, ch_14),
  HG_DATUM(uint32_t, ch_15)
);

//  ****************************************************************************
HG_BEGIN_FORMAT(Basic,
  HG_DATUM(int32_t,         i32),
  HG_DATUM(uint32_t,        u32),
  HG_DATUM(int16_t,         i16),
  HG_DATUM(uint16_t,        u16),
  HG_DATUM(char,            ch),
  HG_DATUM(uint8_t,         u8)
);

//  ****************************************************************************
HG_BEGIN_FORMAT(Packed,
  HG_DATUM(SetA,            set_a),
  HG_DATUM(SetB,            set_b),
  HG_DATUM(SetC,            set_c)
);

//  ****************************************************************************
HG_BEGIN_FORMAT(Unaligned,
  HG_DATUM(char,            ch),
  HG_DATUM(uint32_t,        u32_a),
  HG_DATUM(uint32_t,        u32_b),
  HG_DATUM(uint32_t,        u32_c),
  HG_DATUM(int16_t,         i16_a),
  HG_DATUM(int16_t,         i16_b),
  HG_DATUM(int16_t,         i16_c)
);

//  ****************************************************************************
HG_BEGIN_FORMAT(Complex,
  HG_DATUM(uint32_t,                  seq),
  HG_ARRAY(Basic, alchemy::benchmark::k_complex_basic_count, basic),
  HG_DATUM(Packed,                    bits),
  HG_DATUM(Unaligned,                 unaligned)
);

//  ****************************************************************************
HG_BEGIN_FORMAT(Array_test,
  HG_ARRAY(uint32_t, alchemy::benchmark::k_array_test_count,   items)
);

} // namespace Hg






#endif  
