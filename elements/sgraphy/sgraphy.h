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

ALCHEMY_PACKED
( byte_t, 
  s_data,
  ALCHEMY_BITS(0, d0, 2),
  ALCHEMY_BITS(1, d1, 2),
  ALCHEMY_BITS(2, d2, 2),
  ALCHEMY_BITS(3, d3, 2)
);

#endif
