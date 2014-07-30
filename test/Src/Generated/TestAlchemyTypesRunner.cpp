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
#include "C:\Development\GitGub\Alchemy\test\Src\TestArrayProxySuite.h"

static TestArrayDataSuite suite_TestArrayDataSuite;

static CxxTest::List Tests_TestArrayDataSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestArrayDataSuite( "../TestArrayProxySuite.h", 71, "TestArrayDataSuite", suite_TestArrayDataSuite, Tests_TestArrayDataSuite );

static class TestDescription_suite_TestArrayDataSuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 110, "TestDtor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestDtor(); }
} testDescription_suite_TestArrayDataSuite_TestDtor;

static class TestDescription_suite_TestArrayDataSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 111, "TestCopyConstructor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestCopyConstructor(); }
} testDescription_suite_TestArrayDataSuite_TestCopyConstructor;

static class TestDescription_suite_TestArrayDataSuite_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 112, "TestValueConstructor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestValueConstructor(); }
} testDescription_suite_TestArrayDataSuite_TestValueConstructor;

static class TestDescription_suite_TestArrayDataSuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 113, "TestAssignment" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAssignment(); }
} testDescription_suite_TestArrayDataSuite_TestAssignment;

static class TestDescription_suite_TestArrayDataSuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 114, "TestValueAssignment" ) {}
 void runTest() { suite_TestArrayDataSuite.TestValueAssignment(); }
} testDescription_suite_TestArrayDataSuite_TestValueAssignment;

static class TestDescription_suite_TestArrayDataSuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 117, "TestOpEquals" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpEquals(); }
} testDescription_suite_TestArrayDataSuite_TestOpEquals;

static class TestDescription_suite_TestArrayDataSuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 118, "TestOpEquals_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpEquals_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpEquals_false;

static class TestDescription_suite_TestArrayDataSuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 119, "TestOpNotEquals" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpNotEquals(); }
} testDescription_suite_TestArrayDataSuite_TestOpNotEquals;

static class TestDescription_suite_TestArrayDataSuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 120, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpNotEquals_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpNotEquals_false;

static class TestDescription_suite_TestArrayDataSuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 121, "TestOpLessThan" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpLessThan(); }
} testDescription_suite_TestArrayDataSuite_TestOpLessThan;

static class TestDescription_suite_TestArrayDataSuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 122, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpLessThan_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpLessThan_false;

static class TestDescription_suite_TestArrayDataSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 125, "TestClear" ) {}
 void runTest() { suite_TestArrayDataSuite.TestClear(); }
} testDescription_suite_TestArrayDataSuite_TestClear;

static class TestDescription_suite_TestArrayDataSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 126, "TestSize" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSize(); }
} testDescription_suite_TestArrayDataSuite_TestSize;

static class TestDescription_suite_TestArrayDataSuite_TestSizeOf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSizeOf() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 127, "TestSizeOf" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSizeOf(); }
} testDescription_suite_TestArrayDataSuite_TestSizeOf;

static class TestDescription_suite_TestArrayDataSuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestGet() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 130, "TestGet" ) {}
 void runTest() { suite_TestArrayDataSuite.TestGet(); }
} testDescription_suite_TestArrayDataSuite_TestGet;

static class TestDescription_suite_TestArrayDataSuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSet() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 131, "TestSet" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSet(); }
} testDescription_suite_TestArrayDataSuite_TestSet;

static class TestDescription_suite_TestArrayDataSuite_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAt_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 133, "TestAt_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAt_const(); }
} testDescription_suite_TestArrayDataSuite_TestAt_const;

static class TestDescription_suite_TestArrayDataSuite_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAt() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 134, "TestAt" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAt(); }
} testDescription_suite_TestArrayDataSuite_TestAt;

static class TestDescription_suite_TestArrayDataSuite_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 135, "TestOpSquare_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpSquare_const(); }
} testDescription_suite_TestArrayDataSuite_TestOpSquare_const;

static class TestDescription_suite_TestArrayDataSuite_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 136, "TestOpSquare" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpSquare(); }
} testDescription_suite_TestArrayDataSuite_TestOpSquare;

static class TestDescription_suite_TestArrayDataSuite_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestFront_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 137, "TestFront_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestFront_const(); }
} testDescription_suite_TestArrayDataSuite_TestFront_const;

static class TestDescription_suite_TestArrayDataSuite_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestFront() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 138, "TestFront" ) {}
 void runTest() { suite_TestArrayDataSuite.TestFront(); }
} testDescription_suite_TestArrayDataSuite_TestFront;

static class TestDescription_suite_TestArrayDataSuite_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBack_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 139, "TestBack_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBack_const(); }
} testDescription_suite_TestArrayDataSuite_TestBack_const;

static class TestDescription_suite_TestArrayDataSuite_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBack() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 140, "TestBack" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBack(); }
} testDescription_suite_TestArrayDataSuite_TestBack;

static class TestDescription_suite_TestArrayDataSuite_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBegin() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 143, "TestBegin" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBegin(); }
} testDescription_suite_TestArrayDataSuite_TestBegin;

static class TestDescription_suite_TestArrayDataSuite_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestEnd() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 144, "TestEnd" ) {}
 void runTest() { suite_TestArrayDataSuite.TestEnd(); }
} testDescription_suite_TestArrayDataSuite_TestEnd;

static class TestDescription_suite_TestArrayDataSuite_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestRBegin() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 145, "TestRBegin" ) {}
 void runTest() { suite_TestArrayDataSuite.TestRBegin(); }
} testDescription_suite_TestArrayDataSuite_TestRBegin;

static class TestDescription_suite_TestArrayDataSuite_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestREnd() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 146, "TestREnd" ) {}
 void runTest() { suite_TestArrayDataSuite.TestREnd(); }
} testDescription_suite_TestArrayDataSuite_TestREnd;

#include "C:\Development\GitGub\Alchemy\test\Src\TestBitSetMsgFieldSuite.h"

static TestBitSetFieldSuite suite_TestBitSetFieldSuite;

static CxxTest::List Tests_TestBitSetFieldSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestBitSetFieldSuite( "../TestBitSetMsgFieldSuite.h", 90, "TestBitSetFieldSuite", suite_TestBitSetFieldSuite, Tests_TestBitSetFieldSuite );

static class TestDescription_suite_TestBitSetFieldSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 147, "TestCopyConstructor" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestCopyConstructor(); }
} testDescription_suite_TestBitSetFieldSuite_TestCopyConstructor;

