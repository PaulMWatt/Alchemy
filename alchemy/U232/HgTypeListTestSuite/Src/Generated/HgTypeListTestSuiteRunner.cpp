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
bool suite_HgTypeListTestSuite_init = false;
#include "..\hgtypelisttestsuite.h"

static HgTypeListTestSuite suite_HgTypeListTestSuite;

static CxxTest::List Tests_HgTypeListTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_HgTypeListTestSuite( "../hgtypelisttestsuite.h", 122, "HgTypeListTestSuite", suite_HgTypeListTestSuite, Tests_HgTypeListTestSuite );

static class TestDescription_suite_HgTypeListTestSuite_TestNoSubstitution : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestNoSubstitution() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 143, "TestNoSubstitution" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestNoSubstitution(); }
} testDescription_suite_HgTypeListTestSuite_TestNoSubstitution;

static class TestDescription_suite_HgTypeListTestSuite_TestArrayNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestArrayNoSub() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 144, "TestArrayNoSub" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestArrayNoSub(); }
} testDescription_suite_HgTypeListTestSuite_TestArrayNoSub;

static class TestDescription_suite_HgTypeListTestSuite_TestArraySubBitFields : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestArraySubBitFields() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 145, "TestArraySubBitFields" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestArraySubBitFields(); }
} testDescription_suite_HgTypeListTestSuite_TestArraySubBitFields;

static class TestDescription_suite_HgTypeListTestSuite_TestArraySubNested : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestArraySubNested() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 146, "TestArraySubNested" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestArraySubNested(); }
} testDescription_suite_HgTypeListTestSuite_TestArraySubNested;

static class TestDescription_suite_HgTypeListTestSuite_TestArrayArrayNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestArrayArrayNoSub() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 147, "TestArrayArrayNoSub" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestArrayArrayNoSub(); }
} testDescription_suite_HgTypeListTestSuite_TestArrayArrayNoSub;

static class TestDescription_suite_HgTypeListTestSuite_TestArrayArrayBitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestArrayArrayBitSet() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 148, "TestArrayArrayBitSet" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestArrayArrayBitSet(); }
} testDescription_suite_HgTypeListTestSuite_TestArrayArrayBitSet;

static class TestDescription_suite_HgTypeListTestSuite_TestVectorNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestVectorNoSub() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 149, "TestVectorNoSub" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestVectorNoSub(); }
} testDescription_suite_HgTypeListTestSuite_TestVectorNoSub;

static class TestDescription_suite_HgTypeListTestSuite_TestVectorSubBitFields : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestVectorSubBitFields() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 150, "TestVectorSubBitFields" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestVectorSubBitFields(); }
} testDescription_suite_HgTypeListTestSuite_TestVectorSubBitFields;

static class TestDescription_suite_HgTypeListTestSuite_TestVectorSubNested : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestVectorSubNested() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 151, "TestVectorSubNested" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestVectorSubNested(); }
} testDescription_suite_HgTypeListTestSuite_TestVectorSubNested;

static class TestDescription_suite_HgTypeListTestSuite_TestVectorArrayNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestVectorArrayNoSub() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 152, "TestVectorArrayNoSub" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestVectorArrayNoSub(); }
} testDescription_suite_HgTypeListTestSuite_TestVectorArrayNoSub;

static class TestDescription_suite_HgTypeListTestSuite_TestVectorArrayBitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestVectorArrayBitSet() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 153, "TestVectorArrayBitSet" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestVectorArrayBitSet(); }
} testDescription_suite_HgTypeListTestSuite_TestVectorArrayBitSet;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
