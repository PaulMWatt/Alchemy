/// @file Hg/proxy/data_proxy.h
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
#include <Pb/type_list.h>
#include <Hg/datum/datum.h>
#include <Hg/storage_policy.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A template to adapt all field types to the Datum assignment.
/// 
/// @tparam datum_trait     The general category of proxy management required by
///                         the specified field.
/// @tparam kt_idx
/// @tparam format_type
/// @tparam kt_offset
/// 
template< typename  datum_trait, 
          size_t    kt_idx,
          typename  format_t
        >
struct DataProxy
  : public Hg::Datum<kt_idx, format_t>
{
  using trait_type = datum_trait;
  using datum_type = Hg::Datum <kt_idx, format_t>;
  using value_type = typename datum_type::value_type;

  using reference  = datum_type&;

  //  **************************************************************************
  /// Default Constructor
  ///
  DataProxy()
    : datum_type()
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
  /// Move Constructor
  ///
  /// @param proxy           A reference to the Another instance of a DataProxy.
  /// 
  DataProxy(DataProxy&& proxy)
    : datum_type(std::move(proxy))
  { }

  //  **************************************************************************
  /// Value Constructor: Construct a proxy directly from a datum instance.
  ///
  /// @param datum           A reference to a datum object used to initilize this.
  /// 
  DataProxy(const datum_type& datum)
    : datum_type(datum)
  { }

  //  **************************************************************************
  /// Copy assignment
  ///
  DataProxy& operator=(const DataProxy& rhs)
  {
    datum_type::operator=(rhs);
    return *this;
  }

  //  **************************************************************************
  /// Move assignment
  ///
  DataProxy& operator=(DataProxy&& rhs)
  {
    datum_type::operator=(std::move(rhs));
    return *this;
  }

  //  **************************************************************************
  /// Copy assignment (value)
  ///
  DataProxy& operator=(const datum_type& value)
  {
    datum_type::operator=(rhs);
    return *this;
  }

  //  **************************************************************************
  /// Move assignment (value)
  ///
  DataProxy& operator=(datum_type&& rhs)
  {
    datum_type::operator=(std::move(rhs));
    return *this;
  }

  //  **************************************************************************
  /// Copy assignment value
  ///
  DataProxy& operator=(const value_type& rhs)
  {
    datum_type::operator=(rhs);
    return *this;
  }

  //  **************************************************************************
  /// Move assignment value
  ///
  DataProxy& operator=(value_type&& rhs)
  {
    datum_type::operator=(std::move(rhs));
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
