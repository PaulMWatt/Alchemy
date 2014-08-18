/// @file TestFocusedDynamicMessageSuite.hpp
/// 
/// The tests in this group first verify a basic definition.
/// The a second section contains tests with more focused scenarios
/// that have required extra attention during development.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
/// 
///  Verify data with these TEST ASSERTIONS:
/// 
/// TS_FAIL(message):                        Fail unconditionally
/// TS_ASSERT(expr):                         Verify (expr) is true
/// TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
/// TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
/// TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
/// TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
/// TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
/// TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
/// TS_ASSERT_PREDICATE(P, x):               Verify P(x)
/// TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
/// TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
/// TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
/// TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
/// TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
/// TS_WARN(message):                        Print message as a warning
/// TS_TRACE(message):                       Print message as an information message
/// 
#ifndef TEST_FOCUSED_DYNAMIC_MESSAGE_SUITE_H_INCLUDED
#define TEST_FOCUSED_DYNAMIC_MESSAGE_SUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <msgtest_typelist.h>
#include <Hg.h>
#include <algorithm>
#include <string>

#include <geometry_typelist.h>
#include <geometry_testdata.h>

namespace test
{
//  Typedefs *****************************************************************
typedef std::vector<uint8_t>                              byte_vector;

} // namespace test

//  ****************************************************************************
/// @brief TestFocusedDynamicMessageSuite Test Suite class.
///
class TestFocusedDynamicMessageSuite : public CxxTest::TestSuite
{
public:

  TestFocusedDynamicMessageSuite()
  { 
  }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  { }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  { }

protected:
  //  Typedefs *****************************************************************
  typedef test::byte_vector             byte_vector;

  //  Constants ******************************************************************

  // Helper Functions ************************************************************
  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateBaseValues(SUT_t& msg)
  {
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
  }

public:
  // Test Cases ****************************************************************
  void Test_write_vector_with_nested_fixed_size(void);
  void Test_read_vector_with_nested_fixed_size(void);

  void Test_write_vector_with_nested_dynamic_size(void);
  void Test_read_vector_with_nested_dynamic_size(void);

  void Test_write_vector_with_nested_mixed_size(void);
  void Test_read_vector_with_nested_mixed_size(void);

  void Test_write_array_of_bitsets(void);
  void Test_read_array_of_bitsets(void);

  void Test_write_array_of_arrays(void);
  void Test_read_array_of_arrays(void);

  void Test_write_array_of_vectors(void);
  void Test_read_array_of_vectors(void);

  void Test_write_vector_of_bitsets(void);
  void Test_read_vector_of_bitsets(void);

  void Test_write_vector_of_arrays(void);
  void Test_read_vector_of_arrays(void);

  void Test_write_vector_of_vectors(void);
  void Test_read_vector_of_vectors(void);


  void Test_write_nested_at_correct_offset(void);

};


//  ****************************************************************************
//  The message definitions, utility functions and tests are grouped 
//  together for clarity and convenience. Each set of definitions is grouped
//  with the tests directly below their definition.
//  Also each set of tests definitions is defined within a namespace to avoid
//  collisions with similar definitions for the other tests.
//



//  ****************************************************************************
namespace Hg {

typedef TypeList
<
  uint16_t,                       // size:          =  2
  std::vector<pt3d_t>             // size: (3 * 4)  = 12
> points_t;                       // total:         = 14

HG_BEGIN_FORMAT(points_t)
  HG_DATUM (uint16_t, count)
  HG_DYN_DATUM ((std::vector<pt3d_t>), pts, count)
HG_END_FORMAT


} // namespace Hg


