/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ParenPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ParenPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ParenPrinter >( tmp, argc, argv );
    return status;
}
bool suite_BiTestSuite_init = false;
#include "..\BiTestSuite.h"

static BiTestSuite suite_BiTestSuite;

static CxxTest::List Tests_BiTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_BiTestSuite( "../BiTestSuite.h", 44, "BiTestSuite", suite_BiTestSuite, Tests_BiTestSuite );

static class TestDescription_suite_BiTestSuite_Test_DefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_DefaultConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 94, "Test_DefaultConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_DefaultConstructor(); }
} testDescription_suite_BiTestSuite_Test_DefaultConstructor;

static class TestDescription_suite_BiTestSuite_Test_InitializerList_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_InitializerList_Constructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 95, "Test_InitializerList_Constructor" ) {}
 void runTest() { suite_BiTestSuite.Test_InitializerList_Constructor(); }
} testDescription_suite_BiTestSuite_Test_InitializerList_Constructor;

static class TestDescription_suite_BiTestSuite_Test_CopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_CopyConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 96, "Test_CopyConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_CopyConstructor(); }
} testDescription_suite_BiTestSuite_Test_CopyConstructor;

static class TestDescription_suite_BiTestSuite_Test_MoveConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_MoveConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 97, "Test_MoveConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_MoveConstructor(); }
} testDescription_suite_BiTestSuite_Test_MoveConstructor;

static class TestDescription_suite_BiTestSuite_Test_ValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_ValueConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 98, "Test_ValueConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_ValueConstructor(); }
} testDescription_suite_BiTestSuite_Test_ValueConstructor;

static class TestDescription_suite_BiTestSuite_Test_int_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_int_Constructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 99, "Test_int_Constructor" ) {}
 void runTest() { suite_BiTestSuite.Test_int_Constructor(); }
} testDescription_suite_BiTestSuite_Test_int_Constructor;

static class TestDescription_suite_BiTestSuite_Test_hex_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_hex_Constructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 100, "Test_hex_Constructor" ) {}
 void runTest() { suite_BiTestSuite.Test_hex_Constructor(); }
} testDescription_suite_BiTestSuite_Test_hex_Constructor;

static class TestDescription_suite_BiTestSuite_Test_Destructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_Destructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 102, "Test_Destructor" ) {}
 void runTest() { suite_BiTestSuite.Test_Destructor(); }
} testDescription_suite_BiTestSuite_Test_Destructor;

static class TestDescription_suite_BiTestSuite_Test_AssignOp : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_AssignOp() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 104, "Test_AssignOp" ) {}
 void runTest() { suite_BiTestSuite.Test_AssignOp(); }
} testDescription_suite_BiTestSuite_Test_AssignOp;

static class TestDescription_suite_BiTestSuite_Test_MoveOp : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_MoveOp() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 105, "Test_MoveOp" ) {}
 void runTest() { suite_BiTestSuite.Test_MoveOp(); }
} testDescription_suite_BiTestSuite_Test_MoveOp;

static class TestDescription_suite_BiTestSuite_Test_AssignOp_T : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_AssignOp_T() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 106, "Test_AssignOp_T" ) {}
 void runTest() { suite_BiTestSuite.Test_AssignOp_T(); }
} testDescription_suite_BiTestSuite_Test_AssignOp_T;

static class TestDescription_suite_BiTestSuite_Test_AssignOp_int : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_AssignOp_int() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 107, "Test_AssignOp_int" ) {}
 void runTest() { suite_BiTestSuite.Test_AssignOp_int(); }
} testDescription_suite_BiTestSuite_Test_AssignOp_int;

static class TestDescription_suite_BiTestSuite_Test_eq_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_eq_true() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 110, "Test_eq_true" ) {}
 void runTest() { suite_BiTestSuite.Test_eq_true(); }
} testDescription_suite_BiTestSuite_Test_eq_true;

static class TestDescription_suite_BiTestSuite_Test_eq_false_sign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_eq_false_sign() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 111, "Test_eq_false_sign" ) {}
 void runTest() { suite_BiTestSuite.Test_eq_false_sign(); }
} testDescription_suite_BiTestSuite_Test_eq_false_sign;

