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
bool suite_TestBitSetFieldSuite_init = false;
#include "..\TestBitSetMsgFieldSuite.h"

static TestBitSetFieldSuite suite_TestBitSetFieldSuite;

static CxxTest::List Tests_TestBitSetFieldSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestBitSetFieldSuite( "../TestBitSetMsgFieldSuite.h", 90, "TestBitSetFieldSuite", suite_TestBitSetFieldSuite, Tests_TestBitSetFieldSuite );

static class TestDescription_suite_TestBitSetFieldSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 144, "TestCopyConstructor" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestCopyConstructor(); }
} testDescription_suite_TestBitSetFieldSuite_TestCopyConstructor;

static class TestDescription_suite_TestBitSetFieldSuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 145, "TestAssignment" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestAssignment(); }
} testDescription_suite_TestBitSetFieldSuite_TestAssignment;

static class TestDescription_suite_TestBitSetFieldSuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 146, "TestValueAssignment" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestValueAssignment(); }
} testDescription_suite_TestBitSetFieldSuite_TestValueAssignment;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 149, "TestOpEquals" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpEquals(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpEquals;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 150, "TestOpEquals_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpEquals_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpEquals_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 151, "TestOpNotEquals" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpNotEquals(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpNotEquals;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 152, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpNotEquals_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpNotEquals_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 153, "TestOpLessThan" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThan(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThan;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 154, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThan_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThan_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 155, "TestOpLessThanOrEqual" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThanOrEqual(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 156, "TestOpLessThanOrEqual_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpLessThanOrEqual_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpLessThanOrEqual_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 157, "TestOpGreaterThan" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThan(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 158, "TestOpGreaterThan_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThan_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThan_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 159, "TestOpGreaterThanOrEqual" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThanOrEqual(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual;

static class TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 160, "TestOpGreaterThanOrEqual_false" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestOpGreaterThanOrEqual_false(); }
} testDescription_suite_TestBitSetFieldSuite_TestOpGreaterThanOrEqual_false;

static class TestDescription_suite_TestBitSetFieldSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 163, "TestClear" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestClear(); }
} testDescription_suite_TestBitSetFieldSuite_TestClear;

static class TestDescription_suite_TestBitSetFieldSuite_TestClear_Empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestClear_Empty() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 164, "TestClear_Empty" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestClear_Empty(); }
} testDescription_suite_TestBitSetFieldSuite_TestClear_Empty;

static class TestDescription_suite_TestBitSetFieldSuite_TestGet_Const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestGet_Const() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 167, "TestGet_Const" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestGet_Const(); }
} testDescription_suite_TestBitSetFieldSuite_TestGet_Const;

static class TestDescription_suite_TestBitSetFieldSuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestGet() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 168, "TestGet" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestGet(); }
} testDescription_suite_TestBitSetFieldSuite_TestGet;

static class TestDescription_suite_TestBitSetFieldSuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestSet() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 169, "TestSet" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestSet(); }
} testDescription_suite_TestBitSetFieldSuite_TestSet;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Ctor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Ctor() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 173, "TestBitField_Ctor" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Ctor(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Ctor;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 174, "TestBitField_Assignment" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Assignment(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment_Truncate : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment_Truncate() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 175, "TestBitField_Assignment_Truncate" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Assignment_Truncate(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Assignment_Truncate;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 176, "TestBitField_Conversion" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Conversion(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion_Empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion_Empty() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 177, "TestBitField_Conversion_Empty" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Conversion_Empty(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Conversion_Empty;

static class TestDescription_suite_TestBitSetFieldSuite_TestBitField_Attach : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestBitSetFieldSuite_TestBitField_Attach() : CxxTest::RealTestDescription( Tests_TestBitSetFieldSuite, suiteDescription_TestBitSetFieldSuite, 178, "TestBitField_Attach" ) {}
 void runTest() { suite_TestBitSetFieldSuite.TestBitField_Attach(); }
} testDescription_suite_TestBitSetFieldSuite_TestBitField_Attach;

#include "..\TestMessageSuite.h"

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

#include "..\TestMsgBufferSuite.h"

static TestMsgBufferSuite suite_TestMsgBufferSuite;

static CxxTest::List Tests_TestMsgBufferSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestMsgBufferSuite( "../TestMsgBufferSuite.h", 165, "TestMsgBufferSuite", suite_TestMsgBufferSuite, Tests_TestMsgBufferSuite );

static class TestDescription_suite_TestMsgBufferSuite_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 352, "TestDefaultCtor" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestDefaultCtor(); }
} testDescription_suite_TestMsgBufferSuite_TestDefaultCtor;

static class TestDescription_suite_TestMsgBufferSuite_TestCopyCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestCopyCtor() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 353, "TestCopyCtor" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestCopyCtor(); }
} testDescription_suite_TestMsgBufferSuite_TestCopyCtor;

