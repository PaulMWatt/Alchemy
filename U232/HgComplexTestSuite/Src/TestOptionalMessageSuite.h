/// @file TestOptionalMessageSuite.hpp
/// 
/// This test suite verifies the msg Template with optional parameters.
///
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
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
#ifndef TEST_OPTIONAL_MESSAGE_SUITE_H_INCLUDED
#define TEST_OPTIONAL_MESSAGE_SUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <msgtest_typelist.h>
#include <geometry_typelist.h>
#include <Hg.h>
#include <algorithm>


//  ****************************************************************************
bool IsArrayValid(const uint8_t* pBuffer, size_t len)
{
  // Read the first byte of the buffer.
  return  pBuffer
       && pBuffer[0] == 0;
}


//  ****************************************************************************
//  A statically-sized type list with optional fields
// 
//  The fields are formatted according to the following column configuration.
//  Fields are optional based upon their declaration type:
//                   type       [size] [valid]        name
//                   ---------- ------ -------------  ------
ALCHEMY_STRUCT(basic_opt_t,
  ALCHEMY_DATUM     (uint8_t,                         avail),
  ALCHEMY_DATUM_OPT (pt3d_t,           avail,         pt),
  ALCHEMY_DATUM_OPT (uint32_t,         avail,         single),
  ALCHEMY_ARRAY_OPT (uint32_t,  4,     IsArrayValid,  many),
  ALCHEMY_DATUM     (uint8_t,                         last)
);

//  ****************************************************************************
//  A dynamically-sized type list with optional fields
//
//  The fields are formatted according to the following column configuration.
//  Fields are optional based upon their declaration type:
//                   type       [size] [valid] name
//                   ---------- ------ ------- ------
ALCHEMY_STRUCT(dyn_opt_format_t,
  ALCHEMY_DATUM     (uint8_t,                  id),
  ALCHEMY_DATUM     (uint8_t,                  exists),
  ALCHEMY_DATUM_OPT (basic_opt_t,      exists, fixed),
//  ALCHEMY_DATUM     (basic_opt_t,              fixed),
  ALCHEMY_DATUM     ( int8_t,                  extra),
  ALCHEMY_ALLOC_OPT (uint16_t,  extra, extra,  dynamic)
);


const uint8_t                 k_valid_alt   = 0;
const  int8_t                 k_extra_alt   = 0;

const uint8_t                 k_valid       = 1;

const uint32_t                k_pt_x        = 0x0A0B0C0D;
const uint32_t                k_pt_y        = 0xA00AB00B;
const uint32_t                k_pt_z        = 0xF0E00D0C;

const uint32_t                k_single      = 0x12345678;
const std::array<uint32_t,4>  k_many        = { 0x12345678, 0x78563412, 
                                                0xABCDEF00, 0x00FEDCBA};
const uint8_t                 k_last        = 254;

const uint8_t                 k_id          = 10;
const uint8_t                 k_exists      = 2;
const  int8_t                 k_extra       = -1;

const std::array<uint16_t,12> k_dynamic     = { 0x600D, 0xEA45, 0x0B13, 0x553D, 
                                                0x0C1A, 0x5500, 0x0DEF, 0xEA40,
                                                0xDEAD, 0xC0DE, 0x1234, 0x5678};

// Opposite byte-swapped values.
const uint8_t                 k_opp_valid   = 1;

const uint32_t                k_opp_pt_x    = 0x0D0C0B0A;
const uint32_t                k_opp_pt_y    = 0x0BB00AA0;
const uint32_t                k_opp_pt_z    = 0x0C0DE0F0;

const uint32_t                k_opp_single  = 0x78563412;
const std::array<uint32_t,4>  k_opp_many    = {0x78563412, 0x12345678,
                                               0x00FEDCBA, 0xABCDEF00};
const uint8_t                 k_opp_last    = 254;

const uint8_t                 k_opp_id      = 10;
const uint8_t                 k_opp_exists  = 2;
const  int8_t                 k_opp_extra   = 1;

const std::array<uint16_t,12> k_opp_dynamic = { 0x0D60, 0x45EA, 0x130B, 0x3D55,
                                                0x1A0C, 0x0055, 0xEF0D, 0x40EA,
                                                0xADDE, 0xDEC0, 0x3412, 0x7856};

namespace Hg
{

using optional_format_t = dyn_opt_format_t;

}

//  ****************************************************************************
/// @brief TestOptionalMessageSuite Test Suite class.
///
class TestOptionalMessageSuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::dyn_opt_format_t::format_type, Hg::BufferedStoragePolicy >
{
public:
  
  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  { }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  { }

protected:
  //  Constants ******************************************************************

  // With the current test structure, the SUT format uses 45 bytes.
  static const size_t k_sut_msg_size = 45;

