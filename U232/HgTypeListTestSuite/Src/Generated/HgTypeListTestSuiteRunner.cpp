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
#include "C:\Development\Alchemy\Tests\HgTypeListTestSuite\Src\hgtypelisttestsuite.h"

static HgTypeListTestSuite suite_HgTypeListTestSuite;

static CxxTest::List Tests_HgTypeListTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_HgTypeListTestSuite( "../hgtypelisttestsuite.h", 84, "HgTypeListTestSuite", suite_HgTypeListTestSuite, Tests_HgTypeListTestSuite );

static class TestDescription_suite_HgTypeListTestSuite_TestCase1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_HgTypeListTestSuite_TestCase1() : CxxTest::RealTestDescription( Tests_HgTypeListTestSuite, suiteDescription_HgTypeListTestSuite, 115, "TestCase1" ) {}
 void runTest() { suite_HgTypeListTestSuite.TestCase1(); }
} testDescription_suite_HgTypeListTestSuite_TestCase1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
