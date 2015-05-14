/// @file Carbon.h
/// 
/// Carbon generates c-linkable interfaces for constructs generated by Alchemy.
/// 
/// The MIT License(MIT)
/// 
/// @copyright 2015 Paul M Watt
/// 
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files(the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions :
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
/// 
//  ***************************************************************************
#ifndef CARBON_H_INCLUDED
#define CARBON_H_INCLUDED
//  Includes ******************************************************************
#define ALCHEMY_CARBONATE
#include <Alchemy.h>

// The definition that indicates these 
// functions will be publically accessible.
#if defined(_WIN32)

# if defined(ALCHEMY_EXPORT)
#   define ALCHEMY_API __declspec(dllexport) 
# else
#   define ALCHEMY_API __declspec(dllimport) 
# endif

#else

#define ALCHEMY_API

#endif



// Disable name-mangling for these 
// functions when compiled with C++.
#ifdef __cplusplus
extern "C"
{
#endif

//  Typedefs *******************************************************************
typedef unsigned char     Hg_msg_t;
typedef unsigned long     Hg_type_t;

//  Constants ******************************************************************
#define k_invalid_type -1


//  ****************************************************************************
/// Reports the type of endianess of the local system.
///
/// @return     
///
ALCHEMY_API 
int Hg_local_endianess();

//  ****************************************************************************
/// Creates a new Hg message object of the specified type.
/// The caller must call Hg_destroy when they are done with the returned 
/// object to return the messages allocated memory.
///
/// @param msg_type[in] 
///
/// @return             On success, an allocated message pointer is returned.
///                       This pointer can be cast to the structure that 
///                       matches the type of requested message.
///                     0 is returned on failure.
///
ALCHEMY_API 
Hg_msg_t* Hg_create(
  Hg_type_t msg_type
);

//  ****************************************************************************
/// Creates a complete clone of an existing Hg message object.
/// The caller must call Hg_destroy when they are done with the returned 
/// object to return the messages allocated memory.
///
/// @param p_src[in]    A valid message object that should be cloned.
///                     All of the data inside of the message, including
///                     dynamically allocated space will be initialized to
///                     match the source message.
///
/// @return             On success, an allocated message pointer is returned.
///                       This pointer can be cast to the structure that 
///                       matches the type of requested message.
///                     0 is returned on failure.
///
ALCHEMY_API
Hg_msg_t* Hg_clone(
  const Hg_msg_t* p_src
);

//  ****************************************************************************
/// The specified message is destroyed.
/// ALL memory is reclaimed, including dynamically allocated space.
///
/// @param p_msg[in]    The previously allocated message to be destroyed.
///                     This message should not be used after it is passed 
///                     to this function.
///
ALCHEMY_API
void  Hg_destroy(
  Hg_msg_t* p_msg
);

//  ****************************************************************************
/// Resize the buffer for a dynamically allocated field in an existing message.
///
/// @param p_msg[inout]
/// @param p_field[inout]
/// @param len[in]
///
/// @return             The number of bytes allocated for the field is returned.
///                     If no bytes can be allocated, 0 is returned.
///
ALCHEMY_API 
size_t Hg_resize_dynamic(
  Hg_msg_t* p_msg, 
  void*     p_field, 
  size_t    len
);

//  ****************************************************************************
/// Returns the type of the specified message.
///
/// @param p_msg[in]    The message to query.
///
/// @return             The enumerated type identifying this message is returned.
///
ALCHEMY_API 
Hg_type_t Hg_type(
  const Hg_msg_t* p_msg
);

//  ****************************************************************************
/// Returns the size of the specified message.
///
/// @param p_msg[in]    The message to query.
///
/// @return             The size of the buffer to hold the main message.
///                     0 is returned if the buffer does not represent a valid msg.
///
ALCHEMY_API 
size_t Hg_size(
  const Hg_msg_t* p_msg
);

//  ****************************************************************************
/// Returns the number of bytes that are required to serialize this object.
///
/// @param p_msg[in]    The message to query.
///
/// @return             The calculated buffer size required to serialize
///                     the specified message.
///                     0 is returned if the buffer does not represent a valid msg.
///
ALCHEMY_API 
size_t Hg_data_size(
  const Hg_msg_t* p_msg
);

//  ****************************************************************************
/// Converts this object, in-place, to network byte-order.
/// No actions will be performed if the local platform is big-endian.
///
/// @param p_msg[in]    The message to convert.
///
/// @return             A status code indicating the result.
///                     0 indicates success
///                     A negative value indicates an error.
///
ALCHEMY_API 
int Hg_to_network(
  Hg_msg_t* p_msg
);

//  ****************************************************************************
/// Converts this object, in-place, to host byte-order.
/// No actions will be performed if the local platform is big-endian.
///
/// @param p_msg[in]    The message to convert.
///
/// @return             A status code indicating the result.
///                     0 indicates success
///                     A negative value indicates an error.
///
ALCHEMY_API 
int Hg_to_host(
  Hg_msg_t* p_msg
);

//  ****************************************************************************
/// Converts this object, in-place, to big-endian byte-order.
/// The message will always be converted as requested.
///
/// @param p_msg[in]    The message to convert.
///
/// @return             A status code indicating the result.
///                     0 indicates success
///                     A negative value indicates an error.
///
ALCHEMY_API 
int Hg_to_big_end(
  Hg_msg_t* p_msg
);

//  ****************************************************************************
/// Converts this object, in-place, to little-endian byte-order.
/// The message will always be converted as requested.
///
/// @param p_msg[in]    The message to convert.
///
/// @return             A status code indicating the result.
///                     0 indicates success
///                     A negative value indicates an error.
///
ALCHEMY_API 
int Hg_to_little_end(
  Hg_msg_t* p_msg
);
          
//  ****************************************************************************
/// Serializes the specified message into a buffer.
///
/// @param p_msg[in]      The message to serialize.
/// @param p_buffer[out]  The buffer that will be written into.
/// @param len[in]        The length of the output buffer.
///
/// @return               The number of bytes written to the serialized buffer.
///                       0 indicates an error occurred.
///
ALCHEMY_API 
size_t Hg_pack(
  const Hg_msg_t  *p_msg, 
  unsigned char   *p_buffer, 
  size_t          len
);

//  ****************************************************************************
/// Deserializes the specified message from a buffer.
///
/// @param p_msg[in]      The message to populate from the serialized buffer.
/// @param p_buffer[out]  The buffer that will be read from.
/// @param len[in]        The length of the input buffer.
///
/// @return               The number of bytes read from the serialized buffer.
///                       0 indicates an error occurred.
///
ALCHEMY_API 
size_t Hg_unpack(
  Hg_msg_t            *p_msg, 
  const unsigned char *p_buffer, 
  size_t              len
);

//  ****************************************************************************
//  Function pointer declarations for dynamically-loading the library.
//
typedef int       (*pfn_Hg_local_endianess) ();
typedef Hg_msg_t* (*pfn_Hg_create)          (Hg_type_t);
typedef void      (*pfn_Hg_destroy)         (Hg_msg_t*);
typedef Hg_type_t (*pfn_Hg_type)            (const Hg_msg_t*);
typedef size_t    (*pfn_Hg_size)            (const Hg_msg_t*);
typedef size_t    (*pfn_Hg_data_size)       (const Hg_msg_t*);
typedef int       (*pfn_Hg_to_network)      (Hg_msg_t*);
typedef int       (*pfn_Hg_to_host)         (Hg_msg_t*);
typedef int       (*pfn_Hg_to_big_end)      (Hg_msg_t*);
typedef int       (*pfn_Hg_to_little_end)   (Hg_msg_t*);
typedef size_t    (*pfn_Hg_pack)            (const Hg_msg_t*, void*, size_t);
typedef size_t    (*pfn_Hg_unpack)          (Hg_msg_t*, const void*, size_t);


// End of name-mangling guard.
#ifdef __cplusplus
}
#endif

#endif
