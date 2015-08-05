/// @file Hg/proxy/optional_proxy.h
/// 
/// The OptionalProxy template.
///           
/// A parameterized proxy that adds the capabilities for any type to become 
/// an optionally present type in a serialized message.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef OPTIONAL_PROXY_H_INCLUDED
#define OPTIONAL_PROXY_H_INCLUDED
//  Includes ******************************************************************

#include <Pb/meta_fwd.h>
#include <Pb/type_list.h>
#include <Hg/datum/datum.h>
#include <Hg/storage_policy.h>
#include <Hg/proxy.h>

namespace Hg
{

namespace detail
{


//  ****************************************************************************
/// A template to provide optional support for field definitions.
/// 
/// @tparam datum_trait     The general category of proxy management required by
///                         the specified field.
/// @tparam kt_idx
/// @tparam format_type
/// @tparam kt_offset
/// 
template< size_t    IdxT,
          typename  FormatT
        >
struct DataProxy <optional_trait, IdxT, FormatT>
  : public  DataProxy
            < deduce_type_trait_t< typename type_at<IdxT, FormatT>::type::optional_type>, 
              IdxT, 
              FormatT
            >
{
  /// The type managed by the optional container.
  using index_type    = typename type_at<IdxT, FormatT>::type;
  using optional_type = typename index_type::optional_type;

  /// The proxy-type for the actual value type managed by the optional object.
  using proxy_type = 
          DataProxy
          < deduce_type_trait_t< optional_type>, 
            IdxT, 
            FormatT
          >;

  using datum_type = typename proxy_type::datum_type;
  using value_type = typename datum_type::value_type;
  using reference  = datum_type&;

  //  **************************************************************************
  /// Default Constructor
  ///
  DataProxy()
    : proxy_type()
  { }

  //  **************************************************************************
  /// Copy Constructor
  ///
  /// Makes a complete copy of an existing Proxy object.
  ///
  /// @param proxy           A reference to the Another instance of a DataProxy.
  /// 
  DataProxy(const DataProxy& proxy)
    : proxy_type()
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
  /// Value Constructor: Construct a proxy directly from a datum instance.
  ///
  /// @param datum           A reference to a datum object used to initilize this.
  /// 
  DataProxy(datum_type&& datum)
    : datum_type(std::move(datum))
  { }

  //  **************************************************************************
  /// Value Constructor: Construct a proxy directly from the optional value type.
  ///
  /// @param datum           A reference to a value type instance used to initilize this.
  /// 
  DataProxy(const value_type& value)
    : datum_type(value)
  { }

  //  **************************************************************************
  /// Value Constructor: Construct a proxy directly from the optional value type.
  ///
  /// @param datum           A reference to a value type instance used to initilize this.
  /// 
  DataProxy(value_type&& value)
    : datum_type(std::move(value))
  { }

  //  **************************************************************************
  /// Value Constructor: Construct a proxy directly from the optional value type.
  ///
  /// @param datum           A reference to a value type instance used to initilize this.
  /// 
  DataProxy(const optional_type& value)
  { 
    this->set(index_type(value));
  }

  //  **************************************************************************
  /// Value Constructor: Construct a proxy directly from the optional value type.
  ///
  /// @param datum           A reference to a value type instance used to initilize this.
  /// 
  DataProxy(optional_type&& value)
    : datum_type(index_type(std::move(value)))
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
  /// Copy assignment
  ///
  DataProxy& operator=(const proxy_type& rhs)
  {
    proxy_type::operator=(rhs);
    return *this;
  }

  //  **************************************************************************
  /// Move assignment
  ///
  DataProxy& operator=(proxy_type&& rhs)
  {
    proxy_type::operator=(std::move(rhs));
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

  //  **************************************************************************
  /// Exchanges the contents of this DataProxy container with those of other.
  /// This version does not invoke any move, copy, or swap operations on
  /// the individual elements.
  ///
  /// Iterators and references will remain valid, with the exception to the
  /// end iterators.
  ///
  /// @param other    The other vector to swap elements.
  ///
  void swap(DataProxy& other)                     { this->get().swap(other.get()); }

  //  **************************************************************************
  /// Exchanges the contents of the container with those of other.
  /// This version does not invoke any move, copy, or swap operations on
  /// the individual elements.
  ///
  /// Iterators and references will remain valid, with the exception to the
  /// end iterators.
  ///
  /// @param other    The other vector to swap elements.
  ///
  void swap(optional_type& other)                    { this->get().swap(other);   }


};

} // namespace detail

} // namespace Hg

#endif
