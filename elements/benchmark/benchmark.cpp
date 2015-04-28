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
using std::cin;
using std::cout;
using std::endl;


namespace alchemy
{
namespace benchmark
{

//const size_t k_cycles = 0x1000000;
const size_t k_cycles   = 0x8000000;

enum TimeIndex
{
  k_start_basic = 0,
  k_end_basic,
  k_start_packed,
  k_end_packed,
  k_start_unaligned,
  k_end_unaligned,
  k_start_complex,
  k_end_complex,
  k_start_array,
  k_end_array
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

  // Run and record the end of the PackedBits test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_packed_bits(data, output);
  times.push_back(get_time());

  // Run and record the end of the Unaligned test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_unaligned(data, output);
  times.push_back(get_time());

  // Run and record the end of the Complex test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_complex(data, output);
  times.push_back(get_time());

  // Run and record the end of the Array test.
  data.Reset();
  output.Restart();

  times.push_back(get_time());
  T::test_array(data, output);
  times.push_back(get_time());
}


//  ****************************************************************************
void DisplayResults(const std::string &control_name, 
                    const TimeValues  &control_times,
                    const std::string &name, 
                    const TimeValues  &times)
{
  double c_basic_len     = control_times[k_end_basic]     - control_times[k_start_basic];
  double c_packed_len    = control_times[k_end_packed]    - control_times[k_start_packed];   
  double c_unaligned_len = control_times[k_end_unaligned] - control_times[k_start_unaligned];
  double c_complex_len   = control_times[k_end_complex]   - control_times[k_start_complex];
  double c_array_len     = control_times[k_end_array]   - control_times[k_start_array];
  double c_total_len     = c_basic_len + c_packed_len + c_unaligned_len + c_complex_len + c_array_len;

  double basic_len     = times[k_end_basic]     - times[k_start_basic];
  double packed_len    = times[k_end_packed]    - times[k_start_packed];   
  double unaligned_len = times[k_end_unaligned] - times[k_start_unaligned];
  double complex_len   = times[k_end_complex]   - times[k_start_complex];
  double array_len     = times[k_end_array]     - times[k_start_array];
  double total_len     = basic_len + packed_len + unaligned_len + complex_len + array_len;

  cout << "           " << control_name << "\t" << name << "\tdiff\t\tpercent\n";

  cout << "Basic:     " << c_basic_len     << "s\t" << basic_len     << "s\t" << (basic_len     - c_basic_len    ) << "\t" << 100.0 - (basic_len     / c_basic_len    ) * 100.0 << "%\n";
  cout << "Packed:    " << c_packed_len    << "s\t" << packed_len    << "s\t" << (packed_len    - c_packed_len   ) << "\t" << 100.0 - (packed_len    / c_packed_len   ) * 100.0 << "%\n";
  cout << "Unaligned: " << c_unaligned_len << "s\t" << unaligned_len << "s\t" << (unaligned_len - c_unaligned_len) << "\t" << 100.0 - (unaligned_len / c_unaligned_len) * 100.0 << "%\n";
  cout << "Complex:   " << c_complex_len   << "s\t" << complex_len   << "s\t" << (complex_len   - c_complex_len  ) << "\t" << 100.0 - (complex_len   / c_complex_len  ) * 100.0 << "%\n";
  cout << "Array:     " << c_array_len     << "s\t" << array_len     << "s\t" << (array_len     - c_array_len    ) << "\t" << 100.0 - (array_len     / c_array_len    ) * 100.0 << "%\n";
  cout << "Total:     " << c_total_len     << "s\t" << total_len     << "s\t" << (total_len     - c_total_len    ) << "\t" << 100.0 - (total_len     / c_total_len    ) * 100.0 << "%\n" << endl;
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
  data.Init(k_cycles);

  cout << "Hit enter when ready...:";
  cin.ignore();

  // Run the test scenario for each type of implementation.
  cout << "Running Hg benchmark:" << endl;

  TimeValues hgTime;
  RunTest<UsingHg>(data, hgTime);
  cout << "Test completed\n" << endl;

  cout << "Running memcpy benchmark:" << endl;

  TimeValues memcpyTime;
  RunTest<UsingMemcpy>(data, memcpyTime);
  cout << "Test completed\n" << endl;

  // Display the tabulated results.
  DisplayResults( "Hg:     ", hgTime,
                  "memcpy: ", memcpyTime);

  cout << "Hit enter to exit.";
  cin.ignore();

	return 0;
}



