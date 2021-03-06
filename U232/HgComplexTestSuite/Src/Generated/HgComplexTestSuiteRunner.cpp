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

static class TestDescription_suite_TestArrayDataSuite_Testsize_of : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestArrayDataSuite_Testsize_of() : CxxTest::RealTestDescription( Tests_TestArrayDataSuite, suiteDescription_TestArrayDataSuite, 115, "Testsize_of" ) {}
 void runTest() { suite_TestArrayDataSuite.Testsize_of(); }
} testDescription_suite_TestArrayDataSuite_Testsize_of;

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
CxxTest::StaticSuiteDescription suiteDescription_TestDynamicMessageSuite( "../TestDynamicMessageSuite.h", 115, "TestDynamicMessageSuite", suite_TestDynamicMessageSuite, Tests_TestDynamicMessageSuite );

static class TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 356, "TestHasDynamic_true" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestHasDynamic_true(); }
} testDescription_suite_TestDynamicMessageSuite_TestHasDynamic_true;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 357, "TestDynamicFields_none" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_none(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_none;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 358, "TestDynamicFields_basic" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_basic(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_basic;

static class TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 359, "TestDynamicFields_message" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDynamicFields_message(); }
} testDescription_suite_TestDynamicMessageSuite_TestDynamicFields_message;

static class TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 362, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 363, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestCopyCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestCopyCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 364, "TestValueCtor" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestValueCtor(); }
} testDescription_suite_TestDynamicMessageSuite_TestValueCtor;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 365, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 366, "Testempty" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty;

static class TestDescription_suite_TestDynamicMessageSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 367, "Testempty_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testempty_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testempty_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 368, "TestSize" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestSize(); }
} testDescription_suite_TestDynamicMessageSuite_TestSize;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 369, "Testis_host_order" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order;

static class TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 370, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynamicMessageSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynamicMessageSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 371, "TestAssign" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestAssign(); }
} testDescription_suite_TestDynamicMessageSuite_TestAssign;

static class TestDescription_suite_TestDynamicMessageSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 372, "TestClear" ) {}
 void runTest() { suite_TestDynamicMessageSuite.TestClear(); }
} testDescription_suite_TestDynamicMessageSuite_TestClear;

static class TestDescription_suite_TestDynamicMessageSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 373, "Testdata" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testdata(); }
} testDescription_suite_TestDynamicMessageSuite_Testdata;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 376, "Testto_host" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_host(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_host;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 377, "Testto_network" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_network(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_network;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 378, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_big_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_big_endian;

static class TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynamicMessageSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynamicMessageSuite, suiteDescription_TestDynamicMessageSuite, 379, "Testto_little_endian" ) {}
 void runTest() { suite_TestDynamicMessageSuite.Testto_little_endian(); }
} testDescription_suite_TestDynamicMessageSuite_Testto_little_endian;

#include "..\TestDynTypePermsSuite.h"

static TestDynTypePermsSuite suite_TestDynTypePermsSuite;

static CxxTest::List Tests_TestDynTypePermsSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDynTypePermsSuite( "../TestDynTypePermsSuite.h", 53, "TestDynTypePermsSuite", suite_TestDynTypePermsSuite, Tests_TestDynTypePermsSuite );

static class TestDescription_suite_TestDynTypePermsSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 241, "TestDefaultCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestDefaultCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestDefaultCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 242, "TestCopyCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestCopyCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestCopyCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 243, "TestValueCtor" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestValueCtor(); }
} testDescription_suite_TestDynTypePermsSuite_TestValueCtor;

static class TestDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 244, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestAssignmentOperator(); }
} testDescription_suite_TestDynTypePermsSuite_TestAssignmentOperator;

static class TestDescription_suite_TestDynTypePermsSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 245, "Testempty" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testempty(); }
} testDescription_suite_TestDynTypePermsSuite_Testempty;

static class TestDescription_suite_TestDynTypePermsSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 246, "Testempty_false" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testempty_false(); }
} testDescription_suite_TestDynTypePermsSuite_Testempty_false;

static class TestDescription_suite_TestDynTypePermsSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 247, "TestSize" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestSize(); }
} testDescription_suite_TestDynTypePermsSuite_TestSize;

static class TestDescription_suite_TestDynTypePermsSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 248, "Testis_host_order" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testis_host_order(); }
} testDescription_suite_TestDynTypePermsSuite_Testis_host_order;

