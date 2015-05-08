// @file C/carbon_def.h
// 
// Internal implementation MACROS for C-linkable structs and function calls.
// 
// @note           This header file must not be included directly and the 
//                 MACROS defined in this file should not be accessed
//                 directly. Include and used the definitions from the file
//                 **<Carbon.h>** instead.
//           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef CARBONATE_H_INCLUDED
#define CARBONATE_H_INCLUDED

//  Includes *******************************************************************
#include <Pb/detail/endianess.h>
#include <stdint.h>

#include <Alchemy.h>

#else

/// This MACRO enables Carbon definitions for C-linkable APIs.
#define ALCHEMY_CARBONATE 1

// TODO: Cleanup final Carbon/Alchemy header organization.
#define ALCHEMY_H_INCLUDED
//#ifdef ALCHEMY_H_INCLUDED

#ifdef ALCHEMY_STRUCT
# undef ALCHEMY_STRUCT
#endif

#ifdef ALCHEMY_DATUM
# undef ALCHEMY_DATUM
#endif

#ifdef ALCHEMY_ARRAY
# undef ALCHEMY_ARRAY
#endif

#ifdef ALCHEMY_ALLOC
# undef ALCHEMY_ALLOC
#endif

#ifdef ALCHEMY_ALLOC_EX
# undef ALCHEMY_ALLOC_EX
#endif

#ifdef ALCHEMY_END_STRUCT
# undef ALCHEMY_END_STRUCT
#endif

#ifdef ALCHEMY_PACKED
# undef ALCHEMY_PACKED
#endif

#ifdef ALCHEMY_BITS
# undef ALCHEMY_BITS
#endif

#ifdef ALCHEMY_END_PACKED
# undef ALCHEMY_END_PACKED
#endif

//#endif

//  Includes ******************************************************************
//#include <Alchemy.h>
#include <C/carbon_def.h>
#include <Hg/msg_def.h>


//  ****************************************************************************
//  TODO: Need to find someplace for these MACROS to live out of sight.

//#if defined(_MSC_VER)
//
//#define STRUCT_PARAMS(NAME, EL,S) \
//  (NAME BOOST_PP_SEQ_FOR_EACH_I(ELEMENTAL_PARAM, EL, S))
//
//#else
//
//#define DEFINE_STRUCT_PARAMS(...) \
//  (NAME BOOST_PP_SEQ_FOR_EACH_I(ELEMENTAL_PARAM, EL, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__)))
//
//#endif


////  ****************************************************************************
//#define ELEMENTAL_PARAM(r, data, i, x) \
//   , BOOST_PP_CAT(data, x)
//
//
//// TODO: It's possible, GCC may accept this form
//#define STRUCT_PARAMS(NAME, EL,S) \
//  (NAME BOOST_PP_SEQ_FOR_EACH_I(ELEMENTAL_PARAM, EL, S))
//
//#define DECLARE_STRUCT(NAME, EL, ...)                                          \
//  EL##DECLARE_STRUCT_HEADER                                                    \
//    STRUCT_PARAMS(NAME, EL,BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))
//
////  ****************************************************************************
//

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
///   ALCHEMY_STRUCT(new_point_t,
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
///   } // namespace Hg
/// ~~~
///             
#define ALCHEMY_STRUCT(NAME, ...)       DECLARE_STRUCT(NAME, C_,  __VA_ARGS__);\
                                        DECLARE_STRUCT(NAME, Hg_, __VA_ARGS__);




//  ****************************************************************************
/// Adds a field to the message definition.
/// 
/// This MACRO generates code based on the TypeList specified in the 
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
/// This MACRO generates code based on the TypeList specified in the 
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
/// This MACRO generates code based on the TypeList specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// Finally, a field is provided to specify how this datum will know how
/// large the field should be when reading data on input.
///             
/// @param TYPE     The type to use for this field
/// @param COUNT    Specifies how the size of the field is determined on input.
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
#define ALCHEMY_ALLOC(TYPE,COUNT,NAME)\
                                        DECLARE_VECTOR_DATUM(TYPE,COUNT,NAME)


//  ****************************************************************************
/// Adds a field with a dynamic size controlled by a user specified allocator.
/// 
/// This MACRO generates code based on the TypeList specified in the 
/// ALCHEMY_STRUCT MACRO. This MACRO also provides the user the ability to 
/// name the property associated with this message format field. 
/// A field is provided for the user to indicate how the field can determine
/// its own size. This MACRO is similar to ALCHEMY_ALLOC, with the exception
/// that a user specified allocator can be used.
///             
/// @param TYPE       The type to use for this field
/// @param ALLOCATOR  An allocator that will be used to allocate space for
///                   the dynamically sized field.
/// @param COUNT      Specifies how the size of the field is determined on input.
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
#define ALCHEMY_ALLOC_EX(TYPE,ALLOCATOR,COUNT,NAME)\
                                        DECLARE_ALLOCATOR_DATUM(TYPE,ALLOCATOR,COUNT,NAME)


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
#define ALCHEMY_END_STRUCT(TYPE_LIST)  DECLARE_STRUCT_FOOTER(TYPE_LIST)


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
///   // The BIT_SET definitions must occur in the *Hg* namespace.
///   namespace Hg
///   {
///   
///   HG_BEGIN_PACKED (uint8_t, flags)
///     HG_BIT_FIELD   (0, is_visible, 1)
///     HG_BIT_FIELD   (1, is_light  , 1)
///     HG_BIT_FIELD   (2, ambient   , 3)
///     HG_BIT_FIELD   (3, diffuse   , 3)
///   HG_END_PACKED   (flags)
///     
///   } // namespace Hg
/// ~~~     
///         
/// @remarks        There are three constructs that are created by the definition
///                 of this MACRO:
///                 1) ContainerSize<> specialization to properly return the
///                    size of the data buffer required for the bitset.
///                    Otherwise the size of the BIT_SET object would be returned.
///                 2) field_data_t<> specialization that defines the 
///                    value_type and a data cache for the message field.
///                 3) The definition of the BIT_SET struct, which contains
///                    all of the named bit-field properties managed by the BIT_SET.
///         
#define ALCHEMY_PACKED(TYPE,NAME)      C_DECLARE_PACKED_HEADER(TYPE,NAME)

#define C_BEGIN_PACKED(TYPE,NAME)      C_DECLARE_PACKED_HEADER(TYPE,NAME)


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
                                        C_DECLARE_BIT_FIELD(INDEX, NAME, COUNT)

#define C_BIT_FIELD(INDEX,NAME,COUNT)\
                                        C_DECLARE_BIT_FIELD(INDEX, NAME, COUNT)


//  ****************************************************************************
/// Ends the definition for a message field that represents a set of packed bits.
///             
/// A type container specialization is declared for this class to facilitate
/// the proper calculation of the internal buffer size for the container.
/// 
#define ALCHEMY_END_PACKED              C_DECLARE_PACKED_FOOTER

#define C_END_PACKED                    C_DECLARE_PACKED_FOOTER


#endif
