// @file TestMeta.h
// 
// Test suite to verify functionality for small template meta-programming tools.
// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
// 
// @note   The bitset and bitfield objects are only useful in the context of 
//         Msg_fields with Packets. Therefore, the basic meta-constructs for
//         Bit_sets will be verified in this test suite. The majority of the
//         Bit_set verification will occur in the Msg_field test suite.
//
// @note   The *compile_check* and *type_check* based constructs 
//         are not tests for negative results because they would cause the
//         unit tests to not compile. The fact that the unit tests do compile
//         verifies that the *compile_check* constructs are valid.
// 
// Verify data with these TEST ASSERTIONS:
// 
// TS_FAIL(message):                        Fail unconditionally
// TS_ASSERT(expr):                         Verify (expr) is true
// TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
// TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
// TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
// TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
// TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
// TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
// TS_ASSERT_PREDICATE(P, x):               Verify P(x)
// TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
// TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
// TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
// TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
// TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
// TS_WARN(message):                        Print message as a warning
// TS_TRACE(message):                       Print message as an information message
// 
//  ****************************************************************************
#ifndef TESTMETA_H_INCLUDED
#define TESTMETA_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <geometry_typelist.h>
#include <Pb/meta_fwd.h>
#include <test_def.h>

//  ****************************************************************************
/// Verifies a variety of utility meta-templateconstructs.
/// 
class TestMeta : public CxxTest::TestSuite
{
public: 
  
