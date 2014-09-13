/// @file bit_field_vector.h
/// 
/// Defines the BitFieldVector construct for Alchemy Message Fields.
/// This is a specialized meta object the keeps track of a series of bit-field 
/// definitions for a message structure. 
///
/// Note: Currently the vector of bit-fields is inefficient due to the number
///       of temporary objects that are constructed. This sub-type will be
///       optimized after the first mile-stone release.
///       The optimization will require an alternative bit-field list implementation
///       that allows the internal storage to be reassigned at run time.
///
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BIT_FIELD_VECTOR_H_INCLUDED
#define BIT_FIELD_VECTOR_H_INCLUDED
//  Includes ******************************************************************
#include <meta/compiler.h>
#include <meta/meta_util.h>
#include <meta/bit_field_list.h>
#include <vector>


namespace Hg
{

// ****************************************************************************
/// Represents a set of fields that provide homogeneous bit-field access to each
/// of the data values.
///           
/// This object requires a Hg bit-field definition for the type definition of
/// this object. The base integer type that is defined for the bit-field 
/// will be used to define the type for allocation of memory for the vector.
/// 
/// Each field allocated in the vector will accessible either by the base
/// integer type or with the bit-field interface provided supplied to the
/// definition.
///
template< typename T,
          typename A = std::allocator<T>
        >
struct BitFieldVector
  : vector_trait
{
public:
  //  Typedefs *****************************************************************
  typedef BitFieldVector<T,A>           this_type;
                                        ///< An alias for this classes definition.

  typedef T                             user_bit_field_type;
                                        ///< The type of bit-field interface 
                                        ///  defined by the user to access 
                                        ///  individual value entries in the vector.

  typedef typename
    DeclareBitFieldList
      < user_bit_field_type>::type      bit_field_type;
                                        ///< The Hg type required to properly 
                                        ///  initialized nested structures to
                                        ///  provide the natural bit-field syntax.

  typedef typename
    T::value_type                       value_type;
                                        ///< The data type managed by this vector.
                                        ///  This is the type of data that will 
                                        ///  be written to the attached buffer.
  typedef A                             allocator_type;
                                        ///< The allocator used by this vector.


  typedef std::vector<value_type, A>    vector_type;

  typedef typename                      ///  Reference to an element in the vector.
    bit_field_type                      reference;
                                                                                
  typedef typename                      ///  Const Reference to an element in the vector.
    const bit_field_type                const_reference;


  // TODO: Bit-field access through the iterator is not yet supported, 
  //       the user is actually receiving an iterator to an integer.

  typedef typename                      ///  An iterator to a value_type index.
    vector_type::iterator               iterator;

  typedef typename                      ///  A const iterator to a value_type index.
    vector_type::const_iterator         const_iterator;

  typedef typename                      ///  A reverse iterator to a value_type index.
    vector_type::reverse_iterator       reverse_iterator;

  typedef typename                      ///  A const reverse iterator to a value_type index.
    vector_type::const_reverse_iterator const_reverse_iterator;


  //  Construction *************************************************************
  //  **************************************************************************
  /// Default Constructor
  /// 
  BitFieldVector()
  {
    // TODO: Considering a compilation flag to not initialize buffers for performance conscieous users.
    std::fill(m_data.begin(), m_data.end(), value_type());
  }


  //  **************************************************************************
  /// Copy Constructor.
  /// 
  BitFieldVector(const BitFieldVector &rhs)
  {
    std::copy( rhs.begin(), 
               rhs.end(), 
               begin());    
  }

  //  **************************************************************************
  /// Destructor
  /// 
  ~BitFieldVector()
  { }

  //  **************************************************************************
  /// Assignment operator.
  /// 
  BitFieldVector& operator=(const BitFieldVector &rhs)
  {
    std::copy( rhs.begin(), 
               rhs.end(), 
               begin());  
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
  /// Erases every element in the vector.
  /// 
  void clear()
  {
    m_data.clear();  
  }

  //  **************************************************************************
  /// Indicates if this container contains 0 elements.
  /// 
  bool empty() const
  {
    return size() == 0;
  }

  //  **************************************************************************
  /// Returns the number of elements within the vector.
  /// 
  size_t size() const                             
  { 
    return m_data.size(); 
  }

  //  **************************************************************************
  /// Returns the number of bytes required to hold the entire vector of data.
  /// 
  size_t data_size() const                        
  { 
    return size() * sizeof(value_type); 
  }

  //  **************************************************************************
  /// Changes the number of elements stored.
  ///
  /// @param n      The number of elements the container should now hold.
  /// 
  void resize(size_t count)                       { resize(count, value_type()); }

  //  **************************************************************************
  /// Changes the number of elements stored.
  ///
  /// @param n      The number of elements the container should now hold.
  /// @param value  Default value to initialize elements if the resize
  ///               causes new elements to be added to the container.
  /// 
  void resize(size_t     count, 
              value_type value)                   { m_data.resize(count, value); }

  //  **************************************************************************
  /// Conversion operator to the value_type reference.
  /// 
  /// @note         The converted vector interface provides direct access values.
  /// 
  operator reference()
  {
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
  /// Accesses the value at the specified index in the vector data..
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
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference at(size_t idx)                        
  { 
    return reference(m_data.at(idx)); 
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
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
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference operator[](size_t idx)                
  { 
    return reference(m_data[idx]); 
  }

  //  **************************************************************************
  /// Accesses the first value in the vector data..
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
  /// Accesses the first value in the vector data..
  /// 
  reference front()                               
  { 
    return reference(m_data.front()); 
  }

  //  **************************************************************************
  /// Accesses the last valid value in the vector data..
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
  /// Accesses the last valid value in the vector data..
  /// 
  reference back()                                
  { 
    return reference(m_data.back()); 
  }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the vector.
  /// 
  iterator begin()                                { return m_data.begin();  }
  const_iterator begin()  const                   { return m_data.begin();  }
  const_iterator cbegin() const                   { return m_data.cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the vector.
  /// 
  iterator end()                                  { return m_data.end();    }
  const_iterator end()  const                     { return m_data.end();    }
  const_iterator cend() const                     { return m_data.cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the vector moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return m_data.rbegin(); }
  const_reverse_iterator rbegin()  const          { return m_data.rbegin(); }
  const_reverse_iterator crbegin() const          { return m_data.crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the vector,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return m_data.rend();   }
  const_reverse_iterator rend()  const            { return m_data.rend();   }
  const_reverse_iterator crend() const            { return m_data.crend();  } 

  //  Modifiers ****************************************************************
  //  **************************************************************************
  /// Removes the specified element from this container.
  ///
  /// @param pos    Iterator that points to the element to be removed.
  ///
  /// @return       The iterator that follows the last item removed is returned.
  ///
  /// @note         All iterators at or after this point of erasure will be
  ///               invalidated.
  ///
  iterator erase(iterator pos)                    { return m_data.erase(pos);   }

  //  **************************************************************************
  /// Removes the range of specified elements from this container.
  ///
  /// @param first  Iterator that points to the first element to be removed.
  /// @param last   Iterator that points to the last element to be removed.
  ///
  /// @return       The iterator that follows the last item removed is returned.
  ///
  /// @note         All iterators at or after this point of erasure will be
  ///               invalidated.
  ///
  iterator erase(iterator first, iterator last)   { return m_data.erase(first, last);}

  //  **************************************************************************
  /// Removes the specified element from this container.
  ///
  /// @param pos    Iterator that points to the element to be removed.
  ///
  /// @return       The iterator that follows the last item removed is returned.
  ///
  /// @note         All iterators at or after this point of erasure will be
  ///               invalidated.
  ///
  void push_back(const vector_type& value)        { m_data.push_back(value);   }

  //  **************************************************************************
  /// Removes the last element in the container.
  ///
  /// @note: Iterators that point to the last element and end will be 
  ///        invalidated after this call.
  ///
  void pop_back()                                 { if (!m_data.empty()) {
                                                      m_data.pop_back(); 
                                                    }
                                                  }

  //  **************************************************************************
  /// Exchanges the contents of this BitFieldVector container with those of other.
  /// This version does not invoke any move, copy, or swap operations on
  /// the individual elements.
  ///
  /// Iterators and references will remain valid, with the exception to the
  /// end iterators.
  ///
  /// @param other    The other vector to swap elements.
  ///
  void swap(BitFieldVector& other)                 { m_data.swap(other.m_data); }

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
  void swap(value_type& other)                    { m_data.swap(other);   }

private:
  //  Data Members *************************************************************
  vector_type                 m_data;   ///< The data buffers that hold the 
                                        ///  raw values for the collection of
                                        ///  bit-fields.
};


} // namespace Hg


#endif