static class TestDescription_suite_TestBitSetFieldSuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 148, "TestAssignment" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestAssignment(); }
} testDescription_suite_TestBitSetFieldSuite_TestAssignment;

static class TestDescription_suite_TestBitSetFieldSuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 149, "TestValueAssignment" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestValueAssignment(); }
} testDescription_suite_TestBitSetFieldSuite_TestValueAssignment;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 152, "TestOpEquals" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpEquals(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpEquals;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 153, "TestOpEquals_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpEquals_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpEquals_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 154, "TestOpNotEquals" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpNotEquals(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpNotEquals;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 155, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpNotEquals_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpNotEquals_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 156, "TestOpLessThan" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThan(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThan;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 157, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThan_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThan_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 158, "TestOpLessThanOrEqual" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThanOrEqual(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 159, "TestOpLessThanOrEqual_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThanOrEqual_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 160, "TestOpGreaterThan" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThan(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 161, "TestOpGreaterThan_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThan_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 162, "TestOpGreaterThanOrEqual" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThanOrEqual(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 163, "TestOpGreaterThanOrEqual_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThanOrEqual_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 166, "TestClear" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestClear(); }
} testDescription_suite_TestBitSetFieldSuite_TestClear;

static class TestDescription_suite_TestBitSetFieldSuite_TestClear_Empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestClear_Empty() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 167, "TestClear_Empty" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestClear_Empty(); }
} testDescription_suite_TestBitSetFieldSuite_TestClear_Empty;

static class TestDescription_suite_TestBitSetFieldSuite_TestGet_Const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestGet_Const() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 170, "TestGet_Const" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestGet_Const(); }
} testDescription_suite_TestBitSetFieldSuite_TestGet_Const;

static class TestDescription_suite_TestBitSetFieldSuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestGet() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 171, "TestGet" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestGet(); }
} testDescription_suite_TestBitSetFieldSuite_TestGet;

static class TestDescription_suite_TestBitSetFieldSuite_TestGet_NonZeroOffset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestGet_NonZeroOffset() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 172, "TestGet_NonZeroOffset" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestGet_NonZeroOffset(); }
} testDescription_suite_TestBitSetFieldSuite_TestGet_NonZeroOffset;

static class TestDescription_suite_TestBitSetFieldSuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestSet() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 174, "TestSet" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestSet(); }
} testDescription_suite_TestBitSetFieldSuite_TestSet;

static class TestDescription_suite_TestBitSetFieldSuite_TestSet_NonZeroOffset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestSet_NonZeroOffset() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 175, "TestSet_NonZeroOffset" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestSet_NonZeroOffset(); }
} testDescription_suite_TestBitSetFieldSuite_TestSet_NonZeroOffset;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Ctor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Ctor() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 179, "TestBitField_Ctor" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Ctor(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Ctor;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 180, "TestBitField_Assignment" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Assignment(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment_Truncate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment_Truncate() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 181, "TestBitField_Assignment_Truncate" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Assignment_Truncate(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment_Truncate;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 182, "TestBitField_Conversion" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Conversion(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion_Empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion_Empty() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 183, "TestBitField_Conversion_Empty" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Conversion_Empty(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion_Empty;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Attach : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Attach() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 184, "TestBitField_Attach" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Attach(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Attach;

#include "C:\Development\GitGub\Alchemy\test\Src\TestByteOrder.h"

static TestByteOrder suite_TestByteOrder;

static CxxTest::List Tests_TestByteOrder = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestByteOrder( "../TestByteOrder.h", 47, "TestByteOrder", suite_TestByteOrder, Tests_TestByteOrder );

static class TestDescription_suite_TestByteOrder_TestEndianSwap_no_op : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_no_op() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 73, "TestEndianSwap_no_op" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_no_op(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_no_op;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_int16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_int16() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 74, "TestEndianSwap_int16" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_int16(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_int16;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_uint16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_uint16() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 75, "TestEndianSwap_uint16" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_uint16(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_uint16;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_int32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_int32() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 76, "TestEndianSwap_int32" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_int32(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_int32;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_uint32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_uint32() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 77, "TestEndianSwap_uint32" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_uint32(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_uint32;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_int64 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_int64() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 78, "TestEndianSwap_int64" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_int64(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_int64;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_uint64 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_uint64() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 79, "TestEndianSwap_uint64" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_uint64(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_uint64;

static class TestDescription_suite_TestByteOrder_TestEndianType_no_op : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianType_no_op() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 81, "TestEndianType_no_op" ) {}
 void runTest() { suite_TestByteOrder.TestEndianType_no_op(); }
} testDescription_suite_TestByteOrder_TestEndianType_no_op;

static class TestDescription_suite_TestByteOrder_TestEndianType_swap_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianType_swap_order() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 82, "TestEndianType_swap_order" ) {}
 void runTest() { suite_TestByteOrder.TestEndianType_swap_order(); }
} testDescription_suite_TestByteOrder_TestEndianType_swap_order;

static class TestDescription_suite_TestByteOrder_TestHostByteOrder_to_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestHostByteOrder_to_host() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 84, "TestHostByteOrder_to_host" ) {}
 void runTest() { suite_TestByteOrder.TestHostByteOrder_to_host(); }
} testDescription_suite_TestByteOrder_TestHostByteOrder_to_host;

static class TestDescription_suite_TestByteOrder_TestHostByteOrder_to_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestHostByteOrder_to_network() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 85, "TestHostByteOrder_to_network" ) {}
 void runTest() { suite_TestByteOrder.TestHostByteOrder_to_network(); }
} testDescription_suite_TestByteOrder_TestHostByteOrder_to_network;

static class TestDescription_suite_TestByteOrder_TestNetByteOrder_to_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestNetByteOrder_to_host() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 86, "TestNetByteOrder_to_host" ) {}
 void runTest() { suite_TestByteOrder.TestNetByteOrder_to_host(); }
} testDescription_suite_TestByteOrder_TestNetByteOrder_to_host;

static class TestDescription_suite_TestByteOrder_TestNetByteOrder_to_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestNetByteOrder_to_network() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 87, "TestNetByteOrder_to_network" ) {}
 void runTest() { suite_TestByteOrder.TestNetByteOrder_to_network(); }
} testDescription_suite_TestByteOrder_TestNetByteOrder_to_network;

#include "C:\Development\GitGub\Alchemy\test\Src\TestDynamicMessageSuite.h"

static TestDynamicMessageSuite suite_TestDynamicMessageSuite;

static CxxTest::List Tests_TestDynamicMessageSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDynamicMessageSuite( "../TestDynamicMessageSuite.h", 116, "TestDynamicMessageSuite", suite_TestDynamicMessageSuite, Tests_TestDynamicMessageSuite );

static class TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 380, "TestHasDynamic_true" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestHasDynamic_true(); }
} testDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 381, "TestDynamicFields_none" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_none(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 382, "TestDynamicFields_basic" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_basic(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 383, "TestDynamicFields_message" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_message(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message;

static class TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 386, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 387, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestCopyCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestCopyCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 388, "TestValueCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestValueCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestValueCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 389, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 390, "Testempty" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 391, "Testempty_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 392, "TestSize" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestSize(); }
} testDescription_suite_TestDynamicMessageSuite_TestSize;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 393, "Testis_host_order" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 394, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 395, "TestAssign" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssign(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssign;

static class TestDescription_suite_TestDynamicMessageSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 396, "TestClear" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestClear(); }
} testDescription_suite_TestDynamicMessageSuite_TestClear;

