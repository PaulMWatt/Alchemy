/// @file Bi/Z.h
/// 
/// Big Integer class and supporting operations for arbitrarily large integers.
///             
/// The MIT License(MIT)
/// @copyright 2016 Paul M Watt
//  ****************************************************************************
#ifndef BI_Z_H_INCLUDED
#define BI_Z_H_INCLUDED

#include <Bi/Bi_defs.h>

#include <cstdint>
#include <algorithm>
#include <functional>
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
/// Basic integer, Z, that supports arbitrarily large integers.
///
class Z
{
  //  ****************************************************************************
  // TODO: Currently using a 64-bit block to handle all 32-bit calculations.
  //       This wastes 2x the space, however, it makes the calculations simpler
  //       while I am constructing the library. This will be converted to more
  //       efficient algorithms once a base set of algorithms is available.
  using type_type       = Z;
  using T               = uint64_t;
  using value_t         = std::vector<T>;
  using size_type       = value_t::size_type;
  using value_iter_t    = value_t::iterator;
  using value_riter_t   = value_t::reverse_iterator;
  using minmax_type     = std::pair<size_type, size_type>;

  using bit_size_t      = uint64_t;

  static const 
    uint8_t   k_base_size   = (sizeof(uint64_t)/2) * 8;

  static const 
    uint8_t   k_word_size   = (sizeof(uint64_t) * 8);

  static const
    uint64_t  k_upper_mask  = 0xFFFFFFFF00000000;

  static const
    uint64_t  k_lower_mask  = 0x00000000FFFFFFFF;

public:
  //  Typedefs *******************************************************************
  // TODO: these operations need to be converted to reference the Bi namespace once they are implemented.
  using plus        = std::plus<type_type>;
  using multiplies  = std::multiplies<type_type>;

  //  Construction ***************************************************************
  //  ****************************************************************************
  /// Default Constructor
  Z()
    : m_value({0})
    , m_signbit(false)
  { }

  //  ****************************************************************************
  /// Copy Constructor
  ///
  Z(const Z& rhs)
    : m_value(rhs.m_value)
    , m_signbit(rhs.signbit())
  { }

  //  ****************************************************************************
  /// Move Constructor
  ///
  Z(Z&& rhs)
    : m_value(std::move(rhs.m_value))
    , m_signbit(std::move(rhs.signbit()))
  { }
  
  //  ****************************************************************************
  /// Value Constructor for unsigned integer
  /// 
  Z(T  rhs)
    : m_signbit(false)
  {
    m_value.push_back(remove_overflow(rhs));

    T high = calculate_overflow(rhs);
    if (high > 0)
      m_value.push_back(high);
  }

  //  ****************************************************************************
  /// Value Constructor for signed integer.
  ///
  Z(int rhs)
    : m_signbit(false)
  {
    if (rhs < 0)
    {
      m_signbit = true;
      rhs       = -rhs;
    }

    m_value.push_back(static_cast<T>(rhs));
  }