static class TestDescription_suite_TestDynTypePermsSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 249, "Testis_host_order_false" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testis_host_order_false(); }
} testDescription_suite_TestDynTypePermsSuite_Testis_host_order_false;

static class TestDescription_suite_TestDynTypePermsSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 250, "TestAssign" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestAssign(); }
} testDescription_suite_TestDynTypePermsSuite_TestAssign;

static class TestDescription_suite_TestDynTypePermsSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 251, "TestClear" ) {}
 void runTest() { suite_TestDynTypePermsSuite.TestClear(); }
} testDescription_suite_TestDynTypePermsSuite_TestClear;

static class TestDescription_suite_TestDynTypePermsSuite_Testdata_static : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testdata_static() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 252, "Testdata_static" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testdata_static(); }
} testDescription_suite_TestDynTypePermsSuite_Testdata_static;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 255, "Testto_host" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_host(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_host;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 256, "Testto_network" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_network(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_network;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 257, "Testto_big_endian" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_big_endian(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_big_endian;

static class TestDescription_suite_TestDynTypePermsSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDynTypePermsSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestDynTypePermsSuite, suiteDescription_TestDynTypePermsSuite, 258, "Testto_little_endian" ) {}
 void runTest() { suite_TestDynTypePermsSuite.Testto_little_endian(); }
} testDescription_suite_TestDynTypePermsSuite_Testto_little_endian;

#include "..\TestFocusedDynamicMessageSuite.h"

static TestFocusedDynamicMessageSuite suite_TestFocusedDynamicMessageSuite;

static CxxTest::List Tests_TestFocusedDynamicMessageSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestFocusedDynamicMessageSuite( "../TestFocusedDynamicMessageSuite.h", 52, "TestFocusedDynamicMessageSuite", suite_TestFocusedDynamicMessageSuite, Tests_TestFocusedDynamicMessageSuite );

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 76, "Test_write_array_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_array_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 77, "Test_read_array_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_array_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 79, "Test_write_array_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_array_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_array_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 80, "Test_read_array_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_array_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_array_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_fundamental : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_fundamental() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 82, "Test_write_vector_fundamental" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_fundamental(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_fundamental;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_fundamental : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_fundamental() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 83, "Test_read_vector_fundamental" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_fundamental(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_fundamental;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_fixed_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_fixed_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 85, "Test_write_vector_with_nested_fixed_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_with_nested_fixed_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_fixed_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_fixed_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_fixed_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 86, "Test_read_vector_with_nested_fixed_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_with_nested_fixed_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_fixed_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_dynamic_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_dynamic_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 88, "Test_write_vector_with_nested_dynamic_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_with_nested_dynamic_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_with_nested_dynamic_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_dynamic_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_dynamic_size() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 89, "Test_read_vector_with_nested_dynamic_size" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_with_nested_dynamic_size(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_with_nested_dynamic_size;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 91, "Test_write_vector_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_bitsets : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_bitsets() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 92, "Test_read_vector_of_bitsets" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_of_bitsets(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_bitsets;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 94, "Test_write_vector_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_arrays : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_arrays() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 95, "Test_read_vector_of_arrays" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_read_vector_of_arrays(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_read_vector_of_arrays;

static class TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_vectors : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_vectors() : CxxTest::RealTestDescription( Tests_TestFocusedDynamicMessageSuite, suiteDescription_TestFocusedDynamicMessageSuite, 97, "Test_write_vector_of_vectors" ) {}
 void runTest() { suite_TestFocusedDynamicMessageSuite.Test_write_vector_of_vectors(); }
} testDescription_suite_TestFocusedDynamicMessageSuite_Test_write_vector_of_vectors;

#include "..\TestOptionalMessageSuite.h"

static TestOptionalMessageSuite suite_TestOptionalMessageSuite;

static CxxTest::List Tests_TestOptionalMessageSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestOptionalMessageSuite( "../TestOptionalMessageSuite.h", 128, "TestOptionalMessageSuite", suite_TestOptionalMessageSuite, Tests_TestOptionalMessageSuite );

static class TestDescription_suite_TestOptionalMessageSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 300, "TestDefaultCtor" ) {}
 void runTest() { suite_TestOptionalMessageSuite.TestDefaultCtor(); }
} testDescription_suite_TestOptionalMessageSuite_TestDefaultCtor;

static class TestDescription_suite_TestOptionalMessageSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 301, "TestCopyCtor" ) {}
 void runTest() { suite_TestOptionalMessageSuite.TestCopyCtor(); }
} testDescription_suite_TestOptionalMessageSuite_TestCopyCtor;

