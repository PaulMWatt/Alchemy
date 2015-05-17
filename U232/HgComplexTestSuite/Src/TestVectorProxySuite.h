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
#include <Hg/storage_policy.h>
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

  typedef Hg::Datum<0,Hg::vec_t>                        field_uint32_t;
  typedef Hg::detail::DataProxy < Hg::vector_trait, 
                                  1,
                                  Hg::vec_t
                                >                       vector_data;
  typedef Hg::Datum<2,Hg::vec_t>                        field_uint8_t;

  //  Utility Functions ********************************************************
  template< size_t  N >
  std::vector<uint8_t> make_vector(const uint8_t (&vals)[N])
  {
    std::vector<uint8_t> retVal;
    std::copy(vals, vals + N, std::back_inserter(retVal));
    return retVal;
  }

public:
  //  Test Cases ***************************************************************
  //  Test the basic function set with a u32 ***********************************
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
  void TestReserve();
  void TestCapacity();
  void TestSize();

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

  // Modifiers
  void TestErase();
  void TestErase_range();
  void TestPushBack();
  void TestPushBack_empty();
  void TestPopBack();
  void TestPopBack_empty();
  void TestResize_smaller();
  void TestResize_larger();
  void TestResize_default_smaller();
  void TestResize_default_larger();
  void TestSwap();
  void TestSwap_vector();

};