static class TestDescription_suite_TestMsgBufferSuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 354, "TestDtor" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestDtor(); }
} testDescription_suite_TestMsgBufferSuite_TestDtor;

static class TestDescription_suite_TestMsgBufferSuite_TestOpAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestOpAssignment() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 355, "TestOpAssignment" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestOpAssignment(); }
} testDescription_suite_TestMsgBufferSuite_TestOpAssignment;

static class TestDescription_suite_TestMsgBufferSuite_TestOpAssignment_ToSelf : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestOpAssignment_ToSelf() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 356, "TestOpAssignment_ToSelf" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestOpAssignment_ToSelf(); }
} testDescription_suite_TestMsgBufferSuite_TestOpAssignment_ToSelf;

static class TestDescription_suite_TestMsgBufferSuite_Testempty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testempty() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 357, "Testempty" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testempty(); }
} testDescription_suite_TestMsgBufferSuite_Testempty;

static class TestDescription_suite_TestMsgBufferSuite_Testempty_NotEmpty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testempty_NotEmpty() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 358, "Testempty_NotEmpty" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testempty_NotEmpty(); }
} testDescription_suite_TestMsgBufferSuite_Testempty_NotEmpty;

static class TestDescription_suite_TestMsgBufferSuite_TestSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSize() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 359, "TestSize" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSize(); }
} testDescription_suite_TestMsgBufferSuite_TestSize;

static class TestDescription_suite_TestMsgBufferSuite_Testbuffer_read : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testbuffer_read() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 360, "Testbuffer_read" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testbuffer_read(); }
} testDescription_suite_TestMsgBufferSuite_Testbuffer_read;

static class TestDescription_suite_TestMsgBufferSuite_Testbuffer_write : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testbuffer_write() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 361, "Testbuffer_write" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testbuffer_write(); }
} testDescription_suite_TestMsgBufferSuite_Testbuffer_write;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 362, "Testget_data" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_OffsetLTZero : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_OffsetLTZero() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 363, "Testget_data_OOB_OffsetLTZero" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data_OOB_OffsetLTZero(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data_OOB_OffsetLTZero;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_ExceedsSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data_OOB_ExceedsSize() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 364, "Testget_data_OOB_ExceedsSize" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data_OOB_ExceedsSize(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data_OOB_ExceedsSize;

static class TestDescription_suite_TestMsgBufferSuite_Testget_data_NotValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_Testget_data_NotValid() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 365, "Testget_data_NotValid" ) {}
 void runTest() { suite_TestMsgBufferSuite.Testget_data_NotValid(); }
} testDescription_suite_TestMsgBufferSuite_Testget_data_NotValid;

static class TestDescription_suite_TestMsgBufferSuite_TestSetData : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSetData() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 366, "TestSetData" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSetData(); }
} testDescription_suite_TestMsgBufferSuite_TestSetData;

static class TestDescription_suite_TestMsgBufferSuite_TestSetData_OOB_ExceedsSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSetData_OOB_ExceedsSize() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 367, "TestSetData_OOB_ExceedsSize" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSetData_OOB_ExceedsSize(); }
} testDescription_suite_TestMsgBufferSuite_TestSetData_OOB_ExceedsSize;

static class TestDescription_suite_TestMsgBufferSuite_TestSetData_NotValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestSetData_NotValid() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 368, "TestSetData_NotValid" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestSetData_NotValid(); }
} testDescription_suite_TestMsgBufferSuite_TestSetData_NotValid;

static class TestDescription_suite_TestMsgBufferSuite_TestClone : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestClone() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 369, "TestClone" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestClone(); }
} testDescription_suite_TestMsgBufferSuite_TestClone;

static class TestDescription_suite_TestMsgBufferSuite_TestClone_NotValid : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestClone_NotValid() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 370, "TestClone_NotValid" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestClone_NotValid(); }
} testDescription_suite_TestMsgBufferSuite_TestClone_NotValid;

static class TestDescription_suite_TestMsgBufferSuite_TestClone_BufferAllocFailed : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMsgBufferSuite_TestClone_BufferAllocFailed() : CxxTest::RealTestDescription( Tests_TestMsgBufferSuite, suiteDescription_TestMsgBufferSuite, 371, "TestClone_BufferAllocFailed" ) {}
 void runTest() { suite_TestMsgBufferSuite.TestClone_BufferAllocFailed(); }
} testDescription_suite_TestMsgBufferSuite_TestClone_BufferAllocFailed;

#include "..\TestMsgFieldSuite.h"

static TestDatumSuite suite_TestDatumSuite;

static CxxTest::List Tests_TestDatumSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestDatumSuite( "../TestMsgFieldSuite.h", 66, "TestDatumSuite", suite_TestDatumSuite, Tests_TestDatumSuite );

