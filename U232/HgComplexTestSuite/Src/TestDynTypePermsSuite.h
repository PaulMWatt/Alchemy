//  @file TestDynTypePermsSuite.hpp
//  
//  This test suite verifies the different sub-types that can appear in
//  a dynamic field type (vector). Primarily tests for proper behavior 
//  of read, writes, and conversions.
//  
//  The MIT License(MIT)
//  @copyright 2014 Paul M Watt
//  
//   Verify data with these TEST ASSERTIONS:
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
#ifndef TEST_DYN_TYPE_PERMS_SUITE_H_INCLUDED
#define TEST_DYN_TYPE_PERMS_SUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <geometry_typelist.h>
#include <geometry_testdata.h>
#include <Hg.h>
#include <algorithm>

namespace Hg
{


//  Typedefs *******************************************************************

typedef world_t_HgFormat world_message_type;

} // namespace Hg



//  ****************************************************************************
//  TestDynTypePermsSuite Test Suite class.
//
class TestDynTypePermsSuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::world_t, Hg::BufferedStoragePolicy >
{
public:

  TestDynTypePermsSuite()
  { 
    test::data::to_buffer(test::data::k_world, perms_msg, false);
    test::data::to_buffer(test::data::k_other_world, other_perms_msg, true);
  }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual 
    void setUp()
  { 
    m_world       = test::data::k_world;
    m_other_world = test::data::k_other_world;
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  { }

protected:


  //  Typedefs *******************************************************************
  typedef std::array<char, 16>          array_16_t;
  typedef std::vector<uint32_t>         uint32_vec_t;


  //  Constants ******************************************************************

  // TODO: Define the correct size based on the test data when ready
  // With the current test structure, the SUT format uses 75 bytes.
  static const size_t k_sut_msg_size = 75;

  test::data::World m_world;
  test::data::World m_other_world;

  test::data::byte_vector     perms_msg;
  test::data::byte_vector     other_perms_msg;

  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different msg field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::BufferedStoragePolicy                               storage_type;
  typedef Hg::world_message_type                                  msg_type;
  typedef Hg::MessageT<msg_type>                                  SUT;
  typedef Hg::Message<Hg::MessageT<msg_type>, Hg::BigEndian>      SUT_big_endian;
  typedef Hg::Message<Hg::MessageT<msg_type>, Hg::LittleEndian>   SUT_little_endian;

  typedef storage_type::data_type                                 data_type;
  typedef storage_type::s_pointer                                 s_pointer;

  // Helper Functions ************************************************************
  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateBaseValues(SUT_t& msg)
  {
    to_sut(msg, m_world, false);
  }


  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
    to_sut(msg, m_other_world, true);
  }

  //  ****************************************************************************
  Hg::triangle_t_HgFormat to_triangle_t(const test::data::Triangle &triangle)
  {
    Hg::triangle_t_HgFormat out;

    out.pts[0] = triangle.pts[0];
    out.pts[1] = triangle.pts[1];
    out.pts[2] = triangle.pts[2];

    out.normal.start.X = triangle.normal.start.X;
    out.normal.start.Y = triangle.normal.start.Y;
    out.normal.start.Z = triangle.normal.start.Z;

    out.normal.magnitude.X = triangle.normal.magnitude.X;
    out.normal.magnitude.Y = triangle.normal.magnitude.Y;
    out.normal.magnitude.Z = triangle.normal.magnitude.Z;

    return out;
  }

  //  ****************************************************************************
  Hg::object_t_HgFormat to_object_t(const test::data::Object &object, bool is_network)
  {
    Hg::object_t_HgFormat out;

    out.count = object.count;

    uint32_t count = object.count;
    if (is_network)
    {
      count = Hg::EndianSwap(object.count);
    }

    for (uint32_t index = 0; index < count; ++index)
    {
      out.surfaces.push_back(to_triangle_t(object.surfaces[index]));
    }

    return out;
  }

