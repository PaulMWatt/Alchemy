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
const int      k_signed   = -1024;
const uint32_t k_unsigned = 0x400;

const uint32_t k_A = 0x12345678;
const uint32_t k_B = 0x9ABCDEF0;
const uint32_t k_C = 0x13579BDF;
const uint32_t k_D = 0x2468ACE0;
const uint32_t k_E = 0xFEDCBA98;
const uint32_t k_F = 0x76543210;

const uint32_t k_zero = 0x00000000;
const uint32_t k_odd  = 0x55555555;
const uint32_t k_even = 0xAAAAAAAA;
const uint32_t k_all  = 0xFFFFFFFF;


typedef std::vector<uint32_t>   z_type;


//  *****************************************************************************
/// BiTestSuite Test Suite class.
/// 
class BiTestSuite : public CxxTest::TestSuite
{
public:

  BiTestSuite()
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

  //  Comparison Operators ********************************************************
  void Test_eq_true(void);
  void Test_eq_false_sign(void);
  void Test_eq_false_value(void);

  void Test_not_eq_true_sign(void);
  void Test_not_eq_true_value(void);
  void Test_not_eq_false(void);

  void Test_less_than_true_negative(void);
  void Test_less_than_true_value(void);
  void Test_less_than_false_sign(void);
  void Test_less_than_false_value(void);

  void Test_le_true_negative(void);
  void Test_le_true_value(void);
  void Test_le_true_equal(void);
  void Test_le_false_sign(void);
  void Test_le_false_value(void);

  void Test_greater_than_true(void);
  void Test_greater_than_false(void);

  void Test_ge_true(void);
  void Test_ge_true_equal(void);
  void Test_ge_false(void);

  //  Arithmetic ******************************************************************
  void Test_negate(void);
  void Test_add_eq(void);
  void Test_sub_eq(void);
  void Test_mul_eq(void);
  void Test_div_eq(void);
  void Test_mod_eq(void);

  //  Logic ***********************************************************************
  void Test_invert(void);
  void Test_and_eq(void);
  void Test_or_eq(void);
  void Test_xor_eq(void);

  // TODO: Need to add tests that include variables of different sizes

  //  Other ***********************************************************************



  // TODO: Add binary arithmetic operators

};

//  *****************************************************************************
void BiTestSuite::Test_DefaultConstructor(void)
{
  Bi::Z sut;

  TS_ASSERT(sut >= 0); 
}

//  *****************************************************************************
void BiTestSuite::Test_InitializerList_Constructor(void)
{
  const z_type control = {k_C, k_B, k_A};
  // SUT
  Bi::Z sut = {k_C, k_B, k_A};

  z_type result;
  sut.data(result);

  TS_ASSERT_EQUALS(control, result);
}

//  *****************************************************************************
void BiTestSuite::Test_CopyConstructor(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  z_type result;
  sut.data(result);

  TS_ASSERT_EQUALS(k_default, result);
}

//  *****************************************************************************
void BiTestSuite::Test_MoveConstructor(void)
{
  // TODO: Invoke the move constructor
}

//  *****************************************************************************
void BiTestSuite::Test_ValueConstructor(void)
{
  // SUT
  Bi::Z sut(k_A);

  z_type result;
  sut.data(result);

  z_type expected({k_A});
  TS_ASSERT_EQUALS(expected, result);
}

//  *****************************************************************************
void BiTestSuite::Test_int_Constructor(void)
{  
  // SUT
  Bi::Z sut(k_signed);

  z_type result;
  sut.data(result);

  z_type expected({k_unsigned});
  TS_ASSERT_EQUALS(expected, result);
  TS_ASSERT(sut < 0);
}

//  *****************************************************************************
void BiTestSuite::Test_hex_Constructor(void)
{
  // TODO: Needs implementation
}

//  *****************************************************************************
void BiTestSuite::Test_Destructor(void)
{
  // TODO: No current action, will add for security impl
}

//  *****************************************************************************
void BiTestSuite::Test_AssignOp(void)
{
  Bi::Z sut;
  // SUT
  sut = get_SUT();

  z_type result;
  sut.data(result);

  TS_ASSERT_EQUALS(k_default, result);
}

//  *****************************************************************************
void BiTestSuite::Test_MoveOp(void)
{
  // TODO: Invoke the move operator
}

//  *****************************************************************************
void BiTestSuite::Test_AssignOp_T(void)
{
  Bi::Z sut;

  // SUT
  sut = k_A;

  z_type result;
  sut.data(result);

  z_type expected({k_A});
  TS_ASSERT_EQUALS(expected, result);
}

//  *****************************************************************************
void BiTestSuite::Test_AssignOp_int(void)
{
  Bi::Z sut;

  // SUT
  sut = k_signed;

  z_type result;
  sut.data(result);

  z_type expected({k_unsigned});
  TS_ASSERT_EQUALS(expected, result);
  TS_ASSERT(sut < 0);
}

//  *****************************************************************************
void BiTestSuite::Test_eq_true(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  TS_ASSERT(k_control == sut);
}

//  *****************************************************************************
void BiTestSuite::Test_eq_false_sign(void)
{
  // SUT
  Bi::Z sut(get_nSUT());

  TS_ASSERT(!(k_control == sut));
}