static class TestDescription_suite_BiTestSuite_Test_eq_false_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_eq_false_value() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 112, "Test_eq_false_value" ) {}
 void runTest() { suite_BiTestSuite.Test_eq_false_value(); }
} testDescription_suite_BiTestSuite_Test_eq_false_value;

static class TestDescription_suite_BiTestSuite_Test_not_eq_true_sign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_not_eq_true_sign() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 114, "Test_not_eq_true_sign" ) {}
 void runTest() { suite_BiTestSuite.Test_not_eq_true_sign(); }
} testDescription_suite_BiTestSuite_Test_not_eq_true_sign;

static class TestDescription_suite_BiTestSuite_Test_not_eq_true_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_not_eq_true_value() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 115, "Test_not_eq_true_value" ) {}
 void runTest() { suite_BiTestSuite.Test_not_eq_true_value(); }
} testDescription_suite_BiTestSuite_Test_not_eq_true_value;

static class TestDescription_suite_BiTestSuite_Test_not_eq_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_not_eq_false() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 116, "Test_not_eq_false" ) {}
 void runTest() { suite_BiTestSuite.Test_not_eq_false(); }
} testDescription_suite_BiTestSuite_Test_not_eq_false;

static class TestDescription_suite_BiTestSuite_Test_less_than_true_negative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_less_than_true_negative() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 118, "Test_less_than_true_negative" ) {}
 void runTest() { suite_BiTestSuite.Test_less_than_true_negative(); }
} testDescription_suite_BiTestSuite_Test_less_than_true_negative;

static class TestDescription_suite_BiTestSuite_Test_less_than_true_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_less_than_true_value() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 119, "Test_less_than_true_value" ) {}
 void runTest() { suite_BiTestSuite.Test_less_than_true_value(); }
} testDescription_suite_BiTestSuite_Test_less_than_true_value;

static class TestDescription_suite_BiTestSuite_Test_less_than_false_sign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_less_than_false_sign() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 120, "Test_less_than_false_sign" ) {}
 void runTest() { suite_BiTestSuite.Test_less_than_false_sign(); }
} testDescription_suite_BiTestSuite_Test_less_than_false_sign;

static class TestDescription_suite_BiTestSuite_Test_less_than_false_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_less_than_false_value() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 121, "Test_less_than_false_value" ) {}
 void runTest() { suite_BiTestSuite.Test_less_than_false_value(); }
} testDescription_suite_BiTestSuite_Test_less_than_false_value;

static class TestDescription_suite_BiTestSuite_Test_le_true_negative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_le_true_negative() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 123, "Test_le_true_negative" ) {}
 void runTest() { suite_BiTestSuite.Test_le_true_negative(); }
} testDescription_suite_BiTestSuite_Test_le_true_negative;

static class TestDescription_suite_BiTestSuite_Test_le_true_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_le_true_value() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 124, "Test_le_true_value" ) {}
 void runTest() { suite_BiTestSuite.Test_le_true_value(); }
} testDescription_suite_BiTestSuite_Test_le_true_value;

static class TestDescription_suite_BiTestSuite_Test_le_true_equal : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_le_true_equal() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 125, "Test_le_true_equal" ) {}
 void runTest() { suite_BiTestSuite.Test_le_true_equal(); }
} testDescription_suite_BiTestSuite_Test_le_true_equal;

static class TestDescription_suite_BiTestSuite_Test_le_false_sign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_le_false_sign() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 126, "Test_le_false_sign" ) {}
 void runTest() { suite_BiTestSuite.Test_le_false_sign(); }
} testDescription_suite_BiTestSuite_Test_le_false_sign;

static class TestDescription_suite_BiTestSuite_Test_le_false_value : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_le_false_value() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 127, "Test_le_false_value" ) {}
 void runTest() { suite_BiTestSuite.Test_le_false_value(); }
} testDescription_suite_BiTestSuite_Test_le_false_value;