static class TestDescription_suite_TestDynamicMessageSuite_TestClone : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestClone() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 397, "TestClone" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestClone(); }
} testDescription_suite_TestDynamicMessageSuite_TestClone;

static class TestDescription_suite_TestDynamicMessageSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 398, "Testdata" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testdata(); }
} testDescription_suite_TestDynamicMessageSuite_Testdata;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 401, "Testto_host" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_host(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_host;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 402, "Testto_network" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_network(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_network;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 403, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_big_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_big_endian;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 404, "Testto_little_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_little_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_little_endian;

#include "C:\Development\GitGub\Alchemy\test\Src\TestDynamicPermutationsSuite.h"

static TestDynPermSuite suite_TestDynPermSuite;

static CxxTest::List Tests_TestDynPermSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDynPermSuite( "../TestDynamicPermutationsSuite.h", 82, "TestDynPermSuite", suite_TestDynPermSuite, Tests_TestDynPermSuite );

static class TestDescription_suite_TestDynPermSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 347, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynPermSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynPermSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynPermSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 348, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynPermSuite.TestCopyCtor(); }
} testDescription_suite_TestDynPermSuite_TestCopyCtor;

static class TestDescription_suite_TestDynPermSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 349, "TestValueCtor" ) {}
 void runTest() { suite_TestDynPermSuite.TestValueCtor(); }
} testDescription_suite_TestDynPermSuite_TestValueCtor;

static class TestDescription_suite_TestDynPermSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 350, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynPermSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynPermSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynPermSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 351, "Testempty" ) {}
 void runTest() { suite_TestDynPermSuite.Testempty(); }
} testDescription_suite_TestDynPermSuite_Testempty;

static class TestDescription_suite_TestDynPermSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 352, "Testempty_false" ) {}
 void runTest() { suite_TestDynPermSuite.Testempty_false(); }
} testDescription_suite_TestDynPermSuite_Testempty_false;

static class TestDescription_suite_TestDynPermSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 353, "TestSize" ) {}
 void runTest() { suite_TestDynPermSuite.TestSize(); }
} testDescription_suite_TestDynPermSuite_TestSize;

static class TestDescription_suite_TestDynPermSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 354, "Testis_host_order" ) {}
 void runTest() { suite_TestDynPermSuite.Testis_host_order(); }
} testDescription_suite_TestDynPermSuite_Testis_host_order;

static class TestDescription_suite_TestDynPermSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 355, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynPermSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynPermSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynPermSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 356, "TestAssign" ) {}
 void runTest() { suite_TestDynPermSuite.TestAssign(); }
} testDescription_suite_TestDynPermSuite_TestAssign;

static class TestDescription_suite_TestDynPermSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 357, "TestClear" ) {}
 void runTest() { suite_TestDynPermSuite.TestClear(); }
} testDescription_suite_TestDynPermSuite_TestClear;

static class TestDescription_suite_TestDynPermSuite_TestClone : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_TestClone() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 358, "TestClone" ) {}
 void runTest() { suite_TestDynPermSuite.TestClone(); }
} testDescription_suite_TestDynPermSuite_TestClone;

static class TestDescription_suite_TestDynPermSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 359, "Testdata" ) {}
 void runTest() { suite_TestDynPermSuite.Testdata(); }
} testDescription_suite_TestDynPermSuite_Testdata;

static class TestDescription_suite_TestDynPermSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 362, "Testto_host" ) {}
 void runTest() { suite_TestDynPermSuite.Testto_host(); }
} testDescription_suite_TestDynPermSuite_Testto_host;

static class TestDescription_suite_TestDynPermSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 363, "Testto_network" ) {}
 void runTest() { suite_TestDynPermSuite.Testto_network(); }
} testDescription_suite_TestDynPermSuite_Testto_network;

static class TestDescription_suite_TestDynPermSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 364, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynPermSuite.Testto_big_endian(); }
} testDescription_suite_TestDynPermSuite_Testto_big_endian;

static class TestDescription_suite_TestDynPermSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynPermSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynPermSuite, suiteDescription_TestDynPermSuite, 365, "Testto_little_endian" ) {}
 void runTest() { suite_TestDynPermSuite.Testto_little_endian(); }
} testDescription_suite_TestDynPermSuite_Testto_little_endian;

#include "C:\Development\GitGub\Alchemy\test\Src\TestMessageSuite.h"

static TestMessageSuite suite_TestMessageSuite;

static CxxTest::List Tests_TestMessageSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestMessageSuite( "../TestMessageSuite.h", 54, "TestMessageSuite", suite_TestMessageSuite, Tests_TestMessageSuite );

static class TestDescription_suite_TestMessageSuite_TestHasDynamic_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestHasDynamic_false() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 161, "TestHasDynamic_false" ) {}
 void runTest() { suite_TestMessageSuite.TestHasDynamic_false(); }
} testDescription_suite_TestMessageSuite_TestHasDynamic_false;

static class TestDescription_suite_TestMessageSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 162, "TestDefaultCtor" ) {}
 void runTest() { suite_TestMessageSuite.TestDefaultCtor(); }
} testDescription_suite_TestMessageSuite_TestDefaultCtor;

static class TestDescription_suite_TestMessageSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 163, "TestCopyCtor" ) {}
 void runTest() { suite_TestMessageSuite.TestCopyCtor(); }
} testDescription_suite_TestMessageSuite_TestCopyCtor;

static class TestDescription_suite_TestMessageSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 164, "TestValueCtor" ) {}
 void runTest() { suite_TestMessageSuite.TestValueCtor(); }
} testDescription_suite_TestMessageSuite_TestValueCtor;

