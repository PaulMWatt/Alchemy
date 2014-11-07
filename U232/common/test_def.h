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

typedef TypeList 
        <
          uint8_t,      
          uint8_t,      
          uint16_t,     
          uint32_t      
        > Basic_format;
 
typedef TypeList 
        <
          uint32_t,     
          Basic_format, 
          uint16_t,     
          uint8_t,      
          uint8_t     
        > Nested_format;

HG_BEGIN_BIT_SET (uint8_t, Bits_type_a)
  HG_BIT_FIELD   (Bits_type_a, 0,   a_one,   1)
  HG_BIT_FIELD   (Bits_type_a, 1,   a_two,   2)
  HG_BIT_FIELD   (Bits_type_a, 2,   a_three, 3)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint32_t, Bits_type_b)
  HG_BIT_FIELD   (Bits_type_b, 0,   b_one,   4)
  HG_BIT_FIELD   (Bits_type_b, 1,   b_two,   5)
  HG_BIT_FIELD   (Bits_type_b, 2,   b_three, 6)
  HG_BIT_FIELD   (Bits_type_b, 3,   b_four,  2)
  HG_BIT_FIELD   (Bits_type_b, 4,   b_five,  3)
  HG_BIT_FIELD   (Bits_type_b, 5,   b_six,   4)
HG_END_BIT_SET

typedef TypeList 
        <
          Bits_type_a,
          Bits_type_b
        > Bitset_format; 

typedef TypeList 
        <
          uint8_t,
          uint16_t,
          Bitset_format
        > Nested_bitset_format; 

typedef TypeList
        <
          uint8_t,            
          uint8_t,      
          uint16_t,     
          Bits_type_a,  
          Nested_format   
        > Compound_format;

typedef TypeList
        <
          uint8_t,        
          Compound_format
        > Nested_compound_format;


} // namespace Hg


#endif