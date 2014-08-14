/// @file Alchemy.h
/// 
/// Include this file for access to the alchemy message structure framework.
///
/// Alchemy is a message and structured data processing framework. 
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
///   - HG_BEGIN_FORMAT(TYPE_LIST)
///   - HG_MSG_FIELD(TYPE,PARAM)
///   - HG_END_FORMAT
///
/// Hg provides a portable bit-field interface that works by generating the
/// appropriate shift and mask operations for each field. Use these MACROS
/// to define a set of bit-fields that are packed into a user-specified integral type.
/// Hg currently is written to allow up to 32 bit-fields in a single parameter.
///
///   - HG_BEGIN_BIT_SET(TYPE,BITSET)
///   - HG_END_BIT_SET
///   - HG_BIT_FIELD(INDEX,COUNT,PARAM)
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
#include <detail/msg_def.h>

//  ****************************************************************************
/// Marks the beginning of a message format.
/// 
/// A MACRO used to start the definition for a message format interface. 
/// This definition requires that the parent class derive from the MsgFormat 
/// base class.
///             
/// @param TYPE_LIST         The TypeList used to defined the layout format.
///             
/// @note           This definition MACRO should be placed in the global or
///                 alchemy namespace.
/// ~~~{.cpp}
///   // Currently the BIT_SET definitions must occur in the *alchemy* namespace.
///   namespace Hg
///   {
///   // A TypeList definition provides a map to navigate the data structure,.
///   typedef TypeList
///   {
///     uint8_t,
///     uint8_t,
///     uint16_t,
///     uint32_t,
///     uint32_t,
///     uint32_t,
///     uint16_t,
///     uint8_t,
///     uint8_t,
///   } new_point_t;        
///
///   // Define the message data format
///   HG_BEGIN_FORMAT(new_point_t)
///     HG_DATUM (uint8_t,    msgType)              
///     HG_DATUM (uint8_t,    verNum)               
///     HG_DATUM (uint16_t,   id)            
///     HG_DATUM (uint32_t,   X)            
///     HG_DATUM (uint32_t,   Y)             
///     HG_DATUM (uint32_t,   Z)         
///     HG_DATUM (uint16_t,   flags)            
///     HG_DATUM (uint8_t,    priority)             
///     HG_DATUM (uint8_t,    count)      
///   END_MSG_FORMAT
///     
///   } // namespace Hg
/// ~~~
///             
#define HG_BEGIN_FORMAT(TYPE_LIST)      DECLARE_FORMAT_HEADER(TYPE_LIST)


//  ****************************************************************************
/// Adds a field to the message definition.
/// 
/// This MACRO generates code based on the TypeList specified in the 
/// HG_BEGIN_FORMAT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field.
///             
/// @param TYPE     The type to use for this field
/// @param PARAM    The name to assign this parameter in the message definition.
///                 PARAM will be the name used to access this field directly.
///             
#define HG_DATUM(TYPE,PARAM)            DECLARE_DATUM_FORMAT(TYPE,PARAM)

//  ****************************************************************************
/// Adds a field with a dynamic size to the message definition.
/// 
/// This MACRO generates code based on the TypeList specified in the 
/// HG_BEGIN_FORMAT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// Finally, a field is provided to specify how this datum will know how
/// large the field should be when reading data on input.
///             
/// @param TYPE     The type to use for this field
/// @param PARAM    The name to assign this parameter in the message definition.
///                 PARAM will be the name used to access this field directly.
/// @param DATUM_SZ Specifies how the size of the field is determined on input.
///                 There are a few possible ways to indicate the method:
///                   * Reference a field previously defined in the message that
///                     indicates the number of entries.
///                   * Specify a function pointer to a user-defined function
///                     that will inspect the data and return the size.
///                     the function should have the following signature:
///                         size_t pfn_GetDatumSize(uint8_t* pCur, size_t len)
///
///             
#define HG_DYN_DATUM(TYPE,PARAM,DATUM_SZ)\
                                        DECLARE_DYN_DATUM_FORMAT(TYPE,PARAM,DATUM_SZ)

