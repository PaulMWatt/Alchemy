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

namespace alchemy
{
namespace benchmark
{

typedef Hg::Message<Hg::Basic_HgFormat, Hg::HostByteOrder, Hg::BufferedStaticStoragePolicy>   HgBasicHost;
typedef Hg::Message<Hg::Basic_HgFormat, Hg::NetByteOrder, Hg::BufferedStaticStoragePolicy>    HgBasicNet;


void UsingHg::test_basic(DataBuffer &data,
                         DataBuffer &out)
{
  size_t len   = Hg::SizeOf<Hg::Basic>::value;
  size_t count = data.Size() / len;

  for (size_t index = 0; index < count; ++index)
  {
    HgBasicHost host((HgBasicHost::data_type*)data.GetBytes(len), len);  

    //HgBasicNet  net = Hg::to_network(host);
    HgBasicNet  net;//((HgBasicHost::data_type*)data.GetBytes(len), len);

    net.data((unsigned char*)out.GetBytes(len), len);
  }
}

void UsingHg::test_packed_bits(DataBuffer &data)
{

}

void UsingHg::test_unaligned(DataBuffer &data)
{

}

void UsingHg::test_complex(DataBuffer &data)
{

}


} // benchmark
} // alchemy

