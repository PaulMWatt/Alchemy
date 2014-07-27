/// @file detail/select_data_proxy.h
/// 
/// The declaration and definition of SelectDataProxy.
///           
/// A template meta-function that selects the appropriate type of Data Proxy
/// to declare for a specified type T. The data proxy is an important layer
/// to homogenize access to all of the different types of values supported
/// by Hg.
///             
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef SELECT_PROXY_TYPE_H_INCLUDED
#define SELECT_PROXY_TYPE_H_INCLUDED
//  Includes ******************************************************************
#include <detail/data_proxy.h>
#include <detail/bitlist_field_proxy.h>
#include <detail/dynamic_proxy.h>
#include <detail/array_proxy.h>

namespace Hg
{

namespace detail
{

//  ****************************************************************************
/// A convenience meta-function to define the correct type of DataProxy holder.
/// The constructed type can be accessed through the public typedef *type*. 
/// 
/// @paramt kt_idx
/// @paramt format_type
/// @paramt kt_offset
/// 
template< size_t    kt_idx,
          typename  format_t,
          size_t    kt_offset = 0
        >
struct SelectProxyType
{
private:
  //  **************************************************************************
  typedef typename
    TypeAt< kt_idx,
            format_t 
          >::type                       field_type;

  //  **************************************************************************
  //  Defines the multi-type trait to use if a multi_value is selected.  
  //
  typedef typename
    type_if < array_value<field_type>::value,
              array_trait,
              dynamic_trait
            >::type                     multi_type;

  //  **************************************************************************
  //  Defines the datum-type to select if this type is not a bitfield.  
  //
  typedef typename
    type_if < multi_value<field_type>::value, 
              multi_type,
              field_type
            >::type                     datum_type;

public:

  //  **************************************************************************
  /// There are four distinct types of proxy objects required:
  /// 1: bit field proxy       Bit-field types
  /// 2: fixed array proxy     Fixed sized nested homogenous types 
  /// 3: dynamic array proxy   Dynamically sized nested homogenous types
  /// 4: datum proxy:          Fundamental and nested heterogenous types.
  ///                          This is the catch all type for fields that do 
  ///                          not require any special processing.
  typedef typename 
    type_if < bitfield_value<field_type>::value,
              bitfield_trait,
              datum_type
            >::type                     selected_type;

  //  **************************************************************************
  /// The selected DataProxy type for the specified input type.
  typedef DataProxy < selected_type,
                      kt_idx,
                      format_t,
                      kt_offset
                    >                   type;
};


} // namespace detail

} // namespace Hg

#endif
