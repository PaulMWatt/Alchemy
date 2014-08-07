/// @file TestDynamicMessageSuite.hpp
/// 
/// This test suite verifies the msg Template which provides the capability to 
/// interface with a binary buffer with a formatted msg definition.
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
#ifndef TEST_DYNAMIC_MESSAGE_SUITE_H_INCLUDED
#define TEST_DYNAMIC_MESSAGE_SUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <msgtest_typelist.h>
#include <Hg.h>
#include <algorithm>

namespace Hg
{


//  ****************************************************************************
//  A type list used to create a basic message with a dynamic value.
// 
typedef TypeList
<
  uint32_t,
  uint32_t,
  uint32_t,
  std::array<uint32_t,20>
> no_dyn_format_t;

HG_BEGIN_FORMAT(no_dyn_format_t)
  HG_DATUM (uint32_t,                 word_0)
  HG_DATUM (uint32_t,                 word_1)
  HG_DATUM (uint32_t,                 word_2)
  HG_DATUM ((std::array<uint32_t,20>),  arry_3)
HG_END_FORMAT

typedef no_dyn_format_tFormat<0> no_dyn_type;

//  ****************************************************************************
//  A type list used to create a basic message with a dynamic value.
// 
typedef TypeList
<
  uint32_t,
  uint32_t,
  std::vector<uint16_t>,
  uint32_t
> dyn_basic_format_t;

HG_BEGIN_FORMAT(dyn_basic_format_t)
  HG_DATUM (uint32_t,                 word_0)
  HG_DATUM (uint32_t,                 word_1)
  HG_DATUM ((std::vector<uint16_t>),  seq_16)
  HG_DATUM (uint32_t,                 word_2)
HG_END_FORMAT

typedef dyn_basic_format_tFormat<0> dyn_basic_type;

//  ****************************************************************************
//  A type list used to create the base message field.
// 
typedef TypeList
<
  uint8_t,
  uint8_t,
  uint8_t,
  uint8_t,
  uint32_t,
  std::vector<uint8_t>,
  std::vector<uint16_t>,
  uint32_t,
  std::vector<uint32_t>,
  std::vector<uint64_t>,
  uint32_t
> dyn_test_format_t;

HG_BEGIN_FORMAT(dyn_test_format_t)
  HG_DATUM    (uint8_t,                  size_8)
  HG_DATUM    (uint8_t,                  size_16)
  HG_DATUM    (uint8_t,                  size_32)
  HG_DATUM    (uint8_t,                  size_64)
  HG_DATUM    (uint32_t,                 word_0)
  HG_DYN_DATUM((std::vector<uint8_t>),   seq_8,  size_8)
  HG_DYN_DATUM((std::vector<uint16_t>),  seq_16, size_16)
  HG_DATUM    (uint32_t,                 word_1)
  HG_DYN_DATUM((std::vector<uint32_t>),  seq_32, size_32)
  HG_DYN_DATUM((std::vector<uint64_t>),  seq_64, size_64)
  HG_DATUM    (uint32_t,                 word_2)
HG_END_FORMAT

typedef dyn_test_format_tFormat<0> dyn_message_type;

} // namespace Hg

//  ****************************************************************************
/// @brief TestDynamicMessageSuite Test Suite class.
///
class TestDynamicMessageSuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::dyn_test_format_t, Hg::BufferedStoragePolicy >
{
public:

  TestDynamicMessageSuite()
  { 
    char buffer[] = "Hello World, This is a test";

    ::memcpy(seq_8,  buffer, sizeof(seq_8));  
    ::memcpy(seq_16, buffer, sizeof(seq_16));  
    ::memcpy(seq_32, buffer, sizeof(seq_32));  
    ::memcpy(seq_64, buffer, sizeof(seq_64));  

    ::memcpy(other_seq_8,  seq_8, sizeof(other_seq_8));  

    other_seq_16[0] = Hg::EndianSwap(seq_16[0]);
    other_seq_16[1] = Hg::EndianSwap(seq_16[1]);
    other_seq_16[2] = Hg::EndianSwap(seq_16[2]);
    other_seq_16[3] = Hg::EndianSwap(seq_16[3]);
    other_seq_16[4] = Hg::EndianSwap(seq_16[4]);
    other_seq_16[5] = Hg::EndianSwap(seq_16[5]);

    other_seq_32[0] = Hg::EndianSwap(seq_32[0]);
    other_seq_32[1] = Hg::EndianSwap(seq_32[1]);
    other_seq_32[2] = Hg::EndianSwap(seq_32[2]);

    other_seq_64[0] = Hg::EndianSwap(seq_64[0]);
    other_seq_64[1] = Hg::EndianSwap(seq_64[1]);
    other_seq_64[2] = Hg::EndianSwap(seq_64[2]);
  }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  { }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  { }

protected:
  //  Constants ******************************************************************
  static const uint32_t  k_word_0               = 0xDEADC0DE;
  static const uint32_t  k_other_word_0         = 0xDEC0ADDE;
  static const uint32_t  k_word_1               = 0x12345678;
  static const uint32_t  k_other_word_1         = 0x78563412;
  static const uint32_t  k_word_2               = 0xABCDEF00;
  static const uint32_t  k_other_word_2         = 0x00EFCDAB;