static class TestDescription_suite_TestOptionalMessageSuite_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 302, "TestValueCtor" ) {}
 void runTest() { suite_TestOptionalMessageSuite.TestValueCtor(); }
} testDescription_suite_TestOptionalMessageSuite_TestValueCtor;

static class TestDescription_suite_TestOptionalMessageSuite_TestAssignmentOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_TestAssignmentOperator() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 303, "TestAssignmentOperator" ) {}
 void runTest() { suite_TestOptionalMessageSuite.TestAssignmentOperator(); }
} testDescription_suite_TestOptionalMessageSuite_TestAssignmentOperator;

static class TestDescription_suite_TestOptionalMessageSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 304, "Testempty" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testempty(); }
} testDescription_suite_TestOptionalMessageSuite_Testempty;

static class TestDescription_suite_TestOptionalMessageSuite_Testempty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testempty_false() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 305, "Testempty_false" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testempty_false(); }
} testDescription_suite_TestOptionalMessageSuite_Testempty_false;

static class TestDescription_suite_TestOptionalMessageSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 306, "TestSize" ) {}
 void runTest() { suite_TestOptionalMessageSuite.TestSize(); }
} testDescription_suite_TestOptionalMessageSuite_TestSize;

static class TestDescription_suite_TestOptionalMessageSuite_Testis_host_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testis_host_order() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 307, "Testis_host_order" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testis_host_order(); }
} testDescription_suite_TestOptionalMessageSuite_Testis_host_order;

static class TestDescription_suite_TestOptionalMessageSuite_Testis_host_order_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testis_host_order_false() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 308, "Testis_host_order_false" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testis_host_order_false(); }
} testDescription_suite_TestOptionalMessageSuite_Testis_host_order_false;

static class TestDescription_suite_TestOptionalMessageSuite_TestAssign : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_TestAssign() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 309, "TestAssign" ) {}
 void runTest() { suite_TestOptionalMessageSuite.TestAssign(); }
} testDescription_suite_TestOptionalMessageSuite_TestAssign;

static class TestDescription_suite_TestOptionalMessageSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 310, "TestClear" ) {}
 void runTest() { suite_TestOptionalMessageSuite.TestClear(); }
} testDescription_suite_TestOptionalMessageSuite_TestClear;

static class TestDescription_suite_TestOptionalMessageSuite_Testdata : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testdata() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 311, "Testdata" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testdata(); }
} testDescription_suite_TestOptionalMessageSuite_Testdata;

static class TestDescription_suite_TestOptionalMessageSuite_Testto_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testto_host() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 314, "Testto_host" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testto_host(); }
} testDescription_suite_TestOptionalMessageSuite_Testto_host;

static class TestDescription_suite_TestOptionalMessageSuite_Testto_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testto_network() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 315, "Testto_network" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testto_network(); }
} testDescription_suite_TestOptionalMessageSuite_Testto_network;

static class TestDescription_suite_TestOptionalMessageSuite_Testto_big_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testto_big_endian() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 316, "Testto_big_endian" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testto_big_endian(); }
} testDescription_suite_TestOptionalMessageSuite_Testto_big_endian;

static class TestDescription_suite_TestOptionalMessageSuite_Testto_little_endian : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalMessageSuite_Testto_little_endian() : CxxTest::RealTestDescription( Tests_TestOptionalMessageSuite, suiteDescription_TestOptionalMessageSuite, 317, "Testto_little_endian" ) {}
 void runTest() { suite_TestOptionalMessageSuite.Testto_little_endian(); }
} testDescription_suite_TestOptionalMessageSuite_Testto_little_endian;

#include "..\TestOptionalProxySuite.h"

static TestOptionalProxySuite suite_TestOptionalProxySuite;

static CxxTest::List Tests_TestOptionalProxySuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestOptionalProxySuite( "../TestOptionalProxySuite.h", 62, "TestOptionalProxySuite", suite_TestOptionalProxySuite, Tests_TestOptionalProxySuite );

static class TestDescription_suite_TestOptionalProxySuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 109, "TestCopyConstructor" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestCopyConstructor(); }
} testDescription_suite_TestOptionalProxySuite_TestCopyConstructor;

static class TestDescription_suite_TestOptionalProxySuite_TestValueConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestValueConstructor() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 110, "TestValueConstructor" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestValueConstructor(); }
} testDescription_suite_TestOptionalProxySuite_TestValueConstructor;

static class TestDescription_suite_TestOptionalProxySuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 111, "TestAssignment" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestAssignment(); }
} testDescription_suite_TestOptionalProxySuite_TestAssignment;

