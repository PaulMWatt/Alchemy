/// @file BiTestSuite.h
///
/// Test Fixture for Lithium library -
/// (Bi) Big Integers
/// 
/// @author Paul
/// @date   2016.8.5: Paul    -- Initial release.
///
/// TODO: Update with an appropriate license copyright 2016
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
#ifndef BiTestSuite_H_INCLUDED
#define BiTestSuite_H_INCLUDED

#include <cxxtest/TestSuite.h>

#include <Bi.h>

//  Constants for use with tests ************************************************
const uint64_t k_A = 0x12345678;
const uint64_t k_B = 0x9ABCDEF0;
const uint64_t k_C = 0x13579BDF;
const uint64_t k_D = 0x2468ACE0;
const uint64_t k_E = 0xFEDCBA98;
const uint64_t k_F = 0x76543210;

typedef std::vector<uint64_t>   z_type;


//  *****************************************************************************
/// BiTestSuite Test Suite class.
/// 
class BiTestSuite : public CxxTest::TestSuite
{
public:

  BiTestSuite()
    : k_default({k_A, k_B, k_C, k_D})
  {
    // TODO: Construct Test Suite Object
  }

  /* Fixture Management ******************************************************/
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
  /* Test Suite Data *********************************************************/
  const 
    z_type k_default; 

  /* Creator Methods *********************************************************/
  Bi::Z get_SUT()
  {
    return Bi::Z({k_A, k_B, k_C, k_D});
  }
  

public:
  /* Test Cases **************************************************************/
  void Test_DefaultConstructor(void);
  void Test_InitializerList_Constructor(void);
  void Test_CopyConstructor(void);
  void Test_MoveConstructor(void);
  void Test_ValueConstructor(void);
  void Test_int_Constructor(void);
  void Test_hex_Constructor(void);

  void Test_Destructor(void);

  void Test_AssignOp(void);
  void Test_MoveOp(void);
  void Test_AssignOp_T(void);
  void Test_AssignOp_int(void);

};

/*****************************************************************************/
void BiTestSuite::Test_DefaultConstructor(void)
{
  Bi::Z sut;

  TS_ASSERT(sut >= 0); 
}

/*****************************************************************************/
void BiTestSuite::Test_InitializerList_Constructor(void)
{
  const z_type control = {k_C, k_B, k_A};
  // SUT
  Bi::Z sut = {k_C, k_B, k_A};

  z_type result;
  sut.data(result);

  TS_ASSERT_EQUALS(control, result);
}

/*****************************************************************************/
void BiTestSuite::Test_CopyConstructor(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  z_type result;
  sut.data(result);

  TS_ASSERT_EQUALS(k_default, result);
}

/*****************************************************************************/
void BiTestSuite::Test_MoveConstructor(void)
{
  // TODO: Invoke the move constructor
}

/*****************************************************************************/
void BiTestSuite::Test_ValueConstructor(void)
{
  // SUT
  Bi::Z sut(k_A);

  z_type result;
  sut.data(result);

  z_type expected({k_A});
  TS_ASSERT_EQUALS(expected, result);
}

/*****************************************************************************/
void BiTestSuite::Test_int_Constructor(void)
{

}

/*****************************************************************************/
void BiTestSuite::Test_hex_Constructor(void)
{

}

/*****************************************************************************/
void BiTestSuite::Test_Destructor(void)
{

}

/*****************************************************************************/
void BiTestSuite::Test_AssignOp(void)
{

}

/*****************************************************************************/
void BiTestSuite::Test_MoveOp(void)
{

}

/*****************************************************************************/
void BiTestSuite::Test_AssignOp_T(void)
{

}

/*****************************************************************************/
void BiTestSuite::Test_AssignOp_int(void)
{

}

#endif