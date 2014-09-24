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
bool suite_TestArrayDataSuite_init = false;
#include "..\TestArrayProxySuite.h"

static TestArrayDataSuite suite_TestArrayDataSuite;

static CxxTest::List Tests_TestArrayDataSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestArrayDataSuite( "../TestArrayProxySuite.h", 63, "TestArrayDataSuite", suite_TestArrayDataSuite, Tests_TestArrayDataSuite );

static class TestDescription_suite_TestArrayDataSuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 102, "TestDtor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestDtor(); }
} testDescription_suite_TestArrayDataSuite_TestDtor;

static class TestDescription_suite_TestArrayDataSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 103, "TestCopyConstructor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestCopyConstructor(); }
} testDescription_suite_TestArrayDataSuite_TestCopyConstructor;

static class TestDescription_suite_TestArrayDataSuite_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 104, "TestValueConstructor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestValueConstructor(); }
} testDescription_suite_TestArrayDataSuite_TestValueConstructor;

static class TestDescription_suite_TestArrayDataSuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 105, "TestAssignment" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAssignment(); }
} testDescription_suite_TestArrayDataSuite_TestAssignment;

static class TestDescription_suite_TestArrayDataSuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 106, "TestValueAssignment" ) {}
 void runTest() { suite_TestArrayDataSuite.TestValueAssignment(); }
} testDescription_suite_TestArrayDataSuite_TestValueAssignment;

static class TestDescription_suite_TestArrayDataSuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 109, "TestOpEquals" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpEquals(); }
} testDescription_suite_TestArrayDataSuite_TestOpEquals;

static class TestDescription_suite_TestArrayDataSuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 110, "TestOpEquals_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpEquals_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpEquals_false;

static class TestDescription_suite_TestArrayDataSuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 111, "TestOpNotEquals" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpNotEquals(); }
} testDescription_suite_TestArrayDataSuite_TestOpNotEquals;

static class TestDescription_suite_TestArrayDataSuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 112, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpNotEquals_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpNotEquals_false;

static class TestDescription_suite_TestArrayDataSuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 113, "TestOpLessThan" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpLessThan(); }
} testDescription_suite_TestArrayDataSuite_TestOpLessThan;

static class TestDescription_suite_TestArrayDataSuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 114, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpLessThan_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpLessThan_false;

static class TestDescription_suite_TestArrayDataSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 117, "TestClear" ) {}
 void runTest() { suite_TestArrayDataSuite.TestClear(); }
} testDescription_suite_TestArrayDataSuite_TestClear;

static class TestDescription_suite_TestArrayDataSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 118, "TestSize" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSize(); }
} testDescription_suite_TestArrayDataSuite_TestSize;

static class TestDescription_suite_TestArrayDataSuite_TestSizeOf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSizeOf() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 119, "TestSizeOf" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSizeOf(); }
} testDescription_suite_TestArrayDataSuite_TestSizeOf;

static class TestDescription_suite_TestArrayDataSuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestGet() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 122, "TestGet" ) {}
 void runTest() { suite_TestArrayDataSuite.TestGet(); }
} testDescription_suite_TestArrayDataSuite_TestGet;

static class TestDescription_suite_TestArrayDataSuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSet() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 123, "TestSet" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSet(); }
} testDescription_suite_TestArrayDataSuite_TestSet;

static class TestDescription_suite_TestArrayDataSuite_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAt_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 125, "TestAt_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAt_const(); }
} testDescription_suite_TestArrayDataSuite_TestAt_const;

static class TestDescription_suite_TestArrayDataSuite_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAt() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 126, "TestAt" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAt(); }
} testDescription_suite_TestArrayDataSuite_TestAt;

static class TestDescription_suite_TestArrayDataSuite_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 127, "TestOpSquare_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpSquare_const(); }
} testDescription_suite_TestArrayDataSuite_TestOpSquare_const;

