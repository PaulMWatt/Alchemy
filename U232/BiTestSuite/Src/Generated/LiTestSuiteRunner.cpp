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
CxxTest::StaticSuiteDescription suiteDescription_BiTestSuite( "../BiTestSuite.h", 43, "BiTestSuite", suite_BiTestSuite, Tests_BiTestSuite );

static class TestDescription_suite_BiTestSuite_TestCase1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_BiTestSuite_TestCase1() : CxxTest::RealTestDescription( Tests_BiTestSuite, suiteDescription_BiTestSuite, 74, "TestCase1" ) {}
 void runTest() { suite_BiTestSuite.TestCase1(); }
} testDescription_suite_BiTestSuite_TestCase1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
