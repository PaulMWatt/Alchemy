/// @file TestMessageSuite.hpp
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
#ifndef TEST_MESSAGE_SUITE_H_INCLUDED
#define TEST_MESSAGE_SUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <msgtest_typelist.h>
#include <Hg.h>
#include <algorithm>

namespace Hg
{

HG_BEGIN_FORMAT(base_format_t)
  HG_DATUM (uint32_t,                 word_0)
  HG_DATUM (uint32_t,                 word_1)
  HG_DATUM (uint32_t,                 word_2)
  HG_DATUM (uint8_t,                  val)
  HG_DATUM (nested_format_t,          nested)
  HG_ARRAY (uint32_t, 3,              sequence)
HG_END_FORMAT(base_format_t)

typedef base_format_t_HgFormat    message_type;

} // namespace Hg

//  ****************************************************************************
/// @brief TestMessageSuite Test Suite class.
///
class TestMessageSuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::base_format_t, Hg::BufferedStoragePolicy >
{
public:

  TestMessageSuite()
  { }

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
  static const uint8_t   k_byte                 = 0xB1;
  static const uint32_t  k_bits_value           = 0x0DEC0DED;   
  static const uint32_t  k_other_bits_value     = 0xED0DEC0D;

  static const uint32_t  k_bits_0               = 0xCC;       // 5  bits
  static const uint32_t  k_bits_1               = 0xA;        // 4  bits
  static const uint32_t  k_bits_2               = 0x7;        // 3  bits
  static const uint32_t  k_bits_3               = 0x6;        // 2  bits
  static const uint32_t  k_bits_4               = 0x1;        // 1  bit
  static const uint32_t  k_bits_5               = 0x1234;     // 16 bits
  static const uint32_t  k_bits_6               = 0x3;        // 1  bit;

  static const uint8_t   k_zero                 = 0xA7;
  static const uint16_t  k_one                  = 0xCE11;
  static const uint16_t  k_other_one            = 0x11CE;
  static const uint32_t  k_three                = 0x00112233;
  static const uint32_t  k_other_three          = 0x33221100;
  static const int16_t   k_four                 = int16_t(0xF00D);
  static const int16_t   k_other_four           = 0x0DF0;

  static const size_t    k_seq_0                = 0xFEE1600D;
  static const size_t    k_seq_1                = 0x0FEE1BAD;
  static const size_t    k_seq_2                = 0x0FEE101D;

  static const size_t    k_other_seq_0          = 0x0D60E1FE;
  static const size_t    k_other_seq_1          = 0xAD1BEE0F;
  static const size_t    k_other_seq_2          = 0x1D10EE0F;

  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different msg field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::BufferedStoragePolicy                             storage_type;
  typedef Hg::message_type                                      msg_type;
  typedef Hg::MessageT<msg_type>                                SUT;
  typedef Hg::Message<Hg::MessageT<msg_type>, Hg::BigEndian>    SUT_big_endian;
  typedef Hg::Message<Hg::MessageT<msg_type>, Hg::LittleEndian> SUT_little_endian;

  typedef storage_type::data_type                               data_type;
  typedef storage_type::s_pointer                               s_pointer;

  // Helper Functions ************************************************************
  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateBaseValues(SUT_t& msg)
  {
    msg.word_0       = k_word_0;
    msg.word_1       = k_word_1;
    msg.word_2       = k_word_2;
    msg.val          = k_byte;
    msg.nested.zero  = k_zero;
    msg.nested.one   = k_one;
    msg.nested.two   = k_bits_value;
    msg.nested.three = k_three;
    msg.nested.four  = k_four;

    msg.sequence[0]  = k_seq_0;
    msg.sequence[1]  = k_seq_1;
    msg.sequence[2]  = k_seq_2;
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
    msg.word_0       = k_other_word_0;
    msg.word_1       = k_other_word_1;
    msg.word_2       = k_other_word_2;
    msg.val          = k_byte;
    msg.nested.zero  = k_zero;
    msg.nested.one   = k_other_one;
    msg.nested.two   = k_other_bits_value;
    msg.nested.three = k_other_three;
    msg.nested.four  = k_other_four;

    msg.sequence[0]  = k_other_seq_0;
    msg.sequence[1]  = k_other_seq_1;
    msg.sequence[2]  = k_other_seq_2;
  }

public:
  // Test Cases ****************************************************************
  void TestHasDynamic_false(void);
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
void TestMessageSuite::TestHasDynamic_false(void)
{
  // SUT
  bool result = Hg::has_dynamic<msg_type::format_type>::value;

  // The msg buffer should not exist.
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestMessageSuite::TestDefaultCtor(void)
{
  // SUT
  SUT sut;

  // The msg buffer should not exist.
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestMessageSuite::TestCopyCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);

  // SUT
  SUT sut(rhs);
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), sut.size());
}

