// @file TestByteOrder.h
// 
// Test suite to verify functionality for host<->network byte order utilities.
// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
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
#ifndef TESTBYTEORDER_H_INCLUDED
#define TESTBYTEORDER_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <Pb/compiler.h>
typedef unsigned char       byte_t;

#include <Pb/byte_order.h>
#include <string>

// Bring the Hg::convert namespace into this scope for convenience ************
using namespace Hg::convert;
using std::string;
using std::pair;


//  ****************************************************************************
/// @brief        TestByteOrder Test Suite class.
///               Verifies a variety of utility byte-order conversion utilities.
///
class TestByteOrder : public CxxTest::TestSuite
{
public: 
  
  TestByteOrder()  
  {

  }

  /* Fixture Management ******************************************************/
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {

  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {

  }

public:
  /* Test Cases **************************************************************/

  //  Byte-Order Tests *********************************************************
  void TestEndianSwap_no_op(void);
  void TestEndianSwap_int16(void);
  void TestEndianSwap_uint16(void);
  void TestEndianSwap_int32(void);
  void TestEndianSwap_uint32(void);
  void TestEndianSwap_int64(void);
  void TestEndianSwap_uint64(void);

  void TestEndianType_no_op(void);
  void TestEndianType_swap_order(void);

  void TestHostByteOrder_to_host(void);
  void TestHostByteOrder_to_network(void);
  void TestNetByteOrder_to_host(void);
  void TestNetByteOrder_to_network(void);
};

//  ****************************************************************************
void TestByteOrder::TestEndianSwap_no_op(void)
{
  // Verify a few types that do not have specializations for EndianSwap.
  const double k_real = 2345.987;
  double real_result  = Hg::EndianSwap(k_real);
  TS_ASSERT_EQUALS(k_real, real_result);

  const char  k_char = 'L';
  char  char_result  = Hg::EndianSwap(k_char);
  TS_ASSERT_EQUALS(k_char, char_result);

  const char* k_char_star     = "Hello World";
  const char* char_star_result= Hg::EndianSwap(k_char_star);
  TS_ASSERT_EQUALS(k_char_star, char_star_result);

  const string k_string = "Hello World";
  string string_result  = Hg::EndianSwap(k_string);
  TS_ASSERT_EQUALS(k_string, string_result);

  typedef std::pair<int16_t, int32_t>   Int_pair;
  Int_pair control;
  control.first = 100;
  control.second= 1001;

  Int_pair result = Hg::EndianSwap(control);
  TS_ASSERT_EQUALS(control, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianSwap_int16(void)
{
  const int16_t k_control = 0x1234;
  const int16_t k_expect  = 0x3412;

  int16_t result  = Hg::EndianSwap(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianSwap_uint16(void)
{
  const uint16_t k_control = 0x24CD;
  const uint16_t k_expect  = 0xCD24;

  uint16_t result  = Hg::EndianSwap(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianSwap_int32(void)
{
  const int32_t k_control = 0x12345678;
  const int32_t k_expect  = 0x78563412;

  int32_t result  = Hg::EndianSwap(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianSwap_uint32(void)
{
  const uint32_t k_control = 0xFEDCBA98;
  const uint32_t k_expect  = 0x98BADCFE;

  uint32_t result  = Hg::EndianSwap(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianSwap_int64(void)
{
  const int64_t k_control = 0x0123456789ABCDEF;
  const int64_t k_expect  = 0xEFCDAB8967452301;

  int64_t result  = Hg::EndianSwap(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianSwap_uint64(void)
{
  const uint64_t k_control = 0x0123456789ABCDEF;
  const uint64_t k_expect  = 0xEFCDAB8967452301;

  uint64_t result  = Hg::EndianSwap(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianType_no_op(void)
{
  const int32_t k_control = 0x12345678;
  const int32_t k_expect  = 0x12345678;

  int32_t result = Hg::EndianType<int32_t, false>::swap_order(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestEndianType_swap_order(void)
{
  const int32_t k_control = 0x12345678;
  const int32_t k_expect  = 0x78563412;

  int32_t result = Hg::EndianType<int32_t, true>::swap_order(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestHostByteOrder_to_host(void)
{
  const uint32_t k_control = 0x12345678;
  const uint32_t k_expect  = 0x12345678;

  uint32_t result = Hg::HostByteOrder::to_host(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestHostByteOrder_to_network(void)
{
  const uint32_t k_control = 0x12345678;
  const uint32_t k_expect  = 0x78563412;

  uint32_t result = Hg::HostByteOrder::to_network(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestNetByteOrder_to_host(void)
{
  const uint32_t k_control = 0x12345678;
  const uint32_t k_expect  = 0x78563412;

  uint32_t result = Hg::NetByteOrder::to_host(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

//  ****************************************************************************
void TestByteOrder::TestNetByteOrder_to_network(void)
{
  const uint32_t k_control = 0x78563412;
  const uint32_t k_expect  = 0x78563412;

  uint32_t result = Hg::NetByteOrder::to_network(k_control);
  TS_ASSERT_EQUALS(k_expect, result);
}

#endif