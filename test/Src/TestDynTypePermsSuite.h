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

// TODO: Working to resolve an issue where nested types in arrays and vectors need to be redefined with their internal format that contains data rather than the typelist definition.
//typedef world_tFormat<0> world_message_type;
typedef object_tFormat<0> world_message_type;

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
  //  Constants ******************************************************************

  // TODO: Define the correct size based on the test data when ready
  // With the current test structure, the SUT format uses 75 bytes.
  static const size_t k_sut_msg_size = 75;

  test::data::World m_world;
  test::data::World m_other_world;

  uint8_t         perms_msg[k_sut_msg_size];

  //uint8_t         bytes             [k_byte_size];
  //array_16_t      arrays            [k_array_size];
  //pt3d_t          pts               [k_pts_size];
  //uint32_vec_t    vectors           [k_vector_size];
  //vector_of_pts_t pathological      [k_path_size];


  uint8_t         other_perms_msg[k_sut_msg_size];

  //uint8_t         other_bytes       [k_byte_size];
  //array_16_t      other_arrays      [k_array_size];
  //pt3d_t          other_pts         [k_pts_size];
  //uint32_vec_t    other_vectors     [k_vector_size];
  //vector_of_pts_t other_pathological[k_path_size];


  //typedef std::array<char, 16>          array_16_t;
  //typedef std::vector<uint32_t>         uint32_vec_t;

  //uint8_t
  //array_16_t
  //pt3d_t
  //uint32_vec_t
  //vector_of_pts_t

  //byte_vec_t;
  //string_vec_t;
  //pt_vec_t;
  //vec_of_vec_t;
  //pathological_t;

  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different msg field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::BufferedStoragePolicy                         storage_type;
  typedef Hg::world_message_type                            msg_type;
  typedef Hg::Message<msg_type>                             SUT;
  typedef Hg::Message<msg_type, Hg::NetByteOrder>           SUT_net_order;
  typedef Hg::Message<msg_type, Hg::BigEndian>              SUT_big_endian;
  typedef Hg::Message<msg_type, Hg::LittleEndian>           SUT_little_endian;

  typedef storage_type::data_type                           data_type;
  typedef storage_type::s_pointer                           s_pointer;

  // Helper Functions ************************************************************
  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateBaseValues(SUT_t& msg)
  {
    bool isValue = Hg::nested_value<triangle_tFormat<0> >::value;
    bool isType  = Hg::nested_value<triangle_t>::value;

    Hg::detail::DeduceTypeTrait<triangle_t>::type         i;
//    Hg::detail::DeduceTypeTrait<triangle_t>::value_type   j;
    Hg::detail::DeduceTypeTrait<triangle_tFormat<0> >::type         k;
//    Hg::detail::DeduceTypeTrait<triangle_tFormat<0> >::value_type   l;

    Hg::detail::field_data_t<triangle_tFormat<0> >::value_type m;
    Hg::detail::field_data_t<triangle_tFormat<0> >::value_type n;

    int x = 0;
//    to_sut(msg, m_world);
  }

  //  ****************************************************************************
  template <typename SUT_t>
  void PopulateOtherValues(SUT_t& msg)
  {
//    to_sut(msg, m_other_world);
  }

  //  ****************************************************************************
  //object_t to_object_t(const test::data::Object &object)
  //{
  //  object_t out;




  //  return out;
  //}

  ////  ****************************************************************************
  //instance_t to_instance_t(const test::data::Instance &instance)
  //{
  //
  //  return instance_t();
  //}

  //  ****************************************************************************
  template <typename SUT_t>
  void to_sut(SUT_t& msg, test::data::World &world)
  {
    //msg.width         = world.width;
    //msg.height        = world.height;

    //msg.camera.eye.X  = world.camera.eye.X;
    //msg.camera.eye.Y  = world.camera.eye.Y;
    //msg.camera.eye.Z  = world.camera.eye.Z;
    //msg.camera.at.X   = world.camera.at.X;
    //msg.camera.at.Y   = world.camera.at.Y;
    //msg.camera.at.Z   = world.camera.at.Z;
    //msg.camera.up.X   = world.camera.up.X;
    //msg.camera.up.Y   = world.camera.up.Y;
    //msg.camera.up.Z   = world.camera.up.Z;

    //msg.fov           = world.fov;
    //msg.ambient       = world.ambient;

    //msg.light.pt.X    = world.light.pt.X;
    //msg.light.pt.Y    = world.light.pt.Y;
    //msg.light.pt.Z    = world.light.pt.Z;
    //msg.light.color   = world.light.color;



    //msg.object_count  = world.object_count;

    //for (size_t index = 0; index < world.object_count; ++index)
    //{
    //  msg.objects.push_back(to_object_t(world.objects[index]));
    //}

    //msg.instance_count  = world.instance_count;

    //for (size_t index = 0; index < world.instance_count; ++index)
    //{
    //  msg.instances.push_back(to_instance_t(world.instances[index]));
    //}
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
  TS_ASSERT_SAME_DATA(perms_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestValueCtor(void)
{
  SUT                 rhs;
  PopulateBaseValues (rhs);
  // SUT
  SUT sut(rhs.data(), rhs.size());
  TS_ASSERT_SAME_DATA(perms_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::TestAssignmentOperator(void)
{
  SUT                rhs;
  PopulateBaseValues(rhs);

  // SUT
  SUT sut;
  sut = rhs;
  TS_ASSERT_SAME_DATA(perms_msg, sut.data(), sut.size());
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
  sut.size<true>();

  TS_ASSERT_EQUALS(Hg::SizeOf<SUT::format_type>::value, sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testis_host_order(void)
{
  // SUT: Host order is defined within the type itself.
  //      Look at the typedef for details
  SUT sut;
  TS_ASSERT(sut.is_host_order());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testis_host_order_false(void)
{
  // SUT: Net order is defined within the type itself. 
  //      Look at the typedef for details
  SUT_net_order sut;
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

  TS_ASSERT_SAME_DATA(perms_msg, rhs.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testdata(void)
{
  //SUT sut;
  //sut.size_8       = k_count_seq_8;
  //sut.size_16      = k_count_seq_16;
  //sut.size_32      = k_count_seq_32;
  //sut.size_64      = k_count_seq_64;

  //sut.word_0       = k_word_0;
  //sut.word_1       = k_word_1;
  //sut.word_2       = k_word_2;

  //// allocate and copy with the vector assign
  //uint8_t* seq8_first = &seq_8[0];
  //uint8_t* seq8_last  = seq8_first;
  //std::advance(seq8_last, k_count_seq_8);
  //sut.seq_8.assign(seq8_first, seq8_last);

  //// grow incrementally with push_back for each element.
  //sut.seq_16.push_back(seq_16[0]);
  //sut.seq_16.push_back(seq_16[1]);
  //sut.seq_16.push_back(seq_16[2]);
  //sut.seq_16.push_back(seq_16[3]);
  //sut.seq_16.push_back(seq_16[4]);
  //sut.seq_16.push_back(seq_16[5]);

  //// Allocate the memory up front.
  //sut.seq_32.resize(k_count_seq_32);
  //sut.seq_32[0] = seq_32[0];
  //sut.seq_32[1] = seq_32[1];
  //sut.seq_32[2] = seq_32[2];

  //sut.seq_64.resize(k_count_seq_64);
  //sut.seq_64[0] = seq_64[0];
  //sut.seq_64[1] = seq_64[1];
  //sut.seq_64[2] = seq_64[2];

  //TS_ASSERT_EQUALS(k_sut_msg_size, sut.size());
  //TS_ASSERT_SAME_DATA(perms_msg, sut.data(), sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_host(void)
{
  // Populate the expected results.
  SUT_net_order expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT_net_order sut;
  PopulateBaseValues(sut);

  SUT no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT result = to_host(sut);
  SUT no_op_result = to_host(no_op_sut);

  TS_ASSERT_SAME_DATA(other_perms_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_perms_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_network(void)
{
  // Populate the expected results.
  SUT expected;
  PopulateOtherValues(expected);

  // Perform two instances of this test.
  // 1) with data that requires a conversion.
  // 2) with data that does not require a conversion
  SUT sut;
  PopulateBaseValues(sut);

  SUT_net_order no_op_sut;
  PopulateOtherValues(no_op_sut);

  // SUT
  SUT_net_order result = to_network(sut);
  SUT_net_order no_op_result = to_network(no_op_sut);

  TS_ASSERT_SAME_DATA(other_perms_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_perms_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_big_endian(void)
{
  // Populate the expected results.
  SUT expected;
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

  TS_ASSERT_SAME_DATA(other_perms_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_perms_msg, no_op_result.data(), no_op_sut.size());
}

//  ****************************************************************************
void TestDynTypePermsSuite::Testto_little_endian(void)
{
  // Populate the expected results.
  SUT expected;
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

  TS_ASSERT_SAME_DATA(other_perms_msg, result.data(), sut.size());
  TS_ASSERT_SAME_DATA(other_perms_msg, no_op_result.data(), no_op_sut.size());
}


#endif