static class TestDescription_suite_TestArrayDataSuite_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 128, "TestOpSquare" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpSquare(); }
} testDescription_suite_TestArrayDataSuite_TestOpSquare;

static class TestDescription_suite_TestArrayDataSuite_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestFront_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 129, "TestFront_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestFront_const(); }
} testDescription_suite_TestArrayDataSuite_TestFront_const;

static class TestDescription_suite_TestArrayDataSuite_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestFront() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 130, "TestFront" ) {}
 void runTest() { suite_TestArrayDataSuite.TestFront(); }
} testDescription_suite_TestArrayDataSuite_TestFront;

static class TestDescription_suite_TestArrayDataSuite_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBack_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 131, "TestBack_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBack_const(); }
} testDescription_suite_TestArrayDataSuite_TestBack_const;

static class TestDescription_suite_TestArrayDataSuite_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBack() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 132, "TestBack" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBack(); }
} testDescription_suite_TestArrayDataSuite_TestBack;

static class TestDescription_suite_TestArrayDataSuite_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBegin() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 135, "TestBegin" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBegin(); }
} testDescription_suite_TestArrayDataSuite_TestBegin;

static class TestDescription_suite_TestArrayDataSuite_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestEnd() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 136, "TestEnd" ) {}
 void runTest() { suite_TestArrayDataSuite.TestEnd(); }
} testDescription_suite_TestArrayDataSuite_TestEnd;

static class TestDescription_suite_TestArrayDataSuite_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestRBegin() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 137, "TestRBegin" ) {}
 void runTest() { suite_TestArrayDataSuite.TestRBegin(); }
} testDescription_suite_TestArrayDataSuite_TestRBegin;

static class TestDescription_suite_TestArrayDataSuite_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestREnd() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 138, "TestREnd" ) {}
 void runTest() { suite_TestArrayDataSuite.TestREnd(); }
} testDescription_suite_TestArrayDataSuite_TestREnd;

#include "..\testbitfieldarray.h"

static TestBitFieldArray suite_TestBitFieldArray;

static CxxTest::List Tests_TestBitFieldArray = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestBitFieldArray( "../testbitfieldarray.h", 63, "TestBitFieldArray", suite_TestBitFieldArray, Tests_TestBitFieldArray );

static class TestDescription_suite_TestBitFieldArray_TestStatic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestStatic() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 119, "TestStatic" ) {}
 void runTest() { suite_TestBitFieldArray.TestStatic(); }
} testDescription_suite_TestBitFieldArray_TestStatic;

static class TestDescription_suite_TestBitFieldArray_TestDefaultConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestDefaultConstructor() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 122, "TestDefaultConstructor" ) {}
 void runTest() { suite_TestBitFieldArray.TestDefaultConstructor(); }
} testDescription_suite_TestBitFieldArray_TestDefaultConstructor;

static class TestDescription_suite_TestBitFieldArray_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 123, "TestCopyConstructor" ) {}
 void runTest() { suite_TestBitFieldArray.TestCopyConstructor(); }
} testDescription_suite_TestBitFieldArray_TestCopyConstructor;

static class TestDescription_suite_TestBitFieldArray_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 124, "TestValueConstructor" ) {}
 void runTest() { suite_TestBitFieldArray.TestValueConstructor(); }
} testDescription_suite_TestBitFieldArray_TestValueConstructor;

static class TestDescription_suite_TestBitFieldArray_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestAssignment() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 125, "TestAssignment" ) {}
 void runTest() { suite_TestBitFieldArray.TestAssignment(); }
} testDescription_suite_TestBitFieldArray_TestAssignment;

static class TestDescription_suite_TestBitFieldArray_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 126, "TestValueAssignment" ) {}
 void runTest() { suite_TestBitFieldArray.TestValueAssignment(); }
} testDescription_suite_TestBitFieldArray_TestValueAssignment;

