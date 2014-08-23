// @file TestVectorProxySuite.hpp
// 
// Verifies the Hg::VectorProxy object.
//
// This test suite verifies the VectorProxy object which provides a dynamic 
// buffer of memory for data fields.
// 
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
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
#ifndef TESTVECTORPROXYSUITE_H_INCLUDED
#define TESTVECTORPROXYSUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <storage_policy.h>
#include <Hg/proxy/vector_proxy.h>

#include <test_helper.h>
#include <test_def.h>


namespace Hg
{


//  ****************************************************************************
/// A type array that contains a few variations of Vector entries.
///
typedef TypeList
<
  uint32_t,
  std::vector<uint8_t>,
  uint8_t
> vec_t;

} // namespace Hg

//  ****************************************************************************
/// @brief TestVectorProxySuite Test Suite class.
///
class TestVectorProxySuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::vec_t, Hg::BufferedStoragePolicy >
{
public:
  TestVectorProxySuite() { }

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
  //  Constants ****************************************************************
  static const int    k_offset = 0;

  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different data field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef uint8_t                                       vector_value_type[8];

  typedef Hg::Datum<0,Hg::vec_t,k_offset>               field_uint32_t;
  typedef Hg::detail::DataProxy < Hg::vector_trait, 
                                  1,
                                  Hg::vec_t,
                                  k_offset
                                >                       vector_data;
  typedef Hg::Datum<2,Hg::vec_t,k_offset>               field_uint8_t;

public:
  //  Test Cases ***************************************************************
  //  Test the basic function set with a u32 ***********************************
  void TestDtor(void);
  void TestCopyConstructor(void);
  void TestValueConstructor(void);
  void TestAssignment(void);
  void TestValueAssignment(void);

  // Comparison Operators
  void TestOpEquals(void);
  void TestOpEquals_false(void);
  void TestOpNotEquals(void);
  void TestOpNotEquals_false(void);
  void TestOpLessThan(void);
  void TestOpLessThan_false(void);

  // Status and Methods
  void TestClear(void);
  void TestReserve(void);
  void TestCapacity(void);
  void TestSize(void);
  void TestSizeOf(void);

  // Accessors
  void TestGet(void);
  void TestSet(void);

  void TestAt_const(void);
  void TestAt(void);
  void TestOpSquare_const(void);
  void TestOpSquare(void);
  void TestFront_const(void);
  void TestFront(void);
  void TestBack_const(void);
  void TestBack(void);

  // Iterators
  void TestBegin(void);
  void TestEnd(void);
  void TestRBegin(void);
  void TestREnd(void);

  // Modifiers
  void TestErase(void);
  void TestErase_range(void);
  void TestPushBack(void);
  void TestPushBack_empty(void);
  void TestPopBack(void);
  void TestPopBack_empty(void);
  void TestResize_smaller(void);
  void TestResize_larger(void);
  void TestResize_default_smaller(void);
  void TestResize_default_larger(void);
  void TestSwap(void);
  void TestSwap_vector(void);

};

