/// @file Pb/detail/uses_exceptions.h
/// Conditional header file to enable exception handling.
///
/// Exception handling is disabled by default in Alchemy because it's initial
/// and primary target usage is for embedded communication devices such as
/// routers and modems.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef USES_EXCEPTIONS_H_INCLUDED
#define USES_EXCEPTIONS_H_INCLUDED
//  Includes *******************************************************************
#include <utility>

// Enable Exception Support
// If there are other compiler pre-processor definitions
// that are used to control exception handling support, 
// add there definition to the clause below.

#ifdef _USES_EXCEPTIONS
# define ALCHEMY_USES_EXCEPTIONS
#endif


#endif 
