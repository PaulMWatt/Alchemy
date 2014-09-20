/// @file Pb/detail/tr1_helper.h
/// Contains standard library definitions that may be missing for TR1 releases.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef TR1_HELPER_H_INCLUDED
#define TR1_HELPER_H_INCLUDED
//  Includes *******************************************************************

// TODO: Need to add more correct feature support detection for the various 
//       compilers that we are trying to support.

#if defined(_WIN32)

#if defined(_HAS_TR1)
#include <Pb/detail/conditional.h>
// TODO: I know this is just as bad as crossing the streams, but we'll fix this really soon.

namespace std
{
using Pb::conditional;
using namespace std::tr1;
}

typedef char                int8_t; 
typedef short               int16_t;
typedef long                int32_t;
typedef long long           int64_t;

typedef unsigned char       uint8_t; 
typedef unsigned short      uint16_t;
typedef unsigned long       uint32_t;
typedef unsigned long long  uint64_t;


#else
# include <cstdint>
#endif
#endif


#endif 