static class TestDescription_suite_TestBitFieldArray_TestEmpty_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestEmpty_true() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 129, "TestEmpty_true" ) {}
 void runTest() { suite_TestBitFieldArray.TestEmpty_true(); }
} testDescription_suite_TestBitFieldArray_TestEmpty_true;

static class TestDescription_suite_TestBitFieldArray_TestEmpty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestEmpty_false() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 130, "TestEmpty_false" ) {}
 void runTest() { suite_TestBitFieldArray.TestEmpty_false(); }
} testDescription_suite_TestBitFieldArray_TestEmpty_false;

static class TestDescription_suite_TestBitFieldArray_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestSize() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 131, "TestSize" ) {}
 void runTest() { suite_TestBitFieldArray.TestSize(); }
} testDescription_suite_TestBitFieldArray_TestSize;

static class TestDescription_suite_TestBitFieldArray_TestSizeOf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestSizeOf() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 132, "TestSizeOf" ) {}
 void runTest() { suite_TestBitFieldArray.TestSizeOf(); }
} testDescription_suite_TestBitFieldArray_TestSizeOf;

static class TestDescription_suite_TestBitFieldArray_TestData_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestData_const() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 135, "TestData_const" ) {}
 void runTest() { suite_TestBitFieldArray.TestData_const(); }
} testDescription_suite_TestBitFieldArray_TestData_const;

static class TestDescription_suite_TestBitFieldArray_TestData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestData() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 136, "TestData" ) {}
 void runTest() { suite_TestBitFieldArray.TestData(); }
} testDescription_suite_TestBitFieldArray_TestData;

static class TestDescription_suite_TestBitFieldArray_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestAt_const() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 137, "TestAt_const" ) {}
 void runTest() { suite_TestBitFieldArray.TestAt_const(); }
} testDescription_suite_TestBitFieldArray_TestAt_const;

static class TestDescription_suite_TestBitFieldArray_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestAt() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 138, "TestAt" ) {}
 void runTest() { suite_TestBitFieldArray.TestAt(); }
} testDescription_suite_TestBitFieldArray_TestAt;

static class TestDescription_suite_TestBitFieldArray_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 139, "TestOpSquare_const" ) {}
 void runTest() { suite_TestBitFieldArray.TestOpSquare_const(); }
} testDescription_suite_TestBitFieldArray_TestOpSquare_const;

static class TestDescription_suite_TestBitFieldArray_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 140, "TestOpSquare" ) {}
 void runTest() { suite_TestBitFieldArray.TestOpSquare(); }
} testDescription_suite_TestBitFieldArray_TestOpSquare;

static class TestDescription_suite_TestBitFieldArray_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestFront_const() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 141, "TestFront_const" ) {}
 void runTest() { suite_TestBitFieldArray.TestFront_const(); }
} testDescription_suite_TestBitFieldArray_TestFront_const;

static class TestDescription_suite_TestBitFieldArray_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestFront() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 142, "TestFront" ) {}
 void runTest() { suite_TestBitFieldArray.TestFront(); }
} testDescription_suite_TestBitFieldArray_TestFront;

static class TestDescription_suite_TestBitFieldArray_TestFront_BitFields : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestFront_BitFields() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 143, "TestFront_BitFields" ) {}
 void runTest() { suite_TestBitFieldArray.TestFront_BitFields(); }
} testDescription_suite_TestBitFieldArray_TestFront_BitFields;

static class TestDescription_suite_TestBitFieldArray_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestBack_const() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 144, "TestBack_const" ) {}
 void runTest() { suite_TestBitFieldArray.TestBack_const(); }
} testDescription_suite_TestBitFieldArray_TestBack_const;

static class TestDescription_suite_TestBitFieldArray_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestBack() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 145, "TestBack" ) {}
 void runTest() { suite_TestBitFieldArray.TestBack(); }
} testDescription_suite_TestBitFieldArray_TestBack;

