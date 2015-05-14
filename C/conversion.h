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
#include <Hg.h>
#include <Hg/static_storage_policy.h>


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
    T::value_type value = src;
    ::memcpy(&dest, &value, sizeof(T::value_type));
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


//  ****************************************************************************
//  ****************************************************************************
namespace detail
{

//  ****************************************************************************
//
//
template< typename HgT, 
          typename CT
        >
int ConvertToNetworkOrder(Hg_msg_t *p_msg)
{
  Hg::basic_msg<HgT>::host_t hg_msg;
  C::struct_to_msg(*(CT*)p_msg, hg_msg.values());

  Hg::basic_msg<HgT>::net_t hg_net_msg = Hg::to_network(hg_msg);

  C::msg_to_struct(hg_net_msg.values(), *(CT*)p_msg);

  return 0;
}

//  ****************************************************************************
//
//
template< typename HgT, 
          typename CT
        >
int ConvertToBigEndian(Hg_msg_t *p_msg)
{
  Hg::basic_msg<HgT>::little_t hg_msg;
  C::struct_to_msg(*(CT*)p_msg, hg_msg.values());

  Hg::basic_msg<HgT>::big_t hg_big_msg = Hg::to_big_endian(hg_msg);

  C::msg_to_struct(hg_big_msg.values(), *(CT*)p_msg);

  return 0;
}

//  ****************************************************************************
//
//
template< typename HgT, 
          typename CT
        >
size_t PackMessage( const Hg_msg_t  *p_msg,   
                    unsigned char   *p_buffer, 
                    size_t          len)
{
  Hg::basic_msg<HgT, Hg::BufferedStaticStoragePolicy> hg_msg;
  C::struct_to_msg(*(CT*)p_msg, hg_msg.values());

  hg_msg.data((unsigned char*)p_buffer, len);

  return 0;
}

//  ****************************************************************************
//
//
template< typename HgT, 
          typename CT
        >
size_t UnpackMessage( Hg_msg_t            *p_msg,   
                      const unsigned char *p_buffer, 
                      size_t              len)
{
  Hg::basic_msg<HgT> hg_msg((unsigned char*)p_buffer, len);

  C::msg_to_struct(hg_msg.values(), *(CT*)p_msg);
  return 0;
}

} // namespace detail


} // namespace C


#endif
