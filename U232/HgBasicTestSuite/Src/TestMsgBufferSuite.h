// @file TestMsgBufferSuite.h
// 
// This test suite verifies the MsgBuffer Template. 
// This provides the abstraction container between the Mercury Message Packet
// and the selected buffer, format, and byte-order type of the message.
// 
// The individual data fields are not available at this level. 
// MsgBuffer is aware of the format of the data due to the format_type,
// type_list definition. 
// 
// The tests require stuffing buffers in the worker functions to match the
// expected results. These buffers are populated with the expected values at
// the offset locations defined in the encoded type_list.
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
#ifndef TESTMsgBufferSUITE_H_INCLUDED
#define TESTMsgBufferSUITE_H_INCLUDED
//  Includes *******************************************************************
#include <cxxtest/TestSuite.h>
#include <alchemy.h>

//  ****************************************************************************
/// A type array that contains 32-bit word aligned data structures.
///

ALCHEMY_STRUCT(aligned_int_t,
  ALCHEMY_DATUM   (int32_t,  l32),
  ALCHEMY_DATUM   (uint32_t, ul32),
  ALCHEMY_DATUM   (int16_t, s16),
  ALCHEMY_DATUM   (uint16_t, us16),
  ALCHEMY_DATUM   (int8_t, c8),
  ALCHEMY_DATUM   (uint8_t, uc8)
);

//  ****************************************************************************
/// A type array that is purposely maligned from a 32-bit word.
/// This type is important to verify the the memory read 
/// operations.
///
ALCHEMY_STRUCT(maligned_int_t,
  ALCHEMY_DATUM   (int8_t,   c8),
  ALCHEMY_DATUM   (int16_t,  s16),
  ALCHEMY_DATUM   (int32_t,  l32),
  ALCHEMY_DATUM   (uint16_t, us16),
  ALCHEMY_DATUM   (uint32_t, ul32),
  ALCHEMY_DATUM   (uint8_t, uc8)
);

// Constants used for endian or testing.
const int8_t    k_signed8_t           = int8_t(0xA7);
const int16_t   k_signed16_t          = int16_t(0xBAD1);
const int16_t   k_other_signed16_t    = int16_t(0xD1BA);
const int32_t   k_signed32_t          = 0xDEADC0DE;
const int32_t   k_other_signed32_t    = 0xDEC0ADDE;

const uint8_t   k_unsigned8_t         = 0x6E;
const uint16_t  k_unsigned16_t        = 0x5AFE;
const uint16_t  k_other_unsigned16_t  = 0xFE5A;
const uint32_t  k_unsigned32_t        = 0xFA54BA11;
const uint32_t  k_other_unsigned32_t  = 0x11BA54FA;

//  ****************************************************************************
/// @brief TestMsgBufferSuite Test Suite class.
///
class TestMsgBufferSuite : public CxxTest::TestSuite
{
public:

  TestMsgBufferSuite()         {  }


  // Fixture Management ********************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  {

  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  {
    m_spBuffer.reset();
  }

protected:
  //  Typedefs *****************************************************************
  //  These typedefs allow the creation of the different msg field types
  //  with a simplified syntax for readability in the unit-tests.
  typedef Hg::BufferedStoragePolicy                         storage_type;
  
  typedef storage_type::data_type                           data_type;
  typedef storage_type::s_pointer                           s_pointer;
  typedef Hg::maligned_int_t::format_type                   format_type;

  typedef Hg::MsgBuffer<storage_type>                       host_buffer;

  typedef Hg::MsgBuffer<storage_type>                       net_buffer;

  typedef data_type*                                        pointer;
  typedef const pointer                                     const_pointer;

  // Test Suite Data ***********************************************************
  s_pointer   m_spBuffer;

  // Creator Methods ***********************************************************
  template <typename T>
  s_pointer CreateMsgBufferT()
  {
    // Provide plenty of extra storage for the nested type,
    // this will allow for flexible offsets.
    const size_t k_len = Hg::size_of<format_type>::value ;
    return s_pointer(new(std::nothrow) data_type[k_len]);
  }

  //  ****************************************************************************
  size_t GetLength()
  {
    return Hg::size_of<format_type>::value;
  }

  //  ****************************************************************************
  s_pointer GetBuffer()
  {
    if (!m_spBuffer)
    {
      m_spBuffer = CreateMsgBufferT<host_buffer>();
    }
    
    return m_spBuffer;
  }

  //  ****************************************************************************
  void ClearBuffer()
  {
    m_spBuffer.reset();
  }

  //  ****************************************************************************
  template <typename T>
  void InitMsgField(T& sut)
  {
    sut.Attach(GetBuffer());
    sut.Flush();
  }

