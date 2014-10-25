//  @file Hg.h
//  
//  Contains the Hg (Mercury) Message template definition.
//  This format is used to access data fields in formatted message buffers.
//  
//  The MIT License(MIT)
//  
//  @copyright 2014 Paul M Watt
//  
//  TS_FAIL(message):                        Fail unconditionally
//  TS_ASSERT(expr):                         Verify (expr) is true
//  TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
//  TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
//  TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
//  TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
//  TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
//  TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
//  TS_ASSERT_PREDICATE(P, x):               Verify P(x)
//  TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
//  TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
//  TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
//  TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
//  TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
//  TS_WARN(message):                        Print message as a warning
//  TS_TRACE(message):                       Print message as an information message
// 
#ifndef TESTBITFIELDARRAY_H_INCLUDED
#define TESTBITFIELDARRAY_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <alchemy.h>
#include <Hg/storage_policy.h>
#include <Pb/bit_field/bit_field_array.h>

#include <test_helper.h>
#include <test_def.h>
#include <geometry_typelist.h>
#include <geometry_testdata.h>


namespace test
{
namespace data
{

const size_t k_color_count = 16;

uint32_t k_color_values[k_color_count] = 
{
  k_White,  k_Fuchsia,  k_Aqua,   k_Yellow,
  k_Purple, k_Teal,     k_Olive,  k_Silver,
  k_Blue,   k_Lime,     k_Red,    k_Gray,
  k_Navy,   k_Green,    k_Maroon, k_Black
};

} // namespace data
} // namespace test


//  ****************************************************************************
/// @brief TestBitFieldArray Test Suite class.
///
class TestBitFieldArray : public CxxTest::TestSuite
//  , HgTestHelper<Hg::array_t, Hg::BufferedStoragePolicy >
{
public:
  TestBitFieldArray() { }

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
  static const size_t k_count = test::data::k_color_count;

  //  Typedefs *****************************************************************
  typedef Hg::color4                    SUT_bit_field_type;

  typedef Hg::BitFieldArray<SUT_bit_field_type,
                            k_count>            SUT;

  //  **************************************************************************
  void Populate(SUT &sut)
  {
    using namespace test::data;

    sut[0]  = k_White  ;
    sut[1]  = k_Fuchsia;
    sut[2]  = k_Aqua   ;
    sut[3]  = k_Yellow ;
    sut[4]  = k_Purple ;
    sut[5]  = k_Teal   ;
    sut[6]  = k_Olive  ;
    sut[7]  = k_Silver ;
    sut[8]  = k_Blue   ;
    sut[9]  = k_Lime   ;
    sut[10] = k_Red    ;
    sut[11] = k_Gray   ;
    sut[12] = k_Navy   ;
    sut[13] = k_Green  ;
    sut[14] = k_Maroon ;
    sut[15] = k_Black  ;
  }

public:
  //  Test Cases ***************************************************************

  // Static Assertions
  void TestStatic(void);

  // Construction and assignment
  void TestDefaultConstructor(void);
  void TestCopyConstructor(void);
  void TestValueConstructor(void);
  void TestAssignment(void);
  void TestValueAssignment(void);

  // Status and Methods
  void TestEmpty_true(void);
  void TestEmpty_false(void);
  void TestSize(void);
  void TestSizeOf(void);

  // Accessors
  void TestData_const(void);
  void TestData(void);
  void TestAt_const(void);
  void TestAt(void);
  void TestOpSquare_const(void);
  void TestOpSquare(void);
  void TestFront_const(void);
  void TestFront(void);
  void TestFront_BitFields(void);
  void TestBack_const(void);
  void TestBack(void);
  void TestBack_BitFields(void);

  // Iterators
  void TestBegin(void);
  void TestEnd(void);
  void TestRBegin(void);
  void TestREnd(void);
};


//  ****************************************************************************
void TestBitFieldArray::TestStatic(void)
{

  TS_ASSERT((std::is_same<SUT::user_bit_field_type, SUT_bit_field_type>::value));
}

//  ****************************************************************************
void TestBitFieldArray::TestDefaultConstructor(void)
{
  const SUT::value_type k_control[k_count] = { };

  // SUT
  SUT sut;

  TS_ASSERT_SAME_DATA(k_control, sut.data(), sut.data_size());
}

//  ****************************************************************************
void TestBitFieldArray::TestCopyConstructor(void)
{
  SUT input;
  Populate(input);

  // SUT
  SUT sut(input);

  TS_ASSERT_SAME_DATA(input.data(), sut.data(), sut.data_size());
}

//  ****************************************************************************
void TestBitFieldArray::TestValueConstructor(void)
{
  using namespace test::data;

  SUT control;
  Populate(control);

  // SUT
  SUT sut(k_color_values);

  TS_ASSERT_SAME_DATA(control.data(), sut.data(), sut.data_size());
}

//  ****************************************************************************
void TestBitFieldArray::TestAssignment(void)
{
  SUT sut;
  SUT input;
  Populate(input);

  // SUT
  sut = input;

  TS_ASSERT_SAME_DATA(input.data(), sut.data(), sut.data_size());
}