static class TestDescription_suite_TestDatumSuite_TestDtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestDtor() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 101, "TestDtor" ) {}
 void runTest() { suite_TestDatumSuite.TestDtor(); }
} testDescription_suite_TestDatumSuite_TestDtor;

static class TestDescription_suite_TestDatumSuite_TestCopyConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestCopyConstructor() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 102, "TestCopyConstructor" ) {}
 void runTest() { suite_TestDatumSuite.TestCopyConstructor(); }
} testDescription_suite_TestDatumSuite_TestCopyConstructor;

static class TestDescription_suite_TestDatumSuite_TestAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestAssignment() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 103, "TestAssignment" ) {}
 void runTest() { suite_TestDatumSuite.TestAssignment(); }
} testDescription_suite_TestDatumSuite_TestAssignment;

static class TestDescription_suite_TestDatumSuite_TestValueAssignment : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestValueAssignment() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 104, "TestValueAssignment" ) {}
 void runTest() { suite_TestDatumSuite.TestValueAssignment(); }
} testDescription_suite_TestDatumSuite_TestValueAssignment;

static class TestDescription_suite_TestDatumSuite_TestOpEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpEquals() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 107, "TestOpEquals" ) {}
 void runTest() { suite_TestDatumSuite.TestOpEquals(); }
} testDescription_suite_TestDatumSuite_TestOpEquals;

static class TestDescription_suite_TestDatumSuite_TestOpEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpEquals_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 108, "TestOpEquals_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpEquals_false(); }
} testDescription_suite_TestDatumSuite_TestOpEquals_false;

static class TestDescription_suite_TestDatumSuite_TestOpNotEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpNotEquals() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 109, "TestOpNotEquals" ) {}
 void runTest() { suite_TestDatumSuite.TestOpNotEquals(); }
} testDescription_suite_TestDatumSuite_TestOpNotEquals;

static class TestDescription_suite_TestDatumSuite_TestOpNotEquals_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpNotEquals_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 110, "TestOpNotEquals_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpNotEquals_false(); }
} testDescription_suite_TestDatumSuite_TestOpNotEquals_false;

static class TestDescription_suite_TestDatumSuite_TestOpLessThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThan() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 111, "TestOpLessThan" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThan(); }
} testDescription_suite_TestDatumSuite_TestOpLessThan;

static class TestDescription_suite_TestDatumSuite_TestOpLessThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThan_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 112, "TestOpLessThan_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThan_false(); }
} testDescription_suite_TestDatumSuite_TestOpLessThan_false;

static class TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 113, "TestOpLessThanOrEqual" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThanOrEqual(); }
} testDescription_suite_TestDatumSuite_TestOpLessThanOrEqual;

static class TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpLessThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 114, "TestOpLessThanOrEqual_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpLessThanOrEqual_false(); }
} testDescription_suite_TestDatumSuite_TestOpLessThanOrEqual_false;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThan : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThan() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 115, "TestOpGreaterThan" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThan(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThan;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThan_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThan_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 116, "TestOpGreaterThan_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThan_false(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThan_false;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 117, "TestOpGreaterThanOrEqual" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThanOrEqual(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual;

static class TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual_false() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 118, "TestOpGreaterThanOrEqual_false" ) {}
 void runTest() { suite_TestDatumSuite.TestOpGreaterThanOrEqual_false(); }
} testDescription_suite_TestDatumSuite_TestOpGreaterThanOrEqual_false;

static class TestDescription_suite_TestDatumSuite_TestClear : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestClear() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 121, "TestClear" ) {}
 void runTest() { suite_TestDatumSuite.TestClear(); }
} testDescription_suite_TestDatumSuite_TestClear;

static class TestDescription_suite_TestDatumSuite_TestClear_Empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestClear_Empty() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 122, "TestClear_Empty" ) {}
 void runTest() { suite_TestDatumSuite.TestClear_Empty(); }
} testDescription_suite_TestDatumSuite_TestClear_Empty;

static class TestDescription_suite_TestDatumSuite_TestGet_Const : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestGet_Const() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 125, "TestGet_Const" ) {}
 void runTest() { suite_TestDatumSuite.TestGet_Const(); }
} testDescription_suite_TestDatumSuite_TestGet_Const;

static class TestDescription_suite_TestDatumSuite_TestGet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestGet() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 126, "TestGet" ) {}
 void runTest() { suite_TestDatumSuite.TestGet(); }
} testDescription_suite_TestDatumSuite_TestGet;

static class TestDescription_suite_TestDatumSuite_TestSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestDatumSuite_TestSet() : CxxTest::RealTestDescription( Tests_TestDatumSuite, suiteDescription_TestDatumSuite, 128, "TestSet" ) {}
 void runTest() { suite_TestDatumSuite.TestSet(); }
} testDescription_suite_TestDatumSuite_TestSet;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
