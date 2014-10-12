/// @file meta/bit_field_list.h
/// 
/// Defines a collector for bit-fields.
/// 
/// @author         Paul Watt
/// @date           4/6/2013
/// @copyright 2013 Paul Watt
//  ****************************************************************************
#ifndef BIT_FIELD_LIST_H_INCLUDED
#define BIT_FIELD_LIST_H_INCLUDED
//  Includes *******************************************************************
#include <meta/bit_field.h>


namespace alchemy
{

//  ****************************************************************************
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
template<>
struct FieldIndex<0,empty,0>
{
  typedef empty                                   host_type;
  typedef FieldIndex<0,empty,0>                   this_type;

  enum { k_index = 0};
  enum { k_size  = 0};
};

//  ****************************************************************************
typedef FieldIndex<0,empty,0>     idx_empty_t;

//  ****************************************************************************
struct BaseBitFields 
  : public container_trait
  , public bitset_trait
{ 
  // Define each of these types for the base.
  // This will insure the types exist if less than 
  // eight bit-fields are defined.
  typedef idx_empty_t   idx_0;
  typedef idx_empty_t   idx_1;
  typedef idx_empty_t   idx_2;
  typedef idx_empty_t   idx_3;
  typedef idx_empty_t   idx_4;
  typedef idx_empty_t   idx_5;
  typedef idx_empty_t   idx_6;
  typedef idx_empty_t   idx_7;

protected:
  BaseBitFields() {}
};

// TODO: Add a compile_check to verify each Bit_field uses the correct size value_type.

//  ****************************************************************************
/// The BitFields manages a set of bit fields, and provides parameterized access to 
/// these fields in a controlled manner.
///
template  < typename BaseT,
            size_t B0,   size_t B1=0, size_t B2=0, size_t B3=0,
            size_t B4=0, size_t B5=0, size_t B6=0, size_t B7=0
          >
struct BitFields
  // Are you receiving a compiler Error: 
  //    'alchemy::type_check<false>' : base class undefined?
  // The sum of the provided bits must be <= sizeof(T) in bits
  : type_check<(B0+B1+B2+B3+B4+B5+B6+B7)<=(sizeof(typename BaseT::value_type)*8)>
  , public BaseT
{
  //  Typedef *******************************************************************
  typedef typename BaseT::value_type                      value_type;

  //  Construction ***************************************************************
  BitFields(value_type &data_field)
    : m_data(data_field)
    , m_field_0(GetFieldAddress<0>(m_field_0))
    , m_field_1(GetFieldAddress<1>(m_field_1))
    , m_field_2(GetFieldAddress<2>(m_field_2))
    , m_field_3(GetFieldAddress<3>(m_field_3))
    , m_field_4(GetFieldAddress<4>(m_field_4))
    , m_field_5(GetFieldAddress<5>(m_field_5))
    , m_field_6(GetFieldAddress<6>(m_field_6))
    , m_field_7(GetFieldAddress<7>(m_field_7))
  {
    // The assignment in the constructor assigns the reference of
    // data_field to the data member, m_data.
    // 

    m_field_0.attach(m_data);
    m_field_1.attach(m_data);
    m_field_2.attach(m_data);
    m_field_3.attach(m_data);
    m_field_4.attach(m_data);
    m_field_5.attach(m_data);
    m_field_6.attach(m_data);
    m_field_7.attach(m_data);
  }

  operator value_type() const
  {
    return m_data;
  }

  BitFields& operator=(const BitFields &rhs)
  {
    m_data = rhs.m_data;
    return *this;
  }

  value_type operator=(value_type rhs)
  {
    m_data = rhs;
    return m_data;
  }

  //  Methods *******************************************************************
  const byte_t* buffer() const
  {
    return reinterpret_cast<const byte_t*>(&m_data);
  }

  static
  size_t size()
  {
    return sizeof(value_type);
  }

private:
  //  Constants ******************************************************************
  static const size_t k_size_0   = B0;
  static const size_t k_offset_0 = 0;

  static const size_t k_size_1   = B1;
  static const size_t k_offset_1 = value_if<(B1>0), size_t, k_size_0, 0>::value; 

  static const size_t k_size_2   = B2;
  static const size_t k_offset_2 = value_if<(B2>0), size_t, 
                                            k_offset_1 + k_size_1, 
                                            0>::value; 
  static const size_t k_size_3   = B3;
  static const size_t k_offset_3 = value_if<(B3>0), size_t, 
                                            k_offset_2 + k_size_2,
                                            0>::value; 
  static const size_t k_size_4   = B4;
  static const size_t k_offset_4 = value_if<(B4>0), size_t, 
                                            k_offset_3 + k_size_3, 
                                            0>::value;
  static const size_t k_size_5   = B5;
  static const size_t k_offset_5 = value_if<(B5>0), size_t, 
                                            k_offset_4 + k_size_4, 
                                            0>::value;
  static const size_t k_size_6   = B6;
  static const size_t k_offset_6 = value_if<(B6>0), size_t, 
                                            k_offset_5 + k_size_5, 
                                            0>::value;
  static const size_t k_size_7   = B7;
  static const size_t k_offset_7 = value_if<(B7>0), size_t, 
                                            k_offset_6 + k_size_6, 
                                            0>::value;

  //  Data Members ***************************************************************
  value_type                                     &m_data;

  Bit_field< k_offset_0, B0, value_type>          &m_field_0;
  Bit_field< k_offset_1, B1, value_type>          &m_field_1;
  Bit_field< k_offset_2, B2, value_type>          &m_field_2;
  Bit_field< k_offset_3, B3, value_type>          &m_field_3;
  Bit_field< k_offset_4, B4, value_type>          &m_field_4;
  Bit_field< k_offset_5, B5, value_type>          &m_field_5;
  Bit_field< k_offset_6, B6, value_type>          &m_field_6;
  Bit_field< k_offset_7, B7, value_type>          &m_field_7;

  //  Private Methods ************************************************************
  //  ****************************************************************************
  template <size_t    Idx,
            typename  field_t>
  field_t& GetFieldAddress(const field_t&)
  {
    // Create this typedef, to simplify the overly complex statement below.
    typedef FieldIndex< Idx, BaseT, field_t::k_size> field_index_t;

    // This syntax is calling a template member function "GetField" found 
    // in the base class "BaseT".
    // 
    // The template keyword lets the compiler know this is a template,
    // rather than a < sign:
    //    "this->GetField <" 
    // 
    // The static_cast from this to a type "BaseT" is required in order to 
    // give a hint to the compiler where to look for the "GetField" function.
    //
    return 
      static_cast<BaseT*>(this)->template 
                                 GetField<field_index_t>(field_t());
  }
};

//  ****************************************************************************
/// A utility function that will deduce a BitFields object type.
///             
template< typename base_t>
struct Declare_BitFields
{
  typedef alchemy::BitFields
                    < base_t,
                      base_t::idx_0::k_size,
                      base_t::idx_1::k_size,
                      base_t::idx_2::k_size,
                      base_t::idx_3::k_size,
                      base_t::idx_4::k_size,
                      base_t::idx_5::k_size,
                      base_t::idx_6::k_size,
                      base_t::idx_7::k_size
                    >                             type;
};

//  ****************************************************************************
/// A utility function that will deduce a BitFields object type from a 
/// TypeArray and a specified index.
///             
template< size_t    Idx,
          typename  format_type>
struct Format_BitFields
{
  typedef 
  typename alchemy::TypeAt< Idx,
                            format_type
                          >::type                   base_t;

  typedef alchemy::BitFields 
                          < base_t,
                            base_t::idx_0::k_size,
                            base_t::idx_1::k_size,
                            base_t::idx_2::k_size,
                            base_t::idx_3::k_size,
                            base_t::idx_4::k_size,
                            base_t::idx_5::k_size,
                            base_t::idx_6::k_size,
                            base_t::idx_7::k_size
                          >                         type;
};

} // namespace alchemy


#endif
