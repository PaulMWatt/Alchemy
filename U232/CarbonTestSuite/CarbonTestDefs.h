//  @file CarbonTestDefs.h
//  
//  Test definition types for Carbon.
// 
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef CARBON_TEST_DEFS_H_INCLUDED
#define CARBON_TEST_DEFS_H_INCLUDED
#include <Alchemy.h>

ALCHEMY_STRUCT  
( fundamentals_t,
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
ALCHEMY_STRUCT
( color_map_t,
  ALCHEMY_ARRAY (color4, 16, table)
);


//  ****************************************************************************
//  Type definition that represents a 3-dimensional point.
//  This type is a nested type with simple sub-types.
// 
ALCHEMY_STRUCT
( pt3d_t,
  ALCHEMY_DATUM (int32_t, X),
  ALCHEMY_DATUM (int32_t, Y),
  ALCHEMY_DATUM (int32_t, Z)
);


//  ****************************************************************************
//  Type definition to represent a mathematical vector.
//  A starting point and a magnitude.
//  This format covers a nested type with nested sub-types.
// 
ALCHEMY_STRUCT
( ray_t,
  ALCHEMY_DATUM (pt3d_t, start),
  ALCHEMY_DATUM (pt3d_t, magnitude)
);


//  ****************************************************************************
//  A single point with with a specified color.
//  This format covers a nested type that contains a nested type and a bit-list.
// 
ALCHEMY_STRUCT
( vertex_t,
  ALCHEMY_DATUM (pt3d_t, pt),
  ALCHEMY_DATUM (color4, color)
);

////extern "C" 
////typedef struct tag_vertex_t 
////{ 
////  pt3d_t pt; 
////  color4 color;   
////} vertex_t; 
////extern const uint32_t k_vertex_t_id; 
//namespace C 
//{ 
//  template< > 
//  Hg::vertex_t& struct_to_msg(vertex_t& src, Hg::vertex_t& dest) 
//  { 
//    using namespace Hg; 
//    C::struct_to_msg(src.pt, dest.pt); 
//    C::struct_to_msg(src.color, dest.color);   
//  } 
//} 
//
//namespace C 
//{ 
//  template< > 
//  vertex_t& msg_to_struct(Hg::vertex_t& src, vertex_t& dest) 
//  { 
//    using namespace Hg; 
//    C::msg_to_struct(src.pt, dest.pt); 
//    C::msg_to_struct(src.color, dest.color);   
//  } 
//}

#endif

