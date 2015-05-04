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

//  ****************************************************************************
/// CarbonTestSuite Test Suite class.
///
class CarbonTestSuite : public CxxTest::TestSuite
{
public:

  CarbonTestSuite()
  {
    // TODO: Construct Test Suite Object
  }

  // Fixture Management *******************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {
    // TODO: Add common fixture setup code if any exists.
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {
    // TODO: Add common fixture teardown code if any exists.
  }

protected:
  // Test Suite Data **********************************************************

  // Creator Methods **********************************************************
  // TODO: Use creator methods to reduce redundant setup code in test cases.

public:
  // Test Cases ***************************************************************
  // TODO: Add a new function for each unique test to be performed in this suite. 
  void TestCase1(void);

};

//  ******************************************************************************
void CarbonTestSuite::TestCase1(void)
{
  // TODO: Implement Single Test Case.
  // TODO: The implementation can also be placed in a cpp file if desired.
}

#endif