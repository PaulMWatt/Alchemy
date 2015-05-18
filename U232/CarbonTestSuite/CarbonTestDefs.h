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


//  Simple Types ***************************************************************
//  ****************************************************************************
//  Bitset definition to represent 4-channel color value.  
// 
ALCHEMY_PACKED 
( uint32_t, color4,
  ALCHEMY_BITS   (0,   R, 8),
  ALCHEMY_BITS   (1,   G, 8),
  ALCHEMY_BITS   (2,   B, 8),
  ALCHEMY_BITS   (3,   A, 8)
);


//  ****************************************************************************
//  Indexed Color Table
//  This type represents a fixed-size array of bit-fields.
// 
ALCHEMY_STRUCT( color_map_t,
  ALCHEMY_ARRAY (color4, 16, table)
);


//  ****************************************************************************
//  Type definition that represents a 3-dimensional point.
//  This type is a nested type with simple sub-types.
// 
ALCHEMY_STRUCT( pt3d_t,
  ALCHEMY_DATUM (int32_t, X),
  ALCHEMY_DATUM (int32_t, Y),
  ALCHEMY_DATUM (int32_t, Z)
);


//  ****************************************************************************
//  Type definition to represent a mathematical vector.
//  A starting point and a magnitude.
//  This format covers a nested type with nested sub-types.
// 
ALCHEMY_STRUCT( ray_t,
  ALCHEMY_DATUM (pt3d_t, start),
  ALCHEMY_DATUM (pt3d_t, magnitude)
);


//  ****************************************************************************
//  A single point with with a specified color.
//  This format covers a nested type that contains a nested type and a bit-list.
// 
ALCHEMY_STRUCT( vertex_t,
  ALCHEMY_DATUM (pt3d_t, pt),
  ALCHEMY_DATUM (color4, color)
);


//  ****************************************************************************
//  A definition for a triangle surface.
//  The triangle is constructed from 3 points, and a surface normal vector.
// 
ALCHEMY_STRUCT(triangle_t,
  ALCHEMY_ARRAY (uint16_t, 3,  pts),
  ALCHEMY_DATUM (ray_t,        normal)
);


//  ****************************************************************************
//  A camera definition for a 3-dimensional scene.
//  There are 3 points that can be combined to create the orientation vectors
//  for the camera.
// 
ALCHEMY_STRUCT(camera_t,
  ALCHEMY_DATUM      (pt3d_t, eye),
  ALCHEMY_DATUM      (pt3d_t, at),
  ALCHEMY_DATUM      (pt3d_t, up)
);


//  ****************************************************************************
//  Represents a 3-dimensional object. 
//  This type contains fundamental, nested, array and dynamic fields.
// 
ALCHEMY_STRUCT(object_t,
  ALCHEMY_DATUM  (uint32_t,          count),
  ALCHEMY_ALLOC  (triangle_t, count, surfaces)
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
  object_t
);


#endif

