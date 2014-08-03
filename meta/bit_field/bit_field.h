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
#include <meta/compiler.h>

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
template <size_t OffsetT, 
          size_t CountT, 
          typename T = uint8_t>
struct BitField
{
  static_assert(CountT <= (sizeof(T)* 8),
                "The number of bits in the BitField cannot exceed the size of the host type T.");
    
  //  Typedefs ******************************************************************
  typedef BitField<OffsetT, CountT, T>&   reference;
  typedef T                               value_type;

  //  Constants *****************************************************************
  enum { k_offset = OffsetT };
  enum { k_size   = CountT  };

  /// The BitField Mask can be described with this formula:
  ///
  /// Mask = (2 ^ (number of bits))-1 << shifted to the left by offset bits.
  ///
  enum { k_mask   = T(((tmp::math::pow<size_t, 2, k_size>::value)-1) << k_offset) };

  //  Construction **************************************************************
  //  ****************************************************************************
  BitField()
    : m_pValue(0)
  {  }

  //  ****************************************************************************
  explicit
  BitField(T& value)
    : m_pValue(&value)
  {  }
  
  //  ****************************************************************************
  void attach(T* pStorage)
  {
    m_pValue = pStorage;
  }

  //  Operators *****************************************************************
  operator value_type()
  {
    return  m_pValue
          ? mask_value()
          : 0;
  }

  //  ****************************************************************************
  value_type operator=(const value_type& rhs)
  {
    if (!m_pValue)
      return 0;

    *m_pValue &= ~k_mask;
    *m_pValue |= k_mask & (rhs << k_offset);

    return mask_value();
  }

  //  ****************************************************************************
  BitField& operator=(const BitField& rhs)
  {
    if ( m_pValue
      && rhs.m_pValue)
    {
      T value = (*rhs.m_pValue) & k_mask;
      *m_pValue &= ~k_mask;
      *m_pValue |= value & k_mask;
    }

    return *this;
  }

private:
  //  Member Data ***************************************************************
  value_type* m_pValue;

  //  Member Functions **********************************************************
  //  ***************************************************************************
  value_type mask_value()
  {
    return (*m_pValue & k_mask) >> k_offset;
  }
};


// ****************************************************************************
/// A specialization to allow MT bit_fields to convert to the nil type.
///           
template <size_t OffsetT,
          typename T>
struct BitField <OffsetT, 0, T>
{
  typedef BitField<0, 0, T>            nil_bits_t;

  operator nil_bits_t()
  {
    return nil_bits_t();
  }
};


} // namespace Hg


#endif
