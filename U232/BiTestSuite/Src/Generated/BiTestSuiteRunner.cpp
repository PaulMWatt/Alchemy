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
CxxTest::StaticSuiteDescription suiteDescription_BiTestSuite( "../BiTestSuite.h", 52, "BiTestSuite", suite_BiTestSuite, Tests_BiTestSuite );

static class TestDescription_suite_BiTestSuite_Test_DefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_DefaultConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 89, "Test_DefaultConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_DefaultConstructor(); }
} testDescription_suite_BiTestSuite_Test_DefaultConstructor;

static class TestDescription_suite_BiTestSuite_Test_InitializerList_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_InitializerList_Constructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 90, "Test_InitializerList_Constructor" ) {}
 void runTest() { suite_BiTestSuite.Test_InitializerList_Constructor(); }
} testDescription_suite_BiTestSuite_Test_InitializerList_Constructor;

static class TestDescription_suite_BiTestSuite_Test_CopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_CopyConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 91, "Test_CopyConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_CopyConstructor(); }
} testDescription_suite_BiTestSuite_Test_CopyConstructor;

static class TestDescription_suite_BiTestSuite_Test_MoveConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_MoveConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 92, "Test_MoveConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_MoveConstructor(); }
} testDescription_suite_BiTestSuite_Test_MoveConstructor;

static class TestDescription_suite_BiTestSuite_Test_ValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_ValueConstructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 93, "Test_ValueConstructor" ) {}
 void runTest() { suite_BiTestSuite.Test_ValueConstructor(); }
} testDescription_suite_BiTestSuite_Test_ValueConstructor;

static class TestDescription_suite_BiTestSuite_Test_int_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_int_Constructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 94, "Test_int_Constructor" ) {}
 void runTest() { suite_BiTestSuite.Test_int_Constructor(); }
} testDescription_suite_BiTestSuite_Test_int_Constructor;

static class TestDescription_suite_BiTestSuite_Test_hex_Constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_hex_Constructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 95, "Test_hex_Constructor" ) {}
 void runTest() { suite_BiTestSuite.Test_hex_Constructor(); }
} testDescription_suite_BiTestSuite_Test_hex_Constructor;

static class TestDescription_suite_BiTestSuite_Test_Destructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_Destructor() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 97, "Test_Destructor" ) {}
 void runTest() { suite_BiTestSuite.Test_Destructor(); }
} testDescription_suite_BiTestSuite_Test_Destructor;

static class TestDescription_suite_BiTestSuite_Test_AssignOp : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_AssignOp() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 99, "Test_AssignOp" ) {}
 void runTest() { suite_BiTestSuite.Test_AssignOp(); }
} testDescription_suite_BiTestSuite_Test_AssignOp;

static class TestDescription_suite_BiTestSuite_Test_MoveOp : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_MoveOp() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 100, "Test_MoveOp" ) {}
 void runTest() { suite_BiTestSuite.Test_MoveOp(); }
} testDescription_suite_BiTestSuite_Test_MoveOp;

static class TestDescription_suite_BiTestSuite_Test_AssignOp_T : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_AssignOp_T() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 101, "Test_AssignOp_T" ) {}
 void runTest() { suite_BiTestSuite.Test_AssignOp_T(); }
} testDescription_suite_BiTestSuite_Test_AssignOp_T;

static class TestDescription_suite_BiTestSuite_Test_AssignOp_int : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_Test_AssignOp_int() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 102, "Test_AssignOp_int" ) {}
 void runTest() { suite_BiTestSuite.Test_AssignOp_int(); }
} testDescription_suite_BiTestSuite_Test_AssignOp_int;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