  static const uint32_t  k_word_3               = 0x600DEA45;
  static const uint32_t  k_other_word_3         = 0x45EA0D60;
  static const uint32_t  k_word_4               = 0x0B13553D;
  static const uint32_t  k_other_word_4         = 0x3D55130B;
  static const uint32_t  k_word_5               = 0x0C1A5500;
  static const uint32_t  k_other_word_5         = 0x00551A0C;
  static const uint32_t  k_word_6               = 0x0DEFEA40;
  static const uint32_t  k_other_word_6         = 0x40EAEF0D;

  static const size_t k_count_seq_8  = 11;
  static const size_t k_count_seq_16 = 6;
  static const size_t k_count_seq_32 = 3;
  static const size_t k_count_seq_64 = 3;

  uint8_t   seq_8[k_count_seq_8];
  uint16_t  seq_16[k_count_seq_16];
  uint32_t  seq_32[k_count_seq_32];
  uint64_t  seq_64[k_count_seq_64];

  uint8_t   other_seq_8[k_count_seq_8];
  uint16_t  other_seq_16[k_count_seq_16];
  uint32_t  other_seq_32[k_count_seq_32];
  uint64_t  other_seq_64[k_count_seq_64];

  // With the current test structure, the SUT format uses 75 bytes.
  static const size_t k_sut_msg_size = 75;

  uint8_t   packed_msg[k_sut_msg_size];
  uint8_t   other_packed_msg[k_sut_msg_size];
 

  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different msg field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::BufferedStoragePolicy                         storage_type;
  typedef Hg::dyn_message_type                              msg_type;
  typedef Hg::Message<msg_type>                             SUT;
  typedef Hg::Message<msg_type, Hg::NetByteOrder>           SUT_net_order;
  typedef Hg::Message<msg_type, Hg::BigEndian>              SUT_big_endian;
  typedef Hg::Message<msg_type, Hg::LittleEndian>           SUT_little_endian;

  typedef storage_type::data_type                           data_type;
  typedef storage_type::s_pointer                           s_pointer;

