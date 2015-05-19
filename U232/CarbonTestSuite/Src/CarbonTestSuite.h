/// @file CarbonTestSuite.h
///
/// Verifies the Carbon interfaces derives from Hg interface definitions.
/// 
/// @author Paul  Watt
/// @date   2015.5.4: Paul  Watt    -- Initial release.
/// 
/// TODO: Update with an appropriate license copyright 2015
/// 
///  Verify data with these TEST ASSERTIONS:
/// 
///  TS_FAIL(message):                        Fail unconditionally
///  TS_ASSERT(expr):                         Verify (expr) is true
///  TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
///  TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
///  TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
///  TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
///  TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
///  TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
///  TS_ASSERT_PREDICATE(P, x):               Verify P(x)
///  TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
///  TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
///  TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
///  TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
///  TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
///  TS_WARN(message):                        Print message as a warning
///  TS_TRACE(message):                       Print message as an information message
/// 
//  **************************************************************************** 
#ifndef CarbonTestSuite_H_INCLUDED
#define CarbonTestSuite_H_INCLUDED

#if defined(_MSC_VER)

// Library import directive for Microsoft compiler.
#pragma comment(lib, "CarbonTestLibrary")

#endif

#include <iostream>
using namespace std;

#include <cxxtest/TestSuite.h>

#include <Carbon.h>
#include <C/carbonate.h>
#include <CarbonTestDefs.h>


//  ****************************************************************************
/// CarbonTestSuite Test Suite class.
///
class CarbonTestSuite : public CxxTest::TestSuite
{
public:

  CarbonTestSuite()
  {
    // TODO: Construct Test Suite Object
  }

  // Fixture Management *******************************************************
  // setUp will be called before each test case in order to setup common fixtures.
  virtual void setUp()
  { 
    m_pSut = 0;
  }
 
  // tearDown will be called after each test case to clean up common resources.
  virtual void tearDown()
  { 
    Hg_destroy(m_pSut);
  }

protected:

  // Typedefs *****************************************************************
  typedef Hg::exported_types        test_types;

  static const 
    Hg_type_t k_test_msg_type = k_vertex_t;
  static const 
    size_t k_msg_buffer_len = Hg::SizeOf<Hg::vertex_t>::value;

  // Test Suite Data **********************************************************
  Hg_msg_t    *m_pSut;

  // Creator Methods **********************************************************
  //  **************************************************************************
  Hg_msg_t* GetSUT(Hg_type_t type)
  {
    if (!m_pSut)
    {
      m_pSut = Hg_create(type);
    }

    return m_pSut;
  }

  //  **************************************************************************
  int GetInvalidType()
  {
    return k_invalid_type;
  }

  //  **************************************************************************
  void PopulateTestHostMsg(vertex_t* p_vertex)
  {
    p_vertex->pt.X = 0x01234567;
    p_vertex->pt.Y = 0xABCDEF00;
    p_vertex->pt.Z = 0x9A8B7C6D;

    p_vertex->color.R = 0xFF;
    p_vertex->color.G = 0xC0;
    p_vertex->color.B = 0x7F;
    p_vertex->color.A = 0x40;
  }

  //  **************************************************************************
  void PopulateTestNetMsg(vertex_t* p_vertex)
  {
    p_vertex->pt.X = 0x67452301;
    p_vertex->pt.Y = 0x00EFCDAB;
    p_vertex->pt.Z = 0x6D7C8B9A;

    p_vertex->color.R = 0x40;
    p_vertex->color.G = 0x7F;
    p_vertex->color.B = 0xC0;
    p_vertex->color.A = 0xFF;
  }

  //  **************************************************************************
  void PopulateHostOrder(unsigned char *pBuffer, size_t len)
  {
    uint32_t X    = 0x01234567;
    uint32_t Y    = 0xABCDEF00;
    uint32_t Z    = 0x9A8B7C6D;
    uint32_t RGBA = 0x407FC0FF;

    unsigned char* pCur = pBuffer;
    ::memcpy(pCur, &X, sizeof(X));
    pCur += sizeof(X);

    ::memcpy(pCur, &Y, sizeof(Y));
    pCur += sizeof(Y);

    ::memcpy(pCur, &Z, sizeof(Z));
    pCur += sizeof(Z);

    ::memcpy(pCur, &RGBA, sizeof(RGBA));
    pCur += sizeof(RGBA);
  }