//  *****************************************************************************
void BiTestSuite::Test_eq_false_value(void)
{
  // SUT
  Bi::Z sut(get_SUT()+1);

  TS_ASSERT(!(k_control == sut));
}

//  *****************************************************************************
void BiTestSuite::Test_not_eq_true_sign(void)
{
  // SUT
  Bi::Z sut(get_nSUT());

  TS_ASSERT(k_control != sut);
}

//  *****************************************************************************
void BiTestSuite::Test_not_eq_true_value(void)
{
  // SUT
  Bi::Z sut(get_SUT()-1);

  TS_ASSERT(k_control != sut);
}

//  *****************************************************************************
void BiTestSuite::Test_not_eq_false(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  TS_ASSERT(!(k_control != sut));
}

//  *****************************************************************************
void BiTestSuite::Test_less_than_true_negative(void)
{
  // SUT
  Bi::Z sut(get_nSUT());

  TS_ASSERT(sut < k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_less_than_true_value(void)
{
  // SUT
  Bi::Z sut(get_SUT() - 1);

  TS_ASSERT(sut < k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_less_than_false_sign(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  TS_ASSERT(sut < k_negative);
}

//  *****************************************************************************
void BiTestSuite::Test_less_than_false_value(void)
{
  // SUT
  Bi::Z sut(get_SUT() + 1);

  TS_ASSERT(sut < k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_le_true_negative(void)
{
  // SUT
  Bi::Z sut(get_nSUT());

  TS_ASSERT(sut <= k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_le_true_value(void)
{
  // SUT
  Bi::Z sut(get_SUT() - 1);

  TS_ASSERT(sut <= k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_le_true_equal(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  TS_ASSERT(sut <= k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_le_false_sign(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  TS_ASSERT(!(sut <= k_negative));
}

//  *****************************************************************************
void BiTestSuite::Test_le_false_value(void)
{
  // SUT
  Bi::Z sut(get_SUT() + 1);

  TS_ASSERT(!(sut <= k_control));
}

//  *****************************************************************************
void BiTestSuite::Test_greater_than_true(void)
{
  // SUT
  Bi::Z sut(get_SUT() + 1);

  TS_ASSERT(sut > k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_greater_than_false(void)
{
  // SUT
  Bi::Z sut(get_SUT() - 1);

  TS_ASSERT(!(sut > k_control));
}

//  *****************************************************************************
void BiTestSuite::Test_ge_true(void)
{
  // SUT
  Bi::Z sut(get_SUT() + 1);

  TS_ASSERT(sut >= k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_ge_true_equal(void)
{
  // SUT
  Bi::Z sut(get_SUT());

  TS_ASSERT(sut >= k_control);
}

//  *****************************************************************************
void BiTestSuite::Test_ge_false(void)
{
  // SUT
  Bi::Z sut(get_SUT() - 1);

  TS_ASSERT(!(sut >= k_control));
}

//  *****************************************************************************
void BiTestSuite::Test_negate(void)
{
  Bi::Z sut = get_SUT();
  TS_ASSERT_EQUALS(k_control, sut);

  // SUT
  sut = -sut;
  TS_ASSERT_EQUALS(k_negative, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_add_eq(void)
{

}

//  *****************************************************************************
void BiTestSuite::Test_sub_eq(void)
{

}

//  *****************************************************************************
void BiTestSuite::Test_mul_eq(void)
{

}

//  *****************************************************************************
void BiTestSuite::Test_div_eq(void)
{

}

//  *****************************************************************************
void BiTestSuite::Test_mod_eq(void)
{

}

//  *****************************************************************************
void BiTestSuite::Test_invert(void)
{
  Bi::Z sut;
  Bi::Z rhs = {k_even, k_even, k_even, k_even, k_even, k_even, k_even, k_even};
  Bi::Z odd = {k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd};

  // SUT
  sut = ~rhs;

  TS_ASSERT_EQUALS(odd, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_and_eq(void)
{
  Bi::Z rhs = {k_all,  k_even, k_odd,  k_all,  k_even, k_odd,  k_all,  k_even};
  Bi::Z sut = {k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd};

  Bi::Z mix = {k_odd,  k_zero, k_odd,  k_odd,  k_zero, k_odd,  k_odd,  k_zero};

  // SUT
  sut &= rhs;
  TS_ASSERT_EQUALS(mix, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_or_eq(void)
{
  Bi::Z rhs = {k_even, k_even, k_even, k_even, k_even, k_even, k_even, k_even};
  Bi::Z sut = {k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd};

  Bi::Z all = {k_all,  k_all,  k_all,  k_all,  k_all,  k_all,  k_all,  k_all};

  // SUT
  sut |= rhs;
  TS_ASSERT_EQUALS(all, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_xor_eq(void)
{
  Bi::Z rhs = {k_all,  k_all,  k_all,  k_all,  k_all,  k_all,  k_all,  k_all};
  Bi::Z sut = {k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd,  k_odd };

  Bi::Z even = {k_even, k_even, k_even, k_even, k_even, k_even, k_even, k_even};

  // SUT
  sut ^= rhs;
  TS_ASSERT_EQUALS(even, sut);
}

#endif