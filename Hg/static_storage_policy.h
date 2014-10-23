/// @file storage_policy.h
/// 
/// Manages allocation and access behaviors to fixed-size memory buffers.
/// 
/// The MIT License(MIT)
/// 
/// @copyright 2014 Paul M Watt
/// 
//  ****************************************************************************
#ifndef STATIC_STORAGE_POLICY_H_INCLUDED
#define STATIC_STORAGE_POLICY_H_INCLUDED
//  Includes *******************************************************************
#include <storage_policy.h>

namespace Hg
{

//  ****************************************************************************
/// Storage Policy implementation for fixed-size memory buffers. 
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
struct StaticStoragePolicy
  : std::integral_constant<bool, IsBufferedT>
{
  typedef unsigned char                 data_type;
  typedef data_type*                    pointer;
  typedef const data_type*              const_pointer;
  typedef std::shared_ptr<data_type>    s_pointer;
  typedef std::weak_ptr<data_type>      w_pointer;
  
  //  **************************************************************************
  /// Not Implemented.
  /// This is a fixed-size static storage policy;
  /// 
  /// @return       0.
  ///      
  static
  s_pointer allocate(size_t size)
  {
    return 0;
  }

  //  **************************************************************************
  /// Not Implemented.
  /// This is a fixed-size static storage policy.
  /// 
  static
    void deallocate(s_pointer &spBuffer)
  { }

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
  bool read ( const_pointer   pBuffer, 
              void*           pStorage,
              size_t          size,
              std::ptrdiff_t  offset)
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
              std::ptrdiff_t    offset)
  {
    ::memcpy( pBuffer + offset,
              pStorage,
              size);
    return true;
  }
};

typedef StaticStoragePolicy<true>     BufferedStaticStoragePolicy;

} // namespace Hg

#endif