static class TestDescription_suite_TestBitFieldArray_TestBack_BitFields : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestBack_BitFields() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 146, "TestBack_BitFields" ) {}
 void runTest() { suite_TestBitFieldArray.TestBack_BitFields(); }
} testDescription_suite_TestBitFieldArray_TestBack_BitFields;

static class TestDescription_suite_TestBitFieldArray_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestBegin() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 149, "TestBegin" ) {}
 void runTest() { suite_TestBitFieldArray.TestBegin(); }
} testDescription_suite_TestBitFieldArray_TestBegin;

static class TestDescription_suite_TestBitFieldArray_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestEnd() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 150, "TestEnd" ) {}
 void runTest() { suite_TestBitFieldArray.TestEnd(); }
} testDescription_suite_TestBitFieldArray_TestEnd;

static class TestDescription_suite_TestBitFieldArray_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestRBegin() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 151, "TestRBegin" ) {}
 void runTest() { suite_TestBitFieldArray.TestRBegin(); }
} testDescription_suite_TestBitFieldArray_TestRBegin;

static class TestDescription_suite_TestBitFieldArray_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitFieldArray_TestREnd() : CxxTest::RealTestDescription( Tests_TestBitFieldArray, suiteDescription_TestBitFieldArray, 152, "TestREnd" ) {}
 void runTest() { suite_TestBitFieldArray.TestREnd(); }
} testDescription_suite_TestBitFieldArray_TestREnd;

#include "..\TestDynamicMessageSuite.h"

static TestDynamicMessageSuite suite_TestDynamicMessageSuite;

static CxxTest::List Tests_TestDynamicMessageSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDynamicMessageSuite( "../TestDynamicMessageSuite.h", 123, "TestDynamicMessageSuite", suite_TestDynamicMessageSuite, Tests_TestDynamicMessageSuite );

static class TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 387, "TestHasDynamic_true" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestHasDynamic_true(); }
} testDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 388, "TestDynamicFields_none" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_none(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 389, "TestDynamicFields_basic" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_basic(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 390, "TestDynamicFields_message" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_message(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message;

static class TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 393, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 394, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestCopyCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestCopyCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 395, "TestValueCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestValueCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestValueCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 396, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 397, "Testempty" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 398, "Testempty_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 399, "TestSize" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestSize(); }
} testDescription_suite_TestDynamicMessageSuite_TestSize;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 400, "Testis_host_order" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 401, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 402, "TestAssign" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssign(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssign;

static class TestDescription_suite_TestDynamicMessageSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 403, "TestClear" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestClear(); }
} testDescription_suite_TestDynamicMessageSuite_TestClear;

static class TestDescription_suite_TestDynamicMessageSuite_TestClone : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestClone() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 404, "TestClone" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestClone(); }
} testDescription_suite_TestDynamicMessageSuite_TestClone;

static class TestDescription_suite_TestDynamicMessageSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 405, "Testdata" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testdata(); }
} testDescription_suite_TestDynamicMessageSuite_Testdata;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 408, "Testto_host" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_host(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_host;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 409, "Testto_network" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_network(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_network;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 410, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_big_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_big_endian;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 411, "Testto_little_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_little_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_little_endian;

#include "..\TestDynTypePermsSuite.h"

static TestDynTypePermsSuite suite_TestDynTypePermsSuite;

static CxxTest::List Tests_TestDynTypePermsSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDynTypePermsSuite( "../TestDynTypePermsSuite.h", 55, "TestDynTypePermsSuite", suite_TestDynTypePermsSuite, Tests_TestDynTypePermsSuite );

static class TestDescription_suite_TestDynTypePermsSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 222, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 223, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestCopyCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestCopyCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 224, "TestValueCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestValueCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestValueCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 225, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynTypePermsSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 226, "Testempty" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testempty(); }
} testDescription_suite_TestDynTypePermsSuite_Testempty;

static class TestDescription_suite_TestDynTypePermsSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 227, "Testempty_false" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testempty_false(); }
} testDescription_suite_TestDynTypePermsSuite_Testempty_false;

