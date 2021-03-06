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
namespace detail
{

//  ****************************************************************************
template< typename T >
void test_impl( DataBuffer &data,
                DataBuffer &out,
                const char (&name)[14])
{
  using HgType = Hg::basic_msg<T, Hg::BufferedStaticStoragePolicy>;

  size_t len = Hg::size_of<HgType>::value;
  cout << name << " size: " << len;

  size_t count = data.Size() / len;

  if (len < 1000)
  {
    cout << "\t";
  }

  cout << "\tcount: " << count << endl;
  
  
  for (size_t index = 0; index < count; ++index)
  {
    HgType::host_t host((HgType::data_type*)data.GetBytes(len), len);  
    HgType::net_t  net = std::move(Hg::to_network(host));

    net.data((unsigned char*)out.GetBytes(len), len);
  }

}

} // namespace detail


//  ****************************************************************************
void UsingHg::test_no_conversion( DataBuffer &data,
                                  DataBuffer &out)
{
  detail::test_impl<Hg::NoConversion>(data, out, "no_conversion");
}

//  ****************************************************************************
void UsingHg::test_basic(DataBuffer &data,
                         DataBuffer &out)
{
  detail::test_impl<Hg::Basic>(data, out, "        basic");
}

//  ****************************************************************************
void UsingHg::test_packed_bits( DataBuffer &data,
                                DataBuffer &out)
{
  detail::test_impl<Hg::Packed>(data, out, "       packed");
}


//  ****************************************************************************
void UsingHg::test_unaligned( DataBuffer &data,
                              DataBuffer &out)
{
  detail::test_impl<Hg::Unaligned>(data, out, "    unaligned");
}

//  ****************************************************************************
void UsingHg::test_complex(DataBuffer &data,
                           DataBuffer &out)
{
  detail::test_impl<Hg::Complex>(data, out, "      complex");
}


//  ****************************************************************************
void UsingHg::test_array(DataBuffer &data,
                         DataBuffer &out)
{
  detail::test_impl<Hg::Array_test>(data, out, "        array");
}



} // benchmark
} // alchemy

