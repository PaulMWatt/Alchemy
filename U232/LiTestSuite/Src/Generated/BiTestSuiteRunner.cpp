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
bool suite_LiTestSuite_init = false;
#include "..\LiTestSuite.h"

static LiTestSuite suite_LiTestSuite;

static CxxTest::List Tests_LiTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_LiTestSuite( "../LiTestSuite.h", 41, "LiTestSuite", suite_LiTestSuite, Tests_LiTestSuite );

static class TestDescription_suite_LiTestSuite_TestCase1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LiTestSuite_TestCase1() : CxxTest::RealTestDescription( Tests_LiTestSuite, suiteDescription_LiTestSuite, 72, "TestCase1" ) {}
 void runTest() { suite_LiTestSuite.TestCase1(); }
} testDescription_suite_LiTestSuite_TestCase1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
