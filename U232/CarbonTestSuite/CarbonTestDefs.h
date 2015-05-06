//  @file CarbonTestDefs.h
//  
//  Test definition types for Carbon.
// 
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef CARBON_TEST_DEFS_H_INCLUDED
#define CARBON_TEST_DEFS_H_INCLUDED
#include <Carbon.h>


//  Simple Types ***************************************************************
//  ****************************************************************************
//  Bitset definition to represent 4-channel color value.  
// 
HG_BEGIN_PACKED (uint32_t, color4)
  HG_BIT_FIELD   (0,   R, 8)
  HG_BIT_FIELD   (1,   G, 8)
  HG_BIT_FIELD   (2,   B, 8)
  HG_BIT_FIELD   (3,   A, 8)
HG_END_PACKED


//  ****************************************************************************
//  Indexed Color Table
//  This type represents a fixed-size array of bit-fields.
// 
HG_BEGIN_FORMAT(color_map_t,
  HG_ARRAY (color4, 16, table)
);

//  ****************************************************************************
//  Type definition that represents a 3-dimensional point.
//  This type is a nested type with simple sub-types.
// 
HG_BEGIN_FORMAT(pt3d_t,
  HG_DATUM (int32_t, X),
  HG_DATUM (int32_t, Y),
  HG_DATUM (int32_t, Z)
);

//  ****************************************************************************
//  Type definition to represent a mathematical vector.
//  A starting point and a magnitude.
//  This format covers a nested type with nested sub-types.
// 
HG_BEGIN_FORMAT(ray_t,
  HG_DATUM (pt3d_t, start),
  HG_DATUM (pt3d_t, magnitude)
);

//  ****************************************************************************
//  A single point with with a specified color.
//  This format covers a nested type that contains a nested type and a bit-list.
// 
HG_BEGIN_FORMAT(vertex_t,
  HG_DATUM (pt3d_t, pt),
  HG_DATUM (color4, color)
);


#endif

