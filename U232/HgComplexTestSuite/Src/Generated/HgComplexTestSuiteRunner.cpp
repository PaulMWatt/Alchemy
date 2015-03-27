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
 TestDescription_suite_TestArrayDataSuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 98, "TestDtor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestDtor(); }
} testDescription_suite_TestArrayDataSuite_TestDtor;

static class TestDescription_suite_TestArrayDataSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 99, "TestCopyConstructor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestCopyConstructor(); }
} testDescription_suite_TestArrayDataSuite_TestCopyConstructor;

static class TestDescription_suite_TestArrayDataSuite_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 100, "TestValueConstructor" ) {}
 void runTest() { suite_TestArrayDataSuite.TestValueConstructor(); }
} testDescription_suite_TestArrayDataSuite_TestValueConstructor;

static class TestDescription_suite_TestArrayDataSuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 101, "TestAssignment" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAssignment(); }
} testDescription_suite_TestArrayDataSuite_TestAssignment;

static class TestDescription_suite_TestArrayDataSuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 102, "TestValueAssignment" ) {}
 void runTest() { suite_TestArrayDataSuite.TestValueAssignment(); }
} testDescription_suite_TestArrayDataSuite_TestValueAssignment;

static class TestDescription_suite_TestArrayDataSuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 105, "TestOpEquals" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpEquals(); }
} testDescription_suite_TestArrayDataSuite_TestOpEquals;

static class TestDescription_suite_TestArrayDataSuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 106, "TestOpEquals_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpEquals_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpEquals_false;

static class TestDescription_suite_TestArrayDataSuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 107, "TestOpNotEquals" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpNotEquals(); }
} testDescription_suite_TestArrayDataSuite_TestOpNotEquals;

static class TestDescription_suite_TestArrayDataSuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 108, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpNotEquals_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpNotEquals_false;

static class TestDescription_suite_TestArrayDataSuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 109, "TestOpLessThan" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpLessThan(); }
} testDescription_suite_TestArrayDataSuite_TestOpLessThan;

static class TestDescription_suite_TestArrayDataSuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 110, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpLessThan_false(); }
} testDescription_suite_TestArrayDataSuite_TestOpLessThan_false;

static class TestDescription_suite_TestArrayDataSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 113, "TestClear" ) {}
 void runTest() { suite_TestArrayDataSuite.TestClear(); }
} testDescription_suite_TestArrayDataSuite_TestClear;

static class TestDescription_suite_TestArrayDataSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 114, "TestSize" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSize(); }
} testDescription_suite_TestArrayDataSuite_TestSize;

static class TestDescription_suite_TestArrayDataSuite_TestSizeOf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSizeOf() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 115, "TestSizeOf" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSizeOf(); }
} testDescription_suite_TestArrayDataSuite_TestSizeOf;

static class TestDescription_suite_TestArrayDataSuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestGet() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 118, "TestGet" ) {}
 void runTest() { suite_TestArrayDataSuite.TestGet(); }
} testDescription_suite_TestArrayDataSuite_TestGet;

static class TestDescription_suite_TestArrayDataSuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestSet() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 119, "TestSet" ) {}
 void runTest() { suite_TestArrayDataSuite.TestSet(); }
} testDescription_suite_TestArrayDataSuite_TestSet;

static class TestDescription_suite_TestArrayDataSuite_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAt_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 121, "TestAt_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAt_const(); }
} testDescription_suite_TestArrayDataSuite_TestAt_const;

static class TestDescription_suite_TestArrayDataSuite_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestAt() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 122, "TestAt" ) {}
 void runTest() { suite_TestArrayDataSuite.TestAt(); }
} testDescription_suite_TestArrayDataSuite_TestAt;

static class TestDescription_suite_TestArrayDataSuite_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 123, "TestOpSquare_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpSquare_const(); }
} testDescription_suite_TestArrayDataSuite_TestOpSquare_const;

static class TestDescription_suite_TestArrayDataSuite_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 124, "TestOpSquare" ) {}
 void runTest() { suite_TestArrayDataSuite.TestOpSquare(); }
} testDescription_suite_TestArrayDataSuite_TestOpSquare;

static class TestDescription_suite_TestArrayDataSuite_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestFront_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 125, "TestFront_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestFront_const(); }
} testDescription_suite_TestArrayDataSuite_TestFront_const;

static class TestDescription_suite_TestArrayDataSuite_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestFront() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 126, "TestFront" ) {}
 void runTest() { suite_TestArrayDataSuite.TestFront(); }
} testDescription_suite_TestArrayDataSuite_TestFront;

