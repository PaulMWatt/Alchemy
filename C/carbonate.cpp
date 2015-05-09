//  @file C/carbonate.cpp
//  
//  The implementation for the Carbon functions with C-linkage.
//  
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
//  Includes *******************************************************************
#include <C/carbonate.h>
#include <algorithm>



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
  uint32_t base = C::k_carbon_id | (size << 8);
  
  ::memcpy(p_msg, &base, 4);
  ::memcpy(p_msg + C::k_type_offset, &msg_type, 4);

  return p_msg;
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
  // TODO: 
  // Use the type information to calculate
  // the size of the output buffer.


  return 0;
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_network(
  Hg_msg_t* p_msg
)
{
  // TODO: Dispatch to the correct type converter.


  return 0;
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_host(
  Hg_msg_t* p_msg
)
{
  // TODO: Dispatch to the correct type converter.
  return 0;
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_big_end(
  Hg_msg_t* p_msg
)
{
  // TODO: Dispatch to the correct type converter.
  return 0;
}


//  ****************************************************************************
ALCHEMY_API 
int Hg_to_little_end(
  Hg_msg_t* p_msg
)
{
  // TODO: Dispatch to the correct type converter.
  return 0;
}

          
//  ****************************************************************************
ALCHEMY_API 
size_t Hg_pack(
  const Hg_msg_t* p_msg, 
  void*           p_buffer, 
  size_t          len
)
{
  // TODO: Dispatch to the correct serializer.
  return 0;
}


//  ****************************************************************************
ALCHEMY_API 
size_t Hg_unpack(
  Hg_msg_t*   p_msg, 
  const void* p_buffer, 
  size_t      len
)
{
  // TODO: Dispatch to the correct deserializer.
  return 0;
}


// End of name-mangling guard.
}