static class TestDescription_suite_TestDynTypePermsSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 228, "TestSize" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestSize(); }
} testDescription_suite_TestDynTypePermsSuite_TestSize;

static class TestDescription_suite_TestDynTypePermsSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 229, "Testis_host_order" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testis_host_order(); }
} testDescription_suite_TestDynTypePermsSuite_Testis_host_order;

static class TestDescription_suite_TestDynTypePermsSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 230, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynTypePermsSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynTypePermsSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 231, "TestAssign" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestAssign(); }
} testDescription_suite_TestDynTypePermsSuite_TestAssign;

static class TestDescription_suite_TestDynTypePermsSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 232, "TestClear" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestClear(); }
} testDescription_suite_TestDynTypePermsSuite_TestClear;

static class TestDescription_suite_TestDynTypePermsSuite_TestClone : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestClone() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 233, "TestClone" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestClone(); }
} testDescription_suite_TestDynTypePermsSuite_TestClone;

static class TestDescription_suite_TestDynTypePermsSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 234, "Testdata" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testdata(); }
} testDescription_suite_TestDynTypePermsSuite_Testdata;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 237, "Testto_host" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_host(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_host;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 238, "Testto_network" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_network(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_network;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 239, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_big_endian(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_big_endian;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 240, "Testto_little_endian" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_little_endian(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_little_endian;

#include "..\TestFocusedDynamicMessageSuite.h"

static TestFocusedDynamicMessageSuite suite_TestFocusedDynamicMessageSuite;

static CxxTest::List Tests_TestFocusedDynamicMessageSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestFocusedDynamicMessageSuite( "../TestFocusedDynamicMessageSuite.h", 53, "TestFocusedDynamicMessageSuite", suite_TestFocusedDynamicMessageSuite, Tests_TestFocusedDynamicMessageSuite );

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 77, "Test_write_array_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_array_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 78, "Test_read_array_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_array_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 80, "Test_write_array_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_array_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 81, "Test_read_array_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_array_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_fundamental : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_fundamental() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 83, "Test_write_vector_fundamental" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_fundamental(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_fundamental;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_fundamental : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_fundamental() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 84, "Test_read_vector_fundamental" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_fundamental(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_fundamental;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_fixed_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_fixed_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 86, "Test_write_vector_with_nested_fixed_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_with_nested_fixed_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_fixed_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_fixed_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_fixed_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 87, "Test_read_vector_with_nested_fixed_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_with_nested_fixed_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_fixed_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_dynamic_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_dynamic_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 89, "Test_write_vector_with_nested_dynamic_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_with_nested_dynamic_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_dynamic_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_dynamic_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_dynamic_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 90, "Test_read_vector_with_nested_dynamic_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_with_nested_dynamic_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_dynamic_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 92, "Test_write_vector_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 93, "Test_read_vector_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 95, "Test_write_vector_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 96, "Test_read_vector_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_vectors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_vectors() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 98, "Test_write_vector_of_vectors" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_of_vectors(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_vectors;

#include "..\TestVectorProxySuite.h"

static TestVectorProxySuite suite_TestVectorProxySuite;

static CxxTest::List Tests_TestVectorProxySuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestVectorProxySuite( "../TestVectorProxySuite.h", 61, "TestVectorProxySuite", suite_TestVectorProxySuite, Tests_TestVectorProxySuite );

static class TestDescription_suite_TestVectorProxySuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 109, "TestDtor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestDtor(); }
} testDescription_suite_TestVectorProxySuite_TestDtor;

static class TestDescription_suite_TestVectorProxySuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 110, "TestCopyConstructor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestCopyConstructor(); }
} testDescription_suite_TestVectorProxySuite_TestCopyConstructor;

static class TestDescription_suite_TestVectorProxySuite_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 111, "TestValueConstructor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestValueConstructor(); }
} testDescription_suite_TestVectorProxySuite_TestValueConstructor;

static class TestDescription_suite_TestVectorProxySuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 112, "TestAssignment" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAssignment(); }
} testDescription_suite_TestVectorProxySuite_TestAssignment;

static class TestDescription_suite_TestVectorProxySuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 113, "TestValueAssignment" ) {}
 void runTest() { suite_TestVectorProxySuite.TestValueAssignment(); }
} testDescription_suite_TestVectorProxySuite_TestValueAssignment;

