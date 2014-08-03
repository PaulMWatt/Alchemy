/// @file detail/array_proxy.h
/// 
/// A parameterized type that abstracts the details of accessing Array entries
/// with a fixed-size field length.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef ARRAY_PROXY_H_INCLUDED
#define ARRAY_PROXY_H_INCLUDED
//  Includes ******************************************************************

#include <meta/meta_fwd.h>
#include <meta/type_list.h>
#include <meta/type_at.h>
#include <detail/datum.h>
#include <storage_policy.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A template to provide access to sequences of data fields.
/// 
/// @paramt IdxT
/// @paramt FormatType
/// @paramt OffsetT
/// 
template< size_t    IdxT,
          typename  FormatT,
          size_t    OffsetT
        >
struct DataProxy <array_trait, IdxT, FormatT, OffsetT>
  : public Hg::Datum<IdxT, FormatT, OffsetT>
{
  //  Typedefs *****************************************************************
  typedef FormatT                       format_type;

    typedef typename 
      Hg::Datum < IdxT,
                  format_type,
                  OffsetT
                >                       datum_type;

  typedef typename
    detail::DefineFieldType < IdxT, 
                              format_type, 
                              OffsetT
                            >::type     field_type;
                                        ///< Type mapping for the message format
                                        ///  type to the actual value_type.

  typedef typename
    field_type::index_type              index_type;
                                        ///< The type extracted at the current
                                        ///  index defined in the parent TypeList.

  typedef typename
    index_type::value_type              data_type;
                                        ///< The value type of the element extracted 
                                        ///  at the current index defined in the 
                                        ///  parent TypeList.

  //  Constants ****************************************************************
  static 
    const size_t k_extent = Hg::SizeOf<index_type>::value 
                          / Hg::SizeOf<data_type >::value;
                                        ///< The number of elements in the array.

  //  Typedefs *****************************************************************
  typedef std::array< data_type, 
                      k_extent
                    >                   value_type;
                                        ///< The data type managed by this Array.
                                        ///  This is the type of data that will 
                                        ///  be written to the attached buffer.
  
  typedef typename                      ///  Reference to an element in the array.
    value_type::reference               reference;
                                                                                
  typedef typename                      ///  Const Reference to an element in the array.
    value_type::const_reference         const_reference;

  typedef typename                      ///  An iterator to a value_type index.
    value_type::iterator                iterator;

  typedef typename                      ///  A const iterator to a value_type index.
    value_type::const_iterator          const_iterator;

  typedef typename                      ///  A reverse iterator to a value_type index.
    value_type::reverse_iterator        reverse_iterator;

  typedef typename                      ///  A const reverse iterator to a value_type index.
    value_type::const_reverse_iterator  const_reverse_iterator;

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
    set(proxy.get());
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
  /// Value Constructor: Construct a proxy directly from a datum instance.
  ///
  /// @param datum           A reference to a datum object used to initilize this.
  /// 
  DataProxy(const value_type& value)
  { 
    set(value);
  }

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
  DataProxy& operator=(const value_type &value)
  {
    set(value);
    return *this;
  }

  //  **************************************************************************
  /// Returns the number of valid objects managed by this array structure.
  /// 
  size_t size() const                             { return get().size(); }

  //  **************************************************************************
  /// Returns the number of bytes that are required to hold this array in a buffer.
  /// 
  size_t size_of() const                          { return sizeof(get()); }


  //  **************************************************************************
  /// Updates the value of this ArrayProxy with a std::array type. 
  /// 
  /// @param value  The array which will initialize this object.
  /// 
  void set(const value_type& value)
  {
    std::copy( value.begin(), 
               value.end(), 
               begin());
  }

  //  **************************************************************************
  /// Updates the value of this Array with a native array type. 
  /// 
  /// @param value  The array which will initialize this object.
  /// 
  void set(const data_type (&value)[k_extent])
  {
    if (!value)
    {
      // TODO: Return and add exception handling. 
      return;
    }

    std::copy( &value[0], 
              (&value[0]) + k_extent, 
                begin());
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
  /// Value Conversion Operator (value_type)
  /// 
  /// Allows the entire BitSet to be extracted and assigned as a value to
  /// the host value type.
  /// 
  operator value_type() const
  {
    return static_cast<const datum_type*>(this)->operator value_type();
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference at(size_t idx) const            { return get().at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference at(size_t idx)                        { return get().at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference operator[](size_t idx) const    { return get()[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference operator[](size_t idx)                { return get()[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference front() const                   { return get().front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference front()                               { return get().front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference back() const                    { return get().back(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference back()                                { return get().back(); }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the array.
  /// 
  iterator begin()                                { return get().begin();  }
  const_iterator begin()  const                   { return get().begin();  }
  const_iterator cbegin() const                   { return get().cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the array.
  /// 
  iterator end()                                  { return get().end();    }
  const_iterator end()  const                     { return get().end();    }
  const_iterator cend() const                     { return get().cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the array moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return get().rbegin(); }
  const_reverse_iterator rbegin()  const          { return get().rbegin(); }
  const_reverse_iterator crbegin() const          { return get().crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the array,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return get().rend();   }
  const_reverse_iterator rend()  const            { return get().rend();   }
  const_reverse_iterator crend() const            { return get().crend();  } 
};


} // namespace detail

} // namespace Hg

#endif
