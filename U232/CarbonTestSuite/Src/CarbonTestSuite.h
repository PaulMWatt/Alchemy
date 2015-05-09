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

#include <cxxtest/TestSuite.h>

#include <Carbon.h>
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
  // TODO: Use creator methods to reduce redundant setup code in test cases.

public:
  // Test Cases ***************************************************************
  // TODO: Add a new function for each unique test to be performed in this suite. 
  void TestCase1(void);

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
void CarbonTestSuite::TestCase1(void)
{
  vertex_t v;

  v.pt.X = 10;
  v.pt.Y = 5;
  v.pt.Z = -2;


  function();
}

#endif




