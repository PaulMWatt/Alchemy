/// @file detail/array_data.h
/// 
/// Declarations for the class of data fields that can store multiple entries.
///           
/// A parameterized type that abstracts the details of accessing a set of
/// homogenous Datum entries.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef ARRAY_DATA_H_INCLUDED
#define ARRAY_DATA_H_INCLUDED
//  Includes ******************************************************************
#include <detail/multival_data.h>
#include <detail/datum.h>
#include <array>

namespace Hg
{

using std::array;

//  ****************************************************************************
/// Aggregation definition of the standard array to associate the array_trait
///                 
//template< typename  T, 
//          size_t    N 
//        >
//struct array
//  : array_trait
//  , public std::array<T,N>
//{ };


//  ****************************************************************************
/// MACRO that defines a fixed-size array for Typelist definitions.
/// This MACRO is defined for convenience.
///                 
#define HG_TYPE_ARRAY(TYPE, COUNT)      array<TYPE, COUNT>


//  ****************************************************************************
/// A type-wrapper that provides transparent access to a range 
/// of memory in message buffer is if it were the specified 
/// type itself.
///                 
/// The ArrayData<> is intended to be used as if it were the array of fields.
/// All details of byte-order and memory-alignment are handled
/// internally by the buffers the Datum<> instance is mapped to.
///
/// Unlike the base Datum, the ArrayData object does not allow direct assignment
/// of the values. This object manages a set of Data entries. Therefore, the
/// individual Datum objects will be reference by index. 
/// 
/// @param  Idx               [size_t] The index of this element in the 
///                           TypeList definition.
///                           Idx must be < length<T>::value.
/// @param  T                 [typename] The TypeList that contains this 
///                           elements definition.
///                           T must be an indexable type container.
/// @note           Parameterized type **T** is verified by the compiler to be
///                 A type container.
///              
template <size_t   Idx, 
          typename format_t, 
          size_t   kt_offset = 0
         >
class ArrayData
  : type_check< type_container<format_t>::value >
  , public detail::FieldTypes < typename Hg::TypeAt<Idx, format_t>::type,
                                Hg::OffsetOf<Idx, format_t>::value + kt_offset
                              >
{
public:
  //  Typedefs *****************************************************************
  typedef typename
    detail::DefineFieldType < Idx, 
                              format_t
                            >::type     field_type;
                                        ///< Type mapping for the message format
                                        ///  type to the actual value_type.

  typedef typename
    field_type::index_type              index_type;
                                        ///< The type extracted at the current
                                        ///  index defined in the parent TypeList.

  typedef typename
    index_type::value_type              data_type;
                                        ///< The type extracted at the current
                                        ///  index defined in the parent TypeList.
  
  //  Constants ****************************************************************
  static const
    size_t k_offset = OffsetOf<Idx, format_t>::value
                    + kt_offset;        ///< The offset in the buffer where this 
                                        ///  msg field is located.
  static 
    const size_t k_extent = Hg::SizeOf<index_type>::value 
                          / Hg::SizeOf<data_type >::value;
                                        ///< The number of elements in the array.

  //  Typedefs *****************************************************************
  typedef std::array< data_type, 
                      k_extent
                    >                   value_type;
                                        ///< The data type managed by this ArrayData.
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
  ArrayData()
  { }

  //  **************************************************************************
  /// Copy Constructor
  /// 
  ArrayData(const ArrayData& rhs)
  {
    set(rhs.get());
  }

  //  **************************************************************************
  /// Value constructor to initialize from an array type.
  /// 
  ArrayData(const value_type& rhs)
  {
    set(rhs);
  }

  //  **************************************************************************
  /// Value constructor to initialize from an array type.
  /// 
  explicit
    ArrayData(const data_type (&rhs)[k_extent])
  {
    if (!rhs)
    {
      // TODO: Add exception throw here for invalid input.
    }

    set(rhs);
  }

  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// Allows assignment of the ArrayData value. 
  /// 
  /// @param rhs              A different instance of a ArrayData object whose
  ///                         value will be copied into this instance.
  /// 
  // TODO: Revisit, ensure the implementation is valid.
  ArrayData& operator=(const ArrayData& rhs)               
  { 
    if (this != &rhs)
    { 
      std::copy(rhs.begin(), rhs.end(), begin());
    }

    return *this;
  }

  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// Allows assignment of the ArrayData value. 
  /// 
  /// @param rhs              A different instance of a ArrayData object whose
  ///                         value will be copied into this instance.
  /// 
  // TODO: Revisit, ensure the implementation is valid.
  ArrayData& operator=(const value_type& rhs)               
  { 
    if (this != &rhs)
    { 
      m_shadow_data.assign(rhs.begin(), rhs.end());
    }

    return *this;
  }

  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// Allows assignment from a native array type. 
  /// 
  /// @param rhs              A native array definition to matches the
  ///                         this objects type and extent.
  /// 
  // TODO: Revisit, ensure the implementation is valid.
  ArrayData& operator=(const data_type rhs[k_extent])
  { 
    if (this != rhs)
    { 
      m_shadow_data.assign(&rhs[0], &rhs[0] + k_extent);
    }

    return *this;
  }

  //  Comparison Operators *****************************************************
  //  **************************************************************************
  /// Equality Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator==(const value_type& rhs) const    { return equivalent(rhs); }

  //  **************************************************************************
  /// Inequality Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator!=(const value_type& rhs) const    { return !equivalent(rhs);}

  //  **************************************************************************
  /// less Than Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator< (const value_type& rhs) const    { return less(rhs);       }

  //  Methods ******************************************************************
  //  **************************************************************************
  /// Zeros the Data buffers.
  /// 
  void clear ( )                                  
  { 
    m_shadow_data.fill(data_type());
  }

  //  **************************************************************************
  /// Returns the number of valid objects managed by this array structure.
  /// 
  size_t size() const                             { return m_shadow_data.size(); }

  //  **************************************************************************
  /// Returns the number of bytes that are required to hold this array in a buffer.
  /// 
  size_t size_of() const                          { return sizeof(m_shadow_data); }

  //  **************************************************************************
  /// Returns the current value of this ArrayData.
  /// 
  /// @return       The value of this ArrayData is returned.
  /// 
  const value_type& get( ) const
  { 
    return GetShadow();
  }

  //  **************************************************************************
  /// Updates the value of this ArrayData.
  /// 
  /// @param value  The value to assign to this object. 
  /// 
  void set(const value_type &value)
  {
    SetShadow(value);
  }

  //  **************************************************************************
  /// Updates the value of this ArrayData with a native array type. 
  /// 
  /// @param value  The array which will initialize this object.
  /// 
  void set(const data_type (&value)[k_extent])
  {
    SetShadow(value);
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference at(size_t idx) const            { return m_shadow_data.at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference at(size_t idx)                        { return m_shadow_data.at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference operator[](size_t idx) const    { return m_shadow_data[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference operator[](size_t idx)                { return m_shadow_data[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference front() const                   { return m_shadow_data.front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference front()                               { return m_shadow_data.front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference back() const                    { return m_shadow_data.back(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference back()                                { return m_shadow_data.back(); }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the array.
  /// 
  iterator begin()                                { return m_shadow_data.begin();  }
  const_iterator begin()  const                   { return m_shadow_data.begin();  }
  const_iterator cbegin() const                   { return m_shadow_data.cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the array.
  /// 
  iterator end()                                  { return m_shadow_data.end();    }
  const_iterator end()  const                     { return m_shadow_data.end();    }
  const_iterator cend() const                     { return m_shadow_data.cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the array moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return m_shadow_data.rbegin(); }
  const_reverse_iterator rbegin()  const          { return m_shadow_data.rbegin(); }
  const_reverse_iterator crbegin() const          { return m_shadow_data.crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the array,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return m_shadow_data.rend();   }
  const_reverse_iterator rend()  const            { return m_shadow_data.rend();   }
  const_reverse_iterator crend() const            { return m_shadow_data.crend();  } 

  //  **************************************************************************
  /// 
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool equivalent(const value_type &rhs) const    { return get() == rhs; }

  //  **************************************************************************
  /// 
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool less (const value_type &rhs) const         { return get() < rhs; }

protected:
  //  **************************************************************************
  /// Returns a reference to the internal shadow data storage.
  /// 
  /// Returns a reference to the internal shadow data storage managed by this
  /// ArrayData. The reference to the data can be useful, and necessary for
  ///
  value_type& ShadowData()                     
  { 
    return m_shadow_data;
  }

  //  **************************************************************************
  /// Returns the value of the shadow buffer.
  /// 
  const value_type& GetShadow() const                   
  { 
    return m_shadow_data;
  }

  //  **************************************************************************
  /// Sets the value of the shadow buffer from an array<> container.
  /// 
  void SetShadow(const value_type& value)                
  { 
    std::copy( &value[0], 
              (&value[0]) + k_extent, 
               ShadowData().begin());
  }

  //  **************************************************************************
  /// Sets the value of the shadow buffer from a native array definition.
  /// 
  void SetShadow(const data_type (&value)[k_extent])
  { 
    std::copy( &value[0], 
              (&value[0]) + k_extent, 
               ShadowData().begin());
  }
};

} // namespace Hg

#endif