  uint8_t   packed_msg[k_sut_msg_size];
  uint8_t   other_packed_msg[k_sut_msg_size];
 

  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different msg field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::BufferedStoragePolicy                               storage_type;
  typedef Hg::optional_format_t                                   msg_type;
  typedef Hg::basic_msg<msg_type>::host_t                         SUT;
  typedef Hg::basic_msg<msg_type>::net_t                          SUT_net;
  typedef Hg::basic_msg<msg_type>::big_t                          SUT_big;
  typedef Hg::basic_msg<msg_type>::little_t                       SUT_little;

  typedef storage_type::data_type                                 data_type;
  typedef storage_type::s_pointer                                 s_pointer;

  // Helper Functions ************************************************************
  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateBaseValues(SUT_t& msg)
  {
    msg.fixed.avail     = k_valid;
    msg.fixed.pt.X      = k_pt_x;
    msg.fixed.pt.Y      = k_pt_y;
    msg.fixed.pt.Z      = k_pt_z;
    msg.fixed.pt.valid();

    msg.fixed.single    = k_single;
    //msg.fixed.many  = k_many; // not valid in this case
    msg.fixed.last      = k_last;
    msg.fixed.reset();

    msg.id              = k_id;
    msg.exists          = k_exists;
    msg.extra           = k_extra;

    msg.dynamic.assign(k_dynamic.begin(), k_dynamic.end());

    // Construct a packed memory array by hand that contains the data
    // buffer that is expected based on the values assigned above.

    ::memset(packed_msg, 0, sizeof(packed_msg));
    uint8_t *pCur = packed_msg;
    
    // Pack a dynamic message object.
    ::memcpy(pCur, &k_id, sizeof(k_id));
    pCur += sizeof(msg.id);

    ::memcpy(pCur, &k_exists, sizeof(k_exists));
    pCur += sizeof(msg.exists);

    // Populate the fixed size object.
    ::memcpy(pCur, &k_valid, sizeof(k_valid));
    pCur += sizeof(k_valid);

    ::memcpy(pCur, &k_pt_x, sizeof(k_pt_x));
    pCur += sizeof(k_pt_x);

    ::memcpy(pCur, &k_pt_y, sizeof(k_pt_y));
    pCur += sizeof(k_pt_y);

    ::memcpy(pCur, &k_pt_z, sizeof(k_pt_z));
    pCur += sizeof(k_pt_z);

    ::memcpy(pCur, &k_single, sizeof(k_single));
    pCur += sizeof(k_single);

    ::memcpy(pCur, &k_last, sizeof(k_last));
    pCur += sizeof(k_last);

    // return to the parent object.
    ::memcpy(pCur, &k_extra, sizeof(k_extra));
    pCur += sizeof(k_extra);

    ::memcpy(pCur, &k_dynamic, sizeof(k_dynamic));
    pCur += sizeof(k_dynamic);

    // This value is explicitly specified to insure that the 
    // the test is updated if the message buffer is updated.
    TS_ASSERT_EQUALS((pCur - packed_msg), 45)
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
    msg.fixed.avail       = k_opp_valid;
    msg.fixed.pt.X        = k_opp_pt_x;
    msg.fixed.pt.Y        = k_opp_pt_y;
    msg.fixed.pt.Z        = k_opp_pt_z;
    msg.fixed.pt.valid();

    msg.fixed.single      = k_opp_single;
    //msg.fixed.many        = k_opp_many; // not valid in this case
    msg.fixed.last        = k_opp_last;
    msg.fixed.valid();

    msg.id          = k_opp_id;
    msg.exists      = k_opp_exists;
    msg.extra       = k_opp_extra;

    msg.dynamic.assign(k_dynamic.begin(), k_dynamic.end());

    // Construct a packed memory array by hand that contains the data
    // buffer that is expected based on the values assigned above.

    ::memset(other_packed_msg, 0, sizeof(other_packed_msg));
    uint8_t *pCur = other_packed_msg;
    
    // Pack a dynamic message object.
    ::memcpy(pCur, &k_opp_id, sizeof(k_opp_id));
    pCur += sizeof(k_id);

    ::memcpy(pCur, &k_opp_exists, sizeof(k_opp_exists));
    pCur += sizeof(k_exists);

    // Populate the fixed size object.
    ::memcpy(pCur, &k_opp_valid, sizeof(k_opp_valid));
    pCur += sizeof(k_valid);

    ::memcpy(pCur, &k_opp_pt_x, sizeof(k_opp_pt_x));
    pCur += sizeof(k_opp_pt_x);

    ::memcpy(pCur, &k_opp_pt_y, sizeof(k_opp_pt_y));
    pCur += sizeof(k_opp_pt_y);

    ::memcpy(pCur, &k_opp_pt_z, sizeof(k_opp_pt_z));
    pCur += sizeof(k_opp_pt_z);

    ::memcpy(pCur, &k_opp_single, sizeof(k_opp_single));
    pCur += sizeof(k_single);

    ::memcpy(pCur, &k_opp_last, sizeof(k_opp_last));
    pCur += sizeof(k_last);

    // return to the parent object.
    ::memcpy(pCur, &k_opp_extra, sizeof(k_opp_extra));
    pCur += sizeof(k_extra);

    ::memcpy(pCur, &k_opp_dynamic, sizeof(k_opp_dynamic));
    pCur += sizeof(k_opp_dynamic);

    // This value is explicitly specified to insure that the 
    // the test is updated if the message buffer is updated.
    TS_ASSERT_EQUALS((pCur - other_packed_msg), 45)
  }

public:
  // Test Cases ****************************************************************

