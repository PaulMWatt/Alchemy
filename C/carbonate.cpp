//  @file C/carbonate.cpp
//  
//  The implementation for the Carbon functions with C-linkage.
//  
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  ****************************************************************************
//  Includes *******************************************************************
#include <Carbon.h>
#include <algorithm>

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
const int       k_base_offset = -8;
const int       k_type_offset = 4;
const uint32_t  k_carbon_id   = 0xA9;       

const uint32_t  k_size_mask   = 0x00FFFFFF; 



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
  std::advance(p_base, k_base_offset);

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
/// Returns the size of the allocated buffer.
///
inline
size_t carbon_size(const Hg_msg_t* p_msg)
{
  carbon_t* p_base = carbon_ptr(p_msg);
  if (!p_base)
    return 0;

  uint32_t size = 0;
  memcpy(&size, p_base, 4);

  return size & k_size_mask;
}

//  ****************************************************************************
/// Returns the type of message for which the buffer is allocated.
///
inline
Hg_type_t carbon_type(const Hg_msg_t* p_msg)
{
  carbon_t* p_base = carbon_ptr(p_msg);
  if (!p_base)
    return 0;

  Hg_type_t type = 0;
  memcpy(&type, p_base + k_type_offset, 4);

  return type;
}



} // namespace C


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
  return 0;
}


//  ****************************************************************************
ALCHEMY_API
Hg_msg_t* Hg_clone(
  const Hg_msg_t* p_src
)
{
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

