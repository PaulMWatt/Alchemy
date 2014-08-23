/// @file TestBitSetFieldSuite.hpp
/// 
/// This test suite verifies the BitSetField object, which provides data-field
/// transparency for interaction of bit-field entries in Mercury Packet definitions.
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
#ifndef TESTBITSETFIELDSUITE_H_INCLUDED
#define TESTBITSETFIELDSUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <test_helper.h>
#include <Alchemy.h>
#include <Hg/proxy/bitlist_field_proxy.h>
#include <vector>

//  Test Types *****************************************************************
namespace Hg
{

HG_BEGIN_BIT_SET (uint8_t, byte_1x8)
  HG_BIT_FIELD   (0,   first, 8)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint8_t, byte_4x2)
  HG_BIT_FIELD   (0,   first,   2)
  HG_BIT_FIELD   (1,   second,  2)
  HG_BIT_FIELD   (2,   third,   2)
  HG_BIT_FIELD   (3,   fourth,  2)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint8_t, byte_8x1)
  HG_BIT_FIELD   (0,   first,   1)
  HG_BIT_FIELD   (1,   second,  1)
  HG_BIT_FIELD   (2,   third,   1)
  HG_BIT_FIELD   (3,   fourth,  1)
  HG_BIT_FIELD   (4,   fifth,   1)
  HG_BIT_FIELD   (5,   sixth,   1)
  HG_BIT_FIELD   (6,   seventh, 1)
  HG_BIT_FIELD   (7,   eighth,  1)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint32_t, mixed_set)
  HG_BIT_FIELD   (0,   first,   5)
  HG_BIT_FIELD   (1,   second,  4)
  HG_BIT_FIELD   (2,   third,   3)
  HG_BIT_FIELD   (3,   fourth,  2)
  HG_BIT_FIELD   (4,   fifth,   1)
  HG_BIT_FIELD   (5,   sixth,   16)
  HG_BIT_FIELD   (6,   seventh, 1)
HG_END_BIT_SET

//  ****************************************************************************
//  A type array that contains an entry for each of the fundamental types.
//
typedef TypeList
<
  byte_4x2,      
  byte_8x1,     
  mixed_set,
  uint32_t          // Extra bytes to allow for the offset read/write tests.
> bitset_format_t;

} // namespace Hg


