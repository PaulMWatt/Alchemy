/// @file CarbonTestSuite.h
///
/// Verifies the Carbon interfaces derives from Hg interface definitions.
/// 
/// @author Paul  Watt
/// @date   2015.5.4: Paul  Watt    -- Initial release.
/// 
/// TODO: Update with an appropriate license copyright 2015
/// 
///  Verify data with these TEST ASSERTIONS:
/// 
///  TS_FAIL(message):                        Fail unconditionally
///  TS_ASSERT(expr):                         Verify (expr) is true
///  TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
///  TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
///  TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
///  TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
///  TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
///  TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
///  TS_ASSERT_PREDICATE(P, x):               Verify P(x)
///  TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
///  TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
///  TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
///  TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
///  TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
///  TS_WARN(message):                        Print message as a warning
///  TS_TRACE(message):                       Print message as an information message
/// 
//  **************************************************************************** 
#ifndef CarbonTestSuite_H_INCLUDED
#define CarbonTestSuite_H_INCLUDED

#include <iostream>
using namespace std;

#include <cxxtest/TestSuite.h>

#include <Carbon.h>
#include <C/carbonate.h>
#include <CarbonTestDefs.h>

#include <c_usage.h>
 
//  ****************************************************************************
/// CarbonTestSuite Test Suite class.
///
class CarbonTestSuite : public CxxTest::TestSuite
{
public:

  CarbonTestSuite()
    : m_hLib(0)
  {
    // TODO: Construct Test Suite Object
  }

  // Fixture Management *******************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {
    m_hLib = setup_library();
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {
    teardown_library(m_hLib);
  }

protected:
  // Test Suite Data **********************************************************
  HMODULE m_hLib;

  // Creator Methods **********************************************************

public:
  // Test Cases ***************************************************************
  void Test_struct_to_msg_fundamentals(void);
  void Test_msg_to_struct_fundamentals(void);
  void Test_struct_to_msg_packed(void);
  void Test_msg_to_struct_packed(void);

  // Utility Functions used to implement the API.


  // Collection of functions to test in the Carbon API
  //Hg_local_endianess
  //Hg_create
  //Hg_clone
  //Hg_destroy
  //Hg_resize_dynamic
  //Hg_type
  //Hg_size
  //Hg_data_size
  //Hg_to_network
  //Hg_to_host
  //Hg_to_big_end
  //Hg_to_little_end
  //Hg_pack
  //Hg_unpack



};

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_fundamentals(void)
{
  fundamentals_t  c;
  c.ch = 'A';
  c.s  = -12345;
  c.l  = 0xF005BA11;
  c.i  = -987654;
  c.uch= 'B';
  c.us = 6543;
  c.ul = 0x0BADFA11;
  c.ui = 123456789;

  Hg::fundamentals_t hg;

  // SUT;
  C::struct_to_msg(c, hg);
  TS_ASSERT_EQUALS(c.ch,  hg.ch);
  TS_ASSERT_EQUALS(c.s,   hg.s);
  TS_ASSERT_EQUALS(c.l,   hg.l);
  TS_ASSERT_EQUALS(c.i,   hg.i);
  TS_ASSERT_EQUALS(c.uch, hg.uch);
  TS_ASSERT_EQUALS(c.us,  hg.us);
  TS_ASSERT_EQUALS(c.ul,  hg.ul);
  TS_ASSERT_EQUALS(c.ui,  hg.ui);
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_fundamentals(void)
{
  Hg::fundamentals_t hg;
  hg.ch = 'A';
  hg.s  = -12345;
  hg.l  = 0xF005BA11;
  hg.i  = -987654;
  hg.uch= 'B';
  hg.us = 6543;
  hg.ul = 0x0BADFA11;
  hg.ui = 123456789;

  fundamentals_t  c;

  // SUT;
  C::msg_to_struct(hg, c);
  TS_ASSERT_EQUALS(c.ch,  hg.ch);
  TS_ASSERT_EQUALS(c.s,   hg.s);
  TS_ASSERT_EQUALS(c.l,   hg.l);
  TS_ASSERT_EQUALS(c.i,   hg.i);
  TS_ASSERT_EQUALS(c.uch, hg.uch);
  TS_ASSERT_EQUALS(c.us,  hg.us);
  TS_ASSERT_EQUALS(c.ul,  hg.ul);
  TS_ASSERT_EQUALS(c.ui,  hg.ui);
}

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_packed(void)
{
  color4 pixel;
  pixel.R = 3;
  pixel.G = 234;
  pixel.B = 109;
  pixel.A = 127;

  Hg::color4 hg_pixel;

  // SUT;
  C::struct_to_msg(pixel, hg_pixel);
  TS_ASSERT_EQUALS(pixel.R, hg_pixel.R);
  TS_ASSERT_EQUALS(pixel.G, hg_pixel.G);
  TS_ASSERT_EQUALS(pixel.B, hg_pixel.B);
  TS_ASSERT_EQUALS(pixel.A, hg_pixel.A);
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_packed(void)
{
  Hg::color4 hg_pixel;
  hg_pixel.R = 231;
  hg_pixel.G = 67;
  hg_pixel.B = 100;
  hg_pixel.A = 192;

  color4 pixel;

  // SUT;
  C::msg_to_struct(hg_pixel, pixel);
  TS_ASSERT_EQUALS(pixel.R, hg_pixel.R);
  TS_ASSERT_EQUALS(pixel.G, hg_pixel.G);
  TS_ASSERT_EQUALS(pixel.B, hg_pixel.B);
  TS_ASSERT_EQUALS(pixel.A, hg_pixel.A);
}

//  ******************************************************************************
//void CarbonTestSuite::TestCase1(void)
//{
//  vertex_t v;
//
//  v.pt.X = 10;
//  v.pt.Y = 5;
//  v.pt.Z = -2;
//
//
//  color4 pixel;
//  pixel.R = 3;
//  pixel.G = 234;
//  pixel.B = 109;
//  pixel.A = 127;
//
//  Hg::color4 hg_pixel;
//
//  C::struct_to_msg(pixel, hg_pixel);
//  cout << " R:" << hg_pixel.R
//       << " G:" << hg_pixel.G
//       << " B:" << hg_pixel.B
//       << " A:" << hg_pixel.A << "\n";
//
//  function();
//}

#endif