//  ****************************************************************************
/// Adds a fixed-size array field to the message definition.
/// 
/// This MACRO generates code based on the TypeList specified in the 
/// HG_BEGIN_FORMAT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field.
///             
/// @param TYPE     The type to use for this field
/// @param COUNT    The number of elements allocated for the array.
/// @param PARAM    The name to assign this parameter in the message definition.
///                 PARAM will be the name used to access this field directly.
///             
#define HG_ARRAY(TYPE,COUNT,PARAM)      DECLARE_ARRAY_FORMAT(TYPE,COUNT,PARAM)


//  ****************************************************************************
/// Marks the end of a message format.
/// 
/// A MACRO used to end the definition for a message format interface.
/// This MACRO adds no functionality, it simply acts as a bookend to indicate 
/// the end of the message format definition.
/// 
/// This MACRO will verify that all of the entries have been configured in the
/// data format definition. A compiler error will be emitted if the number 
/// of declared HG_MSG_FIELD entries does not match the number expected.
/// 
#define HG_END_FORMAT                   DECLARE_FORMAT_FOOTER


//  ****************************************************************************
/// Starts the definition for a message field that represents a set of bit-fields. 
///             
/// This definition builds a BitSet definition in place, and allows the user
/// to specify the size and names of each bit-field. This provides a very
/// convenient and natural way to interact with the named bit-fields in an expressive
/// manner.
///        
/// @param TYPE     The integer type to use for this field.
/// @param BITSET   The name to assign to this bitset definition.
///        
/// @note           A current limitation requires that bit-sets, defined with this 
///                 MACRO definition, are performed in the *Hg* namespace.
///           
/// usage:
/// ~~~{.cpp}
///   // The BIT_SET definitions must occur in the *Hg* namespace.
///   namespace Hg
///   {
///   
///   HG_BEGIN_BIT_SET (uint8_t, flags)
///     HG_BIT_FIELD   (0,1,   is_visible)
///     HG_BIT_FIELD   (1,1,   is_light)
///     HG_BIT_FIELD   (2,3,   ambient)
///     HG_BIT_FIELD   (3,3,   diffuse)
///   HG_END_BIT_SET
///     
///   } // namespace Hg
/// ~~~     
///         
/// @remarks        There are four constructs that are created by the definition
///                 of this MACRO:
///                 1) type_container<> specialization for the BIT_SET
///                 2) ContainerSize<> specialization to properly return the
///                    size of the data buffer required for the bitset.
///                    Otherwise the size of the BIT_SET object would be returned.
///                 3) NestedFieldData<> specialization that defines the 
///                    value_type and a data cache for the message field.
///                 4) The definition of the BIT_SET struct, which contains
///                    all of the named bit-field properties managed by the BIT_SET.
///         
#define HG_BEGIN_BIT_SET(TYPE,BITSET)   DECLARE_BIT_SET_HEADER(TYPE,BITSET)


//  ****************************************************************************
/// Adds a bit-field type parameter to the bit-set.
/// 
/// This MACRO generates the code required to add a bit-field to a parent bit-set.
/// The name of the bit-field can be specified as well as the number of bits
/// this field should occupy.
///             
/// @param INDEX    The index of this bit-field in the definition.
/// @param PARAM    The name to assign this parameter in the bit-set definition.
///                 PARAM will be the name used to access this bit-field directly.
/// @param COUNT    The number of bits this Bit-Field occupies.
///             
#define HG_BIT_FIELD(INDEX,PARAM,COUNT)\
                                        DECLARE_BIT_FIELD(INDEX, PARAM, COUNT)


//  ****************************************************************************
/// Ends the definition for a message field that represents a set of bit-fields.
///             
/// A type container specialization is declared for this class to facilitate
/// the proper calculation of the internal buffer size for the container.
/// 
#define HG_END_BIT_SET                  DECLARE_BIT_SET_FOOTER



#endif
