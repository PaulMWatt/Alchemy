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
#include <meta/bit_field/bit_field.h>
#include <meta/integer_sequence.h>

namespace Hg
{

//  ****************************************************************************
//  A trait-type to define constants and common parameterized typedefs.
//
template< size_t    IndexT,
          typename  HostT,
          size_t    CountT
        >
struct FieldIndex
{
  typedef HostT                                   host_type;
  typedef FieldIndex<IndexT,HostT,CountT>         this_type;

  enum { k_index = IndexT};
  enum { k_size  = CountT};
};

//  ****************************************************************************
//  A specialization for a bit-field representing the empty type.
//
template<>
struct FieldIndex<0,MT,0>
{
  typedef MT                                   host_type;
  typedef FieldIndex<0,MT,0>                   this_type;

  enum { k_index = 0};
  enum { k_size  = 0};
};

//  ****************************************************************************
typedef FieldIndex<0,MT,0>     idx_empty_t;

//  ****************************************************************************
//  The base container definition for a list of bit-fields.
//  This object contains type definitions 
// 
template <typename T,
          typename FieldsT>
struct BasicBitList
  : public container_trait
  , public bitfield_trait
{ 
  // Define each of these types for the base.
  // This will ensure the types exist if less than 
  // the maximum number of bit-fields are defined.
  typedef idx_empty_t   idx_0;
  typedef idx_empty_t   idx_1;
  typedef idx_empty_t   idx_2;
  typedef idx_empty_t   idx_3;
  typedef idx_empty_t   idx_4;
  typedef idx_empty_t   idx_5;
  typedef idx_empty_t   idx_6;
  typedef idx_empty_t   idx_7;

  typedef idx_empty_t   idx_8;
  typedef idx_empty_t   idx_9;
  typedef idx_empty_t   idx_10;
  typedef idx_empty_t   idx_11;
  typedef idx_empty_t   idx_12;
  typedef idx_empty_t   idx_13;
  typedef idx_empty_t   idx_14;
  typedef idx_empty_t   idx_15;

  typedef idx_empty_t   idx_16;
  typedef idx_empty_t   idx_17;
  typedef idx_empty_t   idx_18;
  typedef idx_empty_t   idx_19;
  typedef idx_empty_t   idx_20;
  typedef idx_empty_t   idx_21;
  typedef idx_empty_t   idx_22;
  typedef idx_empty_t   idx_23;

  typedef idx_empty_t   idx_24;
  typedef idx_empty_t   idx_25;
  typedef idx_empty_t   idx_26;
  typedef idx_empty_t   idx_27;
  typedef idx_empty_t   idx_28;
  typedef idx_empty_t   idx_29;
  typedef idx_empty_t   idx_30;
  typedef idx_empty_t   idx_31;

  typedef BasicBitList<T, FieldsT>      this_type;
  typedef T                             value_type;
  typedef FieldsT                       field_type;
  typedef BitField<0, 0, value_type>    nil_bits_t;

  enum { k_offset_0 = 0 };

  //  **************************************************************************
  //  Returns the value of the entire storage buffer.
  // 
  const value_type& value() const
  { 
    return *m_pData; 
  }

  //  **************************************************************************
  //  Returns the value of the entire storage buffer.
  // 
  value_type& value()
  { 
    return *m_pData; 
  }

  //  **************************************************************************
  //  Sets the value of the entire storage buffer.
  // 
  void value(value_type value)
  { 
    *m_pData = value; 
  }

  //  **************************************************************************
  //  Attaches an externally referenced data buffer for storage.
  //
  void set_buffer(value_type &buffer)
  { 
    m_pData = &buffer; 
  }

protected:
  //  Member Data **************************************************************

  value_type            *m_pData;       // Points to the local buffer that 
                                        // stores the values for the proxy.
                                        // This type must be a pointer as opposed
                                        // to a reference because of containers
                                        // such as the array that allocate in bulk,
                                        // they can only use the default constructor.

                                        //   TODO: Would like to explore options 
                                        //   for removing this data fields
                                        //   without adding buffer validity tests.

  value_type            temp_data;      // The MT data value field 
                                        // provides a location to reference
                                        // for the default constructor.

  //  **************************************************************************
  //  Default Constructor
  //  Prevent direct creation of this class; must use a derived class.
  // 
  BasicBitList()
    : m_pData(&temp_data)
    , temp_data(0)
  { }

  //  **************************************************************************
  //  Value constructor that associates the address of the storage with this list.
  //  Prevent direct creation of this class; must use a derived class.
  // 
  BasicBitList(value_type &data_field)
    : temp_data(0)

  { 
    m_pData = &data_field;
  }


  //  **************************************************************************
  //  Endian swap provides a specialization to handle the unique structure 
  //  created to provide bit-field support.
  //  The function is declared and implemented as a friend function to simplify
  //  the declaration and namespace lookup for proper endian order conversions.
  // 
  friend inline
    field_type EndianSwap(field_type &input)
  { 
    return field_type(EndianSwap<value_type>(value()));
  }

};



} // namespace Hg


#endif
