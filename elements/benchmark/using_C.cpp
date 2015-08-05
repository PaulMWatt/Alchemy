/// @file using_Hg.cpp
/// 
/// Implements message parsing by using Hg. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
//  Includes *******************************************************************
#ifdef BENCHMARK_CARBON

#include <using_C.h>
#include <Carbon.h>
#include <Hg.h>
#include <../BenchmarkCarbonLibrary/BenchmarkCarbonDefs.h>
#include <Hg/static_msg_buffer.h>
#include <iostream>

#if defined(_MSC_VER)

// Library import directive for Microsoft compiler.
#pragma comment(lib, "BenchmarkCarbonLibrary")

#endif



using std::cout;
using std::endl;

namespace alchemy
{
namespace benchmark
{
namespace detail
{

//  ****************************************************************************
template< size_t Type >
void test_impl( DataBuffer &data,
                DataBuffer &out,
                const char (&name)[14])
{
  // Pre-allocate message objects.
  Hg_msg_t *pMsg = Hg_create(Type);

  size_t len = Hg_size(pMsg);
  size_t count = data.Size() / len;

  cout << name << " size: " << len   << "\t\tcount: " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    Hg_unpack(pMsg, (unsigned char*)data.GetBytes(len), len);  
    Hg_to_network(pMsg);
    Hg_pack(pMsg, (unsigned char*)out.GetBytes(len), len);
  }

  Hg_destroy(pMsg);
  pMsg = 0;
}

} // namespace detail


  //  ****************************************************************************
void UsingC::test_no_conversion( DataBuffer &data,
                                  DataBuffer &out)
{
  detail::test_impl<k_NoConversion>(data, out, "no_conversion");
}

//  ****************************************************************************
void UsingC::test_basic(DataBuffer &data,
                         DataBuffer &out)
{
  detail::test_impl<k_Basic>(data, out, "        basic");
}

//  ****************************************************************************
void UsingC::test_packed_bits( DataBuffer &data,
                                DataBuffer &out)
{
  detail::test_impl<k_Packed>(data, out, "       packed");
}


//  ****************************************************************************
void UsingC::test_unaligned( DataBuffer &data,
                              DataBuffer &out)
{
  detail::test_impl<k_Unaligned>(data, out, "    unaligned");
}

//  ****************************************************************************
void UsingC::test_array(DataBuffer &data,
                         DataBuffer &out)
{
  detail::test_impl<k_Array_test>(data, out, "        array");
}

//  ****************************************************************************
void UsingC::test_complex(DataBuffer &data,
                           DataBuffer &out)
{
  detail::test_impl<k_Complex>(data, out, "      complex");
}




} // benchmark
} // alchemy

#endif