  //  ****************************************************************************
  template <typename T>
  T ReadFromOffset(s_pointer& spBuffer, size_t offset)
  {
    T  result;
    ::memcpy( &result,
              &(spBuffer.get()[offset]),
              sizeof(T));
    return result;
  }

  //  ****************************************************************************
  template <typename T>
  void WriteToOffset(s_pointer& spBuffer, size_t offset, const T& value)
  {
    ::memcpy( &(spBuffer.get()[offset]),
              &value,
              sizeof(T));
  }

  //  ****************************************************************************
  template <typename T>
  void PopulateBaseValues(T& data)
  {
    std::vector<data_type> buffer;
    buffer.resize(GetLength());

    pointer pBuffer = &buffer[0];


    //// The variable names are not accessible at this level.
    //// Populate the buffer as if this were valid code at this level:
    //// 
    //// data->c8    = k_signed8_t;
    //// data->s16   = k_signed16_t;
    //// data->l32   = k_signed32_t;
    //// data->us16  = k_unsigned16_t;
    //// data->ul32  = k_unsigned32_t;
    //// data->uc8   = k_unsigned8_t;

    ::memcpy( &(pBuffer[ Hg::offset_of<0,format_type>::value ]), 
              &k_signed8_t, 
              sizeof(int8_t));
    ::memcpy( &(pBuffer[ Hg::offset_of<1,format_type>::value ]), 
              &k_signed16_t, 
              sizeof(int16_t));
    ::memcpy( &(pBuffer[ Hg::offset_of<2,format_type>::value ]), 
              &k_signed32_t, 
              sizeof(int32_t));
    ::memcpy( &(pBuffer[ Hg::offset_of<3,format_type>::value ]), 
              &k_unsigned16_t, 
              sizeof(uint16_t));
    ::memcpy( &(pBuffer[ Hg::offset_of<4,format_type>::value ]), 
              &k_unsigned32_t, 
              sizeof(uint32_t));
    ::memcpy( &(pBuffer[ Hg::offset_of<5,format_type>::value ]), 
              &k_unsigned8_t, 
              sizeof(uint8_t));

    data.assign(pBuffer, buffer.size());
  }

  //  ****************************************************************************
  template <typename T>
  void PopulateOtherValues(T& data)
  {
    std::vector<data_type> buffer;
    buffer.resize(GetLength());

    pointer pBuffer = &buffer[0];

    //// The variable names are not accessible at this level.
    //// Populate the buffer as if this were valid code at this level:
    //// 
    //// data->c8    = k_signed8_t;
    //// data->s16   = k_other_signed16_t;
    //// data->l32   = k_other_signed32_t;
    //// data->us16  = k_other_unsigned16_t;
    //// data->ul32  = k_other_unsigned32_t;
    //// data->uc8   = k_unsigned8_t;

    ::memcpy( &pBuffer[ Hg::offset_of<0,format_type>::value ], 
              &k_signed8_t, 
              sizeof(int8_t));
    ::memcpy( &pBuffer[ Hg::offset_of<1,format_type>::value ], 
              &k_other_signed16_t, 
              sizeof(int16_t));
    ::memcpy( &pBuffer[ Hg::offset_of<2,format_type>::value ], 
              &k_other_signed32_t, 
              sizeof(int32_t));
    ::memcpy( &pBuffer[ Hg::offset_of<3,format_type>::value ], 
              &k_other_unsigned16_t, 
              sizeof(uint16_t));
    ::memcpy( &pBuffer[ Hg::offset_of<4,format_type>::value ], 
              &k_other_unsigned32_t, 
              sizeof(uint32_t));
    ::memcpy( &pBuffer[ Hg::offset_of<5,format_type>::value ], 
              &k_unsigned8_t, 
              sizeof(uint8_t));

    data.assign(pBuffer, buffer.size());
  }

public:
  // Test Cases ****************************************************************
  //  MsgBuffer Class Tests *************************************************
  void TestDefaultCtor();
  void TestCopyCtor();
  void TestDtor();
  void TestOpAssignment();
  void TestOpAssignment_ToSelf();
  void Testempty();
  void Testempty_NotEmpty();
  void TestSize();
  void Testbuffer_read();
  void Testbuffer_write();
  void Testget_data();
  void Testget_data_OOB_OffsetLTZero();
  void Testget_data_OOB_ExceedsSize();
  void Testget_data_NotValid();
  void TestSetData();
  void TestSetData_OOB_ExceedsSize();
  void TestSetData_NotValid();
  void TestClone();
  void TestClone_NotValid();
  void TestClone_BufferAllocFailed();

