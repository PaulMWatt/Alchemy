/// @file bit_field_array.h
/// 
/// Defines the BitFieldArray construct for Alchemy Message Fields.
/// This is a specialized meta object the keeps track of a series of bit-field 
/// definitions for a message structure. 
///
/// Note: Currently the array of bit-fields is inefficient due to the number
///       of temporary objects that are constructed. This sub-type will be
///       optimized after the first mile-stone release.
///       The optimization will require an alternative bit-field list implementation
///       that allows the internal storage to be reassigned at run time.
///
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BIT_FIELD_ARRAY_H_INCLUDED
#define BIT_FIELD_ARRAY_H_INCLUDED
//  Includes ******************************************************************
#include <Pb/compiler.h>
#include <Pb/meta_util.h>

#include <Pb/meta_fwd.h>
#include <Pb/bit_field/packed_bits.h>
#include <Pb/bit_field/bit_field.h>
#include <Pb/integer_sequence.h>

#include <array>


namespace Hg
{

// ****************************************************************************
/// Represents a set of fields that provide homogeneous bit-field access to each
/// of the data values.
///           
/// This object requires a Hg bit-field definition for the type definition of
/// this object. The base integer type that is defined for the bit-field 
/// will be used to define the type for allocation of memory for the array.
/// 
/// Each field allocated in the array will accessible either by the base
/// integer type or with the bit-field interface provided supplied to the
/// definition.
///
template< typename T,
          size_t   N
        >
struct BitFieldArray
  : array_trait
{
public:
  //  Typedefs *****************************************************************
  typedef BitFieldArray<T,N>            this_type;
                                        ///< An alias for this classes definition.

  typedef T                             user_bit_field_type;
                                        ///< The type of bit-field interface 
                                        ///  defined by the user to access 
                                        ///  individual value entries in the array.

  // TODO: Remove this if the alternate implementation checks out.
  //typedef typename
  //  DeclareBitFieldList
  //    < user_bit_field_type>::type      

  typedef user_bit_field_type           bit_field_type;
                                        ///< The Hg type required to properly 
                                        ///  initialized nested structures to
                                        ///  provide the natural bit-field syntax.

  typedef typename
    T::value_type                       value_type;
                                        ///< The data type managed by this Array.
                                        ///  This is the type of data that will 
                                        ///  be written to the attached buffer.

  typedef std::array<value_type, N>     array_type;

  typedef                               ///  Reference to an element in the array.
    bit_field_type                      reference;
                                                                                
  typedef                               ///  Const Reference to an element in the array.
    const bit_field_type                const_reference;


  // TODO: Bit-field access through the iterator is not yet supported, 
  //       the user is actually receiving an iterator to an integer.

  typedef typename                      ///  An iterator to a value_type index.
    array_type::iterator                iterator;

  typedef typename                      ///  A const iterator to a value_type index.
    array_type::const_iterator          const_iterator;

  typedef typename                      ///  A reverse iterator to a value_type index.
    array_type::reverse_iterator        reverse_iterator;

  typedef typename                      ///  A const reverse iterator to a value_type index.
    array_type::const_reverse_iterator  const_reverse_iterator;


  //  Construction *************************************************************
  //  **************************************************************************
  /// Default Constructor
  /// 
  BitFieldArray()
  {
    // TODO: Considering a compilation flag to not initialize buffers for performance conscieous users.
    std::fill(m_data.begin(), m_data.end(), value_type());
  }


  //  **************************************************************************
  /// Copy Constructor.
  /// 
  BitFieldArray(const BitFieldArray &rhs)
  {
    std::copy( rhs.begin(), 
               rhs.end(), 
               begin());    
  }

  //  **************************************************************************
  /// Value constructor based on an array of raw integer type data.
  /// 
  BitFieldArray(const value_type (&rhs)[N])
  {
    ::memcpy(&m_data[0], &rhs[0], sizeof(value_type) * N);
  }

  //  **************************************************************************
  /// Destructor
  /// 
  ~BitFieldArray()
  { }

  //  **************************************************************************
  /// Assignment operator.
  /// 
  BitFieldArray& operator=(const BitFieldArray &rhs)
  {
    std::copy( rhs.begin(), 
               rhs.end(), 
               begin());  
    return *this;
  }

  //  **************************************************************************
  /// Value Assignment operator (Assigns a raw array of the correct size.)
  /// 
  BitFieldArray& operator=(const value_type (&rhs)[N])
  {
    ::memcpy(&m_data[0], &rhs[0], sizeof(value_type) * N);

    return *this;
  }

  //  **************************************************************************
  /// Returns a pointer to the raw data buffer for the container for reference.
  /// 
  const value_type* data() const                  
  { 
    return &m_data[0]; 
  }

  //  **************************************************************************
  /// Returns a pointer to the raw data buffer for the container for assignment.
  /// 
  value_type* data()                              
  { 
    return &m_data[0]; 
  }

  //  **************************************************************************
  /// Indicates if this container contains 0 elements.
  /// 
  bool empty() const
  {
    return size() == 0;
  }

  //  **************************************************************************
  /// Returns the number of elements within the array.
  /// 
  size_t size() const                             
  { 
    return m_data.size(); 
  }

  //  **************************************************************************
  /// Returns the number of bytes required to hold the entire array of data.
  /// 
  size_t data_size() const                        
  { 
    return size() * sizeof(value_type); 
  }

  //  **************************************************************************
  /// Conversion operator to the value_type reference.
  /// 
  /// @note         The converted array interface provides direct access values.
  /// 
  operator reference()
  {
// TODO: Investigate if this is necessary, and add the correct implementation.
    //return *static_cast<datum_type*>(this);
    return reference();
  }

  //  **************************************************************************
  /// Value Conversion Operator (value_type)
  /// 
  /// Allows the entire BitSet to be extracted and assigned as a value to
  /// the host value type.
  /// 
  operator value_type() const
  {
//    return static_cast<const datum_type*>(this)->operator value_type();
    return value_type();
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference at(size_t idx) const            
  { 
    // Remove constness to allow the non-const calls
    // from the bit-field implementation to be called.
    // A const instance of the object will be returned.
    this_type *pThis = const_cast<this_type*>(this);

    return const_reference(pThis->m_data.at(idx));
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference at(size_t idx)                        
  { 
    return reference(m_data.at(idx)); 
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference operator[](size_t idx) const
  { 
    // Remove constness to allow the non-const calls
    // from the bit-field implementation to be called.
    // A const instance of the object will be returned.
    this_type *pThis = const_cast<this_type*>(this);

    return const_reference(pThis->m_data[idx]);
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference operator[](size_t idx)                
  { 
    return reference(m_data[idx]); 
  }

  //  **************************************************************************
  /// Accesses the first value in the array data..
  /// 
  const_reference front() const
  { 
    // Remove constness to allow the non-const calls
    // from the bit-field implementation to be called.
    // A const instance of the object will be returned.
    this_type *pThis = const_cast<this_type*>(this);

    return const_reference(pThis->m_data.front());
  }

  //  **************************************************************************
  /// Accesses the first value in the array data..
  /// 
  reference front()                               
  { 
    return reference(m_data.front()); 
  }

  //  **************************************************************************
  /// Accesses the last valid value in the array data..
  /// 
  const_reference back() const
  { 
    // Remove constness to allow the non-const calls
    // from the bit-field implementation to be called.
    // A const instance of the object will be returned.
    this_type *pThis = const_cast<this_type*>(this);

    return const_reference(pThis->m_data.back());
  }

  //  **************************************************************************
  /// Accesses the last valid value in the array data..
  /// 
  reference back()                                
  { 
    return reference(m_data.back()); 
  }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the array.
  /// 
  iterator begin()                                { return m_data.begin();  }
  const_iterator begin()  const                   { return m_data.begin();  }
  const_iterator cbegin() const                   { return m_data.cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the array.
  /// 
  iterator end()                                  { return m_data.end();    }
  const_iterator end()  const                     { return m_data.end();    }
  const_iterator cend() const                     { return m_data.cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the array moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return m_data.rbegin(); }
  const_reverse_iterator rbegin()  const          { return m_data.rbegin(); }
  const_reverse_iterator crbegin() const          { return m_data.crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the array,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return m_data.rend();   }
  const_reverse_iterator rend()  const            { return m_data.rend();   }
  const_reverse_iterator crend() const            { return m_data.crend();  } 


private:
  //  Data Members *************************************************************
  array_type                  m_data;   ///< The data buffers that hold the 
                                        ///  raw values for the collection of
                                        ///  bit-fields.
};


} // namespace Hg


#endif
