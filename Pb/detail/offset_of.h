/// @file Pb/detail/offset_of.h
///
/// Defines the *most* portable version of offsetof possible for the platform.
/// As it is, offsetof, is not a portable or safe MACRO to use.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef OFFSET_OF_H_INCLUDED
# error "Do not include this file directly. Use <Pb/offset_of.h> instead"
#endif

//  Includes *******************************************************************
# include<cstddef>

#ifdef  __GNUC__

#ifdef offsetof
#undef offsetof
#endif

// GCC does not approve of the way in which Alchemy employs this MACRO.
// This is a slight alteration:
// Performing the calculation on a non-null value.
#define offsetof(type,member) (size_t)reinterpret_cast<const char*>((((type*)1)->member)-1); 

#endif