static class TestDescription_suite_TestMessageSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 165, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestMessageSuite.TestAssignmentOperator(); }
} testDescription_suite_TestMessageSuite_TestAssignmentOperator;

static class TestDescription_suite_TestMessageSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 166, "Testempty" ) {}
 void runTest() { suite_TestMessageSuite.Testempty(); }
} testDescription_suite_TestMessageSuite_Testempty;

static class TestDescription_suite_TestMessageSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 167, "Testempty_false" ) {}
 void runTest() { suite_TestMessageSuite.Testempty_false(); }
} testDescription_suite_TestMessageSuite_Testempty_false;

static class TestDescription_suite_TestMessageSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 168, "TestSize" ) {}
 void runTest() { suite_TestMessageSuite.TestSize(); }
} testDescription_suite_TestMessageSuite_TestSize;

static class TestDescription_suite_TestMessageSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 169, "Testis_host_order" ) {}
 void runTest() { suite_TestMessageSuite.Testis_host_order(); }
} testDescription_suite_TestMessageSuite_Testis_host_order;

static class TestDescription_suite_TestMessageSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 170, "Testis_host_order_false" ) {}
 void runTest() { suite_TestMessageSuite.Testis_host_order_false(); }
} testDescription_suite_TestMessageSuite_Testis_host_order_false;

static class TestDescription_suite_TestMessageSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 171, "TestAssign" ) {}
 void runTest() { suite_TestMessageSuite.TestAssign(); }
} testDescription_suite_TestMessageSuite_TestAssign;

static class TestDescription_suite_TestMessageSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 172, "TestClear" ) {}
 void runTest() { suite_TestMessageSuite.TestClear(); }
} testDescription_suite_TestMessageSuite_TestClear;

static class TestDescription_suite_TestMessageSuite_TestClone : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestClone() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 173, "TestClone" ) {}
 void runTest() { suite_TestMessageSuite.TestClone(); }
} testDescription_suite_TestMessageSuite_TestClone;

static class TestDescription_suite_TestMessageSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 174, "Testdata" ) {}
 void runTest() { suite_TestMessageSuite.Testdata(); }
} testDescription_suite_TestMessageSuite_Testdata;

static class TestDescription_suite_TestMessageSuite_TestSingleFieldMsg_Basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestSingleFieldMsg_Basic() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 177, "TestSingleFieldMsg_Basic" ) {}
 void runTest() { suite_TestMessageSuite.TestSingleFieldMsg_Basic(); }
} testDescription_suite_TestMessageSuite_TestSingleFieldMsg_Basic;

static class TestDescription_suite_TestMessageSuite_TestSingleFieldMsg_Nested : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestSingleFieldMsg_Nested() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 178, "TestSingleFieldMsg_Nested" ) {}
 void runTest() { suite_TestMessageSuite.TestSingleFieldMsg_Nested(); }
} testDescription_suite_TestMessageSuite_TestSingleFieldMsg_Nested;

static class TestDescription_suite_TestMessageSuite_TestSingleFieldMsg_Bitlist : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_TestSingleFieldMsg_Bitlist() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 179, "TestSingleFieldMsg_Bitlist" ) {}
 void runTest() { suite_TestMessageSuite.TestSingleFieldMsg_Bitlist(); }
} testDescription_suite_TestMessageSuite_TestSingleFieldMsg_Bitlist;

static class TestDescription_suite_TestMessageSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 182, "Testto_host" ) {}
 void runTest() { suite_TestMessageSuite.Testto_host(); }
} testDescription_suite_TestMessageSuite_Testto_host;

static class TestDescription_suite_TestMessageSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 183, "Testto_network" ) {}
 void runTest() { suite_TestMessageSuite.Testto_network(); }
} testDescription_suite_TestMessageSuite_Testto_network;

static class TestDescription_suite_TestMessageSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 184, "Testto_big_endian" ) {}
 void runTest() { suite_TestMessageSuite.Testto_big_endian(); }
} testDescription_suite_TestMessageSuite_Testto_big_endian;

static class TestDescription_suite_TestMessageSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMessageSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestMessageSuite, suiteDescription_TestMessageSuite, 185, "Testto_little_endian" ) {}
 void runTest() { suite_TestMessageSuite.Testto_little_endian(); }
} testDescription_suite_TestMessageSuite_Testto_little_endian;

#include "C:\Development\GitGub\Alchemy\test\Src\TestMeta.h"

static TestMeta suite_TestMeta;

static CxxTest::List Tests_TestMeta = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestMeta( "../TestMeta.h", 49, "TestMeta", suite_TestMeta, Tests_TestMeta );

static class TestDescription_suite_TestMeta_Test_value_if_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_value_if_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 82, "Test_value_if_true" ) {}
 void runTest() { suite_TestMeta.Test_value_if_true(); }
} testDescription_suite_TestMeta_Test_value_if_true;

static class TestDescription_suite_TestMeta_Test_value_if_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_value_if_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 83, "Test_value_if_false" ) {}
 void runTest() { suite_TestMeta.Test_value_if_false(); }
} testDescription_suite_TestMeta_Test_value_if_false;

static class TestDescription_suite_TestMeta_Test_one_or_zero_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_one_or_zero_1() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 84, "Test_one_or_zero_1" ) {}
 void runTest() { suite_TestMeta.Test_one_or_zero_1(); }
} testDescription_suite_TestMeta_Test_one_or_zero_1;

static class TestDescription_suite_TestMeta_Test_one_or_zero_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_one_or_zero_0() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 85, "Test_one_or_zero_0" ) {}
 void runTest() { suite_TestMeta.Test_one_or_zero_0(); }
} testDescription_suite_TestMeta_Test_one_or_zero_0;

static class TestDescription_suite_TestMeta_Test_type_check : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_check() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 88, "Test_type_check" ) {}
 void runTest() { suite_TestMeta.Test_type_check(); }
} testDescription_suite_TestMeta_Test_type_check;

static class TestDescription_suite_TestMeta_Test_not_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_not_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 91, "Test_not_true" ) {}
 void runTest() { suite_TestMeta.Test_not_true(); }
} testDescription_suite_TestMeta_Test_not_true;

static class TestDescription_suite_TestMeta_Test_not_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_not_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 92, "Test_not_false" ) {}
 void runTest() { suite_TestMeta.Test_not_false(); }
} testDescription_suite_TestMeta_Test_not_false;

static class TestDescription_suite_TestMeta_Test_and_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_and_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 93, "Test_and_true" ) {}
 void runTest() { suite_TestMeta.Test_and_true(); }
} testDescription_suite_TestMeta_Test_and_true;

