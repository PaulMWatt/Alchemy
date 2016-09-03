/// @file Bi_NumberTheory_Fns_TestSuite.h
///
/// Test Fixture for verifying number theory functions -
/// (Bi) Big Integers
/// 
/// The MIT License(MIT)
/// 
/// @copyright 2014 Paul M Watt
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
#ifndef Bi_NumberTheory_Fns_TestSuite_H_INCLUDED
#define Bi_NumberTheory_Fns_TestSuite_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <BiTestIntegers.h>

#include <Bi.h>



//  *****************************************************************************
/// Bi_NumberTheory_Fns_TestSuite Test Suite class.
/// 
class Bi_NumberTheory_Fns_TestSuite : public CxxTest::TestSuite
{
public:

  Bi_NumberTheory_Fns_TestSuite()
    : k_default({k_A, k_B, k_C, k_D})
    , k_control({k_A, k_B, k_C, k_D})
    , k_negative(Bi::Z({k_A, k_B, k_C, k_D}) * -1)
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
  // Test Suite Data **********************************************************
  const 
    z_type k_default; 

  const 
    Bi::Z  k_control;

  const
    Bi::Z  k_negative;

  // Creator Methods **********************************************************
  Bi::Z get_SUT()
  {
    return Bi::Z({k_A, k_B, k_C, k_D});
  }

  Bi::Z get_nSUT()
  {
    return -Bi::Z({k_A, k_B, k_C, k_D});
  }


public:
  // Test Cases ***************************************************************
  void Test_gcd(void);
  void Test_gcd_lhs_larger(void);
  void Test_gcd_lhs_smaller(void);
  void Test_gcd_both_equal(void);
  void Test_gcd_rhs_0(void);

  void Test_gcd_ex(void);
  void Test_gcd_ex_lhs_larger(void);
  void Test_gcd_ex_lhs_smaller(void);
  void Test_gcd_ex_both_equal(void);
  void Test_gcd_ex_rhs_0(void);


};

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd(void)
{
  Bi::Z lhs = 240;
  Bi::Z rhs = 46;
  
  const Bi::Z k_expected = 2;

  // SUT
  Bi::Z result = gcd(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected, result); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_lhs_larger(void)
{
  Bi::Z lhs = k_128B_z;
  Bi::Z rhs = k_24B_z;

  const Bi::Z k_expected = k_8B_z;

  // SUT
  Bi::Z result = gcd(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected, result); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_lhs_smaller(void)
{
  Bi::Z lhs = k_16B_z;
  Bi::Z rhs = k_24B_z;

  const Bi::Z k_expected = k_8B_z;

  // SUT
  Bi::Z result = gcd(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected, result); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_both_equal(void)
{
  Bi::Z lhs = k_64B_z;
  Bi::Z rhs = k_64B_z;

  const Bi::Z k_expected = k_64B_z;

  // SUT
  Bi::Z result = gcd(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected, result); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_rhs_0(void)
{
  Bi::Z lhs = k_32B_z;
  Bi::Z rhs = 0;

  const Bi::Z k_expected = k_32B_z;

  // SUT
  Bi::Z result = gcd(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected, result); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_ex(void)
{
  Bi::Z lhs = 722;
  Bi::Z rhs = 56;

  const Bi::gcd_ex_Z_t k_expected = {9, 2};

  // SUT
  Bi::gcd_ex_Z_t result = Bi::gcd_ex(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected.coef,   result.coef); 
  TS_ASSERT_EQUALS(k_expected.denom,  result.denom); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_ex_lhs_larger(void)
{
  Bi::Z lhs = k_722B_z;
  Bi::Z rhs = k_56B_z;

  const Bi::gcd_ex_Z_t k_expected = {9, k_2B};

  // SUT
  Bi::gcd_ex_Z_t result = Bi::gcd_ex(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected.coef,   result.coef); 
  TS_ASSERT_EQUALS(k_expected.denom,  result.denom); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_ex_lhs_smaller(void)
{
  Bi::Z lhs = k_56B_z;
  Bi::Z rhs = k_722B_z;

  const Bi::gcd_ex_Z_t k_expected = {-116, k_2B};

  // SUT
  Bi::gcd_ex_Z_t result = gcd_ex(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected.coef,   result.coef); 
  TS_ASSERT_EQUALS(k_expected.denom,  result.denom); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_ex_both_equal(void)
{
  Bi::Z lhs = k_128B_z;
  Bi::Z rhs = k_128B_z;

  const Bi::gcd_ex_Z_t k_expected = {0, k_128B_z};

  // SUT
  Bi::gcd_ex_Z_t result = Bi::gcd_ex(lhs, rhs);


  TS_ASSERT_EQUALS(k_expected.coef,   result.coef); 
  TS_ASSERT_EQUALS(k_expected.denom,  result.denom); 
}

//  *****************************************************************************
void Bi_NumberTheory_Fns_TestSuite::Test_gcd_ex_rhs_0(void)
{
  Bi::Z lhs = k_32B_z;
  Bi::Z rhs = 0;

  const Bi::gcd_ex_Z_t k_expected = {1, k_32B_z};

  // SUT
  Bi::gcd_ex_Z_t result = Bi::gcd_ex(lhs, rhs);

  TS_ASSERT_EQUALS(k_expected.coef,   result.coef); 
  TS_ASSERT_EQUALS(k_expected.denom,  result.denom); 
}


#endif
