/// @file TestDynamicMessageSuite.hpp
/// 
/// This test suite verifies the msg Template which provides the capability to interface with a binary buffer with a formatted msg definition.
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
  uint32_t
> no_dyn_format_t;

HG_BEGIN_FORMAT(no_dyn_format_t)
  HG_DATUM (uint32_t,                 word_0)
  HG_DATUM (uint32_t,                 word_1)
  HG_DATUM (uint32_t,                 word_2)
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
  uint32_t,
  std::vector<uint8_t>,
  std::vector<uint16_t>,
  uint32_t,
  std::vector<uint32_t>,
  std::vector<uint64_t>,
  uint32_t
> dyn_test_format_t;

HG_BEGIN_FORMAT(dyn_test_format_t)
  HG_DATUM (uint32_t,                 word_0)
  HG_DATUM ((std::vector<uint8_t>),   seq_8)
  HG_DATUM ((std::vector<uint16_t>),  seq_16)
  HG_DATUM (uint32_t,                 word_1)
  HG_DATUM ((std::vector<uint32_t>),  seq_32)
  HG_DATUM ((std::vector<uint64_t>),  seq_64)
  HG_DATUM (uint32_t,                 word_2)
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
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
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

  // Special cases
  void TestSingleFieldMsg_Basic(void);
  void TestSingleFieldMsg_Nested(void);
  void TestSingleFieldMsg_Bitlist(void);

  //  Worker Functions *********************************************************
  void Testto_host(void);
  void Testto_network(void);
  void Testto_big_endian(void);
  void Testto_little_endian(void);
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

  typedef empty   k_control_type;
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

  typedef integer_sequence<1,2,4,5>::type   k_control_type;
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

  // TODO: Last debeggin session determined that the offsets were not being adjusted for the dynamic sizes of the fields.
  // TODO: Modify the tests so the control buffer is hand-generated to the expected result. If both expected and actual are modified by the same logic, this will not detect problems in the logic to verify that it is generating the correct output.

  // SUT
  SUT sut(rhs);
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestValueCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);
  // SUT
  SUT sut(rhs.data(), rhs.size());
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestAssignmentOperator(void)
{
  SUT                rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs;
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), sut.size());
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

  // Verify the contents held in the input buffer were properly assigned to the msg.
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

  TS_ASSERT_SAME_DATA(sut.data(), rhs.data(), sut.size());
}

//  ****************************************************************************
void TestDynamicMessageSuite::Testdata(void)
{
  // TODO: Add code to test that values are set to the interface, and can be read out of the data call.

  //SUT sut;
  //s_pointer spBuffer = get_buffer();
  //TS_ASSERT(sut.empty());

  //// SUT
  //SUT::buffer_type buffer = sut.buffer();
  //TS_ASSERT(buffer.empty());

  //// SUT
  //sut.assign(spBuffer.get(), 0);
  //buffer = sut.buffer();
  //TS_ASSERT(!buffer.empty());
  //TS_ASSERT_EQUALS(spBuffer, buffer.buffer());
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestSingleFieldMsg_Basic(void)
{
  typedef single_tFormat<0> SingleMsg;

  SingleMsg sut;
  sut.only = 1001;

  TS_ASSERT_EQUALS(1001, sut.only);
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestSingleFieldMsg_Nested(void)
{
  typedef single_nested_tFormat<0> SingleMsg;

  SingleMsg sut;
  sut.only.zero = 255;

  TS_ASSERT_EQUALS(255, sut.only.zero);
}

//  ****************************************************************************
void TestDynamicMessageSuite::TestSingleFieldMsg_Bitlist(void)
{
  typedef single_bit_tFormat<0> SingleMsg;

  SingleMsg sut;
  sut.only.lonely = 3;

  TS_ASSERT_EQUALS(1, sut.only.lonely);
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

  TS_ASSERT_SAME_DATA(expected.data(), result.data(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), no_op_result.data(), no_op_sut.size());
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

  TS_ASSERT_SAME_DATA(expected.data(), result.data(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), no_op_result.data(), no_op_sut.size());
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

  TS_ASSERT_SAME_DATA(expected.data(), result.data(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), no_op_result.data(), no_op_sut.size());
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

  TS_ASSERT_SAME_DATA(expected.data(), result.data(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), no_op_result.data(), no_op_sut.size());
}


#endif
