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



//#ifdef __cplusplus
//namespace Hg 
//{ 
//typedef TypeList < std::array<uint16_t,3>, ray_t, Hg::MT > triangle_t_tl; 
//typedef Hg::make_Hg_type_list<triangle_t_tl>::type triangle_t_Hg; 
//
//struct triangle_t 
//  : nested_trait 
//{ 
//  typedef triangle_t this_type; 
//  typedef triangle_t_tl format_type; 
//  enum { k_size = SizeOf<format_type>::value }; 
//  enum { k_length = length<format_type>::value }; 
//  
//  template< size_t IDX> Datum<IDX, format_type>& FieldAt() 
//  { 
//    typedef Datum < IDX, format_type> datum_type_t; 
//    return this_type::FieldAtIndex((datum_type_t*)0); 
//  } 
//  
//  template< size_t IDX> 
//  const Datum<IDX, format_type>& const_FieldAt() const 
//  { 
//    return const_cast<this_type*>(this)->FieldAt<IDX>(); 
//  } 
//  
//  static const size_t k_enum_base = 21 + 1;  
//  
//  typedef Hg::detail::DeduceProxyType < ((22 - k_enum_base)), format_type>::type Proxypts; 
//  typedef Proxypts::datum_type datum_pts; 
//  Proxypts pts; 
//  
//  datum_pts& FieldAtIndex(const datum_pts*) 
//  { 
//    return *static_cast<datum_pts*>(&pts); 
//  } 
//    
//  const char* FieldName(const Proxypts&) 
//  { 
//    return "pts"; 
//  };  
//  
//  typedef Hg::detail::DeduceProxyType < ((23 - k_enum_base)), format_type>::type Proxynormal; 
//  typedef Proxynormal::datum_type datum_normal; 
//  Proxynormal normal; 
//  
//  datum_normal& FieldAtIndex(const datum_normal*) 
//  { 
//    return *static_cast<datum_normal*>(&normal); 
//  } 
//  
//  const char* FieldName(const Proxynormal&) 
//  { 
//    return "normal"; 
//  };
//
//  private: 
//    template <typename T, typename U> 
//    size_t DatumSize(T value, U*) 
//    { 
//      return value; 
//    } 
//    
//    template <typename U> 
//    size_t DatumSize(pfnGetDatumSize ftor, U* buffer) 
//    { 
//      if (buffer->empty()) 
//      { 
//        return 0; 
//      } 
//      
//      return ftor(buffer->data(), buffer->size()); 
//    } 
//}; 
//
//namespace detail 
//{ 
//  
//template <> 
//struct field_data_t <triangle_t_Hg> 
//{ 
//  typedef triangle_t value_type; 
//}; 
//
//} 
//}; 
//
//extern "C" typedef struct tag_triangle_t 
//{ 
//  uint16_t pts[3]; 
//  ray_t normal;   
//} triangle_t; 
//extern const uint32_t k_triangle_t; 
//
//namespace C 
//{ 
//  
//Hg::triangle_t& struct_to_msg(triangle_t& src, Hg::triangle_t& dest) 
//{ 
//  using namespace Hg; 
//  
//  C::struct_to_msg(src.pts, dest.pts); 
//  C::struct_to_msg(src.normal, dest.normal);   
//  return dest; 
//} 
//
//} 
//
//namespace C 
//{ 
//  
//triangle_t& msg_to_struct(Hg::triangle_t& src, triangle_t& dest) 
//{ 
//  using namespace Hg; 
//
//  C::msg_to_struct(src.pts, dest.pts); 
//  C::msg_to_struct(src.normal, dest.normal);   
//  return dest; 
//} 
//
//} 
//
//namespace C 
//{ 
//
//void destroy_datum(triangle_t& src) 
//{ 
//  using namespace Hg; 
//  
//  C::destroy_datum( src.pts, (Hg::TypeAt<0, Hg::triangle_t_tl>::type*)0); 
//  C::destroy_datum( src.normal, (Hg::TypeAt<1, Hg::triangle_t_tl>::type*)0);   
//} 
//
//} 
//
//namespace C 
//{ 
//  
//size_t get_active_size(const triangle_t& src) 
//{ 
//  using namespace Hg; 
//  
//  size_t total_size = 0; 
//  total_size += C::get_datum_size( src.pts, (Hg::TypeAt<0, Hg::triangle_t_tl>::type*)0); 
//  total_size += C::get_datum_size( src.normal, (Hg::TypeAt<1, Hg::triangle_t_tl>::type*)0);   
//  return total_size; 
//} 
//
//}
//
//#endif


//  ****************************************************************************
//  A MACRO declaration like this is required for every Carbon library.
//  This informs Carbon which struct types to generate and export conversions.
//
C_DECLARE_EXPORTED_TYPES
(
  color_map_t,
  pt3d_t,
  triangle_t,
  ray_t,
  vertex_t,
  object_t
);



#endif