  //  ****************************************************************************
  /// Value Constructor from initializer list
  /// 
  Z(const std::initializer_list<T> rhs)
    : m_signbit(false)
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
    m_value   = rhs.m_value;
    m_signbit = rhs.signbit();
    return *this;
  }

  //  ****************************************************************************
  /// Move Opperator.
  ///
  Z& operator=  (Z&& rhs)
  {
    m_value   = std::move(rhs.m_value);
    m_signbit = std::move(rhs.signbit());

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
  /// Compares two integers, Z, for equality with sign and magnitude.
  ///
  bool operator==(const Z& rhs) const
  {
    if (signbit() != rhs.signbit())
      return false;

    if (m_value != rhs.m_value) 
      return false;

    return true;
  }

  //  ****************************************************************************
  /// Compares two integers, Z, for inequality with sign and/or magnitude.
  ///
  bool operator!=(const Z& rhs) const
  {
    return !operator==(rhs);
  }

  //  ****************************************************************************
  /// Determins if this integer is less-than the supplied integer in both
  /// sign and magnitude.
  ///
  bool operator< (const Z& rhs) const
  {
    return compare(rhs) < 0;
  }

  //  ****************************************************************************
  /// Determins if this integer is less-than or equal to the supplied integer in 
  /// both sign and magnitude.
  ///
  bool operator<=(const Z& rhs) const
  {
    return compare(rhs) < 1;
  }

  //  ****************************************************************************
  /// Determins if this integer is greater-than the supplied integer in both
  /// sign and magnitude.
  ///
  bool operator> (const Z& rhs) const
  {
    return compare(rhs) > 0;
  }

  //  ****************************************************************************
  /// Determins if this integer is greeter-than or equal to the supplied integer in 
  /// both sign and magnitude.
  ///
  bool operator>=(const Z& rhs) const
  {
    return compare(rhs) > -1;
  }

  //  Arithmetic *****************************************************************
  //  ****************************************************************************
  /// Unary *negate* operation for an integer, Z.
  ///
  Z&   operator- ()
  {
    negate( );
    return *this;
  }

  //  ****************************************************************************
  /// Unary *addition* operation for an integer, Z.
  /// A value, rhs, is added to this instance. Carry operations and storage 
  /// expansion are automatically managed.
  ///
  Z&   operator+=(const Z& rhs)
  {
    add_and_substract<OpPositive<value_t>>(rhs);
    return *this;
  }

  //  ****************************************************************************
  /// Unary *subtraction* operation for an integer, Z.
  /// A value, rhs, is subtracted from this instance. Borrow operations and storage 
  /// contraction are automatically managed.
  ///
  Z&   operator-=(const Z& rhs)
  {
    add_and_substract<OpNegative<value_t>>(rhs);
    return *this;
  }

  //  ****************************************************************************
  /// Unary *multiplication* operation for an integer, Z.
  /// A value, rhs, is multiplied with this instance. 
  /// Adaptive algorithms are used for multiplication based on the size of 
  /// the underlying integer.
  ///
  /// @note: Only long-form multiplication is currently implemented.
  /// Additional planned algorithms include:
  ///   * Maratsuba
  ///   * Toom-3 and other dimensions
  ///   * Strassen (Potentially)
  ///
  /// @note: Also plan to abstract implementations to use intrinsic
  ///        compiler functions for both VS and GCC. Then have a default
  ///        implementation that breaks up native-word blocks to perform
  ///        calculations in standard C++ for portability.
  ///
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

    // Change the sign of this value if rhs is negative.
    if (rhs.signbit())
    {
      m_signbit = !signbit();
    }

    // Remove the upper blocks that equal 0.
    adjust_storage();

    return *this;
  }

  //  ****************************************************************************
  /// Unary *division* operation for an integer, Z.
  /// A value, rhs, is divided into this instance. 
  ///
  /// @return   The quotient of *this*/rhs is returned. The remainder is discarded.
  ///
  Z&   operator/=(const Z& rhs)
  {
    // Divide-by-zero (amatuer hour)
    if (rhs == 0)
    {
      // TODO: Determine how best to handle this. Possibly exception, or abort dependent upon the context.
      zero();
      return *this;
    }
    else if (rhs == 1)
    {
      // The identity element returns the dividend.
      return *this;
    }

    // If the divisor is larger, 
    // it cannot be divided into the dividend.
    Z_relation rel = compare_abs(rhs);
    if (k_cmp_less == rel)
    {
      zero();
      return *this;
    }
    else if (k_cmp_equal == rel)
    {
      *this = 1;
      return *this;
    }

    // Determine final sign.
    bool L_sign = signbit();
    m_signbit = false;

    // TODO: Using the extremely slow, yet functional "Subtract-and-shift" division algorithm for the moment.
    bit_size_t dividend_bits  = bit_size( );
    bit_size_t divisor_bits   = rhs.bit_size( );
    uint64_t   iterations     = dividend_bits - divisor_bits;
    
    if (iterations > k_base_size)
    {
      uint64_t full_words = (iterations / k_base_size) / 2;
      iterations = (full_words * k_base_size) + (iterations % k_base_size);
    }

    // Line up the divisor with the most significant bit of the dividend.
    Z remainder(0);
    Z div = rhs;

    // Change the sign of this value if rhs is negative.
    if (rhs.signbit())
    {
      div = -div;
    }

    div <<= iterations;

    // The quotient will be stored in this objects buffers.
    swap(remainder);

    for (uint64_t i = 0; i <= iterations; ++i)
    {
      // Make space for the result of this round.
      *this <<= 1;

      if (div <= remainder)
      {
        *this += 1;

        remainder -= div;
      }

      div >>= 1;
    }

    // Change the sign of this value if rhs is negative.
    m_signbit = L_sign;
    if (rhs.signbit())
    {
      m_signbit = !signbit();
    }

    // Remove the upper blocks that equal 0.
    adjust_storage();

    return *this;
  }

  //  ****************************************************************************
  /// Unary *modulus* operation for an integer, Z.
  /// A value, rhs, is divided into this instance and determines the remainder. 
  ///
  /// @return   The remainder of *this*/rhs is returned. The quotient is discarded.
  ///
  Z&   operator%=(const Z& rhs)
  {
    // Divide-by-zero (amatuer hour)
    if (rhs == 0)
    {
      // TODO: Determine how best to handle this. Possibly exception, or abort dependent upon the context.
      zero();
      return *this;
    }
    else if (rhs == 1)
    {
      // The identity element does not produce a remainder.
      zero();
      return *this;
    }

    // Determine final sign.
    bool L_sign = signbit();
    m_signbit = false;

    // If the divisor is larger, 
    // it cannot be divided into the dividend.
    Z_relation rel = compare_abs(rhs);
    if (k_cmp_less == rel)
    {
      return *this;
    }
    else if (k_cmp_equal == rel)
    {
      zero();
      return *this;
    }

    // TODO: Using the extremely slow, yet functional "Subtract-and-shift" division algorithm for the moment.
    bit_size_t dividend_bits  = bit_size( );
    bit_size_t divisor_bits   = rhs.bit_size( );
    uint64_t   iterations     = dividend_bits - divisor_bits;

    if (iterations > k_base_size)
    {
      uint64_t full_words = (iterations / k_base_size) / 2;
      iterations = (full_words * k_base_size) + (iterations % k_base_size);
    }

    // Line up the divisor with the most significant bit of the dividend.
    Z quotient(0);
    Z div = rhs;

    // Change the sign of this value if rhs is negative.
    if (rhs.signbit())
    {
      div = -div;
    }

    div <<= iterations;

    for (uint64_t i = 0; i <= iterations; ++i)
    {
      // Make space for the result of this round.
      quotient <<= 1;

      if (div <= *this)
      {
        quotient += 1;

        *this -= div;
      }

      div >>= 1;
    }

    // Change the sign of this value if rhs is negative.
    m_signbit = L_sign;
    if (rhs.signbit())
    {
      m_signbit = !signbit();
    }

    // Remove the upper blocks that equal 0.
    adjust_storage();

    return *this;
  }

  //  Logic **********************************************************************
  //  ****************************************************************************
  /// Unary *invert* or "not" operation for an integer, Z.
  /// All of the bits of this number are flipped, similar to "ones complement".
  ///
  Z&   operator~()
  {
    for (auto& word : m_value)
    {
      word = ~word;
    }

    return *this;
  }

  //  ****************************************************************************
  /// Unary logical *and* operation for an integer, Z.
  /// A value, rhs, is logically *and'ed* with this integer.
  ///
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
  /// Unary logical *or* operation for an integer, Z.
  /// A value, rhs, is logically *or'ed* with this integer.
  ///
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
  /// Unary logical *xor* operation for an integer, Z.
  /// A value, rhs, is logically *xor'ed* with this integer.
  ///
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

  //  Bit-shift Operations *******************************************************
  //  ****************************************************************************
  /// Unary logical left-shift and assign
  ///
  Z& operator<<=(uint64_t offset)
  {
    if (offset >= k_word_size)
    {
      uint64_t count = offset / k_base_size;
      for (auto i = 0; i < count; ++i)
      {
        m_value.insert(m_value.begin( ), 0);
      }

      offset %= k_word_size;
    }

    shift_left_one_word(offset);
    
    return *this;
  }

  //  ****************************************************************************
  /// Unary logical right-shift and assign
  ///
  Z& operator>>=(uint64_t offset)
  {
    if (offset >= k_word_size)
    {
      uint64_t count = offset / k_base_size;
      // Prevent too many bits from being removed.
      if (count >= m_value.size( ))
      {
        zero( );
        return *this;
      }

      for (auto i = 0; i < count; ++i)
      {
        m_value.erase(m_value.begin( ));
      }

      offset %= k_word_size;
    }

    shift_right_one_word(offset);
    
    return *this;
  }


  //  Methods ********************************************************************
  //  ****************************************************************************
  /// The contents of this integer are swapped with another integer rhs.
  ///
  void swap(Z& rhs)
  {
    std::swap(m_value, rhs.m_value);
    std::swap(m_signbit, rhs.m_signbit);
  }

  //  ****************************************************************************
  /// Clears the contents of the current integer and sets it's value to zero. 
  ///
  void clear()
  {
    m_value.clear();
    m_value.push_back(0);
    abs( );
  }

  //  ****************************************************************************
  /// Clears the contents of the current integer and sets it's value to zero. 
  /// This is an alias for the method: *clear*.
  ///
  void zero()
  {
    clear();
  }

  //  ****************************************************************************
  /// Converts this value to a strictly positive magnitude.
  ///
  void abs()
  {
    m_signbit = false;
  }

  //  ****************************************************************************
  /// Inverts the current sign for this integer.
  ///
  void negate()
  {
    if (!is_zero())
      m_signbit = !signbit();
  }

  //  ****************************************************************************
  /// Returns a copy of the raw data contents of the internal integer values.
  ///
  /// TODO: Return to this function. I do not like the idea of releasing control of internal variables. Working towards building a collection of utility functions, then factoring the interface of Z to be minimal.
  ///
  void data(value_t &values)
  {
    values = m_value;
  }

  //  ****************************************************************************
  /// Returns a copy of the raw data contents of the internal integer values.
  ///
  T low_word() const
  {
    return m_value[0];
  }

  //  ****************************************************************************
  /// Indicates of the value of this integer is negative.
  ///
  /// @return   true indicates the sign of the value is negative.
  ///           false indicates the sign of the value is positive.
  ///
  bool signbit() const
  {
    return m_signbit;
  }

  //  ****************************************************************************
  /// Copies the sign of the specified parameter to this value.
  ///
  /// @param[in]  rhs   The value to copy the sign from.
  ///
  /// @return   a reference to this instance.
  ///
  Z& copysign(const Z& rhs) 
  {
    m_signbit = rhs.signbit( );
    return *this;
  }

  //  ****************************************************************************
  /// Reports the size of the integer in bits.
  ///
  bit_size_t bit_size() const
  {
    bit_size_t count = 0;
    size_type  words = m_value.size( );

    if (words > 1)
    {
      count = words * k_base_size;
    }

    // Add the number of bits used in the highest order word.
    T msw = m_value.back(); 
    while (msw)
    {
      count++;
      msw >>= 1;
    }

    return count;
  }

