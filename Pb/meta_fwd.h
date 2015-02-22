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
#include <Pb/meta_util.h>
#include <Pb/meta_error.h>

namespace Hg
{

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

template <typename ContainerT,
          typename T>
struct push_back;

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
