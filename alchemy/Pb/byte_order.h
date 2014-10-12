/// @file meta/byte_order.h
/// 
/// Defines constructs that help manage byte-order conversion.
/// 
/// This file contains definitions, utilities and policy implementations
/// to deal with byte-order characteristics for different machine architectures.
/// 
/// The final structure of byte-order conversion is an aggregate of two concepts 
/// into a set of user classes that can be used indiscriminately for the conversion
/// of all data:\n
/// 
/// 1) **EndianSwap<T>**    This is a generic function that contains specializations
///                         for each type that may require byte-order management.
///                         The generic version performs no operations. Calling
///                         this function a second time with the result of the
///                         first call, will result with a value equal to the 
///                         input of the first call.\n
///                         
/// 2) **EndianType<>**     This structure allows a discriminating ID to be 
///                         associated with endian swap operations. 
///                         Two ID's are specified to discriminate between 
///                         Big-Endian and Little-Endian byte-orders. This 
///                         structure provides a function **swap_order**, which
///                         will swap the byte-order of a value type according
///                         to the appropriate context.\n
///           
/// The user classes, **HostByteOrderT** and **NetByteOrderT**, provide the 
/// appropriate context for converting between byte-orders. Both of these 
/// collectors provide the same interfaces with two functions:\n
///   - **to_host**\n Converts the value to host order for NetByteOrderT and a no-op for HostByteOrderT\n
///   - **to_network**\n Converts the value to network order for HostByteOrderT and a no-op for NetByteOrderT\n
/// 
/// Users should use these constructs for byte-order conversion:
///   - Hg::HostByteOrder\n
///   - Hg::NetByteOrder
///   - Hg::BigEndian
///   - Hg::LittleEndian
/// 
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef BYTE_ORDER_H_INCLUDED
#define BYTE_ORDER_H_INCLUDED
//  Includes *******************************************************************
#include <Pb/compiler.h>

namespace Hg
{

//  Constants ******************************************************************
/// This enumeration set contains definitions for each type of endian processor
/// supported by these conversion functions. 
/// 
enum Endianess
{
  k_big_endian    = BL_BIG_ENDIAN,      ///< Indicates Big-Endian byte-order
  k_little_endian = BL_LITTLE_ENDIAN    ///< Indicates Little-Endian byte-order
};

///< Constant indicates machine endianess.
const Endianess k_endianess = Endianess(BL_ENDIANESS); 

namespace convert
{

//  Constants ******************************************************************
const size_t k_64bits = 64;             ///< Bit-shift constant, 8-bytes
const size_t k_56bits = 56;             ///< Bit-shift constant, 7-bytes
const size_t k_48bits = 48;             ///< Bit-shift constant, 6-bytes
const size_t k_40bits = 40;             ///< Bit-shift constant, 5-bytes
const size_t k_32bits = 32;             ///< Bit-shift constant, 4-bytes
const size_t k_24bits = 24;             ///< Bit-shift constant, 3-bytes
const size_t k_16bits = 16;             ///< Bit-shift constant, 2-bytes
const size_t k_8bits  = 8;              ///< Bit-shift constant, 1-byte

} // namespace convert

//  ****************************************************************************
/// A generic implementation that performs no action.
/// 
/// No change is required the for generic case of EndianSwap.
/// Specialized definitions of this function will perform endian swap operations.
///
/// @param input    Input value to perform endian-swap operation.
/// @return         Simply return the input value.  
/// 
///
template <typename T>
T EndianSwap(T input)
{
  return input;
}

//  ****************************************************************************
/// Endian Swap (Specialization, uint16_t) 
/// 
/// Swaps the current byte order between endian formats for a 16-bit value.  
///
template <>
uint16_t EndianSwap(uint16_t input)
{
  return  (input >> convert::k_8bits)
        | (input << convert::k_8bits);
}

//  ****************************************************************************
/// Endian Swap (Specialization, int16_t) 
/// 
/// Swaps the current byte order between endian formats for a 16-bit value.  
///
template <>
int16_t EndianSwap(int16_t input)
{
  return static_cast<int32_t> (
                                EndianSwap(static_cast<uint16_t>(input))
                              );
}

//  ****************************************************************************
/// Endian Swap (Specialization, uint32_t) 
/// 
/// Swaps the current byte order between endian formats for a 32-bit value.
/// 
template <>
uint32_t EndianSwap(uint32_t input)
{
  return  (input >> convert::k_24bits)
        | ((input << convert::k_8bits) & 0x00FF0000)
        | ((input >> convert::k_8bits) & 0x0000FF00)
        | (input << convert::k_24bits);
}

//  ****************************************************************************
/// Endian Swap (Specialization, int32_t) 
/// 
/// Swaps the current byte order between endian formats for a 32-bit value.  
///
template <>
int32_t EndianSwap(int32_t input)
{
  return static_cast<int32_t> (
                                EndianSwap(static_cast<uint32_t>(input))
                              );
}

//  ****************************************************************************
/// Endian Swap (Specialization, uint64_t)
/// 
/// Swaps the current byte order between endian formats for a 64-bit value.
///
template <>
uint64_t EndianSwap(uint64_t input)
{
  return  (input >> (convert::k_56bits))
        | (input >> (convert::k_40bits) & 0x000000000000FF00LL)
        | (input >> (convert::k_24bits) & 0x0000000000FF0000LL)
        | (input >> (convert::k_8bits)  & 0x00000000FF000000LL)
        | (input << (convert::k_8bits)  & 0x000000FF00000000LL)
        | (input << (convert::k_24bits) & 0x0000FF0000000000LL)
        | (input << (convert::k_40bits) & 0x00FF000000000000LL)
        | (input << (convert::k_56bits));
}

//  ****************************************************************************
/// Endian Swap (Specialization, int64_t) 
/// 
/// Swaps the current byte order between endian formats for a 64-bit value.  
///
template <>
int64_t EndianSwap(int64_t input)
{
  return static_cast<int64_t> (
                                EndianSwap(static_cast<uint64_t>(input))
                              );
}


#if defined(_WIN32) && defined(_HAS_TR1)
//  ****************************************************************************
/// Endian Swap (Specialization, compiler does not recognize int as long) 
/// 
template <>
unsigned int EndianSwap(unsigned int input)
{
  return EndianSwap<unsigned long>(input);
}
#endif

//  ****************************************************************************
/// Policy class used to perform byte-order operations.
/// 
/// The EndianType struct is a policy class that provides the swap function.
/// The swap capability is indicated by t0he isSwap template parameter.
/// 
/// @param <typename T>       The type of variable to perform the swap upon.
/// @param <bool isSwap>      Indicates if the swap should be performed for
///                           this EndianType.
///                           - **true:** Indicates a swap is required.
///                           - **false:** Will not swap byte-order.
/// 
template <typename T, bool isSwap>
struct EndianType
{
  //  **************************************************************************
  /// Swaps the byte-order of value T based on platform endianess.
  /// 
  /// This swap function will instantiate the proper version of EndianSwap based
  /// on the current EndianType and input value type T. If T does not contain
  /// a EndianSwap specialization, no operation will be performed.
  /// 
  /// @param value              The value whose byte-order will be swapped.
  /// @return                   The input parameter **value** 
  ///                           with a swapped byte-order.
  /// 
  static T swap_order(const T& value)
  {
    return EndianSwap(value);
  }
};

//  ****************************************************************************
/// Policy class used to perform byte-order operations.
/// 
/// This type specialization that uses a swap operation that performs 
/// a no-op on the input value.
///  
template <typename T>
struct EndianType<T, false>
{
  //  **************************************************************************
  /// A no-op version of swap. 
  /// This EndianType matches the target byte-order type.
  /// 
  static T swap_order(const T& value)
  {
    return value;
  }
};

//  ****************************************************************************
/// Byte-order management policy for network data transfers.
/// 
/// This class represents the host byte-order behavior and 
/// provides the capability to convert to a value type in network byte-order.\n
/// Host Byte-Order is determined by the platform byte-order.
/// 
/// Usage:
/// ~~~{.cpp}
/// using std::cout;
/// using std::hex;
/// 
/// long hostInput   = 0x12345678;
/// 
/// cout << hex              << "HostByteOrder: " << netInput << "\n";
/// cout << "to_host():    " << Hg::HostByteOrder::to_host(hostInput)   << "\n";
/// cout << "to_network(): " << Hg::HostByteOrder::to_network(hostInput)<< "\n";
/// 
/// // Prints to the console:
/// //    HostByteOrder: 12345678
/// //    to_host:       12345678
/// //    to_network:    78563412
/// ~~~
///  
template <Endianess E>
struct HostByteOrderT
{
  static const 
    Endianess order   = E;
          
