/// @file using_Hg.cpp
/// 
/// Implements message parsing by using Hg. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
//  Includes *******************************************************************
#include <using_Hg.h>
#include <Hg.h>
#include <Hg/static_msg_buffer.h>
#include <iostream>

using std::cout;
using std::endl;

namespace alchemy
{
namespace benchmark
{

//  ****************************************************************************
typedef Hg::basic_msg<Hg::Basic, Hg::BufferedStaticStoragePolicy>   HgBasic;


void UsingHg::test_basic(DataBuffer &data,
                         DataBuffer &out)
{
  size_t len   = Hg::SizeOf<Hg::Basic>::value;
  size_t count = data.Size() / len;

  cout << "basic size:      " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgBasic::host_t host((HgBasic::data_type*)data.GetBytes(len), len);  

    HgBasic::net_t  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }
}

//  ****************************************************************************
typedef Hg::basic_msg<Hg::Packed, Hg::BufferedStaticStoragePolicy>   HgPacked;

void UsingHg::test_packed_bits( DataBuffer &data,
                                DataBuffer &out)
{
  size_t len   = Hg::SizeOf<Hg::Packed>::value;
  size_t count = data.Size() / len;

  cout << "packed size:     " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgPacked::host_t host((HgPacked::data_type*)data.GetBytes(len), len);  

    HgPacked::net_t  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }
}


//  ****************************************************************************
typedef Hg::basic_msg<Hg::Unaligned, Hg::BufferedStaticStoragePolicy>   HgUnaligned;

void UsingHg::test_unaligned( DataBuffer &data,
                              DataBuffer &out)
{
  size_t len   = Hg::SizeOf<Hg::Unaligned>::value;
  size_t count = data.Size() / len;

  cout << "unaligned size:  " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgUnaligned::host_t host((HgUnaligned::data_type*)data.GetBytes(len), len);  

    HgUnaligned::net_t  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }

}

//  ****************************************************************************
typedef Hg::basic_msg<Hg::Complex, Hg::BufferedStaticStoragePolicy>   HgComplex;

void UsingHg::test_complex(DataBuffer &data,
                           DataBuffer &out)
{
  size_t len = Hg::SizeOf<Hg::Complex>::value;
  size_t count = data.Size() / len;

  cout << "complex size:    " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgComplex::host_t host((HgComplex::data_type*)data.GetBytes(len), len);  

    HgComplex::net_t  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }

}


//  ****************************************************************************
typedef Hg::basic_msg<Hg::Array_test, Hg::BufferedStaticStoragePolicy>   HgArray;

void UsingHg::test_array(DataBuffer &data,
                         DataBuffer &out)
{
  size_t len = Hg::SizeOf<Hg::Array_test>::value;
  size_t count = data.Size() / len;

  cout << "array size:    " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgArray::host_t host((HgArray::data_type*)data.GetBytes(len), len);  

    HgArray::net_t  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }

}




} // benchmark
} // alchemy