  //  **************************************************************************
  void PopulateNetOrder(unsigned char *pBuffer, size_t len)
  {
    uint32_t X    = 0x67452301;
    uint32_t Y    = 0x00EFCDAB;
    uint32_t Z    = 0x6D7C8B9A;
    uint32_t RGBA = 0xFFC07F40;

    unsigned char* pCur = pBuffer;
    ::memcpy(pCur, &X, sizeof(X));
    pCur += sizeof(X);

    ::memcpy(pCur, &Y, sizeof(Y));
    pCur += sizeof(Y);

    ::memcpy(pCur, &Z, sizeof(Z));
    pCur += sizeof(Z);

    ::memcpy(pCur, &RGBA, sizeof(RGBA));
    pCur += sizeof(RGBA);
  }

public:
  // Test Cases ***************************************************************
  // Utility Functions used to implement the API.
  void Test_struct_to_msg_fundamentals();
  void Test_msg_to_struct_fundamentals();

  void Test_struct_to_msg_packed();
  void Test_msg_to_struct_packed();

  void Test_struct_to_msg_nested();
  void Test_msg_to_struct_nested();

  void Test_struct_to_msg_array();
  void Test_msg_to_struct_array();

  void Test_struct_to_msg_vector();
  void Test_msg_to_struct_vector();

  // Collection of functions to test in the Carbon API
  void Test_Hg_local_endianess();
  void Test_Hg_create();
  void Test_Hg_create_Invalid_type();

  void Test_Hg_clone();
  void Test_Hg_clone_Uninitialized();

  void Test_Hg_destroy();

  void Test_Hg_field_alloc();
  void Test_Hg_field_alloc_Uninitialized_msg();
  void Test_Hg_field_alloc_Uninitialized_field();
  void Test_Hg_field_alloc_zero_size();

  void Test_Hg_type();
  void Test_Hg_type_Uninitialized();

  void Test_Hg_size();
  void Test_Hg_size_Uninitialized();
  
  void Test_Hg_data_size();
  void Test_Hg_data_size_Uninitialized();

  void Test_Hg_to_network();
  void Test_Hg_to_network_Uninitialized();

  void Test_Hg_to_host();
  void Test_Hg_to_host_Uninitialized();

  void Test_Hg_to_big_end();
  void Test_Hg_to_big_end_Uninitialized();

  void Test_Hg_to_little_end();
  void Test_Hg_to_little_end_Uninitialized();

  void Test_Hg_pack();
  void Test_Hg_pack_invalid_msg();
  void Test_Hg_pack_invalid_buffer();
  void Test_Hg_pack_invalid_len();

