//  @file meta/BitField/basic_list.h
//  
//  Defines a collector for bit-fields.
//  
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef META_BIT_FIELD_BASIC_LIST_H_INCLUDED
#define META_BIT_FIELD_BASIC_LIST_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/bit_field/bit_field.h>
#include <Pb/integer_sequence.h>

namespace Hg
{

//  ****************************************************************************
//  A trait-type to define constants and common parameterized aliases.
//
template< size_t    IndexT,
          typename  HostT,
          size_t    CountT
        >
struct FieldIndex
{
  using host_type = HostT;
  using this_type = FieldIndex<IndexT,HostT,CountT>;

  enum { k_index = IndexT};
  enum { k_size  = CountT};
};

//  ****************************************************************************
//  A specialization for a bit-field representing the empty type.
//
template<>
struct FieldIndex<0,MT,0>
{
  using host_type = MT;
  using this_type = FieldIndex<0,MT,0>;

  enum { k_index = 0};
  enum { k_size  = 0};
};

//  ****************************************************************************
using idx_empty_t = FieldIndex<0,MT,0>;

//  ****************************************************************************
//  The base container definition for a list of bit-fields.
//  This object contains type definitions 
// 
template <typename T>
struct PackedBits
  : public packed_trait
  , public container_trait
     
{ 
  // Define each of these types for the base.
  // This will ensure the types exist if less than 
  // the maximum number of bit-fields are defined.
  using idx_0  = idx_empty_t;
  using idx_1  = idx_empty_t;
  using idx_2  = idx_empty_t;
  using idx_3  = idx_empty_t;
  using idx_4  = idx_empty_t;
  using idx_5  = idx_empty_t;
  using idx_6  = idx_empty_t;
  using idx_7  = idx_empty_t;

  using idx_8  = idx_empty_t;
  using idx_9  = idx_empty_t;
  using idx_10 = idx_empty_t;
  using idx_11 = idx_empty_t;
  using idx_12 = idx_empty_t;
  using idx_13 = idx_empty_t;
  using idx_14 = idx_empty_t;
  using idx_15 = idx_empty_t;

  using idx_16 = idx_empty_t;
  using idx_17 = idx_empty_t;
  using idx_18 = idx_empty_t;
  using idx_19 = idx_empty_t;
  using idx_20 = idx_empty_t;
  using idx_21 = idx_empty_t;
  using idx_22 = idx_empty_t;
  using idx_23 = idx_empty_t;

  using idx_24 = idx_empty_t;
  using idx_25 = idx_empty_t;
  using idx_26 = idx_empty_t;
  using idx_27 = idx_empty_t;
  using idx_28 = idx_empty_t;
  using idx_29 = idx_empty_t;
  using idx_30 = idx_empty_t;
  using idx_31 = idx_empty_t;

  using this_type   = PackedBits<T>;
  using value_type  = T;

  enum { k_offset_0 = 0 };

  //  **************************************************************************
  //  Default Constructor
  // 
  PackedBits()
    : m_data(0)
  { }

  //  **************************************************************************
  //  Value Constructor.
  // 
  PackedBits(value_type &data_field)
    : m_data(data_field)
  { }

  //  **************************************************************************
  //  Value conversion operator.
  // 
  operator value_type() const
  { 
    return m_data; 
  }

  //  **************************************************************************
  //  (Value) Assignment operator
  //
  PackedBits& operator=(const value_type &rhs)
  {
    m_data = rhs;
    return *this;
  }

  //  **************************************************************************
  //  Returns the value of the packed bits.
  // 
  const value_type& value() const
  { 
    return m_data; 
  }

  //  **************************************************************************
  //  Returns a reference to the storage buffer.
  // 
  value_type& value()
  { 
    return m_data; 
  }

  //  **************************************************************************
  //  Sets the value of the packed bits.
  // 
  void value(value_type value)
  { 
    m_data = value; 
  }

  //  Methods *******************************************************************
  //  ***************************************************************************
  /// Returns the size of the base integer type used in the bit list.
  ///
  static
  size_t size()
  {
    return sizeof(value_type);
  }

protected:
  //  Member Data **************************************************************

  value_type            m_data;                 // Stores the values for the proxy.
};



//  ****************************************************************************
template< size_t    Idx,
          typename  format_type
        >
struct DeduceBitFieldList
{
  using base_t = typename type_at < Idx, format_type>::type;
  using type   = base_t;
};


} // namespace Hg


#endif