//  ****************************************************************************
void TestMessageSuite::TestValueCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);
  // SUT
  SUT sut(rhs.data(), rhs.size());
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), sut.size());
}

//  ****************************************************************************
void TestMessageSuite::TestAssignmentOperator(void)
{
  SUT                rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs;
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), sut.size());
}

//  ****************************************************************************
void TestMessageSuite::Testempty(void)
{
  // SUT
  SUT sut;
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestMessageSuite::Testempty_false(void)
{
  // SUT
  SUT sut(get_buffer().get(), get_length());
  TS_ASSERT(!sut.empty());
}

//  ****************************************************************************
void TestMessageSuite::TestSize(void)
{
  // SUT
  SUT sut(get_buffer().get(), Hg::SizeOf<SUT::format_type>::value);
  TS_ASSERT_EQUALS(Hg::SizeOf<SUT::format_type>::value, sut.size());
}

//  ****************************************************************************
void TestMessageSuite::Testis_host_order(void)
{
  // SUT: Host order is defined within the type itself.
  //      Look at the typedef for details
  SUT::host_t sut;
  TS_ASSERT(sut.is_host_order());
}

//  ****************************************************************************
void TestMessageSuite::Testis_host_order_false(void)
{
  // SUT: Net order is defined within the type itself. 
  //      Look at the typedef for details
  SUT::net_t sut;
  TS_ASSERT(!sut.is_host_order());
}

//  ****************************************************************************
void TestMessageSuite::TestAssign(void)
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
void TestMessageSuite::TestClear(void)
{
  SUT sut(get_buffer().get(), get_length());
  TS_ASSERT(!sut.empty());

  // SUT
  sut.clear();

  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestMessageSuite::TestClone(void)
{
  SUT rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs.clone();

  TS_ASSERT_SAME_DATA(sut.data(), rhs.data(), sut.size());
}

//  ****************************************************************************
void TestMessageSuite::Testdata(void)
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
void TestMessageSuite::TestSingleFieldMsg_Basic(void)
{
  typedef Hg::single_t_HgFormat SingleMsg;

  SingleMsg sut;
  sut.only = 1001;

  TS_ASSERT_EQUALS(1001, sut.only);
}

//  ****************************************************************************
void TestMessageSuite::TestSingleFieldMsg_Nested(void)
{
  typedef Hg::single_nested_t_HgFormat SingleMsg;

  SingleMsg sut;
  sut.only.zero = 255;

  TS_ASSERT_EQUALS(255, sut.only.zero);
}

//  ****************************************************************************
void TestMessageSuite::TestSingleFieldMsg_Bitlist(void)
{
  typedef Hg::single_bit_t_HgFormat SingleMsg;

  SingleMsg sut;
  sut.only.lonely = 3;

  TS_ASSERT_EQUALS(1, (int)sut.only.lonely);
}

//  ****************************************************************************
void TestMessageSuite::Testto_host(void)
{
  // Populate the expected results.
  SUT::net_t expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT::net_t sut;
  PopulateBaseValues(sut);

  SUT::host_t no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT::host_t result = to_host(sut);
  SUT::host_t no_op_result = to_host(no_op_sut);

  TS_ASSERT_SAME_DATA(expected.data(), result.data(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestMessageSuite::Testto_network(void)
{
  // Populate the expected results.
  SUT::host_t expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT::host_t sut;
  PopulateBaseValues(sut);

  SUT::net_t no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT::net_t result = to_network(sut);
  SUT::net_t no_op_result = to_network(no_op_sut);

  TS_ASSERT_SAME_DATA(expected.data(), result.data(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestMessageSuite::Testto_big_endian(void)
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
void TestMessageSuite::Testto_little_endian(void)
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
