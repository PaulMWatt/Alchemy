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
typedef Hg::MessageT<Hg::Basic_HgFormat, Hg::HostByteOrder, Hg::BufferedStaticStoragePolicy>   HgBasicHost;
typedef Hg::MessageT<Hg::Basic_HgFormat, Hg::NetByteOrder, Hg::BufferedStaticStoragePolicy>    HgBasicNet;


void UsingHg::test_basic(DataBuffer &data,
                         DataBuffer &out)
{
  size_t len   = Hg::SizeOf<Hg::Basic>::value;
  size_t count = data.Size() / len;

  cout << "basic size:      " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgBasicHost host((HgBasicHost::data_type*)data.GetBytes(len), len);  

    HgBasicNet  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }
}

//  ****************************************************************************
typedef Hg::MessageT<Hg::Packed_HgFormat, Hg::HostByteOrder, Hg::BufferedStaticStoragePolicy>   HgPackedHost;
typedef Hg::MessageT<Hg::Packed_HgFormat, Hg::NetByteOrder, Hg::BufferedStaticStoragePolicy>    HgPackedNet;

void UsingHg::test_packed_bits( DataBuffer &data,
                                DataBuffer &out)
{
  size_t len   = Hg::SizeOf<Hg::Packed>::value;
  size_t count = data.Size() / len;

  cout << "packed size:     " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgPackedHost host((HgPackedHost::data_type*)data.GetBytes(len), len);  

    HgPackedNet  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }
}


//  ****************************************************************************
typedef Hg::MessageT<Hg::Unaligned_HgFormat, Hg::HostByteOrder, Hg::BufferedStaticStoragePolicy>   HgUnalignedHost;
typedef Hg::MessageT<Hg::Unaligned_HgFormat, Hg::NetByteOrder, Hg::BufferedStaticStoragePolicy>    HgUnalignedNet;

void UsingHg::test_unaligned( DataBuffer &data,
                              DataBuffer &out)
{
  size_t len   = Hg::SizeOf<Hg::Unaligned>::value;
  size_t count = data.Size() / len;

  cout << "unaligned size:  " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgUnalignedHost host((HgUnalignedHost::data_type*)data.GetBytes(len), len);  

    HgUnalignedNet  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }

}

//  ****************************************************************************
typedef Hg::MessageT<Hg::Complex_HgFormat, Hg::HostByteOrder, Hg::BufferedStaticStoragePolicy>   HgComplexHost;
typedef Hg::MessageT<Hg::Complex_HgFormat, Hg::NetByteOrder, Hg::BufferedStaticStoragePolicy>    HgComplexNet;

void UsingHg::test_complex(DataBuffer &data,
                           DataBuffer &out)
{
  size_t len = Hg::SizeOf<Hg::Complex>::value;
  size_t count = data.Size() / len;

  cout << "complex size:    " << len   << ", count; " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    HgComplexHost host((HgComplexHost::data_type*)data.GetBytes(len), len);  

    HgComplexNet  net = Hg::to_network(host);

    net.data((unsigned char*)out.GetBytes(len), len);
  }

}


} // benchmark
} // alchemy

