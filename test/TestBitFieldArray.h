//  @file Hg.h
//  
//  Contains the Hg (Mercury) Message template definition.
//  This format is used to access data fields in formatted message buffers.
//  
//  The MIT License(MIT)
//  
//  @copyright 2014 Paul M Watt
//  
//  TS_FAIL(message):                        Fail unconditionally
//  TS_ASSERT(expr):                         Verify (expr) is true
//  TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
//  TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
//  TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
//  TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
//  TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
//  TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
//  TS_ASSERT_PREDICATE(P, x):               Verify P(x)
//  TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
//  TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
//  TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
//  TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
//  TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
//  TS_WARN(message):                        Print message as a warning
//  TS_TRACE(message):                       Print message as an information message
// 
#ifndef TESTBITFIELDARRAY_H_INCLUDED
#define TESTBITFIELDARRAY_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <storage_policy.h>
#include <meta/bit_field_array.h>

#include <test_helper.h>
#include <test_def.h>


namespace Hg
{



} // namespace Hg


//  ****************************************************************************
/// @brief TestArrayDataSuite Test Suite class.
///
class TestBitFieldArray : public CxxTest::TestSuite
//  , HgTestHelper<Hg::array_t, Hg::BufferedStoragePolicy >
{
public:
  TestBitFieldArray() { }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {
    
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {

  }

protected:
  //  Constants ****************************************************************

public:
  //  Test Cases ***************************************************************
  //  Test the basic function set with a u32 ***********************************
  void TestDtor(void);


};

//  ****************************************************************************
void TestBitFieldArray::TestDtor(void)
{
//  const std::array<uint8_t, 8> k_control = {1,2,3,4,5,6,7,8};
////  const uint8_t k_control[8] = {1,2,3,4,5,6,7,8};
//
//  array_data_8 sut;
//  sut.set(k_control);
//
//  // SUT
//  // Call the destructor explicitly.
//  sut.~DataProxy();
//
//  // The assigned code should still be present in the datum.
//  TS_ASSERT_EQUALS(k_control, sut.get());
}






#endif
