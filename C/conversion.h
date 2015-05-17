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
//  Frees memory for each datum in the most appropriate way.
//  The default case does not require any special processing.
//
template< typename T, 
          bool IsDynamicT
        >
struct DestroyDatum
{
  static
  void destroy(const T datum) 
  { }
};

//  ****************************************************************************
//  // Destroy the sub-buffer maintained by this element.
//
template< typename T>
struct DestroyDatum<T,true>
{
  static
  void destroy(const T datum) 
  { 
    Hg_destroy((Hg_msg_t*)datum);
  }
};

//  ****************************************************************************
//  Frees the memory allocated to this datum in the most appropriate way.
//  The pointer HgT is for type deduction.
//  When called, it should be a NULL pointer cast to type HgT.
//
template< typename T, typename HgT>
void destroy_datum(T datum, const HgT*)
{
  DestroyDatum<T, Hg::vector_value<HgT>::value>::destroy(datum);
}


//  ****************************************************************************
//  Calculates the size appropriately for the type of field supplied.
//  The default case simply returns the value from sizeof.
//
template< typename T, 
          bool IsDynamicT
        >
struct GetDatumSize
{
  static
  size_t get_data_size(const T) 
  { 
    return sizeof(T);
  }
};

//  ****************************************************************************
//  Calculate the size of the dynamic buffer.
//
template< typename T>
struct GetDatumSize<T,true>
{
  static
  size_t get_data_size(const T datum) 
  { 
    return Hg_size((Hg_msg_t*)datum);
  }
};


//  ****************************************************************************
//  Returns the calculated size for this data element.
//  This is primarily required for dynamiclly sized elements.
//
//  The pointer HgT is for type deduction.
//  When called, it should be a NULL pointer cast to type HgT.
//
template< typename T, typename HgT>
size_t get_datum_size(const T datum, const HgT*)
{
  return GetDatumSize<T, Hg::vector_value<HgT>::value>::get_data_size(datum);
}


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
  template< bool IsArrayT>
  struct copy_t
  {
    static 
    void copy(T &src, U &dest)
    {
      for (size_t index = 0; index < dest.size(); ++index)
      {
        struct_to_msg(src[index], dest[index]);
      }
    }
  };

  template< >
  struct copy_t<false>
  {
    static 
    void copy(T &src, U &dest)
    {
      memcpy(&dest, &src, sizeof(dest));
    }
  };
          
  static 
  U& assign(T &src, U &dest)
  {
    typedef typename 
      U::value_type::value_type                   value_type;
    typedef typename 
      copy_t<Hg::array_value<value_type>::value>  copy_type;
    
    copy_type::copy(src, dest);
    return dest;
  }
};

//  ****************************************************************************
/// Specialization for vector value types (variable-length arrays).
///
template< typename T, typename U >
struct translate_from_C<T,U,Hg::vector_trait>
{
  static 
  U& assign(T &src, U &dest)
  {
    typedef U::value_type  value_type;

    // Get the size of the vector from the C-structure
    // and allocate space in the Hg message.
    //template< typename T, typename HgT>
    //get_datum_size<T, (const T datum, const HgT*)

    size_t len = get_datum_size<T>(src, (U*)0);
    dest.resize(len);

    if (0 == len)
      return dest;

    if ( Hg::array_value<value_type::value_type>::value
      || Hg::nested_value<value_type::value_type>::value)
    {
      size_t count = len / sizeof(value_type);
      for (size_t index = 0; index < count; ++index)
      {
        struct_to_msg(src[index], dest[index]);
      }
    }
    else
    {
      memcpy(&dest, &src, len);
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
    if ( Hg::array_value<value_type::value_type>::value
      || Hg::nested_value<value_type::value_type>::value)
    {
      for (size_t index = 0; index < src.size(); ++index)
      {
//        msg_to_struct(src[index], dest[index]);
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
/// Specialization for vector value types (variable-length arrays).
///
template< typename T, typename U >
struct translate_to_C<T,U,Hg::vector_trait>
{
  static 
  U& assign(T &src, U &dest)
  {
    typedef T::value_type  value_type;

    // Allocate a buffer in the C-structure 
    // to accept the data stored in the Hg message.
    size_t len = src.size() * sizeof(value_type);
    if (0 == len)
    {
      dest = 0;
      return dest;
    }

    dest = *(U*)C::carbon_alloc(len, C::k_carbon_field_id, 0);

    if ( Hg::array_value<value_type::value_type>::value
      || Hg::nested_value<value_type::value_type>::value)
    {
      for (size_t index = 0; index < src.size(); ++index)
      {
        msg_to_struct(src[index], dest[index]);
      }
    }
    else
    {
      memcpy(&dest, &src, len);
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
//  Converts a message from its current byte-order into the opposite order.
//
template< typename HgT, 
          typename CT
        >
int ConvertByteOrder(Hg_msg_t *p_msg)
{
  Hg::basic_msg<HgT>::little_t hg_msg;
  C::struct_to_msg(*(CT*)p_msg, hg_msg.values());

  Hg::basic_msg<HgT>::big_t hg_big_msg = Hg::to_big_endian(hg_msg);

  C::msg_to_struct(hg_big_msg.values(), *(CT*)p_msg);

  return 0;
}

//  ****************************************************************************
//  Packs an existing C-struct message into a data buffer.
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
//  Unpacks a data buffer into a C-struct.
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
