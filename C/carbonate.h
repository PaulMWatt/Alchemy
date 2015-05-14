//  @file C/carbonate.h
// 
//  Internal implementation MACROS for C-linkable structs and function calls.
// 
//  @note           This header file must not be included directly and the 
//                  MACROS defined in this file should not be accessed
//                  directly. Include and used the definitions from the file
//                  **<Carbon.h>** instead.
//           
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef CARBONATE_H_INCLUDED
#define CARBONATE_H_INCLUDED
//  Includes *******************************************************************
#include <Carbon.h>
#include <C/conversion.h>


namespace C
{
//  Typedefs *******************************************************************
typedef unsigned char     carbon_t;

//  ****************************************************************************
/// Opaque type representation of memory buffers returned for Carbon.
///
/// Byte [0]:     Carbon ID
/// Bytes[1,3]:   Size of the buffer, 3-bytes, 16 MB max
/// Bytes[4,7]:   Type Id mapping the C-struct to a C++ Hg::Message format.  
/// Byte [8]:     The pointer returned to the caller.
///               The remainder of the structure starts here.
///               Therefore, all allocations will be 8-bytes larger than requested.
///
const int       k_carbon_footprint  = 8;
const int       k_base_offset       = k_carbon_footprint;
const int       k_type_offset       = 4;
const uint32_t  k_carbon_id         = 0xA9;       

const char      k_size_shift        = 8; 


//  ****************************************************************************
/// Given the users msg address, the actual allocated based address is returned.
///
inline
carbon_t* carbon_ptr(Hg_msg_t* p_msg)
{
  if (!p_msg)
    return 0;

  // Offset the user supplied pointer to the 
  // calculated position of the allocation base address.
  carbon_t* p_base = static_cast<carbon_t*>(p_msg);
  std::advance(p_base, -k_carbon_footprint);

  // Verify the Carbon ID before returning the pointer.
  if ( !p_base
    || p_base[0] != k_carbon_id)
    return 0;

  return p_base;
}

//  ****************************************************************************
inline
carbon_t* carbon_ptr(const Hg_msg_t* p_msg)
{
  return carbon_ptr(const_cast<Hg_msg_t*>(p_msg));
}

//  ****************************************************************************
/// Returns the size of the allocated buffer that is usable by the user.
///
inline
size_t carbon_size(const Hg_msg_t* p_msg)
{
  carbon_t* p_base = carbon_ptr(p_msg);
  if (!p_base)
    return 0;

  uint32_t size = 0;
  memcpy(&size, p_base, 4);

  return size >> k_size_shift;
}

//  ****************************************************************************
/// Returns the type of message for which the buffer is allocated.
///
inline
Hg_type_t carbon_type(const Hg_msg_t* p_msg)
{
  carbon_t* p_base = carbon_ptr(p_msg);
  if (!p_base)
    return k_invalid_type;

  Hg_type_t type = 0;
  memcpy(&type, p_base + k_type_offset, 4);

  return type;
}

} // namespace C



// TODO: For now, hand-writing the implementation. These functions will eventually all be generated.


#include <CarbonTestDefs.h>
//  ****************************************************************************
#include <Pb/type_list.h>
#include <Pb/size_at.h>

typedef Hg::TypeList
<
  color_map_t,
  pt3d_t,
  ray_t,
  vertex_t
> exported_types;


#define k_color_map     0
#define k_pt3d          1
#define k_ray           2
#define k_vertex        3


template< Hg_type_t IdT,      
          typename  T
        >
T* Hg_msg_cast(C::carbon_t* p_msg);//, T*);

template <>
Hg::color_map_t* Hg_msg_cast<k_color_map, Hg::color_map_t>(C::carbon_t* p_msg)//, Hg::color_map_t* = 0)
{
  return reinterpret_cast<Hg::color_map_t*>(p_msg);
}

template <>
Hg::pt3d_t* Hg_msg_cast<k_pt3d, Hg::pt3d_t>(C::carbon_t* p_msg)//, Hg::pt3d_t* = 0)
{
  return reinterpret_cast<Hg::pt3d_t*>(p_msg);
}

template <>
Hg::ray_t* Hg_msg_cast<k_ray, Hg::ray_t>(C::carbon_t* p_msg)//, Hg::ray_t* = 0)
{
  return reinterpret_cast<Hg::ray_t*>(p_msg);
}

template <>
Hg::vertex_t* Hg_msg_cast<k_vertex, Hg::vertex_t>(C::carbon_t* p_msg)//, Hg::vertex_t* = 0)
{
  return reinterpret_cast<Hg::vertex_t*>(p_msg);
}

//  ****************************************************************************
size_t GetTypeSize(int v)
{
  switch (v)
  {
  case k_color_map:
    return Hg::SizeAt<k_color_map , exported_types>::value;
  case k_pt3d:
    return Hg::SizeAt<k_pt3d, exported_types>::value;
  case k_ray:
    return Hg::SizeAt<k_ray, exported_types>::value;
  case k_vertex:
    return Hg::SizeAt<k_vertex, exported_types>::value;
  }

  return 0;
}



//  ****************************************************************************
size_t GetTotalSize(Hg_msg_t* p_src)
{
  if (!p_src)
    return 0;

  Hg_type_t id = C::carbon_type(p_src);


  switch (id)
  {
  case k_color_map:
    {
      Hg::color_map_t* m = Hg_msg_cast<k_color_map, Hg::color_map_t>(p_src);
      return 0;
    }
  case k_pt3d:
    {
      Hg::pt3d_t* m = Hg_msg_cast<k_pt3d, Hg::pt3d_t>(p_src);
      return 0;
    }
  case k_ray:
    {
      Hg::ray_t* m = Hg_msg_cast<k_ray, Hg::ray_t>(p_src);
      return 0;
    }
  case k_vertex:
    {
      Hg::vertex_t* m = Hg_msg_cast<k_vertex, Hg::vertex_t>(p_src);
      return 0;
    }
  }


  return 0;
}


#endif
