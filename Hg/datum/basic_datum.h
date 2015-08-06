/// @file detail/basic_datum.h
/// 
/// The declaration and definition of general functions for a data field.
///           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BASIC_DATUM_H_INCLUDED
#define BASIC_DATUM_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/meta_fwd.h>
#include <Pb/optional.h>
#include <Hg/msg_buffer.h>
#include <Hg/deduce_type_trait.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// Type definition that indicates the parameterized-type
/// located at an index in a type container.
///
/// @tparam field_t           [typename] This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
///
/// @note           This type should be specialized for custom fields that
///                 desire the field_t input to differ from the defined value_type.
/// 
template <typename FieldT>
struct field_data_t
{
  /// The matching data type for the index.
  /// The default implementation uses 
  /// the same type as the index type.
  using value_type = FieldT;            
};

//  ****************************************************************************
/// Generalized copy function for message field value types.
///
/// @param to       A reference to the variable to copy the into.
/// @param from     A reference to the data to copy from.
///
template< typename T >
void copy_value_type(T& to, const T& from)
{
  to = from;
}

//  ****************************************************************************
/// (Fixed-Array Specialization) To copy from one instance to another.
///
/// @tparam SubTypeT          [typename] This parameterized type declares the
///                           sub-type of the array defined at the location 
///                           in the parent type container.
/// @tparam N                 [size_t] The number of elements in the array.
///
template< typename SubTypeT,
          size_t   N
        >
void copy_value_type(       std::array<SubTypeT, N>& to, 
                      const std::array<SubTypeT, N>& from)
{
  std::copy(from.begin(), from.end(), to.begin());
}


//  ****************************************************************************
/// (Dynamic-Array Specialization) Type definitions for field in type-container.
///
/// @param SubTypeT           [typename] This parameterized type declares the
///                           sub-type of the vector defined at the location 
///                           in the parent type container.
/// @param AllocT             [typename] The defined allocator of the vector.
///
template< typename SubTypeT,
          typename AllocT
        >
struct field_data_t < std::vector<SubTypeT, AllocT> >
{
  using sub_type        = SubTypeT;
  using value_sub_type  = typename field_data_t<sub_type>::value_type;

  /// The proper value_type definition
  /// deduced from the type-container
  /// and the specified array sub-type.
  using value_type      = typename
                            std::conditional
                              < nested_value<sub_type>::value,
                                std::vector< value_sub_type, AllocT>,
                                std::vector< sub_type, AllocT>
                              >::type;
};

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
/// (Dynamic-Array Specialization) To copy from one instance to another.
///
/// @param SubTypeT           [typename] This parameterized type declares the
///                           sub-type of the vector defined at the location 
///                           in the parent type container.
/// @param AllocT             [typename] The defined allocator of the vector.
///
template< typename SubTypeT,
          typename AllocT
        >
void copy_value_type(       std::vector<SubTypeT, AllocT>& to, 
                      const std::vector<SubTypeT, AllocT>& from)
{
  // Empty the existing elements before inserting the new data.
  to.clear();
  std::copy(from.begin(), from.end(), std::back_inserter(to));
}


//  ****************************************************************************
/// Provides the data field type definitions.
/// 
/// This class acts as a discriminator object to choose the proper msg field types.
/// This method of field and data definition allows the use of virtual 
/// interfaces to be avoided for message fields. 
/// 
/// In cases such as a uint8_t, this would cause a 400% increase in size for 
/// no value. This extra hidden complexity of implementation is well worth
/// the runtime value of the final structure.
/// 
/// @note           The template defaults use *field_t* for both *index_type*
///                 and *value_type*. These definitions determine the data
///                 managed within a Datum. This template should be 
///                 specialized if a different *value_type* is desired.
///
/// @note           The simplest method to specialize the value_type is
///                 to create a specialization of the *field_data_t* template.
/// 
/// @tparam FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
template< typename FieldT,
          typename TraitT = typename Hg::detail::deduce_type_trait<FieldT>::type >
