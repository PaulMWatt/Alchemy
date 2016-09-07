/// @file BiTestSuite.h
///
/// Test Fixture for Bismuth library -
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
#ifndef BiTestSuite_H_INCLUDED
#define BiTestSuite_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <BiTestIntegers.h>

#include <Bi.h>



//  *****************************************************************************
/// BiTestSuite Test Suite class.
/// 
class BiTestSuite : public CxxTest::TestSuite
{
public:

  BiTestSuite()
    : k_default({k_A, k_B, k_C, k_D})
    , k_control({k_A, k_B, k_C, k_D})
    , k_negative(-Bi::Z({k_A, k_B, k_C, k_D}))
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

  //  Arithmetic: Addition ********************************************************
  void Test_unary_add_wo_carry(void);
  void Test_unary_add_w_carry(void);
  void Test_unary_add_w_ripple_carry(void);
  void Test_unary_add_identity(void);

  void Test_unary_add_same_sign_pos_L_ls_R(void);
  void Test_unary_add_same_sign_pos_L_gr_R(void);
  void Test_unary_add_same_sign_pos_L_eq_R(void);
  void Test_unary_add_same_sign_neg_L_ls_R(void);
  void Test_unary_add_same_sign_neg_L_gr_R(void);
  void Test_unary_add_same_sign_neg_L_eq_R(void);
  void Test_unary_add_diff_sign_L_eq_R(void);
  void Test_unary_add_neg_L_mag_L(void);
  void Test_unary_add_neg_L_mag_R(void);
  void Test_unary_add_neg_R_mag_L(void);
  void Test_unary_add_neg_R_mag_R(void);

  //  Arithmetic: Subtraction *****************************************************
  void Test_unary_sub_wo_borrow(void);
  void Test_unary_sub_w_borrow(void);
  void Test_unary_sub_w_ripple_borrow(void);
  void Test_unary_sub_identity(void);

  void Test_unary_sub_same_sign_pos_L_ls_R(void);
  void Test_unary_sub_same_sign_pos_L_gr_R(void);
  void Test_unary_sub_same_sign_pos_L_eq_R(void);
  void Test_unary_sub_same_sign_neg_L_ls_R(void);
  void Test_unary_sub_same_sign_neg_L_gr_R(void);
  void Test_unary_sub_same_sign_neg_L_eq_R(void);
  void Test_unary_sub_diff_sign_L_eq_R(void);
  void Test_unary_sub_neg_L_mag_L(void);
  void Test_unary_sub_neg_L_mag_R(void);
  void Test_unary_sub_neg_R_mag_L(void);
  void Test_unary_sub_neg_R_mag_R(void);


  //  Arithmetic: Multiplication **************************************************
  void Test_unary_mul_identity(void);
  void Test_unary_mul_zero(void);
  void Test_unary_mul_same_sign_pos(void);
  void Test_unary_mul_same_sign_neg(void);
  void Test_unary_mul_diff_sign_L_neg(void);
  void Test_unary_mul_diff_sign_R_neg(void);

  //  Arithmetic: Division ********************************************************
  void Test_unary_div_identity(void);
  void Test_unary_div_zero(void);
  void Test_unary_div_same_sign_pos(void);
  void Test_unary_div_same_sign_neg(void);
  void Test_unary_div_diff_sign_L_neg(void);
  void Test_unary_div_diff_sign_R_neg(void);
  void Test_unary_div_divisor_larger(void);
  void Test_unary_div_divisor_equal(void);

  //  Arithmetic: Modulus *********************************************************
  void Test_unary_mod_zero(void);
  void Test_unary_mod_same_sign_pos(void);
  void Test_unary_mod_same_sign_neg(void);
  void Test_unary_mod_diff_sign_L_neg(void);
  void Test_unary_mod_diff_sign_R_neg(void);
  void Test_unary_mod_divisor_larger(void);
  void Test_unary_mod_divisor_equal(void);

  //  Logic ***********************************************************************
  void Test_not(void);
  void Test_and_eq(void);
  void Test_or_eq(void);
  void Test_xor_eq(void);