static class TestDescription_suite_TestOptionalProxySuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 112, "TestValueAssignment" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestValueAssignment(); }
} testDescription_suite_TestOptionalProxySuite_TestValueAssignment;

static class TestDescription_suite_TestOptionalProxySuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 115, "TestOpEquals" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpEquals(); }
} testDescription_suite_TestOptionalProxySuite_TestOpEquals;

static class TestDescription_suite_TestOptionalProxySuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 116, "TestOpEquals_false" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpEquals_false(); }
} testDescription_suite_TestOptionalProxySuite_TestOpEquals_false;

static class TestDescription_suite_TestOptionalProxySuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 117, "TestOpNotEquals" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpNotEquals(); }
} testDescription_suite_TestOptionalProxySuite_TestOpNotEquals;

static class TestDescription_suite_TestOptionalProxySuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 118, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpNotEquals_false(); }
} testDescription_suite_TestOptionalProxySuite_TestOpNotEquals_false;

static class TestDescription_suite_TestOptionalProxySuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 119, "TestOpLessThan" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpLessThan(); }
} testDescription_suite_TestOptionalProxySuite_TestOpLessThan;

static class TestDescription_suite_TestOptionalProxySuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 120, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpLessThan_false(); }
} testDescription_suite_TestOptionalProxySuite_TestOpLessThan_false;

static class TestDescription_suite_TestOptionalProxySuite_TestIsValid_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestIsValid_true() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 123, "TestIsValid_true" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestIsValid_true(); }
} testDescription_suite_TestOptionalProxySuite_TestIsValid_true;

static class TestDescription_suite_TestOptionalProxySuite_TestIsValid_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestIsValid_false() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 124, "TestIsValid_false" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestIsValid_false(); }
} testDescription_suite_TestOptionalProxySuite_TestIsValid_false;

static class TestDescription_suite_TestOptionalProxySuite_TestValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestValid() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 125, "TestValid" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestValid(); }
} testDescription_suite_TestOptionalProxySuite_TestValid;

static class TestDescription_suite_TestOptionalProxySuite_TestReset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestReset() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 126, "TestReset" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestReset(); }
} testDescription_suite_TestOptionalProxySuite_TestReset;

static class TestDescription_suite_TestOptionalProxySuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestClear() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 128, "TestClear" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestClear(); }
} testDescription_suite_TestOptionalProxySuite_TestClear;

static class TestDescription_suite_TestOptionalProxySuite_TestReserve : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestReserve() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 129, "TestReserve" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestReserve(); }
} testDescription_suite_TestOptionalProxySuite_TestReserve;

static class TestDescription_suite_TestOptionalProxySuite_TestCapacity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestCapacity() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 130, "TestCapacity" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestCapacity(); }
} testDescription_suite_TestOptionalProxySuite_TestCapacity;

static class TestDescription_suite_TestOptionalProxySuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestSize() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 131, "TestSize" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestSize(); }
} testDescription_suite_TestOptionalProxySuite_TestSize;

static class TestDescription_suite_TestOptionalProxySuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestGet() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 134, "TestGet" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestGet(); }
} testDescription_suite_TestOptionalProxySuite_TestGet;

static class TestDescription_suite_TestOptionalProxySuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestSet() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 135, "TestSet" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestSet(); }
} testDescription_suite_TestOptionalProxySuite_TestSet;

static class TestDescription_suite_TestOptionalProxySuite_TestAt_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestAt_const() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 137, "TestAt_const" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestAt_const(); }
} testDescription_suite_TestOptionalProxySuite_TestAt_const;

static class TestDescription_suite_TestOptionalProxySuite_TestAt : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestAt() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 138, "TestAt" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestAt(); }
} testDescription_suite_TestOptionalProxySuite_TestAt;

static class TestDescription_suite_TestOptionalProxySuite_TestOpSquare_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpSquare_const() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 139, "TestOpSquare_const" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpSquare_const(); }
} testDescription_suite_TestOptionalProxySuite_TestOpSquare_const;

static class TestDescription_suite_TestOptionalProxySuite_TestOpSquare : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestOpSquare() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 140, "TestOpSquare" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestOpSquare(); }
} testDescription_suite_TestOptionalProxySuite_TestOpSquare;

static class TestDescription_suite_TestOptionalProxySuite_TestFront_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestFront_const() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 141, "TestFront_const" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestFront_const(); }
} testDescription_suite_TestOptionalProxySuite_TestFront_const;

