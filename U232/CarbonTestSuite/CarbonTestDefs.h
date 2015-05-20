//  @file CarbonTestDefs.h
//  
//  Test definition types for Carbon.
// 
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef CARBON_TEST_DEFS_H_INCLUDED
#define CARBON_TEST_DEFS_H_INCLUDED
#include <Carbon.h>
#include <U232/common/geometry_typelist.h>

ALCHEMY_STRUCT  ( fundamentals_t,
  ALCHEMY_DATUM (char,  ch),
  ALCHEMY_DATUM (short, s),
  ALCHEMY_DATUM (long,  l),
  ALCHEMY_DATUM (int,   i),
  ALCHEMY_DATUM (unsigned char,  uch),
  ALCHEMY_DATUM (unsigned short, us),
  ALCHEMY_DATUM (unsigned long,  ul),
  ALCHEMY_DATUM (unsigned int,   ui)
);


//  ****************************************************************************
//  A MACRO declaration like this is required for every Carbon library.
//  This informs Carbon which struct types to generate and export conversions.
//
C_DECLARE_EXPORTED_TYPES
(
  color_map_t,
  pt3d_t,
  ray_t,
  vertex_t,
  triangle_t,
  camera_t,
  object_t,
  instance_t,
  world_t
);

#endif

