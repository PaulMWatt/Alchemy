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
#include <Pb/type_at.h>
#include <Hg/datum/basic_datum.h>

namespace Hg
{

//  ****************************************************************************
/// A type-wrapper that provides transparent access to a range 
/// of memory in message buffer is if it were the specified 
/// type itself.
///                 
/// The Datum<> is intended to be used as if it were the direct field itself.
/// All details of byte-order and memory-alignment are handled
/// internally by the buffers the Datum<> instance is mapped to.
/// 
/// @param  Idx               [size_t] The index of this element in the 
///                           TypeList definition.
///                           Idx must be < length<T>::value.
/// @param  format_t          [typename] The TypeList that contains this 
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
  // Concept check to verify a type container has been supplied.
  // TODO: Convert to a static_assertion
  // type_check< type_container<format_t>::value >;

public:
  //  Constants ****************************************************************
  static const
    size_t k_offset = OffsetOf<Idx, format_t>::value;
                                        ///< The offset in the buffer where this 
                                        ///  msg field is located.

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
    field_type::value_type              value_type;
                                        ///< The data type managed by this Datum.
                                        ///  This is the type of data that will 
                                        ///  be written to the attached buffer.

  typedef format_t                      format_type;
                                        ///< format of the parent TypeList.

  //  **************************************************************************
  /// Default Constructor
  ///
  Datum()
  { 
    set(value_type());
  }

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
  /// managed by this object. The value returned comes from the shadow buffer.
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
  /// from the buffer. Otherwise the shadow copy will be returned.
  /// This const version will not update the shadow copy from the buffer.
  /// 
  /// @return       The value of this Datum is returned.
  ///               If a valid buffer is associated with this field, the data
  ///               referenced in the buffer is returned.
  ///               Otherwise the temporary locally cached value is returned.
  /// 
  const value_type& get( ) const
  { 
    return GetShadow();
  }

  //  **************************************************************************
  /// Returns a reference to the value managed in this datum.
  ///
  value_type& get( )
  { 
    return RefShadowData();
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
    // Update the shadow copy.
    SetShadow(value);
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
  /// Returns a reference to the internal shadow data storage.
  /// 
  /// Returns a reference to the internal shadow data storage managed by this
  /// Datum. The reference to the data can be useful, and necessary for
  ///
  value_type& RefShadowData()                     
  { 
    field_type* pThis = static_cast<field_type*>(this);
    return pThis->m_shadow_data; 
  }

  //  **************************************************************************
  /// Returns the value of the shadow buffer.
  /// 
  const value_type& GetShadow() const                   
  { 
    const field_type* pThis = static_cast<const field_type*>(this);
    return pThis->m_shadow_data; 
  }

  //  **************************************************************************
  /// Returns the value of the shadow buffer.
  /// 
  void SetShadow(const value_type &value)                
  { 
    Hg::detail::copy_value_type(RefShadowData(), value);
  }
};

} // namespace Hg

#endif
