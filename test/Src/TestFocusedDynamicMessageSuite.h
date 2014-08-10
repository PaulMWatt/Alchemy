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

namespace test
{
//  Typedefs *****************************************************************
typedef std::vector<uint8_t>                              byte_vector;

} // namespace test

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
  //  Typedefs *****************************************************************
  typedef test::byte_vector             byte_vector;

  //  Constants ******************************************************************

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
//  The message definitions, utility functions and tests are grouped 
//  together for clarity and convenience. Each set of definitions is grouped
//  with the tests directly below their definition.
//  Also each set of tests definitions is defined within a namespace to avoid
//  collisions with similar definitions for the other tests.
//



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


} // namespace Hg


//  Nested-Fixed sub-fields ****************************************************
namespace test
{
namespace nested
{
namespace fixed
{
typedef Hg::Message<Hg::points_tFormat<0> >    MsgPoints;
typedef MsgPoints                              SUT;

const   size_t k_count = 3;

//  ************************************
void make_buffer(byte_vector &buffer)
{
  using namespace test::data;

  // allocate space for the size fields (2-bytes).
  buffer.resize(sizeof(uint16_t));

  uint16_t count = k_count;
  ::memcpy(&buffer[0], &count, sizeof(count));

  // to_buffer allocates its own space for the vector.
  to_buffer(k_eight_pts[0], buffer);
  to_buffer(k_eight_pts[1], buffer);
  to_buffer(k_eight_pts[2], buffer);
}

//  ************************************
void populate_msg(SUT &msg)
{
  using namespace test::data;

  msg.count = k_count;
  msg.pts.resize(msg.count);

  msg.pts[0].X   = k_eight_pts[0].X;
  msg.pts[0].Y   = k_eight_pts[0].Y;
  msg.pts[0].Z   = k_eight_pts[0].Z;
  
  msg.pts[1].X   = k_eight_pts[1].X;
  msg.pts[1].Y   = k_eight_pts[1].Y;
  msg.pts[1].Z   = k_eight_pts[1].Z;

  msg.pts[2].X   = k_eight_pts[2].X;
  msg.pts[2].Y   = k_eight_pts[2].Y;
  msg.pts[2].Z   = k_eight_pts[2].Z;
}


} // namespace fixed
} // namespace nested
} // namespace test

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_fixed_size(void)
{
  using namespace test::nested::fixed;

  // Place them in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the SUT with the test values.
  SUT sut;
  populate_msg(sut);

  // SUT: Serialize into a buffer.
  uint8_t const* pData = sut.data();

  TS_ASSERT_EQUALS(buffer.size(), sut.size());
  TS_ASSERT_SAME_DATA(&buffer[0], pData, buffer.size());
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_read_vector_with_nested_fixed_size(void)
{
  using namespace test::nested::fixed;
  using namespace test::data;

  // Place three points in a buffer.
  byte_vector buffer;
  make_buffer(buffer);

  // Populate the expected structure for comparison.
  MsgPoints expected;
  populate_msg(expected);

  // SUT
  SUT sut;
  sut.assign(&buffer[0], buffer.size());

  // Verify the results for all of the fields.
  TS_ASSERT_EQUALS(k_count, sut.count);
  TS_ASSERT_EQUALS(k_eight_pts[0].X, sut.pts[0].X);
  TS_ASSERT_EQUALS(k_eight_pts[0].Y, sut.pts[0].Y);
  TS_ASSERT_EQUALS(k_eight_pts[0].Z, sut.pts[0].Z);

  TS_ASSERT_EQUALS(k_eight_pts[1].X, sut.pts[1].X);
  TS_ASSERT_EQUALS(k_eight_pts[1].Y, sut.pts[1].Y);
  TS_ASSERT_EQUALS(k_eight_pts[1].Z, sut.pts[1].Z);

  TS_ASSERT_EQUALS(k_eight_pts[2].X, sut.pts[2].X);
  TS_ASSERT_EQUALS(k_eight_pts[2].Y, sut.pts[2].Y);
  TS_ASSERT_EQUALS(k_eight_pts[2].Z, sut.pts[2].Z);
}

//  ****************************************************************************
void TestFocusedDynamicMessageSuite::Test_write_vector_with_nested_dynamic_size(void)
{
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
void TestFocusedDynamicMessageSuite::Test_write_nested_at_correct_offset(void)
{

}


#endif