  // Helper Functions ************************************************************
  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateBaseValues(SUT_t& msg)
  {
    msg.size_8       = k_count_seq_8;
    msg.size_16      = k_count_seq_16;
    msg.size_32      = k_count_seq_32;
    msg.size_64      = k_count_seq_64;

    msg.word_0       = k_word_0;
    msg.word_1       = k_word_1;
    msg.word_2       = k_word_2;

    uint8_t* seq8_first = &seq_8[0];
    uint8_t* seq8_last  = seq8_first;
    std::advance(seq8_last, k_count_seq_8);
    msg.seq_8.assign(seq8_first, seq8_last);

    uint16_t* seq16_first = &seq_16[0];
    uint16_t* seq16_last  = seq16_first;
    std::advance(seq16_last, k_count_seq_16);
    msg.seq_16.assign(seq16_first, seq16_last);

    uint32_t* seq32_first = &seq_32[0];
    uint32_t* seq32_last  = seq32_first;
    std::advance(seq32_last, k_count_seq_32);
    msg.seq_32.assign(seq32_first, seq32_last);

    uint64_t* seq64_first = &seq_64[0];
    uint64_t* seq64_last  = seq64_first;
    std::advance(seq64_last, k_count_seq_64);
    msg.seq_64.assign(seq64_first, seq64_last);

    // Construct a packed memory array by hand that contains the data
    // buffer that is expected based on the values assigned above.

    ::memset(packed_msg, 0, sizeof(packed_msg));
    uint8_t *pCur = packed_msg;
    
    // size values
    ::memcpy(pCur, &k_count_seq_8, sizeof(k_count_seq_8));
    pCur += sizeof(msg.size_8);

    ::memcpy(pCur, &k_count_seq_16, sizeof(k_count_seq_16));
    pCur += sizeof(msg.size_16);

    ::memcpy(pCur, &k_count_seq_32, sizeof(k_count_seq_32));
    pCur += sizeof(msg.size_32);

    ::memcpy(pCur, &k_count_seq_64, sizeof(k_count_seq_64));
    pCur += sizeof(msg.size_64);

    // data values
    ::memcpy(pCur, &k_word_0, sizeof(k_word_0));
    pCur += sizeof(k_word_0);

    ::memcpy(pCur, &seq_8[0], k_count_seq_8);
    pCur += k_count_seq_8;
    
    size_t seq_16_size = k_count_seq_16 * sizeof(uint16_t);
    ::memcpy(pCur, &seq_16[0], seq_16_size);
    pCur += seq_16_size;    

    ::memcpy(pCur, &k_word_1, sizeof(k_word_1));
    pCur += sizeof(k_word_1);

    size_t seq_32_size = k_count_seq_32 * sizeof(uint32_t);
    ::memcpy(pCur, &seq_32[0], seq_32_size);
    pCur += seq_32_size;
    
    size_t seq_64_size = k_count_seq_64 * sizeof(uint64_t);
    ::memcpy(pCur, &seq_64[0], seq_64_size);
    pCur += seq_64_size;

    ::memcpy(pCur, &k_word_2, sizeof(k_word_2));
    pCur += sizeof(k_word_2);

    // This value is explicitly specified to insure that the 
    // the test is updated if the message buffer is updated.
    TS_ASSERT_EQUALS((pCur - packed_msg), 75)
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
    msg.size_8       = k_count_seq_8;
    msg.size_16      = k_count_seq_16;
    msg.size_32      = k_count_seq_32;
    msg.size_64      = k_count_seq_64;

    msg.word_0       = k_other_word_0;
    msg.word_1       = k_other_word_1;
    msg.word_2       = k_other_word_2;

    uint8_t* seq8_first = &other_seq_8[0];
    uint8_t* seq8_last  = seq8_first;
    std::advance(seq8_last, k_count_seq_8);
    msg.seq_8.assign(seq8_first, seq8_last);

    uint16_t* seq16_first = &other_seq_16[0];
    uint16_t* seq16_last  = seq16_first;
    std::advance(seq16_last, k_count_seq_16);
    msg.seq_16.assign(seq16_first, seq16_last);

    uint32_t* seq32_first = &other_seq_32[0];
    uint32_t* seq32_last  = seq32_first;
    std::advance(seq32_last, k_count_seq_32);
    msg.seq_32.assign(seq32_first, seq32_last);

    uint64_t* seq64_first = &other_seq_64[0];
    uint64_t* seq64_last  = seq64_first;
    std::advance(seq64_last, k_count_seq_64);
    msg.seq_64.assign(seq64_first, seq64_last);

    // Construct a packed memory array by hand that contains the data
    // buffer that is expected based on the values assigned above.

    ::memset(other_packed_msg, 0, sizeof(other_packed_msg));
    uint8_t *pCur = other_packed_msg;
    
    // size values
    ::memcpy(pCur, &k_count_seq_8, sizeof(k_count_seq_8));
    pCur += sizeof(msg.size_8);

    ::memcpy(pCur, &k_count_seq_16, sizeof(k_count_seq_16));
    pCur += sizeof(msg.size_16);

    ::memcpy(pCur, &k_count_seq_32, sizeof(k_count_seq_32));
    pCur += sizeof(msg.size_32);

    ::memcpy(pCur, &k_count_seq_64, sizeof(k_count_seq_64));
    pCur += sizeof(msg.size_64);

    // data values
    ::memcpy(pCur, &k_other_word_0, sizeof(k_other_word_0));
    pCur += sizeof(k_other_word_0);

    ::memcpy(pCur, &other_seq_8[0], k_count_seq_8);
    pCur += k_count_seq_8;
    
    size_t seq_16_size = k_count_seq_16 * sizeof(uint16_t);
    ::memcpy(pCur, &other_seq_16[0], seq_16_size);
    pCur += seq_16_size;    

    ::memcpy(pCur, &k_other_word_1, sizeof(k_other_word_1));
    pCur += sizeof(k_other_word_1);

    size_t seq_32_size = k_count_seq_32 * sizeof(uint32_t);
    ::memcpy(pCur, &other_seq_32[0], seq_32_size);
    pCur += seq_32_size;
    
    size_t seq_64_size = k_count_seq_64 * sizeof(uint64_t);
    ::memcpy(pCur, &other_seq_64[0], seq_64_size);
    pCur += seq_64_size;

    ::memcpy(pCur, &k_other_word_2, sizeof(k_other_word_2));
    pCur += sizeof(k_other_word_2);

    // This value is explicitly specified to insure that the 
    // the test is updated if the message buffer is updated.
    TS_ASSERT_EQUALS((pCur - other_packed_msg), 75)
  }

public:
  // Test Cases ****************************************************************
  // Initial Tests for the dynamic type support functions
  void TestHasDynamic_true(void);
  void TestDynamicFields_none(void);
  void TestDynamicFields_basic(void);
  void TestDynamicFields_message(void);

