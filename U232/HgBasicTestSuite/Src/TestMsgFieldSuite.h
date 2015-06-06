// @file TestDatumSuite.hpp
// 
// Verifies the Hg::Datum object.
//
// This test suite verifies the Datum object which provides data-field
// transparency for interaction with Mercury Packet definitions.
// 
// The message field object only needs a type array definition to construct
// a message field. The testing in this suite will focus on single Datum
// elements, and their proper processing of variable data.
// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
// 
//  Verify data with these TEST ASSERTIONS:
// 
// TS_FAIL(message):                        Fail unconditionally
// TS_ASSERT(expr):                         Verify (expr) is true
// TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
// TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
// TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
// TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
// TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
// TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
// TS_ASSERT_PREDICATE(P, x):               Verify P(x)
// TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
// TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
// TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
// TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
// TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
// TS_WARN(message):                        Print message as a warning
// TS_TRACE(message):                       Print message as an information message
// 
#ifndef TESTDATUMSUITE_H_INCLUDED
#define TESTDATUMSUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <test_def.h>


namespace Hg
{

//  ****************************************************************************
/// @brief          A type array that contains an entry for each of the 
///                 fundamental types.
///
typedef type_list
<
  int8_t,      
  uint8_t,     
  int16_t,     
  uint16_t,    
  int32_t,     
  uint32_t,   
  float,
  double
> fundamental_t;

} // namespace Hg

