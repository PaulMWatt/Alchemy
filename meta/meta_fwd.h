/// @file meta/meta_fwd.h
/// 
/// Forward declarations for template types used in meta framework.
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef META_FWD_H_INCLUDED
#define META_FWD_H_INCLUDED
//  Includes *******************************************************************
#include <memory>
#include <meta/meta_util.h>

typedef unsigned char   byte_t;


#include <meta/meta_error.h>

namespace Hg
{
  // Bring the shared_ptr types into the alchemy namespace for convenience ******
  using std::tr1::shared_ptr;
  using std::tr1::weak_ptr;



  template <typename ContainerT>
  struct front
  {
    typedef Hg::MT      type;
  };

  template <typename ContainerT>
  struct pop_front
  {
    typedef Hg::MT      type; 
  };

  template <typename ContainerT,
    typename T>
  struct push_front;

  template <typename ContainerT>
  struct back;

  template <size_t Index,
    typename ContainerT,
    typename ErrorT>
  struct TypeAt;

  template <typename ContainerT>
  struct length;

  template <size_t index,
    typename ContainerT>
  struct SizeAt;

  template <typename T>
  struct SizeOf;

  template <size_t Index,
    typename ContainerT>
  struct OffsetOf;

  template <typename ContainerT>
  struct ContainerSize;

} // namespace Hg

#endif