//  ****************************************************************************
void TestBitFieldArray::TestValueAssignment(void)
{
  using namespace test::data;

  SUT sut;
  SUT control;
  Populate(control);

  // SUT
  sut = k_color_values;

  TS_ASSERT_SAME_DATA(control.data(), sut.data(), sut.data_size());
}

//  ****************************************************************************
void TestBitFieldArray::TestEmpty_true(void)
{
  // TODO: error C2265: 'abstract declarator' : reference to a zero-sized array is illegal, Add a static assertion to prevent this.
  //Hg::BitFieldArray<SUT_bit_field_type,0> sut;

  //// SUT
  //bool result = sut.empty();

  //TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestBitFieldArray::TestEmpty_false(void)
{
  SUT sut;

  // SUT
  bool result = sut.empty();

  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestBitFieldArray::TestSize(void)
{
  SUT sut;

  // SUT
  size_t result = sut.size();

  TS_ASSERT_EQUALS(k_count, result);
}

//  ****************************************************************************
void TestBitFieldArray::TestSizeOf(void)
{
  const size_t k_control = k_count * sizeof(SUT::value_type);

  SUT sut;

  // SUT
  size_t result = sut.data_size();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestBitFieldArray::TestData_const(void)
{
  using namespace test::data;

  const SUT sut(k_color_values);

  // SUT
  const SUT::value_type* pResult = sut.data();

  TS_ASSERT_SAME_DATA(pResult, k_color_values, sizeof(k_color_values));
}

//  ****************************************************************************
void TestBitFieldArray::TestData(void)
{
  using namespace test::data;

  SUT sut(k_color_values);

  // SUT
  SUT::value_type* pResult = sut.data();

  // Read a data array in through the data pointer.
  ::memcpy(pResult, k_color_values, sizeof(k_color_values));

  TS_ASSERT_SAME_DATA(sut.data(), k_color_values, sizeof(k_color_values));
}

//  ****************************************************************************
void TestBitFieldArray::TestAt_const(void)
{
  using namespace test::data;
  const SUT sut(k_color_values);

  // SUT
  TS_ASSERT_EQUALS(k_color_values[0], sut.at(0));
  TS_ASSERT_EQUALS(k_color_values[1], sut.at(1));
  TS_ASSERT_EQUALS(k_color_values[2], sut.at(2));
  TS_ASSERT_EQUALS(k_color_values[3], sut.at(3));
  TS_ASSERT_EQUALS(k_color_values[4], sut.at(4));
  TS_ASSERT_EQUALS(k_color_values[5], sut.at(5));
  TS_ASSERT_EQUALS(k_color_values[6], sut.at(6));
  TS_ASSERT_EQUALS(k_color_values[7], sut.at(7));
}

//  ****************************************************************************
void TestBitFieldArray::TestAt(void)
{
  using namespace test::data;
  SUT initial(k_color_values);

  // SUT
  SUT sut;
  sut.at(0) = initial.at(0);
  sut.at(1) = initial.at(1);
  sut.at(2) = initial.at(2);
  sut.at(3) = initial.at(3);
  sut.at(4) = initial.at(4);
  sut.at(5) = initial.at(5);
  sut.at(6) = initial.at(6);
  sut.at(7) = initial.at(7);

  TS_ASSERT_EQUALS(k_color_values[0], sut.at(0));
  TS_ASSERT_EQUALS(k_color_values[1], sut.at(1));
  TS_ASSERT_EQUALS(k_color_values[2], sut.at(2));
  TS_ASSERT_EQUALS(k_color_values[3], sut.at(3));
  TS_ASSERT_EQUALS(k_color_values[4], sut.at(4));
  TS_ASSERT_EQUALS(k_color_values[5], sut.at(5));
  TS_ASSERT_EQUALS(k_color_values[6], sut.at(6));
  TS_ASSERT_EQUALS(k_color_values[7], sut.at(7));
}

//  ****************************************************************************
void TestBitFieldArray::TestOpSquare_const(void)
{
  using namespace test::data;
  const SUT sut(k_color_values);

  // SUT
  TS_ASSERT_EQUALS(k_color_values[0], sut[0]);
  TS_ASSERT_EQUALS(k_color_values[1], sut[1]);
  TS_ASSERT_EQUALS(k_color_values[2], sut[2]);
  TS_ASSERT_EQUALS(k_color_values[3], sut[3]);
  TS_ASSERT_EQUALS(k_color_values[4], sut[4]);
  TS_ASSERT_EQUALS(k_color_values[5], sut[5]);
  TS_ASSERT_EQUALS(k_color_values[6], sut[6]);
  TS_ASSERT_EQUALS(k_color_values[7], sut[7]);
}

//  ****************************************************************************
void TestBitFieldArray::TestOpSquare(void)
{
  using namespace test::data;
  SUT initial(k_color_values);

  // SUT
  SUT sut;
  sut[0] = initial[0];
  sut[1] = initial[1];
  sut[2] = initial[2];
  sut[3] = initial[3];
  sut[4] = initial[4];
  sut[5] = initial[5];
  sut[6] = initial[6];
  sut[7] = initial[7];

  TS_ASSERT_EQUALS(k_color_values[0], sut[0]);
  TS_ASSERT_EQUALS(k_color_values[1], sut[1]);
  TS_ASSERT_EQUALS(k_color_values[2], sut[2]);
  TS_ASSERT_EQUALS(k_color_values[3], sut[3]);
  TS_ASSERT_EQUALS(k_color_values[4], sut[4]);
  TS_ASSERT_EQUALS(k_color_values[5], sut[5]);
  TS_ASSERT_EQUALS(k_color_values[6], sut[6]);
  TS_ASSERT_EQUALS(k_color_values[7], sut[7]);
}

//  ****************************************************************************
void TestBitFieldArray::TestFront_const(void)
{
  using namespace test::data;
  const SUT sut(k_color_values);

  // SUT
  uint32_t result = sut.front();
  TS_ASSERT_EQUALS(k_color_values[0], result);
}

//  ****************************************************************************
void TestBitFieldArray::TestFront(void)
{
  using namespace test::data;
  SUT sut;

  // SUT
  sut.front() = k_color_values[0];
  TS_ASSERT_EQUALS(k_color_values[0], sut.front());
}

//  ****************************************************************************
void TestBitFieldArray::TestFront_BitFields(void)
{
  using namespace test::data;
  SUT sut;

  uint32_t R = (k_color_values[0] & 0x000000FF);
  uint32_t G = (k_color_values[0] & 0x0000FF00) >> 8;
  uint32_t B = (k_color_values[0] & 0x00FF0000) >> 16;
  uint32_t A = (k_color_values[0] & 0xFF000000) >> 24;

  // SUT
  sut.front().A = A;
  sut.front().G = G;
  sut.front().R = R;
  sut.front().B = B;

  TS_ASSERT_EQUALS(k_color_values[0], sut.front());
}

//  ****************************************************************************
void TestBitFieldArray::TestBack_const(void)
{
  using namespace test::data;
  const SUT sut(k_color_values);

  // SUT
  uint32_t result = sut.back();
  TS_ASSERT_EQUALS(k_color_values[k_count-1], result);
}

//  ****************************************************************************
void TestBitFieldArray::TestBack(void)
{
  using namespace test::data;
  const size_t k_last = k_count - 1;   

  SUT sut;

  // SUT
  sut.back() = k_color_values[k_last];
  TS_ASSERT_EQUALS(k_color_values[k_last], sut.back());
}

//  ****************************************************************************
void TestBitFieldArray::TestBack_BitFields(void)
{
  using namespace test::data;
  const size_t k_last = k_count - 1;   

  SUT sut;

  uint32_t R = (k_color_values[k_last] & 0x000000FF);
  uint32_t G = (k_color_values[k_last] & 0x0000FF00) >> 8;
  uint32_t B = (k_color_values[k_last] & 0x00FF0000) >> 16;
  uint32_t A = (k_color_values[k_last] & 0xFF000000) >> 24;

  // SUT
  sut.front().A = A;
  sut.front().G = G;
  sut.front().R = R;
  sut.front().B = B;

  TS_ASSERT_EQUALS(k_color_values[k_last], sut.back());
}

//  ****************************************************************************
void TestBitFieldArray::TestBegin(void)
{
  using namespace test::data;
  SUT sut(k_color_values);

  // SUT
  SUT::iterator iter = sut.begin();

  TS_ASSERT_EQUALS(*iter, sut.front());
}

//  ****************************************************************************
void TestBitFieldArray::TestEnd(void)
{
  // Note: c.end() is equivalent to std::advance(c.begin(), c.size());
  //       Moving the iterator 'size' elements forward reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  using namespace test::data;
  SUT sut(k_color_values);

  SUT::iterator control_end = sut.begin();
  std::advance( control_end,  sut.size());

  // SUT
  SUT::iterator iter        = sut.end();

  TS_ASSERT_EQUALS(control_end, iter);
}

//  ****************************************************************************
void TestBitFieldArray::TestRBegin(void)
{
  // Note: *c.rbegin()is equivalent to c.back() 
  using namespace test::data;
  SUT sut(k_color_values);

  // SUT
  SUT::reverse_iterator iter = sut.rbegin();

  TS_ASSERT_EQUALS(*iter, sut.back());
}

//  ****************************************************************************
void TestBitFieldArray::TestREnd(void)
{
  // Note: c.rend() is equivalent to std::advance(c.rbegin(), c.size());
  //       Moving the iterator 'size' elements forward(reverse) reaches the end iterator.
  //       end() cannot be dereferenced because it does not point to a valid item.
  using namespace test::data;
  SUT sut(k_color_values);

  SUT::reverse_iterator control_rend  = sut.rbegin();  
  std::advance(control_rend, sut.size());

  // SUT
  SUT::reverse_iterator iter          = sut.rend();

  TS_ASSERT_EQUALS(control_rend, iter);
}

#endif