static class TestDescription_suite_TestMeta_Test_and_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_and_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 94, "Test_and_false" ) {}
 void runTest() { suite_TestMeta.Test_and_false(); }
} testDescription_suite_TestMeta_Test_and_false;

static class TestDescription_suite_TestMeta_Test_or_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_or_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 95, "Test_or_true" ) {}
 void runTest() { suite_TestMeta.Test_or_true(); }
} testDescription_suite_TestMeta_Test_or_true;

static class TestDescription_suite_TestMeta_Test_or_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_or_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 96, "Test_or_false" ) {}
 void runTest() { suite_TestMeta.Test_or_false(); }
} testDescription_suite_TestMeta_Test_or_false;

static class TestDescription_suite_TestMeta_Test_type_container_T : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_T() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 100, "Test_type_container_T" ) {}
 void runTest() { suite_TestMeta.Test_type_container_T(); }
} testDescription_suite_TestMeta_Test_type_container_T;

static class TestDescription_suite_TestMeta_Test_type_container_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_empty() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 103, "Test_type_container_empty" ) {}
 void runTest() { suite_TestMeta.Test_type_container_empty(); }
} testDescription_suite_TestMeta_Test_type_container_empty;

static class TestDescription_suite_TestMeta_Test_type_container_TypeList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_TypeList() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 104, "Test_type_container_TypeList" ) {}
 void runTest() { suite_TestMeta.Test_type_container_TypeList(); }
} testDescription_suite_TestMeta_Test_type_container_TypeList;

static class TestDescription_suite_TestMeta_Test_type_container_traits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_traits() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 105, "Test_type_container_traits" ) {}
 void runTest() { suite_TestMeta.Test_type_container_traits(); }
} testDescription_suite_TestMeta_Test_type_container_traits;

static class TestDescription_suite_TestMeta_TestContainerSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestContainerSize() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 108, "TestContainerSize" ) {}
 void runTest() { suite_TestMeta.TestContainerSize(); }
} testDescription_suite_TestMeta_TestContainerSize;

static class TestDescription_suite_TestMeta_TestTypeAt_1_to_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestTypeAt_1_to_max() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 114, "TestTypeAt_1_to_max" ) {}
 void runTest() { suite_TestMeta.TestTypeAt_1_to_max(); }
} testDescription_suite_TestMeta_TestTypeAt_1_to_max;

static class TestDescription_suite_TestMeta_TestSizeOf_char : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_char() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 118, "TestSizeOf_char" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_char(); }
} testDescription_suite_TestMeta_TestSizeOf_char;

static class TestDescription_suite_TestMeta_TestSizeOf_uchar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_uchar() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 119, "TestSizeOf_uchar" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_uchar(); }
} testDescription_suite_TestMeta_TestSizeOf_uchar;

static class TestDescription_suite_TestMeta_TestSizeOf_short : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_short() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 120, "TestSizeOf_short" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_short(); }
} testDescription_suite_TestMeta_TestSizeOf_short;

static class TestDescription_suite_TestMeta_TestSizeOf_ushort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_ushort() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 121, "TestSizeOf_ushort" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_ushort(); }
} testDescription_suite_TestMeta_TestSizeOf_ushort;

static class TestDescription_suite_TestMeta_TestSizeOf_long : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_long() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 122, "TestSizeOf_long" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_long(); }
} testDescription_suite_TestMeta_TestSizeOf_long;

static class TestDescription_suite_TestMeta_TestSizeOf_ulong : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_ulong() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 123, "TestSizeOf_ulong" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_ulong(); }
} testDescription_suite_TestMeta_TestSizeOf_ulong;

static class TestDescription_suite_TestMeta_TestSizeOf_float : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_float() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 124, "TestSizeOf_float" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_float(); }
} testDescription_suite_TestMeta_TestSizeOf_float;

static class TestDescription_suite_TestMeta_TestSizeOf_double : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_double() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 125, "TestSizeOf_double" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_double(); }
} testDescription_suite_TestMeta_TestSizeOf_double;

static class TestDescription_suite_TestMeta_TestSizeOf_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_empty() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 128, "TestSizeOf_empty" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_empty(); }
} testDescription_suite_TestMeta_TestSizeOf_empty;

static class TestDescription_suite_TestMeta_TestSizeOf_TypeList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_TypeList() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 129, "TestSizeOf_TypeList" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_TypeList(); }
} testDescription_suite_TestMeta_TestSizeOf_TypeList;

static class TestDescription_suite_TestMeta_TestSizeOf_BitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_BitSet() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 130, "TestSizeOf_BitSet" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_BitSet(); }
} testDescription_suite_TestMeta_TestSizeOf_BitSet;

static class TestDescription_suite_TestMeta_TestSizeOf_DynamicValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_DynamicValue() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 131, "TestSizeOf_DynamicValue" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_DynamicValue(); }
} testDescription_suite_TestMeta_TestSizeOf_DynamicValue;

static class TestDescription_suite_TestMeta_TestSizeOf_ArrayValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_ArrayValue() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 132, "TestSizeOf_ArrayValue" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_ArrayValue(); }
} testDescription_suite_TestMeta_TestSizeOf_ArrayValue;

static class TestDescription_suite_TestMeta_TestSizeAt_1_to_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeAt_1_to_max() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 135, "TestSizeAt_1_to_max" ) {}
 void runTest() { suite_TestMeta.TestSizeAt_1_to_max(); }
} testDescription_suite_TestMeta_TestSizeAt_1_to_max;

static class TestDescription_suite_TestMeta_TestOffsetOf_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestOffsetOf_basic() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 138, "TestOffsetOf_basic" ) {}
 void runTest() { suite_TestMeta.TestOffsetOf_basic(); }
} testDescription_suite_TestMeta_TestOffsetOf_basic;

static class TestDescription_suite_TestMeta_TestOffsetOf_bitset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestOffsetOf_bitset() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 139, "TestOffsetOf_bitset" ) {}
 void runTest() { suite_TestMeta.TestOffsetOf_bitset(); }
} testDescription_suite_TestMeta_TestOffsetOf_bitset;

static class TestDescription_suite_TestMeta_TestOffsetOf_nested : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestOffsetOf_nested() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 140, "TestOffsetOf_nested" ) {}
 void runTest() { suite_TestMeta.TestOffsetOf_nested(); }
} testDescription_suite_TestMeta_TestOffsetOf_nested;

