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

// The contents of this header file only apply to C++ builds.
#ifdef __cplusplus

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
///               This may also identify a carbon field of dynamic size.
/// Byte [8]:     The pointer returned to the caller.
///               The remainder of the structure starts here.
///               Therefore, all allocations will be 8-bytes larger than requested.
///
const int       k_carbon_footprint  = 8;
const int       k_base_offset       = k_carbon_footprint;
const int       k_type_offset       = 4;
const uint32_t  k_carbon_id         = 0xA9;       
const uint32_t  k_carbon_field_id   = 0xC4;       

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
    || ( p_base[0] != k_carbon_id
      && p_base[0] != k_carbon_field_id))
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
/// Allocates a carbon buffer to act as an abstract buffer of memory in C.
///
inline
Hg_msg_t* carbon_alloc(size_t size, uint32_t buffer_id, uint32_t msg_type)
{
  if (0 == size)
    return 0;

  C::carbon_t* p_msg = new C::carbon_t[size + C::k_carbon_footprint];
  uint32_t base = buffer_id | (size << C::k_size_shift);
  
  ::memcpy(p_msg, &base, 4);
  ::memcpy(p_msg + C::k_type_offset, &msg_type, 4);
  ::memset(p_msg + C::k_base_offset, 0, size);

  return p_msg + C::k_base_offset;
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


//  Forward Declarations *******************************************************
//  These functions are used by the Carbonated implementation functions.

void CarbonDestroy(
  Hg_msg_t* p_src
);


Hg_msg_t* CarbonClone(
  const Hg_msg_t* p_src
);


size_t GetTypeSize(
  int type_id
);


size_t GetTypeDataSize(
  Hg_msg_t* p_src
);


int CarbonSwapByteOrder(
  Hg_msg_t* p_src
);


size_t CarbonPackMessage( 
  const Hg_msg_t  *p_src,
  unsigned char   *p_buffer,
  size_t           len
);


size_t CarbonUnpackMessage( 
  Hg_msg_t            *p_src,
  const unsigned char *p_buffer,
  size_t              len
);


#endif // __cplusplus

#endif
