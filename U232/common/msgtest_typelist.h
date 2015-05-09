//  @file msgtest_TypeList.h
//  
//  This is a helper file for tests with type definitions.
// 
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MSGTEST_TypeList_H_INCLUDED
#define MSGTEST_TypeList_H_INCLUDED

//  Test Types *****************************************************************
// A current limitation for the Hg definitions are they must be defined in 
// the Hg namespace.
ALCHEMY_PACKED 
( uint32_t, 
  mixed_bits,
  ALCHEMY_BITS   (0,   first,   5),
  ALCHEMY_BITS   (1,   second,  4),
  ALCHEMY_BITS   (2,   third,   3),
  ALCHEMY_BITS   (3,   fourth,  2),
  ALCHEMY_BITS   (4,   fifth,   1),
  ALCHEMY_BITS   (5,   sixth,   1),
  ALCHEMY_BITS   (6,   seventh, 1)
);

//  ****************************************************************************
//  A type array used to create the nested message field.
//
ALCHEMY_STRUCT(nested_format_t,
  ALCHEMY_DATUM (uint8_t, zero),
  ALCHEMY_DATUM (uint16_t, one),
  ALCHEMY_DATUM (mixed_bits, two),      // Extra bytes are required after this field to test offsets.
  ALCHEMY_DATUM (uint32_t, three),
  ALCHEMY_DATUM (int16_t, four)
)

//  ****************************************************************************
//  A type list definition for a single entry message.
// 
ALCHEMY_STRUCT(single_t,
  ALCHEMY_DATUM (uint32_t, only)
)

//  ****************************************************************************
//  A type list definition for a single nested message.
// 
ALCHEMY_STRUCT(single_nested_t,
  ALCHEMY_DATUM (nested_format_t, only)
)

//  ****************************************************************************
//  Bitlist with a single entry 
// the Hg namespace.
ALCHEMY_PACKED 
( uint8_t, 
  single_bit,
  ALCHEMY_BITS   (0, lonely, 1)
);


ALCHEMY_STRUCT(single_bit_t,
  ALCHEMY_DATUM (single_bit, only)
)

//  ****************************************************************************
//  A type list used to verify the sequence containers.
//
ALCHEMY_STRUCT(point_format_t,
  ALCHEMY_DATUM (uint32_t, X),
  ALCHEMY_DATUM (uint32_t, Y),
  ALCHEMY_DATUM (uint32_t, Z)
)

//  ****************************************************************************
//  A type list definition that defines a single array as the only field.
// 
ALCHEMY_STRUCT(single_array_t,
  ALCHEMY_ARRAY (point_format_t, 2, line)
)


#endif
