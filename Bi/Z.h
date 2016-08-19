/// @file Bi/Z.h
/// 
/// Big Integer class and supporting operations for arbitrarily large integers.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_Z_H_INCLUDED
#define BI_Z_H_INCLUDED

#include <cstdint>
#include <algorithm>
#include <initializer_list>
#include <utility>
#include <vector>

// TODO: Once the basic class is up and running, I plan to convert this class to a template
//       that accepts its base integer type, as well as a policy trait that 
//       dictates what type of security to enforce. This will allow one implementation
//       to support both fast and secure implementation types.

namespace Bi
{

//  ****************************************************************************
/// Basic Integer that supports arbitrarily large integers.
///
class Z
{
  //  ****************************************************************************
  typedef uint32_t                          T;
  typedef std::vector<T>                    value_t;
  typedef value_t::size_type                size_type;
  typedef std::pair<size_type, size_type>   minmax_type;

  static const 
    uint8_t   k_place_bits  = (sizeof(uint64_t)/2) * 8;

  static const
    uint64_t  k_upper_mask  = 0xFFFFFFFF00000000;

  static const
    uint64_t  k_lower_mask  = 0x00000000FFFFFFFF;

public:
  //  Construction ***************************************************************
  //  ****************************************************************************
  /// Default Constructor
  Z()
    : m_is_positive(true)
  { }

  //  ****************************************************************************
  /// Copy Constructor
  ///
  Z(const Z& rhs)
    : m_value(rhs.m_value)
    , m_is_positive(rhs.m_is_positive)
  { }

  //  ****************************************************************************
  /// Move Constructor
  ///
  Z(Z&& rhs)
    : m_value(std::move(rhs.m_value))
    , m_is_positive(std::move(rhs.m_is_positive))
  { }
  
  //  ****************************************************************************
  /// Value Constructor for unsigned integer
  /// 
  Z(T  rhs)
    : m_is_positive(true)
  {
    m_value.push_back(remove_carry(rhs));

    T high = calculate_carry(rhs);
    if (high > 0)
      m_value.push_back(high);
  }

  //  ****************************************************************************
  /// Value Constructor for signed integer (Will be converted to unsigned).
  ///
  Z(int rhs)
    : m_is_positive(true)
  {
    if (rhs < 0)
    {
      m_is_positive = false;
      rhs           = -rhs;
    }

    m_value.push_back(static_cast<T>(rhs));
  }

  //  ****************************************************************************
  /// Value Constructor from initializer list
  /// 
  Z(std::initializer_list<T> rhs)
    : m_is_positive(true)
    , m_value(rhs)
  { }

  //  ****************************************************************************
  /// Constructs an unsigned integer from a sequence of hexadecimal values.
  ///
  Z(const uint8_t hex_value[], size_t len)
  {
    m_value.resize(len);
    ::memcpy(&m_value[0], hex_value, len);
  }


  //  ****************************************************************************
  /// Destructor
  ///
  ~Z()
  { }

  //  ****************************************************************************
  /// Assignment operator.
  ///
  Z&  operator=  (const Z& rhs)
  {
    m_value       = rhs.m_value;
    m_is_positive = rhs.m_is_positive;
    return *this;
  }

  //  ****************************************************************************
  /// Move Opperator.
  ///
  Z& operator=  (Z&& rhs)
  {
    m_value       = std::move(rhs.m_value);
    m_is_positive = std::move(rhs.m_is_positive);

    return *this;
  }

  //  ****************************************************************************
  /// Assignment Opperator:= type T.
  ///
  Z& operator=  (T rhs)
  {
    *this = Z(rhs);
    return *this;
  }

  //  ****************************************************************************
  /// Assignment Opperator:= integer.
  ///
  Z& operator=  (int rhs)
  {
    *this = Z(rhs);
    return *this;
  }

  //  Operators ******************************************************************
  //  Comparison *****************************************************************
  //  ****************************************************************************
  bool operator==(const Z& rhs) const
  {
    if (m_is_positive != rhs.m_is_positive)
      return false;

    if (m_value != rhs.m_value) 
      return false;

    return true;
  }

  //  ****************************************************************************
  bool operator!=(const Z& rhs) const
  {
    return !operator==(rhs);
  }

  //  ****************************************************************************
  bool operator< (const Z& rhs) const
  {
    if (m_is_positive == rhs.m_is_positive)
    {
// TODO: Complete this implementation for the less comparison of the data string. 
      if (m_value != rhs.m_value)
        return false;
    }
    else if (m_is_positive)
    {
      // Then rhs is negative, and therefore, less than this.
      return false;
    }

    return true;
  }

  //  ****************************************************************************
  bool operator<=(const Z& rhs) const
  {
    // TODO: This will not be as efficient as it could be. Rewrite with it's own impl.
    return operator<(rhs) || operator==(rhs);
  }

  //  ****************************************************************************
  bool operator> (const Z& rhs) const
  {
    return !operator<=(rhs);
  }

  //  ****************************************************************************
  bool operator>=(const Z& rhs) const
  {
    return !operator<(rhs);
  }


  //  Arithmetic *****************************************************************
  //  ****************************************************************************
  Z&   operator- ()
  {
    m_is_positive = !m_is_positive;
    return *this;
  }

  //  ****************************************************************************
  Z&   operator+=(const Z& rhs)
  {
    accumulate(rhs.m_value);
    return *this;
  }

