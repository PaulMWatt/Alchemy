/// @file detail/bitlist_field_proxy.h
/// 
/// An adapter object for BitLists to work within MsgFields.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BITLIST_FIELD_PROXY_H_INCLUDED
#define BITLIST_FIELD_PROXY_H_INCLUDED
//  Includes *******************************************************************
#include <Hg/datum/datum.h>
#include <Pb/bit_field/packed_bits.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A proxy template specialization for bitfield data types.
/// 
/// @param kt_idx
/// @param format_type
/// 
template <size_t    kt_idx,
          typename  format_t
        >
struct DataProxy<packed_trait, kt_idx, format_t>
  : public Datum<kt_idx, format_t>
{
  using datum_type = Datum < kt_idx, format_t>;
  using value_type = typename datum_type::value_type;
  using reference  = datum_type;

  //  **************************************************************************
  /// Default Constructor
  ///
  /// Initializes the internal buffer to a static nil instance that is legal to 
  /// call into with no actions performed.
  ///
  DataProxy()
  { }

  //  **************************************************************************
  /// Copy Constructor
  ///
  /// Makes a complete copy of an existing Proxy object, including internal
  /// references to the MsgBuffer that is associated with the base Datum instance.
  ///
  /// @param proxy           A reference to the Another instance of a DataProxy.
  /// 
  DataProxy(DataProxy& proxy)
    : datum_type(proxy)
  { 
    this->set(proxy.get());
  }

  //  **************************************************************************
  /// Conversion operator to a base Datum Type.
  /// 
  /// @note         The converted Datum base provides access to the Attach and
  ///               Flush functions of the Datum.
  /// 
  operator reference()
  {
    return *static_cast<datum_type*>(this);
  }

  //  **************************************************************************
  /// Value Conversion Operator (value_type) const
  /// 
  /// Allows the entire BitSet to be extracted and assigned as a value to
  /// the host value type.
  /// 
  operator value_type() const
  {
    return static_cast<const datum_type*>(this)->operator value_type();
  }

  //  **************************************************************************
  /// Value Conversion Operator (value_type)
  /// 
  /// Allows the entire BitSet to be extracted and assigned as a value to
  /// the host value type.
  /// 
  operator value_type()
  {
    return static_cast<datum_type*>(this)->operator value_type();
  }

  //  **************************************************************************
  /// Assignment Operator (value_type)
  /// 
  /// Allows assignment to this Datum type from it's parameter type, *value_type*.
  /// This function is the key to allowing the Datum to behave as if the
  /// assignment was performed directly on the the managed type.
  /// 
  /// @param rhs              A value of the Datum value_type that will
  ///                         be used to directly modify the value of the object.
  /// 
  DataProxy& 
    operator=(value_type rhs)                     
  { 
    datum_type::operator=(rhs);
    return *this;
  }
};

} // namespace detail

} // namespace Hg

#endif

