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
#include <meta/dynamic.h>
#include <meta/meta_foreach.h>
#include <meta/type_at.h>

namespace Hg
{

namespace detail
{

//  Forward Declarations *******************************************************
//  ****************************************************************************
template< typename MessageT,
          bool     IsDynamicT
        >
struct DynamicSizeWorker;

//  ****************************************************************************
template< typename MessageT,
          typename ByteOrderT,
          typename StorageT>
class Message;

//  ****************************************************************************
/// Reports the total size of the dynamic buffers required for this message.
///    
//template< typename MessageT,
//          typename ByteOrderT,
//          typename StorageT
//        >
//size_t dynamic_size(const Message<MessageT, ByteOrderT, StorageT>& msg)
//{
//  return DynamicSizeWorker<MessageT, has_dynamic<MessageT>::value>.size(msg);
//}

//  ****************************************************************************
/// Reports the total size of the dynamic buffers required for this message.
///    
template <typename T>
size_t dynamic_size(const std::vector<T>& field)
{
  return sizeof(T) * field.size();
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
template< typename MessageT >
struct DynamicSizeFunctor
{
  //  Typedefs *****************************************************************
  typedef MessageT                      message_type;
  typedef typename
    message_type::format_type           format_type;

  typedef typename
    dynamic_fields<format_type>::type   dynamic_field_indices;

  static const size_t k_base_offset =   message_type::k_base_offset;

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
  void operator()(const value_t&)
  {
    typedef typename
      Hg::detail::DeduceProxyType < IdxT,
                                    format_type,
                                    k_base_offset>::type      proxy_type;
    typedef typename
      proxy_type::value_type                                  value_type;
                                      
    message_type &msg = const_cast<message_type&>(message);
    value_type &value  = msg.template FieldAt<IdxT>().get();
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
template< typename MessageT,
          bool     IsDynamicT
        >
struct DynamicSizeWorker
{
  static
    size_t size(const MessageT& msg)
  {
    typedef MessageT                      message_type;
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
template< typename MessageT >
struct DynamicSizeWorker<MessageT, false>
{
  static
    size_t size(const MessageT& msg)
  {
    return 0;  
  }
};


} // namespace detail

} // namespace Hg

#endif
