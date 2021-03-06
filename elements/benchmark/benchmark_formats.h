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
//  ****************************************************************************
ALCHEMY_PACKED 
( uint32_t, 
  SetA,
  ALCHEMY_BITS   (0,   fifteen, 15),
  ALCHEMY_BITS   (1,   two,     2),
  ALCHEMY_BITS   (2,   five,    5),
  ALCHEMY_BITS   (3,   eight,   8),
  ALCHEMY_BITS   (4,   one,     1)
);

//  ****************************************************************************
ALCHEMY_PACKED 
( uint16_t, 
  SetB,
  ALCHEMY_BITS   (0,   first,   4),
  ALCHEMY_BITS   (1,   second,  4),
  ALCHEMY_BITS   (2,   third,   4),
  ALCHEMY_BITS   (3,   fourth,  4)
);

//  ****************************************************************************
ALCHEMY_PACKED 
( uint8_t, 
  SetC,
  ALCHEMY_BITS   (0,   a, 1),
  ALCHEMY_BITS   (1,   b, 1),
  ALCHEMY_BITS   (2,   c, 1),
  ALCHEMY_BITS   (3,   d, 1),
  ALCHEMY_BITS   (4,   e, 1),
  ALCHEMY_BITS   (5,   f, 1),
  ALCHEMY_BITS   (6,   g, 1),
  ALCHEMY_BITS   (7,   h, 1)
);


ALCHEMY_STRUCT(NoConversion,
  ALCHEMY_DATUM(uint32_t, ch_0),
  ALCHEMY_DATUM(uint32_t, ch_1),
  ALCHEMY_DATUM(uint32_t, ch_2),
  ALCHEMY_DATUM(uint32_t, ch_3),
  ALCHEMY_DATUM(uint32_t, ch_4),
  ALCHEMY_DATUM(uint32_t, ch_5),
  ALCHEMY_DATUM(uint32_t, ch_6),
  ALCHEMY_DATUM(uint32_t, ch_7),
  ALCHEMY_DATUM(uint32_t, ch_8),
  ALCHEMY_DATUM(uint32_t, ch_9),
  ALCHEMY_DATUM(uint32_t, ch_10),
  ALCHEMY_DATUM(uint32_t, ch_11),
  ALCHEMY_DATUM(uint32_t, ch_12),
  ALCHEMY_DATUM(uint32_t, ch_13),
  ALCHEMY_DATUM(uint32_t, ch_14),
  ALCHEMY_DATUM(uint32_t, ch_15)
);

//  ****************************************************************************
ALCHEMY_STRUCT(Basic,
  ALCHEMY_DATUM(int32_t,         i32),
  ALCHEMY_DATUM(uint32_t,        u32),
  ALCHEMY_DATUM(int16_t,         i16),
  ALCHEMY_DATUM(uint16_t,        u16),
  ALCHEMY_DATUM(char,            ch),
  ALCHEMY_DATUM(uint8_t,         u8)
);

//  ****************************************************************************
ALCHEMY_STRUCT(Packed,
  ALCHEMY_DATUM(SetA,            set_a),
  ALCHEMY_DATUM(SetB,            set_b),
  ALCHEMY_DATUM(SetC,            set_c)
);

//  ****************************************************************************
ALCHEMY_STRUCT(Unaligned,
  ALCHEMY_DATUM(char,            ch),
  ALCHEMY_DATUM(uint32_t,        u32_a),
  ALCHEMY_DATUM(uint32_t,        u32_b),
  ALCHEMY_DATUM(uint32_t,        u32_c),
  ALCHEMY_DATUM(int16_t,         i16_a),
  ALCHEMY_DATUM(int16_t,         i16_b),
  ALCHEMY_DATUM(int16_t,         i16_c)
);

//  ****************************************************************************
ALCHEMY_STRUCT(Complex,
  ALCHEMY_DATUM(uint32_t,                  seq),
  ALCHEMY_ARRAY(Basic, alchemy::benchmark::k_complex_basic_count, basic),
  ALCHEMY_DATUM(Packed,                    bits),
  ALCHEMY_DATUM(Unaligned,                 unaligned)
);

//  ****************************************************************************
ALCHEMY_STRUCT(Array_test,
  ALCHEMY_ARRAY(uint32_t, alchemy::benchmark::k_array_test_count,   items)
);





#endif  