//  ****************************************************************************
void TestVectorProxySuite::TestCopyConstructor()
{
  vector_data    existing;
  const uint8_t vals[] = {0xB,0xA,5,0xE,0xB,0xA,1,1};
  const std::vector<uint8_t> k_control = make_vector(vals);

  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  vector_data sut(existing);
  // The Shadow value should be present.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestValueConstructor()
{
  const uint8_t vals[] = {0xB,0xA,5,0xE,0xB,0xA,1,1};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data    existing;
  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  vector_data sut(existing);
  // The Shadow value should be present.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestAssignment()
{
  const uint8_t vals[] = {0xD,0xE,0xA,0xD,0xB,0xA,1,1};
  const std::vector<uint8_t> k_control = make_vector(vals);

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
void TestVectorProxySuite::TestValueAssignment()
{
  const uint8_t vals[] = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  const std::vector<uint8_t> k_control = make_vector(vals);

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
void TestVectorProxySuite::TestOpEquals()
{
  const uint8_t vals[] = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);

  bool result = sut == k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpEquals_false()
{
  const uint8_t vals[] = {0xB,0x1,0x6,0xB,0xE,0xA,0xD,0x5};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);
  ++(sut[0]);

  vector_data::value_type vvv;

  bool result = sut == k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpNotEquals()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);
  ++(sut[0]);

  bool result = sut != k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpNotEquals_false()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);

  bool result = sut != k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpLessThan()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);
  --(sut[0]);

  bool result = sut < k_control;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestOpLessThan_false()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);

  bool result = sut < k_control;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestClear()
{
  const uint8_t vals[] = {0x6,0x0,0x0,0xD,0xF,0x0,0x0,0xd};
  const std::vector<uint8_t> k_control = make_vector(vals);

  // Clear will erase all elements allocaated in the vector.
  const std::vector<uint8_t> k_cleared;
  vector_data sut(k_control);

  // SUT: Zeroes the shadow data and the buffer.
  sut.clear();
  TS_ASSERT_EQUALS(k_cleared, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestReserve()
{
  const size_t k_control = 10;

  // SUT
  vector_data sut;
  sut.reserve(k_control);

  // Verify the new capacity is at least as large as the specified reserve mount. 
  TS_ASSERT_EQUALS(k_control, sut.capacity());
}

//  ****************************************************************************
void TestVectorProxySuite::TestCapacity()
{
  const uint8_t vals[] = {0x6,0x0,0x0,0xD,0xF,0x0,0x0,0xd};
  const std::vector<uint8_t> k_control = make_vector(vals);

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
void TestVectorProxySuite::TestSize()
{
  const size_t k_control = vector_data().size();

  // SUT
  vector_data sut;
  size_t result = sut.size();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestGet()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  const vector_data sut(k_control);

  std::vector<uint8_t> result = sut.get();

  TS_ASSERT_EQUALS (k_control, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestSet()
{
  // Verify Set() writes the value to the buffer and the shadow copy.
  const uint8_t vals[] = {0xB,0xE,0xE,0xF,0xB,0xE,0xE,0xF};
  const std::vector<uint8_t> k_initial = make_vector(vals);

  const uint8_t ctrl_vals[] = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);
  vector_data sut;

  // SUT
  sut.set(k_control);

  std::vector<uint8_t> result = sut.get();
  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestAt_const()
{
  const uint8_t vals[] = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);
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
void TestVectorProxySuite::TestAt()
{
  const uint8_t vals[] = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);
  
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
void TestVectorProxySuite::TestOpSquare_const()
{
  const uint8_t vals[] = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);
  
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
void TestVectorProxySuite::TestOpSquare()
{
  const uint8_t vals[] = {0x7,0xE,0x5,0x7,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

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
void TestVectorProxySuite::TestFront_const()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  const vector_data sut(k_control);

  // SUT
  uint8_t result = sut.front();
  TS_ASSERT_EQUALS(k_control[0], result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestFront()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut;
  sut.resize(k_control.size());

  // SUT
  sut.front() = k_control[0];
  TS_ASSERT_EQUALS(k_control[0], sut.front());
}

//  ****************************************************************************
void TestVectorProxySuite::TestBack_const()
{
  const size_t k_len = 8;   
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  const vector_data sut(k_control);

  // SUT
  uint8_t result = sut.back();
  TS_ASSERT_EQUALS(k_control[k_len-1], result);
}

//  ****************************************************************************
void TestVectorProxySuite::TestBack()
{
  const uint8_t k_control = 8;   
  vector_data sut;
  sut.resize(k_control);


  // SUT
  sut.back() = k_control;
  TS_ASSERT_EQUALS(k_control, sut.back());
}

//  ****************************************************************************
void TestVectorProxySuite::TestBegin()
{
  // Note: c.front() is equivalent to *c.begin()
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);

  // SUT
  vector_data::iterator iter = sut.begin();

  TS_ASSERT_EQUALS(*iter, sut.front());
}

//  ****************************************************************************
void TestVectorProxySuite::TestEnd()
{
  // Note: c.end() is equivalent to std::advance(c.begin(), c.size());
  //       Moving the iterator 'size' elements forward reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);

  vector_data::iterator control_end  = sut.begin();  
  std::advance(control_end, sut.size());

  // SUT
  vector_data::iterator iter         = sut.end();

  TS_ASSERT_EQUALS(control_end, iter);
}

//  ****************************************************************************
void TestVectorProxySuite::TestRBegin()
{
  // Note: *c.rbegin()is equivalent to c.back() 
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);

  // SUT
  vector_data::reverse_iterator iter = sut.rbegin();

  TS_ASSERT_EQUALS(*iter, sut.back());
}

//  ****************************************************************************
void TestVectorProxySuite::TestREnd()
{
  // Note: c.rend() is equivalent to std::advance(c.rbegin(), c.size());
  //       Moving the iterator 'size' elements forward(reverse) reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data sut(k_control);

  vector_data::reverse_iterator control_rend  = sut.rbegin();  
  std::advance(control_rend, sut.size());

  // SUT
  vector_data::reverse_iterator iter         = sut.rend();

  TS_ASSERT_EQUALS(control_rend, iter);
}

//  ****************************************************************************
void TestVectorProxySuite::TestErase()
{
  const uint8_t init_vals[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_initial = make_vector(init_vals);
  const uint8_t vals1[] = {0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_control_1 = make_vector(vals1);
  const uint8_t vals2[] = {0x2,0x3,0x4,0x5,0x6,0x7};
  const std::vector<uint8_t> k_control_2 = make_vector(vals2);
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
void TestVectorProxySuite::TestErase_range()
{
  const uint8_t vals[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_initial = make_vector(vals);
  const uint8_t ctrl_vals[] = {0x1,0x8};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);
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
void TestVectorProxySuite::TestPushBack()
{
  const uint8_t vals[] = {0x1,0x2,0x3,0x4,0x5,0x6};
  const std::vector<uint8_t> k_initial = make_vector(vals);

  const uint8_t              k_first   = 0x7;
  const uint8_t              k_second  = 0x8;
  const uint8_t ctrl_vals[] = {0x1,0x2,0x3,0x4,0x5,0x6,k_first,k_second};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);

  vector_data   sut(k_initial);

  // SUT: Add more elements to the end of the vector.
  sut.push_back(k_first);
  sut.push_back(k_second);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestPushBack_empty()
{
  const uint8_t              k_first   = 0x7;
  const uint8_t              k_second  = 0x8;
  const uint8_t vals[] = {k_first,k_second};
  const std::vector<uint8_t> k_control = make_vector(vals);

  vector_data   sut;

  // SUT: Populate the MT vector with new data at the end.
  sut.push_back(k_first);
  sut.push_back(k_second);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestPopBack()
{
  const uint8_t vals[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8};
  const std::vector<uint8_t> k_initial = make_vector(vals);

  const uint8_t ctrl_vals[] = {0x1,0x2,0x3,0x4,0x5,0x6};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);
  vector_data   sut(k_initial);

  // SUT
  sut.pop_back();
  sut.pop_back();

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestPopBack_empty()
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
void TestVectorProxySuite::TestResize_smaller()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_initial = make_vector(vals);

  const uint8_t ctrl_vals[] = {0xF,0xE,0xE,0xD,0xC,0x0};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);

  const size_t                  k_new_size = k_control.size();

  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestResize_larger()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_initial = make_vector(vals);

  const uint8_t ctrl_vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE,
                               0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);

  const size_t  k_new_size = k_control.size();

  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestResize_default_smaller()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_initial = make_vector(vals);

  const uint8_t ctrl_vals[] = {0xF,0xE,0xE};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);

  const size_t                  k_new_size = k_control.size();
  const vector_data::data_type  k_default_value = 100;
  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size,k_default_value);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestResize_default_larger()
{
  const uint8_t vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE};
  const std::vector<uint8_t> k_initial = make_vector(vals);

  const uint8_t ctrl_vals[] = {0xF,0xE,0xE,0xD,0xC,0x0,0xD,0xE,
                                          0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0};
  const std::vector<uint8_t> k_control = make_vector(ctrl_vals);

  const size_t  k_new_size = k_control.size();

  vector_data   sut(k_initial);

  // SUT
  sut.resize(k_new_size);

  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestVectorProxySuite::TestSwap()
{
  // Verifies Swap between two VectorProxy instances.
  const uint8_t l_vals[] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9};
  const std::vector<uint8_t> k_lhs = make_vector(l_vals);

  const uint8_t r_vals[] = {0xF,0xE,0xD,0xC,0xB,0xA};
  const std::vector<uint8_t> k_rhs = make_vector(r_vals);

  vector_data   sut_lhs(k_lhs);
  vector_data   sut_rhs(k_rhs);

  // SUT
  sut_lhs.swap(sut_rhs);

  TS_ASSERT_EQUALS(k_rhs, sut_lhs.get());
  TS_ASSERT_EQUALS(k_lhs, sut_rhs.get());
  TS_ASSERT_DIFFERS(sut_lhs.size(), sut_rhs.size());
}

//  ****************************************************************************
void TestVectorProxySuite::TestSwap_vector()
{
  const uint8_t l_vals[] = {0x0,0x1,0x2,0x3,0x4,0x5,0x6,0x7,0x8,0x9};
  const std::vector<uint8_t> k_lhs = make_vector(l_vals);

  const uint8_t r_vals[] = {0xF,0xE,0xD,0xC,0xB,0xA};
  const std::vector<uint8_t> k_rhs = make_vector(r_vals);

  vector_data           sut_lhs(k_lhs);
  std::vector<uint8_t>  sut_rhs(k_rhs);

  // SUT
  sut_lhs.swap(sut_rhs);

  TS_ASSERT_EQUALS(k_rhs, sut_lhs.get());
  TS_ASSERT_EQUALS(k_lhs, sut_rhs);
  TS_ASSERT_DIFFERS(sut_lhs.size(), sut_rhs.size());
}


#endif