//  ****************************************************************************
/// @brief TestDatumSuite Test Suite class.
///
class TestDatumSuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::fundamental_t, Hg::BufferedStoragePolicy >
{
public:
  TestDatumSuite() { }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {
    
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {

  }

protected:
  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different data field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::Datum<0,Hg::fundamental_t>           field_int8_t;
  typedef Hg::Datum<1,Hg::fundamental_t>           field_uint8_t;
  typedef Hg::Datum<2,Hg::fundamental_t>           field_int16_t;
  typedef Hg::Datum<3,Hg::fundamental_t>           field_uint16_t;
  typedef Hg::Datum<4,Hg::fundamental_t>           field_int32_t;
  typedef Hg::Datum<5,Hg::fundamental_t>           field_uint32_t;
  typedef Hg::Datum<6,Hg::fundamental_t>           field_float_t;
  typedef Hg::Datum<7,Hg::fundamental_t>           field_double_t;

public:
  //  Test Cases ***************************************************************
  //  Test the basic function set with a u32 ***********************************
  void TestDtor();
  void TestCopyConstructor();
  void TestAssignment();
  void TestValueAssignment();

  // Comparison Operators
  void TestOpEquals();
  void TestOpEquals_false();
  void TestOpNotEquals();
  void TestOpNotEquals_false();
  void TestOpLessThan();
  void TestOpLessThan_false();
  void TestOpLessThanOrEqual();
  void TestOpLessThanOrEqual_false();
  void TestOpGreaterThan();
  void TestOpGreaterThan_false();
  void TestOpGreaterThanOrEqual();
  void TestOpGreaterThanOrEqual_false();

  // Status and Methods
  void TestClear();
  void TestClear_Empty();

  // Accessors
  void TestGet_Const();
  void TestGet();

  void TestSet();

};

//  ****************************************************************************
void TestDatumSuite::TestDtor()
{
  field_uint32_t sut;

  const uint32_t k_control = 0xBA5EC0DE;
  sut.set(k_control);

  // SUT
  // Call the destructor explicitly, 
  // and verify the release of the buffer.
  sut.~Datum();

  // The assigned code should still be present at the 
  // Data configured offset.
  uint32_t  result = sut.get();
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestDatumSuite::TestCopyConstructor()
{
  field_uint32_t    existing;
  const uint32_t    k_control = 0xBA5EBA11;

  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  field_uint32_t sut(existing);
  // The Shadow value should be present, 
  // and it is independent of the existing buffer.
  TS_ASSERT_EQUALS(k_control, sut.get());

  existing = k_control + 1;
  TS_ASSERT_DIFFERS(k_control+1, sut.get());
}

//  ****************************************************************************
void TestDatumSuite::TestAssignment()
{
  field_uint32_t    existing;

  const uint32_t k_control = 0xDEADBA11;
  existing.set(k_control);

  // Create an sut without a buffer.
  field_uint32_t sut;

  // SUT
  sut = existing;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestDatumSuite::TestValueAssignment()
{
  const uint32_t k_control = 0xB16BEAD5;
  // SUT
  field_uint32_t sut;
  sut = k_control;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestDatumSuite::TestOpEquals()
{
  const uint32_t k_control = 0xA110BA5E;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control;

  bool result = sut == rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestDatumSuite::TestOpEquals_false()
{
  const uint32_t k_control = 0xA110BA5E;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control + 1;

  bool result = sut == rhs;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestDatumSuite::TestOpNotEquals()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control + 1;

  bool result = sut != rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestDatumSuite::TestOpNotEquals_false()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control;

  bool result = sut != rhs;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestDatumSuite::TestOpLessThan()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = sut + 1;

  // SUT
  bool result = sut < rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestDatumSuite::TestOpLessThan_false()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = sut - 1;

  // SUT
  bool result = sut < rhs;
  TS_ASSERT(!result);
  TS_ASSERT(sut >= rhs)
}

//  ****************************************************************************
void TestDatumSuite::TestOpLessThanOrEqual()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs_equal;
  field_uint32_t    rhs_more;
  
  rhs_equal = sut;
  rhs_more  = sut + 1;

  // SUT
  bool result_eq    = sut <= rhs_equal;
  TS_ASSERT(result_eq);

  bool result_more  = sut <= rhs_more;
  TS_ASSERT(result_more);
}

//  ****************************************************************************
void TestDatumSuite::TestOpLessThanOrEqual_false()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control - 1;

  // SUT
  bool result  = sut <= rhs;
  TS_ASSERT(!result);
  TS_ASSERT(sut > rhs);
}

//  ****************************************************************************
void TestDatumSuite::TestOpGreaterThan()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control - 1;

  // SUT
  bool result = sut > rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestDatumSuite::TestOpGreaterThan_false()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control + 1;

  // SUT
  bool result = sut > rhs;
  TS_ASSERT(!result);
  TS_ASSERT(sut <= rhs)
}

//  ****************************************************************************
void TestDatumSuite::TestOpGreaterThanOrEqual()
{
  const uint32_t k_control = 0xFEEDC0DE;
  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs_equal;
  field_uint32_t    rhs_less;

  rhs_equal = sut;
  rhs_less  = sut - 1;

  // SUT
  bool result_eq    = sut >= rhs_equal;
  TS_ASSERT(result_eq);

  bool result_less  = sut >= rhs_less;
  TS_ASSERT(result_less);
}

//  ****************************************************************************
void TestDatumSuite::TestOpGreaterThanOrEqual_false()
{
  const uint32_t k_control = 0xFEEDC0DE;

  field_uint32_t sut;
  
  sut = k_control;

  field_uint32_t    rhs;
  rhs = k_control + 1;

  // SUT
  bool result = sut >= rhs;
  TS_ASSERT(!result);
  TS_ASSERT(sut < rhs);
}

//  ****************************************************************************
void TestDatumSuite::TestClear()
{
  const uint32_t k_control = 0x600DF00D;
  field_uint32_t sut;

  sut = k_control;

  // SUT: Zeroes the shadow data and the buffer.
  sut.clear();
  TS_ASSERT_EQUALS(uint32_t(), sut.get());
}

//  ****************************************************************************
void TestDatumSuite::TestClear_Empty()
{
  // Initialize without a buffer.
  const uint32_t k_control = 0xFA57F00D;
  field_uint32_t sut;
  sut = k_control;

  // SUT
  sut.clear();

  TS_ASSERT_EQUALS(uint32_t(), sut.get());
}

//  ****************************************************************************
void TestDatumSuite::TestGet_Const()
{
  // Verify Get() reads the value from the buffer,
  // the shadow copy should remain intact.
  const uint32_t k_control = 0x7E57C0DE;
  const uint32_t k_shadow  = 0xDEADC0DE;

  field_uint32_t sut;
  sut = k_control;

  // Create a const reference to call the Get() const.
  const field_uint32_t& const_sut = sut;

  // SUT
  uint32_t before = const_sut.get();
  sut = k_shadow;
  uint32_t after  = const_sut.get();
  uint32_t shadow = sut.get();

  TS_ASSERT_EQUALS (k_control, before);
  TS_ASSERT_EQUALS (k_shadow,  after);
  TS_ASSERT_EQUALS (k_shadow,  shadow);
}

//  ****************************************************************************
void TestDatumSuite::TestGet()
{
  // Verify Get() reads the value from the buffer and updates the shadow copy.
  const uint32_t k_control = 0x7E57C0DE;
  field_uint32_t sut;
  sut.set(k_control);

  // SUT
  uint32_t result = sut.get();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestDatumSuite::TestSet()
{
  // Verify Set() writes the value to the buffer and the shadow copy.
  const uint32_t k_initial = 0xBEEFBEEF;
  const uint32_t k_control = 0x7E57C0DE;
  field_uint32_t sut;

  // SUT
  sut.set(k_control);

  uint32_t result = sut.get();
  TS_ASSERT_EQUALS(k_control, result);
}

#endif
