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

namespace Hg
{

//  Simple Types ***************************************************************
//  ****************************************************************************
//  Bitset definition to represent 4-channel color value.  
// 
HG_BEGIN_BIT_SET (uint32_t, color4)
  HG_BIT_FIELD   (0,   R, 8)
  HG_BIT_FIELD   (1,   G, 8)
  HG_BIT_FIELD   (2,   B, 8)
  HG_BIT_FIELD   (3,   A, 8)
HG_END_BIT_SET


//  ****************************************************************************
//  Indexed Color Table
//  This type represents a fixed-size array of bit-fields.
// 
typedef TypeList
<
  std::array<color4, 16>
> color_map_t;

HG_BEGIN_FORMAT(color_map_t)
  HG_ARRAY (color4, 16, table)
HG_END_FORMAT

//  ****************************************************************************
//  Type definition that represents a 3-dimensional point.
//  This type is a nested type with simple sub-types.
// 
typedef TypeList
<
  int32_t,      
  int32_t,      
  int32_t      
> pt3d_t;

HG_BEGIN_FORMAT(pt3d_t)
  HG_DATUM (int32_t, X)
  HG_DATUM (int32_t, Y)
  HG_DATUM (int32_t, Z)
HG_END_FORMAT

//  ****************************************************************************
//  Type definition to represent a mathematical vector.
//  A starting point and a magnitude.
//  This format covers a nested type with nested sub-types.
// 
typedef TypeList
<
  pt3d_t,      
  pt3d_t      
> ray_t;

HG_BEGIN_FORMAT(ray_t)
  HG_DATUM (pt3d_t, start)
  HG_DATUM (pt3d_t, magnitude)
HG_END_FORMAT

//  ****************************************************************************
//  A single point with with a specified color.
//  This format covers a nested type that contains a nested type and a bit-list.
// 
typedef TypeList
<
  pt3d_t,      
  color4      
> vertex_t;

HG_BEGIN_FORMAT(vertex_t)
  HG_DATUM (pt3d_t, pt)
  HG_DATUM (color4, color)
HG_END_FORMAT

//  ****************************************************************************
//  A triangle represents a simple polygon surface with a front-facing normal.
//  This format represents a nested type with an array sub-type.
//  The array sub-type only holds simple types.
// 
typedef TypeList
<
  std::array<uint16_t, 3>,
  ray_t
> triangle_t;

HG_BEGIN_FORMAT(triangle_t)
  HG_ARRAY (uint16_t, 3,  pts)
  HG_DATUM (ray_t,        normal)
HG_END_FORMAT

//  ****************************************************************************
//  Sub-type definition used to represent a camera.
//  This gives three points required to create the eye vector with 
//  scene orientation.
// 
typedef TypeList
<
  pt3d_t,
  pt3d_t,
  pt3d_t
> camera_t;

HG_BEGIN_FORMAT(camera_t)
  HG_DATUM      (pt3d_t, eye)
  HG_DATUM      (pt3d_t, at)
  HG_DATUM      (pt3d_t, up)
HG_END_FORMAT

//  ****************************************************************************
//  A polygon is a collection of triangle references to create a single body.
//  This type represents a nested type with a vector sub-type.
//  The vector sub-type holds a nested sub-type;
// 
typedef TypeList
<
  uint32_t,
  std::vector<triangle_t>
> object_t;

HG_BEGIN_FORMAT(object_t)
  HG_DATUM    (uint32_t,          count)
  HG_DYNAMIC  (triangle_t, count, surfaces)
HG_END_FORMAT

//  ****************************************************************************
//  
// 
typedef std::array<double,  3>          row_t;
typedef std::array<row_t,   3>          matrix_t;

//  ****************************************************************************
//  
// 
typedef TypeList
<
  uint8_t,
  pt3d_t,
  matrix_t
> instance_t;

HG_BEGIN_FORMAT(instance_t)
  HG_DATUM      (uint8_t,   object_index)
  HG_DATUM      (pt3d_t,    location)
  HG_DATUM      (matrix_t,  transform)
HG_END_FORMAT


//  ****************************************************************************
//  Top-level world defintiion.
//  This object is a complex object that contains nested sub-types, vectors
//  that contain nested sub-types that contain arrays or vectors, as well
//  as simple-types and bit-sets.
//
typedef TypeList
<
  uint16_t,
  uint16_t,
  camera_t,
  uint16_t,
  color4,
  vertex_t,
  uint8_t,
  std::vector<object_t>,
  uint8_t,
  std::vector<instance_t>
> world_t;

HG_BEGIN_FORMAT(world_t)
  HG_DATUM    (uint16_t,                  width)
  HG_DATUM    (uint16_t,                  height)
  HG_DATUM    (camera_t,                  camera)
  HG_DATUM    (uint16_t,                  fov)
  HG_DATUM    (color4,                    ambient)
  HG_DATUM    (vertex_t,                  light)
  HG_DATUM    (uint8_t,                   object_count)
  HG_DYNAMIC  (object_t, object_count,    objects)
  HG_DATUM    (uint8_t,                   instance_count)
  HG_DYNAMIC  (instance_t, instance_count, instances)
HG_END_FORMAT

} // namespace Hg


#endif
