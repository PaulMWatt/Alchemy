/// @file detail/opaque_proxy.h
/// 
/// The declaration and definition of the Opaque DataProxy.
///           
/// A parameterized type that provides an opaque buffer of bytes.
/// The user can then associate an unbuffered message with the type to 
/// directly manipulate the data.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef OPAQUE_PROXY_H_INCLUDED
#define OPAQUE_PROXY_H_INCLUDED
//  Includes ******************************************************************

#include <Pb/meta_fwd.h>
#include <Pb/type_list.h>
#include <Pb/type_at.h>
#include <Hg/datum/datum.h>
#include <Hg/storage_policy.h>

#include <vector>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A template to provide access to sequences of data fields.
///
/// This version derives from the Vector Proxy.
/// Additional functionality is defined for obtaining views of the data buffers.
/// 
/// @paramt IdxT
/// @paramt FormatType
/// 
template< size_t    IdxT,
          typename  FormatT
        >
struct DataProxy <opaque_vector_trait, IdxT, FormatT>
  : public DataProxy <vector_trait, IdxT, FormatT>
{
  //  Typedefs *****************************************************************
  typedef DataProxy < opaque_trait, 
                      IdxT, 
                      FormatT
                    >                   this_type;
  typedef DataProxy < vector_trait, 
                      IdxT, 
                      FormatT
                    >                   base_type;

  typedef FormatT                       format_type;

  typedef typename
    base_type::datum_type               datum_type;

  typedef typename
    base_type::field_type               field_type;
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
    base_type::value_type               value_type;

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


  //  Forward Declarations *****************************************************
  //  Bring all of these type into this namespace from the base template.
  //
  using base_type::clear;
  using base_type::empty;
  using base_type::reserve;
  using base_type::capacity;
  using base_type::size;
  using base_type::resize;
  using base_type::set;
  using base_type::assign;
  using base_type::at;
  using base_type::front;
  using base_type::back;
  using base_type::begin;
  using base_type::end;
  using base_type::cend;
  using base_type::rbegin;
  using base_type::crbegin;
  using base_type::rend;
  using base_type::crend;
  using base_type::erase;
  using base_type::push_back;
  using base_type::pop_back;
  using base_type::swap;

  //  **************************************************************************
  /// 
  /// 
  DataProxy()
  { }

};



////  ****************************************************************************
///// A template to provide access to sequences of data fields (fixed-size).
/////
///// This version derives from the Array Proxy.
///// Additional functionality is defined for obtaining views of the data buffers.
///// 
///// @paramt IdxT
///// @paramt FormatType
///// 
//template< size_t    IdxT,
//          typename  FormatT
//        >
//struct DataProxy <opaque_trait, IdxT, FormatT>
//  : public DataProxy <array_trait, IdxT, FormatT>
//{
//  //  Typedefs *****************************************************************
//  typedef DataProxy < opaque_trait, 
//                      IdxT, 
//                      FormatT
//                    >                   this_type;
//  typedef DataProxy < array_trait, 
//                      IdxT, 
//                      FormatT
//                    >                   base_type;
//
//  typedef FormatT                       format_type;
//
//  typedef typename
//    base_type::datum_type               datum_type;
//
//  typedef typename
//    base_type::field_type               field_type;
//                                        ///< Type mapping for the message format
//                                        ///  type to the actual value_type.
//  typedef typename
//    field_type::index_type              index_type;
//                                        ///< The raw type extracted at the current
//                                        ///  index defined in the parent TypeList.
//  typedef typename
//    index_type::value_type              data_type;
//                                        ///< The value type of the element extracted 
//                                        ///  at the current index defined in the 
//                                        ///  parent TypeList.
//
//  //  Typedefs *****************************************************************
//  typedef typename
//    base_type::value_type               value_type;
//
//  typedef typename                      ///  Reference to an element in the vector.
//    value_type::reference               reference;
//                                                                                
//  typedef typename                      ///  Const Reference to an element in the vector.
//    value_type::const_reference         const_reference;
//
//  typedef typename                      ///  An iterator to a value_type index.
//    value_type::iterator                iterator;
//
//  typedef typename                      ///  A const iterator to a value_type index.
//    value_type::const_iterator          const_iterator;
//
//  typedef typename                      ///  A reverse iterator to a value_type index.
//    value_type::reverse_iterator        reverse_iterator;
//
//  typedef typename                      ///  A const reverse iterator to a value_type index.
//    value_type::const_reverse_iterator  const_reverse_iterator;
//
//  //  Forward Declarations *****************************************************
//  //  Bring all of these type into this namespace from the base template.
//  //
//  using base_type::clear;
//  using base_type::empty;
//  using base_type::reserve;
//  using base_type::capacity;
//  using base_type::size;
//  using base_type::set;
//  using base_type::assign;
//  using base_type::at;
//  using base_type::front;
//  using base_type::back;
//  using base_type::begin;
//  using base_type::end;
//  using base_type::cend;
//  using base_type::rbegin;
//  using base_type::crbegin;
//  using base_type::rend;
//  using base_type::crend;
//  using base_type::erase;
//  using base_type::push_back;
//  using base_type::pop_back;
//  using base_type::swap;
//
//  //  **************************************************************************
//  /// 
//  /// 
//  DataProxy()
//  { }
//
//};

} // namespace detail
} // namespace Hg

#endif
