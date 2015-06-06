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
void ReadNoConversion(alchemy::benchmark::DataBuffer    &data,
                      alchemy::benchmark::NoConversion  &msg)
{
  // Read the basic field data in.
  ::memcpy(&msg.ch_0,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_1,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_2,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_3,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_4,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_5,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_6,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_7,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_8,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_9,  data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_10, data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_11, data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_12, data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_13, data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_14, data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  ::memcpy(&msg.ch_15, data.GetBytes(sizeof(uint32_t)),  sizeof(uint32_t));
  //  ::memcpy(&msg, data.GetBytes(sizeof(alchemy::benchmark::NoConversion)), sizeof(alchemy::benchmark::NoConversion));
}

//  ****************************************************************************
void WriteNoConversion( alchemy::benchmark::DataBuffer    &data,
                        alchemy::benchmark::NoConversion  &msg)
{
  // Read the basic field data in.
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_0,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_1,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_2,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_3,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_4,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_5,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_6,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_7,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_8,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_9,   sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_10,  sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_11,  sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_12,  sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_13,  sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_14,  sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.ch_15,  sizeof(uint32_t));
//  ::memcpy(data.GetBytes(sizeof(alchemy::benchmark::NoConversion)), &msg, sizeof(alchemy::benchmark::NoConversion));
}

//  ****************************************************************************
void NoConversionToNetwork( const alchemy::benchmark::NoConversion &host,
                                  alchemy::benchmark::NoConversion &net)
{
  // Read the basic field data in.
  ::memcpy(&net.ch_0,   &host.ch_0,   sizeof(uint32_t));
  ::memcpy(&net.ch_1,   &host.ch_1,   sizeof(uint32_t));
  ::memcpy(&net.ch_2,   &host.ch_2,   sizeof(uint32_t));
  ::memcpy(&net.ch_3,   &host.ch_3,   sizeof(uint32_t));
  ::memcpy(&net.ch_4,   &host.ch_4,   sizeof(uint32_t));
  ::memcpy(&net.ch_5,   &host.ch_5,   sizeof(uint32_t));
  ::memcpy(&net.ch_6,   &host.ch_6,   sizeof(uint32_t));
  ::memcpy(&net.ch_7,   &host.ch_7,   sizeof(uint32_t));
  ::memcpy(&net.ch_8,   &host.ch_8,   sizeof(uint32_t));
  ::memcpy(&net.ch_9,   &host.ch_9,   sizeof(uint32_t));
  ::memcpy(&net.ch_10,  &host.ch_10,  sizeof(uint32_t));
  ::memcpy(&net.ch_11,  &host.ch_11,  sizeof(uint32_t));
  ::memcpy(&net.ch_12,  &host.ch_12,  sizeof(uint32_t));
  ::memcpy(&net.ch_13,  &host.ch_13,  sizeof(uint32_t));
  ::memcpy(&net.ch_14,  &host.ch_14,  sizeof(uint32_t));
  ::memcpy(&net.ch_15,  &host.ch_15,  sizeof(uint32_t));
  //::memcpy(&net, &host, sizeof(alchemy::benchmark::NoConversion));
}

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
void ReadPacked(alchemy::benchmark::DataBuffer &data,
                alchemy::benchmark::Packed     &msg)
{
  // Read the basic field data in.
  ::memcpy(&msg.set_a, data.GetBytes(sizeof(int32_t)),  sizeof(int32_t));
  ::memcpy(&msg.set_b, data.GetBytes(sizeof(uint16_t)), sizeof(uint16_t));
  ::memcpy(&msg.set_c,  data.GetBytes(sizeof(uint8_t)),  sizeof(uint8_t));
}

//  ****************************************************************************
void WritePacked( alchemy::benchmark::DataBuffer &data,
                  alchemy::benchmark::Packed     &msg)
{
  // Read the basic field data in.
  ::memcpy(data.GetBytes(sizeof(uint32_t)),&msg.set_a, sizeof(uint32_t));
  ::memcpy(data.GetBytes(sizeof(uint16_t)),&msg.set_b, sizeof(uint16_t));
  ::memcpy(data.GetBytes(sizeof(uint8_t)), &msg.set_c, sizeof(uint8_t));
}

//  ****************************************************************************
void PackedToNetwork(const alchemy::benchmark::Packed &host,
                           alchemy::benchmark::Packed &net)
{
  // Convert the necessary terms to network byte order.
  net.set_a = htonl(host.set_a);
  net.set_b = htons(host.set_b);
  net.set_c = host.set_c;
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
  for (size_t i = 0; i < alchemy::benchmark::k_complex_basic_count; ++i)
  {
    ReadBasic(data, msg.basic[i]);
  }

  ReadPacked(data, msg.bits);

  ReadUnaligned(data, msg.unaligned);
}

