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

// Disable name-mangling for these functions
// that are to be exported from this library.
extern "C"
{

//  ****************************************************************************
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

  return C::carbon_alloc(size, C::k_carbon_id, msg_type);
}


//  ****************************************************************************
ALCHEMY_API
Hg_msg_t* Hg_clone(
  const Hg_msg_t* p_src
)
{
  return CarbonClone(p_src);
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

  CarbonDestroy(p_msg);

  // Zeroize the preamble to prevent this 
  // message from accidentally being reused
  // after it has been freed.
  ::memset(p_base, 0, C::k_carbon_footprint);

  delete[] p_base;
}


//  ****************************************************************************
// TODO: Consider attempting to verify the association between p_field and p_msg.
ALCHEMY_API 
size_t Hg_field_alloc(
  Hg_msg_t* p_msg, 
  void**    p_field, 
  size_t    len
)
{
  if ( !p_msg
    || !p_field)
  {
    return 0;
  }

  // Inspect the incoming field pointer. 
  // If it has an existing buffer, it must be destroyed.
  if (*p_field)
  {
    Hg_destroy((Hg_msg_t*)*p_field);
  }

  Hg_msg_t* p_buffer = C::carbon_alloc(len, C::k_carbon_field_id, 0);
  *p_field = p_buffer;

  return  ( 0 == p_buffer )
          ? 0
          : len;
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
  return GetTypeDataSize(const_cast<Hg_msg_t*>(p_msg));
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

  return CarbonSwapByteOrder(p_msg);
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
  return CarbonSwapByteOrder(p_msg);
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



