/// @file using_Hg.h
/// 
/// Implements message parsing by using Hg. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef USING_HG_H_INCLUDED
#define USING_HG_H_INCLUDED
//  Includes *******************************************************************
#include <benchmark_util.h>
#include <benchmark_formats.h>

namespace alchemy
{
namespace benchmark
{

struct UsingHg
{
  static 
    void test_basic(DataBuffer &data,
                    DataBuffer &out);

  static 
    void test_packed_bits(DataBuffer &data);

  static 
    void test_unaligned(DataBuffer &data);

  static 
    void test_complex(DataBuffer &data);

};

} // benchmark
} // alchemy


#endif