static class TestDescription_suite_BiTestSuite_Test_greater_than_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_greater_than_true() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 129, "Test_greater_than_true" ) {}
 void runTest() { suite_BiTestSuite.Test_greater_than_true(); }
} testDescription_suite_BiTestSuite_Test_greater_than_true;

static class TestDescription_suite_BiTestSuite_Test_greater_than_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_greater_than_false() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 130, "Test_greater_than_false" ) {}
 void runTest() { suite_BiTestSuite.Test_greater_than_false(); }
} testDescription_suite_BiTestSuite_Test_greater_than_false;

static class TestDescription_suite_BiTestSuite_Test_ge_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_ge_true() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 132, "Test_ge_true" ) {}
 void runTest() { suite_BiTestSuite.Test_ge_true(); }
} testDescription_suite_BiTestSuite_Test_ge_true;

static class TestDescription_suite_BiTestSuite_Test_ge_true_equal : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_ge_true_equal() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 133, "Test_ge_true_equal" ) {}
 void runTest() { suite_BiTestSuite.Test_ge_true_equal(); }
} testDescription_suite_BiTestSuite_Test_ge_true_equal;

static class TestDescription_suite_BiTestSuite_Test_ge_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_ge_false() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 134, "Test_ge_false" ) {}
 void runTest() { suite_BiTestSuite.Test_ge_false(); }
} testDescription_suite_BiTestSuite_Test_ge_false;

static class TestDescription_suite_BiTestSuite_Test_negate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_negate() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 137, "Test_negate" ) {}
 void runTest() { suite_BiTestSuite.Test_negate(); }
} testDescription_suite_BiTestSuite_Test_negate;

static class TestDescription_suite_BiTestSuite_Test_unary_add_wo_carry : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_wo_carry() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 140, "Test_unary_add_wo_carry" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_wo_carry(); }
} testDescription_suite_BiTestSuite_Test_unary_add_wo_carry;

static class TestDescription_suite_BiTestSuite_Test_unary_add_w_carry : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_w_carry() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 141, "Test_unary_add_w_carry" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_w_carry(); }
} testDescription_suite_BiTestSuite_Test_unary_add_w_carry;

static class TestDescription_suite_BiTestSuite_Test_unary_add_w_ripple_carry : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_w_ripple_carry() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 142, "Test_unary_add_w_ripple_carry" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_w_ripple_carry(); }
} testDescription_suite_BiTestSuite_Test_unary_add_w_ripple_carry;

static class TestDescription_suite_BiTestSuite_Test_unary_add_identity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_identity() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 143, "Test_unary_add_identity" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_identity(); }
} testDescription_suite_BiTestSuite_Test_unary_add_identity;

static class TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_ls_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_ls_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 145, "Test_unary_add_same_sign_pos_L_ls_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_same_sign_pos_L_ls_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_ls_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_gr_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_gr_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 146, "Test_unary_add_same_sign_pos_L_gr_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_same_sign_pos_L_gr_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_gr_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_eq_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_eq_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 147, "Test_unary_add_same_sign_pos_L_eq_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_same_sign_pos_L_eq_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_same_sign_pos_L_eq_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_ls_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_ls_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 148, "Test_unary_add_same_sign_neg_L_ls_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_same_sign_neg_L_ls_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_ls_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_gr_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_gr_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 149, "Test_unary_add_same_sign_neg_L_gr_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_same_sign_neg_L_gr_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_gr_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_eq_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_eq_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 150, "Test_unary_add_same_sign_neg_L_eq_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_same_sign_neg_L_eq_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_same_sign_neg_L_eq_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_diff_sign_L_eq_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_diff_sign_L_eq_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 151, "Test_unary_add_diff_sign_L_eq_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_diff_sign_L_eq_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_diff_sign_L_eq_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_neg_L_mag_L : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_neg_L_mag_L() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 152, "Test_unary_add_neg_L_mag_L" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_neg_L_mag_L(); }
} testDescription_suite_BiTestSuite_Test_unary_add_neg_L_mag_L;

static class TestDescription_suite_BiTestSuite_Test_unary_add_neg_L_mag_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_neg_L_mag_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 153, "Test_unary_add_neg_L_mag_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_neg_L_mag_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_neg_L_mag_R;