static class TestDescription_suite_TestVectorProxySuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 116, "TestOpEquals" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpEquals(); }
} testDescription_suite_TestVectorProxySuite_TestOpEquals;

static class TestDescription_suite_TestVectorProxySuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 117, "TestOpEquals_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpEquals_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpEquals_false;

static class TestDescription_suite_TestVectorProxySuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 118, "TestOpNotEquals" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpNotEquals(); }
} testDescription_suite_TestVectorProxySuite_TestOpNotEquals;

static class TestDescription_suite_TestVectorProxySuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 119, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpNotEquals_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpNotEquals_false;

static class TestDescription_suite_TestVectorProxySuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 120, "TestOpLessThan" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpLessThan(); }
} testDescription_suite_TestVectorProxySuite_TestOpLessThan;

static class TestDescription_suite_TestVectorProxySuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 121, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpLessThan_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpLessThan_false;

static class TestDescription_suite_TestVectorProxySuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestClear() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 124, "TestClear" ) {}
 void runTest() { suite_TestVectorProxySuite.TestClear(); }
} testDescription_suite_TestVectorProxySuite_TestClear;

static class TestDescription_suite_TestVectorProxySuite_TestReserve : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestReserve() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 125, "TestReserve" ) {}
 void runTest() { suite_TestVectorProxySuite.TestReserve(); }
} testDescription_suite_TestVectorProxySuite_TestReserve;

static class TestDescription_suite_TestVectorProxySuite_TestCapacity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestCapacity() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 126, "TestCapacity" ) {}
 void runTest() { suite_TestVectorProxySuite.TestCapacity(); }
} testDescription_suite_TestVectorProxySuite_TestCapacity;

static class TestDescription_suite_TestVectorProxySuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSize() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 127, "TestSize" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSize(); }
} testDescription_suite_TestVectorProxySuite_TestSize;

static class TestDescription_suite_TestVectorProxySuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestGet() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 130, "TestGet" ) {}
 void runTest() { suite_TestVectorProxySuite.TestGet(); }
} testDescription_suite_TestVectorProxySuite_TestGet;

static class TestDescription_suite_TestVectorProxySuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSet() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 131, "TestSet" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSet(); }
} testDescription_suite_TestVectorProxySuite_TestSet;

static class TestDescription_suite_TestVectorProxySuite_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAt_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 133, "TestAt_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAt_const(); }
} testDescription_suite_TestVectorProxySuite_TestAt_const;

static class TestDescription_suite_TestVectorProxySuite_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAt() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 134, "TestAt" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAt(); }
} testDescription_suite_TestVectorProxySuite_TestAt;

static class TestDescription_suite_TestVectorProxySuite_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 135, "TestOpSquare_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpSquare_const(); }
} testDescription_suite_TestVectorProxySuite_TestOpSquare_const;

static class TestDescription_suite_TestVectorProxySuite_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 136, "TestOpSquare" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpSquare(); }
} testDescription_suite_TestVectorProxySuite_TestOpSquare;

static class TestDescription_suite_TestVectorProxySuite_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestFront_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 137, "TestFront_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestFront_const(); }
} testDescription_suite_TestVectorProxySuite_TestFront_const;

static class TestDescription_suite_TestVectorProxySuite_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestFront() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 138, "TestFront" ) {}
 void runTest() { suite_TestVectorProxySuite.TestFront(); }
} testDescription_suite_TestVectorProxySuite_TestFront;

static class TestDescription_suite_TestVectorProxySuite_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBack_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 139, "TestBack_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBack_const(); }
} testDescription_suite_TestVectorProxySuite_TestBack_const;

