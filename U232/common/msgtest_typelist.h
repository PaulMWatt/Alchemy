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
namespace Hg
{

HG_BEGIN_BIT_SET (uint32_t, mixed_bits)
  HG_BIT_FIELD   (mixed_bits, 0,   first,   5)
  HG_BIT_FIELD   (mixed_bits, 1,   second,  4)
  HG_BIT_FIELD   (mixed_bits, 2,   third,   3)
  HG_BIT_FIELD   (mixed_bits, 3,   fourth,  2)
  HG_BIT_FIELD   (mixed_bits, 4,   fifth,   1)
  HG_BIT_FIELD   (mixed_bits, 5,   sixth,   1)
  HG_BIT_FIELD   (mixed_bits, 6,   seventh, 1)
HG_END_BIT_SET

//  ****************************************************************************
//  A type array used to create the nested message field.
//
typedef TypeList
<
  uint8_t,      
  uint16_t,     
  mixed_bits,        // Extra bytes are required after this field to test offsets.
  uint32_t,
  int16_t
> nested_format_t;

HG_BEGIN_FORMAT(nested_format_t)
  HG_DATUM (uint8_t, zero)
  HG_DATUM (uint16_t, one)
  HG_DATUM (mixed_bits, two)
  HG_DATUM (uint32_t, three)
  HG_DATUM (int16_t, four)
HG_END_FORMAT(nested_format_t)

//  ****************************************************************************
//  A type array used to create the base message field.
// 
//  The entry, HG_TYPE_ARRAY(size_t, 3), defined below is equivalent to this:
//
//      array<size_t, 3>
//
typedef TypeList
<
  uint32_t,
  uint32_t,
  uint32_t,
  uint8_t,
  nested_format_t,
  std::array<uint32_t, 3>
> base_format_t;


//  ****************************************************************************
//  A type list definition for a single entry message.
// 
typedef TypeList
<
  uint32_t      
> single_t;

HG_BEGIN_FORMAT(single_t)
  HG_DATUM (uint32_t, only)
HG_END_FORMAT(single_t)

//  ****************************************************************************
//  A type list definition for a single nested message.
// 
typedef TypeList
<
  nested_format_t      
> single_nested_t;

HG_BEGIN_FORMAT(single_nested_t)
  HG_DATUM (nested_format_t, only)
HG_END_FORMAT(single_nested_t)

//  ****************************************************************************
//  Bitlist with a single entry 
// the Hg namespace.
HG_BEGIN_BIT_SET (uint8_t, single_bit)
  HG_BIT_FIELD   (single_bit, 0, lonely, 1)
HG_END_BIT_SET

typedef TypeList
<
  single_bit      
> single_bit_t;

HG_BEGIN_FORMAT(single_bit_t)
  HG_DATUM (single_bit, only)
HG_END_FORMAT(single_bit_t)

//  ****************************************************************************
//  A type list used to verify the sequence containers.
//
typedef TypeList
<
  uint32_t,      
  uint32_t,     
  uint32_t
> point_format_t;

HG_BEGIN_FORMAT(point_format_t)
  HG_DATUM (uint32_t, X)
  HG_DATUM (uint32_t, Y)
  HG_DATUM (uint32_t, Z)
HG_END_FORMAT(point_format_t)

//  ****************************************************************************
//  A type list definition that defines a single array as the only field.
// 
typedef TypeList
<
  std::array<point_format_t, 2>      
> single_array_t;

HG_BEGIN_FORMAT(single_array_t)
  HG_DATUM ((std::array<point_format_t, 2>), line)
HG_END_FORMAT(single_array_t)



} // namespace Hg


#endif
