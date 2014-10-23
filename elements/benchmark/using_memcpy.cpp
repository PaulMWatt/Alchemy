/// @file using_memcpy.cpp
/// 
/// Implements message parsing by using memcpy when possible. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
//  Includes *******************************************************************
#include <using_memcpy.h>
#include <Hg.h>

struct Basic
{
  int32_t         i32;
  uint32_t        u32;
  int16_t         i16;
  uint16_t        u16;
  char            ch;
  uint8_t         u8;
};


void ReadBasic( alchemy::benchmark::DataBuffer &data,
                alchemy::benchmark::Basic      &msg)
{
  // Read the basic field data in.
  ::memcpy(&msg.i32, data.GetBytes(sizeof(int32_t)),  sizeof(int32_t));
  ::memcpy(&msg.u32, data.GetBytes(sizeof(uint32_t)), sizeof(uint32_t));
  ::memcpy(&msg.i16, data.GetBytes(sizeof(int16_t)),  sizeof(int16_t));
  ::memcpy(&msg.u16, data.GetBytes(sizeof(uint16_t)), sizeof(uint16_t));
  ::memcpy(&msg.ch,  data.GetBytes(sizeof(char)),     sizeof(char));
  ::memcpy(&msg.u8,  data.GetBytes(sizeof(uint8_t)),  sizeof(uint8_t));
}

void WriteBasic(alchemy::benchmark::DataBuffer &data,
                alchemy::benchmark::Basic      &msg)
{
  // Read the basic field data in.
  ::memcpy(data.GetBytes(sizeof(int32_t)), &msg.i32, sizeof(int32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)),&msg.u32, sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(int16_t)), &msg.i16, sizeof(int16_t));
  ::memcpy(data.GetBytes(sizeof(uint16_t)),&msg.u16, sizeof(uint16_t));
  ::memcpy(data.GetBytes(sizeof(char)),    &msg.ch,  sizeof(char));
  ::memcpy(data.GetBytes(sizeof(uint8_t)), &msg.u8,  sizeof(uint8_t));
}

void BasicToNetwork(const alchemy::benchmark::Basic &host,
                          alchemy::benchmark::Basic &net)
{
  // Convert the necessary terms to network byte order.
  net.i32 = htonl(host.i32);
  net.u32 = htonl(host.u32);
  net.i16 = htons(host.i16);
  net.u16 = htons(host.u16);
  net.ch  = host.ch;
  net.u8  = host.u8;
}


namespace alchemy
{
namespace benchmark
{

void UsingMemcpy::test_basic( DataBuffer &data,
                              DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Basic;

  size_t len   = Hg::SizeOf<Hg::Basic>::value;
  size_t count = data.Size() / len;

  for (size_t index = 0; index < count; ++index)
  {
    Basic host;
    ReadBasic(data, host);

    Basic net;
    BasicToNetwork(host, net);

    WriteBasic(out, net);
  }
}

void UsingMemcpy::test_packed_bits(DataBuffer &data)
{

}

void UsingMemcpy::test_unaligned(DataBuffer &data)
{

}

void UsingMemcpy::test_complex(DataBuffer &data)
{

}

} // benchmark
} // alchemy

