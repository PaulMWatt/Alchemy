//  @file geometry_testdata.h
//  
//  Data definitions to simplify the declarations of tests.
//
//  The two top-level data constants defined for testing are of type World:
//      k_world
//      k_other_world
//
//  Where k_other_world is defined in the opposite-byte order as k_world.
//
//  There are also two packed memory buffers that contain the data
//  represented by these objects:
//      k_world_buffer
//      k_other_world_buffer
// 
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef GEOMETRY_TESTDATA_H_INCLUDED
#define GEOMETRY_TESTDATA_H_INCLUDED
#include <Alchemy.h>
#include <vector>

namespace test
{
namespace data
{

typedef std::vector<uint8_t>            byte_vector;


// A few basic color definitions
static const uint32_t k_black = 0x00000000;
static const uint32_t k_gray  = 0x7F7F7F00;
static const uint32_t k_white = 0xFFFFFF00;
static const uint32_t k_red   = 0xFF000000;
static const uint32_t k_green = 0x00FF0000;
static const uint32_t k_blue  = 0x0000FF00;
static const uint8_t  k_opaque= 0xFF;
static const uint8_t  k_clear = 0x00;

// Point definitions 
struct point
{
  int32_t X;
  int32_t Y;
  int32_t Z;
};

const point k_cube[8] =
{
  {0,0,0},
  {1,0,0},
  {1,1,0},
  {0,1,0},
  {0,0,1},
  {1,0,1},
  {1,1,1},
  {0,1,1}
};

const point k_eight_pts[8] =
{
  {0xFEEDF00D,0xDEADC0DE,0x0BADF1A6},
  {0xF1A6BALL,0xC0DEBAD0,0xF00DDEAD},
  {0x0BAD0DAD,0xF1A6F00D,0xC0DEF1A6},
  {0xDEADBA11,0x0FEEDBA6,0x0BADA550},
  {0x0A55401E,0xBEEF600D,0x0BADBEEF},
  {0xC0DEF1A6,0x0BADF1A6,0x0FEEDBA6},
  {0x0BADA550,0x0A55401E,0xC0DEBAD0},
  {0x0FEEDBA6,0x0BADA550,0xF1A6BALL}
};

const uint32_t k_eight_colors[8] =
{
  k_white,
  k_red,
  k_gray,
  k_black,
  0xFF881165,
  0x88AD6502,
  0x66554433,
  0x221100CC
};


// Ray definitions
struct Ray
{
  point start;
  point magnitude;
};

const Ray k_normal_x =
{
  {0,0,0},
  {1,0,0}
};

const Ray k_normal_x_neg =
{
  {0, 0,0},
  {-1,0,0}
};

const Ray k_normal_y =
{
  {0,0,0},
  {0,1,0}
};

const Ray k_normal_y_neg =
{
  {0, 0,0},
  {0,-1,0}
};

const Ray k_normal_z =
{
  {0,0,0},
  {0,0,1}
};

const Ray k_normal_z_neg =
{
  {0,0, 0},
  {0,0,-1}
};

// Vertex definitions
struct Vertex
{
  point     pt;
  uint32_t  color;
};

inline
Vertex make_vertex(int32_t X, int32_t Y, int32_t Z, uint32_t color)
{
  Vertex result = {X,Y,Z,color};
  return result;
}

inline
Vertex make_vertex(const point &pt, uint32_t color)
{
  Vertex result = {pt,color};
  return result;
}

inline
void to_buffer(const Vertex &vertex, byte_vector &buffer)
{
  // 1 pt (3 4-byte value) + 1 color (4 bytes)
  const size_t k_org_size    = buffer.size();
  const size_t k_vertex_size = 16;
  buffer.resize(k_org_size + k_vertex_size);

  const size_t k_field_size = sizeof(uint32_t);
  byte_vector::value_type *pCur = &buffer[0];
  std::advance(pCur, k_org_size);

  ::memcpy(pCur, &vertex.pt.X, k_field_size);
  std::advance(pCur, k_field_size);

  ::memcpy(pCur, &vertex.pt.Y, k_field_size);
  std::advance(pCur, k_field_size);

  ::memcpy(pCur, &vertex.pt.Z, k_field_size);
  std::advance(pCur, k_field_size);

  ::memcpy(pCur, &vertex.color, k_field_size);
  std::advance(pCur, k_field_size);
}

//  Triangle definitions
struct Triangle
{
  uint16_t pts[3];
  Ray      normal;
};

inline
Triangle make_triangle( uint16_t first,
                        uint16_t second,
                        uint16_t third,
                        const Ray &normal)
{
  Triangle result;
  result.pts[0] = first;
  result.pts[1] = second;
  result.pts[2] = third;
  result.normal = normal;

  return result;
}

const Triangle k_cube_triangles[12] =
{
  {4,5,7,k_normal_z},
  {0,4,3,k_normal_z_neg},
  {0,1,4,k_normal_y},
  {7,5,6,k_normal_z},
  {4,1,5,k_normal_y_neg},
  {3,4,7,k_normal_z_neg},
  {5,1,2,k_normal_x},
  {0,3,1,k_normal_y},
  {3,6,2,k_normal_x},
  {3,7,6,k_normal_x_neg},
  {2,6,5,k_normal_y_neg},
  {3,2,1,k_normal_x_neg}
};

// Camera definitions.
struct Camera
{
  point eye;
  point at;
  point up;
};

const Camera k_camera = 
{
  {3ul,4ul,5ul},
  {0ul,0ul,0ul},
  {0ul,0ul,1ul}
};

// Object definitions
struct Object
{
  uint32_t          count;
  Triangle const*   surfaces;
};


const Object k_obj_cube = 
{
  12,
  k_cube_triangles
};

// Transformation Matrix declaration.
const double k_transform[9] = 
{
  1,0,0,
  0,1,0,
  0,0,1
};

// Declare an object instance structure.
struct Instance
{
  uint8_t object_index;
  point   location;
  double  transform[3][3];
};


const Instance k_instances[2] =
{
  {0, 0, 0, 0,  {1,0,0,0,1,0,0,0,1}},
  {0, 3, 0, -4, {1,0,0,0,1,0,0,0,1}}
};

const Vertex k_light = make_vertex(-2, 5, -2, k_white);

// A World structure is at the top-level.
struct World
{
  uint16_t        width;
  uint16_t        height;
  Camera          camera;
  uint16_t        fov;
  uint32_t        ambient;
  Vertex          light;
  uint8_t         object_count;
  Object const*   objects;
  uint8_t         instance_count;
  Instance const* instances;
};

// Create two data definitions, 
// Start Byte-order
const World k_world = 
{
  512, 512,
  k_camera,
  90,
  k_gray,
  k_light,
  1, 
  &k_obj_cube,
  2,
  k_instances
};

//  ****************************************************************************
//  Define the set of data that is the opposite byte-order of k_world.
//

const Camera k_other_camera = 
{
  { Hg::EndianSwap(k_camera.eye.X),
    Hg::EndianSwap(k_camera.eye.Y),
    Hg::EndianSwap(k_camera.eye.Z)
  },
  { Hg::EndianSwap(k_camera.at.X),
    Hg::EndianSwap(k_camera.at.Y),
    Hg::EndianSwap(k_camera.at.Z)
  },
  { Hg::EndianSwap(k_camera.up.X),
    Hg::EndianSwap(k_camera.up.Y),
    Hg::EndianSwap(k_camera.up.Z)
  },
};

const Vertex k_other_light = make_vertex( Hg::EndianSwap<int32_t>(-2), 
                                          Hg::EndianSwap<int32_t>(5), 
                                          Hg::EndianSwap<int32_t>(-2), 
                                          Hg::EndianSwap<uint32_t>(k_white));

//  ****************************************************************************
Ray endian_swap_ray(const Ray &ray)
{
  Ray output;
  output.start.X = Hg::EndianSwap<int32_t>(ray.start.X);
  output.start.Y = Hg::EndianSwap<int32_t>(ray.start.Y);
  output.start.Z = Hg::EndianSwap<int32_t>(ray.start.Z);

  output.magnitude.X = Hg::EndianSwap<int32_t>(ray.magnitude.X);
  output.magnitude.Y = Hg::EndianSwap<int32_t>(ray.magnitude.Y);
  output.magnitude.Z = Hg::EndianSwap<int32_t>(ray.magnitude.Z);

  return output;
}

//  ****************************************************************************
Triangle endian_swap_triangle(const Triangle &tri)
{
  Triangle output;
  output.pts[0] = Hg::EndianSwap<uint16_t>(tri.pts[0]);
  output.pts[1] = Hg::EndianSwap<uint16_t>(tri.pts[1]);
  output.pts[2] = Hg::EndianSwap<uint16_t>(tri.pts[2]);
  output.normal = endian_swap_ray(tri.normal);

  return output;
}


//  ****************************************************************************
const Triangle k_other_cube_triangles[12] =
{
  endian_swap_triangle(k_cube_triangles[0]),
  endian_swap_triangle(k_cube_triangles[1]),
  endian_swap_triangle(k_cube_triangles[2]),
  endian_swap_triangle(k_cube_triangles[3]),
  endian_swap_triangle(k_cube_triangles[4]),
  endian_swap_triangle(k_cube_triangles[5]),
  endian_swap_triangle(k_cube_triangles[6]),
  endian_swap_triangle(k_cube_triangles[7]),
  endian_swap_triangle(k_cube_triangles[8]),
  endian_swap_triangle(k_cube_triangles[9]),
  endian_swap_triangle(k_cube_triangles[10]),
  endian_swap_triangle(k_cube_triangles[11])
};

const Object k_other_obj_cube = 
{
  Hg::EndianSwap<uint32_t>(k_obj_cube.count),
  k_cube_triangles
};

// Only the 32-bit fields in the point def require conversion.
const Instance k_other_instances[2] =
{
  {
    0,
    Hg::EndianSwap<int32_t>(0),
    Hg::EndianSwap<int32_t>(0),
    Hg::EndianSwap<int32_t>(0),
    {1,0,0,0,1,0,0,0,1}
  },
  {
    0,
    Hg::EndianSwap<int32_t>(3),
    Hg::EndianSwap<int32_t>(0),
    Hg::EndianSwap<int32_t>(-4),
    {1,0,0,0,1,0,0,0,1}
  }
};



// Converted Byte-order
const World k_other_world = 
{
  Hg::EndianSwap<uint16_t>(k_world.width), 
  Hg::EndianSwap<uint16_t>(k_world.height),
  k_other_camera,
  Hg::EndianSwap<uint16_t>(90),
  Hg::EndianSwap<uint32_t>(k_gray),
  k_other_light,
  1,                                        // 8-bits, no conversion req.
  &k_other_obj_cube,
  2,                                        // 8-bits, no conversion req.
  k_other_instances
};

// Create two corresponding packed data buffers
// TODO: Complete this.


} // namespace data
} // namespace test


#endif
