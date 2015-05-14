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
  // Utility Functions used to implement the API.
  void Test_struct_to_msg_fundamentals(void);
  void Test_msg_to_struct_fundamentals(void);

  void Test_struct_to_msg_packed(void);
  void Test_msg_to_struct_packed(void);

  void Test_struct_to_msg_nested(void);
  void Test_msg_to_struct_nested(void);

  void Test_struct_to_msg_array(void);
  void Test_msg_to_struct_array(void);


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
void CarbonTestSuite::Test_struct_to_msg_nested(void)
{
  vertex_t v;
  v.pt.X = 10;
  v.pt.Y = 5;
  v.pt.Z = -2;

  v.color.R = 3;
  v.color.G = 234;
  v.color.B = 109;
  v.color.A = 127;

  Hg::vertex_t hg_v;
  
  // SUT
  C::struct_to_msg(v, hg_v);

  TS_ASSERT_EQUALS(v.pt.X, hg_v.pt.X);
  TS_ASSERT_EQUALS(v.pt.Y, hg_v.pt.Y);
  TS_ASSERT_EQUALS(v.pt.Z, hg_v.pt.Z);

  TS_ASSERT_EQUALS(v.color.R, hg_v.color.R);
  TS_ASSERT_EQUALS(v.color.G, hg_v.color.G);
  TS_ASSERT_EQUALS(v.color.B, hg_v.color.B);
  TS_ASSERT_EQUALS(v.color.A, hg_v.color.A);
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_nested(void)
{
  Hg::vertex_t hg_v;
  hg_v.pt.X = 10;
  hg_v.pt.Y = 5;
  hg_v.pt.Z = -2;
  
  hg_v.color.R = 3;
  hg_v.color.G = 234;
  hg_v.color.B = 109;
  hg_v.color.A = 127;

  vertex_t v;
  
  // SUT
  C::msg_to_struct(hg_v, v);

  TS_ASSERT_EQUALS(v.pt.X, hg_v.pt.X);
  TS_ASSERT_EQUALS(v.pt.Y, hg_v.pt.Y);
  TS_ASSERT_EQUALS(v.pt.Z, hg_v.pt.Z);

  TS_ASSERT_EQUALS(v.color.R, hg_v.color.R);
  TS_ASSERT_EQUALS(v.color.G, hg_v.color.G);
  TS_ASSERT_EQUALS(v.color.B, hg_v.color.B);
  TS_ASSERT_EQUALS(v.color.A, hg_v.color.A);
}

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_array(void)
{
  color_map_t c;
  for (size_t index = 0; index < 16; ++index)
  {
    c.table[index].R = index * 2;
    c.table[index].G = index * 3;
    c.table[index].B = index * 4;
    c.table[index].A = index * 5;
  }

  Hg::color_map_t hg_c;

  // TODO: Need to correct the copy of arrays. it is pasting array[size] in the copy code. Therefore, it tries to dereference one passed the end.
  // SUT
  C::struct_to_msg(c, hg_c);
  
  for (size_t index = 0; index < 16; ++index)
  {
    TS_ASSERT_EQUALS(c.table[index].R, hg_c.table[index].R);
    TS_ASSERT_EQUALS(c.table[index].G, hg_c.table[index].G);
    TS_ASSERT_EQUALS(c.table[index].B, hg_c.table[index].B);
    TS_ASSERT_EQUALS(c.table[index].A, hg_c.table[index].A);
  }
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_array(void)
{
  Hg::color_map_t hg_c;

  for (size_t index = 0; index < 16; ++index)
  {
    hg_c.table[index].R = index * 2;
    hg_c.table[index].G = index * 3;
    hg_c.table[index].B = index * 4;
    hg_c.table[index].A = index * 5;
  }

  color_map_t c;

  // SUT
  C::msg_to_struct(hg_c, c);
  
  for (size_t index = 0; index < 16; ++index)
  {
    TS_ASSERT_EQUALS(c.table[index].R, hg_c.table[index].R);
    TS_ASSERT_EQUALS(c.table[index].G, hg_c.table[index].G);
    TS_ASSERT_EQUALS(c.table[index].B, hg_c.table[index].B);
    TS_ASSERT_EQUALS(c.table[index].A, hg_c.table[index].A);
  }
}




#endif




