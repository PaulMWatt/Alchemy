/// @file benchmark.cpp
/// 
/// Performs a basic set of benchmark tests for comparison with other implementations.. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#include <benchmark_util.h>
#include <benchmark_formats.h>
#include <iostream>
#include <string>
#include <vector>

#include <using_Hg.h>
#include <using_memcpy.h>


//  ****************************************************************************
typedef std::vector<double>     TimeValues;
using std::cout;
using std::endl;


namespace alchemy
{
namespace benchmark
{

enum TimeIndex
{
  k_start_basic = 0,
  k_end_basic,
  k_start_packed,
  k_end_packed,
  k_start_unaligned,
  k_end_unaligned,
  k_start_complex,
  k_end_complex
};


//  ****************************************************************************
template <class T>
void RunTest(DataBuffer &data, TimeValues &times)
{
  DataBuffer output(data.Size());
  std::vector<int> X; 

  times.clear();

  // Run and record the end of the Basic test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_basic(data, output);
  times.push_back(get_time());

  //int v = output.Value();
  //X.push_back(v);

  // Run and record the end of the PackedBits test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_packed_bits(data);
  times.push_back(get_time());

  // Run and record the end of the Unaligned test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_unaligned(data);
  times.push_back(get_time());

  // Run and record the end of the Complex test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_complex(data);
  times.push_back(get_time());

//  std::cout << "X" << X[0] << std::endl;
}


//  ****************************************************************************
void DisplayResults(const std::string &name, 
                    const TimeValues  &times)
{
  cout << "Results for " << name << "\n";

  double basic_len     = times[k_end_basic]     - times[k_start_basic];
  double packed_len    = times[k_end_packed]    - times[k_start_packed];   
  double unaligned_len = times[k_end_unaligned] - times[k_start_unaligned];
  double complex_len   = times[k_end_complex]   - times[k_start_complex];
  double total_len     = basic_len + packed_len + unaligned_len + complex_len;

  cout << "Basic:     " << basic_len     << "s\n";
  cout << "Packed:    " << packed_len    << "s\n";
  cout << "Unaligned: " << unaligned_len << "s\n";
  cout << "Complex:   " << complex_len   << "s\n";
  cout << "Total:     " << total_len     << "s\n" << endl;
}

} // namespace benchmark
} // namespace alchemy

//  ****************************************************************************
int main(int argc, char* argv[])
{
  using namespace alchemy::benchmark;

  cout << "Loading test data:" << endl;
  // Pre-allocate memory for processing.
  DataBuffer data;
  data.Init(0x1000000);

  // Run the test scenario for each type of implementation.
  cout << "Running Hg benchmark:" << endl;

  TimeValues hgTime;
  RunTest<UsingHg>(data, hgTime);
  cout << "Test completed\n" << endl;

  cout << "Running memcpy benchmark:" << endl;

  TimeValues memcpyTime;
  RunTest<UsingMemcpy>(data, memcpyTime);
  cout << "Test completed\n" << endl;

  DisplayResults("Hg:     ", hgTime);

  // Display the tabulated results.
  DisplayResults("memcpy: ", memcpyTime);

	return 0;
}