//  Nested-Fixed sub-fields ****************************************************
namespace test
{
namespace nested
{
namespace fixed
{
typedef Hg::Message<Hg::points_tFormat<0> >    MsgPoints;
typedef MsgPoints                              SUT;

const   size_t k_count = 3;

//  ************************************
void make_buffer(byte_vector &buffer)
{
  using namespace test::data;

  // allocate space for the size fields (2-bytes).
  buffer.resize(sizeof(uint16_t));

  uint16_t count = k_count;
  ::memcpy(&buffer[0], &count, sizeof(count));

  // to_buffer allocates its own space for the vector.
  to_buffer(k_eight_pts[0], buffer);
  to_buffer(k_eight_pts[1], buffer);
  to_buffer(k_eight_pts[2], buffer);
}

//  ************************************
void populate_msg(SUT &msg)
{
  using namespace test::data;

  msg.count = k_count;
  msg.pts.resize(msg.count);

  msg.pts[0].X   = k_eight_pts[0].X;
  msg.pts[0].Y   = k_eight_pts[0].Y;
  msg.pts[0].Z   = k_eight_pts[0].Z;
  
  msg.pts[1].X   = k_eight_pts[1].X;
  msg.pts[1].Y   = k_eight_pts[1].Y;
  msg.pts[1].Z   = k_eight_pts[1].Z;

  msg.pts[2].X   = k_eight_pts[2].X;
  msg.pts[2].Y   = k_eight_pts[2].Y;
  msg.pts[2].Z   = k_eight_pts[2].Z;
}


} // namespace fixed
} // namespace nested
} // namespace test

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_fixed_size(void)
{
  using namespace test::nested::fixed;

  // Place them in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the SUT with the test values.
  SUT sut;
  populate_msg(sut);

  // SUT: Serialize into a buffer.
  uint8_t const* pData = sut.data();

  TS_ASSERT_EQUALS(buffer.size(), sut.size());
  TS_ASSERT_SAME_DATA(&buffer[0], pData, buffer.size());
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_with_nested_fixed_size(void)
{
  using namespace test::nested::fixed;
  using namespace test::data;

  // Place three points in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the expected structure for comparison.
  MsgPoints expected;
  populate_msg(expected);

  // SUT
  SUT sut;
  sut.assign(&buffer[0], buffer.size());

  // Verify the results for all of the fields.
  TS_ASSERT_EQUALS(k_count, sut.count);
  TS_ASSERT_EQUALS(k_eight_pts[0].X, sut.pts[0].X);
  TS_ASSERT_EQUALS(k_eight_pts[0].Y, sut.pts[0].Y);
  TS_ASSERT_EQUALS(k_eight_pts[0].Z, sut.pts[0].Z);

  TS_ASSERT_EQUALS(k_eight_pts[1].X, sut.pts[1].X);
  TS_ASSERT_EQUALS(k_eight_pts[1].Y, sut.pts[1].Y);
  TS_ASSERT_EQUALS(k_eight_pts[1].Z, sut.pts[1].Z);

  TS_ASSERT_EQUALS(k_eight_pts[2].X, sut.pts[2].X);
  TS_ASSERT_EQUALS(k_eight_pts[2].Y, sut.pts[2].Y);
  TS_ASSERT_EQUALS(k_eight_pts[2].Z, sut.pts[2].Z);
}

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_dynamic_size(void)
{
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_with_nested_dynamic_size(void)
{

}

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_mixed_size(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_with_nested_mixed_size(void)
{

}

//  Array of Bitsets ***********************************************************
namespace test
{
namespace fixed_array
{
namespace bit_list
{
typedef Hg::Message<Hg::color_map_tFormat<0> >    MsgColorMap;
typedef MsgColorMap                               SUT;

//  ************************************
//  A message buffer with the expected 
//  test results.
//
void make_buffer(byte_vector &buffer)
{
  using namespace test::data;

  buffer.clear();

  // to_buffer allocates its own space for the vector.
  to_buffer(k_White  , buffer);
  to_buffer(k_Fuchsia, buffer);
  to_buffer(k_Aqua   , buffer);
  to_buffer(k_Yellow , buffer);
  to_buffer(k_Purple , buffer);
  to_buffer(k_Teal   , buffer);
  to_buffer(k_Olive  , buffer);
  to_buffer(k_Silver , buffer);
  to_buffer(k_Blue   , buffer);
  to_buffer(k_Lime   , buffer);
  to_buffer(k_Red    , buffer);
  to_buffer(k_Gray   , buffer);
  to_buffer(k_Navy   , buffer);
  to_buffer(k_Green  , buffer);
  to_buffer(k_Maroon , buffer);
  to_buffer(k_Black  , buffer);
}

//  ************************************
void populate_msg(SUT &msg)
{
  using namespace test::data;

  msg.table[0]  = k_White  ;
  msg.table[1]  = k_Fuchsia;
  msg.table[2]  = k_Aqua   ;
  msg.table[3]  = k_Yellow ;
  msg.table[4]  = k_Purple ;
  msg.table[5]  = k_Teal   ;
  msg.table[6]  = k_Olive  ;
  msg.table[7]  = k_Silver ;
  msg.table[8]  = k_Blue   ;
  msg.table[9]  = k_Lime   ;
  msg.table[10] = k_Red    ;
  msg.table[11] = k_Gray   ;
  msg.table[12] = k_Navy   ;
  msg.table[13] = k_Green  ;
  msg.table[14] = k_Maroon ;
  msg.table[15] = k_Black  ;
}


} // namespace bit_list
} // namespace fixed_array
} // namespace test

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_array_of_bitsets(void)
{
  using namespace test::fixed_array::bit_list;

  // Place them in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the SUT with the test values.
  SUT sut;
  populate_msg(sut);

  // SUT: Serialize into a buffer.
  uint8_t const* pData = sut.data();

  //TS_ASSERT_EQUALS(buffer.size(), sut.size());
  //TS_ASSERT_SAME_DATA(&buffer[0], pData, buffer.size());
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_array_of_bitsets(void)
{
  using namespace test::fixed_array::bit_list;
  using namespace test::data;

  // Place three points in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the expected structure for comparison.
  MsgColorMap expected;
  populate_msg(expected);

  // SUT
  SUT sut;
  sut.assign(&buffer[0], buffer.size());

  // Verify the results for all of the fields.
  //TS_ASSERT_EQUALS(k_White  , sut.table[0] );
  //TS_ASSERT_EQUALS(k_Fuchsia, sut.table[1] );
  //TS_ASSERT_EQUALS(k_Aqua   , sut.table[2] );
  //TS_ASSERT_EQUALS(k_Yellow , sut.table[3] );
  //TS_ASSERT_EQUALS(k_Purple , sut.table[4] );
  //TS_ASSERT_EQUALS(k_Teal   , sut.table[5] );
  //TS_ASSERT_EQUALS(k_Olive  , sut.table[6] );
  //TS_ASSERT_EQUALS(k_Silver , sut.table[7] );
  //TS_ASSERT_EQUALS(k_Blue   , sut.table[8] );
  //TS_ASSERT_EQUALS(k_Lime   , sut.table[9] );
  //TS_ASSERT_EQUALS(k_Red    , sut.table[10]);
  //TS_ASSERT_EQUALS(k_Gray   , sut.table[11]);
  //TS_ASSERT_EQUALS(k_Navy   , sut.table[12]);
  //TS_ASSERT_EQUALS(k_Green  , sut.table[13]);
  //TS_ASSERT_EQUALS(k_Maroon , sut.table[14]);
  //TS_ASSERT_EQUALS(k_Black  , sut.table[15]);
}

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_array_of_arrays(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_array_of_arrays(void)
{

}

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_array_of_vectors(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_array_of_vectors(void)
{

}

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_of_bitsets(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_of_bitsets(void)
{

}

//  ****************************************************************************
namespace Hg {

typedef std::array<uint32_t, 5>     u32_array_t;

typedef TypeList
<
  uint16_t,                       //                =  2
  std::vector<u32_array_t>        // size: (4 * 5)  = 20
> vec_array_t;                    // total:         = 22 * ?

HG_BEGIN_FORMAT(vec_array_t)
  HG_DATUM     (uint16_t, count)
  HG_DYN_DATUM ((std::vector<u32_array_t>), items, count)
HG_END_FORMAT


} // namespace Hg

//  Vector of Arrays ***********************************************************
namespace test
{
namespace vector
{
namespace fixed_array
{
typedef Hg::Message<Hg::vec_array_tFormat<0> >    MsgVecArray;
typedef MsgVecArray                               SUT;


inline
void to_buffer(uint32_t     a,
               uint32_t     b,
               uint32_t     c,
               uint32_t     d,
               uint32_t     e, 
               byte_vector &buffer)
{
  const size_t k_org_size    = buffer.size();
  const size_t k_increased_size = 20;
  buffer.resize(k_org_size + k_increased_size);

  const size_t k_len = sizeof(uint32_t);
  byte_vector::value_type *pCur = &buffer[0];
  std::advance(pCur, k_org_size);

  ::memcpy(pCur, &a, k_len);
  std::advance(pCur, k_len);

  ::memcpy(pCur, &b, k_len);
  std::advance(pCur, k_len);

  ::memcpy(pCur, &c, k_len);
  std::advance(pCur, k_len);

  ::memcpy(pCur, &d, k_len);
  std::advance(pCur, k_len);

  ::memcpy(pCur, &e, k_len);
  std::advance(pCur, k_len);
}

//  ************************************
//  A message buffer with the expected 
//  test results.

void make_buffer(byte_vector &buffer)
{
  using namespace test::data;

  buffer.clear();

  // to_buffer allocates its own space for the vector.
  uint16_t num = 4;
  buffer.resize(sizeof(uint16_t));
  test::byte_vector::value_type *pCur = &buffer[0];
  ::memcpy(pCur, &num, sizeof(uint16_t));
  std::advance(pCur, sizeof(uint16_t));

  to_buffer(0x11223344, 0x22334455, 0x33445566, 0x44556677, 0x55667788, buffer);
  to_buffer(0x66778899, 0x778899AA, 0x8899AABB, 0x99AABBCC, 0xAABBCCDD, buffer);
  to_buffer(0xBEEFBA11, 0xDEADC0DE, 0xFEEDD011, 0x0D065000, 0xBABB1E00, buffer);
  to_buffer(0xEEFF0011, 0xFF001122, 0x01234567, 0x89ABCDEF, 0xFEDCBA98, buffer);
}

//  ************************************
void populate_msg(SUT &msg)
{
  using namespace test::data;

  msg.count = 4;
  //u32_array_t 
  std::array<uint32_t,5> a ={0x11223344, 0x22334455, 0x33445566, 0x44556677, 0x55667788};
  msg.items.push_back(a);
  std::array<uint32_t,5>b ={0x66778899, 0x778899AA, 0x8899AABB, 0x99AABBCC, 0xAABBCCDD};
  msg.items.push_back(b);
  std::array<uint32_t,5> c ={0xBEEFBA11, 0xDEADC0DE, 0xFEEDD011, 0x0D065000, 0xBABB1E00};
  msg.items.push_back(c);
  std::array<uint32_t,5> d ={0xEEFF0011, 0xFF001122, 0x01234567, 0x89ABCDEF, 0xFEDCBA98};
  msg.items.push_back(d);
}

} // namespace fixed_array
} // namespace vector 
} // namespace test

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_of_arrays(void)
{
  using namespace test::vector::fixed_array;

  // Place them in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the SUT with the test values.
  SUT sut;
  populate_msg(sut);

  // SUT: Serialize into a buffer.
  uint8_t const* pData = sut.data();

  TS_ASSERT_EQUALS(buffer.size(), sut.size());
  TS_ASSERT_SAME_DATA(&buffer[0], pData, buffer.size());

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_of_arrays(void)
{
  using namespace test::vector::fixed_array;
  using namespace test::data;

  // Place three points in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the expected structure for comparison.
  MsgVecArray expected;
  populate_msg(expected);

  // SUT
  SUT sut;
  sut.assign(&buffer[0], buffer.size());

  // Verify the results for all of the fields.
  TS_ASSERT_EQUALS(4         , sut.count );

  TS_ASSERT_EQUALS(0x11223344, sut.items[0][0] ); 
  TS_ASSERT_EQUALS(0x22334455, sut.items[0][1] ); 
  TS_ASSERT_EQUALS(0x33445566, sut.items[0][2] ); 
  TS_ASSERT_EQUALS(0x44556677, sut.items[0][3] ); 
  TS_ASSERT_EQUALS(0x55667788, sut.items[0][4] );

  TS_ASSERT_EQUALS(0x66778899, sut.items[1][0] ); 
  TS_ASSERT_EQUALS(0x778899AA, sut.items[1][1] ); 
  TS_ASSERT_EQUALS(0x8899AABB, sut.items[1][2] ); 
  TS_ASSERT_EQUALS(0x99AABBCC, sut.items[1][3] ); 
  TS_ASSERT_EQUALS(0xAABBCCDD, sut.items[1][4] );

  TS_ASSERT_EQUALS(0xBEEFBA11, sut.items[2][0] ); 
  TS_ASSERT_EQUALS(0xDEADC0DE, sut.items[2][1] ); 
  TS_ASSERT_EQUALS(0xFEEDD011, sut.items[2][2] ); 
  TS_ASSERT_EQUALS(0x0D065000, sut.items[2][3] ); 
  TS_ASSERT_EQUALS(0xBABB1E00, sut.items[2][4] );

  TS_ASSERT_EQUALS(0xEEFF0011, sut.items[3][0] ); 
  TS_ASSERT_EQUALS(0xFF001122, sut.items[3][1] ); 
  TS_ASSERT_EQUALS(0x01234567, sut.items[3][2] ); 
  TS_ASSERT_EQUALS(0x89ABCDEF, sut.items[3][3] ); 
  TS_ASSERT_EQUALS(0xFEDCBA98, sut.items[3][4] );
}

//  ****************************************************************************
namespace Hg {

// Define a message format that consists of a collection of 
// NULL terminated strings, with a double-NULL terminator.
typedef std::vector<char>         char_str;


//  ****************************************************************************
//  Field-size functor
//  Count the number of non-empty character sequences until an empty string.
//  The empty string must occur before the end of the buffer (buffer + length).
//  The entire buffer does not need to be used before the empty string.
//
size_t StringCount(uint8_t* pBuffer, size_t length)
{
  size_t count = 0;

  char const* pCur =  reinterpret_cast<char const*>(pBuffer);
  char const* pLast = pCur;
  std::advance(pLast, length);

  size_t  len = 1;
  while (pCur < pLast)
  {
    len = std::char_traits<char>::length(pCur);
    if (0 == len)
      break;

    ++count;
    std::advance(pCur, len);
  }

  return count;
}

// Message definition
typedef TypeList
<
  std::vector<char_str>          
> string_vec_t;                   

HG_BEGIN_FORMAT(string_vec_t)
  HG_DYN_DATUM ((std::vector<char_str>), items, &StringCount)
HG_END_FORMAT

//
//template< size_t kt_offset > struct string_vec_tFormat; template <> struct detail::field_data_t <string_vec_t> { typedef string_vec_tFormat<0> value_type;
//};
//template< size_t kt_offset > struct detail::FieldTypes <string_vec_t,kt_offset> : string_vec_tFormat<kt_offset> { typedef string_vec_t index_type;
//typedef string_vec_tFormat < kt_offset > value_type;
//FieldTypes() : m_shadow_data(This()) { } value_type& This() {return *this;
//} value_type &m_shadow_data;
//};
//template< size_t kt_offset > struct string_vec_tFormat : nested_trait { typedef string_vec_t format_type;
//enum { k_size = SizeOf<format_type>::value };
//enum { k_length = length<format_type>::value };
//enum { k_base_offset = kt_offset };
//template< size_t IDX> Datum<IDX, format_type, k_base_offset>& FieldAt() { typedef Datum < IDX, format_type, k_base_offset> datum_type_t;
//return FieldAtIndex(datum_type_t());
//} template <int L> struct decrement_until_match;
//template<int N> struct enum_begin : std::integral_constant<int, N> { };
//template<int N, bool IsValidT = false> struct enum_entry : std::integral_constant<bool, IsValidT> { };
//template<int N> struct enum_entry<N, true> : std::true_type {};
//template<> struct enum_entry<0, true> : std::true_type {};
//template <int L> struct index_before : std::integral_constant< int, decrement_until_match<L - 1>::value > { };
//template <int L> struct auto_index : std::integral_constant< int, index_before<L>::value + 1 > { };
//template <> struct auto_index<0> : std::integral_constant< int, -1> { };
//template <int L> struct decrement_until_match : std::integral_constant< int, value_if< enum_entry<L>::value, int, auto_index<L>::value, decrement_until_match<L - 1>::value >::value > { };
//template <> struct decrement_until_match<0> : std::integral_constant <int, -1> { };
//typedef std::integral_constant<int, 672> enum_base;
//
//  template<> struct enum_entry<(673 - enum_base::value)> : std::true_type { };
//  typedef typename Hg::detail::DeduceProxyType < (auto_index<673- enum_base::value>::value), format_type, k_base_offset>::type Proxyitems;
//  typedef typename Proxyitems::datum_type datum_items;
//  Proxyitems items;
//  datum_items& FieldAtIndex(const datum_items&) { return *static_cast<datum_items*>(&items);
//  } const char* FieldName(const Proxyitems&) { return "items";
//  } template <typename U> size_t Size(U& buffer, datum_items&) { return DatumSize(StringCount, buffer);
//  }
//
//
//
//private: 
//
//  template <typename T, typename U> 
//  size_t DatumSize( typename std::enable_if<std::is_integral<T>::value, T>::type value,
//                    U&) 
//  { 
//    return value;
//  } 
//
//
//  //template <typename T, typename U> 
//  //size_t DatumSize(T value, U&) 
//  //{ 
//  //  return value;
//  //} 
//  
//  template <typename U> 
//  size_t DatumSize(pfnGetDatumSize ftor, U& buffer) 
//  { 
//    if (buffer.empty()) 
//    { 
//      return 0;
//    } 
//    
//    size_t x = ftor(buffer.data(), buffer.size());
//    return 0;
//  }
//};





} // namespace Hg

//  Vector of vectors **********************************************************
namespace test
{
namespace vec
{
namespace vec
{
typedef Hg::Message<Hg::string_vec_tFormat<0> >   MsgStrVec;
typedef MsgStrVec                                 SUT;

//  Constants **************************
const size_t k_count = 7;
char* pStrings[k_count] =
{
  "Dog", 
  "cAt", 
  "FiSh", 
  "HoRsE", 
  "cHiCkEn",
  "SpIdEr",
  "MoLd"
};

//  ************************************
inline
void to_buffer(const char *pStr,
               byte_vector &buffer)
{
  const size_t k_org_size    = buffer.size();
  const size_t len = ::strlen(pStr) + 1;
  buffer.resize(k_org_size + len);

  byte_vector::value_type *pCur = &buffer[0];
  std::advance(pCur, k_org_size);

  ::memcpy(pCur, pStr, len);
}

//  ************************************
//  A message buffer with the expected 
//  test results.

void make_buffer(byte_vector &buffer)
{
  buffer.clear();

  // to_buffer allocates its own space for the vector.
  to_buffer("Dog", buffer);
  to_buffer("cAt", buffer);
  to_buffer("FiSh", buffer);
  to_buffer("HoRsE", buffer);
  to_buffer("cHiCkEn", buffer);
  to_buffer("SpIdEr", buffer);
  to_buffer("MoLd", buffer);

  buffer.push_back(0);
}

//  ************************************
void populate_msg(SUT &msg)
{
  using Hg::char_str;

  for ( size_t index = 0; 
        index < test::vec::vec::k_count; 
        ++index)
  {
    char_str entry;
    entry.assign(pStrings[index], pStrings[index] + strlen(pStrings[index]));
    entry.push_back(0);

    msg.items.push_back(entry);
  }

  char_str empty_str;
  empty_str.push_back(0);

  msg.items.push_back(empty_str);
}

} // namespace vec
} // namespace vec
} // namespace test

//  ****************************************************************************
//  Tests 
//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_of_vectors(void)
{
  using namespace test::vec::vec;
  using namespace test::data;

  // Place them in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the SUT with the test values.
  SUT sut;
  populate_msg(sut);

  //SUT: Serialize into a buffer.
  uint8_t const* pData = sut.data();

  TS_ASSERT_EQUALS(buffer.size(), sut.size());
  TS_ASSERT_SAME_DATA(&buffer[0], pData, buffer.size());
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_of_vectors(void)
{
  using namespace test::vec::vec;
  using namespace test::data;

  // Place three points in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the expected structure for comparison.
  MsgStrVec expected;
  populate_msg(expected);

  // SUT
  SUT sut;
//  sut.assign(&buffer[0], buffer.size());

  // Verify the results for all of the fields.
//  TS_ASSERT_EQUALS(k_count   , sut.count );

  //TS_ASSERT_EQUALS(0x11223344, sut.items[0]); 

  //TS_ASSERT_EQUALS(0x66778899, sut.items[1][0] ); 

  //TS_ASSERT_EQUALS(0xBEEFBA11, sut.items[2][0] ); 

  //TS_ASSERT_EQUALS(0xEEFF0011, sut.items[3][0] ); 
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_nested_at_correct_offset(void)
{

}


#endif
