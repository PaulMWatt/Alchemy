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
#include <alchemy.h>
#include <test_def.h>
#include <detail/multival_data.h>

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
  typedef Hg::Format_bitlist<0, Hg::Bitset_format>::type   TypeA;
  typedef TypeA::value_type                                          value_type_a;

  typedef Hg::Format_bitlist<1, Hg::Bitset_format>::type   TypeB;
  typedef TypeB::value_type                                          value_type_b;

public:
  //  Test Cases ***************************************************************
  //  Test Meta-conditional constructs *****************************************
  void Test_value_if_true(void);
  void Test_value_if_false(void);
  void Test_one_or_zero_1(void);
  void Test_one_or_zero_0(void);

  //  Test Compile-time checks *************************************************
  void Test_type_check(void);

  //  Boolean Operations *******************************************************
  void Test_not_true(void);
  void Test_not_false(void);
  void Test_and_true(void);
  void Test_and_false(void);
  void Test_or_true(void);
  void Test_or_false(void);

  //  Test type_container ******************************************************
  //  Parameterized version
  void Test_type_container_T(void);

  // Specializations
  void Test_type_container_empty(void);
  void Test_type_container_TypeList(void);
  void Test_type_container_traits(void);

  // Test ContainerSize ********************************************************
  void TestContainerSize(void);

  // Test length, TypeContainer item count *************************************
//  void Test_length(void);

  // TypeAt Template Tests *****************************************************
  void TestTypeAt_1_to_max(void);

  // SizeOf Template Tests *****************************************************
  // Verify the intrinsic types
  void TestSizeOf_char(void);
  void TestSizeOf_uchar(void);
  void TestSizeOf_short(void);
  void TestSizeOf_ushort(void);
  void TestSizeOf_long(void);
  void TestSizeOf_ulong(void);
  void TestSizeOf_float(void);
  void TestSizeOf_double(void);

  // Verify the type_containers
  void TestSizeOf_empty(void);
  void TestSizeOf_TypeList(void);
  void TestSizeOf_BitSet(void);
  void TestSizeOf_DynamicValue(void);
  void TestSizeOf_ArrayValue(void);

  // SizeAt Template Tests *****************************************************
  void TestSizeAt_1_to_max(void);

  // OffsetOf Template Tests ***************************************************
  void TestOffsetOf_basic(void);
  void TestOffsetOf_bitset(void);
  void TestOffsetOf_nested(void);

  //  BitSet Body Tests ********************************************************
  void TestBitSet_constructor(void);
  void TestBitSet_conversion(void);
  void TestBitSet_assignment_BitSet(void);
  void TestBitSet_assignment_value_type(void);
  void TestBitSet_size(void);

  //  Static ForEach Tests *****************************************************
  void TestForEach(void);

};