static class TestDescription_suite_TestOptionalProxySuite_TestFront : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestFront() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 142, "TestFront" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestFront(); }
} testDescription_suite_TestOptionalProxySuite_TestFront;

static class TestDescription_suite_TestOptionalProxySuite_TestBack_const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestBack_const() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 143, "TestBack_const" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestBack_const(); }
} testDescription_suite_TestOptionalProxySuite_TestBack_const;

static class TestDescription_suite_TestOptionalProxySuite_TestBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestBack() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 144, "TestBack" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestBack(); }
} testDescription_suite_TestOptionalProxySuite_TestBack;

static class TestDescription_suite_TestOptionalProxySuite_TestBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestBegin() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 147, "TestBegin" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestBegin(); }
} testDescription_suite_TestOptionalProxySuite_TestBegin;

static class TestDescription_suite_TestOptionalProxySuite_TestEnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestEnd() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 148, "TestEnd" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestEnd(); }
} testDescription_suite_TestOptionalProxySuite_TestEnd;

static class TestDescription_suite_TestOptionalProxySuite_TestRBegin : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestRBegin() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 149, "TestRBegin" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestRBegin(); }
} testDescription_suite_TestOptionalProxySuite_TestRBegin;

static class TestDescription_suite_TestOptionalProxySuite_TestREnd : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestREnd() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 150, "TestREnd" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestREnd(); }
} testDescription_suite_TestOptionalProxySuite_TestREnd;

static class TestDescription_suite_TestOptionalProxySuite_TestErase : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestErase() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 153, "TestErase" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestErase(); }
} testDescription_suite_TestOptionalProxySuite_TestErase;

static class TestDescription_suite_TestOptionalProxySuite_TestErase_range : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestErase_range() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 154, "TestErase_range" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestErase_range(); }
} testDescription_suite_TestOptionalProxySuite_TestErase_range;

static class TestDescription_suite_TestOptionalProxySuite_TestPushBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestPushBack() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 155, "TestPushBack" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestPushBack(); }
} testDescription_suite_TestOptionalProxySuite_TestPushBack;

static class TestDescription_suite_TestOptionalProxySuite_TestPushBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestPushBack_empty() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 156, "TestPushBack_empty" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestPushBack_empty(); }
} testDescription_suite_TestOptionalProxySuite_TestPushBack_empty;

static class TestDescription_suite_TestOptionalProxySuite_TestPopBack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestPopBack() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 157, "TestPopBack" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestPopBack(); }
} testDescription_suite_TestOptionalProxySuite_TestPopBack;

static class TestDescription_suite_TestOptionalProxySuite_TestPopBack_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestPopBack_empty() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 158, "TestPopBack_empty" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestPopBack_empty(); }
} testDescription_suite_TestOptionalProxySuite_TestPopBack_empty;

static class TestDescription_suite_TestOptionalProxySuite_TestResize_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestResize_smaller() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 159, "TestResize_smaller" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestResize_smaller(); }
} testDescription_suite_TestOptionalProxySuite_TestResize_smaller;

static class TestDescription_suite_TestOptionalProxySuite_TestResize_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestResize_larger() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 160, "TestResize_larger" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestResize_larger(); }
} testDescription_suite_TestOptionalProxySuite_TestResize_larger;

static class TestDescription_suite_TestOptionalProxySuite_TestResize_default_smaller : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestResize_default_smaller() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 161, "TestResize_default_smaller" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestResize_default_smaller(); }
} testDescription_suite_TestOptionalProxySuite_TestResize_default_smaller;

static class TestDescription_suite_TestOptionalProxySuite_TestResize_default_larger : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestResize_default_larger() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 162, "TestResize_default_larger" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestResize_default_larger(); }
} testDescription_suite_TestOptionalProxySuite_TestResize_default_larger;

static class TestDescription_suite_TestOptionalProxySuite_TestSwap : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestSwap() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 163, "TestSwap" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestSwap(); }
} testDescription_suite_TestOptionalProxySuite_TestSwap;

static class TestDescription_suite_TestOptionalProxySuite_TestSwap_vector : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptionalProxySuite_TestSwap_vector() : CxxTest::RealTestDescription( Tests_TestOptionalProxySuite, suiteDescription_TestOptionalProxySuite, 164, "TestSwap_vector" ) {}
 void runTest() { suite_TestOptionalProxySuite.TestSwap_vector(); }
} testDescription_suite_TestOptionalProxySuite_TestSwap_vector;

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