  //  Verify proper memory management (no memory leaks) ************************
  // TODO: Revisit, add conceptual tests.
};

//  ****************************************************************************
void TestMsgBufferSuite::TestDefaultCtor()
{
  // SUT
  host_buffer sut;
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestMsgBufferSuite::TestCopyCtor()
{
  host_buffer rhs;
  PopulateBaseValues(rhs);

  // SUT
  host_buffer sut(rhs);
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), (unsigned int)sut.size());
}

//  ****************************************************************************
void TestMsgBufferSuite::TestDtor()
{
  host_buffer sut;

  // SUT
  sut.~host_buffer();
  TS_ASSERT(sut.empty());
}

//  ****************************************************************************
void TestMsgBufferSuite::TestOpAssignment()
{
  host_buffer rhs;
  PopulateBaseValues(rhs);

  host_buffer sut;
  TS_ASSERT(sut.empty());

  // SUT
  sut = rhs;

  TS_ASSERT(!sut.empty());
  TS_ASSERT_SAME_DATA(sut.data(), rhs.data(), (unsigned int)sut.size());
}

//  ****************************************************************************
void TestMsgBufferSuite::TestOpAssignment_ToSelf()
{
  host_buffer sut;
  PopulateBaseValues(sut);

  // SUT
  sut = sut;

  // Verify there are no ill effects.
  TS_ASSERT(!sut.empty());
  host_buffer expected;
  PopulateBaseValues(expected);
  TS_ASSERT_SAME_DATA(sut.data(), expected.data(), (unsigned int)sut.size());
}


//  ****************************************************************************
void TestMsgBufferSuite::Testempty()
{
  host_buffer sut;

  // SUT
  bool result = sut.empty();

  TS_ASSERT_EQUALS(true, result);
}

//  ****************************************************************************
void TestMsgBufferSuite::Testempty_NotEmpty()
{
  host_buffer sut(10);

  // SUT
  bool result = sut.empty();

  TS_ASSERT_EQUALS(false, result);
}

//  ****************************************************************************
void TestMsgBufferSuite::TestSize()
{
  host_buffer sut;
  // TODO: Needs completely new tests

}

//  ****************************************************************************
void TestMsgBufferSuite::Testbuffer_read()
{
  // TODO: Needs a completely new test
  //host_buffer sut;
  //TS_ASSERT(!sut.empty());

  ////SUT
  //s_pointer spBuffer = sut.buffer();
  //TS_ASSERT_EQUALS(spBuffer, GetBuffer());
}

//  ****************************************************************************
void TestMsgBufferSuite::Testbuffer_write()
{
  // TODO: Needs a completely new test
  //host_buffer sut;
  //TS_ASSERT(sut.empty());

  //// SUT
  //sut.attach(GetBuffer(),GetLength());
  //TS_ASSERT(!sut.empty());    // Verify a buffer can be set.
}

//  ****************************************************************************
void TestMsgBufferSuite::Testget_data()
{
  host_buffer sut;
  PopulateBaseValues(sut);

  // SUT: Test every parameter
  int8_t c8 = 0;
  size_t size_read = sut.get_data(c8, Hg::offset_of<0,format_type>::value);

  TS_ASSERT_EQUALS(sizeof(c8), size_read);
  TS_ASSERT_EQUALS(k_signed8_t, c8);

  int16_t s16 = 0;
  size_read = sut.get_data(s16, Hg::offset_of<1, format_type>::value);

  TS_ASSERT_EQUALS(sizeof(s16), size_read);
  TS_ASSERT_EQUALS(k_signed16_t, s16);

  int32_t l32 = 0;
  size_read = sut.get_data(l32, Hg::offset_of<2, format_type>::value);

  TS_ASSERT_EQUALS(sizeof(l32), size_read);
  TS_ASSERT_EQUALS(k_signed32_t, l32);

  uint16_t us16 = 0;
  size_read = sut.get_data(us16, Hg::offset_of<3, format_type>::value);

  TS_ASSERT_EQUALS(sizeof(us16), size_read);
  TS_ASSERT_EQUALS(k_unsigned16_t, us16);

  uint32_t ul32 = 0;
  size_read = sut.get_data(ul32, Hg::offset_of<4, format_type>::value);

  TS_ASSERT_EQUALS(sizeof(ul32), size_read);
  TS_ASSERT_EQUALS(k_unsigned32_t, ul32);

  uint8_t uc8 = 0;
  size_read = sut.get_data(uc8, Hg::offset_of<5, format_type>::value);

  TS_ASSERT_EQUALS(sizeof(uc8), size_read);
  TS_ASSERT_EQUALS(k_unsigned8_t, uc8);
}