  TestMeta()
  {
    
  }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {

  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {

  }

protected:
  // Test Suite Data ***********************************************************
  typedef Hg::DeduceBitFieldList<0, Hg::Bitset_format>::type          TypeA;
  typedef TypeA::value_type                                           value_type_a;

  typedef Hg::DeduceBitFieldList<1, Hg::Bitset_format>::type          TypeB;
  typedef TypeB::value_type                                           value_type_b;

public:
  //  Test Cases ***************************************************************
  //  Test Meta-conditional constructs *****************************************
  void Test_value_if_true();
  void Test_value_if_false();
  void Test_one_or_zero_1();
  void Test_one_or_zero_0();

  //  Test Compile-time checks *************************************************
  void Test_type_check();

  //  Boolean Operations *******************************************************
  void Test_not_true();
  void Test_not_false();
  void Test_and_true();
  void Test_and_false();
  void Test_or_true();
  void Test_or_false();

  //  Test type_container ******************************************************
  //  Parameterized version
  void Test_type_container_T();

  // Specializations
  void Test_type_container_empty();
  void Test_type_container_type_list();
  void Test_type_container_traits();

  // Test container_size ********************************************************
  void Testcontainer_size();

  // Test length, TypeContainer item count *************************************
//  void Test_length();

  // type_at Template Tests *****************************************************
  void Testtype_at_1_to_max();

  // size_of Template Tests *****************************************************
  // Verify the intrinsic types
  void Testsize_of_char();
  void Testsize_of_uchar();
  void Testsize_of_short();
  void Testsize_of_ushort();
  void Testsize_of_long();
  void Testsize_of_ulong();
  void Testsize_of_float();
  void Testsize_of_double();

  // Verify the type_containers
  void Testsize_of_empty();
  void Testsize_of_type_list();
  void Testsize_of_NestedNestedtype_list();
  void Testsize_of_BitSet();
  void Testsize_of_DynamicValue();
  void Testsize_of_NestedArray();

  // size_at Template Tests *****************************************************
  void Testsize_at_1_to_max();

  // offset_of Template Tests ***************************************************
  void Testoffset_of_basic();
  void Testoffset_of_bitset();
  void Testoffset_of_nested();

  //  BitSet Body Tests ********************************************************
  void TestBitSet_constructor();
  void TestBitSet_conversion();
  void TestBitSet_assignment_BitSet();
  void TestBitSet_assignment_value_type();
  void TestBitSet_size();

  //  Static ForEach Tests *****************************************************
  void TestForEach();

};

//  ****************************************************************************
//  ****************************************************************************
void TestMeta::Test_value_if_true()
{
  // Choose the first value listed:
  const size_t k_control = 1024;
  const size_t k_other   = 123;
  size_t       result    = Hg::value_if<true,size_t,k_control,k_other>::value;

  TS_ASSERT_DIFFERS(k_control, k_other);
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestMeta::Test_value_if_false()
{
  // Choose the second value listed:
  const size_t k_control = 1024;
  const size_t k_other   = 123;
  size_t       result    = Hg::value_if<false,size_t,k_other,k_control>::value;

  TS_ASSERT_DIFFERS(k_control, k_other);
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestMeta::Test_one_or_zero_1()
{
  const int k_control = 1;
  TS_ASSERT_EQUALS(k_control, (Hg::one_or_zero<true>::value));
}

//  ****************************************************************************
void TestMeta::Test_one_or_zero_0()
{
  const int k_control = 0;
  TS_ASSERT_EQUALS(k_control, (Hg::one_or_zero<false>::value));
}  

//  ****************************************************************************
void TestMeta::Test_type_check()
{
  // This is a static compilation test.
  // If the unit-test program successfully compiles, this test is a success.
// TODO: Find the best way with other compilers to let this compile without an error. 
#if defined(_WIN32)
  Hg::type_check<true>;
#endif
}

//  ****************************************************************************
void TestMeta::Test_not_true()
{
  // SUT
  bool result = Hg::Not<std::false_type>::value;
  TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestMeta::Test_not_false()
{
  // SUT
  bool result = Hg::Not<std::true_type>::value;
  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestMeta::Test_and_true()
{
  // SUT
  bool result = Hg::And<std::true_type,
                        std::true_type>::value;
  TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestMeta::Test_and_false()
{
  bool result;
  // SUT 1
  result = Hg::And< std::false_type,
                    std::false_type>::value;
  TS_ASSERT_EQUALS(false, result);

  // SUT 2
  result = Hg::And< std::true_type,
                    std::false_type>::value;
  TS_ASSERT_EQUALS(false, result);

  // SUT 3
  result = Hg::And< std::false_type,
                    std::true_type>::value;
  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestMeta::Test_or_true()
{
  bool result;
  // SUT 1
  result = Hg::Or < std::true_type,
                    std::true_type>::value;
  TS_ASSERT_EQUALS(true, result);

  // SUT 2
  result = Hg::Or < std::true_type,
                    std::false_type>::value;
  TS_ASSERT_EQUALS(true, result);

  // SUT 3
  result = Hg::Or < std::false_type,
                    std::true_type>::value;
  TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestMeta::Test_or_false()
{
  // SUT
  bool result = Hg::Or <std::false_type,
                        std::false_type>::value;
  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestMeta::Test_type_container_T()
{
  // Verify all intrinsic types, all forms must report false;
  TS_ASSERT_EQUALS(false, Hg::type_container<char>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<unsigned char>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<short>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<unsigned short>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<int>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<unsigned int>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<long>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<unsigned long>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<float>::value);
  TS_ASSERT_EQUALS(false, Hg::type_container<double>::value);

  // Add a test for a pointer type
  TS_ASSERT_EQUALS(false, Hg::type_container<int*>::value);
  // Add a test for a reference type
  TS_ASSERT_EQUALS(false, Hg::type_container<int&>::value);
  // Add a test for a const type
  TS_ASSERT_EQUALS(false, Hg::type_container<const int>::value);
}

//  ****************************************************************************
void TestMeta::Test_type_container_empty()
{
  typedef Hg::MT sut_t;
  TS_ASSERT_EQUALS(false, Hg::type_container<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Test_type_container_type_list()
{
  // The type array requires an instantiated template type.
  typedef Hg::type_list<int>                     sut1_t;
  typedef Hg::type_list<int, double>             sut2_t;
  typedef Hg::type_list<int, double, ptrdiff_t>  sut3_t;

  TS_ASSERT(Hg::type_container<sut1_t>::value);
  TS_ASSERT(Hg::type_container<sut2_t>::value);
  TS_ASSERT(Hg::type_container<sut3_t>::value);
}

//  ****************************************************************************
void TestMeta::Test_type_container_traits()
{
  TS_ASSERT(Hg::type_container<TypeA>::value);
  TS_ASSERT(Hg::type_container<TypeB>::value);
}

//  ****************************************************************************
void TestMeta::Testcontainer_size()
{
  // Use the pre-declared types for this test.
  // Basic_format
  const size_t k_control1 = sizeof(Hg::type_at<0, Hg::Basic_format>::type)
                          + sizeof(Hg::type_at<1, Hg::Basic_format>::type)
                          + sizeof(Hg::type_at<2, Hg::Basic_format>::type)
                          + sizeof(Hg::type_at<3, Hg::Basic_format>::type);
  TS_ASSERT_EQUALS(k_control1, Hg::detail::container_size<Hg::Basic_format>::value);

  //  This section contains type_containers ************************************
  // type_containers must use size_of<> or container_size<> to determine the
  // actual buffer size required. Otherwise, there total object size is reported.

  // Compound_format
  const size_t k_control2 = sizeof(Hg::type_at<0, Hg::Compound_format>::type)
                          + sizeof(Hg::type_at<1, Hg::Compound_format>::type)
                          + sizeof(Hg::type_at<2, Hg::Compound_format>::type)
                          + Hg::size_of<Hg::type_at<3, Hg::Compound_format>::type>::value
                          + Hg::size_of<Hg::type_at<4, Hg::Compound_format>::type>::value;
  TS_ASSERT_EQUALS(k_control2, Hg::detail::container_size<Hg::Compound_format>::value);

  // Nested_compound_format
  const size_t k_control3 = sizeof(Hg::type_at<0, Hg::Nested_compound_format>::type)
    + Hg::size_of<Hg::type_at<1, Hg::Nested_compound_format>::type>::value;
  TS_ASSERT_EQUALS(k_control3, Hg::detail::container_size<Hg::Nested_compound_format>::value);

}

//  ****************************************************************************
void TestMeta::Testtype_at_1_to_max()
{
  // This test declares a type_list with a unique type for each potential
  // index in the array up to the max elements.
  typedef Hg::type_list< char,   unsigned char,  short,  unsigned short,
                          int,    unsigned int,   long,   unsigned long,
                          float,  double,         size_t, ptrdiff_t,
                          char*,  const char*,    char&,  const char&,
                          short*, const short*,   short&, const short&,
                          int*,   const int*,     int&,   const int&,
                          long*,  const long*,    long&,  const long&,
                          float*, const float*,   float&, const float&
                        > sut_t;

  // Each assertion verifies the type at the the requested index
  // matches the type encoded into the type_list.
  TS_ASSERT((std::is_same<char,            Hg::type_at<0,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned char,   Hg::type_at<1,sut_t>::type>::value));
  TS_ASSERT((std::is_same<short,           Hg::type_at<2,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned short,  Hg::type_at<3,sut_t>::type>::value));
                                                                                
  TS_ASSERT((std::is_same<int,             Hg::type_at<4,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned int,    Hg::type_at<5,sut_t>::type>::value));
  TS_ASSERT((std::is_same<long,            Hg::type_at<6,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned long,   Hg::type_at<7,sut_t>::type>::value));
                                                                                
  TS_ASSERT((std::is_same<float,           Hg::type_at<8,sut_t>::type>::value));
  TS_ASSERT((std::is_same<double,          Hg::type_at<9,sut_t>::type>::value));
  TS_ASSERT((std::is_same<size_t,          Hg::type_at<10,sut_t>::type>::value));
  TS_ASSERT((std::is_same<ptrdiff_t,       Hg::type_at<11,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<char*,           Hg::type_at<12,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const char*,     Hg::type_at<13,sut_t>::type>::value));
  TS_ASSERT((std::is_same<char&,           Hg::type_at<14,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const char&,     Hg::type_at<15,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<short*,          Hg::type_at<16,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const short*,    Hg::type_at<17,sut_t>::type>::value));
  TS_ASSERT((std::is_same<short&,          Hg::type_at<18,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const short&,    Hg::type_at<19,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<int*,            Hg::type_at<20,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const int*,      Hg::type_at<21,sut_t>::type>::value));
  TS_ASSERT((std::is_same<int&,            Hg::type_at<22,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const int&,      Hg::type_at<23,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<long*,           Hg::type_at<24,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const long*,     Hg::type_at<25,sut_t>::type>::value));
  TS_ASSERT((std::is_same<long&,           Hg::type_at<26,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const long&,     Hg::type_at<27,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<float*,          Hg::type_at<28,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const float*,    Hg::type_at<29,sut_t>::type>::value));
  TS_ASSERT((std::is_same<float&,          Hg::type_at<30,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const float&,    Hg::type_at<31,sut_t>::type>::value));
}

//  ****************************************************************************
void TestMeta::Testsize_of_char()
{
  typedef char sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_uchar()
{
  typedef unsigned char sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_short()
{
  typedef short sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_ushort()
{
  typedef unsigned short sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_long()
{
  typedef long sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_ulong()
{
  typedef unsigned long sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_float()
{
  typedef float sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_double()
{
  typedef double sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_empty()
{
  typedef Hg::MT sut_t;
  TS_ASSERT_EQUALS(1, Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_type_list()
{
  typedef Hg::type_list<int, double, ptrdiff_t> sut_t;
  const size_t k_control  = sizeof(int)
                          + sizeof(double)
                          + sizeof(ptrdiff_t);

  // SUT
  TS_ASSERT_EQUALS(k_control, Hg::size_of<sut_t>::value);

// TODO: I think that I can remove this. I am not certain that the original intent was ever required. that is making the typelist itself report the proper size with a sizeof call.
//  TS_ASSERT_EQUALS(sizeof(sut_t::type), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_NestedNestedtype_list()
{
  const size_t k_control_pt      = sizeof(int32_t) * 3;
  const size_t k_control_camera  = k_control_pt * 3;

  const size_t pt_size      = Hg::size_of<Hg::pt3d_t>::value;
  const size_t camera_size  = Hg::size_of<Hg::camera_t>::value;

  const size_t pt_size_f      = Hg::size_of<Hg::pt3d_t::format_type>::value;
  const size_t camera_size_f  = Hg::size_of<Hg::camera_t::format_type>::value;

  bool is_pt = Hg::type_container<Hg::pt3d_t>::value;
  bool is_camera = Hg::type_container<Hg::camera_t>::value;

  // SUT
  TS_ASSERT_EQUALS(k_control_pt, Hg::size_of<Hg::pt3d_t>::value);
  TS_ASSERT_EQUALS(k_control_camera, Hg::size_of<Hg::camera_t>::value);
  
  //TS_ASSERT_EQUALS(sizeof(sut_t::type), Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_BitSet()
{
  typedef Hg::Bits_type_a sut_t;
  const size_t k_control  = sizeof(Hg::Bits_type_a::value_type);

  // SUT
  TS_ASSERT_EQUALS(true,      Hg::type_container<sut_t>::value);
  TS_ASSERT_EQUALS(k_control, Hg::size_of<sut_t>::value);
  TS_ASSERT_EQUALS(k_control, Hg::detail::container_size<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_of_DynamicValue()
{
  typedef std::vector<char>                     char_vec;
  typedef std::vector<double>                   double_vec;
  typedef std::vector<std::array<char, 32>>     char_array_vec;

  typedef Hg::optional<char>                    opt_char;
  typedef Hg::optional<double>                  opt_double;
  typedef Hg::optional<std::array<char,32>>     opt_char_array;

  // Dynamically sized values return 0 for their static size.
  // All size calculations are performed at runtime for these field types.
  size_t size_char = Hg::size_of<char_vec>::value;
  TS_ASSERT_EQUALS(0, size_char);

  size_t size_double = Hg::size_of<char_vec>::value;
  TS_ASSERT_EQUALS(0, size_double);

  size_t size_array = Hg::size_of<char_vec>::value;
  TS_ASSERT_EQUALS(0, size_array);

  size_t size_opt_char = Hg::size_of<opt_char>::value;
  TS_ASSERT_EQUALS(0, size_opt_char);

  size_t size_opt_double = Hg::size_of<opt_double>::value;
  TS_ASSERT_EQUALS(0, size_opt_double);

  size_t size_opt_array = Hg::size_of<opt_char_array>::value;
  TS_ASSERT_EQUALS(0, size_opt_array);
}

//  ****************************************************************************
void TestMeta::Testsize_of_NestedArray()
{
  typedef Hg::type_list
  <
    int32_t,    // 4-bytes
    uint32_t,   // 4-bytes
    int16_t,    // 2-bytes
    uint16_t,   // 2-bytes
    char,       // 1-byte
    uint8_t     // 1-byte
  > Inner;      // 14-bytes total

  typedef Hg::type_list<std::array<Inner, 3> > sut_t;
  const size_t k_control  = Hg::size_of<Inner>::value * 3;

  // SUT
  TS_ASSERT_EQUALS(k_control, Hg::size_of<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Testsize_at_1_to_max()
{
  // This test declares a type_list with a unique type for each potential
  // index in the array up to the max elements.
  typedef Hg::type_list < char,   unsigned char,  short,  unsigned short,
                          int,    unsigned int,   long,   unsigned long,
                          float,  double,         size_t, ptrdiff_t,
                          char*,  const char*,    char&,  const char&,
                          short*, const short*,   short&, const short&,
                          int*,   const int*,     int&,   const int&,
                          long*,  const long*,    long&,  const long&,
                          float*, const float*,   float&, const float&
                        > sut_t;

  // Each assertion verifies the size of type at the the requested index
  // matches the size of the type encoded into the type_list.
  size_t result = (Hg::size_at<0,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(char),            result);
  result = (Hg::size_at<1,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(unsigned char),   result);
  result = (Hg::size_at<2,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(short),           result);
  result = (Hg::size_at<3,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(unsigned short),  result);

  result = (Hg::size_at<4,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(int),             result);
  result = (Hg::size_at<5,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(unsigned int),    result);
  result = (Hg::size_at<6,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(long),            result);
  result = (Hg::size_at<7,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(unsigned long),   result);

  result = (Hg::size_at<8,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(float),           result);
  result = (Hg::size_at<9,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(double),          result);
  result = (Hg::size_at<10,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(size_t),          result);
  result = (Hg::size_at<11,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(ptrdiff_t),       result);
                                            
  result = (Hg::size_at<12,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(char*),           result);
  result = (Hg::size_at<13,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const char*),     result);
  result = (Hg::size_at<14,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(char&),           result);
  result = (Hg::size_at<15,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const char&),     result);
                                            
  result = (Hg::size_at<16,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(short*),          result);
  result = (Hg::size_at<17,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const short*),    result);
  result = (Hg::size_at<18,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(short&),          result);
  result = (Hg::size_at<19,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const short&),    result);
                                            
  result = (Hg::size_at<20,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(int*),            result);
  result = (Hg::size_at<21,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const int*),      result);
  result = (Hg::size_at<22,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(int&),            result);
  result = (Hg::size_at<23,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const int&),      result);
                                            
  result = (Hg::size_at<24,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(long*),           result);
  result = (Hg::size_at<25,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const long*),     result);
  result = (Hg::size_at<26,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(long&),           result);
  result = (Hg::size_at<27,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const long&),     result);
                                            
  result = (Hg::size_at<28,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(float*),          result);
  result = (Hg::size_at<29,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const float*),    result);
  result = (Hg::size_at<30,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(float&),          result);
  result = (Hg::size_at<31,sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(const float&),    result);
}

//  ****************************************************************************
void TestMeta::Testoffset_of_basic()
{
  typedef Hg::Basic_format fmt;

  // Verifies the correct offset is calculated for each type in the type_list.
  size_t offsetTotal = 0;

  size_t offset = (Hg::offset_of<0,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);

  offsetTotal += sizeof(uint8_t); 
  offset = (Hg::offset_of<1,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);

  offsetTotal += sizeof(uint8_t);
  offset = (Hg::offset_of<2,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);

  offsetTotal += sizeof(uint16_t);
  offset = (Hg::offset_of<3,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
}

//  ****************************************************************************
void TestMeta::Testoffset_of_bitset()
{
  typedef Hg::Bitset_format fmt;

  // Verifies the correct offset is calculated for each type in the type_list.
  size_t offsetTotal = 0;

  size_t offset = (Hg::offset_of<0,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
  offsetTotal += sizeof(Hg::Bits_type_a::value_type); 
  offset = (Hg::offset_of<1,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
  offsetTotal += sizeof(Hg::Bits_type_b::value_type);
  size_t size = (Hg::size_of<fmt>::value);

  // Verify the final size is the sum of all of the offsets.
  TS_ASSERT_EQUALS(offsetTotal, size);
}

//  ****************************************************************************
void TestMeta::Testoffset_of_nested()
{
  typedef Hg::Nested_format fmt;

  // Verifies the correct offset is calculated for each type in the type_list.
  size_t offsetTotal = 0;

  // Verify the location for all of the intrinsic types
  size_t offset = (Hg::offset_of<0,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
  offsetTotal += sizeof(uint32_t); 

  // Verify the location of the Nested structure
  offset = (Hg::offset_of<1,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
  offsetTotal += Hg::size_of<Hg::Basic_format>::value;

  offset = (Hg::offset_of<2,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
  offsetTotal += sizeof(uint16_t); 
  offset = (Hg::offset_of<3,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
  offsetTotal += sizeof(uint8_t); 
  offset = (Hg::offset_of<4,fmt>::value);
  TS_ASSERT_EQUALS(offsetTotal, offset);
  offsetTotal += sizeof(uint8_t); 
}

//  ****************************************************************************
void TestMeta::TestBitSet_constructor()
{
  // Test two types
  // Type A uses a single 8-bit value
  value_type_a A_val = 0;
  TypeA sut_a(A_val);
  TS_ASSERT_EQUALS(A_val, sut_a);

  // Type B uses a 32-bit value
  value_type_b B_val = 101;
  TypeB sut_b(B_val);
  TS_ASSERT_EQUALS(B_val, sut_b);
}

//  ****************************************************************************
void TestMeta::TestBitSet_conversion()
{
  value_type_a A_val = 0;
  TypeA sut(A_val);

  value_type_a result = sut;
  TS_ASSERT_EQUALS(A_val, result);
}

//  ****************************************************************************
void TestMeta::TestBitSet_assignment_BitSet()
{
  value_type_a        sut_val   = 0;
  TypeA               sut   (sut_val);

  const value_type_a  k_control = 225;

  // This value will act as the buffer for the bit set field.
  value_type_a        A_val     = k_control;
  TypeA               bits_a(A_val);

  // SUT
  sut                 = bits_a;
  value_type_a result = sut;
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestMeta::TestBitSet_assignment_value_type()
{
  const value_type_a  k_control = 192;
  value_type_a        A_val     = 0;
  TypeA bits_a(A_val);

  // SUT
  bits_a = k_control;
  TS_ASSERT_EQUALS(k_control, bits_a);
}

//  ****************************************************************************
void TestMeta::TestBitSet_size()
{
  // Type A is based on a 1-byte value
  TS_ASSERT_EQUALS(sizeof(uint8_t),  TypeA::size());
  // Type B is based on a 4-byte value
  TS_ASSERT_EQUALS(sizeof(uint32_t), TypeB::size());
}

//  ****************************************************************************
void TestMeta::TestForEach()
{
  // TODO: Revisit to implement a test that iterates over a type_list
}



#endif
