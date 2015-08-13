/// @file Pb/optional.h
/// 
/// Utilty class for representing optional data fields in protocols.
/// 
/// The MIT License(MIT)
/// @copyright 2015 Paul M Watt
//  ****************************************************************************
#ifndef OPTIONAL_H_INCLUDED
#define OPTIONAL_H_INCLUDED
//  includes *******************************************************************
#include <Pb/meta_util.h>
#include <Pb/type_list.h>
#include <array>
#include <vector>

namespace Hg
{

//  ****************************************************************************
/// Optional field base functionality.
///
class base_optional
  : public optional_trait
{
public:
  //  **************************************************************************
  /// Default Constructor
  ///
  base_optional()
    : m_is_valid(false)
  { }

  //  **************************************************************************
  /// Indicates when this field is valid
  ///
  /// @return  false: When this field does not contain a valid value.
  ///           true: The value in this field is valid.
  ///
  bool is_valid() const
  {
    return m_is_valid;
  }

  //  **************************************************************************
  /// Flags the state of this object as valid.
  ///
  void valid()
  {
    m_is_valid = true;
  }

  //  **************************************************************************
  /// Flags the state of this object to the same state as another optional field.
  ///
  void valid(const base_optional& rhs)
  {
    m_is_valid = rhs.m_is_valid;
  }

  //  **************************************************************************
  /// Clears the valid state of this object.
  ///
  void reset()
  {
    m_is_valid = false;
  }

private:
  bool  m_is_valid;
};

//  ****************************************************************************
/// Data type to represent optional data fields in message structures.
///
/// Message structures often contain optional data fields that are not always
/// present. This object contains functions to report and manage the valid
/// state of any type of value.
///
template< typename T >
class optional
  : public optional_trait
{
public:
  /// The type of the optional value managed by this object. 
  using optional_type = T;
  using value_type = T;
};

//  ****************************************************************************
template< typename T, size_t N >
class optional <std::array<T,N> >
  : public optional_trait
{
public:
  /// The type of the optional value managed by this object. 
  using optional_type = std::array<T,N>;
  using value_type = typename optional_type::value_type;
};

//  ****************************************************************************
template< typename T, typename A >
class optional <std::vector<T,A> >
  : public optional_trait
{
public:
  /// The type of the optional value managed by this object. 
  using optional_type = std::vector<T,A>;
  using value_type = typename optional_type::value_type;
};


//  ****************************************************************************
/// Extracts the underlying value type for an optional field.
///
template< size_t    IdxT,
          typename  FormatT 
        >
struct optional_type_at
{
  //  **************************************************************************
  using type = typename Hg::type_at<IdxT, FormatT>::type::optional_type;
};

//  **************************************************************************
/// Template alias to access the meta-operation, optional_type_at.
///
template<size_t IdxT, typename FormatT>
using optional_type_at_t = typename optional_type_at<IdxT,FormatT>::type;


} // namespace Hg

#endif
