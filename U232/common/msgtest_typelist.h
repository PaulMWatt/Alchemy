//  @file msgtest_TypeList.h
//  
//  This is a helper file for tests with type definitions.
// 
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef MSGTEST_TypeList_H_INCLUDED
#define MSGTEST_TypeList_H_INCLUDED

//  Test Types *****************************************************************
// A current limitation for the Hg definitions are they must be defined in 
// the Hg namespace.
namespace Hg
{

HG_BEGIN_BIT_SET (uint32_t, mixed_bits)
  HG_BIT_FIELD   (0,   first,   5)
  HG_BIT_FIELD   (1,   second,  4)
  HG_BIT_FIELD   (2,   third,   3)
  HG_BIT_FIELD   (3,   fourth,  2)
  HG_BIT_FIELD   (4,   fifth,   1)
  HG_BIT_FIELD   (5,   sixth,   1)
  HG_BIT_FIELD   (6,   seventh, 1)
HG_END_BIT_SET

//  ****************************************************************************
//  A type array used to create the nested message field.
//
typedef TypeList
<
  uint8_t,      
  uint16_t,     
  mixed_bits,        // Extra bytes are required after this field to test offsets.
  uint32_t,
  int16_t
> nested_format_t;

//HG_BEGIN_FORMAT(nested_format_t)
//  HG_DATUM (uint8_t, zero)
//  HG_DATUM (uint16_t, one)
//  HG_DATUM (mixed_bits, two)
//  HG_DATUM (uint32_t, three)
//  HG_DATUM (int16_t, four)
//HG_END_FORMAT(nested_format_t)
typedef Hg::make_Hg_type_list<nested_format_t>::type nested_format_t_Hg; 
struct nested_format_t_HgFormat 
: nested_trait 
{ 
typedef nested_format_t_Hg format_type; 
enum { k_size = SizeOf<format_type>::value }; 
enum { k_length = length<format_type>::value }; 
enum { k_base_offset = 0 }; 

template< size_t IDX> Datum<IDX, format_type, k_base_offset>& FieldAt() 
{ 
  typedef Datum < IDX, format_type, k_base_offset> datum_type_t; 
  return FieldAtIndex(datum_type_t()); 
} 

static const size_t k_enum_base = 0 + 1;

   typedef  Hg::detail::DeduceProxyType < ((1 - k_enum_base)), format_type, k_base_offset>::type Proxyzero; 
   typedef  Proxyzero::datum_type datum_zero; 
   Proxyzero zero; datum_zero& FieldAtIndex(const datum_zero&) 
   { return *static_cast<datum_zero*>(&zero); } 
   
   const char* FieldName(const Proxyzero&) { return "zero"; }

   typedef  Hg::detail::DeduceProxyType < ((2 - k_enum_base)), format_type, k_base_offset>::type Proxyone; typedef Proxyone::datum_type datum_one; Proxyone one; datum_one& FieldAtIndex(const datum_one&) { return *static_cast<datum_one*>(&one); } const char* FieldName(const Proxyone&) { return "one"; }
   typedef  Hg::detail::DeduceProxyType < ((3 - k_enum_base)), format_type, k_base_offset>::type Proxytwo; typedef Proxytwo::datum_type datum_two; Proxytwo two; datum_two& FieldAtIndex(const datum_two&) { return *static_cast<datum_two*>(&two); } const char* FieldName(const Proxytwo&) { return "two"; }
   typedef  Hg::detail::DeduceProxyType < ((4 - k_enum_base)), format_type, k_base_offset>::type Proxythree; typedef Proxythree::datum_type datum_three; Proxythree three; datum_three& FieldAtIndex(const datum_three&) { return *static_cast<datum_three*>(&three); } const char* FieldName(const Proxythree&) { return "three"; }
   typedef  Hg::detail::DeduceProxyType < ((5 - k_enum_base)), format_type, k_base_offset>::type Proxyfour; typedef Proxyfour::datum_type datum_four; Proxyfour four; datum_four& FieldAtIndex(const datum_four&) { return *static_cast<datum_four*>(&four); } const char* FieldName(const Proxyfour&) { return "four"; }

private: 
template <typename T, typename U> size_t DatumSize(T value, U&) { return value; } 
template <typename U> size_t DatumSize(pfnGetDatumSize ftor, U& buffer) { if (buffer.empty()) { return 0; } return ftor(buffer.data(), buffer.size()); } 

}; 
//typedef Hg::make_Hg_type_list<F>::type                    F##_Hg;
//nested_format_tFormat

namespace detail { 
template <> 
struct field_data_t <nested_format_t> 
{ 
  typedef nested_format_t_HgFormat value_type; 
//  typedef nested_format_t_HgFormat 
}; 

template< > 
struct FieldTypes <nested_format_t> 
: field_data_t<nested_format_t>::value_type 
{ typedef nested_format_t index_type; 
typedef field_data_t<nested_format_t>::value_type value_type; 

FieldTypes() 
: m_shadow_data(This()) { } 
value_type& This() {return *this;} 
value_type &m_shadow_data; 
}; 

}

//  ****************************************************************************
//  A type array used to create the base message field.
// 
//  The entry, HG_TYPE_ARRAY(size_t, 3), defined below is equivalent to this:
//
//      array<size_t, 3>
//
typedef TypeList
<
  uint32_t,
  uint32_t,
  uint32_t,
  uint8_t,
  nested_format_t,
  std::array<uint32_t, 3>
> base_format_t;


//  ****************************************************************************
//  A type list definition for a single entry message.
// 
typedef TypeList
<
  uint32_t      
> single_t;

HG_BEGIN_FORMAT(single_t)
  HG_DATUM (uint32_t, only)
HG_END_FORMAT(single_t)

//  ****************************************************************************
//  A type list definition for a single nested message.
// 
typedef TypeList
<
  nested_format_t      
> single_nested_t;

HG_BEGIN_FORMAT(single_nested_t)
  HG_DATUM (nested_format_t, only)
HG_END_FORMAT(single_nested_t)

//  ****************************************************************************
//  Bitlist with a single entry 
// the Hg namespace.
HG_BEGIN_BIT_SET (uint8_t, single_bit)
  HG_BIT_FIELD   (0, lonely, 1)
HG_END_BIT_SET

typedef TypeList
<
  single_bit      
> single_bit_t;

HG_BEGIN_FORMAT(single_bit_t)
  HG_DATUM (single_bit, only)
HG_END_FORMAT(single_bit_t)

//  ****************************************************************************
//  A type list used to verify the sequence containers.
//
typedef TypeList
<
  uint32_t,      
  uint32_t,     
  uint32_t
> point_format_t;

HG_BEGIN_FORMAT(point_format_t)
  HG_DATUM (uint32_t, X)
  HG_DATUM (uint32_t, Y)
  HG_DATUM (uint32_t, Z)
HG_END_FORMAT(point_format_t)

//  ****************************************************************************
//  A type list definition that defines a single array as the only field.
// 
typedef TypeList
<
  std::array<point_format_t, 2>      
> single_array_t;

HG_BEGIN_FORMAT(single_array_t)
  HG_DATUM ((std::array<point_format_t, 2>), line)
HG_END_FORMAT(single_array_t)



} // namespace Hg


#endif
