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

static class TestDescription_suite_BiTestSuite_Test_unary_add_single : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_single() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 139, "Test_unary_add_single" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_single(); }
} testDescription_suite_BiTestSuite_Test_unary_add_single;

static class TestDescription_suite_BiTestSuite_Test_unary_add_multiple : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_multiple() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 140, "Test_unary_add_multiple" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_multiple(); }
} testDescription_suite_BiTestSuite_Test_unary_add_multiple;

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

static class TestDescription_suite_BiTestSuite_Test_unary_add_negative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_negative() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 144, "Test_unary_add_negative" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_negative(); }
} testDescription_suite_BiTestSuite_Test_unary_add_negative;

static class TestDescription_suite_BiTestSuite_Test_unary_add_both_negative : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_add_both_negative() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 145, "Test_unary_add_both_negative" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_add_both_negative(); }
} testDescription_suite_BiTestSuite_Test_unary_add_both_negative;

static class TestDescription_suite_BiTestSuite_Test_unary_sub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_sub() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 149, "Test_unary_sub" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_sub(); }
} testDescription_suite_BiTestSuite_Test_unary_sub;

static class TestDescription_suite_BiTestSuite_Test_unary_mul : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mul() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 150, "Test_unary_mul" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mul(); }
} testDescription_suite_BiTestSuite_Test_unary_mul;

static class TestDescription_suite_BiTestSuite_Test_unary_div : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_div() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 151, "Test_unary_div" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_div(); }
} testDescription_suite_BiTestSuite_Test_unary_div;

static class TestDescription_suite_BiTestSuite_Test_unary_mod : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_unary_mod() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 152, "Test_unary_mod" ) {}
 void runTest() { suite_BiTestSuite.Test_unary_mod(); }
} testDescription_suite_BiTestSuite_Test_unary_mod;

static class TestDescription_suite_BiTestSuite_Test_not : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_not() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 155, "Test_not" ) {}
 void runTest() { suite_BiTestSuite.Test_not(); }
} testDescription_suite_BiTestSuite_Test_not;

static class TestDescription_suite_BiTestSuite_Test_and_eq : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_and_eq() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 156, "Test_and_eq" ) {}
 void runTest() { suite_BiTestSuite.Test_and_eq(); }
} testDescription_suite_BiTestSuite_Test_and_eq;

static class TestDescription_suite_BiTestSuite_Test_or_eq : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_or_eq() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 157, "Test_or_eq" ) {}
 void runTest() { suite_BiTestSuite.Test_or_eq(); }
} testDescription_suite_BiTestSuite_Test_or_eq;

static class TestDescription_suite_BiTestSuite_Test_xor_eq : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_xor_eq() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 158, "Test_xor_eq" ) {}
 void runTest() { suite_BiTestSuite.Test_xor_eq(); }
} testDescription_suite_BiTestSuite_Test_xor_eq;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
