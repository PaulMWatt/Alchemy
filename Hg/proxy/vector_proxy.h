/// @file detail/vector_proxy.h
/// 
/// The declaration and definition of the Vector DataProxy.
///           
/// A parameterized type that abstracts the details of accessing Datum entries
/// with variable length fields.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef VECTOR_PROXY_H_INCLUDED
#define VECTOR_PROXY_H_INCLUDED
//  Includes ******************************************************************

#include <Pb/meta_fwd.h>
#include <Pb/type_list.h>
#include <Pb/type_at.h>
#include <Hg/datum/datum.h>
#include <Pb/bit_field/bit_field_vector.h>
#include <Hg/storage_policy.h>

#include <vector>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A template to provide access to sequences of data fields.
/// 
/// @paramt IdxT
/// @paramt FormatType
/// 
template< size_t    IdxT,
          typename  FormatT
        >
struct DataProxy <vector_trait, IdxT, FormatT>
  : public Hg::Datum<IdxT, FormatT>
{
  //  Typedefs *****************************************************************
  typedef FormatT                       format_type;

    typedef  
      Hg::Datum < IdxT,
                  format_type
                >                       datum_type;

  typedef typename
    detail::DefineFieldType < IdxT, 
                              format_type
                            >::type     field_type;
                                        ///< Type mapping for the message format
                                        ///  type to the actual value_type.

  typedef typename
    field_type::index_type              index_type;
                                        ///< The raw type extracted at the current
                                        ///  index defined in the parent TypeList.

  typedef typename
    index_type::value_type              data_type;
                                        ///< The value type of the element extracted 
                                        ///  at the current index defined in the 
                                        ///  parent TypeList.

  //  Typedefs *****************************************************************
  typedef typename 
  std::conditional< std::is_base_of<vector_trait, index_type>::value,
                    index_type,                  
                    typename field_type::value_type                  
                  >::type

                                        value_type;

//std::vector<data_type, typename index_type::allocator_type>
  //typedef typename
  //  field_type::value_type              value_type;
                                        ///< The vector type defined in the 
                                        ///  message format. This type definition
                                        ///  is possibly altered to appropriately
                                        ///  manage the type, such as nested types.
  //typedef typename
  //  value_type::value_type              data_type;
  //                                      ///< The data type managed by this Vector.
  //                                      ///  This is the type of data that will 
  //                                      ///  be written to the attached buffer.
  
  typedef typename                      ///  Reference to an element in the vector.
    value_type::reference               reference;
                                                                                
  typedef typename                      ///  Const Reference to an element in the vector.
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
  /// Releases all allocated memory dedicated for storing entry data.
  /// 
  void clear()                                    { return this->get().clear(); }

  //  **************************************************************************
  /// Indicates if the vector does not have any space allocated for data.
  /// 
  bool empty()                                    { return this->get().empty(); }

  //  **************************************************************************
  /// Insures that space is reserved to hold at least new_cap elements.
  /// 
  void reserve(size_t new_cap)                    { this->get().reserve(new_cap); }

  //  **************************************************************************
  /// Returns the number of elements that this vector can hold based on the 
  /// current allocated space.
  /// 
  size_t capacity() const                         { return this->get().capacity(); }

  //  **************************************************************************
  /// Returns the number of valid objects managed by this vector structure.
  /// 
  size_t size() const                             { return this->get().size(); }

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
              data_type value)                    { this->get().resize(count, value); }

  //  **************************************************************************
  /// Updates the value of this VectorProxy with a std::vector type. 
  /// 
  /// @param value  The vector which will initialize this object.
  /// 
  void set(const value_type& value)
  {
    resize(value.size());
    std::copy( value.begin(), 
               value.end(), 
               begin());
  }

  //  **************************************************************************
  /// Updates the value of this Vector with a native array type. 
  /// 
  /// @param value  The array which will initialize this object.
  /// 
  template <size_t ExtentT>
  void set(const data_type (&value)[ExtentT])
  {
    if (!value)
    {
      // TODO: Return and add exception handling. 
      return;
    }

    std::copy( &value[0], 
              (&value[0]) + ExtentT, 
                std::back_inserter(this->get()));
  }

  //  **************************************************************************
  /// Replaces the contents of the container.
  /// 
  void assign(size_t count, const data_type& value)   { return this->get().assign(count, value); }

  //  **************************************************************************
  /// Replaces the contents of the container.
  /// 
  template< typename InputIt >
  void assign(InputIt first, InputIt last)        { return this->get().assign(first, last); }

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
  /// Allows the entire vector to be extracted and assigned as a value to
  /// the host value type.
  /// 
  operator value_type() const
  {
    return static_cast<const datum_type*>(this)->operator value_type();
  }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference at(size_t idx) const            { return this->get().at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference at(size_t idx)                        { return this->get().at(idx); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference operator[](size_t idx) const    { return this->get()[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference operator[](size_t idx)                { return this->get()[idx]; }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference front() const                   { return this->get().front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference front()                               { return this->get().front(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  const_reference back() const                    { return this->get().back(); }

  //  **************************************************************************
  /// Accesses the value at the specified index in the vector data..
  /// 
  reference back()                                { return this->get().back(); }

  //  Iterator Functions *******************************************************
  //  **************************************************************************
  /// Returns an iterator to the first item in the vector.
  /// 
  iterator begin()                                { return this->get().begin();  }
  const_iterator begin()  const                   { return this->get().begin();  }
  const_iterator cbegin() const                   { return this->get().cbegin(); }

  //  **************************************************************************
  /// Returns an iterator to the item one passed the end of the vector.
  /// 
  iterator end()                                  { return this->get().end();    }
  const_iterator end()  const                     { return this->get().end();    }
  const_iterator cend() const                     { return this->get().cend();   }

  //  **************************************************************************
  /// Returns an iterator to the last item of the vector moving in reverse.
  /// 
  reverse_iterator rbegin()                       { return this->get().rbegin(); }
  const_reverse_iterator rbegin()  const          { return this->get().rbegin(); }
  const_reverse_iterator crbegin() const          { return this->get().crbegin();}

  //  **************************************************************************
  /// Returns an iterator to the item one passed the beginning of the vector,
  /// moving in reverse.
  /// 
  reverse_iterator rend()                         { return this->get().rend();   }
  const_reverse_iterator rend()  const            { return this->get().rend();   }
  const_reverse_iterator crend() const            { return this->get().crend();  } 

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
  iterator erase(iterator pos)                    { return this->get().erase(pos);   }

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
  iterator erase(iterator first, iterator last)   { return this->get().erase(first, last);}

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
  void push_back(const_reference value)           { this->get().push_back(value);   }

  //  **************************************************************************
  /// Removes the last element in the container.
  ///
  /// @note: Iterators that point to the last element and end will be 
  ///        invalidated after this call.
  ///
  void pop_back()                                 { if (!this->get().empty()) {
                                                      this->get().pop_back(); 
                                                    }
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
  void swap(value_type& other)                    { this->get().swap(other);   }

};

} // namespace detail
} // namespace Hg

#endif
