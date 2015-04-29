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


#ifdef WIN32

#include <windows.h>

namespace alchemy
{
namespace benchmark
{

inline
double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

} // benchmark
} // alchemy

#else

#include <sys/time.h>
#include <sys/resource.h>

namespace alchemy
{
namespace benchmark
{

inline
double get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

} // benchmark
} // alchemy

#endif


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
    double seed = get_time();
    srand((unsigned int)seed);

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
