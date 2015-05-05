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

//  ****************************************************************************
//  A triangle represents a simple polygon surface with a front-facing normal.
//  This format represents a nested type with an array sub-type.
//  The array sub-type only holds simple types.
// 
HG_BEGIN_FORMAT(triangle_t,
  HG_ARRAY (uint16_t, 3,  pts),
  HG_DATUM (ray_t,        normal)
);

//  ****************************************************************************
//  Sub-type definition used to represent a camera.
//  This gives three points required to create the eye vector with 
//  scene orientation.
// 
HG_BEGIN_FORMAT(camera_t,
  HG_DATUM      (pt3d_t, eye),
  HG_DATUM      (pt3d_t, at),
  HG_DATUM      (pt3d_t, up)
);

//  ****************************************************************************
//  A polygon is a collection of triangle references to create a single body.
//  This type represents a nested type with a vector sub-type.
//  The vector sub-type holds a nested sub-type;
// 
HG_BEGIN_FORMAT(object_t,
  HG_DATUM    (uint32_t,          count),
  HG_DYNAMIC  (triangle_t, count, surfaces)
);

//  ****************************************************************************
//  
// 
typedef std::array<double,  3>          row_t;
typedef std::array<row_t,   3>          matrix_t;

//  ****************************************************************************
//  
// 
HG_BEGIN_FORMAT(instance_t,
  HG_DATUM      (uint8_t,   object_index),
  HG_DATUM      (pt3d_t,    location),
  HG_DATUM      (matrix_t,  transform)
);


//  ****************************************************************************
//  Top-level world defintiion.
//  This object is a complex object that contains nested sub-types, vectors
//  that contain nested sub-types that contain arrays or vectors, as well
//  as simple-types and bit-sets.
//
HG_BEGIN_FORMAT(world_t,
  HG_DATUM    (uint16_t,                  width),
  HG_DATUM    (uint16_t,                  height),
  HG_DATUM    (camera_t,                  camera),
  HG_DATUM    (uint16_t,                  fov),
  HG_DATUM    (color4,                    ambient),
  HG_DATUM    (vertex_t,                  light),
  HG_DATUM    (uint8_t,                   object_count),
  HG_DYNAMIC  (object_t, object_count,    objects),
  HG_DATUM    (uint8_t,                   instance_count),
  HG_DYNAMIC  (instance_t, instance_count, instances)
);

#endif
