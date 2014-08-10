/// @file TestFocusedDynamicMessageSuite.hpp
/// 
/// The tests in this group first verify a basic definition.
/// The a second section contains tests with more focused scenarios
/// that have required extra attention during development.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
/// 
///  Verify data with these TEST ASSERTIONS:
/// 
/// TS_FAIL(message):                        Fail unconditionally
/// TS_ASSERT(expr):                         Verify (expr) is true
/// TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
/// TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
/// TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
/// TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
/// TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
/// TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
/// TS_ASSERT_PREDICATE(P, x):               Verify P(x)
/// TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
/// TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
/// TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
/// TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
/// TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
/// TS_WARN(message):                        Print message as a warning
/// TS_TRACE(message):                       Print message as an information message
/// 
#ifndef TEST_FOCUSED_DYNAMIC_MESSAGE_SUITE_H_INCLUDED
#define TEST_FOCUSED_DYNAMIC_MESSAGE_SUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <msgtest_typelist.h>
#include <Hg.h>
#include <algorithm>

#include <geometry_typelist.h>
#include <geometry_testdata.h>

//  ****************************************************************************
/// @brief TestFocusedDynamicMessageSuite Test Suite class.
///
class TestFocusedDynamicMessageSuite : public CxxTest::TestSuite
{
public:

  TestFocusedDynamicMessageSuite()
  { 
  }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  { }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  { }

protected:
  //  Constants ******************************************************************

  //  Typedefs *****************************************************************
  typedef std::vector<uint8_t>                              byte_vector;

  // Helper Functions ************************************************************
  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateBaseValues(SUT_t& msg)
  {
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
  }

public:
  // Test Cases ****************************************************************
  void Test_write_vector_with_nested_fixed_size(void);
  void Test_read_vector_with_nested_fixed_size(void);

  void Test_write_vector_with_nested_dynamic_size(void);
  void Test_read_vector_with_nested_dynamic_size(void);

  void Test_write_vector_with_nested_mixed_size(void);
  void Test_read_vector_with_nested_mixed_size(void);

  void Test_write_array_of_bitsets(void);
  void Test_read_array_of_bitsets(void);

  void Test_write_array_of_arrays(void);
  void Test_read_array_of_arrays(void);

  void Test_write_array_of_vectors(void);
  void Test_read_array_of_vectors(void);

  void Test_write_vector_of_bitsets(void);
  void Test_read_vector_of_bitsets(void);

  void Test_write_vector_of_arrays(void);
  void Test_read_vector_of_arrays(void);

  void Test_write_vector_of_vectors(void);
  void Test_read_vector_of_vectors(void);


  void Test_write_nested_at_correct_offset(void);

};


//  ****************************************************************************
namespace Hg {

typedef TypeList
<
  uint16_t,                       // size:          =  2
  std::vector<pt3d_t>             // size: (3 * 4)  = 12
> points_t;                       // total:         = 14

HG_BEGIN_FORMAT(points_t)
  HG_DATUM (uint16_t, count)
  HG_DYN_DATUM ((std::vector<pt3d_t>), pts, count)
HG_END_FORMAT

typedef Message<points_tFormat<0> >    MsgPoints;

} // namespace Hg

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_with_nested_fixed_size(void)
{
  using namespace test::data;
  typedef Hg::MsgPoints SUT;

  // Place three points in a buffer.
  byte_vector buffer(2);
  uint16_t count = 3;
  ::memcpy(&buffer[0], &count, sizeof(count));
  
  to_buffer(k_eight_pts[0], buffer);
  to_buffer(k_eight_pts[1], buffer);
  to_buffer(k_eight_pts[2], buffer);

  // SUT: Read this buffer into a vertices message.
  SUT sut;

  //sut.assign(&buffer[0], buffer.size());

  // Verify the results for all of the fields.
  //TS_ASSERT_EQUALS(count, sut.count);
  //TS_ASSERT_EQUALS(count, sut.value.size());
  //TS_ASSERT_EQUALS(k_points[0].X, sut.value[0].pt.X);
  //TS_ASSERT_EQUALS(k_points[0].Y, sut.value[0].pt.Y);
  //TS_ASSERT_EQUALS(k_points[0].Z, sut.value[0].pt.Z);
  //TS_ASSERT_EQUALS(k_colors[0],   sut.value[0].color);

  //TS_ASSERT_EQUALS(k_points[1].X, sut.value[1].pt.X);
  //TS_ASSERT_EQUALS(k_points[1].Y, sut.value[1].pt.Y);
  //TS_ASSERT_EQUALS(k_points[1].Z, sut.value[1].pt.Z);
  //TS_ASSERT_EQUALS(k_colors[1],   sut.value[1].color);

  //TS_ASSERT_EQUALS(k_points[2].X, sut.value[2].pt.X);
  //TS_ASSERT_EQUALS(k_points[2].Y, sut.value[2].pt.Y);
  //TS_ASSERT_EQUALS(k_points[2].Z, sut.value[2].pt.Z);
  //TS_ASSERT_EQUALS(k_colors[2],   sut.value[2].color);

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_dynamic_size(void)
{
  using namespace test::data;
  typedef Hg::MsgPoints SUT;

  // Place them in a buffer.
  byte_vector buffer(2);
  uint16_t count = 3;
  ::memcpy(&buffer[0], &count, sizeof(count));
  
  to_buffer(k_eight_pts[0], buffer);
  to_buffer(k_eight_pts[1], buffer);
  to_buffer(k_eight_pts[2], buffer);

  SUT sut;

  // Populate the SUT with the test values.
  sut.count = 3;
  sut.pts.resize(3);

  sut.pts[0].X   = k_eight_pts[0].X;
  sut.pts[0].Y   = k_eight_pts[0].Y;
  sut.pts[0].Z   = k_eight_pts[0].Z;
  
  sut.pts[1].X   = k_eight_pts[1].X;
  sut.pts[1].Y   = k_eight_pts[1].Y;
  sut.pts[1].Z   = k_eight_pts[1].Z;

  sut.pts[2].X   = k_eight_pts[2].X;
  sut.pts[2].Y   = k_eight_pts[2].Y;
  sut.pts[2].Z   = k_eight_pts[2].Z;

  // SUT: Serialize into a buffer.
  uint8_t const* pData = sut.data();

  TS_ASSERT_EQUALS(buffer.size(), sut.size());
  TS_ASSERT_SAME_DATA(&buffer[0], pData, buffer.size());
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_with_nested_dynamic_size(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_mixed_size(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_with_nested_mixed_size(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_array_of_bitsets(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_array_of_bitsets(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_array_of_arrays(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_array_of_arrays(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_array_of_vectors(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_array_of_vectors(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_of_bitsets(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_of_bitsets(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_of_arrays(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_of_arrays(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_of_vectors(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_of_vectors(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_fixed_size(void)
{

}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_nested_at_correct_offset(void)
{

}


#endif
