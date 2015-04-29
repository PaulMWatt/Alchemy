/// @file using_memcpy.h
/// 
/// Implements message parsing by using memcpy when possible. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef USING_MEMCPY_H_INCLUDED
#define USING_MEMCPY_H_INCLUDED
//  Includes *******************************************************************
#include <benchmark_util.h>
#include <benchmark_formats.h>

namespace alchemy
{
namespace benchmark
{

struct UsingMemcpy
{
  static 
    void test_no_conversion(DataBuffer &data,
                            DataBuffer &out);

  static 
    void test_basic(DataBuffer &data,
                    DataBuffer &out);

  static 
    void test_packed_bits(DataBuffer &data,
                          DataBuffer &out);

  static 
    void test_unaligned(DataBuffer &data,
                        DataBuffer &out);

  static 
    void test_complex(DataBuffer &data,
                      DataBuffer &out);

  static 
    void test_array(DataBuffer &data,
                      DataBuffer &out);
};

} // benchmark
} // alchemy


#endif