  // Dynamic Message Tests
  void TestDefaultCtor();
  void TestCopyCtor();
  void TestValueCtor();
  void TestAssignmentOperator();
  void Testempty();
  void Testempty_false();
  void TestSize();
  void Testis_host_order();
  void Testis_host_order_false();
  void TestAssign();
  void TestClear();
  void Testdata();

  //  Worker Functions *********************************************************
  void Testto_host();
  void Testto_network();
  void Testto_big_endian();
  void Testto_little_endian();

};

//  ****************************************************************************
void TestOptionalMessageSuite::TestDefaultCtor()
{
  // SUT
  SUT sut;

  // The msg buffer should not exist.
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestOptionalMessageSuite::TestCopyCtor()
{
  SUT                 rhs;
  PopulateBaseValues (rhs);

  // SUT
  SUT sut(rhs);
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestOptionalMessageSuite::TestValueCtor()
{
  SUT                 rhs;
  PopulateBaseValues (rhs);
  // SUT
  SUT sut(rhs.data(), rhs.size());
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestOptionalMessageSuite::TestAssignmentOperator()
{
  SUT                rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs;
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testempty()
{
  // SUT
  SUT sut;
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testempty_false()
{
  // SUT
  SUT sut(get_buffer().get(), get_length());
  TS_ASSERT(!sut.empty());
}

//  ****************************************************************************
void TestOptionalMessageSuite::TestSize()
{
  // SUT
  SUT sut;

  TS_ASSERT_EQUALS(Hg::size_of<SUT::format_type>::value, sut.size());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testis_host_order()
{
  // SUT: Host order is defined within the type itself.
  //      Look at the typedef for details
  SUT sut;
  TS_ASSERT(sut.is_host_order());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testis_host_order_false()
{
  // SUT: Net order is defined within the type itself. 
  //      Look at the typedef for details
  SUT_net sut;
  TS_ASSERT(!sut.is_host_order());
}

//  ****************************************************************************
void TestOptionalMessageSuite::TestAssign()
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
void TestOptionalMessageSuite::TestClear()
{
  SUT sut(get_buffer().get(), get_length());
  TS_ASSERT(!sut.empty());

  // SUT
  sut.clear();

  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testdata()
{
  SUT sut;
  
  sut.id              = k_id;
  sut.exists          = k_exists;

  sut.fixed.avail     = k_valid;

  sut.fixed.pt.X      = k_pt_x;
  sut.fixed.pt.Y      = k_pt_y;
  sut.fixed.pt.Z      = k_pt_z;
  sut.fixed.single    = k_single;
  //msg.many        = k_many; // not valid in this case
  sut.fixed.last      = k_last;

  sut.extra           = k_extra;

  sut.dynamic.assign(k_dynamic.begin(), k_dynamic.end());

  TS_ASSERT_EQUALS(k_sut_msg_size, sut.size());
  TS_ASSERT_SAME_DATA(packed_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testto_host()
{
  // Populate the expected results.
  SUT_net expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_net sut;
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
void TestOptionalMessageSuite::Testto_network()
{
  // Populate the expected results.
  SUT expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT sut;
  PopulateBaseValues(sut);

  SUT_net no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_net result = to_network(sut);
  SUT_net no_op_result = to_network(no_op_sut);

  TS_ASSERT_SAME_DATA(other_packed_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_packed_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testto_big_endian()
{
  // Populate the expected results.
  SUT expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_little sut;
  PopulateBaseValues(sut);

  SUT_big no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_big result = to_big_endian(sut);
  SUT_big no_op_result = to_big_endian(no_op_sut);

  TS_ASSERT_SAME_DATA(other_packed_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_packed_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestOptionalMessageSuite::Testto_little_endian()
{
  // Populate the expected results.
  SUT expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_big sut;
  PopulateBaseValues(sut);

  SUT_little no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_little result        = to_little_endian(sut);
  SUT_little no_op_result  = to_little_endian(no_op_sut);

  TS_ASSERT_SAME_DATA(other_packed_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_packed_msg, no_op_result.data(), no_op_sut.size());
}


#endif
