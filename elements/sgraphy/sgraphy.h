/// @file sgraphy.h 
///
/// Utility definitions for the application.
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef SGRAPHY_H_INCLUDED
#define SGRAPHY_H_INCLUDED
// Includes ********************************************************************
#include <Alchemy.h>

HG_BEGIN_PACKED(byte_t, s_data)
  HG_BIT_FIELD(0, d0, 2)
  HG_BIT_FIELD(1, d1, 2)
  HG_BIT_FIELD(2, d2, 2)
  HG_BIT_FIELD(3, d3, 2)
HG_END_PACKED

#endif