//  ****************************************************************************
void TestVectorProxySuite::TestDtor(void)
{
  const std::vector<uint8_t> k_control = {1,2,3,4,5,6,7,8};

  vector_data sut;
  sut.set(k_control);

  // The buffers should be equal.
  TS_ASSERT_EQUALS(k_control, sut.get());

  // SUT
  // Call the destructor explicitly.
  sut.~DataProxy();

  // The internal vectors fields are cleared, the sut should be empty.
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestVectorProxySuite::TestCopyConstructor(void)
{
  vector_data    existing;
  const std::vector<uint8_t> k_control = {0xB,0xA,5,0xE,0xB,0xA,1,1};

  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  vector_data sut(existing);
  // The Shadow value should be present.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestValueConstructor(void)
{
  const std::vector<uint8_t> k_control = {0xB,0xA,5,0xE,0xB,0xA,1,1};
  vector_data    existing;
  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  vector_data sut(existing);
  // The Shadow value should be present.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestAssignment(void)
{
  const std::vector<uint8_t> k_control = {0xD,0xE,0xA,0xD,0xB,0xA,1,1};
  vector_data    existing;
  existing.set(k_control);

  // SUT
  vector_data sut;

  sut = existing;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestValueAssignment(void)
{
  const std::vector<uint8_t> k_control = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  vector_data    existing;

  existing.set(k_control);

  // SUT
  vector_data sut;

  sut = existing;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpEquals(void)
{
  const std::vector<uint8_t> k_control = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  vector_data sut(k_control);

  bool result = sut == k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpEquals_false(void)
{
  const std::vector<uint8_t> k_control = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  vector_data sut(k_control);
  ++(sut[0]);

  vector_data::value_type vvv;

  bool result = sut == k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpNotEquals(void)
{
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);
  ++(sut[0]);

  bool result = sut != k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpNotEquals_false(void)
{
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);

  bool result = sut != k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpLessThan(void)
{
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);
  --(sut[0]);

  bool result = sut < k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpLessThan_false(void)
{
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);

  bool result = sut < k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestClear(void)
{
  const std::vector<uint8_t> k_control = {0x6,0x0,0x0,0xD,0xF,0x0,0x0,0xd};

  // Clear will erase all elements allocaated in the vector.
  const std::vector<uint8_t> k_cleared = {};
  vector_data sut(k_control);

  // SUT: Zeroes the shadow data and the buffer.
  sut.clear();
  TS_ASSERT_EQUALS(k_cleared, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestReserve(void)
{
  const size_t k_control = 10;

  // SUT
  vector_data sut;
  sut.reserve(k_control);

  // Verify the new capacity is at least as large as the specified reserve mount. 
  TS_ASSERT_EQUALS(k_control, sut.capacity());
}

//  ****************************************************************************
void TestVectorProxySuite::TestCapacity(void)
{
  const std::vector<uint8_t> k_control = {0x6,0x0,0x0,0xD,0xF,0x0,0x0,0xd};
  const size_t               k_count   = 3;

  // SUT
  vector_data sut(k_control);

  // Verify the initialized capacity matches the number
  // of elements assigned to the SUT.
  // Size and capacity should be the same.
  size_t result = sut.capacity();
  TS_ASSERT_EQUALS(k_control.size(), result);
  TS_ASSERT_EQUALS(result, sut.size());

  // Remove a few elements, and verify the capacity is unchanged,
  // and that the size has changed to match the new count.
  sut.resize(result - k_count);
  size_t resize_result = sut.capacity();
  TS_ASSERT_EQUALS(result, resize_result);
  TS_ASSERT_EQUALS(resize_result - k_count, sut.size());
}

//  ****************************************************************************
void TestVectorProxySuite::TestSize(void)
{
  const size_t k_control = vector_data().size();

  // SUT
  vector_data sut;
  size_t result = sut.size();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestSizeOf(void)
{
  const size_t k_control = Hg::SizeOf<vector_data>::value;

  // SUT
  vector_data sut;
  size_t result = sut.size_of();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestGet(void)
{
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const vector_data sut(k_control);

  std::vector<uint8_t> result = sut.get();

  TS_ASSERT_EQUALS (k_control, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestSet(void)
{
  // Verify Set() writes the value to the buffer and the shadow copy.
  const std::vector<uint8_t> k_initial = {0xB,0xE,0xE,0xF,0xB,0xE,0xE,0xF};
  const std::vector<uint8_t> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  vector_data sut;

  // SUT
  sut.set(k_control);

  std::vector<uint8_t> result = sut.get();
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestAt_const(void)
{
  const std::vector<uint8_t> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const vector_data sut(k_control);

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
void TestVectorProxySuite::TestAt(void)
{
  const std::vector<uint8_t> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  vector_data initial(k_control);

  // SUT
  vector_data sut;
  sut.resize(k_control.size());

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
void TestVectorProxySuite::TestOpSquare_const(void)
{
  const std::vector<uint8_t> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const vector_data sut(k_control);

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
void TestVectorProxySuite::TestOpSquare(void)
{
  const std::vector<uint8_t> k_control = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  vector_data initial(k_control);

  // SUT
  vector_data sut;
  sut.resize(k_control.size());

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
void TestVectorProxySuite::TestFront_const(void)
{
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const vector_data sut(k_control);

  // SUT
  uint8_t result = sut.front();
  TS_ASSERT_EQUALS(k_control[0], result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestFront(void)
{
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut;
  sut.resize(k_control.size());

  // SUT
  sut.front() = k_control[0];
  TS_ASSERT_EQUALS(k_control[0], sut.front());
}

//  ****************************************************************************
void TestVectorProxySuite::TestBack_const(void)
{
  const size_t k_len = 8;   
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const vector_data sut(k_control);

  // SUT
  uint8_t result = sut.back();
  TS_ASSERT_EQUALS(k_control[k_len-1], result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestBack(void)
{
  const uint8_t k_control = 8;   
  vector_data sut;
  sut.resize(k_control);


  // SUT
  sut.back() = k_control;
  TS_ASSERT_EQUALS(k_control, sut.back());
}

//  ****************************************************************************
void TestVectorProxySuite::TestBegin(void)
{
  // Note: c.front() is equivalent to *c.begin()
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);

  // SUT
  vector_data::iterator iter = sut.begin();

  TS_ASSERT_EQUALS(*iter, sut.front());
}

//  ****************************************************************************
void TestVectorProxySuite::TestEnd(void)
{
  // Note: c.end() is equivalent to std::advance(c.begin(), c.size());
  //       Moving the iterator 'size' elements forward reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);

  vector_data::iterator control_end  = sut.begin();  
  std::advance(control_end, sut.size());

  // SUT
  vector_data::iterator iter         = sut.end();

  TS_ASSERT_EQUALS(control_end, iter);
}

//  ****************************************************************************
void TestVectorProxySuite::TestRBegin(void)
{
  // Note: *c.rbegin()is equivalent to c.back() 
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);

  // SUT
  vector_data::reverse_iterator iter = sut.rbegin();

  TS_ASSERT_EQUALS(*iter, sut.back());
}

//  ****************************************************************************
void TestVectorProxySuite::TestREnd(void)
{
  // Note: c.rend() is equivalent to std::advance(c.rbegin(), c.size());
  //       Moving the iterator 'size' elements forward(reverse) reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  vector_data sut(k_control);

  vector_data::reverse_iterator control_rend  = sut.rbegin();  
  std::advance(control_rend, sut.size());

  // SUT
  vector_data::reverse_iterator iter         = sut.rend();

  TS_ASSERT_EQUALS(control_rend, iter);
}

//  ****************************************************************************
void TestVectorProxySuite::TestErase(void)
{
  const std::vector<uint8_t> k_initial   = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_control_1 = {0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_control_2 = {0x2,0x3,0x4,0x5,0x6,0x7};
  vector_data   sut(k_initial);

  // SUT: Remove the first and the last element.
  vector_data::iterator first   = sut.begin();
  vector_data::iterator result  = sut.erase(first);

  TS_ASSERT_EQUALS(k_control_1, sut.get());
  TS_ASSERT_EQUALS(result, sut.begin());

  // Removing the last element
  vector_data::iterator last = sut.begin();
  std::advance(last, sut.size()-1);
  result = sut.erase(last);

  TS_ASSERT_EQUALS(k_control_2, sut.get());
  TS_ASSERT_EQUALS(result, sut.end());
}

//  ****************************************************************************
void TestVectorProxySuite::TestErase_range(void)
{
  const std::vector<uint8_t> k_initial = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_control = {0x1,0x8};
  vector_data   sut(k_initial);

  vector_data::iterator first = ++sut.begin();
  vector_data::iterator last  = first;
  std::advance(last, 6);

  // SUT: Remove the range of items in the middle.
  vector_data::iterator result  = sut.erase(first, last);

  vector_data::iterator expected_iter = ++sut.begin();
  TS_ASSERT_EQUALS(k_control, sut.get());
  TS_ASSERT_EQUALS(expected_iter, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestPushBack(void)
{
  const std::vector<uint8_t> k_initial = {0x1,0x2,0x3,0x4,0x5,0x6};
  const uint8_t              k_first   = 0x7;
  const uint8_t              k_second  = 0x8;
  const std::vector<uint8_t> k_control = {0x1,0x2,0x3,0x4,0x5,0x6,k_first,k_second};
  vector_data   sut(k_initial);

  // SUT: Add more elements to the end of the vector.
  sut.push_back(k_first);
  sut.push_back(k_second);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestPushBack_empty(void)
{
  const uint8_t              k_first   = 0x7;
  const uint8_t              k_second  = 0x8;
  const std::vector<uint8_t> k_control = {k_first,k_second};

  vector_data   sut;

  // SUT: Populate the MT vector with new data at the end.
  sut.push_back(k_first);
  sut.push_back(k_second);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestPopBack(void)
{
  const std::vector<uint8_t> k_initial = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_control = {0x1,0x2,0x3,0x4,0x5,0x6};
  vector_data   sut(k_initial);

  // SUT
  sut.pop_back();
  sut.pop_back();

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestPopBack_empty(void)
{
  // SUT: Popback on an MT value should not change the vector.
  vector_data   sut;
  sut.pop_back();

  TS_ASSERT(sut.empty());

  // Reserve space, but do not add elements.
  // Call pop_back and verify the vector is unchanged.
  const size_t k_count = 25;
  sut.reserve(k_count);
  sut.pop_back();

  TS_ASSERT(sut.empty());
  TS_ASSERT_EQUALS(k_count, sut.capacity());
}

//  ****************************************************************************
void TestVectorProxySuite::TestResize_smaller(void)
{
  const std::vector<uint8_t>    k_initial = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t>    k_control = {0xF,0xE,0xE,0xD,0xC,0x0};
  const size_t                  k_new_size = k_control.size();

  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestResize_larger(void)
{
  const std::vector<uint8_t> k_initial = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE,
                                          0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
  const size_t  k_new_size = k_control.size();

  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestResize_default_smaller(void)
{
  const std::vector<uint8_t>    k_initial = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t>    k_control = {0xF,0xE,0xE};
  const size_t                  k_new_size = k_control.size();
  const vector_data::data_type  k_default_value = 100;
  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size,k_default_value);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestResize_default_larger(void)
{
  const std::vector<uint8_t> k_initial = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE,
                                          0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
  const size_t  k_new_size = k_control.size();

  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestSwap(void)
{
  // Verifies Swap between two VectorProxy instances.

  const std::vector<uint8_t> k_lhs = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9};
  const std::vector<uint8_t> k_rhs = {0xF,0xE,0xD,0xC,0xB,0xA};

  vector_data   sut_lhs(k_lhs);
  vector_data   sut_rhs(k_rhs);

  // SUT
  sut_lhs.swap(sut_rhs);

  TS_ASSERT_EQUALS(k_rhs, sut_lhs.get());
  TS_ASSERT_EQUALS(k_lhs, sut_rhs.get());
  TS_ASSERT_DIFFERS(sut_lhs.size(), sut_rhs.size());
}

//  ****************************************************************************
void TestVectorProxySuite::TestSwap_vector(void)
{
  const std::vector<uint8_t> k_lhs = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9};
  const std::vector<uint8_t> k_rhs = {0xF,0xE,0xD,0xC,0xB,0xA};

  vector_data           sut_lhs(k_lhs);
  std::vector<uint8_t>  sut_rhs(k_rhs);

  // SUT
  sut_lhs.swap(sut_rhs);

  TS_ASSERT_EQUALS(k_rhs, sut_lhs.get());
  TS_ASSERT_EQUALS(k_lhs, sut_rhs);
  TS_ASSERT_DIFFERS(sut_lhs.size(), sut_rhs.size());
}


#endif