static class TestDescription_suite_BiTestSuite_Test_unary_add_neg_R_mag_L : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_neg_R_mag_L() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 154, "Test_unary_add_neg_R_mag_L" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_neg_R_mag_L(); }
} testDescription_suite_BiTestSuite_Test_unary_add_neg_R_mag_L;

static class TestDescription_suite_BiTestSuite_Test_unary_add_neg_R_mag_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_neg_R_mag_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 155, "Test_unary_add_neg_R_mag_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_neg_R_mag_R(); }
} testDescription_suite_BiTestSuite_Test_unary_add_neg_R_mag_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_wo_borrow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_wo_borrow() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 158, "Test_unary_sub_wo_borrow" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_wo_borrow(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_wo_borrow;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_w_borrow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_w_borrow() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 159, "Test_unary_sub_w_borrow" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_w_borrow(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_w_borrow;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_w_ripple_borrow : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_w_ripple_borrow() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 160, "Test_unary_sub_w_ripple_borrow" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_w_ripple_borrow(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_w_ripple_borrow;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_identity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_identity() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 161, "Test_unary_sub_identity" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_identity(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_identity;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_ls_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_ls_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 163, "Test_unary_sub_same_sign_pos_L_ls_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_same_sign_pos_L_ls_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_ls_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_gr_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_gr_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 164, "Test_unary_sub_same_sign_pos_L_gr_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_same_sign_pos_L_gr_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_gr_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_eq_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_eq_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 165, "Test_unary_sub_same_sign_pos_L_eq_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_same_sign_pos_L_eq_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_same_sign_pos_L_eq_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_ls_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_ls_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 166, "Test_unary_sub_same_sign_neg_L_ls_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_same_sign_neg_L_ls_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_ls_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_gr_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_gr_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 167, "Test_unary_sub_same_sign_neg_L_gr_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_same_sign_neg_L_gr_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_gr_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_eq_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_eq_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 168, "Test_unary_sub_same_sign_neg_L_eq_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_same_sign_neg_L_eq_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_same_sign_neg_L_eq_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_diff_sign_L_eq_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_diff_sign_L_eq_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 169, "Test_unary_sub_diff_sign_L_eq_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_diff_sign_L_eq_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_diff_sign_L_eq_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_neg_L_mag_L : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_neg_L_mag_L() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 170, "Test_unary_sub_neg_L_mag_L" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_neg_L_mag_L(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_neg_L_mag_L;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_neg_L_mag_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_neg_L_mag_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 171, "Test_unary_sub_neg_L_mag_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_neg_L_mag_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_neg_L_mag_R;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_neg_R_mag_L : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_neg_R_mag_L() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 172, "Test_unary_sub_neg_R_mag_L" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_neg_R_mag_L(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_neg_R_mag_L;

static class TestDescription_suite_BiTestSuite_Test_unary_sub_neg_R_mag_R : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub_neg_R_mag_R() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 173, "Test_unary_sub_neg_R_mag_R" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub_neg_R_mag_R(); }
} testDescription_suite_BiTestSuite_Test_unary_sub_neg_R_mag_R;

static class TestDescription_suite_BiTestSuite_Test_unary_mul_identity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mul_identity() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 177, "Test_unary_mul_identity" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mul_identity(); }
} testDescription_suite_BiTestSuite_Test_unary_mul_identity;

static class TestDescription_suite_BiTestSuite_Test_unary_mul_zero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mul_zero() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 178, "Test_unary_mul_zero" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mul_zero(); }
} testDescription_suite_BiTestSuite_Test_unary_mul_zero;

static class TestDescription_suite_BiTestSuite_Test_unary_mul_same_sign_pos : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mul_same_sign_pos() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 179, "Test_unary_mul_same_sign_pos" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mul_same_sign_pos(); }
} testDescription_suite_BiTestSuite_Test_unary_mul_same_sign_pos;