static class TestDescription_suite_TestVectorProxySuite_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 140, "TestBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBack(); }
} testDescription_suite_TestVectorProxySuite_TestBack;

static class TestDescription_suite_TestVectorProxySuite_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBegin() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 143, "TestBegin" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBegin(); }
} testDescription_suite_TestVectorProxySuite_TestBegin;

static class TestDescription_suite_TestVectorProxySuite_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestEnd() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 144, "TestEnd" ) {}
 void runTest() { suite_TestVectorProxySuite.TestEnd(); }
} testDescription_suite_TestVectorProxySuite_TestEnd;

static class TestDescription_suite_TestVectorProxySuite_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestRBegin() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 145, "TestRBegin" ) {}
 void runTest() { suite_TestVectorProxySuite.TestRBegin(); }
} testDescription_suite_TestVectorProxySuite_TestRBegin;

static class TestDescription_suite_TestVectorProxySuite_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestREnd() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 146, "TestREnd" ) {}
 void runTest() { suite_TestVectorProxySuite.TestREnd(); }
} testDescription_suite_TestVectorProxySuite_TestREnd;

static class TestDescription_suite_TestVectorProxySuite_TestErase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestErase() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 149, "TestErase" ) {}
 void runTest() { suite_TestVectorProxySuite.TestErase(); }
} testDescription_suite_TestVectorProxySuite_TestErase;

static class TestDescription_suite_TestVectorProxySuite_TestErase_range : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestErase_range() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 150, "TestErase_range" ) {}
 void runTest() { suite_TestVectorProxySuite.TestErase_range(); }
} testDescription_suite_TestVectorProxySuite_TestErase_range;

static class TestDescription_suite_TestVectorProxySuite_TestPushBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPushBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 151, "TestPushBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPushBack(); }
} testDescription_suite_TestVectorProxySuite_TestPushBack;

static class TestDescription_suite_TestVectorProxySuite_TestPushBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPushBack_empty() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 152, "TestPushBack_empty" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPushBack_empty(); }
} testDescription_suite_TestVectorProxySuite_TestPushBack_empty;

static class TestDescription_suite_TestVectorProxySuite_TestPopBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPopBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 153, "TestPopBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPopBack(); }
} testDescription_suite_TestVectorProxySuite_TestPopBack;

static class TestDescription_suite_TestVectorProxySuite_TestPopBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPopBack_empty() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 154, "TestPopBack_empty" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPopBack_empty(); }
} testDescription_suite_TestVectorProxySuite_TestPopBack_empty;

static class TestDescription_suite_TestVectorProxySuite_TestResize_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_smaller() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 155, "TestResize_smaller" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_smaller(); }
} testDescription_suite_TestVectorProxySuite_TestResize_smaller;

static class TestDescription_suite_TestVectorProxySuite_TestResize_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_larger() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 156, "TestResize_larger" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_larger(); }
} testDescription_suite_TestVectorProxySuite_TestResize_larger;

static class TestDescription_suite_TestVectorProxySuite_TestResize_default_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_default_smaller() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 157, "TestResize_default_smaller" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_default_smaller(); }
} testDescription_suite_TestVectorProxySuite_TestResize_default_smaller;

static class TestDescription_suite_TestVectorProxySuite_TestResize_default_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_default_larger() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 158, "TestResize_default_larger" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_default_larger(); }
} testDescription_suite_TestVectorProxySuite_TestResize_default_larger;

static class TestDescription_suite_TestVectorProxySuite_TestSwap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSwap() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 159, "TestSwap" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSwap(); }
} testDescription_suite_TestVectorProxySuite_TestSwap;

static class TestDescription_suite_TestVectorProxySuite_TestSwap_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSwap_vector() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 160, "TestSwap_vector" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSwap_vector(); }
} testDescription_suite_TestVectorProxySuite_TestSwap_vector;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
