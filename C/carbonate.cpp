//  @file C/carbonate.cpp
//  
//  The implementation for the Carbon functions with C-linkage.
//  
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
//  Includes *******************************************************************

#include <Carbon.h>
#include <C/carbonate.h>
#include <CarbonTestDefs.h>


int CarbonToNetwork(Hg_msg_t* p_src)
{
  using namespace C::detail;

  if (!p_src)
    return 0;

  Hg_type_t id = C::carbon_type(p_src);


  switch (id)
  {
  case k_color_map:
    {
      return ConvertToNetworkOrder<Hg::color_map_t, color_map_t>(p_src);
    }
  case k_pt3d:
    {
      return ConvertToNetworkOrder<Hg::pt3d_t, pt3d_t>(p_src);
    }
  case k_ray:
    {
      return ConvertToNetworkOrder<Hg::ray_t, ray_t>(p_src);
    }
  case k_vertex:
    {
      return ConvertToNetworkOrder<Hg::vertex_t, vertex_t>(p_src);
    }
  }

  return 0;
}


//  ****************************************************************************
int CarbonToBigEndian(Hg_msg_t* p_src)
{
  using namespace C::detail;

  if (!p_src)
    return 0;

  Hg_type_t id = C::carbon_type(p_src);


  switch (id)
  {
  case k_color_map:
    {
      return ConvertToBigEndian<Hg::color_map_t, color_map_t>(p_src);
    }
  case k_pt3d:
    {
      return ConvertToBigEndian<Hg::pt3d_t, pt3d_t>(p_src);
    }
  case k_ray:
    {
      return ConvertToBigEndian<Hg::ray_t, ray_t>(p_src);
    }
  case k_vertex:
    {
      return ConvertToBigEndian<Hg::vertex_t, vertex_t>(p_src);
    }
  }

  return 0;
}

//  ****************************************************************************
size_t CarbonPackMessage( const Hg_msg_t  *p_src,   
                          unsigned char   *p_buffer, 
                          size_t          len)
{
  using namespace C::detail;

  if (!p_src)
    return 0;

  Hg_type_t id = C::carbon_type(p_src);


  switch (id)
  {
  case k_color_map:
    {
      return PackMessage<Hg::color_map_t, color_map_t>(p_src, p_buffer, len);
    }
  case k_pt3d:
    {
      return PackMessage<Hg::pt3d_t, pt3d_t>(p_src, p_buffer, len);
    }
  case k_ray:
    {
      return PackMessage<Hg::ray_t, ray_t>(p_src, p_buffer, len);
    }
  case k_vertex:
    {
      return PackMessage<Hg::vertex_t, vertex_t>(p_src, p_buffer, len);
    }
  }

  return 0;
}

//  ****************************************************************************
size_t CarbonUnpackMessage( Hg_msg_t            *p_src,   
                            const unsigned char *p_buffer, 
                            size_t              len)
{
  using namespace C::detail;

  if (!p_src)
    return 0;

  Hg_type_t id = C::carbon_type(p_src);


  switch (id)
  {
  case k_color_map:
    {
      return UnpackMessage<Hg::color_map_t, color_map_t>(p_src, p_buffer, len);
    }
  case k_pt3d:
    {
      return UnpackMessage<Hg::pt3d_t, pt3d_t>(p_src, p_buffer, len);
    }
  case k_ray:
    {
      return UnpackMessage<Hg::ray_t, ray_t>(p_src, p_buffer, len);
    }
  case k_vertex:
    {
      return UnpackMessage<Hg::vertex_t, vertex_t>(p_src, p_buffer, len);
    }
  }

  return 0;
}


// Disable name-mangling for these 
// functions when compiled with C++.
extern "C"
{


//  ****************************************************************************
ALCHEMY_API 
int Hg_local_endianess()
{
  return  ALCHEMY_ENDIANESS == ALCHEMY_BIG_ENDIAN
          ? k_big_endian
          : k_little_endian;
}

//  ****************************************************************************
ALCHEMY_API 
Hg_msg_t* Hg_create(
  Hg_type_t msg_type
)
{
  size_t size = GetTypeSize(msg_type);
  if (0 == size)
    return 0;

  C::carbon_t* p_msg = new C::carbon_t[size + C::k_carbon_footprint];
  uint32_t base = C::k_carbon_id | (size << C::k_size_shift);
  
  ::memcpy(p_msg, &base, 4);
  ::memcpy(p_msg + C::k_type_offset, &msg_type, 4);

  return p_msg + C::k_base_offset;
}


//  ****************************************************************************
ALCHEMY_API
Hg_msg_t* Hg_clone(
  const Hg_msg_t* p_src
)
{
  GetTotalSize(const_cast<Hg_msg_t*>(p_src));

  return 0;
}


//  ****************************************************************************
ALCHEMY_API
void  Hg_destroy(
  Hg_msg_t* p_msg
)
{
  C::carbon_t* p_base = C::carbon_ptr(p_msg);
  if (!p_base)
    return;

  // TODO: Handle dynamic buffers.
  // Use the type information to 
  // destroy any dynamic buffers.

  delete[] p_base;
}


//  ****************************************************************************
ALCHEMY_API 
size_t Hg_resize_dynamic(
  Hg_msg_t* p_msg, 
  void*     p_field, 
  size_t    len
)
{
  return 0;
}


//  ****************************************************************************
ALCHEMY_API 
Hg_type_t Hg_type(
  const Hg_msg_t* p_msg
)
{
  return C::carbon_type(p_msg);
}


//  ****************************************************************************
ALCHEMY_API 
size_t Hg_size(
  const Hg_msg_t* p_msg
)
{
  return C::carbon_size(p_msg);
}


//  ****************************************************************************
ALCHEMY_API 
size_t Hg_data_size(
  const Hg_msg_t* p_msg
)
{
  return GetTotalSize(const_cast<Hg_msg_t*>(p_msg));

  return 0;
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_network(
  Hg_msg_t* p_msg
)
{
  // Exit if the local platform is big-endian.
  if (k_big_endian == Hg_local_endianess())
  {
    return 0;
  }

  return CarbonToNetwork(p_msg);
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_host(
  Hg_msg_t* p_msg
)
{  
  return Hg_to_network(p_msg);
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_big_end(
  Hg_msg_t* p_msg
)
{
  return CarbonToBigEndian(p_msg);
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_little_end(
  Hg_msg_t* p_msg
)
{
  return Hg_to_big_end(p_msg);
}

          
//  ****************************************************************************
ALCHEMY_API 
size_t Hg_pack(
  const Hg_msg_t  *p_msg, 
  unsigned char   *p_buffer, 
  size_t          len
)
{
  if ( !p_msg
    || !p_buffer
    || 0 == len)
  {
    return 0;
  }

  return CarbonPackMessage(p_msg, p_buffer, len);
}


//  ****************************************************************************
ALCHEMY_API 
size_t Hg_unpack(
  Hg_msg_t            *p_msg, 
  const unsigned char *p_buffer, 
  size_t              len
)
{
  if ( !p_msg
    || !p_buffer
    || 0 == len)
  {
    return 0;
  }

  return CarbonUnpackMessage(p_msg, p_buffer, len);
}


// End of name-mangling guard.
}



