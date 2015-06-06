/// @file datum.h
/// 
/// A type-wrapper that provides transparent access to a 
/// range of memory in message buffer, as if it were the 
/// specified type itself.
///           
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DATUM_H_INCLUDED
#define DATUM_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/meta_fwd.h>
#include <Hg/datum/basic_datum.h>

namespace Hg
{

//  ****************************************************************************
/// A type-wrapper that provides transparent access to a range 
/// of memory in a message buffer as if it were the specified 
/// type itself.
///                 
/// The Datum<> is intended to be used as if it were the direct field itself.
/// All details of byte-order and memory-alignment are handled
/// internally by the buffers the Datum<> instance is mapped to.
/// 
/// @param  Idx               [size_t] The index of this element in the 
///                           type_list definition.
///                           Idx must be < length<T>::value.
/// @param  format_t          [typename] The type_list that contains this 
///                           elements definition.
///                           T must be an indexable type container.
/// @note           Parameterized type **T** is verified by the compiler to be
///                 A type container.
///              
template <size_t   Idx, 
          typename format_t
         >
class Datum
  : public detail::DefineFieldType< Idx, format_t>::type
{
  static_assert(type_container<format_t>::value, "format_t must be a type container.");

public:
  //  Constants ****************************************************************
  /// The offset in the buffer where this 
  /// msg field is located.
  static const
    size_t k_offset = offset_of<Idx, format_t>::value;

  //  Aliases ******************************************************************
  /// Type mapping for the message format
  /// type to the actual value_type.
  using field_type = typename detail::DefineFieldType < Idx, format_t>::type;

  /// The type extracted at the current
  /// index defined in the parent type_list.
  using index_type = typename field_type::index_type;

  /// The data type managed by this Datum.
  /// This is the type of data that will 
  /// be written to the attached buffer.
  using value_type = typename field_type::value_type;

  /// format of the parent type_list.
  using format_type= format_t;

  //  **************************************************************************
  /// Default Constructor
  ///
  Datum()
    : field_type()
  { }

  //  **************************************************************************
  /// Copy Constructor
  ///
  /// Makes a complete copy of an existing Datum object.
  ///
  /// @param datum            A reference to the Another instance of a Datum.
  /// 
  Datum(Datum& datum)
  { 
    set(datum.get());
  }

  //  **************************************************************************
  /// Move Constructor
  ///
  /// Moves the current instance from one datum to another.
  ///
  /// @param proxy           A rvalue  reference to the another instance of a Datum.
  /// 
  Datum(Datum&& datum)
  {
    *this = std::move(datum);
  }
  
  //  **************************************************************************
  /// Move Assignment operator
  ///
  /// Moves the current instance from one datum to another.
  ///
  /// @param proxy           A rvalue  reference to the another instance of a Datum.
  /// 
  Datum& operator=(Datum&& datum)
  {
    this->set(datum.get());
    return *this;
  }

  //  **************************************************************************
  /// Assignment Operator
  /// 
  /// Allows assignment of the Datum value. 
  /// Associated buffers are not changed through assignment.
  /// 
  /// @param rhs              A different instance of a Datum object whose
  ///                         value will be copied into this instance.
  /// 
  Datum& operator=(const Datum& rhs)              
  { 
    set(rhs.get());
    return *this;
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
  Datum& 
    operator=(value_type rhs)                     
  { 
    set(rhs);
    return *this;
  }

  //  **************************************************************************
  /// Operator to value_type
  /// 
  /// Allows this Datum object to be converted to the value_type 
  /// managed by this object. The value returned comes from the data buffer.
  /// 
  /// @return         The current value of this object is returned.
  /// 
  operator value_type() const                     
  { 
    return get(); 
  }

  //  Comparison Operators *****************************************************
  //  **************************************************************************
  /// Equality Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator==(const value_type& rhs) const    
  { 
    return equivalent(rhs);
  }

  //  **************************************************************************
  /// Inequality Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator!=(const value_type& rhs) const    
  { 
    return !equivalent(rhs);
  }

  //  **************************************************************************
  /// less Than Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator< (const value_type& rhs) const    
  { 
    return less(rhs);         
  }

  //  **************************************************************************
  /// less Than or equal Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator<=(const value_type& rhs) const    
  { 
    return less(rhs)
        || equivalent(rhs);
  }

  //  **************************************************************************
  /// Greater Than or equal Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator>=(const value_type& rhs) const    
  { 
    return !less(rhs);        
  }

  //  **************************************************************************
  /// Greater Than Value Comparison (value_type)
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool operator> (const value_type& rhs) const    
  { 
    return !operator<=(rhs);  
  }

  //  Methods ******************************************************************
  //  **************************************************************************
  /// Zeros the datum.
  /// 
  void clear ( )                                  
  { 
    set(value_type()); 
  }

  //  **************************************************************************
  /// Returns the current value of this Datum.
  /// 
  /// If a buffer is attached to this message field, the value will be read 
  /// from the buffer. Otherwise the data will be returned.
  /// This const version will not update the data from the buffer.
  /// 
  /// @return       The value of this Datum is returned.
  ///               If a valid buffer is associated with this field, the data
  ///               referenced in the buffer is returned.
  ///               Otherwise the temporary locally cached value is returned.
  /// 
  const value_type& get( ) const
  { 
    return get_data();
  }

  //  **************************************************************************
  /// Returns a reference to the value managed in this datum.
  ///
  value_type& get( )
  { 
    return get_reference();
  }


  //  **************************************************************************
  /// Updates the value of this Datum.
  /// 
  /// @param value  The value to assign to this object. 
  ///               The local cached value will be updated.
  ///               If a buffer has been associated with this object, its data
  ///               will be updated with the value as well.
  /// 
  void set(const value_type& value)
  {
    set_data(value);
  }

  //  **************************************************************************
  /// Indicates equivalency for a value_type and this Datum's value.
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool equivalent(const value_type &rhs) const
  {
    return get() == rhs;
  }

  //  **************************************************************************
  /// Compares a value_type against this Datum's value for less-than relationship.
  /// 
  /// @param rhs              A value_type value to compare with the value
  ///                         of this instance.
  ///                         
  bool less(const value_type &rhs) const
  {
    return get() < rhs;
  }

protected:
  //  **************************************************************************
  /// Returns a reference to the internal data storage.
  /// 
  /// Returns a reference to the internal data storage managed by this
  /// Datum. The reference to the data can be useful, and necessary for
  ///
  value_type& get_reference()
  { 
    field_type* pThis = static_cast<field_type*>(this);
    return static_cast<field_type*>(this)->reference();
  }

  //  **************************************************************************
  /// Returns the value of the data buffer.
  /// 
  const value_type& get_data() const
  { 
    // remove constness to be able to call the request for data.
    // This functions return type is const, so no violation of invariants.
    return static_cast<const field_type*>(this)->data();
  }

  //  **************************************************************************
  /// Sets the value into the data buffer.
  /// 
  void set_data(const value_type &value)                
  { 
    Hg::detail::copy_value_type(get_reference(), value);
  }
};

} // namespace Hg

#endif
