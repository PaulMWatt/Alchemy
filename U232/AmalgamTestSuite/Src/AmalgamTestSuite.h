//  @file AmalgamTestSuite.hpp
// 
//  Test fixture for Alchemy Amalgam.
//  This is a collection of interface adapters to allow the conversion
//  from Hg formats into other communication formats such as JSON and XML.
// 
//  @author Paul M. Watt
// 
//  ****************************************************************************
#ifndef AmalgamTestSuite_H_INCLUDED
#define AmalgamTestSuite_H_INCLUDED

#include <cxxtest/TestSuite.h>

//  ****************************************************************************
//  AmalgamTestSuite Test Suite class.
//
class AmalgamTestSuite : public CxxTest::TestSuite
{
public:

  AmalgamTestSuite()
  {
    // TODO: Construct Test Suite Object
  }

  //  ****************************************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {
    // TODO: Add common fixture setup code if any exists.
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {
    // TODO: Add common fixture teardown code if any exists.
  }

protected:
  //  Test Suite Data **********************************************************


  //  Creator Methods **********************************************************

  // TODO: Use creator methods to reduce redundant setup code in test cases.

public:
  //  Test Cases ***************************************************************
  // TODO: Add a new function for each unique test to be performed in this suite. 
  void TestCase1(void);

};

//  ****************************************************************************
void AmalgamTestSuite::TestCase1(void)
{
  // TODO: Implement Single Test Case.
  // TODO: The implementation can also be placed in a cpp file if desired.
}

#endif