//  ****************************************************************************
void WriteComplex(alchemy::benchmark::DataBuffer &data,
                  alchemy::benchmark::Complex    &msg)
{
  // Read the basic field data in.
  ::memcpy(data.GetBytes(sizeof(uint32_t)), &msg.seq, sizeof(uint32_t));

  for (size_t i = 0; i < alchemy::benchmark::k_complex_basic_count; ++i)
  {
    WriteBasic(data, msg.basic[i]);
  }

  WritePacked(data, msg.bits);

  WriteUnaligned(data, msg.unaligned);
}

//  ****************************************************************************
void ComplexToNetwork(const alchemy::benchmark::Complex &host,
                            alchemy::benchmark::Complex &net)
{
  // Convert the necessary terms to network byte order.
  net.seq = htonl(host.seq);

  for (size_t i = 0; i < alchemy::benchmark::k_complex_basic_count; ++i)
  {
    BasicToNetwork(host.basic[i], net.basic[i]);  
  }

  PackedToNetwork(host.bits, net.bits);

  UnalignedToNetwork(host.unaligned, net.unaligned);
}


//  ****************************************************************************
void ReadArray (alchemy::benchmark::DataBuffer &data,
                alchemy::benchmark::Array      &msg)
{
  for (size_t index = 0; index < alchemy::benchmark::k_array_test_count; ++index)
  {
    ::memcpy(&msg.items[index], data.GetBytes(sizeof(int32_t)),  sizeof(int32_t));
  }
}

//  ****************************************************************************
void WriteArray ( alchemy::benchmark::DataBuffer &data,
                  alchemy::benchmark::Array     &msg)
{
  for (size_t index = 0; index < alchemy::benchmark::k_array_test_count; ++index)
  {
    ::memcpy(data.GetBytes(sizeof(uint32_t)),&msg.items[index], sizeof(uint32_t));
  }
}

//  ****************************************************************************
void ArrayToNetwork (const alchemy::benchmark::Array &host,
                           alchemy::benchmark::Array &net)
{
  // Convert the necessary terms to network byte order.
  for (size_t index = 0; index < alchemy::benchmark::k_array_test_count; ++index)
  {
    net.items[index] = htonl(host.items[index]);
  }
}



namespace alchemy
{
namespace benchmark
{

//  ****************************************************************************
void UsingMemcpy::test_no_conversion( DataBuffer &data,
                                      DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::NoConversion;

  size_t len   = Hg::size_of<alchemy::benchmark::NoConversion>::value;
  size_t count = data.Size() / len;

  cout << "no_conversion size: " << len   << "\t\tcount: " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    alchemy::benchmark::NoConversion host;
    ReadNoConversion(data, host);

    alchemy::benchmark::NoConversion net;
    NoConversionToNetwork(host, net);

    WriteNoConversion(out, net);
  }
}

//  ****************************************************************************
void UsingMemcpy::test_basic( DataBuffer &data,
                              DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Basic;

  size_t len   = Hg::size_of<alchemy::benchmark::Basic>::value;
  size_t count = data.Size() / len;

  cout << "        basic size: " << len   << "\t\tcount: " << count << endl;
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
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Packed;

  size_t len   = Hg::size_of<alchemy::benchmark::Packed>::value;
  size_t count = data.Size() / len;

  cout << "       packed size: " << len   << "\t\tcount: " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    Packed host;
    ReadPacked(data, host);

    Packed net;
    PackedToNetwork(host, net);

    WritePacked(out, net);
  }

}

//  ****************************************************************************
void UsingMemcpy::test_unaligned( DataBuffer &data,
                                  DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Unaligned;

  size_t len   = Hg::size_of<alchemy::benchmark::Unaligned>::value;
  size_t count = data.Size() / len;

  cout << "    unaligned size: " << len   << "\t\tcount: " << count << endl;
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

  size_t len   = Hg::size_of<alchemy::benchmark::Complex>::value;
  size_t count = data.Size() / len;
  cout << "      complex size: " << len   << "\t\tcount: " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    Complex host;
    ReadComplex(data, host);

    Complex net;
    ComplexToNetwork(host, net);

    WriteComplex(out, net);
  }
}

//  ****************************************************************************
void UsingMemcpy::test_array (DataBuffer &data,
                              DataBuffer &out)
{
  using alchemy::benchmark::DataBuffer;
  using alchemy::benchmark::Array;

  size_t len   = Hg::size_of<alchemy::benchmark::Array>::value;
  size_t count = data.Size() / len;
  cout << "        array size: " << len   << "\tcount: " << count << endl;
  for (size_t index = 0; index < count; ++index)
  {
    Array host;
    ReadArray(data, host);

    Array net;
    ArrayToNetwork(host, net);

    WriteArray(out, net);
  }

}

} // benchmark
} // alchemy