//  ****************************************************************************
//  TestBitSetFieldSuite Test Suite class.
//
class TestBitSetFieldSuite : public CxxTest::TestSuite
  , HgTestHelper<Hg::bitset_format_t, Hg::BufferedStoragePolicy >
{
public:
  //  Typedefs *****************************************************************


  //  Default Constructor ******************************************************
  TestBitSetFieldSuite()     {  }

  //  Destructor *****************************************************************
  ~TestBitSetFieldSuite()    {  }

  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {

  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {
    m_sp_buffer.reset(); 
  }

protected:
    //  Constants ****************************************************************
  static const size_t k_offset = 0;

  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different data field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::detail::DataProxy < Hg::bitfield_trait, 
                                  0,
                                  Hg::bitset_format_t,
                                  0
                                >                           field_4x2;
  typedef field_4x2::value_type                             value_4x2;

  typedef Hg::detail::DataProxy < Hg::bitfield_trait,
                                  1,
                                  Hg::bitset_format_t,
                                  0
                                >                           field_8x1;
  typedef field_8x1::value_type                             value_8x1;

  typedef Hg::detail::DataProxy < Hg::bitfield_trait,
                                  2,
                                  Hg::bitset_format_t,
                                  0
                                >                           field_mixed;
  typedef field_mixed::value_type                           value_mixed;

public:
  // Test Cases ****************************************************************
  //  Test the basic function set with a u32 ***********************************
  void TestCopyConstructor(void);
  void TestAssignment(void);
  void TestValueAssignment(void);

  // Comparison Operators
  void TestOpEquals(void);
  void TestOpEquals_false(void);
  void TestOpNotEquals(void);
  void TestOpNotEquals_false(void);
  void TestOpLessThan(void);
  void TestOpLessThan_false(void);
  void TestOpLessThanOrEqual(void);
  void TestOpLessThanOrEqual_false(void);
  void TestOpGreaterThan(void);
  void TestOpGreaterThan_false(void);
  void TestOpGreaterThanOrEqual(void);
  void TestOpGreaterThanOrEqual_false(void);

  // Status and Methods
  void TestClear(void);
  void TestClear_Empty(void);

  // Accessors
  void TestGet_Const(void);
  void TestGet(void);
  void TestGet_NonZeroOffset(void);

  void TestSet(void);
  void TestSet_NonZeroOffset(void);

  //  Bitset Specific Tests ****************************************************
  //  Access the bit-fields
  void TestBitField_Ctor(void);
  void TestBitField_Assignment(void);
  void TestBitField_Assignment_Truncate(void);
  void TestBitField_Conversion(void);
  void TestBitField_Conversion_Empty(void);
  void TestBitField_Attach(void);
  
};

//  ****************************************************************************
void TestBitSetFieldSuite::TestCopyConstructor(void)
{
  field_mixed existing;

  const value_mixed k_control = 0xBA5EBA11;
  existing.set(k_control);

  // SUT
  // Create a copy of the existing data field.
  field_mixed sut(existing);
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestAssignment(void)
{
  field_mixed existing;

  const value_mixed k_control = 0xDEADBA11;
  existing.set(k_control);

  // Create an sut without a buffer.
  field_mixed sut;

  // SUT
  sut = existing;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestValueAssignment(void)
{
  const value_mixed k_control = 0xB16BEAD5;
  // SUT
  field_mixed sut;
  sut = k_control;

  // Verify the SUT was properly assigned the existing value.
  // The attached buffers are not modified, therefore sut should be empty.
  TS_ASSERT_EQUALS(k_control, sut.get());
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpEquals(void)
{
  const value_mixed k_control = 0xA110BA5E;

  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control;

  // SUT
  bool result = sut == rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpEquals_false(void)
{
  const value_mixed k_control = 0xA110BA5E;

  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control+1;

  // SUT
  bool result = sut == rhs;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpNotEquals(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control+1;

  // SUT
  bool result = sut != rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpNotEquals_false(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control;

  // SUT
  bool result = sut != rhs;
  TS_ASSERT(!result);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpLessThan(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control + 1;

  // SUT
  bool result = sut < rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpLessThan_false(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control-1;

  // SUT
  bool result = sut < rhs;
  TS_ASSERT(!result);
  TS_ASSERT(sut >= rhs)
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpLessThanOrEqual(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs_equal;
  field_mixed       rhs_more;
  rhs_equal = k_control;
  rhs_more  = k_control + 1;

  // SUT
  bool result_eq    = sut <= rhs_equal;
  TS_ASSERT(result_eq);

  bool result_more  = sut <= rhs_more;
  TS_ASSERT(result_more);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpLessThanOrEqual_false(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control - 1;

  // SUT
  bool result  = sut <= rhs;
  TS_ASSERT(!result);
  TS_ASSERT(sut > rhs);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpGreaterThan(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control-1;

  // SUT
  bool result = sut > rhs;
  TS_ASSERT(result);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpGreaterThan_false(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control-1;

  // SUT
  bool result = rhs > sut;
  TS_ASSERT(!result);
  TS_ASSERT(rhs <= sut)
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpGreaterThanOrEqual(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs_equal;
  field_mixed       rhs_less;
  rhs_equal = k_control;
  rhs_less = k_control - 1;

  // SUT
  bool result_eq = sut >= rhs_equal;
  TS_ASSERT(result_eq);

  bool result_less  = sut >= rhs_less;
  TS_ASSERT(result_less);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestOpGreaterThanOrEqual_false(void)
{
  const value_mixed k_control = 0xFEEDC0DE;
  field_mixed sut;

  sut = k_control;

  field_mixed       rhs;
  rhs = k_control + 1;

  // SUT
  bool result = sut >= rhs;
  TS_ASSERT(!result);
  TS_ASSERT(sut < rhs);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestClear(void)
{
  const value_mixed k_control = 0x600DF00D;
  field_mixed sut;
  sut = k_control;

  // SUT: Zeroes the shadow data and the buffer.
  sut.clear();

  TS_ASSERT_EQUALS(uint32_t(), sut.get());
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestClear_Empty(void)
{
  // Initialize without a buffer.
  const value_mixed k_control = 0xFA57F00D;
  field_mixed sut;
  sut = k_control;

  // SUT
  sut.clear();

  TS_ASSERT_EQUALS(uint32_t(), sut.get());
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestGet_Const(void)
{
  // Verify Get() reads the value from the buffer,
  // the shadow copy should remain intact.
  const value_mixed k_control = 0x7E57C0DE;
  const value_mixed k_shadow = 0xDEADC0DE;
  field_mixed sut;
  sut = k_control;

  // Create a const reference to call the get() const.
  const field_mixed& const_sut = sut;

  // SUT
  value_mixed before = const_sut.get();
  sut = k_shadow;
  value_mixed after  = const_sut.get();
  value_mixed shadow = sut.get();

  TS_ASSERT_EQUALS(k_control, before);
  TS_ASSERT_EQUALS(k_shadow,  after);
  TS_ASSERT_EQUALS(k_shadow,  shadow);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestGet(void)
{
  // Verify Get() reads the value from the buffer and updates the shadow copy.
  const value_mixed k_control = 0x7E57C0DE;
  field_mixed sut;
  sut = k_control;

  // SUT
  uint32_t result = sut.get();

  TS_ASSERT_EQUALS(k_control, result);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestGet_NonZeroOffset(void)
{
  // Verify that a message field with a non-zero offset,
  // reads values from the proper location in a buffer.

  // The type offset from a normal field_mixed by 3 bytes.
  const size_t k_test_offset = 3;
  typedef Hg::detail::DataProxy < Hg::bitfield_trait,
                                  2,
                                  Hg::bitset_format_t,
                                  k_test_offset>                offset_mixed_t;
  
  // Verify Get() reads the value from the buffer and updates the shadow copy.
  const uint32_t k_control = 0x7E57C0DE;
  offset_mixed_t sut;
  sut = k_control;

  // SUT
  uint32_t result = sut.get();

  TS_ASSERT_EQUALS(k_control, result);
  TS_ASSERT_EQUALS(offset_mixed_t::k_offset, field_mixed::k_offset
                                           + k_test_offset);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestSet(void)
{
  // Verify Set() writes the value to the buffer and the shadow copy.
  const uint32_t k_initial = 0xBEEFBEEF;
  const value_mixed k_control = 0x7E57C0DE;
  field_mixed       sut;

  // SUT
  sut.set(k_control);

  value_mixed shadow = sut.get();
  TS_ASSERT_EQUALS(k_control, shadow);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestSet_NonZeroOffset(void)
{
  // Verify that a message field with a non-zero offset,
  // writes values to the proper location in a buffer.

  // The type offset from a normal field_mixed by 3 bytes.
  const size_t k_test_offset = 3;
  typedef Hg::detail::DataProxy
                            < Hg::bitfield_trait,
                              2,
                              Hg::bitset_format_t,
                              k_test_offset>                offset_mixed_t;
  
  const value_mixed k_initial = 0xBEEFBEEF;
  const value_mixed k_control = 0x7E57C0DE;
  offset_mixed_t sut;
  TS_ASSERT_EQUALS(0, sut.get());

  // SUT
  sut.set(k_control);

  uint32_t shadow = sut.get();
  TS_ASSERT_EQUALS(k_control, shadow);
  TS_ASSERT_EQUALS(offset_mixed_t::k_offset, field_mixed::k_offset 
                                           + k_test_offset);
}

//  ****************************************************************************
//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Ctor(void)
{
  const value_mixed k_control = 0xAAAAAAAA; // This creates the bit pattern 1010
  field_mixed sut;
  sut = k_control;
  
  // If the bit-fields have been properly constructed, 
  // their internal buffers will be attached to the sut BitSet.
  // Therefore, they will properly extract the assigned value from the sut.
  value_mixed first_result    = (0xAAAAAAAA &  sut.first.k_mask) 
                                            >> sut.first.k_offset;
  value_mixed second_result   = (0xAAAAAAAA &  sut.second.k_mask) 
                                            >> sut.second.k_offset;
  value_mixed third_result    = (0xAAAAAAAA &  sut.third.k_mask) 
                                            >> sut.third.k_offset;
  value_mixed fourth_result   = (0xAAAAAAAA &  sut.fourth.k_mask) 
                                            >> sut.fourth.k_offset;
  value_mixed fifth_result    = (0xAAAAAAAA &  sut.fifth.k_mask) 
                                            >> sut.fifth.k_offset;
  value_mixed sixth_result    = (0xAAAAAAAA &  sut.sixth.k_mask) 
                                            >> sut.sixth.k_offset;
  value_mixed seventh_result  = (0xAAAAAAAA &  sut.seventh.k_mask) 
                                            >> sut.seventh.k_offset;

  TS_ASSERT_EQUALS(first_result,    sut.first);
  TS_ASSERT_EQUALS(second_result,   sut.second);
  TS_ASSERT_EQUALS(third_result,    sut.third);
  TS_ASSERT_EQUALS(fourth_result,   sut.fourth);
  TS_ASSERT_EQUALS(fifth_result,    sut.fifth);
  TS_ASSERT_EQUALS(sixth_result,    sut.sixth);
  TS_ASSERT_EQUALS(seventh_result,  sut.seventh);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Assignment(void)
{
  // Verify the assignment for each of the bitfields individually.

  const value_mixed k_control = 0xAAAAAAAA; // This creates the bit pattern 1010
  field_mixed sut;
  
  value_mixed k_first_value   = (0xAAAAAAAA &  sut.first.k_mask) 
                                            >> sut.first.k_offset;
  value_mixed k_second_value  = (0xAAAAAAAA &  sut.second.k_mask) 
                                            >> sut.second.k_offset;
  value_mixed k_third_value   = (0xAAAAAAAA &  sut.third.k_mask) 
                                            >> sut.third.k_offset;
  value_mixed k_fourth_value  = (0xAAAAAAAA &  sut.fourth.k_mask) 
                                            >> sut.fourth.k_offset;
  value_mixed k_fifth_value   = (0xAAAAAAAA &  sut.fifth.k_mask) 
                                            >> sut.fifth.k_offset;
  value_mixed k_sixth_value   = (0xAAAAAAAA &  sut.sixth.k_mask) 
                                            >> sut.sixth.k_offset;
  value_mixed k_seventh_value = (0xAAAAAAAA &  sut.seventh.k_mask) 
                                            >> sut.seventh.k_offset;

  // SUT: Assign each bitfield individually.
  sut.first   = k_first_value; 
  TS_ASSERT_EQUALS(k_first_value,   sut.first  );

  sut.second  = k_second_value;
  TS_ASSERT_EQUALS(k_second_value,  sut.second );

  sut.third   = k_third_value;
  TS_ASSERT_EQUALS(k_third_value,   sut.third  );

  sut.fourth  = k_fourth_value;
  TS_ASSERT_EQUALS(k_fourth_value,  sut.fourth );

  sut.fifth   = k_fifth_value;
  TS_ASSERT_EQUALS(k_fifth_value,   sut.fifth  );

  sut.sixth   = k_sixth_value;
  TS_ASSERT_EQUALS(k_sixth_value,   sut.sixth  );

  sut.seventh = k_seventh_value;
  TS_ASSERT_EQUALS(k_seventh_value, sut.seventh);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Assignment_Truncate(void)
{
  // Verify only the bits in the bitset data field are modified
  // when a bit-field is assigned a value that will be truncated.
  
  const value_mixed k_control = 0xAAAAAAAA; // This creates the bit pattern 1010
  field_mixed sut;
  
  value_mixed k_first_value   = (0xAAAAAAAA &  sut.first.k_mask) 
                                            >> sut.first.k_offset;
  value_mixed k_second_value  = (0xAAAAAAAA &  sut.second.k_mask) 
                                            >> sut.second.k_offset;
  value_mixed k_third_value   = (0xAAAAAAAA &  sut.third.k_mask) 
                                            >> sut.third.k_offset;
  value_mixed k_fourth_value  = (0xAAAAAAAA &  sut.fourth.k_mask) 
                                            >> sut.fourth.k_offset;
  value_mixed k_fifth_value   = (0xAAAAAAAA &  sut.fifth.k_mask) 
                                            >> sut.fifth.k_offset;
  value_mixed k_sixth_value   = (0xAAAAAAAA &  sut.sixth.k_mask) 
                                            >> sut.sixth.k_offset;
  value_mixed k_seventh_value = (0xAAAAAAAA &  sut.seventh.k_mask) 
                                            >> sut.seventh.k_offset;

  // Clear the SUT to 0 before each assignment 
  // to facilitate the verification of the SUT bitset value as well.

  // SUT: Assign each bitfield individually.
  sut = 0;
  sut.first   = k_control; 
  TS_ASSERT_EQUALS(k_first_value,     sut.first  );
  TS_ASSERT_EQUALS(k_first_value  <<  sut.first.k_offset,   value_mixed(sut));
  sut = 0;

  sut.second  = k_second_value;
  TS_ASSERT_EQUALS(k_second_value,    sut.second );
  TS_ASSERT_EQUALS(k_second_value <<  sut.second.k_offset,   value_mixed(sut));
  sut = 0;

  sut.third   = k_third_value;
  TS_ASSERT_EQUALS(k_third_value,     sut.third  );
  TS_ASSERT_EQUALS(k_third_value  <<  sut.third.k_offset,   value_mixed(sut));
  sut = 0;

  sut.fourth  = k_fourth_value;
  TS_ASSERT_EQUALS(k_fourth_value,    sut.fourth );
  TS_ASSERT_EQUALS(k_fourth_value <<  sut.fourth.k_offset,   value_mixed(sut));
  sut = 0;

  sut.fifth   = k_fifth_value;
  TS_ASSERT_EQUALS(k_fifth_value,     sut.fifth  );
  TS_ASSERT_EQUALS(k_fifth_value  <<  sut.fifth.k_offset,   value_mixed(sut));
  sut = 0;

  sut.sixth   = k_sixth_value;
  TS_ASSERT_EQUALS(k_sixth_value,     sut.sixth  );
  TS_ASSERT_EQUALS(k_sixth_value  <<  sut.sixth.k_offset,   value_mixed(sut));
  sut = 0;

  sut.seventh = k_seventh_value;
  TS_ASSERT_EQUALS(k_seventh_value,   sut.seventh);
  TS_ASSERT_EQUALS(k_seventh_value << sut.seventh.k_offset,   value_mixed(sut));
  sut = 0;
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Conversion(void)
{
  const uint8_t k_control = 0xAA;
  uint8_t       sut_value = k_control;

  Hg::BitField<3,4,uint8_t> sut(sut_value);
  
  // SUT
  uint8_t result = sut;

  const uint8_t k_expected = (k_control & sut.k_mask) >> sut.k_offset;
  TS_ASSERT_EQUALS(result,    k_expected);
  TS_ASSERT_EQUALS(sut_value, k_control);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Conversion_Empty(void)
{
  // Verify 0 is returned when a buffer has not been attached to a bit-field.
  Hg::BitField<3,4,uint8_t> sut;

  // SUT
  uint8_t result = sut;

  TS_ASSERT_EQUALS(result, 0);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Attach(void)
{
  Hg::BitField<3,4,uint8_t> sut;

  const uint8_t k_control = 0xAA;
  uint8_t       sut_value = k_control;

  // SUT
  sut.attach(&sut_value);

  uint8_t result = sut;
  const uint8_t k_expected = (k_control & sut.k_mask) >> sut.k_offset;

  TS_ASSERT_EQUALS(result, k_expected);
}

#endif
