//  @file test_def.h
//  
//  Test suite to verify functionality for small template meta-programming tools.
//  
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//   
//  ************************************************************************
#ifndef TEST_DEF_H_INCLUDED
#define TEST_DEF_H_INCLUDED

#include <alchemy.h>

namespace Hg
{

typedef type_list 
        <
          uint8_t,      
          uint8_t,      
          uint16_t,     
          uint32_t      
        > Basic_format;
 
typedef type_list 
        <
          uint32_t,     
          Basic_format, 
          uint16_t,     
          uint8_t,      
          uint8_t     
        > Nested_format;

} // namespace Hg

ALCHEMY_PACKED 
( uint8_t, 
  Bits_type_a,
  ALCHEMY_BITS   (0,   a_one,   1),
  ALCHEMY_BITS   (1,   a_two,   2),
  ALCHEMY_BITS   (2,   a_three, 3)
);

ALCHEMY_PACKED 
( uint32_t, 
  Bits_type_b,
  ALCHEMY_BITS   (0,   b_one,   4),
  ALCHEMY_BITS   (1,   b_two,   5),
  ALCHEMY_BITS   (2,   b_three, 6),
  ALCHEMY_BITS   (3,   b_four,  2),
  ALCHEMY_BITS   (4,   b_five,  3),
  ALCHEMY_BITS   (5,   b_six,   4)
);

namespace Hg
{

typedef type_list 
        <
          Bits_type_a,
          Bits_type_b
        > Bitset_format; 

typedef type_list 
        <
          uint8_t,
          uint16_t,
          Bitset_format
        > Nested_bitset_format; 

typedef type_list
        <
          uint8_t,            
          uint8_t,      
          uint16_t,     
          Bits_type_a,  
          Nested_format   
        > Compound_format;

typedef type_list
        <
          uint8_t,        
          Compound_format
        > Nested_compound_format;


} // namespace Hg


#endif