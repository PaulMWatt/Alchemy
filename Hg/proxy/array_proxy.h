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

#include <Pb/meta_fwd.h>
#include <Pb/type_list.h>
#include <Pb/type_at.h>
#include <Hg/datum/datum.h>
#include <Pb/bit_field/bit_field_array.h>
#include <Hg/storage_policy.h>
#include <array>

namespace Hg
{

namespace detail
{

//  Forward Declarations (No Default Implementation) ***************************
template< class ArrayT >
struct array_size;


//  ****************************************************************************
/// Extracts the array extent from a std::array definition.
///
template< class T, size_t N>
struct array_size< std::array<T, N> > 
  : std::integral_constant<size_t, N>
{ };

//  ****************************************************************************
/// Extracts the array extent from a std::array definition.
///
template< class T, size_t N>
struct array_size< Hg::BitFieldArray<T, N> > 
  : std::integral_constant<size_t, N>
{ };


//  ****************************************************************************
/// A template to provide access to sequences of data fields.
/// 
/// @paramt IdxT        The index of the array field represented by this proxy.
/// @paramt FormatType  The type list format that contains the array field.
/// 
template< size_t    IdxT,
          typename  FormatT
        >
struct DataProxy <array_trait, IdxT, FormatT>
  : public Hg::Datum<IdxT, FormatT>
{
  //  Typedefs *****************************************************************
  typedef FormatT                       format_type;

  typedef  
    Hg::Datum < IdxT,
                format_type
              >                         datum_type;

  typedef typename
    detail::DefineFieldType < IdxT, 
                              format_type
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
    const size_t k_extent = array_size<index_type>::value;
                                        ///< The number of elements in the array.

  //  Typedefs *****************************************************************
  typedef typename 
  std::conditional< std::is_base_of<array_trait, index_type>::value,
                    index_type,                  
                    typename field_type::value_type                  
                  >::type
                                        value_type;

                                        ///< The data type managed by this Array.
                                        ///  This is the type of data that will 
                                        ///  be written to the attached buffer.
                                        ///
                                        ///  The index_type is redefined here
                                        ///  in order to capture and convert array
                                        ///  definitions like this: "(&T) [N]"
                                        ///  To the form: std::array<T,N>


  
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

#ifdef ALCHEMY_RVALUE_REF_SUPPORTED

  //  **************************************************************************
  /// Move Constructor
  ///
  /// Moves the current instance from one proxy to another.
  ///
  /// @param proxy           A rvalue  reference to the another instance of a DataProxy.
  /// 
  DataProxy(DataProxy&& proxy)
    : m_data(std::move(proxy.m_data))
  { }
  
  //  **************************************************************************
  /// Move Assignment operator
  ///
  /// Moves the current instance from one proxy to another.
  ///
  /// @param proxy           A rvalue  reference to the another instance of a DataProxy.
  /// 
  DataProxy& operator=(DataProxy&& proxy)
  {
    this->set(std::forward<DataProxy>proxy.get());
    return *this;
  }

#endif


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
  size_t size() const                             { return this->get().size(); }

  //  **************************************************************************
  /// Returns the number of bytes that are required to hold this array in a buffer.
  /// 
  size_t size_of() const                          { return sizeof(this->get()); }


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
  const_reference at(size_t idx) const            { return this->get().at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference at(size_t idx)                        { return this->get().at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference operator[](size_t idx) const    { return this->get()[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference operator[](size_t idx)                { return this->get()[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference front() const                   { return this->get().front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference front()                               { return this->get().front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference back() const                    { return this->get().back(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference back()                                { return this->get().back(); }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the array.
  /// 
  iterator begin()                                { return this->get().begin();  }
  const_iterator begin()  const                   { return this->get().begin();  }
  const_iterator cbegin() const                   { return this->get().cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the array.
  /// 
  iterator end()                                  { return this->get().end();    }
  const_iterator end()  const                     { return this->get().end();    }
  const_iterator cend() const                     { return this->get().cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the array moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return this->get().rbegin(); }
  const_reverse_iterator rbegin()  const          { return this->get().rbegin(); }
  const_reverse_iterator crbegin() const          { return this->get().crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the array,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return this->get().rend();   }
  const_reverse_iterator rend()  const            { return this->get().rend();   }
  const_reverse_iterator crend() const            { return this->get().crend();  } 
};


} // namespace detail

} // namespace Hg

#endif