struct FieldTypes
{
  /// The type at the index of the
  /// parent type container.
  using index_type = FieldT; 
 
  /// The specified value type for 
  /// the current Datum.
  using value_type = typename field_data_t<index_type>::value_type;

  //  **************************************************************************
  FieldTypes()
  { }

  //  **************************************************************************
  FieldTypes(const FieldTypes& rhs)
  {
    m_data = rhs.m_data;
  }

  //  **************************************************************************
  FieldTypes(FieldTypes&& rhs)
  {
    m_data = std::move(rhs.m_data);
  }

  //  **************************************************************************
  FieldTypes(const value_type& rhs)
  {
    m_data = rhs;
  }

  //  **************************************************************************
  FieldTypes(value_type&& rhs)
  {
    m_data = std::move(rhs);
  }

  //  **************************************************************************
  FieldTypes& operator=(const FieldTypes& rhs)
  {
    m_data = rhs.m_data;
    return *this;
  }

  //  **************************************************************************
  FieldTypes& operator=(FieldTypes&& rhs)
  {
    m_data = std::move(rhs.m_data);
    return *this;
  }

  //  **************************************************************************
  FieldTypes& operator=(const value_type& rhs)
  {
    m_data = rhs;
    return *this;
  }
  
  //  **************************************************************************
  FieldTypes& operator=(value_type&& rhs)
  {
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
    Hg::detail::copy_value_type(reference(), value);
  }

protected:
  /// This is a local copy of the data
  /// value to shadow the value held in
  /// the buffer. 
  value_type            m_data;         
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
struct FieldTypes <FieldT, nested_trait>
  : public field_data_t<FieldT>::value_type
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
struct FieldTypes <FieldT, packed_trait>
  : public FieldT
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
  FieldTypes()
  { }

  //  **************************************************************************
  FieldTypes(const FieldTypes& rhs)
    : base_optional(rhs)
  {
    m_data = rhs.m_data;
  }

  //  **************************************************************************
  FieldTypes(FieldTypes&& rhs)
    : base_optional(std::move(rhs))
  {
    m_data = std::move(rhs.m_data);
  }

  //  **************************************************************************
  FieldTypes(const value_type& rhs)
  {
    valid();
    m_data = rhs;
  }

  //  **************************************************************************
  FieldTypes(value_type&& rhs)
  {
    valid();
    m_data = std::move(rhs);
  }

  //  **************************************************************************
  FieldTypes& operator=(const FieldTypes& rhs)
  {
    m_data = rhs.m_data;
    return *this;
  }

  //  **************************************************************************
  FieldTypes& operator=(FieldTypes&& rhs)
  {
    base_optional::operator=(std::move(rhs))
    m_data = std::move(rhs.m_data);
    return *this;
  }

  //  **************************************************************************
  FieldTypes& operator=(const value_type& rhs)
  {
    valid();
    m_data = rhs;
    return *this;
  }
  
  //  **************************************************************************
  FieldTypes& operator=(value_type&& rhs)
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
    Hg::detail::copy_value_type(reference(), value);
  }

protected:
  /// This is a local copy of the data
  /// value to shadow the value held in
  /// the buffer. 
  value_type            m_data;         
};


//  ****************************************************************************
/// A meta-function that simplfies the declaration of a FieldType.
/// Publically derive from the type member of this struct.
///
/// Specialize this template class to customize the internal type that 
/// an index_type will resolve to.
///
/// @tparam  Idx              [size_t] The index of this element in the 
///                           type_list definition.
///                           Idx must be < length<T>::value.
/// @tparam  T                The type_list that contains this 
///                           elements definition.
///                           T must be an indexable type container.
///
template< size_t   Idx,
          typename format_t
        >
struct DefineFieldType
{
  //  Aliases ******************************************************************
  /// The type extracted at the current
  /// index defined in the parent type_list.
  using index_type = typename Hg::type_at<Idx, format_t>::type;

  /// The field type definition that maps
  /// a field type with it's value_type.
  using type       = detail::FieldTypes< index_type >;
};


} // namespace detail

} // namespace Hg

#endif