  // Dynamic Message Tests
  void TestDefaultCtor(void);
  void TestCopyCtor(void);
  void TestValueCtor(void);
  void TestAssignmentOperator(void);
  void Testempty(void);
  void Testempty_false(void);
  void TestSize(void);
  void Testis_host_order(void);
  void Testis_host_order_false(void);
  void TestAssign(void);
  void TestClear(void);
  void TestClone(void);
  void Testdata(void);

  //  Worker Functions *********************************************************
  void Testto_host(void);
  void Testto_network(void);
  void Testto_big_endian(void);
  void Testto_little_endian(void);

  //  Focused Scenario Tests *****************************************************
  void Test_write_nested_at_correct_offset(void);

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


};

//  ****************************************************************************
void TestDynamicMessageSuite::TestHasDynamic_true(void)
{
  // SUT
  bool result = Hg::has_dynamic<msg_type::format_type>::value;
  TS_ASSERT(result);

}

//  ****************************************************************************
void TestDynamicMessageSuite::TestDynamicFields_none(void)
{
  bool result_no    = Hg::has_dynamic<no_dyn_type::format_type>::value;
  TS_ASSERT(!result_no);

  typedef 
    dynamic_fields<no_dyn_type::format_type>::type         reault_type;

  typedef MT   k_control_type;
  bool is_same_type = std::is_same<k_control_type, reault_type>::value;
  TS_ASSERT(is_same_type);
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestDynamicFields_basic(void)
{
  bool result_basic = Hg::has_dynamic<dyn_basic_type::format_type>::value;
  TS_ASSERT(result_basic);

  typedef 
    dynamic_fields<dyn_basic_type::format_type>::type      result_type;

  typedef integer_sequence<2>::type   k_control_type;
  bool is_same_type = std::is_same<k_control_type, result_type>::value;
  TS_ASSERT(is_same_type);
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestDynamicFields_message(void)
{
  bool result_msg   = Hg::has_dynamic<dyn_message_type::format_type>::value;
  TS_ASSERT(result_msg);

  typedef 
    dynamic_fields<dyn_message_type::format_type>::type    result_type;

  typedef integer_sequence<5,6,8,9>::type   k_control_type;
  bool is_same_type = std::is_same<k_control_type, result_type>::value;

  TS_ASSERT(is_same_type);
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestDefaultCtor(void)
{
  // SUT
  SUT sut;

  // The msg buffer should not exist.
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestCopyCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);

  // SUT
  SUT sut(rhs);
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestValueCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);
  // SUT
  SUT sut(rhs.data(), rhs.size());
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestAssignmentOperator(void)
{
  SUT                rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs;
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testempty(void)
{
  // SUT
  SUT sut;
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testempty_false(void)
{
  // SUT
  SUT sut(get_buffer().get(), get_length());
  TS_ASSERT(!sut.empty());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestSize(void)
{
  // SUT
  SUT sut;
  sut.size<true>();

  TS_ASSERT_EQUALS(Hg::SizeOf<SUT::format_type>::value, sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testis_host_order(void)
{
  // SUT: Host order is defined within the type itself.
  //      Look at the typedef for details
  SUT sut;
  TS_ASSERT(sut.is_host_order());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testis_host_order_false(void)
{
  // SUT: Net order is defined within the type itself. 
  //      Look at the typedef for details
  SUT_net_order sut;
  TS_ASSERT(!sut.is_host_order());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestAssign(void)
{
  SUT expected;
  PopulateBaseValues(expected);

  // SUT
  SUT sut;
  sut.assign(expected.data(), expected.size());

  TS_ASSERT_EQUALS(expected.size(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestClear(void)
{
  SUT sut(get_buffer().get(), get_length());
  TS_ASSERT(!sut.empty());

  // SUT
  sut.clear();

  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestClone(void)
{
  SUT rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs.clone();

  TS_ASSERT_SAME_DATA(packed_msg, rhs.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testdata(void)
{
  SUT sut;
  sut.size_8       = k_count_seq_8;
  sut.size_16      = k_count_seq_16;
  sut.size_32      = k_count_seq_32;
  sut.size_64      = k_count_seq_64;

  sut.word_0       = k_word_0;
  sut.word_1       = k_word_1;
  sut.word_2       = k_word_2;

  // allocate and copy with the vector assign
  uint8_t* seq8_first = &seq_8[0];
  uint8_t* seq8_last  = seq8_first;
  std::advance(seq8_last, k_count_seq_8);
  sut.seq_8.assign(seq8_first, seq8_last);

  // grow incrementally with push_back for each element.
  sut.seq_16.push_back(seq_16[0]);
  sut.seq_16.push_back(seq_16[1]);
  sut.seq_16.push_back(seq_16[2]);
  sut.seq_16.push_back(seq_16[3]);
  sut.seq_16.push_back(seq_16[4]);
  sut.seq_16.push_back(seq_16[5]);

  // Allocate the memory up front.
  sut.seq_32.resize(k_count_seq_32);
  sut.seq_32[0] = seq_32[0];
  sut.seq_32[1] = seq_32[1];
  sut.seq_32[2] = seq_32[2];

  sut.seq_64.resize(k_count_seq_64);
  sut.seq_64[0] = seq_64[0];
  sut.seq_64[1] = seq_64[1];
  sut.seq_64[2] = seq_64[2];

  TS_ASSERT_EQUALS(k_sut_msg_size, sut.size());
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testto_host(void)
{
  // Populate the expected results.
  SUT_net_order expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_net_order sut;
  PopulateBaseValues(sut);

  SUT no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT result = to_host(sut);
  SUT no_op_result = to_host(no_op_sut);

  TS_ASSERT_SAME_DATA(other_packed_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_packed_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testto_network(void)
{
  // Populate the expected results.
  SUT expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT sut;
  PopulateBaseValues(sut);

  SUT_net_order no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_net_order result = to_network(sut);
  SUT_net_order no_op_result = to_network(no_op_sut);

  TS_ASSERT_SAME_DATA(other_packed_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_packed_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testto_big_endian(void)
{
  // Populate the expected results.
  SUT expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_little_endian sut;
  PopulateBaseValues(sut);

  SUT_big_endian no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_big_endian result = to_big_endian(sut);
  SUT_big_endian no_op_result = to_big_endian(no_op_sut);

  TS_ASSERT_SAME_DATA(other_packed_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_packed_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testto_little_endian(void)
{
  // Populate the expected results.
  SUT expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_big_endian sut;
  PopulateBaseValues(sut);

  SUT_little_endian no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_little_endian result        = to_little_endian(sut);
  SUT_little_endian no_op_result  = to_little_endian(no_op_sut);

  TS_ASSERT_SAME_DATA(other_packed_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_packed_msg, no_op_result.data(), no_op_sut.size());
}


//  ****************************************************************************
//  Focused Scenario Tests *****************************************************
//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_nested_at_correct_offset(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_vector_with_nested_fixed_size(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_vector_with_nested_fixed_size(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_vector_with_nested_dynamic_size(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_vector_with_nested_dynamic_size(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_vector_with_nested_mixed_size(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_vector_with_nested_mixed_size(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_array_of_bitsets(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_array_of_bitsets(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_array_of_arrays(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_array_of_arrays(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_array_of_vectors(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_array_of_vectors(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_vector_of_bitsets(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_vector_of_bitsets(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_vector_of_arrays(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_vector_of_arrays(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_write_vector_of_vectors(void)
{

}

//  ****************************************************************************
void TestDynamicMessageSuite::Test_read_vector_of_vectors(void)
{

}


#endif
