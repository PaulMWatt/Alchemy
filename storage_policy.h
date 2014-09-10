/// @file storage_policy.h
/// 
/// Manages allocation and access behaviors to memory buffers.
/// 
/// The storage policy is an object that manages the aspects of allocation, 
/// read and write access to a particular memory buffer. Custom storage policies
/// can control access to a buffer through its specialization of this policy.
/// 
///   Here is a list of *potential* implementations of the StoragePolicy:
/// 
///   - Fixed Array Memory Policy
///   - Hardware Memory Map Policy
///   - Read-Only Memory Policy
/// 
/// The MIT License(MIT)
/// 
/// @copyright 2014 Paul M Watt
/// 
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files(the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions :
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
/// 
//  ****************************************************************************
#ifndef STORAGE_POLICY_H_INCLUDED
#define STORAGE_POLICY_H_INCLUDED
//  Includes *******************************************************************
#include <memory>
#include <cstdint>

namespace Hg
{


//  Forward Declarations *******************************************************
using std::tr1::shared_ptr;

//  ****************************************************************************
/// Storage Policy implementation for contiguous memory buffers. 
/// 
/// @tparam IsBufferedT       Indicates if the StoragePolicy desires data to
///                           be buffered, or accessed on demand.
///
/// Note: The policy itself is not responsible, and does not buffer the data.
///       It is an indication to users of the policy, for how the best way to
///       access the storage memory.
///
///       For example, storage policies developed to interface directly with
///       hardware mapped memory access would indicate not to be buffered.
///       However, a network packet buffer, which can vary in size between
///       calls would indicate buffering is preferred.
///                           
template <bool     IsBufferedT>
struct StoragePolicy
  : std::integral_constant<bool, IsBufferedT>
{
  typedef unsigned char                 data_type;
  typedef data_type*                    pointer;
  typedef const data_type*              const_pointer;
  typedef std::shared_ptr<data_type>    s_pointer;
  typedef std::weak_ptr<data_type>      w_pointer;
  
  //  **************************************************************************
  /// Allocates a new storage buffer for this policy.
  /// 
  /// @param size             The number of bytes requested for the allocation.
  /// 
  /// @return       A shared_ptr that contains the allocated container object.
  ///               If the allocation failed, the return value will be invalid.
  ///      
  static
  s_pointer allocate(size_t size)
  {
    s_pointer spBuffer(new(std::nothrow) data_type[size]);
    return spBuffer;
  }

  //  **************************************************************************
  /// Releases memory buffers allocated through this policy.
  /// 
  /// @param size             The number of bytes requested for the allocation.
  /// 
  static
    void deallocate(s_pointer &spBuffer)
  {
    // No real action for this storage_policy.
    // Clear the pointer anyway.
    spBuffer.reset();
  }

  //  **************************************************************************
  /// Performs a storage read operation for this policy.
  /// 
  /// @param sp_buffer        A shared pointer to a buffer previously 
  ///                         allocated by this storage policies Allocate
  ///                         member function.
  /// @param p_storage        The source memory buffer to read from.
  /// @param size             The number of elements read from the buffer.
  /// @param offset           A starting offset from the beginning of the 
  ///                         specified read/write buffer.
  /// 
  /// @return       This function will always return true.
  ///               Other policy implementations may need to indicate failure.
  ///               
  static
  bool read ( const_pointer pBuffer, 
              void*         pStorage,
              size_t        size,
              ptrdiff_t     offset)
  {
    ::memcpy( pStorage,
              pBuffer + offset, 
              size);
    return true;
  }

  //  **************************************************************************
  /// Performs a storage write operation for this policy.
  /// 
  /// @param sp_buffer        A shared pointer to a buffer previously 
  ///                         allocated by this storage policies Allocate
  ///                         member function.
  /// @param p_storage        The source memory buffer to supply the data
  ///                         written into sp_buffer;
  /// @param size             The number of elements write into the buffer.
  /// @param offset           A starting offset from the beginning of the 
  ///                         specified read/write buffer.
  /// 
  /// @return       This function will always return true.
  ///               Other policy implementations may need to indicate failure.
  ///               
  static
  bool write( pointer           pBuffer, 
              const void*       pStorage,
              size_t            size,
              ptrdiff_t         offset)
  {
    ::memcpy( pBuffer + offset,
              pStorage,
              size);
    return true;
  }
};

typedef StoragePolicy<false>       DirectMemStoragePolicy;
typedef StoragePolicy<true>        BufferedStoragePolicy;

} // namespace Hg

#endif
