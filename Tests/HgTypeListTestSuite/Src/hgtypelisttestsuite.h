//  HgTypeListTestSuite
//     
//  @file HgTypeListTestSuite.hpp
//  
//  Verifies the type modification processor to convert user-defined typelists to Hg compatible typelists.
//  
//  @author Paul
//  @date   2014.9.4: Paul    -- Initial release.
//  
//  TODO: Update with an appropriate license copyright 2014
//  
//   Verify data with these TEST ASSERTIONS:
//  
//   TS_FAIL(message):                        Fail unconditionally
//   TS_ASSERT(expr):                         Verify (expr) is true
//   TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
//   TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
//   TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
//   TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
//   TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
//   TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
//   TS_ASSERT_PREDICATE(P, x):               Verify P(x)
//   TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
//   TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
//   TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
//   TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
//   TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
//   TS_WARN(message):                        Print message as a warning
//   TS_TRACE(message):                       Print message as an information message
//  ****************************************************************************  
    
#ifndef HgTypeListTestSuite_H_INCLUDED
#define HgTypeListTestSuite_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <Hg/make_Hg_type_list.h>
#include <array>
#include <vector>

using namespace Hg;


HG_BEGIN_BIT_SET (uint32_t, mixed_bits)
  HG_BIT_FIELD   (0,   first,   5)
  HG_BIT_FIELD   (1,   second,  4)
  HG_BIT_FIELD   (2,   third,   3)
  HG_BIT_FIELD   (3,   fourth,  2)
  HG_BIT_FIELD   (4,   fifth,   1)
  HG_BIT_FIELD   (5,   sixth,   1)
  HG_BIT_FIELD   (6,   seventh, 1)
HG_END_BIT_SET

typedef TypeList
<
  uint32_t,      
  std::array<mixed_bits, 5>
> Hg_nested;

//  ****************************************************************************
//  A type array used to create the nested message field.
//
typedef TypeList
<
  uint32_t,      
  mixed_bits,        // Extra bytes are required after this field to test offsets.
  Hg_nested,
  std::array<uint32_t,    25>,
  std::array<mixed_bits,  20>,
  std::array<Hg_nested,   15>,
  std::array<std::array <uint32_t, 5>, 10>,
  std::array<std::vector<uint32_t>, 5>,
  std::vector<uint32_t>,
  std::vector<mixed_bits>,
  std::vector<Hg_nested>,
  std::vector<std::array <uint32_t, 5>>,
  std::vector<std::vector<mixed_bits>>
> hg_list_t;



//  ****************************************************************************
//  HgTypeListTestSuite Test Suite class.
class HgTypeListTestSuite : public CxxTest::TestSuite
{
public:

  HgTypeListTestSuite()
  {
    // TODO: Construct Test Suite Object
  }

  // Fixture Management ******************************************************
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
  // Test Suite Data *********************************************************

  // Creator Methods *********************************************************
  // TODO: Use creator methods to reduce redundant setup code in test cases.

public:
  // Test Cases **************************************************************
  // TODO: Add a new function for each unique test to be performed in this suite. 
  void TestCase1(void);

};

//  ****************************************************************************
void HgTypeListTestSuite::TestCase1(void)
{
  typedef make_Hg_type_list<hg_list_t>::type     hg_type;

  //hg_list_t   org;
  //hg_type     var;

}

#endif