static class TestDescription_suite_TestArrayDataSuite_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBack_const() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 127, "TestBack_const" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBack_const(); }
} testDescription_suite_TestArrayDataSuite_TestBack_const;

static class TestDescription_suite_TestArrayDataSuite_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBack() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 128, "TestBack" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBack(); }
} testDescription_suite_TestArrayDataSuite_TestBack;

static class TestDescription_suite_TestArrayDataSuite_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestBegin() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 131, "TestBegin" ) {}
 void runTest() { suite_TestArrayDataSuite.TestBegin(); }
} testDescription_suite_TestArrayDataSuite_TestBegin;

static class TestDescription_suite_TestArrayDataSuite_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestEnd() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 132, "TestEnd" ) {}
 void runTest() { suite_TestArrayDataSuite.TestEnd(); }
} testDescription_suite_TestArrayDataSuite_TestEnd;

static class TestDescription_suite_TestArrayDataSuite_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestRBegin() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 133, "TestRBegin" ) {}
 void runTest() { suite_TestArrayDataSuite.TestRBegin(); }
} testDescription_suite_TestArrayDataSuite_TestRBegin;

static class TestDescription_suite_TestArrayDataSuite_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_TestREnd() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 134, "TestREnd" ) {}
 void runTest() { suite_TestArrayDataSuite.TestREnd(); }
} testDescription_suite_TestArrayDataSuite_TestREnd;

#include "..\TestDynamicMessageSuite.h"

static TestDynamicMessageSuite suite_TestDynamicMessageSuite;

static CxxTest::List Tests_TestDynamicMessageSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDynamicMessageSuite( "../TestDynamicMessageSuite.h", 148, "TestDynamicMessageSuite", suite_TestDynamicMessageSuite, Tests_TestDynamicMessageSuite );

static class TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 389, "TestHasDynamic_true" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestHasDynamic_true(); }
} testDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 390, "TestDynamicFields_none" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_none(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 391, "TestDynamicFields_basic" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_basic(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 392, "TestDynamicFields_message" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_message(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message;

static class TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 395, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 396, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestCopyCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestCopyCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 397, "TestValueCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestValueCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestValueCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 398, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 399, "Testempty" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 400, "Testempty_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 401, "TestSize" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestSize(); }
} testDescription_suite_TestDynamicMessageSuite_TestSize;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 402, "Testis_host_order" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 403, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 404, "TestAssign" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssign(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssign;

static class TestDescription_suite_TestDynamicMessageSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 405, "TestClear" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestClear(); }
} testDescription_suite_TestDynamicMessageSuite_TestClear;

static class TestDescription_suite_TestDynamicMessageSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 406, "Testdata" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testdata(); }
} testDescription_suite_TestDynamicMessageSuite_Testdata;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 409, "Testto_host" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_host(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_host;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 410, "Testto_network" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_network(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_network;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 411, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_big_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_big_endian;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 412, "Testto_little_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_little_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_little_endian;

#include "..\TestDynTypePermsSuite.h"

static TestDynTypePermsSuite suite_TestDynTypePermsSuite;

static CxxTest::List Tests_TestDynTypePermsSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDynTypePermsSuite( "../TestDynTypePermsSuite.h", 53, "TestDynTypePermsSuite", suite_TestDynTypePermsSuite, Tests_TestDynTypePermsSuite );

static class TestDescription_suite_TestDynTypePermsSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 240, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 241, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestCopyCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestCopyCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 242, "TestValueCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestValueCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestValueCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 243, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynTypePermsSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 244, "Testempty" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testempty(); }
} testDescription_suite_TestDynTypePermsSuite_Testempty;

static class TestDescription_suite_TestDynTypePermsSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 245, "Testempty_false" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testempty_false(); }
} testDescription_suite_TestDynTypePermsSuite_Testempty_false;

static class TestDescription_suite_TestDynTypePermsSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 246, "TestSize" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestSize(); }
} testDescription_suite_TestDynTypePermsSuite_TestSize;

static class TestDescription_suite_TestDynTypePermsSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 247, "Testis_host_order" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testis_host_order(); }
} testDescription_suite_TestDynTypePermsSuite_Testis_host_order;

static class TestDescription_suite_TestDynTypePermsSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 248, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynTypePermsSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynTypePermsSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 249, "TestAssign" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestAssign(); }
} testDescription_suite_TestDynTypePermsSuite_TestAssign;

static class TestDescription_suite_TestDynTypePermsSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 250, "TestClear" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestClear(); }
} testDescription_suite_TestDynTypePermsSuite_TestClear;

