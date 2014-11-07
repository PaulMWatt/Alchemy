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
#include <alchemy.h>
#include <Hg/proxy/bitlist_field_proxy.h>
#include <vector>

//  Test Types *****************************************************************
namespace Hg
{

HG_BEGIN_BIT_SET (uint8_t, byte_1x8)
  HG_BIT_FIELD   (byte_1x8, 0,   first, 8)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint8_t, byte_4x2)
  HG_BIT_FIELD   (byte_4x2, 0,   first,   2)
  HG_BIT_FIELD   (byte_4x2, 1,   second,  2)
  HG_BIT_FIELD   (byte_4x2, 2,   third,   2)
  HG_BIT_FIELD   (byte_4x2, 3,   fourth,  2)
HG_END_BIT_SET

//struct byte_4x2; template <> struct ContainerSize<byte_4x2> : 
//std::integral_constant<size_t, sizeof(uint8_t)> { }; 
//
//namespace detail 
//{ 
//template <> 
//struct field_data_t<byte_4x2> 
//{ 
//  typedef uint8_t value_type; 
//}; 
//} 
//
//struct byte_4x2 
//  : public BasicBitList<uint8_t,byte_4x2> 
//{ 
//  typedef byte_4x2 this_type; 
//  typedef uint8_t value_type; 
//  typedef BasicBitList<uint8_t,byte_4x2> base_type; 
//  
//  byte_4x2() 
//    : base_type() 
//  { } 
//  
//  byte_4x2(const value_type &data_field) 
//    : base_type() 
//  { 
//    value(data_field); 
//  } 
//  
//  byte_4x2(value_type &data_field) 
//    : base_type(data_field) 
//  { } 
//  
//  byte_4x2& operator=(const byte_4x2 &rhs) 
//  { 
//    value(rhs.value()); 
//    return *this; 
//  } 
//  
//  byte_4x2& operator=(const value_type &data_field) 
//  { 
//    value(data_field); 
//    return *this; 
//  } 
//  
//  enum 
//  { 
//    k_offset_0 = 0 
//  }; 
//  
//  template <typename IndexT, typename BitT> 
//  BitT& GetField(const BitT &) 
//  { 
//    return GetFieldAddress(BitT()); 
//  }
//
//
//  // First field
//  typedef FieldIndex< 0, this_type,2> idx_0; 
//  struct first_tag 
//  { 
//    static ptrdiff_t offset() 
//    { 
//      return (size_t)&reinterpret_cast<const volatile char&>((((byte_4x2 *)0)->first)); 
//    } 
//  }; 
//  
//  typedef BitField < byte_4x2, first_tag, k_offset_0, 2, value_type > first_t; 
//  enum 
//  { 
//    k_offset_1 = k_offset_0 + 2 
//  }; 
//  
//  first_t first; 
//  
//  first_t& GetFieldAddress(const first_t&) 
//  { 
//    return first; 
//  }
//
//  // Second Field
//  typedef FieldIndex< 1, this_type,2> idx_1; struct second_tag { static ptrdiff_t offset() { return (size_t)&reinterpret_cast<const volatile char&>((((byte_4x2 *)0)->second)); } }; typedef BitField < byte_4x2, second_tag, k_offset_1, 2, value_type > second_t; enum { k_offset_2 = k_offset_1 + 2 }; second_t second; second_t& GetFieldAddress(const second_t&) { return second; }
//  typedef FieldIndex< 2, this_type,2> idx_2; struct third_tag { static ptrdiff_t offset() { return (size_t)&reinterpret_cast<const volatile char&>((((byte_4x2 *)0)->third)); } }; typedef BitField < byte_4x2, third_tag, k_offset_2, 2, value_type > third_t; enum { k_offset_3 = k_offset_2 + 2 }; third_t third; third_t& GetFieldAddress(const third_t&) { return third; }
//  typedef FieldIndex< 3, this_type,2> idx_3; struct fourth_tag { static ptrdiff_t offset() { return (size_t)&reinterpret_cast<const volatile char&>((((byte_4x2 *)0)->fourth)); } }; typedef BitField < byte_4x2, fourth_tag, k_offset_3, 2, value_type > fourth_t; enum { k_offset_4 = k_offset_3 + 2 }; fourth_t fourth; fourth_t& GetFieldAddress(const fourth_t&) { return fourth; }
//};




HG_BEGIN_BIT_SET (uint8_t, byte_8x1)
  HG_BIT_FIELD   (byte_8x1, 0,   first,   1)
  HG_BIT_FIELD   (byte_8x1, 1,   second,  1)
  HG_BIT_FIELD   (byte_8x1, 2,   third,   1)
  HG_BIT_FIELD   (byte_8x1, 3,   fourth,  1)
  HG_BIT_FIELD   (byte_8x1, 4,   fifth,   1)
  HG_BIT_FIELD   (byte_8x1, 5,   sixth,   1)
  HG_BIT_FIELD   (byte_8x1, 6,   seventh, 1)
  HG_BIT_FIELD   (byte_8x1, 7,   eighth,  1)
HG_END_BIT_SET