private:
  //  Member data ****************************************************************
  value_t   m_value;        ///<  Buffer that contains integer data.
  bool      m_signbit;  ///<  Flag that indicates the sign of the value.

  //  Methods ********************************************************************
  //  ****************************************************************************
  void adjust_storage()
  {
    // Remove the high-order element for all
    // of the place-blocks that are zero.
    while (  m_value.size() >  1
          && m_value.back() == 0)
    {
      m_value.pop_back();
    }
  }

  //  ****************************************************************************
  //  Compares two integers, Z, for the same sign.
  //
  bool is_same_sign(const Z& rhs) const
  {
    return signbit() == rhs.signbit();
  }

  //  ****************************************************************************
  /// Indicates if this integer instance is zero.
  ///
  bool is_zero( ) const
  {
    return  m_value.size( ) == 1
        &&  m_value.at(0) == 0;
  }

  //  ****************************************************************************
  //  Compares operand to this and indicates the relative relationship of the two
  //  integers with the *Z_relation* type. This provides information relative to 
  //  both the sign and magnitude of the integer.
  //
  Z_relation compare(const Z& rhs) const
  {
    if (!is_same_sign(rhs))
    {
      return  signbit()
              ? k_cmp_less_sign_diff
              : k_cmp_greater_sign_diff;
    }

    // The result changes based on if the values are positive or negative.
    if (m_value.size() > rhs.m_value.size())
    {
      return  signbit()
              ? k_cmp_less_sign_same
              : k_cmp_greater_sign_same;
    }
    else if (m_value.size() < rhs.m_value.size())
    {
      return  signbit()
              ? k_cmp_greater_sign_same
              : k_cmp_less_sign_same;
    }

    // Start at the end (highest-order values), 
    // search for the first element that is not equal.
    typedef std::pair<value_t::const_reverse_iterator,
                      value_t::const_reverse_iterator>  riter_pair;
    riter_pair elts = std::mismatch(m_value.crbegin(), 
                                    m_value.crend(), 
                                    rhs.m_value.crbegin());

    if (elts.first == m_value.crend())
    { // All items compared, the two lists are equal.
      return k_cmp_equal;
    }

    // The elements are not equal.
    // Therefore, a direct comparison (based on sign) determines the result.
    return  (*elts.first < *elts.second) ^ signbit()
            ? k_cmp_less_sign_same
            : k_cmp_greater_sign_same;
  }

  //  ****************************************************************************
  //  Compares operand for integer, solely by the magnitude.
  //
  Z_relation compare_abs(const Z& rhs) const
  {
    // The result changes based on if the values are positive or negative.
    if (m_value.size() > rhs.m_value.size())
    {
      return k_cmp_greater;
    }
    else if (m_value.size() < rhs.m_value.size())
    {
      return k_cmp_less;
    }

    // Start at the end (highest-order values), 
    // search for the first element that is not equal.
    typedef std::pair<value_t::const_reverse_iterator,
                      value_t::const_reverse_iterator>  riter_pair;
    riter_pair elts = std::mismatch(m_value.crbegin(),
                                    m_value.crend(),
                                    rhs.m_value.crbegin());

    if (elts.first == m_value.crend())
    { // All items compared, the two lists are equal.
      return k_cmp_equal;
    }

    // The elements are not equal.
    // Therefore, a direct comparison determines the result.
    return  (*elts.first < *elts.second) 
      ? k_cmp_less
      : k_cmp_greater;
  }


  //  ****************************************************************************
  T remove_overflow(const T value)
  {
    return value & k_lower_mask;
  }

  //  ****************************************************************************
  T calculate_overflow(const T value)
  {
    return value >> k_base_size;
  }

  //  ****************************************************************************
  /// Utility function to perform carry operations for addition on integers.
  ///
  void carry_value(value_t &number)
  {
    T carry = 0;

    for (auto& place : number)
    {
      // Add carry values to the next place value
      place += carry;
      // Calculate the new carry digits.
      carry  = calculate_overflow(place);
      // Eliminate the carry digits from the current place value.
      place &= k_lower_mask;
    }
    
    if (carry != 0)
    {
      number.push_back(carry);
    }
  }

  //  ****************************************************************************
  /// Implements addition for a natural number, N.
  ///
  void accumulate(const value_t &rhs)
  {
    const size_type k_count = rhs.size();

    // Make the local buffer at least as large as the input buffer.
    if (m_value.size() < k_count)
    {
      m_value.resize(k_count);
    }

    for (size_type index = 0; index < k_count; ++index)
    {
      m_value[index] += rhs[index];
    }

    carry_value(m_value);
  }

  //  ****************************************************************************
  /// Utility function to perform borrow operations for subtraction with integers.
  ///
  void borrow_value(value_t &number)
  {
    T borrow = 1;

    for (auto& place : number)
    {
      // If the borrow value does not exist, 
      // remove one from the next place value.
      place += (borrow - 1);
      // Calculate the new borrow digits.
      borrow = calculate_overflow(place);
      // Eliminate the borrow digits from the current place value.
      place &= k_lower_mask;
    }

    adjust_storage();
  }


  //  ****************************************************************************
  /// Implements subtraction for a natural number, N.
  ///
  void disperse(const value_t &rhs)
  {
    const size_type k_count = rhs.size();
    for (size_type index = 0; index < k_count; ++index)
    {
      // Place a temporary borrow value in the upper half of the current index.
      // This will be resolved in the borrow phase.
      m_value[index] = ((0x0000000100000000) | m_value[index]) - rhs[index];
    }

    // For ripple borrows to work, every block in this value must 
    // be extended with the "loaned" borrow value.
    const size_type k_left_count = m_value.size();
    for (size_type index = k_count; index < k_left_count; ++index)
    {
      // Place a temporary borrow value in the upper half of the current index.
      // This will be resolved in the borrow phase.
      m_value[index] = ((0x0000000100000000) | m_value[index]);
    }

    borrow_value(m_value);
  }


  //  ****************************************************************************
  //  A common template for the selection of correct operation for integer sign
  //  selection with addition and subtraction operations. If the signs of the 
  //  numbers differ, it is important to determine the relative magnitude of 
  //  each integer to perform the actual calculation.
  // 
  template <typename OpT>
  void add_and_substract(const Z &rhs)
  {
    OpT op;
    if (op.adjust_sign(is_same_sign(rhs)))
    {
      op.adjust_sign(!rhs.signbit());
      accumulate(rhs.m_value);
      return;
    }
    else
    {
      Z_relation rel = compare_abs(rhs);
      if (rel == k_cmp_equal)
      {
        clear();
        return;
      }

      // TODO: Return and see about eliminating this temporary.
      Z temp(rhs);
      if (rel < k_cmp_equal)
      {
        swap(temp);
        m_signbit = op.adjust_sign(signbit());
      }

      disperse(temp.m_value);
    }
  }

  //  ****************************************************************************
  //  Shifts the contents to the left, at most, by one word.
  //
  void shift_left_one_word(uint64_t offset)
  {
    if (0 == offset)
      return;

    T bits = 0;

    uint64_t opposite = ((sizeof(T) * 8) - offset);
    for (auto &word : m_value)
    {
      uint64_t prev = bits;

      bits = word >> opposite;
      word <<= offset;
      word |= prev;
    }

    carry_value(m_value);
  }


  //  ****************************************************************************
  //  Shifts the contents to the right, at most, by one word.
  //
  void shift_right_one_word(uint64_t offset)
  {
    if (0 == offset)
      return;

    T bits = 0;

    uint64_t opposite;
    if (offset > k_base_size)
    {
      opposite = k_word_size - offset;

      for (auto iter = m_value.rbegin(); iter != m_value.rend(); ++iter)
      {
        auto &word = *iter;

        uint64_t prev = bits;

        bits = word << opposite;
        word >>= offset;
        word |= (prev >> k_base_size);
      }
    }
    else
    {
      opposite = k_base_size - offset;

      for (auto iter = m_value.rbegin(); iter != m_value.rend(); ++iter)
      {
        auto &word = *iter;

        uint64_t prev = bits;

        bits = word << opposite;
        word >>= offset;
        word |= (prev & k_lower_mask);
      }
    }

    adjust_storage();
  }

};





} // namespace Bi

#endif