static class TestDescription_suite_TestMeta_TestBitSet_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_constructor() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 143, "TestBitSet_constructor" ) {}
 void runTest() { suite_TestMeta.TestBitSet_constructor(); }
} testDescription_suite_TestMeta_TestBitSet_constructor;

static class TestDescription_suite_TestMeta_TestBitSet_conversion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_conversion() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 144, "TestBitSet_conversion" ) {}
 void runTest() { suite_TestMeta.TestBitSet_conversion(); }
} testDescription_suite_TestMeta_TestBitSet_conversion;

static class TestDescription_suite_TestMeta_TestBitSet_assignment_BitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_assignment_BitSet() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 145, "TestBitSet_assignment_BitSet" ) {}
 void runTest() { suite_TestMeta.TestBitSet_assignment_BitSet(); }
} testDescription_suite_TestMeta_TestBitSet_assignment_BitSet;

static class TestDescription_suite_TestMeta_TestBitSet_assignment_value_type : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_assignment_value_type() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 146, "TestBitSet_assignment_value_type" ) {}
 void runTest() { suite_TestMeta.TestBitSet_assignment_value_type(); }
} testDescription_suite_TestMeta_TestBitSet_assignment_value_type;

static class TestDescription_suite_TestMeta_TestBitSet_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_size() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 147, "TestBitSet_size" ) {}
 void runTest() { suite_TestMeta.TestBitSet_size(); }
} testDescription_suite_TestMeta_TestBitSet_size;

static class TestDescription_suite_TestMeta_TestForEach : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestForEach() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 150, "TestForEach" ) {}
 void runTest() { suite_TestMeta.TestForEach(); }
} testDescription_suite_TestMeta_TestForEach;

#include "C:\Development\GitGub\Alchemy\test\Src\TestMsgBufferSuite.h"

static TestMsgBufferSuite suite_TestMsgBufferSuite;

static CxxTest::List Tests_TestMsgBufferSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestMsgBufferSuite( "../TestMsgBufferSuite.h", 98, "TestMsgBufferSuite", suite_TestMsgBufferSuite, Tests_TestMsgBufferSuite );

static class TestDescription_suite_TestMsgBufferSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 298, "TestDefaultCtor" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestDefaultCtor(); }
} testDescription_suite_TestMsgBufferSuite_TestDefaultCtor;

static class TestDescription_suite_TestMsgBufferSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 299, "TestCopyCtor" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestCopyCtor(); }
} testDescription_suite_TestMsgBufferSuite_TestCopyCtor;

static class TestDescription_suite_TestMsgBufferSuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 300, "TestDtor" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestDtor(); }
} testDescription_suite_TestMsgBufferSuite_TestDtor;

static class TestDescription_suite_TestMsgBufferSuite_TestOpAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestOpAssignment() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 301, "TestOpAssignment" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestOpAssignment(); }
} testDescription_suite_TestMsgBufferSuite_TestOpAssignment;

static class TestDescription_suite_TestMsgBufferSuite_TestOpAssignment_ToSelf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestOpAssignment_ToSelf() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 302, "TestOpAssignment_ToSelf" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestOpAssignment_ToSelf(); }
} testDescription_suite_TestMsgBufferSuite_TestOpAssignment_ToSelf;

static class TestDescription_suite_TestMsgBufferSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 303, "Testempty" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testempty(); }
} testDescription_suite_TestMsgBufferSuite_Testempty;

static class TestDescription_suite_TestMsgBufferSuite_Testempty_NotEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testempty_NotEmpty() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 304, "Testempty_NotEmpty" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testempty_NotEmpty(); }
} testDescription_suite_TestMsgBufferSuite_Testempty_NotEmpty;

static class TestDescription_suite_TestMsgBufferSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 305, "TestSize" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSize(); }
} testDescription_suite_TestMsgBufferSuite_TestSize;

static class TestDescription_suite_TestMsgBufferSuite_Testbuffer_read : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testbuffer_read() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 306, "Testbuffer_read" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testbuffer_read(); }
} testDescription_suite_TestMsgBufferSuite_Testbuffer_read;

static class TestDescription_suite_TestMsgBufferSuite_Testbuffer_write : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testbuffer_write() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 307, "Testbuffer_write" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testbuffer_write(); }
} testDescription_suite_TestMsgBufferSuite_Testbuffer_write;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 308, "Testget_data" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_OffsetLTZero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_OffsetLTZero() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 309, "Testget_data_OOB_OffsetLTZero" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data_OOB_OffsetLTZero(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data_OOB_OffsetLTZero;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_ExceedsSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_ExceedsSize() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 310, "Testget_data_OOB_ExceedsSize" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data_OOB_ExceedsSize(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data_OOB_ExceedsSize;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data_NotValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data_NotValid() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 311, "Testget_data_NotValid" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data_NotValid(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data_NotValid;

static class TestDescription_suite_TestMsgBufferSuite_TestSetData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSetData() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 312, "TestSetData" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSetData(); }
} testDescription_suite_TestMsgBufferSuite_TestSetData;

static class TestDescription_suite_TestMsgBufferSuite_TestSetData_OOB_ExceedsSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSetData_OOB_ExceedsSize() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 313, "TestSetData_OOB_ExceedsSize" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSetData_OOB_ExceedsSize(); }
} testDescription_suite_TestMsgBufferSuite_TestSetData_OOB_ExceedsSize;

static class TestDescription_suite_TestMsgBufferSuite_TestSetData_NotValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSetData_NotValid() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 314, "TestSetData_NotValid" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSetData_NotValid(); }
} testDescription_suite_TestMsgBufferSuite_TestSetData_NotValid;

static class TestDescription_suite_TestMsgBufferSuite_TestClone : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestClone() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 315, "TestClone" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestClone(); }
} testDescription_suite_TestMsgBufferSuite_TestClone;

static class TestDescription_suite_TestMsgBufferSuite_TestClone_NotValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestClone_NotValid() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 316, "TestClone_NotValid" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestClone_NotValid(); }
} testDescription_suite_TestMsgBufferSuite_TestClone_NotValid;

static class TestDescription_suite_TestMsgBufferSuite_TestClone_BufferAllocFailed : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestClone_BufferAllocFailed() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 317, "TestClone_BufferAllocFailed" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestClone_BufferAllocFailed(); }
} testDescription_suite_TestMsgBufferSuite_TestClone_BufferAllocFailed;

#include "C:\Development\GitGub\Alchemy\test\Src\TestMsgFieldSuite.h"

static TestDatumSuite suite_TestDatumSuite;

