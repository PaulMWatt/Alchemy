/// @file Alchemy.h
/// 
/// Network Alchemy is a message and structured data processing framework.
///
/// Include this file for access to the alchemy message structure framework.
///
/// This framework provides the ability to define structured message formats,
/// which can be used portably across platforms. These structured definitions
/// will facilitate the population of the data in the memoery buffers for
/// inter-process communication, file and network transfer as well as 
/// direct memory access mapping..
/// 
/// Byte-alignment processing is completely transparent to application level
/// users. Conversion utilities are automatically generated for conversion
/// between host, network, big and little-endian formats for transport developers. 
/// 
/// Alchemy is portable across different processor types and platforms. 
/// Word alignment and memory access issues are also handled transparently by 
/// the framework. Users interface with Hg message structures in the same way 
/// structures are accessed. Nested structures are supported.
///
/// Message structure definitions are created with the list of MACROs below.
/// Refer to the appropriate MACROs documentation for details on correct usage:
/// 
///   - ALCHEMY_STRUCT(TYPE_LIST)
///
///   - ALCHEMY_DATUM(TYPE,NAME)
///   - ALCHEMY_ARRAY(TYPE,COUNT,NAME)
///   - ALCHEMY_ALLOC(TYPE,SIZE,NAME)
///   - ALCHEMY_ALLOC_EX(TYPE,ALLOCATOR,SIZE,NAME)
///
///   - ALCHEMY_DATUM_OPT(TYPE,EXISTS,NAME)
///   - ALCHEMY_ARRAY_OPT(TYPE,COUNT,EXISTS,NAME)
///   - ALCHEMY_ALLOC_OPT(TYPE,SIZE,EXISTS,NAME)
///   - ALCHEMY_ALLOC_EX_OPT(TYPE,ALLOCATOR,SIZE,EXISTS,NAME)
///
/// Hg provides a portable bit-field interface that works by generating the
/// appropriate shift and mask operations for each field. Use these MACROS
/// to define a set of bit-fields that are packed into a user-specified integral type.
/// Hg currently is written to allow up to 32 bit-fields in a single parameter.
///
///   - ALCHEMY_PACKED(TYPE,BITSET)
///   - ALCHEMY_END_PACKED
///   - ALCHEMY_BITS(INDEX,COUNT,NAME)
/// 
//  ****************************************************************************
///
/// The MIT License(MIT)
/// 
/// @copyright 2014 Paul M Watt
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
#ifndef ALCHEMY_H_INCLUDED
#define ALCHEMY_H_INCLUDED

//  Includes ******************************************************************
#include <C/carbon_def.h>
#include <Hg/msg_def.h>


//  ****************************************************************************
/// Marks the beginning of a message format.
/// 
/// A MACRO used to start the definition for a message format interface. 
/// This definition requires that the parent class derive from the MsgFormat 
/// base class.
///             
/// @param TYPE_LIST         The type_list used to defined the layout format.
///             
/// @note           This definition MACRO should be placed in the global namespace.
///                 C++ objects will be placed in a namespace that corresponds
///                 with the elemental name of its library, such as Hg.
/// ~~~{.cpp}
///
///   // Define the message data format
///   ALCHEMY_STRUCT  (new_point_t,
///     ALCHEMY_DATUM (uint8_t,    msgType),
///     ALCHEMY_DATUM (uint8_t,    verNum),
///     ALCHEMY_DATUM (uint16_t,   id),
///     ALCHEMY_DATUM (uint32_t,   X),
///     ALCHEMY_DATUM (uint32_t,   Y),
///     ALCHEMY_DATUM (uint32_t,   Z),
///     ALCHEMY_DATUM (uint16_t,   flags),
///     ALCHEMY_DATUM (uint8_t,    priority),
///     ALCHEMY_DATUM (uint8_t,    count)
///   )
///     
/// ~~~
///             
#define ALCHEMY_STRUCT(NAME, ...)       DECLARE_STRUCT(NAME, Hg_, __VA_ARGS__);\
                                        DECLARE_STRUCT(NAME, C_,  __VA_ARGS__);

//  ****************************************************************************
/// Adds a field to the message definition.
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field.
///             
/// @param TYPE     The type to use for this field
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///             
#define ALCHEMY_DATUM(TYPE,NAME)       DECLARE_DATUM(TYPE,NAME)


//  ****************************************************************************
/// Adds a fixed-size array field to the message definition.
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field.
///             
/// @param TYPE     The type to use for this field
/// @param COUNT    The number of elements allocated for the array.
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///             
#define ALCHEMY_ARRAY(TYPE,COUNT,NAME) DECLARE_ARRAY_DATUM(TYPE,COUNT,NAME)


