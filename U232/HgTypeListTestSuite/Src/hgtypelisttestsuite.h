//  HgTypeListTestSuite
//     
//  @file HgTypeListTestSuite.hpp
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
    
#ifndef HgTypeListTestSuite_H_INCLUDED
#define HgTypeListTestSuite_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <Hg/make_Hg_type_list.h>
#include <array>
#include <vector>

using namespace Hg;
namespace Hg
{

HG_BEGIN_PACKED (uint32_t, mixed_bits)
  HG_BIT_FIELD   (0,   first,   5)
  HG_BIT_FIELD   (1,   second,  4)
  HG_BIT_FIELD   (2,   third,   3)
  HG_BIT_FIELD   (3,   fourth,  2)
  HG_BIT_FIELD   (4,   fifth,   1)
  HG_BIT_FIELD   (5,   sixth,   1)
  HG_BIT_FIELD   (6,   seventh, 1)
HG_END_PACKED


//  ****************************************************************************
typedef TypeList
<
  uint32_t,      
  std::array<uint16_t, 5>
> Hg_nested_basic;

//  ****************************************************************************
typedef TypeList
<
  uint32_t,      
  std::array<mixed_bits, 5>
> Hg_nested_sub;

//  ****************************************************************************
typedef TypeList
<
  uint32_t,      
  Hg::BitFieldArray<mixed_bits, 5>
> Hg_nested_adjusted;

}

//  ****************************************************************************
//  A type array used to create the nested message field.
//
typedef TypeList
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
typedef TypeList
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
//  HgTypeListTestSuite Test Suite class.
class HgTypeListTestSuite : public CxxTest::TestSuite
{
public:

  HgTypeListTestSuite()
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
  void TestNoSubstitution(void);
  void TestArrayNoSub(void);
#ifdef ENABLE_BITFIELD_SEQUENCE
//  void TestArraySubBitFields(void);
//  void TestArraySubNested(void);
#endif
  void TestArrayArrayNoSub(void);
  void TestArrayArrayBitSet(void);
  void TestVectorNoSub(void);
#ifdef ENABLE_BITFIELD_SEQUENCE
//  void TestVectorSubBitFields(void);
//  void TestVectorSubNested(void);
#endif
  void TestVectorArrayNoSub(void);
  void TestVectorArrayBitSet(void);

};

//  ****************************************************************************
void HgTypeListTestSuite::TestNoSubstitution(void)
{
  // Verify a Typelist that does not perform any substitution for
  // any of the types used in the Typelist.
  typedef TypeList
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
void HgTypeListTestSuite::TestArrayNoSub(void)
{
  typedef TypeList
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

#ifdef ENABLE_BITFIELD_SEQUENCE
//  ****************************************************************************
void HgTypeListTestSuite::TestArraySubBitFields(void)
{
  typedef TypeList
  <
    std::array<mixed_bits, 5>
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT(!(std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void HgTypeListTestSuite::TestArraySubNested(void)
{
  typedef Hg::Hg_nested_sub                 SUT;
  typedef make_Hg_type_list<SUT>::type      result_type;

  TS_ASSERT(!(std::is_same<SUT, result_type>::value));
  TS_ASSERT((std::is_same<Hg::Hg_nested_adjusted, result_type>::value));
}
#endif

//  ****************************************************************************
void HgTypeListTestSuite::TestArrayArrayNoSub(void)
{
  typedef TypeList
  <
    std::array< std::array<Hg::Hg_nested_basic, 10>, 5>
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT((std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void HgTypeListTestSuite::TestArrayArrayBitSet(void)
{
  typedef TypeList
  <
    std::array< std::array<mixed_bits, 10>, 2 >
  > SUT;

  typedef TypeList
  <
    std::array< BitFieldArray<mixed_bits, 10>, 2 >
  > expected_type;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT(!(std::is_same<expected_type, result_type>::value));
}

//  ****************************************************************************
void HgTypeListTestSuite::TestVectorNoSub(void)
{
  typedef TypeList
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

#ifdef ENABLE_BITFIELD_SEQUENCE
//  ****************************************************************************
void HgTypeListTestSuite::TestVectorSubBitFields(void)
{
  typedef TypeList
  <
    size_t,
    std::vector<mixed_bits>
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT(!(std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void HgTypeListTestSuite::TestVectorSubNested(void)
{
  typedef TypeList
  <
    std::vector<Hg::Hg_nested_sub>
  > SUT;

  typedef TypeList
  <
    std::vector<Hg::Hg_nested_adjusted>
  > expected_type;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT(!(std::is_same<expected_type, result_type>::value));
}
#endif

//  ****************************************************************************
void HgTypeListTestSuite::TestVectorArrayNoSub(void)
{
  typedef TypeList
  <
    std::vector< std::array<uint32_t, 10> >
  > SUT;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT((std::is_same<SUT, result_type>::value));
}

//  ****************************************************************************
void HgTypeListTestSuite::TestVectorArrayBitSet(void)
{
  typedef TypeList
  <
    std::vector< std::array<mixed_bits, 10> >
  > SUT;

  typedef TypeList
  <
    std::vector< BitFieldArray<mixed_bits, 10> >
  > expected_type;

  typedef make_Hg_type_list<SUT>::type     result_type;

  TS_ASSERT(!(std::is_same<expected_type, result_type>::value));

}

#endif