/// @file detail/optional_datum.h
/// 
/// The basic data field behaviors for optional parameters.
///           
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef OPTIONAL_DATUM_H_INCLUDED
#define OPTIONAL_DATUM_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/optional.h>
#include <Hg/datum/basic_datum.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// Optional Specialization provides the type definitions for field in type-container.
///
/// @tparam T           [typename] The type of the optional data field. 
///
template< typename T >
struct field_data_t < Hg::optional<T> >
{
  /// Extract the actual value-type and 
  /// use the FieldType defined for it.
  using value_type = T;
};


//  ****************************************************************************
/// Provides the default optional data field type definition.
/// 
/// This class acts as a discriminator object to choose the proper msg field types.
/// This method of field and data definition allows the use of virtual 
/// interfaces to be avoided for message fields. 
/// 
/// This class behaves as a proxy to the underlying FieldType object. 
/// This class peels off the optional shell before invoking the proper FieldType.
/// 
/// @tparam FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
template< typename FieldT,
          typename TraitT = deduce_type_trait_t<FieldT>>
struct OptionalFieldTypes
  : public base_optional
{
  /// The type at the index of the
  /// parent type container.
  using index_type = FieldT; 
 
  /// The specified value type for 
  /// the current Datum.
  using value_type = typename field_data_t<index_type>::value_type;

  //  **************************************************************************
  OptionalFieldTypes()
  { }

  //  **************************************************************************
  OptionalFieldTypes(const OptionalFieldTypes& rhs)
    : base_optional(rhs)
  {
    m_data = rhs.m_data;
  }

  //  **************************************************************************
  OptionalFieldTypes(OptionalFieldTypes&& rhs)
    : base_optional(std::move(rhs))
  {
    m_data = std::move(rhs.m_data);
  }

  //  **************************************************************************
  OptionalFieldTypes(const value_type& rhs)
  {
    valid();
    m_data = rhs;
  }

  //  **************************************************************************
  OptionalFieldTypes(value_type&& rhs)
  {
    valid();
    m_data = std::move(rhs);
  }

  //  **************************************************************************
  OptionalFieldTypes& operator=(const OptionalFieldTypes& rhs)
  {
    base_optional::operator=(rhs);
    m_data = rhs.m_data;
    return *this;
  }

  //  **************************************************************************
  OptionalFieldTypes& operator=(OptionalFieldTypes&& rhs)
  {
    base_optional::operator=(std::move(rhs));
    m_data = std::move(rhs.m_data);
    return *this;
  }

  //  **************************************************************************
  OptionalFieldTypes& operator=(const value_type& rhs)
  {
    valid();
    m_data = rhs;
    return *this;
  }
  
  //  **************************************************************************
  OptionalFieldTypes& operator=(value_type&& rhs)
  {
    valid();
    m_data = std::move(rhs);
    return *this;
  }


  //  **************************************************************************
  /// Returns a reference to the internal data storage.
  /// 
  /// Returns a reference to the internal data storage managed by this
  /// Datum. The reference to the data can be useful, and necessary for
  ///
  value_type& reference()                     
  { 
    valid();
    return m_data;
  }

  //  **************************************************************************
  /// Returns the value of the data buffer.
  /// 
  const value_type& data() const
  { 
    return m_data;
  }

  //  **************************************************************************
  /// Provides an interface to set the value of the data.
  /// 
  void data(const value_type &value)                
  { 
    valid();
    Hg::detail::copy_value_type(reference(), value);
  }

protected:
  /// This is a local copy of the data
  /// value to shadow the value held in
  /// the buffer. 
  value_type            m_data;         
};


//  ****************************************************************************
/// Nested Specialization for the optional field type definition.
/// 
/// @tparam FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
/// Note: The nested type provides storage for nested fields by deriving from 
///       the user-defined format. 
///
template< typename FieldT > 
struct OptionalFieldTypes <FieldT, nested_trait>
  : public base_optional
  , public field_data_t<FieldT>::value_type
{
  /// The type at the index of the
  /// parent type container.
  using index_type = FieldT;

  /// The specified value type for 
  /// the current Datum.
  using value_type = typename field_data_t<index_type>::value_type;

  //  **************************************************************************
  /// Returns a reference to the internal data storage.
  /// 
  /// Returns a reference to the internal data storage managed by this
  /// Datum. The reference to the data can be useful, and necessary for
  ///
  value_type& reference()                     
  {
    valid();
    return *static_cast<value_type*>(this);
  }

  //  **************************************************************************
  /// Returns the value of the data buffer.
  /// 
  const value_type& data() const
  { 
    return *static_cast<const value_type*>(this);
  }

  //  **************************************************************************
  /// Provides an interface to set the value of the data.
  /// 
  void data(const value_type &value)                
  { 
    valid();
    reference() = value;
  }
};


//  ****************************************************************************
/// Packed Bits Specialization for the index and data field type definitions.
/// 
/// @tparam FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
template< typename FieldT > 
struct OptionalFieldTypes <FieldT, packed_trait>
  : public base_optional
  , public FieldT
{
  /// The type at the index of the
  /// parent type container.
  using index_type = FieldT;

  /// The packed-bit container type.
  using packed_type= typename field_data_t<index_type>::value_type;

  /// The value type used by the packed-bits.
  using value_type = typename packed_type::value_type;


  //  **************************************************************************
  /// Returns a reference to the internal data storage.
  /// 
  /// Returns a reference to the internal data storage managed by this
  /// Datum. The reference to the data can be useful, and necessary for
  ///
  value_type& reference()                     
  { 
    valid();
    return this->value();
  }

  //  **************************************************************************
  /// Returns the value of the data buffer.
  /// 
  const value_type& data() const
  { 
    return this->value();
  }

  //  **************************************************************************
  /// Provides an interface to set the value of the data.
  /// 
  void data(const value_type &value)                
  { 
    valid();
    reference() = value;
  }
};


//  ****************************************************************************
/// Nested Specialization for the index and data field type definitions.
/// 
/// @tparam FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
/// Note: The nested type provides storage for nested fields by deriving from 
///       the user-defined format. 
///
template< typename FieldT > 
struct FieldTypes <FieldT, optional_trait>
  : public OptionalFieldTypes<typename field_data_t<FieldT>::value_type>
{
  /// The type at the index of the
  /// parent type container.
  using index_type = FieldT;

  /// The specified value type for 
  /// the current Datum.
  using value_type = typename field_data_t<index_type>::value_type;
};

} // namespace detail

} // namespace Hg

#endif