static class TestDescription_suite_BiTestSuite_Test_unary_mul_same_sign_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mul_same_sign_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 180, "Test_unary_mul_same_sign_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mul_same_sign_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_mul_same_sign_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_mul_diff_sign_L_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mul_diff_sign_L_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 181, "Test_unary_mul_diff_sign_L_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mul_diff_sign_L_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_mul_diff_sign_L_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_mul_diff_sign_R_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mul_diff_sign_R_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 182, "Test_unary_mul_diff_sign_R_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mul_diff_sign_R_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_mul_diff_sign_R_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_div_identity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_identity() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 185, "Test_unary_div_identity" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_identity(); }
} testDescription_suite_BiTestSuite_Test_unary_div_identity;

static class TestDescription_suite_BiTestSuite_Test_unary_div_zero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_zero() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 186, "Test_unary_div_zero" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_zero(); }
} testDescription_suite_BiTestSuite_Test_unary_div_zero;

static class TestDescription_suite_BiTestSuite_Test_unary_div_same_sign_pos : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_same_sign_pos() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 187, "Test_unary_div_same_sign_pos" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_same_sign_pos(); }
} testDescription_suite_BiTestSuite_Test_unary_div_same_sign_pos;

static class TestDescription_suite_BiTestSuite_Test_unary_div_same_sign_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_same_sign_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 188, "Test_unary_div_same_sign_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_same_sign_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_div_same_sign_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_div_diff_sign_L_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_diff_sign_L_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 189, "Test_unary_div_diff_sign_L_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_diff_sign_L_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_div_diff_sign_L_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_div_diff_sign_R_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_diff_sign_R_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 190, "Test_unary_div_diff_sign_R_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_diff_sign_R_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_div_diff_sign_R_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_div_divisor_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_divisor_larger() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 191, "Test_unary_div_divisor_larger" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_divisor_larger(); }
} testDescription_suite_BiTestSuite_Test_unary_div_divisor_larger;

static class TestDescription_suite_BiTestSuite_Test_unary_div_divisor_equal : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div_divisor_equal() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 192, "Test_unary_div_divisor_equal" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div_divisor_equal(); }
} testDescription_suite_BiTestSuite_Test_unary_div_divisor_equal;

static class TestDescription_suite_BiTestSuite_Test_unary_mod_zero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod_zero() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 195, "Test_unary_mod_zero" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod_zero(); }
} testDescription_suite_BiTestSuite_Test_unary_mod_zero;

static class TestDescription_suite_BiTestSuite_Test_unary_mod_same_sign_pos : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod_same_sign_pos() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 196, "Test_unary_mod_same_sign_pos" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod_same_sign_pos(); }
} testDescription_suite_BiTestSuite_Test_unary_mod_same_sign_pos;

static class TestDescription_suite_BiTestSuite_Test_unary_mod_same_sign_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod_same_sign_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 197, "Test_unary_mod_same_sign_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod_same_sign_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_mod_same_sign_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_mod_diff_sign_L_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod_diff_sign_L_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 198, "Test_unary_mod_diff_sign_L_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod_diff_sign_L_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_mod_diff_sign_L_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_mod_diff_sign_R_neg : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod_diff_sign_R_neg() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 199, "Test_unary_mod_diff_sign_R_neg" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod_diff_sign_R_neg(); }
} testDescription_suite_BiTestSuite_Test_unary_mod_diff_sign_R_neg;

static class TestDescription_suite_BiTestSuite_Test_unary_mod_divisor_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod_divisor_larger() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 200, "Test_unary_mod_divisor_larger" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod_divisor_larger(); }
} testDescription_suite_BiTestSuite_Test_unary_mod_divisor_larger;

static class TestDescription_suite_BiTestSuite_Test_unary_mod_divisor_equal : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod_divisor_equal() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 201, "Test_unary_mod_divisor_equal" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod_divisor_equal(); }
} testDescription_suite_BiTestSuite_Test_unary_mod_divisor_equal;

static class TestDescription_suite_BiTestSuite_Test_not : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_not() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 204, "Test_not" ) {}
 void runTest() { suite_BiTestSuite.Test_not(); }
} testDescription_suite_BiTestSuite_Test_not;

static class TestDescription_suite_BiTestSuite_Test_and_eq : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_and_eq() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 205, "Test_and_eq" ) {}
 void runTest() { suite_BiTestSuite.Test_and_eq(); }
} testDescription_suite_BiTestSuite_Test_and_eq;

