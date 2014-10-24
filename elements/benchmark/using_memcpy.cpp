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
#include <iostream>

using std::cout;
using std::endl;

//  ****************************************************************************
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

//  ****************************************************************************
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

//  ****************************************************************************
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

//  ****************************************************************************
void ReadUnaligned( alchemy::benchmark::DataBuffer &data,
                    alchemy::benchmark::Unaligned  &msg)
{
  // Read the basic field data in.
  ::memcpy(&msg.ch,    data.GetBytes(sizeof(char    )), sizeof(char    ));
  ::memcpy(&msg.u32_a, data.GetBytes(sizeof(uint32_t)), sizeof(uint32_t));
  ::memcpy(&msg.u32_b, data.GetBytes(sizeof(uint32_t)), sizeof(uint32_t));
  ::memcpy(&msg.u32_c, data.GetBytes(sizeof(uint32_t)), sizeof(uint32_t));
  ::memcpy(&msg.i16_a, data.GetBytes(sizeof(int16_t )), sizeof(int16_t ));
  ::memcpy(&msg.i16_b, data.GetBytes(sizeof(int16_t )), sizeof(int16_t ));
  ::memcpy(&msg.i16_c, data.GetBytes(sizeof(int16_t )), sizeof(int16_t ));
}

//  ****************************************************************************
void WriteUnaligned(alchemy::benchmark::DataBuffer &data,
                    alchemy::benchmark::Unaligned  &msg)
{
  // Read the basic field data in.
  ::memcpy(data.GetBytes(sizeof(char    )), &msg.ch,    sizeof(char    ));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.u32_a, sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.u32_b, sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.u32_c, sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(int16_t )), &msg.i16_a, sizeof(int16_t ));
  ::memcpy(data.GetBytes(sizeof(int16_t )), &msg.i16_b, sizeof(int16_t ));
  ::memcpy(data.GetBytes(sizeof(int16_t )), &msg.i16_c, sizeof(int16_t ));
}

//  ****************************************************************************
void UnalignedToNetwork(const alchemy::benchmark::Unaligned &host,
                              alchemy::benchmark::Unaligned &net)
{
  // Convert the necessary terms to network byte order.
  net.ch    = host.ch;
  net.u32_a = htonl(host.u32_a);
  net.u32_b = htonl(host.u32_b);
  net.u32_c = htonl(host.u32_c);
  net.i16_a = htons(host.i16_a);
  net.i16_b = htons(host.i16_b);
  net.i16_c = htons(host.i16_c);
}

//  ****************************************************************************
void ReadComplex( alchemy::benchmark::DataBuffer &data,
                  alchemy::benchmark::Complex    &msg)
{
  // Read the basic field data in.
  ::memcpy(&msg.seq, data.GetBytes(sizeof(uint32_t)), sizeof(uint32_t));
  ReadBasic(data, msg.basic[0]);
  ReadBasic(data, msg.basic[1]);
  ReadBasic(data, msg.basic[2]);

//  ReadBasic(data, msg.basic[0]);

  ReadUnaligned(data, msg.unaligned);
}

//  ****************************************************************************
void WriteComplex(alchemy::benchmark::DataBuffer &data,
                  alchemy::benchmark::Complex    &msg)
{
  // Read the basic field data in.
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.seq, sizeof(uint32_t));

  WriteBasic(data, msg.basic[0]);
  WriteBasic(data, msg.basic[1]);
  WriteBasic(data, msg.basic[2]);

//  ReadBasic(data, msg.basic[0]);

  WriteUnaligned(data, msg.unaligned);
}

//  ****************************************************************************
void ComplexToNetwork(const alchemy::benchmark::Complex &host,
                            alchemy::benchmark::Complex &net)
{
  // Convert the necessary terms to network byte order.
  net.seq = htonl(host.seq);

  BasicToNetwork(host.basic[0], net.basic[0]);
  BasicToNetwork(host.basic[1], net.basic[1]);
  BasicToNetwork(host.basic[2], net.basic[2]);

  net.bits.set_a = host.bits.set_a;
  net.bits.set_b = host.bits.set_b;
  net.bits.set_c = host.bits.set_c;

  UnalignedToNetwork(host.unaligned, net.unaligned);
}

namespace alchemy
{
namespace benchmark
{

//  ****************************************************************************
void UsingMemcpy::test_basic( DataBuffer &data,
                              DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Basic;

  size_t len   = Hg::SizeOf<alchemy::benchmark::Basic>::value;
  size_t count = data.Size() / len;

  cout << "basic count: "     << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    Basic host;
    ReadBasic(data, host);

    Basic net;
    BasicToNetwork(host, net);

    WriteBasic(out, net);
  }
}

//  ****************************************************************************
void UsingMemcpy::test_packed_bits(DataBuffer &data,
                                   DataBuffer &out)
{

}

//  ****************************************************************************
void UsingMemcpy::test_unaligned( DataBuffer &data,
                                  DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Unaligned;

  size_t len   = Hg::SizeOf<alchemy::benchmark::Unaligned>::value;
  size_t count = data.Size() / len;

  cout << "unaligned count: " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    Unaligned host;
    ReadUnaligned(data, host);

    Unaligned net;
    UnalignedToNetwork(host, net);

    WriteUnaligned(out, net);
  }
}

//  ****************************************************************************
void UsingMemcpy::test_complex(DataBuffer &data,
                               DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Complex;

  size_t len   = Hg::SizeOf<alchemy::benchmark::Complex>::value;
  size_t count = data.Size() / len;
  cout << "complex count:   " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    Complex host;
    ReadComplex(data, host);

    Complex net;
    ComplexToNetwork(host, net);

    WriteComplex(out, net);
  }

}

} // benchmark
} // alchemy