static CxxTest::List Tests_TestDatumSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDatumSuite( "../TestMsgFieldSuite.h", 66, "TestDatumSuite", suite_TestDatumSuite, Tests_TestDatumSuite );

static class TestDescription_suite_TestDatumSuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 104, "TestDtor" ) {}
 void runTest() { suite_TestDatumSuite.TestDtor(); }
} testDescription_suite_TestDatumSuite_TestDtor;

static class TestDescription_suite_TestDatumSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 105, "TestCopyConstructor" ) {}
 void runTest() { suite_TestDatumSuite.TestCopyConstructor(); }
} testDescription_suite_TestDatumSuite_TestCopyConstructor;

static class TestDescription_suite_TestDatumSuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 106, "TestAssignment" ) {}
 void runTest() { suite_TestDatumSuite.TestAssignment(); }
} testDescription_suite_TestDatumSuite_TestAssignment;

static class TestDescription_suite_TestDatumSuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 107, "TestValueAssignment" ) {}
 void runTest() { suite_TestDatumSuite.TestValueAssignment(); }
} testDescription_suite_TestDatumSuite_TestValueAssignment;

static class TestDescription_suite_TestDatumSuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 110, "TestOpEquals" ) {}
 void runTest() { suite_TestDatumSuite.TestOpEquals(); }
} testDescription_suite_TestDatumSuite_TestOpEquals;

static class TestDescription_suite_TestDatumSuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 111, "TestOpEquals_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpEquals_false(); }
} testDescription_suite_TestDatumSuite_TestOpEquals_false;

static class TestDescription_suite_TestDatumSuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 112, "TestOpNotEquals" ) {}
 void runTest() { suite_TestDatumSuite.TestOpNotEquals(); }
} testDescription_suite_TestDatumSuite_TestOpNotEquals;

static class TestDescription_suite_TestDatumSuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 113, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpNotEquals_false(); }
} testDescription_suite_TestDatumSuite_TestOpNotEquals_false;

static class TestDescription_suite_TestDatumSuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 114, "TestOpLessThan" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThan(); }
} testDescription_suite_TestDatumSuite_TestOpLessThan;

static class TestDescription_suite_TestDatumSuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 115, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThan_false(); }
} testDescription_suite_TestDatumSuite_TestOpLessThan_false;

static class TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 116, "TestOpLessThanOrEqual" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThanOrEqual(); }
} testDescription_suite_TestDatumSuite_TestOpLessThanOrEqual;

static class TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 117, "TestOpLessThanOrEqual_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThanOrEqual_false(); }
} testDescription_suite_TestDatumSuite_TestOpLessThanOrEqual_false;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThan() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 118, "TestOpGreaterThan" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThan(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThan;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThan_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 119, "TestOpGreaterThan_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThan_false(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThan_false;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 120, "TestOpGreaterThanOrEqual" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThanOrEqual(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 121, "TestOpGreaterThanOrEqual_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThanOrEqual_false(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual_false;

static class TestDescription_suite_TestDatumSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 124, "TestClear" ) {}
 void runTest() { suite_TestDatumSuite.TestClear(); }
} testDescription_suite_TestDatumSuite_TestClear;

static class TestDescription_suite_TestDatumSuite_TestClear_Empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestClear_Empty() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 125, "TestClear_Empty" ) {}
 void runTest() { suite_TestDatumSuite.TestClear_Empty(); }
} testDescription_suite_TestDatumSuite_TestClear_Empty;

static class TestDescription_suite_TestDatumSuite_TestGet_Const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestGet_Const() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 128, "TestGet_Const" ) {}
 void runTest() { suite_TestDatumSuite.TestGet_Const(); }
} testDescription_suite_TestDatumSuite_TestGet_Const;

static class TestDescription_suite_TestDatumSuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestGet() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 129, "TestGet" ) {}
 void runTest() { suite_TestDatumSuite.TestGet(); }
} testDescription_suite_TestDatumSuite_TestGet;

static class TestDescription_suite_TestDatumSuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestSet() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 131, "TestSet" ) {}
 void runTest() { suite_TestDatumSuite.TestSet(); }
} testDescription_suite_TestDatumSuite_TestSet;

#include "C:\Development\GitGub\Alchemy\test\Src\TestVectorProxySuite.h"

static TestVectorProxySuite suite_TestVectorProxySuite;

static CxxTest::List Tests_TestVectorProxySuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestVectorProxySuite( "../TestVectorProxySuite.h", 61, "TestVectorProxySuite", suite_TestVectorProxySuite, Tests_TestVectorProxySuite );

static class TestDescription_suite_TestVectorProxySuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 100, "TestDtor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestDtor(); }
} testDescription_suite_TestVectorProxySuite_TestDtor;

static class TestDescription_suite_TestVectorProxySuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 101, "TestCopyConstructor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestCopyConstructor(); }
} testDescription_suite_TestVectorProxySuite_TestCopyConstructor;

static class TestDescription_suite_TestVectorProxySuite_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 102, "TestValueConstructor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestValueConstructor(); }
} testDescription_suite_TestVectorProxySuite_TestValueConstructor;

static class TestDescription_suite_TestVectorProxySuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 103, "TestAssignment" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAssignment(); }
} testDescription_suite_TestVectorProxySuite_TestAssignment;

static class TestDescription_suite_TestVectorProxySuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 104, "TestValueAssignment" ) {}
 void runTest() { suite_TestVectorProxySuite.TestValueAssignment(); }
} testDescription_suite_TestVectorProxySuite_TestValueAssignment;

static class TestDescription_suite_TestVectorProxySuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 107, "TestOpEquals" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpEquals(); }
} testDescription_suite_TestVectorProxySuite_TestOpEquals;

static class TestDescription_suite_TestVectorProxySuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 108, "TestOpEquals_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpEquals_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpEquals_false;

static class TestDescription_suite_TestVectorProxySuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 109, "TestOpNotEquals" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpNotEquals(); }
} testDescription_suite_TestVectorProxySuite_TestOpNotEquals;

static class TestDescription_suite_TestVectorProxySuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 110, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpNotEquals_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpNotEquals_false;

static class TestDescription_suite_TestVectorProxySuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 111, "TestOpLessThan" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpLessThan(); }
} testDescription_suite_TestVectorProxySuite_TestOpLessThan;

static class TestDescription_suite_TestVectorProxySuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 112, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpLessThan_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpLessThan_false;

static class TestDescription_suite_TestVectorProxySuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestClear() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 115, "TestClear" ) {}
 void runTest() { suite_TestVectorProxySuite.TestClear(); }
} testDescription_suite_TestVectorProxySuite_TestClear;

