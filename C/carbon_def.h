// @file C/carbon_def.h
// 
// Internal implementation MACROS for C-linkable structs and function calls.
// 
// Contains declaration MACROs implementation to define data structure formats.
// The implementations are hidden behind a second layer to simplify the 
// header file the user will interact with.
// 
// @note           This header file must not be included directly and the 
//                 MACROS defined in this file should not be accessed
//                 directly. Include and used the definitions from the file
//                 **<Carbon.h>** instead.
//           
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef CARBON_DEF_H_INCLUDED
#define CARBON_DEF_H_INCLUDED
//  Private Usage Include Guard ************************************************
//  Only allow this header file to be included through Alchemy.h
#ifndef ALCHEMY_H_INCLUDED
# error Do not include this file directly. Use <Alchemy.h> instead
#endif


//  ****************************************************************************
//  If carbon is enabled, generate the extra C-types that are required.
//  
#if defined(ALCHEMY_CARBONATE)

#include <Pb/meta_macros.h>

//  ****************************************************************************
//  Utility Constructs For Use With Carbon Types *******************************
//  ****************************************************************************
//  Typedefs *******************************************************************

// TODO: Return with the proper def.
//typedef size_t (*pfnGetDatumSize)(const uint8_t*, size_t);


#define EACH_C_PARAM(r, data, i, x) \
  BOOST_PP_TUPLE_ELEM(2,0,x) BOOST_PP_TUPLE_ELEM(2,1,x); 


#if defined(_MSC_VER)

#define DEFINE_C_STRUCT_PARAMS(S) \
  BOOST_PP_SEQ_FOR_EACH_I(EACH_C_PARAM, unused, BOOST_PP_VARIADIC_TO_SEQ(S))

#else

#define DEFINE_C_STRUCT_PARAMS(...) \
  BOOST_PP_SEQ_FOR_EACH_I(EACH_C_PARAM, unused, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))

#endif



//  ****************************************************************************
//  Abstracted Message Definition MACROS ***************************************
//  Simplified user MACROS use these definitions.
//  These definitions have been abstracted to simplify the user header files.
//  ****************************************************************************

//  ****************************************************************************
//  Defines the outer value container as well as the formatted type-list.
//
#ifdef __cplusplus
#define C_DECLARE_STRUCT_HEADER(F, ...)                                        \
  extern "C" typedef struct tag_##F                                            \
  {                                                                            \
    DEFINE_C_STRUCT_PARAMS(__VA_ARGS__)                                        \
  C_DECLARE_STRUCT_FOOTER(F)

#else
#define C_DECLARE_STRUCT_HEADER(F, ...)                                        \
  typedef struct tag_##F                                                       \
  {                                                                            \
    DEFINE_C_STRUCT_PARAMS(__VA_ARGS__)                                        \
  C_DECLARE_STRUCT_FOOTER(F)
#endif

//  ****************************************************************************
#define C_DECLARE_STRUCT_FOOTER(F)                                             \
  } F;                                                                         \
  extern const uint32_t k_##F##_id


//  ****************************************************************************
#define C_DATUM_X(T,P)                          (T,P)

//  ****************************************************************************
#define C_DECLARE_DATUM(T,P)                    C_DATUM_X(T,P)

//  ****************************************************************************
#define C_DECLARE_ARRAY_DATUM(T, N, P)          C_DATUM_X(T,P[N])

//  ****************************************************************************
#define C_DECLARE_VECTOR_DATUM(T, N, P)         C_DATUM_X(T*, P)

//  ****************************************************************************
#define C_DECLARE_ALLOCATOR_DATUM(T, A, N, P)   C_DECLARE_ALLOC(T, N, P)


//  ****************************************************************************
//  Bit Fields *****************************************************************
//  ****************************************************************************

// TODO: Working on a solution for bit-field definitions.
#ifdef __cplusplus

# define C_DECLARE_PACKED_HEADER(T,C)       extern "C" typedef T C;
# define C_DECLARE_BIT_FIELD(IDX,P,N)
# define C_DECLARE_PACKED_FOOTER                            
 
#else

# define C_DECLARE_PACKED_HEADER(T,C)       typedef T C;
# define C_DECLARE_BIT_FIELD(IDX,P,N)
# define C_DECLARE_PACKED_FOOTER                            

#endif 
//#define DECLARE_C_PACKED_HEADER(T,C)                                           \
//  typedef struct tag_##C                                                       \
//  {                                                                            \
//    
//// TODO: Need to determine a way to declare the storage type.
//// *****************************************************************************
//#define DECLARE_C_BIT_FIELD(IDX,P,N)        unsigned int P : N;
//
//// *****************************************************************************
//#define DECLARE_C_PACKED_FOOTER                                                \
//  } color4;

#else

//  ****************************************************************************
//  Carbon has not been enabled. 
//  Define empty code generation MACROS
//
# define C_DECLARE_STRUCT_HEADER(F, ...) 
# define C_DECLARE_STRUCT_FOOTER(F)

# define C_DATUM_X(T,P)                  
# define C_DECLARE_DATUM(T,P)            
# define C_DECLARE_ARRAY(T, N, P)        
# define C_DECLARE_DYNAMIC(T, N, P)      
# define C_DECLARE_ALLOCATOR(T, A, N, P) 

# define C_DECLARE_PACKED_HEADER(T,C)  
# define C_DECLARE_BIT_FIELD(IDX,P,N)
# define C_DECLARE_PACKED_FOOTER                            

#endif


#endif