  void Test_Hg_unpack();
  void Test_Hg_unpack_invalid_msg();
  void Test_Hg_unpack_invalid_buffer();
  void Test_Hg_unpack_invalid_len();

};

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_fundamentals()
{
  fundamentals_t  c;
  c.ch = 'A';
  c.s  = -12345;
  c.l  = 0xF005BA11;
  c.i  = -987654;
  c.uch= 'B';
  c.us = 6543;
  c.ul = 0x0BADFA11;
  c.ui = 123456789;

  Hg::fundamentals_t hg;

  // SUT;
  C::struct_to_msg(c, hg);
  TS_ASSERT_EQUALS(c.ch,  hg.ch);
  TS_ASSERT_EQUALS(c.s,   hg.s);
  TS_ASSERT_EQUALS(c.l,   hg.l);
  TS_ASSERT_EQUALS(c.i,   hg.i);
  TS_ASSERT_EQUALS(c.uch, hg.uch);
  TS_ASSERT_EQUALS(c.us,  hg.us);
  TS_ASSERT_EQUALS(c.ul,  hg.ul);
  TS_ASSERT_EQUALS(c.ui,  hg.ui);
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_fundamentals()
{
  Hg::fundamentals_t hg;
  hg.ch = 'A';
  hg.s  = -12345;
  hg.l  = 0xF005BA11;
  hg.i  = -987654;
  hg.uch= 'B';
  hg.us = 6543;
  hg.ul = 0x0BADFA11;
  hg.ui = 123456789;

  fundamentals_t  c;

  // SUT;
  C::msg_to_struct(hg, c);
  TS_ASSERT_EQUALS(c.ch,  hg.ch);
  TS_ASSERT_EQUALS(c.s,   hg.s);
  TS_ASSERT_EQUALS(c.l,   hg.l);
  TS_ASSERT_EQUALS(c.i,   hg.i);
  TS_ASSERT_EQUALS(c.uch, hg.uch);
  TS_ASSERT_EQUALS(c.us,  hg.us);
  TS_ASSERT_EQUALS(c.ul,  hg.ul);
  TS_ASSERT_EQUALS(c.ui,  hg.ui);
}

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_packed()
{
  color4 pixel;
  pixel.R = 3;
  pixel.G = 234;
  pixel.B = 109;
  pixel.A = 127;

  Hg::color4 hg_pixel;

  // SUT;
  C::struct_to_msg(pixel, hg_pixel);
  TS_ASSERT_EQUALS(pixel.R, hg_pixel.R);
  TS_ASSERT_EQUALS(pixel.G, hg_pixel.G);
  TS_ASSERT_EQUALS(pixel.B, hg_pixel.B);
  TS_ASSERT_EQUALS(pixel.A, hg_pixel.A);
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_packed()
{
  Hg::color4 hg_pixel;
  hg_pixel.R = 231;
  hg_pixel.G = 67;
  hg_pixel.B = 100;
  hg_pixel.A = 192;

  color4 pixel;

  // SUT;
  C::msg_to_struct(hg_pixel, pixel);
  TS_ASSERT_EQUALS(pixel.R, hg_pixel.R);
  TS_ASSERT_EQUALS(pixel.G, hg_pixel.G);
  TS_ASSERT_EQUALS(pixel.B, hg_pixel.B);
  TS_ASSERT_EQUALS(pixel.A, hg_pixel.A);
}

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_nested()
{
  vertex_t v;
  v.pt.X = 10;
  v.pt.Y = 5;
  v.pt.Z = -2;

  v.color.R = 3;
  v.color.G = 234;
  v.color.B = 109;
  v.color.A = 127;

  Hg::vertex_t hg_v;
  
  // SUT
  C::struct_to_msg(v, hg_v);

  TS_ASSERT_EQUALS(v.pt.X, hg_v.pt.X);
  TS_ASSERT_EQUALS(v.pt.Y, hg_v.pt.Y);
  TS_ASSERT_EQUALS(v.pt.Z, hg_v.pt.Z);

  TS_ASSERT_EQUALS(v.color.R, hg_v.color.R);
  TS_ASSERT_EQUALS(v.color.G, hg_v.color.G);
  TS_ASSERT_EQUALS(v.color.B, hg_v.color.B);
  TS_ASSERT_EQUALS(v.color.A, hg_v.color.A);
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_nested()
{
  Hg::vertex_t hg_v;
  hg_v.pt.X = 10;
  hg_v.pt.Y = 5;
  hg_v.pt.Z = -2;
  
  hg_v.color.R = 3;
  hg_v.color.G = 234;
  hg_v.color.B = 109;
  hg_v.color.A = 127;

  vertex_t v;
  
  // SUT
  C::msg_to_struct(hg_v, v);

  TS_ASSERT_EQUALS(v.pt.X, hg_v.pt.X);
  TS_ASSERT_EQUALS(v.pt.Y, hg_v.pt.Y);
  TS_ASSERT_EQUALS(v.pt.Z, hg_v.pt.Z);

  TS_ASSERT_EQUALS(v.color.R, hg_v.color.R);
  TS_ASSERT_EQUALS(v.color.G, hg_v.color.G);
  TS_ASSERT_EQUALS(v.color.B, hg_v.color.B);
  TS_ASSERT_EQUALS(v.color.A, hg_v.color.A);
}

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_array()
{
  color_map_t c;
  for (size_t index = 0; index < 16; ++index)
  {
    c.table[index].R = index * 2;
    c.table[index].G = index * 3;
    c.table[index].B = index * 4;
    c.table[index].A = index * 5;
  }

  Hg::color_map_t hg_c;

  // SUT
  C::struct_to_msg(c, hg_c);
  
  for (size_t index = 0; index < 16; ++index)
  {
    TS_ASSERT_EQUALS(c.table[index].R, hg_c.table[index].R);
    TS_ASSERT_EQUALS(c.table[index].G, hg_c.table[index].G);
    TS_ASSERT_EQUALS(c.table[index].B, hg_c.table[index].B);
    TS_ASSERT_EQUALS(c.table[index].A, hg_c.table[index].A);
  }
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_array()
{
  Hg::color_map_t hg_c;

  for (size_t index = 0; index < 16; ++index)
  {
    hg_c.table[index].R = index * 2;
    hg_c.table[index].G = index * 3;
    hg_c.table[index].B = index * 4;
    hg_c.table[index].A = index * 5;
  }

  color_map_t c;

  // SUT
  C::msg_to_struct(hg_c, c);
  
  for (size_t index = 0; index < 16; ++index)
  {
    TS_ASSERT_EQUALS(c.table[index].R, hg_c.table[index].R);
    TS_ASSERT_EQUALS(c.table[index].G, hg_c.table[index].G);
    TS_ASSERT_EQUALS(c.table[index].B, hg_c.table[index].B);
    TS_ASSERT_EQUALS(c.table[index].A, hg_c.table[index].A);
  }
}

//  ******************************************************************************
void CarbonTestSuite::Test_struct_to_msg_vector()
{
  object_t obj;

  Hg::object_t hg_obj;

  // SUT
  C::struct_to_msg(obj, hg_obj);
  
  //for (size_t index = 0; index < 16; ++index)
  //{
  //  TS_ASSERT_EQUALS(c.table[index].R, hg_c.table[index].R);
  //  TS_ASSERT_EQUALS(c.table[index].G, hg_c.table[index].G);
  //  TS_ASSERT_EQUALS(c.table[index].B, hg_c.table[index].B);
  //  TS_ASSERT_EQUALS(c.table[index].A, hg_c.table[index].A);
  //}
}

//  ******************************************************************************
void CarbonTestSuite::Test_msg_to_struct_vector()
{
  Hg::object_t hg_obj;

  //for (size_t index = 0; index < 16; ++index)
  //{
  //  hg_c.table[index].R = index * 2;
  //  hg_c.table[index].G = index * 3;
  //  hg_c.table[index].B = index * 4;
  //  hg_c.table[index].A = index * 5;
  //}

  object_t obj;

  // SUT
  C::msg_to_struct(hg_obj, obj);
  
  //for (size_t index = 0; index < 16; ++index)
  //{
  //  TS_ASSERT_EQUALS(c.table[index].R, hg_c.table[index].R);
  //  TS_ASSERT_EQUALS(c.table[index].G, hg_c.table[index].G);
  //  TS_ASSERT_EQUALS(c.table[index].B, hg_c.table[index].B);
  //  TS_ASSERT_EQUALS(c.table[index].A, hg_c.table[index].A);
  //}
}

//  ******************************************************************************
//  ******************************************************************************
void CarbonTestSuite::Test_Hg_local_endianess()
{
  int endian = Hg_local_endianess();

  TS_ASSERT_EQUALS(ALCHEMY_ENDIANESS, endian);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_create()
{
  Hg_msg_t *sut = Hg_create(k_color_map_t);

  // SUT
  Hg_destroy(sut);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_create_Invalid_type()
{
  // SUT
  Hg_msg_t* p_msg = Hg_create(k_invalid_type);

  TS_ASSERT(!p_msg);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_clone()
{
  Hg_msg_t *sut = GetSUT(k_vertex_t);

  // SUT
  Hg_msg_t* p_result = Hg_clone(sut);

  size_t len = Hg_size(sut);

  TS_ASSERT_SAME_DATA(p_result, sut, len);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_clone_Uninitialized()
{
  // SUT
  Hg_msg_t* p_msg = Hg_clone(0);

  TS_ASSERT(!p_msg);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_destroy()
{
  Hg_msg_t *sut = Hg_create(k_vertex_t);

  // SUT
  Hg_destroy(0);
  Hg_destroy(sut);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_field_alloc()
{
  const size_t k_triangle_size = Hg::SizeOf<Hg::triangle_t>::value;
  const size_t k_control = k_triangle_size * 12;

  Hg_msg_t *p_msg = GetSUT(k_object_t);

  object_t* p_object = (object_t*)p_msg;

  // SUT
  size_t result = 
    Hg_field_alloc( p_msg, 
                    (void**)&p_object->surfaces, 
                    k_triangle_size * 12);

  TS_ASSERT_EQUALS(k_control, result);

  result = Hg_size((Hg_msg_t*)p_object->surfaces);

  TS_ASSERT_EQUALS(k_control, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_field_alloc_Uninitialized_msg()
{
  // SUT
  Hg_msg_t *p_field = GetSUT(k_vertex_t);

  size_t len = Hg_field_alloc(0, (void**)&p_field, 200);

  TS_ASSERT_EQUALS(0, len);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_field_alloc_Uninitialized_field()
{
  // SUT
  Hg_msg_t *p_msg = GetSUT(k_vertex_t);

  size_t len = Hg_field_alloc(p_msg, 0, 200);

  TS_ASSERT_EQUALS(0, len);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_field_alloc_zero_size()
{
  Hg_msg_t *p_msg = GetSUT(k_object_t);

  object_t* p_object = (object_t*)p_msg;

  // SUT
  size_t result = 
    Hg_field_alloc( p_msg, 
                    (void**)&p_object->surfaces, 
                    0);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_type()
{
  const Hg_type_t k_control = k_ray_t;
  Hg_msg_t *sut = GetSUT(k_control);

  // SUT
  Hg_type_t type = Hg_type(sut);

  TS_ASSERT_EQUALS(k_control, type);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_type_Uninitialized()
{
  // SUT
  Hg_type_t type = Hg_type(0);

  TS_ASSERT_EQUALS(k_invalid_type, type);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_size()
{
  const size_t k_control = Hg::SizeOf<Hg::ray_t>::value;
  Hg_msg_t *p_msg = GetSUT(k_ray_t);

  // SUT
  size_t len = Hg_size(p_msg);

  TS_ASSERT_EQUALS(k_control, len);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_size_Uninitialized()
{
  // SUT
  size_t len = Hg_size(0);

  TS_ASSERT_EQUALS(0, len);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_data_size()
{
  const size_t k_count          = 4;
  const size_t k_triangle_size  = Hg::SizeOf<Hg::triangle_t>::value;
  const size_t k_control        = Hg::SizeOf<Hg::object_t>::value
                                + (k_triangle_size * k_count);

  Hg_msg_t *p_msg = GetSUT(k_object_t);

  object_t* p_object = (object_t*)p_msg;

  Hg_field_alloc( p_msg, 
                  (void**)&p_object->surfaces, 
                  k_triangle_size * k_count);

  // SUT
  size_t len = Hg_data_size(p_msg);

  TS_ASSERT_EQUALS(k_control, len);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_data_size_Uninitialized()
{
  // SUT
  size_t len = Hg_data_size(0);

  TS_ASSERT_EQUALS(0, len);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_network()
{
  Hg_msg_t *control  = Hg_create(k_vertex_t);
#if (ALCHEMY_ENDIANESS == ALCHEMY_BIG_ENDIAN)
  // No conversion will occur if the local system is big endian.
  PopulateTestHostMsg((vertex_t*)sut);
#else
  PopulateTestNetMsg((vertex_t*)control);
#endif

  Hg_msg_t      *sut = GetSUT(k_vertex_t);
  PopulateTestHostMsg((vertex_t*)sut);

  // SUT
  int result = Hg_to_network(sut);

  TS_ASSERT_EQUALS(0, result);
  TS_ASSERT_SAME_DATA(control, sut, sizeof(vertex_t));

  Hg_destroy(control);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_network_Uninitialized()
{
  // SUT
  int result = Hg_to_network(0);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_host()
{
  Hg_msg_t *control  = Hg_create(k_vertex_t);
#if (ALCHEMY_ENDIANESS == ALCHEMY_BIG_ENDIAN)
  // No conversion will occur if the local system is big endian.
  PopulateTestNetMsg((vertex_t*)control);
#else
  PopulateTestHostMsg((vertex_t*)control);
#endif

  Hg_msg_t      *sut = GetSUT(k_vertex_t);
  PopulateTestNetMsg((vertex_t*)sut);

  // SUT
  int result = Hg_to_network(sut);

  TS_ASSERT_EQUALS(0, result);
  TS_ASSERT_SAME_DATA(control, sut, sizeof(vertex_t));

  Hg_destroy(control);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_host_Uninitialized()
{
  // SUT
  int result = Hg_to_host(0);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_big_end()
{
  Hg_msg_t *control  = Hg_create(k_vertex_t);
  PopulateTestNetMsg((vertex_t*)control);

  Hg_msg_t      *sut = GetSUT(k_vertex_t);
  PopulateTestHostMsg((vertex_t*)sut);

  // SUT
  int result = Hg_to_network(sut);

  TS_ASSERT_EQUALS(0, result);
  TS_ASSERT_SAME_DATA(control, sut, sizeof(vertex_t));

  Hg_destroy(control);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_big_end_Uninitialized()
{
  // SUT
  int result = Hg_to_big_end(0);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_little_end()
{
  Hg_msg_t *control  = Hg_create(k_vertex_t);
  PopulateTestNetMsg((vertex_t*)control);

  Hg_msg_t      *sut = GetSUT(k_vertex_t);
  PopulateTestHostMsg((vertex_t*)sut);

  // SUT
  int result = Hg_to_network(sut);

  TS_ASSERT_EQUALS(0, result);
  TS_ASSERT_SAME_DATA(control, sut, sizeof(vertex_t));

  Hg_destroy(control);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_to_little_end_Uninitialized()
{
  // SUT
  int result = Hg_to_little_end(0);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_pack()
{
  unsigned char control[k_msg_buffer_len];
  PopulateHostOrder(control, k_msg_buffer_len);

  Hg_msg_t *sut = GetSUT(k_vertex_t);
  PopulateTestHostMsg((vertex_t*)sut);

  unsigned char result_buffer[k_msg_buffer_len] = {0};

  // SUT
  int result = Hg_pack(sut, result_buffer, k_msg_buffer_len);

  TS_ASSERT_SAME_DATA(control, result_buffer, sizeof(vertex_t));
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_pack_invalid_msg()
{
  unsigned char buffer[k_msg_buffer_len];

  // SUT
  int result = Hg_pack(0, buffer, k_msg_buffer_len);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_pack_invalid_buffer()
{
  Hg_msg_t *sut = GetSUT(k_test_msg_type);

  // SUT
  int result = Hg_pack(sut, 0, k_msg_buffer_len);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_pack_invalid_len()
{
  Hg_msg_t      *sut = GetSUT(k_test_msg_type);
  unsigned char  buffer[k_msg_buffer_len];

  // SUT
  int result = Hg_pack(sut, buffer, 0);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_unpack()
{
  Hg_msg_t *control = Hg_create(k_vertex_t);
  PopulateTestHostMsg((vertex_t*)control);

  Hg_msg_t      *sut        = GetSUT(k_vertex_t);
  unsigned char buffer[k_msg_buffer_len];

  PopulateHostOrder(buffer, k_msg_buffer_len);

  // SUT
  int result = Hg_unpack(sut, buffer, k_msg_buffer_len);

  TS_ASSERT_SAME_DATA(control, sut, sizeof(vertex_t));

  Hg_destroy(control);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_unpack_invalid_msg()
{
  unsigned char buffer[k_msg_buffer_len];

  // SUT
  int result = Hg_unpack(0, buffer, k_msg_buffer_len);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_unpack_invalid_buffer()
{
  Hg_msg_t *sut = GetSUT(k_test_msg_type);

  // SUT
  int result = Hg_unpack(sut, 0, k_msg_buffer_len);

  TS_ASSERT_EQUALS(0, result);
}

//  ******************************************************************************
void CarbonTestSuite::Test_Hg_unpack_invalid_len()
{
  Hg_msg_t      *sut = GetSUT(k_test_msg_type);
  unsigned char  buffer[k_msg_buffer_len];

  // SUT
  int result = Hg_unpack(sut, buffer, 0);

  TS_ASSERT_EQUALS(0, result);
}

#endif




