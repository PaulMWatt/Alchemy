// @file TestOptional.h
// 
// Test suite to verify the 'optional' value class.
// 
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
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
#ifndef TESTOPTIONAL_H_INCLUDED
#define TESTOPTIONAL_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <Pb/compiler.h>
typedef unsigned char       byte_t;

#include <Pb/optional.h>
#include <string>

//  ****************************************************************************
/// @brief        TestOptional Test Suite class.
///               Verifies a the optional value management object.
///
class TestOptional : public CxxTest::TestSuite
{
public: 
  
  TestOptional()  
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

  // Tests *********************************************************************
  void TestDefaultCtor();
  void TestValueCtor();
  void TestValueConversion();
  void Test_empty_true();
  void Test_empty_false();
  void Test_reset();

};

//  ****************************************************************************
void TestOptional::TestDefaultCtor()
{
  // SUT
  Hg::optional<int> sut;

  TS_ASSERT(!sut.is_valid());
}

//  ****************************************************************************
void TestOptional::TestValueCtor()
{
  const int k_control = -175;
  // SUT
  Hg::optional<int> sut(k_control);

  TS_ASSERT(sut.is_valid());
  TS_ASSERT_EQUALS(k_control, static_cast<int>(sut));
}

//  ****************************************************************************
void TestOptional::TestValueConversion()
{
  const int k_control = -175;
  // SUT
  Hg::optional<int> sut;
  
  sut = k_control;

  TS_ASSERT(sut.is_valid());
  TS_ASSERT_EQUALS(k_control, static_cast<int>(sut));
}

//  ****************************************************************************
void TestOptional::Test_empty_true()
{
  Hg::optional<int> sut;

  // SUT
  bool result = sut.is_valid();

  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestOptional::Test_empty_false()
{
  Hg::optional<int> sut(200);

  // SUT
  bool result = sut.is_valid();

  TS_ASSERT(result);
}

//  ****************************************************************************
void TestOptional::Test_reset()
{
  Hg::optional<int> sut(100);

  TS_ASSERT(sut.is_valid());

  // SUT
  sut.reset();

  TS_ASSERT(!sut.is_valid());
}


#endif