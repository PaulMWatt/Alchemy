// @file TestArrayDataSuite.hpp
// 
// Verifies the Hg::ArrayData object.
//
// This test suite verifies the ArrayData object which provides data-field
// transparency for interaction with Mercury Packet definitions.
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
#ifndef TESTARRAYDATASUITE_H_INCLUDED
#define TESTARRAYDATASUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <Hg/storage_policy.h>
#include <Hg/proxy/array_proxy.h>

#include <test_helper.h>
#include <test_def.h>


namespace Hg
{

//  Constants ******************************************************************
static const size_t k_array_8_size = 8;

//  ****************************************************************************
/// A type array that contains a few variations of ArrayData entries.
///
typedef type_list
<
  uint32_t,
  std::array<uint8_t, k_array_8_size>,
  uint8_t
> array_t;

} // namespace Hg

//  ****************************************************************************
/// @brief TestArrayDataSuite Test Suite class.
///
class TestArrayDataSuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::array_t, Hg::BufferedStoragePolicy >
{
public:
  TestArrayDataSuite() { }

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
  typedef uint8_t                                       array_8_type[8];

  typedef Hg::Datum<0,Hg::array_t>                      field_uint32_t;
  typedef Hg::detail::DataProxy < Hg::array_trait, 
                                  1,
                                  Hg::array_t
                                >                       array_data_8;
  typedef Hg::Datum<2,Hg::array_t>                      field_uint8_t;

public:
  //  Test Cases ***************************************************************
  //  Test the basic function set with a u32 ***********************************
  void TestDtor();
  void TestCopyConstructor();
  void TestValueConstructor();
  void TestAssignment();
  void TestValueAssignment();

  // Comparison Operators
  void TestOpEquals();
  void TestOpEquals_false();
  void TestOpNotEquals();
  void TestOpNotEquals_false();
  void TestOpLessThan();
  void TestOpLessThan_false();

  // Status and Methods
  void TestClear();
  void TestSize();
  void Testsize_of();

  // Accessors
  void TestGet();
  void TestSet();

  void TestAt_const();
  void TestAt();
  void TestOpSquare_const();
  void TestOpSquare();
  void TestFront_const();
  void TestFront();
  void TestBack_const();
  void TestBack();

  // Iterators
  void TestBegin();
  void TestEnd();
  void TestRBegin();
  void TestREnd();
};

