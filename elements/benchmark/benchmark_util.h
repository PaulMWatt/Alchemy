/// @file benchmark_util.h
/// 
/// Collection of utility functions to simplify benchmark tests. 
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BENCHMARK_UTIL_H_INCLUDED
#define BENCHMARK_UTIL_H_INCLUDED
//  Includes *******************************************************************
#include <algorithm>
#include <chrono>


namespace alchemy
{
namespace benchmark
{

using time_point = std::chrono::time_point<std::chrono::system_clock>;
using duration   = std::chrono::duration<double>;

inline
time_point get_time()
{
  return std::chrono::system_clock::now();
}

} // benchmark
} // alchemy


namespace alchemy
{
namespace benchmark
{

//  ****************************************************************************
class DataBuffer
{
public:

  //  **************************************************************************
  DataBuffer()
    : m_pBuffer(0)
    , m_size(0)
    , m_pCurrent(0)
  { }

  //  **************************************************************************
  DataBuffer(size_t len) 
    : m_pBuffer(new char[len])
    , m_size(len)
    , m_pCurrent(m_pBuffer)
  { }

  //  **************************************************************************
  void Init(size_t size)
  {
    // Attempt to allocate the requested amount of memory.
    Term();

    m_pBuffer = new char[size];
    m_size = size;

    for (size_t index = 0; index < size; ++index)
    {
      char item = char(rand() % 256);
      m_pBuffer[index] = item;
    }
  }

  //  **************************************************************************
  void Term()
  {
    delete[] m_pBuffer;
    m_pBuffer = 0;
    m_size = 0;
    m_pCurrent = 0;
  }

  //  **************************************************************************
  size_t Size() const
  {
    return m_size;
  }

  //  **************************************************************************
  void* GetBytes(size_t count)
  {
    void* pRetVal = (void*)(m_pCurrent);
    std::advance(m_pCurrent, count);

    return pRetVal;
  }

  //  **************************************************************************
  void  Reset()
  {
    if (!Size())
    {
      return;
    }

    m_pCurrent = m_pBuffer;
  }

  //  **************************************************************************
  void  Restart()
  {
    m_pCurrent = m_pBuffer;
  }

  //  **************************************************************************
  int Value()
  {
    size_t index = m_pBuffer[0];
    return m_pBuffer[index];
  }

private:
  size_t    m_size;
  char*     m_pBuffer;
  char*     m_pCurrent;

};

} // benchmark
} // alchemy




#endif
