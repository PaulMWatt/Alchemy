/// @file Carbon.h
/// 
/// Carbon generates c-linkable interfaces for constructs generated by Alchemy.
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
#ifndef CARBON_H_INCLUDED
#define CARBON_H_INCLUDED

/// This MACRO enables Carbon definitions for C-linkable APIs.
#define ALCHEMY_CARBONATE 1

//  Includes ******************************************************************
#include <C/carbon_def.h>

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
///
///   // Define the message data format
///   HG_BEGIN_FORMAT(new_point_t,
///     HG_DATUM (uint8_t,    msgType),
///     HG_DATUM (uint8_t,    verNum),
///     HG_DATUM (uint16_t,   id),
///     HG_DATUM (uint32_t,   X),
///     HG_DATUM (uint32_t,   Y),
///     HG_DATUM (uint32_t,   Z),
///     HG_DATUM (uint16_t,   flags),
///     HG_DATUM (uint8_t,    priority),
///     HG_DATUM (uint8_t,    count)
///   )
///     
///   } // namespace Hg
/// ~~~
///             
#define HG_BEGIN_FORMAT(NAME, ...)  DECLARE_STRUCT_HEADER(NAME, __VA_ARGS__)


//  ****************************************************************************
/// Adds a field to the message definition.
/// 
/// This MACRO generates code based on the TypeList specified in the 
/// HG_BEGIN_FORMAT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field.
///             
/// @param TYPE     The type to use for this field
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///             
#define HG_DATUM(TYPE,NAME)            D_DATUM(TYPE,NAME)

//  ****************************************************************************
/// Adds a fixed-size array field to the message definition.
/// 
/// This MACRO generates code based on the TypeList specified in the 
/// HG_BEGIN_FORMAT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field.
///             
/// @param TYPE     The type to use for this field
/// @param COUNT    The number of elements allocated for the array.
/// @param NAME     The name to assign this parameter in the message definition.
///                 NAME will be the name used to access this field directly.
///             
#define HG_ARRAY(TYPE,COUNT,NAME)      DECLARE_ARRAY_ENTRY(TYPE,COUNT,NAME)


#endif
