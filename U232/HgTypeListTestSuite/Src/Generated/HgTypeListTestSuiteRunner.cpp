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
bool suite_Hgtype_listTestSuite_init = false;
#include "..\hgtypelisttestsuite.h"

static Hgtype_listTestSuite suite_Hgtype_listTestSuite;

static CxxTest::List Tests_Hgtype_listTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Hgtype_listTestSuite( "../hgtypelisttestsuite.h", 125, "Hgtype_listTestSuite", suite_Hgtype_listTestSuite, Tests_Hgtype_listTestSuite );

static class TestDescription_suite_Hgtype_listTestSuite_TestNoSubstitution : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Hgtype_listTestSuite_TestNoSubstitution() : CxxTest::RealTestDescription( Tests_Hgtype_listTestSuite, suiteDescription_Hgtype_listTestSuite, 146, "TestNoSubstitution" ) {}
 void runTest() { suite_Hgtype_listTestSuite.TestNoSubstitution(); }
} testDescription_suite_Hgtype_listTestSuite_TestNoSubstitution;

static class TestDescription_suite_Hgtype_listTestSuite_TestArrayNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Hgtype_listTestSuite_TestArrayNoSub() : CxxTest::RealTestDescription( Tests_Hgtype_listTestSuite, suiteDescription_Hgtype_listTestSuite, 147, "TestArrayNoSub" ) {}
 void runTest() { suite_Hgtype_listTestSuite.TestArrayNoSub(); }
} testDescription_suite_Hgtype_listTestSuite_TestArrayNoSub;

static class TestDescription_suite_Hgtype_listTestSuite_TestArrayArrayNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Hgtype_listTestSuite_TestArrayArrayNoSub() : CxxTest::RealTestDescription( Tests_Hgtype_listTestSuite, suiteDescription_Hgtype_listTestSuite, 152, "TestArrayArrayNoSub" ) {}
 void runTest() { suite_Hgtype_listTestSuite.TestArrayArrayNoSub(); }
} testDescription_suite_Hgtype_listTestSuite_TestArrayArrayNoSub;

static class TestDescription_suite_Hgtype_listTestSuite_TestVectorNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Hgtype_listTestSuite_TestVectorNoSub() : CxxTest::RealTestDescription( Tests_Hgtype_listTestSuite, suiteDescription_Hgtype_listTestSuite, 154, "TestVectorNoSub" ) {}
 void runTest() { suite_Hgtype_listTestSuite.TestVectorNoSub(); }
} testDescription_suite_Hgtype_listTestSuite_TestVectorNoSub;

static class TestDescription_suite_Hgtype_listTestSuite_TestVectorArrayNoSub : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Hgtype_listTestSuite_TestVectorArrayNoSub() : CxxTest::RealTestDescription( Tests_Hgtype_listTestSuite, suiteDescription_Hgtype_listTestSuite, 159, "TestVectorArrayNoSub" ) {}
 void runTest() { suite_Hgtype_listTestSuite.TestVectorArrayNoSub(); }
} testDescription_suite_Hgtype_listTestSuite_TestVectorArrayNoSub;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
