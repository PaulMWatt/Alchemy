//  @file Geometry_TypeList.h
//  
//  This is a helper file for a series of tests of combinations of sub-types.
// 
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef GEOMETRY_TYPELIST_H_INCLUDED
#define GEOMETRY_TYPELIST_H_INCLUDED
#include <alchemy.h>

//  Simple Types ***************************************************************
//  ****************************************************************************
//  Bitset definition to represent 4-channel color value.  
// 
ALCHEMY_PACKED 
( uint32_t, 
  color4,
  ALCHEMY_BITS   (0,   R, 8),
  ALCHEMY_BITS   (1,   G, 8),
  ALCHEMY_BITS   (2,   B, 8),
  ALCHEMY_BITS   (3,   A, 8)
);


//  ****************************************************************************
//  Indexed Color Table
//  This type represents a fixed-size array of bit-fields.
// 
ALCHEMY_STRUCT(color_map_t,
  ALCHEMY_ARRAY (color4, 16, table)
);

//  ****************************************************************************
//  Type definition that represents a 3-dimensional point.
//  This type is a nested type with simple sub-types.
// 
ALCHEMY_STRUCT(pt3d_t,
  ALCHEMY_DATUM (int32_t, X),
  ALCHEMY_DATUM (int32_t, Y),
  ALCHEMY_DATUM (int32_t, Z)
);

//  ****************************************************************************
//  Type definition to represent a mathematical vector.
//  A starting point and a magnitude.
//  This format covers a nested type with nested sub-types.
// 
ALCHEMY_STRUCT(ray_t,
  ALCHEMY_DATUM (pt3d_t, start),
  ALCHEMY_DATUM (pt3d_t, magnitude)
);

//  ****************************************************************************
//  A single point with with a specified color.
//  This format covers a nested type that contains a nested type and a bit-list.
// 
ALCHEMY_STRUCT(vertex_t,
  ALCHEMY_DATUM (pt3d_t, pt),
  ALCHEMY_DATUM (color4, color)
);

//  ****************************************************************************
//  A triangle represents a simple polygon surface with a front-facing normal.
//  This format represents a nested type with an array sub-type.
//  The array sub-type only holds simple types.
// 
ALCHEMY_STRUCT(triangle_t,
  ALCHEMY_ARRAY (uint16_t, 3,  pts),
  ALCHEMY_DATUM (ray_t,        normal)
);

//  ****************************************************************************
//  Sub-type definition used to represent a camera.
//  This gives three points required to create the eye vector with 
//  scene orientation.
// 
ALCHEMY_STRUCT(camera_t,
  ALCHEMY_DATUM      (pt3d_t, eye),
  ALCHEMY_DATUM      (pt3d_t, at),
  ALCHEMY_DATUM      (pt3d_t, up)
);

//  ****************************************************************************
//  A polygon is a collection of triangle references to create a single body.
//  This type represents a nested type with a vector sub-type.
//  The vector sub-type holds a nested sub-type;
// 
ALCHEMY_STRUCT(object_t,
  ALCHEMY_DATUM    (uint32_t,          count),
  ALCHEMY_ALLOC  (triangle_t, count, surfaces)
);

//  ****************************************************************************
#if defined(ALCHEMY_CARBONATE)

ALCHEMY_STRUCT(row_t,
  ALCHEMY_ARRAY      (double, 3, col)
);

ALCHEMY_STRUCT(matrix_t,
  ALCHEMY_ARRAY      (row_t,  3, row)
);

#else

// TODO: There is an issue that will not allow multi-dimensional arrays
//       to be created by alchemy definitions. This must be resolved.

typedef std::array<double,  3>          row_t;
typedef std::array<row_t,   3>          matrix_t;

#endif

//  ****************************************************************************
//  
// 
ALCHEMY_STRUCT(instance_t,
  ALCHEMY_DATUM      (uint8_t,   object_index),
  ALCHEMY_DATUM      (pt3d_t,    location),
  ALCHEMY_DATUM      (matrix_t,  transform)
);


//  ****************************************************************************
//  Top-level world defintiion.
//  This object is a complex object that contains nested sub-types, vectors
//  that contain nested sub-types that contain arrays or vectors, as well
//  as simple-types and bit-sets.
//
ALCHEMY_STRUCT(world_t,
  ALCHEMY_DATUM    (uint16_t,                  width),
  ALCHEMY_DATUM    (uint16_t,                  height),
  ALCHEMY_DATUM    (camera_t,                  camera),
  ALCHEMY_DATUM    (uint16_t,                  fov),
  ALCHEMY_DATUM    (color4,                    ambient),
  ALCHEMY_DATUM    (vertex_t,                  light),
  ALCHEMY_DATUM    (uint8_t,                   object_count),
  ALCHEMY_ALLOC    (object_t, object_count,    objects),
  ALCHEMY_DATUM    (uint8_t,                   instance_count),
  ALCHEMY_ALLOC    (instance_t, instance_count, instances)
);

#endif
