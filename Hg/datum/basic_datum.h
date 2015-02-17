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
#include <Hg/msg_buffer.h>
#include <Hg/deduce_type_trait.h>
#include <Pb/bit_field/bit_field_array.h>
#include <Pb/bit_field/bit_field_vector.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// Type definition that indicates the parameterized-type
/// located at an index in a type container.
///
/// @paramT field_t           [typename] This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
///
/// @note           This type should be specialized for custom fields that
///                 desire the field_t input to differ from the defined value_type.
/// 
template <typename FieldT>
struct field_data_t
{
  typedef FieldT         value_type;    ///< The matching data type for the index.
                                        ///  The default implementation uses 
                                        ///  the same type as the index type.
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
/// (Static-Array Specialization) Type definitions for bit-fields in type-container.
///
/// @param SubTypeT           [typename] This parameterized type declares the
///                           sub-type of the array defined at the location 
///                           in the parent type container.
/// @param N                  [size_t] The number of elements in the array.
///
template< typename SubTypeT,
          size_t   N
        >
struct field_data_t < Hg::BitFieldArray<SubTypeT, N> >
{
  typedef 
    SubTypeT                            sub_type;

  typedef 
    Hg::BitFieldArray<SubTypeT, N>      value_type;
};


//  ****************************************************************************
/// (Fixed-Array Specialization) To copy from one instance to another.
///
/// @paramt SubTypeT          [typename] This parameterized type declares the
///                           sub-type of the array defined at the location 
///                           in the parent type container.
/// @paramt N                 [size_t] The number of elements in the array.
///
template< typename SubTypeT,
          size_t   N
        >
void copy_value_type(       BitFieldArray<SubTypeT, N>& to, 
                      const BitFieldArray<SubTypeT, N>& from)
{
  std::copy(from.begin(), from.end(), to.begin());
}

//  ****************************************************************************
/// (Dynamic-Array Specialization) Type definitions for bit-field in type-container.
///
/// @param SubTypeT           [typename] This parameterized type declares the
///                           sub-type of the vector defined at the location 
///                           in the parent type container.
/// @param AllocT             [typename] The defined allocator of the vector.
///
template< typename SubTypeT,
          typename AllocT
        >
struct field_data_t < Hg::BitFieldVector<SubTypeT, AllocT> >
{
  typedef 
    SubTypeT                                      sub_type;

  typedef 
    Hg::BitFieldVector<SubTypeT, AllocT>          value_type;
};


//  ****************************************************************************
/// (Dynamic-Array Specialization) To copy from one instance to another.
///
/// @param SubTypeT           [typename] This parameterized type declares the
///                           sub-type of the vector defined at the location 
///                           in the parent type container.
/// @param AllocT             [typename] The defined allocator of the vector.
///
template< class SubTypeT,
          class A
        >
void copy_value_type(       BitFieldVector<SubTypeT, A>& to, 
                      const BitFieldVector<SubTypeT, A>& from)
{
  to.clear();
  if (from.empty())
  {
    return;
  }

  to.resize(from.size());
  std::copy( from.begin(), 
             from.end(), 
             to.begin());    
}


//  ****************************************************************************
/// (Fixed-Array Specialization) To copy from one instance to another.
///
/// @paramt SubTypeT          [typename] This parameterized type declares the
///                           sub-type of the array defined at the location 
///                           in the parent type container.
/// @paramt N                 [size_t] The number of elements in the array.
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
  typedef 
    SubTypeT                            sub_type;

  typedef typename 
    field_data_t<sub_type>::value_type  value_sub_type;


  typedef typename
    std::conditional
      < nested_value<sub_type>::value,
        std::vector< value_sub_type, AllocT>,
        std::vector< sub_type, AllocT>
      >::type                           value_type;
                                        ///< The proper value_type definition
                                        ///  deduced from the type-container
                                        ///  and the specified array sub-type.
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
/// @paramt FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
template< class FieldT,
          class TraitT = typename Hg::detail::DeduceTypeTrait<FieldT>::type >
struct FieldTypes
{
  typedef 
    FieldT              index_type;     ///< The type at the index of the
                                        ///  parent type container.
  typedef typename
    field_data_t<index_type>::value_type
                        value_type;     ///< The specified value type for 
                                        ///  the current Datum.

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
  /// Returns the value of the data buffer.
  /// 
  void data(const value_type &value)                
  { 
    Hg::detail::copy_value_type(reference(), value);
  }

protected:
  value_type            m_data;         ///< This is a local copy of the data
                                        ///  value to shadow the value held in
                                        ///  the buffer. 
};

//  ****************************************************************************
/// Nested Specialization for the index and data field type definitions.
/// 
/// @paramt FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
template< typename FieldT > 
struct FieldTypes <FieldT, nested_trait>
  : public field_data_t<FieldT>::value_type
{
  typedef 
    FieldT              index_type;     ///< The type at the index of the
                                        ///  parent type container.
  typedef typename
    field_data_t<index_type>::value_type
                        value_type;     ///< The specified value type for 
                                        ///  the current Datum.

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
  /// Returns the value of the data buffer.
  /// 
  void data( value_type &value)                
  { 
    reference() = value;
  }
};

//  ****************************************************************************
/// Packed Bits Specialization for the index and data field type definitions.
/// 
/// @paramt FieldT            This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// 
template< typename FieldT > 
struct FieldTypes <FieldT, packed_trait>
  : public FieldT
{
  typedef 
    FieldT              index_type;     ///< The type at the index of the
                                        ///  parent type container.
  typedef typename
    field_data_t<index_type>::value_type
                        packed_type;    ///< The packed-bit container type.
  typedef typename
    packed_type::value_type
                        value_type;     ///< The value type used by the packed-bits.

  //  **************************************************************************
  /// Returns a reference to the internal data storage.
  /// 
  /// Returns a reference to the internal data storage managed by this
  /// Datum. The reference to the data can be useful, and necessary for
  ///
  value_type& reference()                     
  { 
    return value();
  }

  //  **************************************************************************
  /// Returns the value of the data buffer.
  /// 
  const value_type& data() const
  { 
    return this->value();
  }

  //  **************************************************************************
  /// Assigns a new value to the data buffer.
  /// 
  void data(const value_type &value)                
  { 
    reference() = value;
  }

};



//  ****************************************************************************
/// A meta-function that simplfies the declaration of a FieldType.
/// Publically derive from the type member of this struct.
///
/// Specialize this template class to customize the internal type that 
/// an index_type will resolve to.
///
/// @paramt  Idx              [size_t] The index of this element in the 
///                           TypeList definition.
///                           Idx must be < length<T>::value.
/// @paramt  T                The TypeList that contains this 
///                           elements definition.
///                           T must be an indexable type container.
///
template< size_t   Idx,
          typename format_t
        >
struct DefineFieldType
{
  //  Typedefs *****************************************************************
  typedef typename 
    Hg::TypeAt<Idx, format_t>::type     index_type;
                                        ///< The type extracted at the current
                                        ///  index defined in the parent TypeList.

  typedef  
    detail::FieldTypes  
      < index_type >                    type;
                                        ///< The field type definition that maps
                                        ///  a field type with it's value_type.
};


} // namespace detail

} // namespace Hg

#endif