static class TestDescription_suite_TestDynTypePermsSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 251, "Testdata" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testdata(); }
} testDescription_suite_TestDynTypePermsSuite_Testdata;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 254, "Testto_host" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_host(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_host;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 255, "Testto_network" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_network(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_network;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 256, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_big_endian(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_big_endian;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 257, "Testto_little_endian" ) {}
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

static class TestDescription_suite_TestVectorProxySuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 108, "TestCopyConstructor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestCopyConstructor(); }
} testDescription_suite_TestVectorProxySuite_TestCopyConstructor;

static class TestDescription_suite_TestVectorProxySuite_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 109, "TestValueConstructor" ) {}
 void runTest() { suite_TestVectorProxySuite.TestValueConstructor(); }
} testDescription_suite_TestVectorProxySuite_TestValueConstructor;

static class TestDescription_suite_TestVectorProxySuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 110, "TestAssignment" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAssignment(); }
} testDescription_suite_TestVectorProxySuite_TestAssignment;

static class TestDescription_suite_TestVectorProxySuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 111, "TestValueAssignment" ) {}
 void runTest() { suite_TestVectorProxySuite.TestValueAssignment(); }
} testDescription_suite_TestVectorProxySuite_TestValueAssignment;

static class TestDescription_suite_TestVectorProxySuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 114, "TestOpEquals" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpEquals(); }
} testDescription_suite_TestVectorProxySuite_TestOpEquals;

static class TestDescription_suite_TestVectorProxySuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 115, "TestOpEquals_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpEquals_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpEquals_false;

static class TestDescription_suite_TestVectorProxySuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 116, "TestOpNotEquals" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpNotEquals(); }
} testDescription_suite_TestVectorProxySuite_TestOpNotEquals;

static class TestDescription_suite_TestVectorProxySuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 117, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpNotEquals_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpNotEquals_false;

static class TestDescription_suite_TestVectorProxySuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 118, "TestOpLessThan" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpLessThan(); }
} testDescription_suite_TestVectorProxySuite_TestOpLessThan;

static class TestDescription_suite_TestVectorProxySuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 119, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpLessThan_false(); }
} testDescription_suite_TestVectorProxySuite_TestOpLessThan_false;

static class TestDescription_suite_TestVectorProxySuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestClear() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 122, "TestClear" ) {}
 void runTest() { suite_TestVectorProxySuite.TestClear(); }
} testDescription_suite_TestVectorProxySuite_TestClear;

static class TestDescription_suite_TestVectorProxySuite_TestReserve : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestReserve() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 123, "TestReserve" ) {}
 void runTest() { suite_TestVectorProxySuite.TestReserve(); }
} testDescription_suite_TestVectorProxySuite_TestReserve;

static class TestDescription_suite_TestVectorProxySuite_TestCapacity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestCapacity() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 124, "TestCapacity" ) {}
 void runTest() { suite_TestVectorProxySuite.TestCapacity(); }
} testDescription_suite_TestVectorProxySuite_TestCapacity;

static class TestDescription_suite_TestVectorProxySuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSize() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 125, "TestSize" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSize(); }
} testDescription_suite_TestVectorProxySuite_TestSize;

static class TestDescription_suite_TestVectorProxySuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestGet() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 128, "TestGet" ) {}
 void runTest() { suite_TestVectorProxySuite.TestGet(); }
} testDescription_suite_TestVectorProxySuite_TestGet;

static class TestDescription_suite_TestVectorProxySuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSet() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 129, "TestSet" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSet(); }
} testDescription_suite_TestVectorProxySuite_TestSet;

static class TestDescription_suite_TestVectorProxySuite_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAt_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 131, "TestAt_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAt_const(); }
} testDescription_suite_TestVectorProxySuite_TestAt_const;

static class TestDescription_suite_TestVectorProxySuite_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestAt() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 132, "TestAt" ) {}
 void runTest() { suite_TestVectorProxySuite.TestAt(); }
} testDescription_suite_TestVectorProxySuite_TestAt;

static class TestDescription_suite_TestVectorProxySuite_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 133, "TestOpSquare_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpSquare_const(); }
} testDescription_suite_TestVectorProxySuite_TestOpSquare_const;

static class TestDescription_suite_TestVectorProxySuite_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 134, "TestOpSquare" ) {}
 void runTest() { suite_TestVectorProxySuite.TestOpSquare(); }
} testDescription_suite_TestVectorProxySuite_TestOpSquare;

static class TestDescription_suite_TestVectorProxySuite_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestFront_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 135, "TestFront_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestFront_const(); }
} testDescription_suite_TestVectorProxySuite_TestFront_const;

