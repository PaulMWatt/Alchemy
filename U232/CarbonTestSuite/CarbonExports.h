//  @file CarbonExports.h
//  
//  Development header working through the details for defining a Carbon Library.
// 
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef CARBONEXPORTS_H_INCLUDED
#define CARBONEXPORTS_H_INCLUDED
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


#define k_color_map 0
#define k_pt3d      1
#define k_ray       2
#define k_vertex    3


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
size_t GetTotalSize(const Hg_msg_t* p_src)
{
  if (!p_src)
    return 0;




  return 0;
}



#endif

