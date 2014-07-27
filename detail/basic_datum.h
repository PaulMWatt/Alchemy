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
#include <meta/meta_fwd.h>
#include <detail/msg_buffer.h>

namespace Hg
{

namespace detail
{
//  ****************************************************************************
/// Type definition that indicates the parameterized-type
/// located at an index in a type container.
///
/// @param field_t            [typename] This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
///
/// @note           This type should be specialized for custom fields that
///                 desire the field_t input to differ from the defined value_type.
/// 
template <typename field_t>
struct field_data_t
{
  typedef field_t        value_type;    ///< The matching data type for the index.
                                        ///  The default implementation uses 
                                        ///  the same type as the index type.
};

//  ****************************************************************************
/// Provides the index and data field type definitions.
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
/// @paramt field_t           This parameterized type declares the
///                           type at the associated location in the parent 
///                           type container.
/// @paramt kt_offset         [size_t] This is the offset of the current 
///                           data field found in its parent type container.
/// 
template< typename field_t,
          size_t   kt_offset = 0
        >
struct FieldTypes
{
  typedef 
    field_t             index_type;     ///< The type at the index of the
                                        ///  parent type container.
  typedef typename
    field_data_t<field_t>::value_type
                        value_type;     ///< The specified value type for 
                                        ///  the current Datum.

  value_type            m_shadow_data;  ///< This is a local copy of the data
                                        ///  value to shadow the value held in
                                        ///  the buffer. 
                                        ///  This provides an alternative location
                                        ///  to store the value if a buffer has
                                        ///  not been assigned to the Datum.
                                        ///  This occurs frequently for temporary
                                        ///  instances of this Datum.

};


//  ****************************************************************************
/// A meta-function that simplfies the declaration of a FieldType.
/// Publically derive from the type member of this struct.
///
/// @paramt  Idx              [size_t] The index of this element in the 
///                           TypeList definition.
///                           Idx must be < length<T>::value.
/// @paramt  T                The TypeList that contains this 
///                           elements definition.
///                           T must be an indexable type container.
///
template< size_t   Idx,
          typename format_t, 
          size_t   kt_offset
        >
struct DefineFieldType
{
  //  Typedefs *****************************************************************
  typedef typename 
    Hg::TypeAt<Idx, format_t>::type     index_type;
                                        ///< The type extracted at the current
                                        ///  index defined in the parent TypeList.

  typedef typename 
    detail::FieldTypes  < index_type,
                          OffsetOf<Idx, format_t>::value + kt_offset
                        >               type;
                                        ///< The field type definition that maps
                                        ///  a field type with it's value_type.
};

} // namespace detail

} // namespace Hg

#endif
