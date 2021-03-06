/// @file meta/compiler.h
/// This file contains any macros that can be used to improve the clarity of 
/// code or ease for debugging purposes.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef COMPILER_H_INCLUDED
#define COMPILER_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/detail/endianess.h>
#include <Pb/detail/tr1_helper.h>
#include <Pb/detail/auto.h>
#include <Pb/detail/decltype.h>
#include <Pb/detail/static_assert.h>
#include <Pb/detail/explicit_conversion.h>
#include <Pb/detail/alias_templates.h>
#include <Pb/detail/variadic_templates.h>
#include <Pb/detail/range_for.h>
#include <Pb/detail/rvalue_ref.h>
#include <Pb/detail/trailing_fn_return.h>


//  ****************************************************************************
//  Reference for compiler flags and versions.
//
//  MSVC++ 12.0 _MSC_VER == 1800 (Visual Studio 2013)
//  MSVC++ 11.0 _MSC_VER == 1700 (Visual Studio 2012)
//  MSVC++ 10.0 _MSC_VER == 1600 (Visual Studio 2010)
//  MSVC++ 9.0  _MSC_VER == 1500 (Visual Studio 2008)
//


// CxxUnit Testing *************************************************************
// Change the mock namespace from T to cxx to reduce confusion with template semantics. 
#define CXXTEST_MOCK_NAMESPACE cxx

// PRAGMA Define for use in MACROS *********************************************
#ifdef _MSC_VER
# define DO_PRAGMA(x) __pragma(x)
#elif defined(__GCC__)
# define DO_PRAGMA(x) _Pragma(x)
#else
# define DO_PRAGMA(x)
#endif

// Stringize Helper ************************************************************
#define STR2_(x) #x
#define STR1_(x) STR2_(x)

#define WSTR2_(x) L ## x
#define WSTR1_(x) _T(x)

// Notice And TODO Macro *******************************************************
// The notice macro set will display a message in the compiler
// output window that you may click to take you immediately to 
// the line in the file where the message is located.
// 
// These messages will only be printed for DEBUG builds.
// 

#ifdef _DEBUG
// This message will be printed to the debug window.
//		NOTICE: This is a notice!
#define NOTICE(str) DO_PRAGMA(message(__FILE__ "(" STR1_(__LINE__) "): NOTICE: " str))

// This message will be printed to the debug window.
//		TODO: This is a notice!
#define TODO(str) DO_PRAGMA(message(__FILE__ "(" STR1_(__LINE__) "): TODO: " str))

#else
#define NOTICE(str)
#define TODO(str)
#endif

// Compiler Dependant Type Definitions *****************************************

#endif //__COMPILER_H

// Macros for conditional compilation on different platforms *******************
#ifdef UNDER_CE
  // Removes severe warnings on CE
# ifndef _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA
#   define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA
# endif

  // Set a windows version to remove certain warnings.
# ifndef WINVER
#   define WINVER 0x0400
# endif
  
# undef _WIN32_WINDOWS
# undef _WIN32_WINNT

# ifdef WIN32_PLATFORM_PSPC
#   ifndef SHELL_AYGSHELL
#     define SHELL_AYGSHELL
#   endif
# endif

#elif defined(_WIN32)
  // Set windows XP as the default version if one is not yet defined.
# ifndef WINVER
#   define WINVER 0x0501
# endif
  
# ifndef UNDER_NT
#   define UNDER_NT
# endif
  
#elif defined(linux)
# ifndef UNDER_LINUX
#   define UNDER_LINUX
# endif

#elif defined(apple_ios)
# ifndef UNDER_APPLE_IOS
#   define UNDER_APPLE_IOS
# endif

#elif defined(SOLARIS)
# ifndef UNDER_SOLARIS
#   define UNDER_SOLARIS
# endif

#else
# error Must add definition to indicate platform.
#endif


#if defined(__cplusplus)

// STL Definitions *************************************************************
#ifdef _WIN32
# define BOOST_NO_STD_TYPEINFO
#endif

//   Add definitions to disable exception handling in the STL 
//   implementations on CE.
#ifdef UNDER_CE
  #define BOOST_NO_EXCEPTION_STD_NAMESPACE
	#if _WIN32_WCE < 0x500 && _MSC_VER > 1220 
	// only needed for WM2003 builds under VS2005 
	#pragma comment(lib, "ccrtrtti.lib") 
	#else

	#ifdef _HAS_EXCEPTIONS
		#undef _HAS_EXCEPTIONS
	#endif /* _HAS_EXCEPTIONS */

	#define _HAS_EXCEPTIONS  0
	//   These extra inclusions and redefinitions need to occur
	//   for eVC4.0 and CE.Net4.2.
	#if (_WIN32_WCE <= 0x420)

		// These macros are defined in here:
		//#define _TRY_BEGIN	try {
		//#define _CATCH(x)	} catch (x) {
		//#define _CATCH_ALL	} catch (...) {
		//#define _CATCH_END	}
		//#define _RAISE(x)	throw (x)
		//#define _RERAISE	throw
		#include <xstddef>

		// Undefine them, and redefine with macros that will do nothing.
		#ifdef _TRY_BEGIN
		#undef _TRY_BEGIN
		#endif

		#define _TRY_BEGIN {

		#ifdef _CATCH_ALL
		#undef _CATCH_ALL
		#endif

		#define _CATCH_ALL } if(0) {

		#ifdef _RAISE
		#undef _RAISE
		#endif

		#define _RAISE(x)	(x)

		#ifdef _RERAISE
		#undef _RERAISE
		#endif

		#define _RERAISE

		#ifdef _CATCH_END
		#undef _CATCH_END
		#endif

		#define _CATCH_END }

	#endif

	#endif
#endif

// Compiler Dependent Settings *************************************************

#ifdef _WIN32
// Disable windows definition of the min/max macros in favor of std templates.
# define NOMINMAX
#ifdef min
# undef min
#endif

#ifdef max
# undef max
#endif

# include <algorithm>
using std::min;
using std::max;
#endif

// Create a definition for __stdcall calling convention.
#ifndef _WIN32
# define __stdcall
#endif

#endif 
