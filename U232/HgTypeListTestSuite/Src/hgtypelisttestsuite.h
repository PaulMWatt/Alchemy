//  Hgtype_listTestSuite
//     
//  @file Hgtype_listTestSuite.hpp
//  
//  Verifies the type modification processor to convert user-defined typelists to Hg compatible typelists.
//  Each test verifies some substitution type that should or should not occur to create
//  the final Hg compatible typelist.
//  
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
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
    
#ifndef Hgtype_listTestSuite_H_INCLUDED
#define Hgtype_listTestSuite_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <Hg/make_Hg_type_list.h>
#include <array>
#include <vector>

using namespace Hg;

ALCHEMY_PACKED 
( uint32_t, 
  mixed_bits,
  ALCHEMY_BITS   (0,   first,   5),
  ALCHEMY_BITS   (1,   second,  4),
  ALCHEMY_BITS   (2,   third,   3),
  ALCHEMY_BITS   (3,   fourth,  2),
  ALCHEMY_BITS   (4,   fifth,   1),
  ALCHEMY_BITS   (5,   sixth,   1),
  ALCHEMY_BITS   (6,   seventh, 1)
);

namespace Hg
{
//  ****************************************************************************
typedef type_list
<
  uint32_t,      
  std::array<uint16_t, 5>
> Hg_nested_basic;

//  ****************************************************************************
typedef type_list
<
  uint32_t,      
  std::array<mixed_bits, 5>
> Hg_nested_sub;

}

//  ****************************************************************************
//  A type array used to create the nested message field.
//
typedef type_list
<
  uint32_t,      
  mixed_bits,        // Extra bytes are required after this field to test offsets.
  Hg_nested_basic,
  Hg_nested_sub,
  std::array<uint32_t,    25>,
  std::array<mixed_bits,  20>,
  std::array<Hg_nested_sub,   15>,
  std::array<std::array <uint32_t, 5>, 10>,
  std::array<std::vector<uint32_t>, 5>,
  std::vector<uint32_t>,
  std::vector<mixed_bits>,
  std::vector<Hg_nested_sub>,
  std::vector<std::array <uint32_t, 5>>,
  std::vector<std::vector<mixed_bits>>
> hg_list_t;

//  ****************************************************************************
//  The expected hg typelist after conversion of hg_list_t.
//
typedef type_list
<
  uint32_t,      
  mixed_bits,        // Extra bytes are required after this field to test offsets.
  Hg_nested_basic,
  Hg_nested_sub,
  std::array<uint32_t,    25>,
  std::array<mixed_bits,  20>,
  std::array<Hg_nested_sub,   15>,
  std::array<std::array <uint32_t, 5>, 10>,
  std::array<std::vector<uint32_t>, 5>,
  std::vector<uint32_t>,
  std::vector<mixed_bits>,
  std::vector<Hg_nested_sub>,
  std::vector<std::array <uint32_t, 5>>,
  std::vector<std::vector<mixed_bits>>
> expected_hg_list_t;


//  ****************************************************************************
//  Hgtype_listTestSuite Test Suite class.
class Hgtype_listTestSuite : public CxxTest::TestSuite
{
public:

  Hgtype_listTestSuite()
  { }

  // Fixture Management ******************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  { }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  { }

protected:
  // Test Suite Data *********************************************************

public:
  // Test Cases **************************************************************
  void TestNoSubstitution();
  void TestArrayNoSub();
  void TestArrayArrayNoSub();
  void TestVectorNoSub();
  void TestVectorArrayNoSub();

};

//  ****************************************************************************
void Hgtype_listTestSuite::TestNoSubstitution()
{
  // Verify a Typelist that does not perform any substitution for
  // any of the types used in the Typelist.
  typedef type_list
  <
    char,
    short,
    long,
    unsigned long,
    mixed_bits,
    Hg_nested_basic
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT((std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void Hgtype_listTestSuite::TestArrayNoSub()
{
  typedef type_list
  <
    std::array<char,  10>,
    std::array<short, 10>,
    std::array<long,  5>,
    std::array<unsigned long, 4>,
    std::array<Hg_nested_basic, 3>
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT((std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void Hgtype_listTestSuite::TestArrayArrayNoSub()
{
  typedef type_list
  <
    std::array< std::array<Hg::Hg_nested_basic, 10>, 5>
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT((std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void Hgtype_listTestSuite::TestVectorNoSub()
{
  typedef type_list
  <
    size_t,
    std::vector<char>,
    std::vector<short>,
    std::vector<long>,
    std::vector<unsigned long>,
    std::vector<Hg_nested_basic>
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT((std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void Hgtype_listTestSuite::TestVectorArrayNoSub()
{
  typedef type_list
  <
    std::vector< std::array<uint32_t, 10> >
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT((std::is_same<SUT, result_type>::value));
}


#endif