static class TestDescription_suite_TestVectorProxySuite_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestFront() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 136, "TestFront" ) {}
 void runTest() { suite_TestVectorProxySuite.TestFront(); }
} testDescription_suite_TestVectorProxySuite_TestFront;

static class TestDescription_suite_TestVectorProxySuite_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBack_const() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 137, "TestBack_const" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBack_const(); }
} testDescription_suite_TestVectorProxySuite_TestBack_const;

static class TestDescription_suite_TestVectorProxySuite_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 138, "TestBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBack(); }
} testDescription_suite_TestVectorProxySuite_TestBack;

static class TestDescription_suite_TestVectorProxySuite_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestBegin() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 141, "TestBegin" ) {}
 void runTest() { suite_TestVectorProxySuite.TestBegin(); }
} testDescription_suite_TestVectorProxySuite_TestBegin;

static class TestDescription_suite_TestVectorProxySuite_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestEnd() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 142, "TestEnd" ) {}
 void runTest() { suite_TestVectorProxySuite.TestEnd(); }
} testDescription_suite_TestVectorProxySuite_TestEnd;

static class TestDescription_suite_TestVectorProxySuite_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestRBegin() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 143, "TestRBegin" ) {}
 void runTest() { suite_TestVectorProxySuite.TestRBegin(); }
} testDescription_suite_TestVectorProxySuite_TestRBegin;

static class TestDescription_suite_TestVectorProxySuite_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestREnd() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 144, "TestREnd" ) {}
 void runTest() { suite_TestVectorProxySuite.TestREnd(); }
} testDescription_suite_TestVectorProxySuite_TestREnd;

static class TestDescription_suite_TestVectorProxySuite_TestErase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestErase() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 147, "TestErase" ) {}
 void runTest() { suite_TestVectorProxySuite.TestErase(); }
} testDescription_suite_TestVectorProxySuite_TestErase;

static class TestDescription_suite_TestVectorProxySuite_TestErase_range : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestErase_range() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 148, "TestErase_range" ) {}
 void runTest() { suite_TestVectorProxySuite.TestErase_range(); }
} testDescription_suite_TestVectorProxySuite_TestErase_range;

static class TestDescription_suite_TestVectorProxySuite_TestPushBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPushBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 149, "TestPushBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPushBack(); }
} testDescription_suite_TestVectorProxySuite_TestPushBack;

static class TestDescription_suite_TestVectorProxySuite_TestPushBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPushBack_empty() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 150, "TestPushBack_empty" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPushBack_empty(); }
} testDescription_suite_TestVectorProxySuite_TestPushBack_empty;

static class TestDescription_suite_TestVectorProxySuite_TestPopBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPopBack() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 151, "TestPopBack" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPopBack(); }
} testDescription_suite_TestVectorProxySuite_TestPopBack;

static class TestDescription_suite_TestVectorProxySuite_TestPopBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestPopBack_empty() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 152, "TestPopBack_empty" ) {}
 void runTest() { suite_TestVectorProxySuite.TestPopBack_empty(); }
} testDescription_suite_TestVectorProxySuite_TestPopBack_empty;

static class TestDescription_suite_TestVectorProxySuite_TestResize_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_smaller() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 153, "TestResize_smaller" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_smaller(); }
} testDescription_suite_TestVectorProxySuite_TestResize_smaller;

static class TestDescription_suite_TestVectorProxySuite_TestResize_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_larger() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 154, "TestResize_larger" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_larger(); }
} testDescription_suite_TestVectorProxySuite_TestResize_larger;

static class TestDescription_suite_TestVectorProxySuite_TestResize_default_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_default_smaller() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 155, "TestResize_default_smaller" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_default_smaller(); }
} testDescription_suite_TestVectorProxySuite_TestResize_default_smaller;

static class TestDescription_suite_TestVectorProxySuite_TestResize_default_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestResize_default_larger() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 156, "TestResize_default_larger" ) {}
 void runTest() { suite_TestVectorProxySuite.TestResize_default_larger(); }
} testDescription_suite_TestVectorProxySuite_TestResize_default_larger;

static class TestDescription_suite_TestVectorProxySuite_TestSwap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSwap() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 157, "TestSwap" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSwap(); }
} testDescription_suite_TestVectorProxySuite_TestSwap;

static class TestDescription_suite_TestVectorProxySuite_TestSwap_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestVectorProxySuite_TestSwap_vector() : CxxTest::RealTestDescription( Tests_TestVectorProxySuite, suiteDescription_TestVectorProxySuite, 158, "TestSwap_vector" ) {}
 void runTest() { suite_TestVectorProxySuite.TestSwap_vector(); }
} testDescription_suite_TestVectorProxySuite_TestSwap_vector;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