//  ****************************************************************************
/// Adds a field with a dynamic size to the message definition.
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// Finally, a field is provided to specify how this datum will know how
/// large the field should be when reading data on input.
///             
/// @param TYPE     The type to use for this field
/// @param SIZE     Specifies how the size of the field is determined on input.
///                 There are a few possible ways to indicate the method:
///                   * Reference a field previously defined in the message that
///                     indicates the number of entries.
///                   * Specify a function pointer to a user-defined function
///                     that will inspect the data and return the size.
///                     the function should have the following signature:
///                         size_t pfn_GetDatumSize(uint8_t* pCur, size_t len)
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///
///             
#define ALCHEMY_ALLOC(TYPE,SIZE,NAME)\
                                        DECLARE_VECTOR_DATUM(TYPE,SIZE,NAME)


//  ****************************************************************************
/// Adds a field with a dynamic size controlled by a user specified allocator.
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// A field is provided for the user to indicate how the field can determine
/// its own size. This MACRO is similar to ALCHEMY_ALLOC, with the exception
/// that a user specified allocator can be used.
///             
/// @param TYPE       The type to use for this field
/// @param ALLOCATOR  An allocator that will be used to allocate space for
///                   the dynamically sized field.
/// @param SIZE       Specifies how the size of the field is determined on input.
///                   There are a few possible ways to indicate the method:
///                   * Reference a field previously defined in the message that
///                     indicates the number of entries.
///                   * Specify a function pointer to a user-defined function
///                     that will inspect the data and return the size.
///                     the function should have the following signature:
///                         size_t pfn_GetDatumSize(uint8_t* pCur, size_t len)
/// @param NAME       The name to assign this parameter in the message definition.
///                   NAME will be the name used to access this field directly.
///
///             
#define ALCHEMY_ALLOC_EX(TYPE,ALLOCATOR,SIZE,NAME)\
                              DECLARE_ALLOCATOR_DATUM(TYPE,ALLOCATOR,SIZE,NAME)


//  ****************************************************************************
/// Adds an optional field that is not guaranteed to be present.  
///
/// This declaration supports fundamental and nested types.
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// Finally, a field is provided to specify how this datum will be able to tell
/// if the optional field is present.  
///             
/// @param TYPE     The type to use for this field
/// @param EXISTS   Specifies how the existance of the field is determined on input.
///                 There are a few possible ways to indicate the method:
///                   * Reference a field previously defined in the message that
///                     indicates the presence of the field.
///                     A boolean field set to true, or a non-zero integral
///                     value will indicate the field exists.
///                   * Specify a function pointer to a user-defined function
///                     that will inspect the data and return a boolean.
///                     the function should have the following signature:
///                         bool pfn_DoesOptionalDatumExist(uint8_t* pCur, size_t len)
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///
///             
#define ALCHEMY_DATUM_OPT(TYPE,EXISTS,NAME) \
                                        DECLARE_OPTIONAL(TYPE,EXISTS,NAME)

//  ****************************************************************************
/// Adds an optional field that is not guaranteed to be present.  
///
/// This declaration supports arrays.
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// Finally, a field is provided to specify how this datum will be able to tell
/// if the optional field is present.  
///             
/// @param TYPE     The type to use for this array field
/// @param COUNT    An unsigned integer that indicates the static size of the array.
/// @param EXISTS   Specifies how the existance of the field is determined on input.
///                 There are a few possible ways to indicate the method:
///                   * Reference a field previously defined in the message that
///                     indicates the presence of the field.
///                     A boolean field set to true, or a non-zero integral
///                     value will indicate the field exists.
///                   * Specify a function pointer to a user-defined function
///                     that will inspect the data and return a boolean.
///                     the function should have the following signature:
///                         bool pfn_DoesOptionalDatumExist(uint8_t* pCur, size_t len)
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///
///             
#define ALCHEMY_ARRAY_OPT(TYPE,COUNT,EXISTS,NAME) \
                                        DECLARE_ARRAY_OPTIONAL(TYPE,COUNT,EXISTS,NAME)

//  ****************************************************************************
/// Adds an optional field that is not guaranteed to be present.  
///
/// This declaration supports dynamically allocated arrays (vector).
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// Finally, a field is provided to specify how this datum will be able to tell
/// if the optional field is present.  
///             
/// @param TYPE     The type to use for this array field
/// @param SIZE     Specifies how the size of the field is determined on input.
///                 There are a few possible ways to indicate the method:
///                   * Reference a field previously defined in the message that
///                     indicates the number of entries.
///                   * Specify a function pointer to a user-defined function
///                     that will inspect the data and return the size.
///                     the function should have the following signature:
///                         size_t pfn_GetDatumSize(uint8_t* pCur, size_t len)
/// @param EXISTS   Specifies how the existance of the field is determined on input.
///                 There are a few possible ways to indicate the method:
///                   * Reference a field previously defined in the message that
///                     indicates the presence of the field.
///                     A boolean field set to true, or a non-zero integral
///                     value will indicate the field exists.
///                   * Specify a function pointer to a user-defined function
///                     that will inspect the data and return a boolean.
///                     the function should have the following signature:
///                         bool pfn_DoesOptionalDatumExist(uint8_t* pCur, size_t len)
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///
///             
#define ALCHEMY_ALLOC_OPT(TYPE,SIZE,EXISTS,NAME) \
                                        DECLARE_VECTOR_OPTIONAL(TYPE,SIZE,EXISTS,NAME)