static class TestDescription_suite_TestVectorProxySuite_TestReserve : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestReserve() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 116, "TestReserve" ) {}
 void runTest() { suite_TestVectorProxySuite.TestReserve(); }
} testDescription_suite_TestVectorProxySuite_TestReserve;

static class TestDescription_suite_TestVectorProxySuite_TestCapacity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestCapacity() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 117, "TestCapacity" ) {}
 void runTest() { suite_TestVectorProxySuite.TestCapacity(); }
} testDescription_suite_TestVectorProxySuite_TestCapacity;

static class TestDescription_suite_TestVectorProxySuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSize() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 118, "TestSize" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSize(); }
} testDescription_suite_TestVectorProxySuite_TestSize;

static class TestDescription_suite_TestVectorProxySuite_TestSizeOf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSizeOf() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 119, "TestSizeOf" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSizeOf(); }
} testDescription_suite_TestVectorProxySuite_TestSizeOf;

static class TestDescription_suite_TestVectorProxySuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestGet() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 122, "TestGet" ) {}
 void runTest() { suite_TestVectorProxySuite.TestGet(); }
} testDescription_suite_TestVectorProxySuite_TestGet;

static class TestDescription_suite_TestVectorProxySuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSet() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 123, "TestSet" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSet(); }
} testDescription_suite_TestVectorProxySuite_TestSet;

static class TestDescription_suite_TestVectorProxySuite_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAt_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 125, "TestAt_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAt_const(); }
} testDescription_suite_TestVectorProxySuite_TestAt_const;

static class TestDescription_suite_TestVectorProxySuite_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAt() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 126, "TestAt" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAt(); }
} testDescription_suite_TestVectorProxySuite_TestAt;

static class TestDescription_suite_TestVectorProxySuite_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 127, "TestOpSquare_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpSquare_const(); }
} testDescription_suite_TestVectorProxySuite_TestOpSquare_const;

static class TestDescription_suite_TestVectorProxySuite_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 128, "TestOpSquare" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpSquare(); }
} testDescription_suite_TestVectorProxySuite_TestOpSquare;

static class TestDescription_suite_TestVectorProxySuite_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestFront_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 129, "TestFront_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestFront_const(); }
} testDescription_suite_TestVectorProxySuite_TestFront_const;

static class TestDescription_suite_TestVectorProxySuite_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestFront() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 130, "TestFront" ) {}
 void runTest() { suite_TestVectorProxySuite.TestFront(); }
} testDescription_suite_TestVectorProxySuite_TestFront;

static class TestDescription_suite_TestVectorProxySuite_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBack_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 131, "TestBack_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBack_const(); }
} testDescription_suite_TestVectorProxySuite_TestBack_const;

static class TestDescription_suite_TestVectorProxySuite_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 132, "TestBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBack(); }
} testDescription_suite_TestVectorProxySuite_TestBack;

static class TestDescription_suite_TestVectorProxySuite_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBegin() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 135, "TestBegin" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBegin(); }
} testDescription_suite_TestVectorProxySuite_TestBegin;

static class TestDescription_suite_TestVectorProxySuite_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestEnd() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 136, "TestEnd" ) {}
 void runTest() { suite_TestVectorProxySuite.TestEnd(); }
} testDescription_suite_TestVectorProxySuite_TestEnd;

static class TestDescription_suite_TestVectorProxySuite_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestRBegin() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 137, "TestRBegin" ) {}
 void runTest() { suite_TestVectorProxySuite.TestRBegin(); }
} testDescription_suite_TestVectorProxySuite_TestRBegin;

static class TestDescription_suite_TestVectorProxySuite_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestREnd() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 138, "TestREnd" ) {}
 void runTest() { suite_TestVectorProxySuite.TestREnd(); }
} testDescription_suite_TestVectorProxySuite_TestREnd;

static class TestDescription_suite_TestVectorProxySuite_TestErase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestErase() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 141, "TestErase" ) {}
 void runTest() { suite_TestVectorProxySuite.TestErase(); }
} testDescription_suite_TestVectorProxySuite_TestErase;

static class TestDescription_suite_TestVectorProxySuite_TestErase_range : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestErase_range() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 142, "TestErase_range" ) {}
 void runTest() { suite_TestVectorProxySuite.TestErase_range(); }
} testDescription_suite_TestVectorProxySuite_TestErase_range;

static class TestDescription_suite_TestVectorProxySuite_TestPushBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPushBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 143, "TestPushBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPushBack(); }
} testDescription_suite_TestVectorProxySuite_TestPushBack;

static class TestDescription_suite_TestVectorProxySuite_TestPushBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPushBack_empty() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 144, "TestPushBack_empty" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPushBack_empty(); }
} testDescription_suite_TestVectorProxySuite_TestPushBack_empty;

static class TestDescription_suite_TestVectorProxySuite_TestPopBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPopBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 145, "TestPopBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPopBack(); }
} testDescription_suite_TestVectorProxySuite_TestPopBack;

static class TestDescription_suite_TestVectorProxySuite_TestPopBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPopBack_empty() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 146, "TestPopBack_empty" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPopBack_empty(); }
} testDescription_suite_TestVectorProxySuite_TestPopBack_empty;

static class TestDescription_suite_TestVectorProxySuite_TestResize_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_smaller() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 147, "TestResize_smaller" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_smaller(); }
} testDescription_suite_TestVectorProxySuite_TestResize_smaller;

static class TestDescription_suite_TestVectorProxySuite_TestResize_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_larger() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 148, "TestResize_larger" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_larger(); }
} testDescription_suite_TestVectorProxySuite_TestResize_larger;

static class TestDescription_suite_TestVectorProxySuite_TestResize_default_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_default_smaller() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 149, "TestResize_default_smaller" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_default_smaller(); }
} testDescription_suite_TestVectorProxySuite_TestResize_default_smaller;

static class TestDescription_suite_TestVectorProxySuite_TestResize_default_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_default_larger() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 150, "TestResize_default_larger" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_default_larger(); }
} testDescription_suite_TestVectorProxySuite_TestResize_default_larger;

static class TestDescription_suite_TestVectorProxySuite_TestSwap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSwap() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 151, "TestSwap" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSwap(); }
} testDescription_suite_TestVectorProxySuite_TestSwap;

static class TestDescription_suite_TestVectorProxySuite_TestSwap_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSwap_vector() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 152, "TestSwap_vector" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSwap_vector(); }
} testDescription_suite_TestVectorProxySuite_TestSwap_vector;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