static class TestDescription_suite_BiTestSuite_Test_or_eq : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_or_eq() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 206, "Test_or_eq" ) {}
 void runTest() { suite_BiTestSuite.Test_or_eq(); }
} testDescription_suite_BiTestSuite_Test_or_eq;

static class TestDescription_suite_BiTestSuite_Test_xor_eq : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_xor_eq() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 207, "Test_xor_eq" ) {}
 void runTest() { suite_BiTestSuite.Test_xor_eq(); }
} testDescription_suite_BiTestSuite_Test_xor_eq;

static class TestDescription_suite_BiTestSuite_Test_lshift_eq_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_lshift_eq_0() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 211, "Test_lshift_eq_0" ) {}
 void runTest() { suite_BiTestSuite.Test_lshift_eq_0(); }
} testDescription_suite_BiTestSuite_Test_lshift_eq_0;

static class TestDescription_suite_BiTestSuite_Test_lshift_eq_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_lshift_eq_1() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 212, "Test_lshift_eq_1" ) {}
 void runTest() { suite_BiTestSuite.Test_lshift_eq_1(); }
} testDescription_suite_BiTestSuite_Test_lshift_eq_1;

static class TestDescription_suite_BiTestSuite_Test_lshift_eq_word_boundary : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_lshift_eq_word_boundary() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 213, "Test_lshift_eq_word_boundary" ) {}
 void runTest() { suite_BiTestSuite.Test_lshift_eq_word_boundary(); }
} testDescription_suite_BiTestSuite_Test_lshift_eq_word_boundary;

static class TestDescription_suite_BiTestSuite_Test_lshift_eq_new_word : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_lshift_eq_new_word() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 214, "Test_lshift_eq_new_word" ) {}
 void runTest() { suite_BiTestSuite.Test_lshift_eq_new_word(); }
} testDescription_suite_BiTestSuite_Test_lshift_eq_new_word;

static class TestDescription_suite_BiTestSuite_Test_lshift_eq_multiple_words : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_lshift_eq_multiple_words() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 215, "Test_lshift_eq_multiple_words" ) {}
 void runTest() { suite_BiTestSuite.Test_lshift_eq_multiple_words(); }
} testDescription_suite_BiTestSuite_Test_lshift_eq_multiple_words;

static class TestDescription_suite_BiTestSuite_Test_rshift_eq_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_rshift_eq_0() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 217, "Test_rshift_eq_0" ) {}
 void runTest() { suite_BiTestSuite.Test_rshift_eq_0(); }
} testDescription_suite_BiTestSuite_Test_rshift_eq_0;

static class TestDescription_suite_BiTestSuite_Test_rshift_eq_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_rshift_eq_1() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 218, "Test_rshift_eq_1" ) {}
 void runTest() { suite_BiTestSuite.Test_rshift_eq_1(); }
} testDescription_suite_BiTestSuite_Test_rshift_eq_1;

static class TestDescription_suite_BiTestSuite_Test_rshift_eq_word_boundary : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_rshift_eq_word_boundary() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 219, "Test_rshift_eq_word_boundary" ) {}
 void runTest() { suite_BiTestSuite.Test_rshift_eq_word_boundary(); }
} testDescription_suite_BiTestSuite_Test_rshift_eq_word_boundary;

static class TestDescription_suite_BiTestSuite_Test_rshift_eq_remove_word : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_rshift_eq_remove_word() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 220, "Test_rshift_eq_remove_word" ) {}
 void runTest() { suite_BiTestSuite.Test_rshift_eq_remove_word(); }
} testDescription_suite_BiTestSuite_Test_rshift_eq_remove_word;

static class TestDescription_suite_BiTestSuite_Test_rshift_eq_multiple_words : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_rshift_eq_multiple_words() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 221, "Test_rshift_eq_multiple_words" ) {}
 void runTest() { suite_BiTestSuite.Test_rshift_eq_multiple_words(); }
} testDescription_suite_BiTestSuite_Test_rshift_eq_multiple_words;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
