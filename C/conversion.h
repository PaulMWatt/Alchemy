//  @file C/conversion.h
// 
//  Conversion templates from C-structs to Hg::Message.
// 
//  @note           This header file must not be included directly and the 
//                  MACROS defined in this file should not be accessed
//                  directly. Include and used the definitions from the file
//                  **<Carbon.h>** instead.
//           
//  The MIT License(MIT)
//  @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef CONVERSION_H_INCLUDED
#define CONVERSION_H_INCLUDED
//  Includes *******************************************************************
#include <Carbon.h>
#include <Hg/proxy/data_proxy.h>

namespace C
{

//  ****************************************************************************
/// Facilitates translating values from C-structs to Hg::Message formats.
///
template< typename T, 
          typename U,
          bool     IsNestedT = Hg::nested_value<U>::value
        >
struct translate_from_C
{
  static 
  U& assign(T& src, U& dest)
  {
    // This version of the template handles fundamental types and bit-fields.
    // The values will fit, they just need a lot of coercing.
    return dest = *(U::value_type*)&src;
  }
};


//  ****************************************************************************
/// Specialization for nested value types.
///
template< typename T, typename U >
struct translate_from_C<T,U,true>
{
  static 
  U& assign(T& src, U& dest)
  {
    U::value_type &value = dest;
    struct_to_msg(src, value);

    return dest;
  }
};


//  ****************************************************************************
/// Facilitates translating values from C-structs to Hg::Message formats.
///
template< typename T, 
          typename U,
          bool     IsNestedT = Hg::nested_value<T>::value
        >
struct translate_to_C
{
  static 
  U& assign(T& src, U& dest)
  {
    // This version of the template handles fundamental types and bit-fields.
    // The values will fit, they just need a lot of coercing.
    ::memcpy((T::value_type*)&dest, &src, sizeof(T::value_type));
    return dest;
  }
};


//  ****************************************************************************
/// Specialization for nested value types.
///
template< typename T, typename U >
struct translate_to_C<T,U,true>
{
  static 
  U& assign(T& src, U& dest)
  {
    T::value_type &value = src;
    msg_to_struct(value, dest);

    return dest;
  }
};


//  ****************************************************************************
//  Assigns the value of a C-struct to a Hg Message.
//
template< typename T, typename U>
U& struct_to_msg(T& src, U& dest)
{
  return translate_from_C<T,U>::assign(src, dest);
}

//  ****************************************************************************
//  Assigns the values of a Hg Message to a C-struct.
//
template< typename T, typename U>
U& msg_to_struct(T& src, U& dest)
{
  return translate_to_C<T,U>::assign(src, dest);
}

} // namespace C

#endif