//  ****************************************************************************
//  ****************************************************************************
void TestMeta::Test_value_if_true(void)
{
  // Choose the first value listed:
  const size_t k_control = 1024;
  const size_t k_other   = 123;
  size_t       result    = Hg::value_if<true,size_t,k_control,k_other>::value;

  TS_ASSERT_DIFFERS(k_control, k_other);
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestMeta::Test_value_if_false(void)
{
  // Choose the second value listed:
  const size_t k_control = 1024;
  const size_t k_other   = 123;
  size_t       result    = Hg::value_if<false,size_t,k_other,k_control>::value;

  TS_ASSERT_DIFFERS(k_control, k_other);
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestMeta::Test_one_or_zero_1(void)
{
  const int k_control = 1;
  TS_ASSERT_EQUALS(k_control, (Hg::one_or_zero<true>::value));
}

//  ****************************************************************************
void TestMeta::Test_one_or_zero_0(void)
{
  const int k_control = 0;
  TS_ASSERT_EQUALS(k_control, (Hg::one_or_zero<false>::value));
}  

//  ****************************************************************************
void TestMeta::Test_type_check(void)
{
  // This is a static compilation test.
  // If the unit-test program successfully compiles, this test is a success.
  Hg::type_check<true>;
}

//  ****************************************************************************
void TestMeta::Test_not_true(void)
{
  // SUT
  bool result = Hg::not<std::false_type>::value;
  TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestMeta::Test_not_false(void)
{
  // SUT
  bool result = Hg::not<std::true_type>::value;
  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestMeta::Test_and_true(void)
{
  // SUT
  bool result = Hg::and<std::true_type,
                        std::true_type>::value;
  TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestMeta::Test_and_false(void)
{
  bool result;
  // SUT 1
  result = Hg::and< std::false_type,
                    std::false_type>::value;
  TS_ASSERT_EQUALS(false, result);

  // SUT 2
  result = Hg::and< std::true_type,
                    std::false_type>::value;
  TS_ASSERT_EQUALS(false, result);

  // SUT 3
  result = Hg::and< std::false_type,
                    std::true_type>::value;
  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestMeta::Test_or_true(void)
{
  bool result;
  // SUT 1
  result = Hg::or < std::true_type,
                    std::true_type>::value;
  TS_ASSERT_EQUALS(true, result);

  // SUT 2
  result = Hg::or < std::true_type,
                    std::false_type>::value;
  TS_ASSERT_EQUALS(true, result);

  // SUT 3
  result = Hg::or < std::false_type,
                    std::true_type>::value;
  TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestMeta::Test_or_false(void)
{
  // SUT
  bool result = Hg::or <std::false_type,
                        std::false_type>::value;
  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestMeta::Test_type_container_T(void)
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
void TestMeta::Test_type_container_empty(void)
{
  typedef Hg::MT sut_t;
  TS_ASSERT_EQUALS(false, Hg::type_container<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::Test_type_container_TypeList(void)
{
  // The type array requires an instantiated template type.
  typedef Hg::TypeList<int>                     sut1_t;
  typedef Hg::TypeList<int, double>             sut2_t;
  typedef Hg::TypeList<int, double, ptrdiff_t>  sut3_t;

  TS_ASSERT(Hg::type_container<sut1_t>::value);
  TS_ASSERT(Hg::type_container<sut2_t>::value);
  TS_ASSERT(Hg::type_container<sut3_t>::value);
}

//  ****************************************************************************
void TestMeta::Test_type_container_traits(void)
{
  TS_ASSERT(Hg::type_container<TypeA>::value);
  TS_ASSERT(Hg::type_container<TypeB>::value);
}

//  ****************************************************************************
void TestMeta::TestContainerSize(void)
{
  // Use the pre-declared types for this test.
  // Basic_format
  const size_t k_control1 = sizeof(Hg::TypeAt<0, Hg::Basic_format>::type)
                          + sizeof(Hg::TypeAt<1, Hg::Basic_format>::type)
                          + sizeof(Hg::TypeAt<2, Hg::Basic_format>::type)
                          + sizeof(Hg::TypeAt<3, Hg::Basic_format>::type);
  TS_ASSERT_EQUALS(k_control1, Hg::ContainerSize<Hg::Basic_format>::value);

  //  This section contains type_containers ************************************
  // type_containers must use SizeOf<> or ContainerSize<> to determine the
  // actual buffer size required. Otherwise, there total object size is reported.

  // Compound_format
  const size_t k_control2 = sizeof(Hg::TypeAt<0, Hg::Compound_format>::type)
                          + sizeof(Hg::TypeAt<1, Hg::Compound_format>::type)
                          + sizeof(Hg::TypeAt<2, Hg::Compound_format>::type)
                          + Hg::SizeOf<Hg::TypeAt<3, Hg::Compound_format>::type>::value
                          + Hg::SizeOf<Hg::TypeAt<4, Hg::Compound_format>::type>::value;
  TS_ASSERT_EQUALS(k_control2, Hg::ContainerSize<Hg::Compound_format>::value);

  // Nested_compound_format
  const size_t k_control3 = sizeof(Hg::TypeAt<0, Hg::Nested_compound_format>::type)
    + Hg::SizeOf<Hg::TypeAt<1, Hg::Nested_compound_format>::type>::value;
  TS_ASSERT_EQUALS(k_control3, Hg::ContainerSize<Hg::Nested_compound_format>::value);

}

//  ****************************************************************************
void TestMeta::TestTypeAt_1_to_max(void)
{
  // This test declares a TypeList with a unique type for each potential
  // index in the array up to the max elements.
  typedef Hg::TypeList< char,   unsigned char,  short,  unsigned short,
                          int,    unsigned int,   long,   unsigned long,
                          float,  double,         size_t, ptrdiff_t,
                          char*,  const char*,    char&,  const char&,
                          short*, const short*,   short&, const short&,
                          int*,   const int*,     int&,   const int&,
                          long*,  const long*,    long&,  const long&,
                          float*, const float*,   float&, const float&
                        > sut_t;

  // Each assertion verifies the type at the the requested index
  // matches the type encoded into the TypeList.
  TS_ASSERT((std::is_same<char,            Hg::TypeAt<0,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned char,   Hg::TypeAt<1,sut_t>::type>::value));
  TS_ASSERT((std::is_same<short,           Hg::TypeAt<2,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned short,  Hg::TypeAt<3,sut_t>::type>::value));
                                                                                
  TS_ASSERT((std::is_same<int,             Hg::TypeAt<4,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned int,    Hg::TypeAt<5,sut_t>::type>::value));
  TS_ASSERT((std::is_same<long,            Hg::TypeAt<6,sut_t>::type>::value));
  TS_ASSERT((std::is_same<unsigned long,   Hg::TypeAt<7,sut_t>::type>::value));
                                                                                
  TS_ASSERT((std::is_same<float,           Hg::TypeAt<8,sut_t>::type>::value));
  TS_ASSERT((std::is_same<double,          Hg::TypeAt<9,sut_t>::type>::value));
  TS_ASSERT((std::is_same<size_t,          Hg::TypeAt<10,sut_t>::type>::value));
  TS_ASSERT((std::is_same<ptrdiff_t,       Hg::TypeAt<11,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<char*,           Hg::TypeAt<12,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const char*,     Hg::TypeAt<13,sut_t>::type>::value));
  TS_ASSERT((std::is_same<char&,           Hg::TypeAt<14,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const char&,     Hg::TypeAt<15,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<short*,          Hg::TypeAt<16,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const short*,    Hg::TypeAt<17,sut_t>::type>::value));
  TS_ASSERT((std::is_same<short&,          Hg::TypeAt<18,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const short&,    Hg::TypeAt<19,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<int*,            Hg::TypeAt<20,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const int*,      Hg::TypeAt<21,sut_t>::type>::value));
  TS_ASSERT((std::is_same<int&,            Hg::TypeAt<22,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const int&,      Hg::TypeAt<23,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<long*,           Hg::TypeAt<24,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const long*,     Hg::TypeAt<25,sut_t>::type>::value));
  TS_ASSERT((std::is_same<long&,           Hg::TypeAt<26,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const long&,     Hg::TypeAt<27,sut_t>::type>::value));
                                                                                  
  TS_ASSERT((std::is_same<float*,          Hg::TypeAt<28,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const float*,    Hg::TypeAt<29,sut_t>::type>::value));
  TS_ASSERT((std::is_same<float&,          Hg::TypeAt<30,sut_t>::type>::value));
  TS_ASSERT((std::is_same<const float&,    Hg::TypeAt<31,sut_t>::type>::value));
}

//  ****************************************************************************
void TestMeta::TestSizeOf_char(void)
{
  typedef char sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_uchar(void)
{
  typedef unsigned char sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_short(void)
{
  typedef short sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_ushort(void)
{
  typedef unsigned short sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_long(void)
{
  typedef long sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_ulong(void)
{
  typedef unsigned long sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_float(void)
{
  typedef float sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_double(void)
{
  typedef double sut_t;
  TS_ASSERT_EQUALS(sizeof(sut_t), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_empty(void)
{
  typedef Hg::MT sut_t;
  TS_ASSERT_EQUALS(1, Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_TypeList(void)
{
  typedef Hg::TypeList<int, double, ptrdiff_t> sut_t;
  const size_t k_control  = sizeof(int)
                          + sizeof(double)
                          + sizeof(ptrdiff_t);

  // SUT
  TS_ASSERT_EQUALS(k_control, Hg::SizeOf<sut_t>::value);
  TS_ASSERT_EQUALS(sizeof(sut_t::type), Hg::SizeOf<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_BitSet(void)
{
  typedef Hg::Bits_type_a sut_t;
  const size_t k_control  = sizeof(Hg::Bits_type_a::value_type);

  // SUT
  TS_ASSERT_EQUALS(true,      Hg::type_container<sut_t>::value);
  TS_ASSERT_EQUALS(k_control, Hg::SizeOf<sut_t>::value);
  TS_ASSERT_EQUALS(k_control, Hg::ContainerSize<sut_t>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_DynamicValue(void)
{
  typedef std::vector<char>                     char_vec;
  typedef std::vector<double>                   double_vec;
  typedef std::vector<std::array<char, 32> >    char_array_vec;

  // Dynamically sized values return 0 for their static size.
  // All size calculations are performed at runtime for these field types.
  size_t size_char = SizeOf<char_vec>::value;
  TS_ASSERT_EQUALS(0, size_char);

  size_t size_double = SizeOf<char_vec>::value;
  TS_ASSERT_EQUALS(0, size_double);

  size_t size_array = SizeOf<char_vec>::value;
  TS_ASSERT_EQUALS(0, size_array);
}

//  ****************************************************************************
void TestMeta::TestSizeOf_ArrayValue(void)
{
  typedef Hg::array_n<size_t, 10>              sut;

  const size_t k_control = sizeof(size_t)* 10;

  // SUT
  TS_ASSERT_EQUALS(k_control, Hg::SizeOf<sut>::value);

  // The standard array object is not guaranteed to be the same
  // size as a basic array allocated with the same time and count.
  // Therefore, this test is not valid.
  //    TS_ASSERT_EQUALS(sizeof(sut), Hg::SizeOf<sut>::value);
}

//  ****************************************************************************
void TestMeta::TestSizeAt_1_to_max(void)
{
  // This test declares a TypeList with a unique type for each potential
  // index in the array up to the max elements.
  typedef Hg::TypeList < char,   unsigned char,  short,  unsigned short,
                          int,    unsigned int,   long,   unsigned long,
                          float,  double,         size_t, ptrdiff_t,
                          char*,  const char*,    char&,  const char&,
                          short*, const short*,   short&, const short&,
                          int*,   const int*,     int&,   const int&,
                          long*,  const long*,    long&,  const long&,
                          float*, const float*,   float&, const float&
                        > sut_t;

  // Each assertion verifies the size of type at the the requested index
  // matches the size of the type encoded into the TypeList.
  TS_ASSERT_EQUALS(sizeof(char),            (Hg::SizeAt<0,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(unsigned char),   (Hg::SizeAt<1,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(short),           (Hg::SizeAt<2,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(unsigned short),  (Hg::SizeAt<3,sut_t>::value));

  TS_ASSERT_EQUALS(sizeof(int),             (Hg::SizeAt<4,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(unsigned int),    (Hg::SizeAt<5,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(long),            (Hg::SizeAt<6,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(unsigned long),   (Hg::SizeAt<7,sut_t>::value));

  TS_ASSERT_EQUALS(sizeof(float),           (Hg::SizeAt<8,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(double),          (Hg::SizeAt<9,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(size_t),          (Hg::SizeAt<10,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(ptrdiff_t),       (Hg::SizeAt<11,sut_t>::value));

  TS_ASSERT_EQUALS(sizeof(char*),           (Hg::SizeAt<12,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const char*),     (Hg::SizeAt<13,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(char&),           (Hg::SizeAt<14,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const char&),     (Hg::SizeAt<15,sut_t>::value));

  TS_ASSERT_EQUALS(sizeof(short*),          (Hg::SizeAt<16,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const short*),    (Hg::SizeAt<17,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(short&),          (Hg::SizeAt<18,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const short&),    (Hg::SizeAt<19,sut_t>::value));

  TS_ASSERT_EQUALS(sizeof(int*),            (Hg::SizeAt<20,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const int*),      (Hg::SizeAt<21,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(int&),            (Hg::SizeAt<22,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const int&),      (Hg::SizeAt<23,sut_t>::value));

  TS_ASSERT_EQUALS(sizeof(long*),           (Hg::SizeAt<24,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const long*),     (Hg::SizeAt<25,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(long&),           (Hg::SizeAt<26,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const long&),     (Hg::SizeAt<27,sut_t>::value));

  TS_ASSERT_EQUALS(sizeof(float*),          (Hg::SizeAt<28,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const float*),    (Hg::SizeAt<29,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(float&),          (Hg::SizeAt<30,sut_t>::value));
  TS_ASSERT_EQUALS(sizeof(const float&),    (Hg::SizeAt<31,sut_t>::value));
}

//  ****************************************************************************
void TestMeta::TestOffsetOf_basic(void)
{
  typedef Hg::Basic_format fmt;

  // Verifies the correct offset is calculated for each type in the TypeList.
  size_t offsetTotal = 0;

  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<0,fmt>::value));
  offsetTotal += sizeof(uint8_t); 
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<1,fmt>::value));
  offsetTotal += sizeof(uint8_t);
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<2,fmt>::value));
  offsetTotal += sizeof(uint16_t);
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<3,fmt>::value));
}

//  ****************************************************************************
void TestMeta::TestOffsetOf_bitset(void)
{
  typedef Hg::Bitset_format fmt;

  // Verifies the correct offset is calculated for each type in the TypeList.
  size_t offsetTotal = 0;

  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<0,fmt>::value));
  offsetTotal += sizeof(Hg::Bits_type_a::value_type); 
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<1,fmt>::value));
  offsetTotal += sizeof(Hg::Bits_type_b::value_type);

  // Verify the final size is the sum of all of the offsets.
  TS_ASSERT_EQUALS(offsetTotal, (Hg::SizeOf<fmt>::value));
}

//  ****************************************************************************
void TestMeta::TestOffsetOf_nested(void)
{
  typedef Hg::Nested_format fmt;

  // Verifies the correct offset is calculated for each type in the TypeList.
  size_t offsetTotal = 0;

  // Verify the location for all of the intrinsic types
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<0,fmt>::value));
  offsetTotal += sizeof(uint32_t); 

  // Verify the location of the Nested structure
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<1,fmt>::value));
  offsetTotal += Hg::SizeOf<Hg::Basic_format>::value;

  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<2,fmt>::value));
  offsetTotal += sizeof(uint16_t); 
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<3,fmt>::value));
  offsetTotal += sizeof(uint8_t); 
  TS_ASSERT_EQUALS(offsetTotal, (Hg::OffsetOf<4,fmt>::value));
  offsetTotal += sizeof(uint8_t); 
}

//  ****************************************************************************
void TestMeta::TestBitSet_constructor(void)
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
void TestMeta::TestBitSet_conversion(void)
{
  value_type_a A_val = 0;
  TypeA sut(A_val);

  value_type_a result = sut;
  TS_ASSERT_EQUALS(A_val, result);
}

//  ****************************************************************************
void TestMeta::TestBitSet_assignment_BitSet(void)
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
void TestMeta::TestBitSet_assignment_value_type(void)
{
  const value_type_a  k_control = 192;
  value_type_a        A_val     = 0;
  TypeA bits_a(A_val);

  // SUT
  bits_a = k_control;
  TS_ASSERT_EQUALS(k_control, bits_a);
}

//  ****************************************************************************
void TestMeta::TestBitSet_size(void)
{
  // Type A is based on a 1-byte value
  TS_ASSERT_EQUALS(sizeof(uint8_t),  TypeA::size());
  // Type B is based on a 4-byte value
  TS_ASSERT_EQUALS(sizeof(uint32_t), TypeB::size());
}

//  ****************************************************************************
void TestMeta::TestForEach(void)
{
  // TODO: Revisit to implement a test that iterates over a TypeList
}



#endif