HG_BEGIN_BIT_SET (uint32_t, mixed_set)
//  HG_BIT_FIELD   (mixed_set, 0,   first,   5)
  // First field
  typedef FieldIndex< 0, this_type,5> idx_0; 
  struct first_tag 
  { 
    static ptrdiff_t offset() 
    { 
      return (size_t)&reinterpret_cast<const volatile char&>((((mixed_set *)0)->first)); 
    } 
  }; 
  
  typedef BitField < mixed_set, first_tag, k_offset_0, 1, value_type > first_t; 
  enum 
  { 
    k_offset_1 = k_offset_0 + 5 
  }; 
  
  first_t first; 
  
  first_t& GetFieldAddress(const first_t&) 
  { 
    return first; 
  }




  HG_BIT_FIELD   (mixed_set, 1,   second,  4)
  HG_BIT_FIELD   (mixed_set, 2,   third,   3)
  HG_BIT_FIELD   (mixed_set, 3,   fourth,  2)
  HG_BIT_FIELD   (mixed_set, 4,   fifth,   1)
  HG_BIT_FIELD   (mixed_set, 5,   sixth,   16)
  HG_BIT_FIELD   (mixed_set, 6,   seventh, 1)
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
                                  Hg::bitset_format_t
                                >                           field_4x2;
  typedef field_4x2::value_type                             value_4x2;

  typedef Hg::detail::DataProxy < Hg::bitfield_trait,
                                  1,
                                  Hg::bitset_format_t
                                >                           field_8x1;
  typedef field_8x1::value_type                             value_8x1;

  typedef Hg::detail::DataProxy < Hg::bitfield_trait,
                                  2,
                                  Hg::bitset_format_t
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
  void TestSet(void);

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

  TS_ASSERT_EQUALS(first_result,    (value_mixed)sut.first);
  TS_ASSERT_EQUALS(second_result,   (value_mixed)sut.second);
  TS_ASSERT_EQUALS(third_result,    (value_mixed)sut.third);
  TS_ASSERT_EQUALS(fourth_result,   (value_mixed)sut.fourth);
  TS_ASSERT_EQUALS(fifth_result,    (value_mixed)sut.fifth);
  TS_ASSERT_EQUALS(sixth_result,    (value_mixed)sut.sixth);
  TS_ASSERT_EQUALS(seventh_result,  (value_mixed)sut.seventh);
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
  TS_ASSERT_EQUALS(k_first_value,   (value_mixed)sut.first  );

  sut.second  = k_second_value;
  TS_ASSERT_EQUALS(k_second_value,  (value_mixed)sut.second );

  sut.third   = k_third_value;
  TS_ASSERT_EQUALS(k_third_value,   (value_mixed)sut.third  );

  sut.fourth  = k_fourth_value;
  TS_ASSERT_EQUALS(k_fourth_value,  (value_mixed)sut.fourth );

  sut.fifth   = k_fifth_value;
  TS_ASSERT_EQUALS(k_fifth_value,   (value_mixed)sut.fifth  );

  sut.sixth   = k_sixth_value;
  TS_ASSERT_EQUALS(k_sixth_value,   (value_mixed)sut.sixth  );

  sut.seventh = k_seventh_value;
  TS_ASSERT_EQUALS(k_seventh_value, (value_mixed)sut.seventh);
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
  TS_ASSERT_EQUALS(k_first_value,     (value_mixed)sut.first  );
  TS_ASSERT_EQUALS(k_first_value  <<  sut.first.k_offset,   value_mixed(sut));
  sut = 0;

  sut.second  = k_second_value;
  TS_ASSERT_EQUALS(k_second_value,    (value_mixed)sut.second );
  TS_ASSERT_EQUALS(k_second_value <<  sut.second.k_offset,   value_mixed(sut));
  sut = 0;

  sut.third   = k_third_value;
  TS_ASSERT_EQUALS(k_third_value,     (value_mixed)sut.third  );
  TS_ASSERT_EQUALS(k_third_value  <<  sut.third.k_offset,   value_mixed(sut));
  sut = 0;

  sut.fourth  = k_fourth_value;
  TS_ASSERT_EQUALS(k_fourth_value,    (value_mixed)sut.fourth );
  TS_ASSERT_EQUALS(k_fourth_value <<  sut.fourth.k_offset,   value_mixed(sut));
  sut = 0;

  sut.fifth   = k_fifth_value;
  TS_ASSERT_EQUALS(k_fifth_value,     (value_mixed)sut.fifth  );
  TS_ASSERT_EQUALS(k_fifth_value  <<  sut.fifth.k_offset,   value_mixed(sut));
  sut = 0;

  sut.sixth   = k_sixth_value;
  TS_ASSERT_EQUALS(k_sixth_value,     (value_mixed)sut.sixth  );
  TS_ASSERT_EQUALS(k_sixth_value  <<  sut.sixth.k_offset,   value_mixed(sut));
  sut = 0;

  sut.seventh = k_seventh_value;
  TS_ASSERT_EQUALS(k_seventh_value,   (value_mixed)sut.seventh);
  TS_ASSERT_EQUALS(k_seventh_value << sut.seventh.k_offset,   value_mixed(sut));
  sut = 0;
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Conversion(void)
{
  //const uint8_t k_control = 0xAA;
  //uint8_t       sut_value = k_control;

  //Hg::BitField<3,4,uint8_t> sut(sut_value);
  //
  //// SUT
  //uint8_t result = sut;

  //const uint8_t k_expected = (k_control & sut.k_mask) >> sut.k_offset;
  //TS_ASSERT_EQUALS(result,    k_expected);
  //TS_ASSERT_EQUALS(sut_value, k_control);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Conversion_Empty(void)
{
  //// Verify 0 is returned when a buffer has not been attached to a bit-field.
  //Hg::BitField<3,4,uint8_t> sut;

  //// SUT
  //uint8_t result = sut;

  //TS_ASSERT_EQUALS(result, 0);
}

//  ****************************************************************************
void TestBitSetFieldSuite::TestBitField_Attach(void)
{
  //Hg::BitField<3,4,uint8_t> sut;

  //const uint8_t k_control = 0xAA;
  //uint8_t       sut_value = k_control;

  //// SUT
  //sut.attach(&sut_value);

  //uint8_t result = sut;
  //const uint8_t k_expected = (k_control & sut.k_mask) >> sut.k_offset;

  //TS_ASSERT_EQUALS(result, k_expected);
}

#endif
