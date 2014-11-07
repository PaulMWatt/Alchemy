/// @file BitField.h
/// 
/// Defines the BitField construct for Alchemy Message Fields.
/// This meta object keeps track of bit-field definitions for a message 
/// structure. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BIT_FIELD_H_INCLUDED
#define BIT_FIELD_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/compiler.h>

namespace Hg
{

// ****************************************************************************
/// Represents a single entry for a bit field type definition.
///           
/// In order for BitFields to be packed into a single byte, the BitFields 
/// must be grouped in a BitSet definition.
/// 
/// @note           The total number of requested bits must fit within the
///                 specified data-field type. The default is a 8-bit byte.
/// 
template <class  OwnerT,
          class  TagT,
          size_t OffsetT, 
          size_t CountT, 
          class  T = uint8_t>
struct BitField
{
  // TODO: Add this static assert back once a suitable tr1 replacement is created.
  //static_assert(CountT <= (sizeof(T)* 8),
  //              "The number of bits in the BitField cannot exceed the size of the host type T.");
    
  //  Typedefs ******************************************************************
  typedef BitField<OwnerT, TagT, OffsetT, CountT, T>&   reference;
  typedef T                                             value_type;

  //  Constants *****************************************************************
  enum { k_offset = OffsetT };
  enum { k_size   = CountT  };

  /// The BitField Mask can be described with this formula:
  ///
  /// Mask = (2 ^ (number of bits))-1 << shifted to the left by offset bits.
  ///
  enum { k_mask   = T(((tmp::math::pow<size_t, 2, k_size>::value)-1) << k_offset) };

  //  ****************************************************************************
  BitField()
  { }

  //  Operators *****************************************************************
  operator value_type()
  {
    return  mask_value();
  }

  //  ****************************************************************************
  value_type operator=(const value_type& rhs)
  {
    value_type& base_value = value();
    base_value &= ~k_mask;
    base_value |= k_mask & (rhs << k_offset);

    return mask_value();
  }

  //  ****************************************************************************
  BitField& operator=(const BitField& rhs)
  {
    value_type value = rhs.value() & k_mask;
    value_type& base_value = value() & ~k_mask;
    base_value |= value & k_mask;

    return *this;
  }

private:
  //  Member Functions **********************************************************
  //  ***************************************************************************
  value_type& value()
  {
    return owner()->value();
  }

  value_type mask_value()
  {
    return (value() & k_mask) >> k_offset;
  }

  OwnerT* owner()
  {
    return reinterpret_cast<OwnerT*>( reinterpret_cast<char*>(this)
                                    - TagT::offset());
  }
};


// ****************************************************************************
/// A specialization to allow MT bit_fields to convert to the nil type.
///           
template <size_t OffsetT,
          typename T>
struct BitField <Hg::MT, Hg::MT, OffsetT, 0, T>
{
  typedef BitField<Hg::MT, Hg::MT, 0, 0, T>            nil_bits_t;
  BitField(){}
  operator nil_bits_t()
  {
    return nil_bits_t();
  }
};


} // namespace Hg


#endif