//  ****************************************************************************
void TestArrayDataSuite::TestDtor()
{
  const std::array<uint8_t, 8> k_control = {1,2,3,4,5,6,7,8};
//  const uint8_t k_control[8] = {1,2,3,4,5,6,7,8};

  array_data_8 sut;
  sut.set(k_control);

  // SUT
  // Call the destructor explicitly.
  sut.~DataProxy();

  // The assigned code should still be present in the datum.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestArrayDataSuite::TestCopyConstructor()
{
  array_data_8    existing;
  const std::array<uint8_t, 8> k_control = {0xB,0xA,5,0xE,0xB,0xA,1,1};

  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  array_data_8 sut(existing);
  // The Shadow value should be present.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestArrayDataSuite::TestValueConstructor()
{
  const std::array<uint8_t, 8> k_control = {0xB,0xA,5,0xE,0xB,0xA,1,1};
  array_data_8    existing;
  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  array_data_8 sut(existing);
  // The Shadow value should be present.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestArrayDataSuite::TestAssignment()
{
  const std::array<uint8_t, 8> k_control = {0xD,0xE,0xA,0xD,0xB,0xA,1,1};
  array_data_8    existing;
  existing.set(k_control);

  // SUT
  array_data_8 sut;

  sut = existing;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestArrayDataSuite::TestValueAssignment()
{
  const std::array<uint8_t, 8> k_control = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  array_data_8    existing;

  existing.set(k_control);

  // SUT
  array_data_8 sut;

  sut = existing;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpEquals()
{
  const std::array<uint8_t, 8> k_control = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  array_data_8 sut(k_control);

  bool result = sut == k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpEquals_false()
{
  const std::array<uint8_t, 8> k_control = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  array_data_8 sut(k_control);
  ++(sut[0]);

  bool result = sut == k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpNotEquals()
{
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);
  ++(sut[0]);

  bool result = sut != k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpNotEquals_false()
{
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);

  bool result = sut != k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpLessThan()
{
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);
  --(sut[0]);

  bool result = sut < k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpLessThan_false()
{
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);

  bool result = sut < k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestClear()
{
  const std::array<uint8_t, 8> k_control = {0x6,0x0,0x0,0xD,0xF,0x0,0x0,0xd};
  const std::array<uint8_t, 8> k_cleared = {0};
  array_data_8 sut(k_control);

  // SUT: Zeroes the shadow data and the buffer.
  sut.clear();
  TS_ASSERT_EQUALS(k_cleared, sut.get());
}


//  ****************************************************************************
void TestArrayDataSuite::TestSize()
{
  const size_t k_control = array_data_8().size();

  // SUT
  array_data_8 sut;
  size_t result = sut.size();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestArrayDataSuite::Testsize_of()
{
  const size_t k_control = Hg::size_of<array_data_8>::value;

  // SUT
  array_data_8 sut;
  size_t result = sut.size_of();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestGet()
{
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const array_data_8 sut(k_control);

  std::array<uint8_t, 8> result = sut.get();

  TS_ASSERT_EQUALS (k_control, result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestSet()
{
  // Verify Set() writes the value to the buffer and the shadow copy.
  const std::array<uint8_t, 8> k_initial = {0xB,0xE,0xE,0xF,0xB,0xE,0xE,0xF};
  const std::array<uint8_t, 8> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  array_data_8 sut;

  // SUT
  sut.set(k_control);

  std::array<uint8_t, 8> result = sut.get();
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestAt_const()
{
  const std::array<uint8_t, 8> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const array_data_8 sut(k_control);

  // SUT
  TS_ASSERT_EQUALS(k_control[0], sut.at(0));
  TS_ASSERT_EQUALS(k_control[1], sut.at(1));
  TS_ASSERT_EQUALS(k_control[2], sut.at(2));
  TS_ASSERT_EQUALS(k_control[3], sut.at(3));
  TS_ASSERT_EQUALS(k_control[4], sut.at(4));
  TS_ASSERT_EQUALS(k_control[5], sut.at(5));
  TS_ASSERT_EQUALS(k_control[6], sut.at(6));
  TS_ASSERT_EQUALS(k_control[7], sut.at(7));
}

//  ****************************************************************************
void TestArrayDataSuite::TestAt()
{
  const std::array<uint8_t, 8> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  array_data_8 initial(k_control);

  // SUT
  array_data_8 sut;
  sut.at(0) = initial.at(0);
  sut.at(1) = initial.at(1);
  sut.at(2) = initial.at(2);
  sut.at(3) = initial.at(3);
  sut.at(4) = initial.at(4);
  sut.at(5) = initial.at(5);
  sut.at(6) = initial.at(6);
  sut.at(7) = initial.at(7);

  TS_ASSERT_EQUALS(k_control[0], sut.at(0));
  TS_ASSERT_EQUALS(k_control[1], sut.at(1));
  TS_ASSERT_EQUALS(k_control[2], sut.at(2));
  TS_ASSERT_EQUALS(k_control[3], sut.at(3));
  TS_ASSERT_EQUALS(k_control[4], sut.at(4));
  TS_ASSERT_EQUALS(k_control[5], sut.at(5));
  TS_ASSERT_EQUALS(k_control[6], sut.at(6));
  TS_ASSERT_EQUALS(k_control[7], sut.at(7));
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpSquare_const()
{
  const std::array<uint8_t, 8> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const array_data_8 sut(k_control);

  // SUT
  TS_ASSERT_EQUALS(k_control[0], sut[0]);
  TS_ASSERT_EQUALS(k_control[1], sut[1]);
  TS_ASSERT_EQUALS(k_control[2], sut[2]);
  TS_ASSERT_EQUALS(k_control[3], sut[3]);
  TS_ASSERT_EQUALS(k_control[4], sut[4]);
  TS_ASSERT_EQUALS(k_control[5], sut[5]);
  TS_ASSERT_EQUALS(k_control[6], sut[6]);
  TS_ASSERT_EQUALS(k_control[7], sut[7]);
}

//  ****************************************************************************
void TestArrayDataSuite::TestOpSquare()
{
  const std::array<uint8_t, 8> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  array_data_8 initial(k_control);

  // SUT
  array_data_8 sut;
  sut[0] = initial[0];
  sut[1] = initial[1];
  sut[2] = initial[2];
  sut[3] = initial[3];
  sut[4] = initial[4];
  sut[5] = initial[5];
  sut[6] = initial[6];
  sut[7] = initial[7];

  TS_ASSERT_EQUALS(k_control[0], sut[0]);
  TS_ASSERT_EQUALS(k_control[1], sut[1]);
  TS_ASSERT_EQUALS(k_control[2], sut[2]);
  TS_ASSERT_EQUALS(k_control[3], sut[3]);
  TS_ASSERT_EQUALS(k_control[4], sut[4]);
  TS_ASSERT_EQUALS(k_control[5], sut[5]);
  TS_ASSERT_EQUALS(k_control[6], sut[6]);
  TS_ASSERT_EQUALS(k_control[7], sut[7]);
}

//  ****************************************************************************
void TestArrayDataSuite::TestFront_const()
{
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const array_data_8 sut(k_control);

  // SUT
  uint8_t result = sut.front();
  TS_ASSERT_EQUALS(k_control[0], result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestFront()
{
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut;

  // SUT
  sut.front() = k_control[0];
  TS_ASSERT_EQUALS(k_control[0], sut.front());
}

//  ****************************************************************************
void TestArrayDataSuite::TestBack_const()
{
  const size_t k_len = 8;   
  const std::array<uint8_t, k_len> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const array_data_8 sut(k_control);

  // SUT
  uint8_t result = sut.back();
  TS_ASSERT_EQUALS(k_control[k_len-1], result);
}

//  ****************************************************************************
void TestArrayDataSuite::TestBack()
{
  const uint8_t k_control = 8;   
  array_data_8 sut;

  // SUT
  sut.back() = k_control;
  TS_ASSERT_EQUALS(k_control, sut.back());
}

//  ****************************************************************************
void TestArrayDataSuite::TestBegin()
{
  // Note: c.front() is equivalent to *c.begin()
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);

  // SUT
  array_data_8::iterator iter = sut.begin();

  TS_ASSERT_EQUALS(*iter, sut.front());
}

//  ****************************************************************************
void TestArrayDataSuite::TestEnd()
{
  // Note: c.end() is equivalent to std::advance(c.begin(), c.size());
  //       Moving the iterator 'size' elements forward reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);

  array_data_8::iterator control_end  = sut.begin();  
  std::advance(control_end, sut.size());

  // SUT
  array_data_8::iterator iter         = sut.end();

  TS_ASSERT_EQUALS(control_end, iter);
}

//  ****************************************************************************
void TestArrayDataSuite::TestRBegin()
{
  // Note: *c.rbegin()is equivalent to c.back() 
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);

  // SUT
  array_data_8::reverse_iterator iter = sut.rbegin();

  TS_ASSERT_EQUALS(*iter, sut.back());
}

//  ****************************************************************************
void TestArrayDataSuite::TestREnd()
{
  // Note: c.rend() is equivalent to std::advance(c.rbegin(), c.size());
  //       Moving the iterator 'size' elements forward(reverse) reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  const std::array<uint8_t, 8> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  array_data_8 sut(k_control);

  array_data_8::reverse_iterator control_rend  = sut.rbegin();  
  std::advance(control_rend, sut.size());

  // SUT
  array_data_8::reverse_iterator iter         = sut.rend();

  TS_ASSERT_EQUALS(control_rend, iter);
}

#endif
