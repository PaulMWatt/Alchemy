/// @file bit_field_array.h
/// 
/// Defines the BitFieldArray construct for Alchemy Message Fields.
/// This is a specialized meta object the keeps track of a series of bit-field 
/// definitions for a message structure. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BIT_FIELD_ARRAY_H_INCLUDED
#define BIT_FIELD_ARRAY_H_INCLUDED
//  Includes ******************************************************************
#include <meta/bit_field/compiler.h>
#include <array>


namespace Hg
{

// ****************************************************************************
/// Represents a set of fields that provide homogeneous bit-field access to each
/// of the data values.
///           
/// This object requires a Hg bit-field definition for the type definition of
/// this object. The base integer type that is defined for the bit-field 
/// will be used to define the type for allocation of memory for the array.
/// 
/// Each field allocated in the array will accessible either by the base
/// integer type or with the bit-field interface provided supplied to the
/// definition.
///
template<typename T,
         template
        >
struct BitFieldArray
{
public:


private:


};


} // namespace Hg


#endif