  //  ****************************************************************************
  Z&   operator-=(const Z& rhs)
  {
    const size_type k_count = std::min(m_value.size(), rhs.m_value.size());
    for (size_type index = 0; index < k_count; ++index)
    {
      m_value[index] -= rhs.m_value[index];
    }

    carry_value(m_value);

    return *this;
  }

  //  ****************************************************************************
  Z&   operator*=(const Z& rhs)
  {
    const size_type k_count = std::min(m_value.size(), rhs.m_value.size());

    size_t place = 0;
    Z sum;
    for (auto operand : rhs.m_value)
    {
      // Shift the initial values for the current multiplication row
      // to the left by the place column for the current multiplicand.
      value_t temp(place);
      for (auto self : m_value)
      {
        temp.push_back(self*operand);
      }

      sum.accumulate(temp);
      place++;
    }

    m_value = sum.m_value;

    // If the signs between the two types do not match, flip them.
    if (m_is_positive != rhs.m_is_positive)
    {
      m_is_positive = !m_is_positive;
    }

    return *this;
  }

  //  ****************************************************************************
  Z&   operator/=(const Z& rhs)
  {
    const size_type k_count = std::min(m_value.size(), rhs.m_value.size());
    for (size_type index = 0; index < k_count; ++index)
    {
      m_value[index] /= rhs.m_value[index];
    }

    carry_value(m_value);

    return *this;
  }

  //  ****************************************************************************
  Z&   operator%=(const Z& rhs)
  {
    const size_type k_count = std::min(m_value.size(), rhs.m_value.size());
    for (size_type index = 0; index < k_count; ++index)
    {
      m_value[index] %= rhs.m_value[index];
    }

    carry_value(m_value);

    return *this;
  }

  //  Logic **********************************************************************
  //  ****************************************************************************
  Z&   operator~()
  {
    for (auto& word : m_value)
    {
      word = ~word;
    }

    return *this;
  }

  //  ****************************************************************************
  Z&   operator&=(const Z& rhs)
  {
    const size_type k_count = std::min(m_value.size(), rhs.m_value.size());
    for (size_type index = 0; index < k_count; ++index)
    {
      m_value[index] &= rhs.m_value[index];
    }

    // Truncate the current value to match the length of the shortest operand.
    m_value.resize(k_count);

    return *this;
  }

  //  ****************************************************************************
  Z&   operator|=(const Z& rhs)
  {
    const minmax_type k_minmax = std::minmax(m_value.size(), rhs.m_value.size());

    m_value.resize(k_minmax.second, 0ull);
    for (size_type index = 0; index < k_minmax.first; ++index)
    {
      m_value[index] |= rhs.m_value[index];
    }

    return *this;
  }

  //  ****************************************************************************
  Z&   operator^=(const Z& rhs)
  {
    const minmax_type k_minmax = std::minmax(m_value.size(), rhs.m_value.size());

    m_value.resize(k_minmax.second, 0ull);
    for (size_type index = 0; index < k_minmax.first; ++index)
    {
      m_value[index] ^= rhs.m_value[index];
    }

    return *this;
  }

  //  Methods ********************************************************************
  //  ****************************************************************************
  void swap(Z& rhs)
  {
    std::swap(m_value, rhs.m_value);
    std::swap(m_is_positive, rhs.m_is_positive);
  }

  void data(value_t &values)
  {
    values = m_value;
  }

private:
  //  Member data ****************************************************************
  value_t   m_value;        ///<  Buffer that contains integer data.
  bool      m_is_positive;  ///<  Flag that indicates the sign of the value.

  //  Methods ********************************************************************
  //  ****************************************************************************
  void adjust_storage()
  {
    for (int index = (int)m_value.size() - 1; index >= 0; --index)
    {
      if (m_value[index] != 0)
        return;

      m_value.resize(index-1);
    }

  }


  //  ****************************************************************************
  T remove_carry(const T value)
  {
    return value & k_lower_mask;
  }

  //  ****************************************************************************
  T calculate_carry(const T value)
  {
    return (value & k_lower_mask) >> k_place_bits;
  }

  //  ****************************************************************************
  void carry_value(value_t &number)
  {
    T carry = 0;

    for (auto& place : number)
    {
      // Add carry values to the next place value
      place += carry;
      // Calculate the new carry digits.
      carry  = calculate_carry(place);
      // Eliminate the carry digits from the current place value.
      place &= k_lower_mask;
    }
    
    if (carry != 0)
    {
      number.push_back(carry);
    }
  }

  //  ****************************************************************************
  void accumulate(const value_t &input)
  {
    const size_type k_count = input.size();

    // Make the local buffer at least as large as the input buffer.
    if (m_value.size() < k_count)
    {
      m_value.resize(k_count);
    }

    for (size_type index = 0; index < k_count; ++index)
    {
      m_value[index] += input[index];
    }

    carry_value(m_value);
  }


};


//  ****************************************************************************
inline
Z operator+(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val += rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator-(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val -= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator*(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val *= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator/(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val /= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator%(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val %= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator&(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val &= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator|(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val |= rhs;

  return ret_val;
}

//  ****************************************************************************
inline
Z operator^(const Z& lhs, const Z& rhs)
{
  Z ret_val(lhs);
  ret_val ^= rhs;

  return ret_val;
}

} // namespace Bi

#endif