  //  Bit Manipulation ************************************************************
  void Test_lshift_eq_0(void);
  void Test_lshift_eq_1(void);
  void Test_lshift_eq_word_boundary(void);
  void Test_lshift_eq_new_word(void);
  void Test_lshift_eq_multiple_words(void);

  void Test_rshift_eq_0(void);
  void Test_rshift_eq_1(void);
  void Test_rshift_eq_word_boundary(void);
  void Test_rshift_eq_remove_word(void);
  void Test_rshift_eq_multiple_words(void);


  //  Other ***********************************************************************



  // TODO: Need to add tests that include variables of different sizes
  // TODO: Add tests for binary arithmetic operators

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

  TS_ASSERT(!(sut < k_negative));
}

//  *****************************************************************************
void BiTestSuite::Test_less_than_false_value(void)
{
  // SUT
  Bi::Z sut(get_SUT() + 1);

  TS_ASSERT(!(sut < k_control));
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

//  Addition ********************************************************************
//  *****************************************************************************
void BiTestSuite::Test_unary_add_wo_carry(void)
{
  const Bi::Z k_expected = k_64B;

  Bi::Z lhs = k_32B_z;
  Bi::Z rhs = k_32B_z;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_w_carry(void)
{
  const Bi::Z k_expected = k_24B;

  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_16B_z;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_w_ripple_carry(void)
{
  const Bi::Z k_expected = {k_zero, k_zero, k_one};

  Bi::Z lhs = {0xFFFFFFFF, 0xFFFFFFFF};
  Bi::Z rhs = 1;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_identity(void)
{
  // The add identity elements for integers is zero.
  const Bi::Z k_expected = k_128B;

  Bi::Z lhs = k_128B_z;
  Bi::Z rhs = k_zero;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_same_sign_pos_L_ls_R(void)
{
  const Bi::Z k_expected = Bi::Z(k_24B);

  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_16B_z;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_same_sign_pos_L_gr_R(void)
{
  const Bi::Z k_expected = k_24B;

  Bi::Z lhs = k_16B_z;
  Bi::Z rhs = k_8B_z;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_same_sign_pos_L_eq_R(void)
{
  const Bi::Z k_expected = k_64B;

  Bi::Z lhs = k_32B_z;
  Bi::Z rhs = k_32B_z;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_same_sign_neg_L_ls_R(void)
{
  const Bi::Z k_expected = -Bi::Z(k_24B);

  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_16B_z;

  // SUT
  Bi::Z sut = (-lhs) + (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_same_sign_neg_L_gr_R(void)
{
  const Bi::Z k_expected = -Bi::Z(k_24B);

  Bi::Z lhs = k_16B_z;
  Bi::Z rhs = k_8B_z;

  // SUT
  Bi::Z sut = (-lhs) + (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_same_sign_neg_L_eq_R(void)
{
  const Bi::Z k_expected = -Bi::Z(k_64B);

  Bi::Z lhs = k_32B_z;
  Bi::Z rhs = k_32B_z;

  // SUT
  Bi::Z sut = (-lhs) + (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_diff_sign_L_eq_R(void)
{
  const Bi::Z k_expected = k_zero;

  Bi::Z lhs = k_32B_z;
  Bi::Z rhs = k_32B_z;

  // SUT
  Bi::Z sut = (-lhs) + (rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_neg_L_mag_L(void)
{
  const Bi::Z k_expected = -Bi::Z(k_8B);

  Bi::Z lhs = -Bi::Z(k_24B_z);
  Bi::Z rhs = k_16B_z;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_neg_L_mag_R(void)
{
  const Bi::Z k_expected = k_16B;

  Bi::Z lhs = -Bi::Z(k_8B_z);
  Bi::Z rhs = k_24B_z;

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_neg_R_mag_L(void)
{
  const Bi::Z k_expected = k_8B;

  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = -Bi::Z(k_16B_z);

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_add_neg_R_mag_R(void)
{
  const Bi::Z k_expected = -Bi::Z(k_8B);

  Bi::Z lhs = k_16B_z;
  Bi::Z rhs = -Bi::Z(k_24B_z);

  // SUT
  Bi::Z sut = lhs + rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  Subtraction *****************************************************************
//  *****************************************************************************
void BiTestSuite::Test_unary_sub_wo_borrow(void)
{
  Bi::Z lhs = 8192;
  Bi::Z rhs = 1024;
  Bi::Z k_expected = 8192 - 1024;

  // SUT
  Bi::Z sut = lhs - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_w_borrow(void)
{
  const Bi::Z k_expected = k_16B;

  Bi::Z lhs = k_24B;
  Bi::Z rhs = k_8B_z;

  // SUT
  Bi::Z sut = lhs - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_w_ripple_borrow(void)
{
  const Bi::Z k_expected = {0xFFFFFFFF, 0xFFFFFFFF};

  Bi::Z lhs = {k_zero, k_zero, k_one};
  Bi::Z rhs = 1;

  // SUT
  Bi::Z sut = lhs - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_identity(void)
{
  // The sub identity elements for integers is zero.
  const Bi::Z k_expected = k_128B;

  Bi::Z lhs = k_128B_z;
  Bi::Z rhs = k_zero;

  // SUT
  Bi::Z sut = lhs - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_same_sign_pos_L_ls_R(void)
{
  const Bi::Z k_expected = -Bi::Z(k_8B);

  Bi::Z lhs = k_16B_z;
  Bi::Z rhs = k_24B_z;

  // SUT
  Bi::Z sut = lhs - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_same_sign_pos_L_gr_R(void)
{
  const Bi::Z k_expected = k_16B;

  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = k_8B_z;

  // SUT
  Bi::Z sut = lhs - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_same_sign_pos_L_eq_R(void)
{
  const Bi::Z k_expected = k_zero;

  Bi::Z lhs = k_128B_z;
  Bi::Z rhs = k_128B_z;

  // SUT
  Bi::Z sut = lhs - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_same_sign_neg_L_ls_R(void)
{
  const Bi::Z k_expected = Bi::Z(k_16B);

  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_24B_z;

  // SUT
  Bi::Z sut = -(lhs) - (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_same_sign_neg_L_gr_R(void)
{
  const Bi::Z k_expected = -Bi::Z(k_8B);

  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = k_16B_z;

  // SUT
  Bi::Z sut = -(lhs)-(-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_same_sign_neg_L_eq_R(void)
{
  const Bi::Z k_expected = k_zero;

  Bi::Z lhs = k_64B_z;
  Bi::Z rhs = k_64B_z;

  // SUT
  Bi::Z sut = (-lhs) - (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_diff_sign_L_eq_R(void)
{
  const Bi::Z k_expected = k_64B_z;

  Bi::Z lhs = k_32B_z;
  Bi::Z rhs = k_32B_z;

  // SUT
  Bi::Z sut = lhs - (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
//  For these next few, the naming system is:
//    All tests are for operands with two different signs
//      neg_X indicates which parameter is negative, Left or Right
//      mag_X indicates which parameter has a larger magnitude, Left or Right
//
void BiTestSuite::Test_unary_sub_neg_L_mag_L(void)
{
  const Bi::Z k_expected = -Bi::Z(k_32B_z);

  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = k_8B_z;

  // SUT
  Bi::Z sut = (-lhs) - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_neg_L_mag_R(void)
{
  const Bi::Z k_expected = -Bi::Z(k_32B_z);

  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_24B_z;

  // SUT
  Bi::Z sut = (-lhs) - rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_neg_R_mag_L(void)
{
  const Bi::Z k_expected = Bi::Z(k_32B_z);

  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = k_8B_z;

  // SUT
  Bi::Z sut = lhs - (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_sub_neg_R_mag_R(void)
{
  const Bi::Z k_expected = Bi::Z(k_24B_z);

  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_16B_z;

  // SUT
  Bi::Z sut = lhs - (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  Multiplication **************************************************************
//  *****************************************************************************
void BiTestSuite::Test_unary_mul_identity(void)
{
  Bi::Z lhs = k_64B_z;
  Bi::Z rhs = 1;
  Bi::Z k_expected = k_64B_z;

  // SUT
  Bi::Z sut = lhs * rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mul_zero(void)
{
  Bi::Z lhs = k_64B_z;
  Bi::Z rhs = 0;
  Bi::Z k_expected = k_zero;

  // SUT
  Bi::Z sut = lhs * rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mul_same_sign_pos(void)
{
  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = 8;
  Bi::Z k_expected = k_64B;

  // SUT
  Bi::Z sut = lhs * rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mul_same_sign_neg(void)
{
  Bi::Z lhs = 16;
  Bi::Z rhs = k_8B_z;
  Bi::Z k_expected = Bi::Z(k_128B);

  // SUT
  Bi::Z sut = (-lhs) * (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mul_diff_sign_L_neg(void)
{
  Bi::Z lhs = 16;
  Bi::Z rhs = k_16B_z;
  Bi::Z k_expected = -Bi::Z(k_256B);

  // SUT
  Bi::Z sut = (-lhs) * rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mul_diff_sign_R_neg(void)
{
  Bi::Z lhs = k_16B_z;
  Bi::Z rhs = 8;
  Bi::Z k_expected = -Bi::Z(k_128B);

  // SUT
  Bi::Z sut = lhs * (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  Division ********************************************************************
//  *****************************************************************************
void BiTestSuite::Test_unary_div_identity(void)
{
  Bi::Z lhs = k_256B_z;
  Bi::Z rhs = 1;
  Bi::Z k_expected = k_256B_z;

  // SUT
  Bi::Z sut = lhs / rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_div_zero(void)
{
  Bi::Z lhs = 8192;
  Bi::Z rhs = 0;
  Bi::Z k_expected = 0;

  // SUT
  Bi::Z sut = lhs / rhs;

  // TODO: This code needs an error handling policy. For now it returns 0.
  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_div_same_sign_pos(void)
{
  Bi::Z lhs = k_65536B_z;
  Bi::Z rhs = k_256B_z;
  Bi::Z k_expected = 256;

  // SUT
  Bi::Z sut = lhs / rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_div_same_sign_neg(void)
{
  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = k_8B_z;
  Bi::Z k_expected = 3;

  // SUT
  Bi::Z sut = (-lhs) / (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_div_diff_sign_L_neg(void)
{
  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = 3;
  Bi::Z k_expected = -Bi::Z(k_8B_z);

  // SUT
  Bi::Z sut = (-lhs) / rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_div_diff_sign_R_neg(void)
{
  Bi::Z lhs = 8192;
  Bi::Z rhs = 1024;
  Bi::Z k_expected = -Bi::Z(8);

  // SUT
  Bi::Z sut = lhs / (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_div_divisor_larger(void)
{
  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_24B_z;
  Bi::Z k_expected = 0;

  // SUT
  Bi::Z sut = lhs / rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_div_divisor_equal(void)
{
  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = k_24B_z;
  Bi::Z k_expected = 1;

  // SUT
  Bi::Z sut = lhs / rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  Modulus *********************************************************************
//  *****************************************************************************
void BiTestSuite::Test_unary_mod_zero(void)
{
  Bi::Z lhs = 8192;
  Bi::Z rhs = 0;
  Bi::Z k_expected = 0;

  // SUT
  Bi::Z sut = lhs % rhs;

  // TODO: This code needs an error handling policy. For now it returns 0.
  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mod_same_sign_pos(void)
{
  Bi::Z lhs = Bi::Z(k_256B_z) - 1;
  Bi::Z rhs = k_16B_z;
  Bi::Z k_expected = Bi::Z(k_16B_z) - 1;

  // SUT
  Bi::Z sut = lhs % rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
  TS_ASSERT_LESS_THAN(sut, rhs);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mod_same_sign_neg(void)
{
  Bi::Z lhs = Bi::Z(k_256B_z) - 1;
  Bi::Z rhs = k_16B_z;
  Bi::Z k_expected = Bi::Z(k_16B_z) - 1;

  // SUT
  Bi::Z sut = (-lhs) % (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
  TS_ASSERT_LESS_THAN(sut, -rhs);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mod_diff_sign_L_neg(void)
{
  Bi::Z lhs = 96;
  Bi::Z rhs = 31;
  Bi::Z k_expected = -Bi::Z(3);

  // SUT
  Bi::Z sut = (-lhs) % rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
  TS_ASSERT_LESS_THAN(sut, rhs);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mod_diff_sign_R_neg(void)
{
  Bi::Z lhs = 98;
  Bi::Z rhs = 31;
  Bi::Z k_expected = -Bi::Z(5);

  // SUT
  Bi::Z sut = lhs % (-rhs);

  TS_ASSERT_EQUALS(k_expected, sut);
  TS_ASSERT_LESS_THAN(-sut, -rhs);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mod_divisor_larger(void)
{
  Bi::Z lhs = k_8B_z;
  Bi::Z rhs = k_24B_z;
  Bi::Z k_expected = k_8B_z;

  // SUT
  Bi::Z sut = lhs % rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
  TS_ASSERT_LESS_THAN(sut, rhs);
}

//  *****************************************************************************
void BiTestSuite::Test_unary_mod_divisor_equal(void)
{
  Bi::Z lhs = k_24B_z;
  Bi::Z rhs = k_24B_z;
  Bi::Z k_expected = 0;

  // SUT
  Bi::Z sut = lhs % rhs;

  TS_ASSERT_EQUALS(k_expected, sut);
  TS_ASSERT_LESS_THAN(sut, rhs);
}


//  *****************************************************************************
void BiTestSuite::Test_not(void)
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

//  Bit-Shift Tests *************************************************************
//  *****************************************************************************
void BiTestSuite::Test_lshift_eq_0(void)
{
  const Bi::Z k_expected = k_16B_z;
  Bi::Z sut = k_16B_z;

  // SUT 
  sut <<= 0;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_lshift_eq_1(void)
{
 const Bi::Z k_expected = k_32B_z;
  Bi::Z sut = k_16B_z;

  // SUT 
  sut <<= 1;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_lshift_eq_word_boundary(void)
{
  const Bi::Z k_expected = k_9EB_z;
  Bi::Z sut = 1;

  // SUT 
  sut <<= 63;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_lshift_eq_new_word(void)
{
  const Bi::Z k_expected = k_18EB_z;
  Bi::Z sut = 1;

  // SUT 
  sut <<= 64;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_lshift_eq_multiple_words(void)
{
  const Bi::Z k_expected = {0x00000000, 0x00000000, 0x00000000, 
                            0x00000000, 0x00000000, 0x00000000, 
                            0x00000001};
  Bi::Z sut = 1;

  // SUT 
  // Insert 2.5 64-bit words
  sut <<= 160;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_rshift_eq_0(void)
{
  const Bi::Z k_expected = k_16B_z;
  Bi::Z sut = k_16B_z;

  // SUT 
  sut >>= 0;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_rshift_eq_1(void)
{
 const Bi::Z k_expected = k_16B_z;
  Bi::Z sut = k_32B_z;

  // SUT 
  sut >>= 1;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_rshift_eq_word_boundary(void)
{
  const Bi::Z k_expected = 1;
  Bi::Z sut = k_4_5EB_z;

  // SUT 
  sut >>= 62;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_rshift_eq_remove_word(void)
{
  const Bi::Z k_expected = 1;
  Bi::Z sut = k_18EB_z;

  // SUT 
  sut >>= 64;

  TS_ASSERT_EQUALS(k_expected, sut);
}

//  *****************************************************************************
void BiTestSuite::Test_rshift_eq_multiple_words(void)
{
  const Bi::Z k_expected = 0x80000001ull;

  Bi::Z sut = { 0x00000000, 0x00000000, 0x00000000, 
                0x00000000, 0x00000000, 0x00000000, 
                0x80000001};

  // SUT 
  // reduce by 2.5 64-bit words
  sut >>= 160;

  TS_ASSERT_EQUALS(k_expected, sut);
}


#endif
