/// @file detail/deduce_proxy_type.h
/// 
/// The declaration and definition of DeduceProxyType.
///           
/// A template meta-function that selects the appropriate type of Data Proxy
/// to declare for a specified type T. The data proxy is an important layer
/// to homogenize access to all of the different types of values supported
/// by Hg.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef DEDUCE_PROXY_TYPE_H_INCLUDED
#define DEDUCE_PROXY_TYPE_H_INCLUDED
//  Includes ******************************************************************
#include <Hg/deduce_type_trait.h>
#include <Hg/proxy/data_proxy.h>
#include <Hg/proxy/bitlist_field_proxy.h>
#include <Hg/proxy/vector_proxy.h>
#include <Hg/proxy/array_proxy.h>
#include <Hg/proxy/opaque_proxy.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A convenience meta-function to define the correct type of DataProxy holder.
/// The constructed type can be accessed through the public alias *type*. 
/// 
/// @tparam IdxT
/// @tparam FormatT
/// 
template< size_t    IdxT,
          typename  FormatT
        >
struct DeduceProxyType
{
  //  **************************************************************************
  //  Deduce the traits from the value_type in order to select the most 
  //  appropriate Proxy handler for value management.
  //
  using selected_type = typename Deducetype_atTrait < IdxT, FormatT>::type;

  //  **************************************************************************
  //  The selected DataProxy type for the specified input type.
  using type          = DataProxy < selected_type, IdxT, FormatT>;
};

} // namespace detail

} // namespace Hg

#endif
