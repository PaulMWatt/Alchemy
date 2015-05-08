/// @file Pb/detail/endianess.h
/// Defines the endianess of the local platform.
///
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef ENDIANESS_H_INCLUDED
#define ENDIANESS_H_INCLUDED

// Determine Processor *********************************************************
#define ALCHEMY_CPU_ARM        1
#define ALCHEMY_CPU_X86        2
// Definition to make comparisons simpler.  
// This value can increase as more l-endian CPUs are added.
#define ALCHEMY_CPU_BIG_ENDIAN 3   

// Determine the processor type based on compiler flags.  This code has been 
// adapted from the POSH portable framework from: http://www.poshlib.org
// New definitions will be required for CPUs that are not defined here.
#if defined ARM || defined __arm__ || defined _ARM
#  define ALCHEMY_CPU        ALCHEMY_CPU_ARM
#  define ALCHEMY_CPU_STRING "ARM"
#endif

#if defined __X86__ || defined __i386__ || defined i386 || defined _M_IX86 || defined __386__ || defined __x86_64__ || defined _M_X64
#  define ALCHEMY_CPU        ALCHEMY_CPU_X86
#  define ALCHEMY_CPU_STRING "Intel 386+"
#endif

#ifndef ALCHEMY_CPU
#  error ALCHEMY_CPU not defined.  Please add definition
#endif

// Determine Support for 64-bit ************************************************



// Determine Endianess *********************************************************
#define ALCHEMY_BIG_ENDIAN     1
#define ALCHEMY_LITTLE_ENDIAN  2
// Attempt to infer endianess by comparing the processor type and/or OS.
// Some processors are bi-endian, such as MIPS, this may cause trouble in the future.
#if (ALCHEMY_CPU < ALCHEMY_CPU_BIG_ENDIAN) || defined(_WIN32)
#  define ALCHEMY_ENDIANESS ALCHEMY_LITTLE_ENDIAN
#  define ORDER_DCBA
#else
#  define ALCHEMY_ENDIANESS ALCHEMY_BIG_ENDIAN
#endif


//  Constants ******************************************************************
/// This set contains constant definitions for each type of endian processor
/// supported by these conversion functions. 
/// 
#ifdef __cplusplus
enum Endianess
{
  k_big_endian    = ALCHEMY_BIG_ENDIAN,      ///< Indicates Big-Endian byte-order
  k_little_endian = ALCHEMY_LITTLE_ENDIAN    ///< Indicates Little-Endian byte-order
};

#else 
# define k_big_endian      ALCHEMY_BIG_ENDIAN
# define k_little_endian   ALCHEMY_LITTLE_ENDIAN

#endif

#endif 
