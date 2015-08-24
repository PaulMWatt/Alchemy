//  @file BenchmarkCarbonDefs.h
//  
//  Carbon benchmark definition types.
// 
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef CARBON_TEST_DEFS_H_INCLUDED
#define CARBON_TEST_DEFS_H_INCLUDED
#include <Carbon.h>
#include <../benchmark/benchmark_formats.h>


//  ****************************************************************************
//  A MACRO declaration like this is required for every Carbon library.
//  This informs Carbon which struct types to generate and export conversions.
//
C_DECLARE_EXPORTED_TYPES
(
  NoConversion,
  Basic,
  Packed,
  Unaligned,
  Complex,
  Array_test
);

#endif