  static const
    bool      is_host = true;

  template <typename T>
  static 
    T to_host(const T &input)
  {
    return input;
  }

  template <typename T>
  static
    T to_network(const T& input)
  {
    // Swapping will be required if the host format is not Big Endian.
    return EndianType<T, (k_big_endian != order)>::swap_order(input);
  }

protected:
  // Protected Destructor prevents the deletion of an object from the policy ***
  ~HostByteOrderT() {}
};

//  ****************************************************************************
/// Byte-order management policy for network data transfers.
/// 
/// This class represents the network byte-order behavior and
/// provides the capability to convert to a value type in host byte-order.\n
/// Network Byte-Order is defined as Big Endian.
/// 
/// Usage:
/// ~~~{.cpp}
/// using std::cout;
/// using std::hex;
/// 
/// long netInput   = 0x12345678;
/// 
/// cout << hex              << "NetByteOrder: " << netInput << "\n";
/// cout << "to_host():    " << Hg::NetByteOrder::to_host(netInput)   << "\n";
/// cout << "to_network(): " << Hg::NetByteOrder::to_network(netInput)<< "\n";
/// 
/// // Prints to the console:
/// //    NetByteOrder: 12345678
/// //    to_host:      78563412
/// //    to_network:   12345678
/// ~~~
/// 
template <Endianess E>
struct NetByteOrderT
{
  static const 
    Endianess order   = E;
          
  static const
    bool      is_host = false;

  template <typename T>
  static 
    T to_host(const T &input)
  {
    // Swapping will be required if the native format is not Big Endian.
    return EndianType<T, (k_big_endian != order)>::swap_order(input);
  }

  template <typename T>
  static 
    T to_network(const T &input)
  {
    return input;
  }

protected:
  // Protected Destructor prevents the deletion of an object from the policy ***
  ~NetByteOrderT() {}
};

// Pre-defined types to represent Host, Network, big and little byte order 
// for the current platform.
typedef HostByteOrderT<k_endianess>   HostByteOrder;
typedef NetByteOrderT <k_endianess>   NetByteOrder;
typedef HostByteOrderT<k_endianess>   BigEndian;
typedef NetByteOrderT <k_endianess>   LittleEndian;

} // namespace Hg

#endif