  //  ****************************************************************************
  Hg::instance_t_HgFormat to_instance_t(const test::data::Instance &instance)
  {
    Hg::instance_t_HgFormat out;

    out.object_index    = instance.object_index;
    out.location.X      = instance.location.X;
    out.location.Y      = instance.location.Y;
    out.location.Z      = instance.location.Z;

    out.transform[0][0] = instance.transform[0][0];
    out.transform[0][1] = instance.transform[0][1];
    out.transform[0][2] = instance.transform[0][2];

    out.transform[1][0] = instance.transform[1][0];
    out.transform[1][1] = instance.transform[1][1];
    out.transform[1][2] = instance.transform[1][2];

    out.transform[2][0] = instance.transform[2][0];
    out.transform[2][1] = instance.transform[2][1];
    out.transform[2][2] = instance.transform[2][2];


    return out;
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void to_sut(SUT_t& msg, test::data::World &world, bool is_network)
  {
    using namespace test::data;

    msg.width         = world.width;
    msg.height        = world.height;
    
    msg.camera.eye.X  = world.camera.eye.X;
    msg.camera.eye.Y  = world.camera.eye.Y;
    msg.camera.eye.Z  = world.camera.eye.Z;
    msg.camera.at.X   = world.camera.at.X;
    msg.camera.at.Y   = world.camera.at.Y;
    msg.camera.at.Z   = world.camera.at.Z;
    msg.camera.up.X   = world.camera.up.X;
    msg.camera.up.Y   = world.camera.up.Y;
    msg.camera.up.Z   = world.camera.up.Z;

    msg.fov           = world.fov;
    msg.ambient       = world.ambient;

    msg.light.pt.X    = world.light.pt.X;
    msg.light.pt.Y    = world.light.pt.Y;
    msg.light.pt.Z    = world.light.pt.Z;
    msg.light.color   = world.light.color;

    msg.object_count  = world.object_count;

    for (size_t index = 0; index < world.object_count; ++index)
    {
      msg.objects.push_back(to_object_t(world.objects[index], is_network));
    }

    msg.instance_count  = world.instance_count;

    for (size_t index = 0; index < world.instance_count; ++index)
    {
      msg.instances.push_back(to_instance_t(world.instances[index]));
    }
  }


public:
  // Test Cases ****************************************************************

  // Dynamic Message Tests
  void TestDefaultCtor(void);
  void TestCopyCtor(void);
  void TestValueCtor(void);
  void TestAssignmentOperator(void);
  void Testempty(void);
  void Testempty_false(void);
  void TestSize(void);
  void Testis_host_order(void);
  void Testis_host_order_false(void);
  void TestAssign(void);
  void TestClear(void);
  void TestClone(void);
  void Testdata(void);

  //  Worker Functions *********************************************************
  void Testto_host(void);
  void Testto_network(void);
  void Testto_big_endian(void);
  void Testto_little_endian(void);
};

//  ****************************************************************************
void TestDynTypePermsSuite::TestDefaultCtor(void)
{
  // SUT
  SUT sut;

  // The msg buffer should not exist.
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestCopyCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);

  // SUT
  SUT sut(rhs);

  TS_ASSERT_SAME_DATA(&perms_msg[0], sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestValueCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);

  // SUT
  SUT sut(rhs.data(), rhs.size());
  TS_ASSERT_SAME_DATA(&perms_msg[0], sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestAssignmentOperator(void)
{
  SUT                rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs;
  TS_ASSERT_SAME_DATA(&perms_msg[0], sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testempty(void)
{
  // SUT
  SUT sut;
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testempty_false(void)
{
  // SUT
  SUT sut;
  sut.data();
  TS_ASSERT(!sut.empty());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestSize(void)
{
  // SUT
  SUT sut;

  TS_ASSERT_EQUALS(Hg::SizeOf<SUT::format_type>::value, sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testis_host_order(void)
{
  // SUT: Host order is defined within the type itself.
  //      Look at the typedef for details
  SUT::host_t sut;
  TS_ASSERT(sut.is_host_order());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testis_host_order_false(void)
{
  // SUT: Net order is defined within the type itself. 
  //      Look at the typedef for details
  SUT::net_t sut;
  TS_ASSERT(!sut.is_host_order());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestAssign(void)
{
  SUT expected;
  PopulateBaseValues(expected);

  // SUT
  SUT sut;
  sut.assign(expected.data(), expected.size());

  TS_ASSERT_EQUALS(expected.size(), sut.size());
  TS_ASSERT_SAME_DATA(expected.data(), sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestClear(void)
{
  SUT sut;
  sut.data();
  TS_ASSERT(!sut.empty());

  // SUT
  sut.clear();

  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestClone(void)
{
  SUT rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs.clone();

  TS_ASSERT_SAME_DATA(&perms_msg[0], rhs.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testdata(void)
{


}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_host(void)
{
  // Populate the expected results.
  SUT::net_t expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT::net_t sut;
  PopulateBaseValues(sut);

  SUT::host_t no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT result = to_host(sut);
  SUT no_op_result = to_host(no_op_sut);

  TS_ASSERT_SAME_DATA(&other_perms_msg[0], result.data(), result.size());
  TS_ASSERT_SAME_DATA(&other_perms_msg[0], no_op_result.data(), no_op_result.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_network(void)
{
  // Populate the expected results.
  SUT::host_t expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT::host_t sut;
  PopulateBaseValues(sut);

  SUT::net_t no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT::net_t result = to_network(sut);
  SUT::net_t no_op_result = to_network(no_op_sut);

  TS_ASSERT_SAME_DATA(&other_perms_msg[0], result.data(), sut.size());
  TS_ASSERT_SAME_DATA(&other_perms_msg[0], no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_big_endian(void)
{
  // Populate the expected results.
  SUT_big_endian expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_little_endian sut;
  PopulateBaseValues(sut);

  SUT_big_endian no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_big_endian result = to_big_endian(sut);
  SUT_big_endian no_op_result = to_big_endian(no_op_sut);

  TS_ASSERT_SAME_DATA(&other_perms_msg[0], result.data(), sut.size());
  TS_ASSERT_SAME_DATA(&other_perms_msg[0], no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_little_endian(void)
{
  // Populate the expected results.
  SUT_little_endian expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_big_endian sut;
  PopulateBaseValues(sut);

  SUT_little_endian no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_little_endian result        = to_little_endian(sut);
  SUT_little_endian no_op_result  = to_little_endian(no_op_sut);

  TS_ASSERT_SAME_DATA(&other_perms_msg[0], result.data(), sut.size());
  TS_ASSERT_SAME_DATA(&other_perms_msg[0], no_op_result.data(), no_op_sut.size());
}


#endif
