/// @file detail/data_proxy.h
/// 
/// The declaration and definition of the DataProxy.
///           
/// A parameterized type that abstracts the details between all different types
/// of message fields.  This will allow a single message field MACRO to be 
/// used when defining fields for message format definitions.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DATA_PROXY_H_INCLUDED
#define DATA_PROXY_H_INCLUDED
//  Includes ******************************************************************

#include <Pb/meta_fwd.h>
#include <Pb/length.h>
#include <Pb/type_list.h>
#include <Pb/type_at.h>
#include <Hg/datum/datum.h>
#include <Hg/storage_policy.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A template to adapt all field types to the Datum assignment.
/// 
/// @paramt datum_trait     The general category of proxy management required by
///                         the specified field.
/// @paramt kt_idx
/// @paramt format_type
/// @paramt kt_offset
/// 
template< typename  datum_trait, 
          size_t    kt_idx,
          typename  format_t
        >
struct DataProxy
  : public Hg::Datum<kt_idx, format_t>
{
  typedef  
    Hg::Datum < kt_idx,
                format_t
              >                                   datum_type;

  typedef typename 
    datum_type::value_type                        value_type;

  typedef datum_type&                             reference;

  //  **************************************************************************
  /// Default Constructor
  ///
  DataProxy()
  { }

  //  **************************************************************************
  /// Copy Constructor
  ///
  /// Makes a complete copy of an existing Proxy object.
  ///
  /// @param proxy           A reference to the Another instance of a DataProxy.
  /// 
  DataProxy(const DataProxy& proxy)
  {
    this->set(proxy.get());
  }

  //  **************************************************************************
  /// Value Constructor: Construct a proxy directly from a datum instance.
  ///
  /// @param datum           A reference to a datum object used to initilize this.
  /// 
  DataProxy(const datum_type& datum)
    : datum_type(datum)
  { }

  //  **************************************************************************
  /// Value assignment
  ///
  DataProxy& operator=(const datum_type& value)
  {
    *static_cast<datum_type*>(this) = value;
    return *this;
  }

  //  **************************************************************************
  /// Value assignment
  ///
  DataProxy& operator=(value_type value)
  {
    *static_cast<datum_type*>(this) = value;
    return *this;
  }

  //  **************************************************************************
  /// Conversion operator to a base Datum Type reference.
  /// 
  /// @note         The converted Datum base provides access to value interface
  ///               of the Datum object.
  /// 
  operator reference()
  {
    return *static_cast<datum_type*>(this);
  }

  //  **************************************************************************
  /// Value Conversion Operator (value_type)
  /// 
  /// Allows the entire Object-type to be extracted and assigned as a value to
  /// the host value type.
  /// 
  operator value_type() const
  {
    return static_cast<const datum_type*>(this)->operator value_type();
  }
};

} // namespace detail

} // namespace Hg

#endif
