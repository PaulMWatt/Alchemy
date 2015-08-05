/// @file Pb/optional.h
/// 
/// Utilty class for representing optional data fields in protocols.
/// 
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef OPTIONAL_H_INCLUDED
#define OPTIONAL_H_INCLUDED
//  includes *******************************************************************
#include <array>
#include <vector>

namespace Hg
{

//  ****************************************************************************
/// Optional field base functionality.
///
class base_optional
{
public:
  //  **************************************************************************
  /// Default Constructor
  ///
  base_optional()
    : m_is_valid(false)
  { }

  //  **************************************************************************
  /// Indicates when this field is valid
  ///
  /// @return  false: When this field does not contain a valid value.
  ///           true: The value in this field is valid.
  ///
  bool is_valid() const
  {
    return m_is_valid;
  }

  //  **************************************************************************
  /// Flags the state of this object as valid.
  ///
  void valid()
  {
    m_is_valid = true;
  }

  //  **************************************************************************
  /// Clears the valid state of this object.
  ///
  void reset()
  {
    m_is_valid = false;
  }

private:
  bool  m_is_valid;
};


//  ****************************************************************************
/// Data type to represent optional data fields in message structures.
///
/// Message structures often contain optional data fields that are not always
/// present. This object contains functions to report and manage the valid
/// state of any type of value.
///
template< typename T >
class optional
  : public base_optional
{
public:
  /// The type of the optional value managed by this object. 
  using optional_type = T;

  //  **************************************************************************
  /// Default Constructor
  ///
  optional()
    : base_optional()
  { }

  //  **************************************************************************
  /// Value Constructor
  ///
  optional(T value)
    : base_optional()
    , m_value(value)
  { 
    valid();
  }

  //  **************************************************************************
  /// Value conversion operator to type T
  ///
  operator T() const
  {
    return m_value;
  }

private:
  T     m_value;
};


//  ****************************************************************************
/// Data type to represent an optional array of data fields in message structures.
///
/// This is a specialization of the optional<T> class for std::array<T> data types.
///
template< typename T, 
          size_t   N
        >
class optional <std::array<T, N>>
  : public base_optional
{
public:
  /// The type of the optional value managed by this object. 
  using optional_type   = std::array<T, N>;

  using value_type      = optional_type;

  ///  Reference to an element in the array.                                        
  using reference       = typename value_type::reference;                     
  
  ///  Const Reference to an element in the array.
  using const_reference = typename value_type::const_reference;

  ///  An iterator to a value_type index.
  using iterator        = typename value_type::iterator;

  ///  A const iterator to a value_type index.
  using const_iterator  = typename value_type::const_iterator;

  ///  A reverse iterator to a value_type index.
  using reverse_iterator= typename value_type::reverse_iterator;

  ///  A const reverse iterator to a value_type index.
  using const_reverse_iterator =
    typename value_type::const_reverse_iterator;

  //  **************************************************************************
  /// Default Constructor
  ///
  optional()
    : base_optional()
  { }

  //  **************************************************************************
  /// Value Constructor
  ///
  optional(value_type value)
    : base_optional()
    , m_value(value)
  { 
    valid();
  }

  //  **************************************************************************
  /// Value conversion operator to the value_type
  ///
  operator value_type() const
  {
    return m_value;
  }

  //  **************************************************************************
  /// Returns the number of valid objects managed by this array structure.
  /// 
  size_t size() const                             { return m_value.size(); }

  //  **************************************************************************
  /// Returns the number of bytes that are required to hold this array in a buffer.
  /// 
  size_t size_of() const                          { return sizeof(m_value); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference at(size_t idx) const            { return m_value.at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference at(size_t idx)                        { return m_value.at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference operator[](size_t idx) const    { return m_value[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference operator[](size_t idx)                { return m_value[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference front() const                   { return m_value.front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference front()                               { return m_value.front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  const_reference back() const                    { return m_value.back(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the array data..
  /// 
  reference back()                                { return m_value.back(); }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the array.
  /// 
  iterator begin()                                { return m_value.begin();  }
  const_iterator begin()  const                   { return m_value.begin();  }
  const_iterator cbegin() const                   { return m_value.cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the array.
  /// 
  iterator end()                                  { return m_value.end();    }
  const_iterator end()  const                     { return m_value.end();    }
  const_iterator cend() const                     { return m_value.cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the array moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return m_value.rbegin(); }
  const_reverse_iterator rbegin()  const          { return m_value.rbegin(); }
  const_reverse_iterator crbegin() const          { return m_value.crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the array,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return m_value.rend();   }
  const_reverse_iterator rend()  const            { return m_value.rend();   }
  const_reverse_iterator crend() const            { return m_value.crend();  } 

private:
  value_type     m_value;
};


//  ****************************************************************************
/// Data type to represent an optional array of data fields in message structures.
///
/// This is a specialization of the optional<T> class for std::vector<T> data types.
///
template< typename T, 
          typename A
        >
class optional <std::vector<T, A>>
  : public base_optional
{
public:
  /// The type of the optional value managed by this object. 
  using optional_type   = std::vector<T, A>;

  using data_type       = T;
  using value_type      = optional_type;

  ///  Reference to an element in the array.                                        
  using reference       = typename value_type::reference;                     
  
  ///  Const Reference to an element in the array.
  using const_reference = typename value_type::const_reference;

  ///  An iterator to a value_type index.
  using iterator        = typename value_type::iterator;

  ///  A const iterator to a value_type index.
  using const_iterator  = typename value_type::const_iterator;

  ///  A reverse iterator to a value_type index.
  using reverse_iterator= typename value_type::reverse_iterator;

  ///  A const reverse iterator to a value_type index.
  using const_reverse_iterator =
    typename value_type::const_reverse_iterator;

  //  **************************************************************************
  /// Default Constructor
  ///
  optional()
    : base_optional()
  { }

  //  **************************************************************************
  /// Value Constructor
  ///
  optional(value_type value)
    : base_optional()
    , m_value(value)
  { 
    valid();
  }

  //  **************************************************************************
  /// Value conversion operator to the value_type
  ///
  operator value_type() const
  {
    return m_value;
  }

  //  **************************************************************************
  /// Releases all allocated memory dedicated for storing entry data.
  /// 
  void clear()                                    { return m_value.clear(); }

  //  **************************************************************************
  /// Indicates if the vector does not have any space allocated for data.
  /// 
  bool empty()                                    { return m_value.empty(); }

  //  **************************************************************************
  /// Insures that space is reserved to hold at least new_cap elements.
  /// 
  void reserve(size_t new_cap)                    { m_value.reserve(new_cap); }

  //  **************************************************************************
  /// Returns the number of elements that this vector can hold based on the 
  /// current allocated space.
  /// 
  size_t capacity() const                         { return m_value.capacity(); }

  //  **************************************************************************
  /// Returns the number of valid objects managed by this vector structure.
  /// 
  size_t size() const                             { return m_value.size(); }

  //  **************************************************************************
  /// Changes the number of elements stored.
  ///
  /// @param n      The number of elements the container should now hold.
  /// 
  void resize(size_t count)                       { resize(count, data_type()); }

  //  **************************************************************************
  /// Changes the number of elements stored.
  ///
  /// @param n      The number of elements the container should now hold.
  /// @param value  Default value to initialize elements if the resize
  ///               causes new elements to be added to the container.
  /// 
  void resize(size_t    count, 
              data_type value)                    { m_value.resize(count, value); }

  //  **************************************************************************
  /// Replaces the contents of the container.
  /// 
  void assign(size_t count, const data_type& value)   { return m_value.assign(count, value); }

  //  **************************************************************************
  /// Replaces the contents of the container.
  /// 
  template< typename InputIt >
  void assign(InputIt first, InputIt last)        { return m_value.assign(first, last); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference at(size_t idx) const            { return m_value.at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference at(size_t idx)                        { return m_value.at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference operator[](size_t idx) const    { return m_value[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference operator[](size_t idx)                { return m_value[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference front() const                   { return m_value.front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference front()                               { return m_value.front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference back() const                    { return m_value.back(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference back()                                { return m_value.back(); }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the vector.
  /// 
  iterator begin()                                { return m_value.begin();  }
  const_iterator begin()  const                   { return m_value.begin();  }
  const_iterator cbegin() const                   { return m_value.cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the vector.
  /// 
  iterator end()                                  { return m_value.end();    }
  const_iterator end()  const                     { return m_value.end();    }
  const_iterator cend() const                     { return m_value.cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the vector moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return m_value.rbegin(); }
  const_reverse_iterator rbegin()  const          { return m_value.rbegin(); }
  const_reverse_iterator crbegin() const          { return m_value.crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the vector,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return m_value.rend();   }
  const_reverse_iterator rend()  const            { return m_value.rend();   }
  const_reverse_iterator crend() const            { return m_value.crend();  } 

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
  iterator erase(iterator pos)                    { return m_value.erase(pos);   }

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
  iterator erase(iterator first, iterator last)   { return m_value.erase(first, last);}

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
  void push_back(const_reference value)           { m_value.push_back(value);   }

  //  **************************************************************************
  /// Removes the last element in the container.
  ///
  /// @note: Iterators that point to the last element and end will be 
  ///        invalidated after this call.
  ///
  void pop_back()                                 { if (!m_value.empty()) {
                                                      m_value.pop_back(); 
                                                    }
                                                  }

  //  **************************************************************************
  /// Exchanges the contents of this container with those of other.
  /// This version does not invoke any move, copy, or swap operations on
  /// the individual elements.
  ///
  /// Iterators and references will remain valid, with the exception to the
  /// end iterators.
  ///
  /// @param other    The other vector to swap elements.
  ///
  void swap(optional<std::vector<T,A>>& other)    { m_value.swap(other.m_value); }

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
  void swap(value_type& other)                    { m_value.swap(other);   }


private:
  value_type     m_value;
};


//  **************************************************************************
/// Less than comparison operation for the optional data type.
///
/// @param lhs    The left-hand side of the comparison.
/// @param rhs    The right-hand side of the comparison.
///
/// @return       If both values are valid, a comparison on their internal
///               value will be returned.
///               If either of the values are invalid, false will be returned.
///
template< typename T >
bool operator< (const optional<T>& lhs, const optional<T>& rhs)
{
  if (lhs.is_valid()
    && rhs.is_valid())
  {
    return static_cast<T>(lhs) < static_cast<T>(rhs);
  }

  return false;
}

//  **************************************************************************
/// Less than comparison operation for the optional data type with its 
/// internal value type.
///
/// @param lhs    The left-hand side of the comparison, an optional type.
/// @param rhs    The right-hand side of the comparison, the internal value type.
///
/// @return       If the lhs (option) type is valid, a comparison with its
///               internal value will be returned.
///               If lhs is invalid, false will be returned.
///
template< typename T >
bool operator< (const optional<T>& lhs, const T& rhs)
{
  return  lhs.is_valid()
          ? static_cast<T>(lhs) < rhs
          : false;
}

//  **************************************************************************
/// Equality comparison operation for the optional data type.
///
/// @param lhs    The left-hand side of the comparison.
/// @param rhs    The right-hand side of the comparison.
///
/// @return       If both values are valid, a comparison on their internal
///               value will be returned.
///               If either of the values are invalid, false will be returned.
///
template< typename T >
bool operator== (const optional<T>& lhs, const optional<T>& rhs)
{
  if ( lhs.is_valid()
    && rhs.is_valid())
  {
    return static_cast<T>(lhs) == static_cast<T>(rhs);
  }

  return false;
}

//  **************************************************************************
/// Equality comparison operation for the optional data type with its
/// internal value type.
///
/// @param lhs    The left-hand side of the comparison, an optional type.
/// @param rhs    The right-hand side of the comparison, the internal value type.
///
/// @return       If the lhs (option) type is valid, a comparison with its
///               internal value will be returned.
///               If lhs is invalid, false will be returned.
///
template< typename T >
bool operator== (const optional<T>& lhs, const T& rhs)
{
  return  lhs.is_valid()
          ? static_cast<T>(lhs) == rhs
          : false;
}

} // namespace Hg

#endif
