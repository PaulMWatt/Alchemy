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
#include <Hg/deduce_type_trait.h>

namespace C
{

//  ****************************************************************************
/// Facilitates translating values from C-structs to Hg::Message formats.
///
template< typename T, 
          typename U,
          typename trait_t = Hg::detail::DeduceTypeTrait<U::value_type>::type
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
struct translate_from_C<T,U,Hg::nested_trait>
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
/// Specialization for array value types.
///
template< typename T, typename U >
struct translate_from_C<T,U,Hg::array_trait>
{
  static 
  U& assign(T &src, U &dest)
  {
    typedef U::value_type  value_type;
    if (Hg::array_value<value_type::value_type>::value)
    {
      for (size_t index = 0; index < dest.size(); ++index)
      {
        struct_to_msg(src[index], dest[index]);
      }
    }
    else
    {
      memcpy(&dest, &src, sizeof(dest));
    }

    return dest;
  }
};

//  ****************************************************************************
/// Facilitates translating values from C-structs to Hg::Message formats.
///
template< typename T, 
          typename U,
          typename trait_t = Hg::detail::DeduceTypeTrait<T::value_type>::type
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
struct translate_to_C<T,U,Hg::nested_trait>
{
  typedef typename T::value_type    value_type;

  static 
  U& assign(T& src, U& dest)
  {
    value_type &value = src;
    msg_to_struct(value, dest);

    return dest;
  }
};


//  ****************************************************************************
/// Specialization for array value types.
///
template< typename T, typename U >
struct translate_to_C<T,U,Hg::array_trait>
{
  static 
  U& assign(T &src, U &dest)
  {
    typedef T::value_type  value_type;
    if (Hg::array_value<value_type::value_type>::value)
    {
      for (size_t index = 0; index < src.size(); ++index)
      {
        msg_to_struct(src[index], dest[index]);
      }
    }
    else
    {
      memcpy(&dest, &src, sizeof(dest));
    }

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