//  ****************************************************************************
/// Adds an optional field that is not guaranteed to be present.  
///
/// This declaration supports dynamically allocated arrays (vector) with
/// a user specified memory allocator.
/// 
/// This MACRO generates code based on the type_list specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// Finally, a field is provided to specify how this datum will be able to tell
/// if the optional field is present.  
///             
/// @param TYPE       The type to use for this array field
/// @param ALLOCATOR  An allocator that will be used to allocate space for
///                   the dynamically sized field.
/// @param SIZE       Specifies how the size of the field is determined on input.
///                   There are a few possible ways to indicate the method:
///                     * Reference a field previously defined in the message that
///                       indicates the number of entries.
///                     * Specify a function pointer to a user-defined function
///                       that will inspect the data and return the size.
///                       the function should have the following signature:
///                         size_t pfn_GetDatumSize(uint8_t* pCur, size_t len)
/// @param EXISTS     Specifies how the existance of the field is determined on input.
///                   There are a few possible ways to indicate the method:
///                     * Reference a field previously defined in the message that
///                       indicates the presence of the field.
///                       A boolean field set to true, or a non-zero integral
///                       value will indicate the field exists.
///                     * Specify a function pointer to a user-defined function
///                       that will inspect the data and return a boolean.
///                       the function should have the following signature:
///                         bool pfn_DoesOptionalDatumExist(uint8_t* pCur, size_t len)
/// @param NAME       The name to assign this parameter in the message definition.
///                   NAME will be the name used to access this field directly.
///
///             
#define ALCHEMY_ALLOC_EX_OPT(TYPE,ALLOCATOR,SIZE,EXISTS,NAME) \
                                        DECLARE_ALLOCATED_OPTIONAL(TYPE,ALLOCATOR,SIZE,EXISTS,NAME)


//  ****************************************************************************
/// Starts the definition for a message field that represents a set of packed bits. 
///             
/// This definition builds a packed bit definition in place, and allows the user
/// to specify the size and names of each bit-field. This provides a very
/// convenient and natural way to interact with the named bit-fields in an expressive
/// manner.
///        
/// @param TYPE     The integer type to use for this field.
/// @param NAME     The name to assign to this bitset definition.
///        
/// @note           A current limitation requires that bit-sets, defined with this 
///                 MACRO definition, are performed in the *Hg* namespace.
///           
/// usage:
/// ~~~{.cpp}
///   
///   ALCHEMY_PACKED 
///   ( uint8_t, 
///     flags,
///     ALCHEMY_BITS   (0, is_visible, 1),
///     ALCHEMY_BITS   (1, is_light  , 1),
///     ALCHEMY_BITS   (2, ambient   , 3),
///     ALCHEMY_BITS   (3, diffuse   , 3)
///   );
///
/// ~~~     
///         
/// @remarks        There are a number of constructs that are created by the definition
///                 of this MACRO:
///                 1) container_size<> specialization to properly return the
///                    size of the data buffer required for the bitset.
///                    Otherwise the size of the BIT_SET object would be returned.
///                 2) field_data_t<> specialization that defines the 
///                    value_type and a data cache for the message field.
///                 3) The definition of the BIT_SET struct, which contains
///                    all of the named bit-field properties managed by the BIT_SET.
///                 4) If ALCHEMY_CARBONATE is defined before the Alchemy.h, 
///                    a set of C-linkable structs and utility functions will be
///                    generated and exported for use in a library.
///         
#define ALCHEMY_PACKED(TYPE, NAME, ...) DECLARE_PACKED(TYPE, NAME, C_,  __VA_ARGS__);\
                                        DECLARE_PACKED(TYPE, NAME, Hg_, __VA_ARGS__);

//  ****************************************************************************
/// Adds a bit-field type parameter to the bit-set.
/// 
/// This MACRO generates the code required to add a bit-field to a parent bit-set.
/// The name of the bit-field can be specified as well as the number of bits
/// this field should occupy.
///             
/// @param INDEX    The index of this bit-field in the definition.
/// @param NAME     The name to assign this parameter in the bit-set definition.
///                 NAME will be the name used to access this bit-field directly.
/// @param COUNT    The number of bits this Bit-Field occupies.
///             
#define ALCHEMY_BITS(INDEX,NAME,COUNT)\
                                        DECLARE_BIT_FIELD(INDEX, NAME, COUNT)


#endif