//  ****************************************************************************
void TestMsgBufferSuite::Testget_data_OOB_OffsetLTZero()
{
  host_buffer sut;
  PopulateBaseValues(sut);

  // SUT
  int32_t l32 = 0;
  size_t status = sut.get_data(l32, -1);

  TS_ASSERT_DIFFERS(sizeof(l32), status);
  TS_ASSERT_EQUALS(0, l32);
}

//  ****************************************************************************
void TestMsgBufferSuite::Testget_data_OOB_ExceedsSize()
{
  host_buffer sut;
  PopulateBaseValues(sut);

  // SUT
  int32_t l32 = 0;
  size_t status = sut.get_data(l32, sut.size());

  TS_ASSERT_DIFFERS(sizeof(l32), status);
  TS_ASSERT_EQUALS(0, l32);
}

//  ****************************************************************************
void TestMsgBufferSuite::Testget_data_NotValid()
{
  host_buffer sut;

  // SUT
  int32_t l32 = 0xAAAAAAAA;
  size_t status = sut.get_data(l32, Hg::offset_of<2,format_type>::value);

  TS_ASSERT_DIFFERS(sizeof(l32), status);
  TS_ASSERT_EQUALS(0xAAAAAAAA, l32);
}

//  ****************************************************************************
void TestMsgBufferSuite::TestSetData()
{
  host_buffer sut;
  PopulateBaseValues(sut);

  // SUT
  int8_t c8 = k_signed8_t;
  size_t status = sut.set_data(c8, Hg::offset_of<0,format_type>::value);
  TS_ASSERT_EQUALS(sizeof(c8), status);

  int16_t s16 = k_signed16_t;
  status = sut.set_data(s16, Hg::offset_of<1,format_type>::value);
  TS_ASSERT_EQUALS(sizeof(s16), status);

  int32_t l32 = k_signed32_t;
  status = sut.set_data(l32, Hg::offset_of<2,format_type>::value);
  TS_ASSERT_EQUALS(sizeof(l32), status);

  uint16_t us16 = k_unsigned16_t;
  status = sut.set_data(us16, Hg::offset_of<3,format_type>::value);
  TS_ASSERT_EQUALS(sizeof(us16), status);

  uint32_t ul32 = k_unsigned32_t;
  status = sut.set_data(ul32, Hg::offset_of<4,format_type>::value);
  TS_ASSERT_EQUALS(sizeof(ul32), status);

  uint8_t uc8 = k_unsigned8_t;
  status = sut.set_data(uc8, Hg::offset_of<5,format_type>::value);
  TS_ASSERT_EQUALS(sizeof(uc8), status);

  // Verify the buffer.
  host_buffer expected;
  PopulateBaseValues(expected);

  TS_ASSERT_SAME_DATA(expected.data(), sut.data(), (unsigned int)expected.size());
}

//  ****************************************************************************
void TestMsgBufferSuite::TestSetData_OOB_ExceedsSize()
{
  host_buffer sut;

  // SUT
  int32_t l32 = 0;
  size_t status = sut.set_data(l32, sut.size());

  TS_ASSERT_DIFFERS(sizeof(l32), status);
}

//  ****************************************************************************
void TestMsgBufferSuite::TestSetData_NotValid()
{
  host_buffer sut;

  // SUT
  int32_t l32 = k_signed32_t;
  size_t status = sut.set_data(l32, Hg::offset_of<2,format_type>::value);

  TS_ASSERT_DIFFERS(sizeof(l32), status);
}

//  ****************************************************************************
void TestMsgBufferSuite::TestClone()
{
  host_buffer rhs;
  PopulateBaseValues(rhs);

  // SUT
  host_buffer sut = rhs.clone();

  // Verify an exact copy of the original has been created.
  TS_ASSERT_SAME_DATA(rhs.data(), sut.data(), (unsigned int)sut.size());

  // Verify that the cloned version (SUT) is in a separate buffer.
  rhs.zero();
  TS_ASSERT_DIFFERS(*rhs.data(), *sut.data());
}

//  ****************************************************************************
void TestMsgBufferSuite::TestClone_NotValid()
{
  host_buffer rhs;

  // SUT
  host_buffer sut = rhs.clone();

  TS_ASSERT_EQUALS(true, sut.empty());
}

//  ****************************************************************************
void TestMsgBufferSuite::TestClone_BufferAllocFailed()
{
  // TODO: Create a FakeStoragePolicy that allows interaction with operations. Example, cause allocation to fail.
}


#endif
