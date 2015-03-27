/// @file message_dynamic_detail.h
/// 
/// Internal details for the implementation of a dynamic message size query.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MESSAGE_DYNAMIC_DETAIL_H_INCLUDED
#define MESSAGE_DYNAMIC_DETAIL_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/dynamic.h>
#include <Pb/meta_foreach.h>
#include <Pb/type_at.h>
#include <Hg/deduce_type_trait.h>

namespace Hg
{

namespace detail
{

//  Forward Declarations *******************************************************
//  ****************************************************************************
template< typename MsgT,
          bool     IsDynamicT
        >
struct DynamicSizeWorker;

//  ****************************************************************************
//template< typename MsgT,
//          typename ByteOrderT,
//          typename StorageT>
//class basic_msg;

//  ****************************************************************************
/// Determines the number of bytes required to serialize a vector.
///    
template< class T,
          class A,
          class TypeTraitT
        >
struct SizeOfVector
{
  //  **************************************************************************
  template< class TypeT,
            class AllocT,
            template <class, class> class VectorT
          >
  size_t operator()(const VectorT<TypeT,AllocT>& field)
  {
    return field.size() * sizeof(TypeT);
  }
};

namespace nested
{

//  ****************************************************************************
//  Returns the size of a vector that contains a dynamically-sized nested type.
//
template< class T,
          class A,
          bool  HasDynamicT
        >
struct HelperSizeOfVector
{
  static size_t size(const std::vector<T,A>& field)
  {
    size_t total_size = 0;

    // This specialization represents vectors of nested traits. 
    // Therefore, T must have a defined format_type.
    const size_t k_fixed_size = Hg::SizeOf<typename T::format_type>::value;

    for (size_t index = 0; index < field.size(); ++index)
    {
      // Type T is the MsgT parameter of a message definition.
      // Therefore there will be a format_type that can be used
      // to tag dispatch this variation of the DynamicSizeWorker.
      //
      // Add both the fixed-size as well as the actual dynamic-size.
      total_size += k_fixed_size
                  + DynamicSizeWorker<T, true>().size(field[index]);
    }

    return total_size;  
  }
};

//  ****************************************************************************
//  Returns the size of a vector that contains a fixed-size nested type.
//
template< class T,
          class A
        >
struct HelperSizeOfVector <T, A, false>
{
  static size_t size(const std::vector<T,A>& field)
  {
    return  field.size() * Hg::SizeOf<typename T::format_type>::value;  
  }
};

} // namespace nested

//  ****************************************************************************
/// Determines the number of bytes required to serialize a vector.
/// This version handles a vector with sub-messages.
///    
template< class T,
          class A
        >
struct SizeOfVector<T,A,nested_trait>
{
  //  **************************************************************************
  size_t operator()(const std::vector<T,A>& field)
  {
    typedef typename 
      T::format_type          format_type;

    return nested::HelperSizeOfVector<T, A, has_dynamic<format_type>::value>::size(field);
  }
};

//  ****************************************************************************
/// Determines the number of bytes required to serialize a vector.
/// This version handles a vector with variable-length types.
///    
template< typename T,
          typename A
        >
struct SizeOfVector<T,A,vector_trait>
{
  //  **************************************************************************
  size_t operator()(const std::vector<T,A>& field)
  {
    size_t total_size = 0;

    SizeOfVector< typename T::value_type, 
                  typename T::allocator_type, 
                  typename DeduceTypeTrait<typename T::value_type>::type
                > Size;

    for (size_t index = 0; index < field.size(); ++index)
    {
      total_size += Size(field[index]);
    }

    return total_size;
  }
};

//  ****************************************************************************
/// Reports the total dynamic size of vector of bit-fields for this item.
///    
template< class T,
          class A
        >
size_t dynamic_size(const Hg::BitFieldVector<T,A>& field)
{
  return field.size() * Hg::SizeOf<T>::value;
}

//  ****************************************************************************
/// Reports the total size of the dynamic buffers required for this message.
///    
template< class T,
          class A
        >
size_t dynamic_size(const std::vector<T,A>& field)
{
  SizeOfVector<T,A, typename DeduceTypeTrait<T>::type> Size;
  return Size(field);
}

//  ****************************************************************************
/// Catch all implementation that returns 0 dynamic size.
///    
template <typename T>
size_t dynamic_size(const T& field)
{
  return 0;
}

//  ****************************************************************************
template< typename MsgT >
struct DynamicSizeFunctor
{
  //  Typedefs *****************************************************************
  typedef MsgT                      message_type;
  typedef typename
    message_type::format_type           format_type;

  typedef typename
    dynamic_fields<format_type>::type   dynamic_field_indices;

  //  Data Members *************************************************************
  const message_type &message;
  size_t              m_dynamic_size;

  //  **************************************************************************
  /// Value constructor that initializes the input message being queried.
  ///
  /// @param rhs      The Message object that contains the specified data.
  ///
  explicit
    DynamicSizeFunctor(const message_type& rhs)
    : message(rhs)
    , m_dynamic_size(0)
  { }

  //  **************************************************************************
  /// Parameterized function operator
  ///
  /// Reports the dynamic size of the requested field.
  /// 
  /// @paramt size_t          Parameterized value that specifies the index
  ///                         of the data field to be converted.
  /// @paramt value_type      [typename] A discriminator type for disambiguation.
  /// @param unnamed          An unused variable to disambiguate the appropriate
  ///                         specialization function for the compiler to select.
  /// 
  template< size_t   IdxT,
            typename value_t
          >
  void operator()(const value_t*)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    format_type>::type        proxy_type;
    typedef typename
      proxy_type::value_type                                  value_type;
                                      
    message_type &msg = const_cast<message_type&>(message);
    value_type &value = msg.template FieldAt<IdxT>().get();
    m_dynamic_size += dynamic_size(value);
  }

  //  **************************************************************************
  /// Returns the dynamic size calculated by the functor.
  ///
  size_t size()
  {
    return m_dynamic_size;
  }
};



//  ****************************************************************************
/// 
///
template< typename MsgT,
          bool     IsDynamicT
        >
struct DynamicSizeWorker
{
  static
    size_t size(const MsgT& msg)
  {
    typedef MsgT                      message_type;
    typedef typename  
      message_type::format_type           format_type;

    // Initialize a functor to query for the dynamic size of each field.
    detail::DynamicSizeFunctor< message_type > ftor(msg);
    Hg::ForEachType < 0,
                      Hg::length<format_type>::value - 1,
                      format_type
                    > (ftor);

    return ftor.size();   
  }
};

//  ****************************************************************************
/// Specialization that does not request dynamic size values for non-dynamic msgs.
///
template< typename MsgT >
struct DynamicSizeWorker<MsgT, false>
{
  static
    size_t size(const MsgT& msg)
  {
    return 0;  
  }
};


} // namespace detail

} // namespace Hg

#endif
