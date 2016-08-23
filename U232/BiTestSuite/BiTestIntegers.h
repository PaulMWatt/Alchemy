/// @file BiTestSuite.h
///
/// Test Fixture for Lithium library -
/// (Bi) Big Integers
/// 
/// @author Paul
/// @date   2016.8.5: Paul    -- Initial release.
///
/// TODO: Update with an appropriate license copyright 2016
///
///  Verify data with these TEST ASSERTIONS:
///
///  TS_FAIL(message):                        Fail unconditionally
///  TS_ASSERT(expr):                         Verify (expr) is true
///  TS_ASSERT_EQUALS(x, y):                  Verify (x==y)
///  TS_ASSERT_SAME_DATA(x, y, size):         Verify two buffers are equal
///  TS_ASSERT_DELTA(x, y, d):                Verify (x==y) up to d
///  TS_ASSERT_DIFFERS(x, y):                 Verify !(x==y)
///  TS_ASSERT_LESS_THAN(x, y):               Verify (x<y)
///  TS_ASSERT_LESS_THAN_EQUALS(x, y):        Verify (x<=y)
///  TS_ASSERT_PREDICATE(P, x):               Verify P(x)
///  TS_ASSERT_RELATION(R, x, y):             Verify x R y, ex. TS_ASSERT_RELATION(std::greater, x, y);
///  TS_ASSERT_THROWS(expr, type):            Verify that (expr) throws a specific type of exception.
///  TS_ASSERT_THROWS_EQUALS(expr, arg, x, y):Verify type and value of what (expr) throws
///  TS_ASSERT_THROWS_ANYTHING(expr):         Verify that (expr) throws an exception
///  TS_ASSERT_THROWS_NOTHING(expr):          Verify that (expr) doesn't throw anything
///  TS_WARN(message):                        Print message as a warning
///  TS_TRACE(message):                       Print message as an information message
///
//  ****************************************************************************
#ifndef BiTestIntegers_H_INCLUDED
#define BiTestIntegers_H_INCLUDED

// TODO: Will be converting the values to read the blocks in big-endian order, for now sending in as little-ending as that logic is not in the object yet.

#include <cstdint>
#include <vector>
#include <initializer_list>

typedef uint64_t                        z_base;

typedef std::vector<z_base>             z_type;
typedef std::initializer_list<z_base>   z_list;

//  Constants for use with tests ************************************************
const int      k_signed = -1024;
const uint64_t k_unsigned = 0x400;

const uint64_t k_A = 0x12345678;
const uint64_t k_B = 0x9ABCDEF0;
const uint64_t k_C = 0x13579BDF;
const uint64_t k_D = 0x2468ACE0;
const uint64_t k_E = 0xFEDCBA98;
const uint64_t k_F = 0x76543210;

const uint64_t k_odd    = 0x5555555555555555; // binary: 0101
const uint64_t k_even   = 0xAAAAAAAAAAAAAAAA; // binary: 1010
const uint64_t k_all    = 0xFFFFFFFFFFFFFFFF; // binary: 1111
const uint64_t k_zero   = 0x0000000000000000; // binary: 0000

const uint64_t k_one    = 0x00000001;
const uint64_t k_two    = 0x00000002;
const uint64_t k_three  = 0x00000003;
const uint64_t k_four   = 0x00000004;
const uint64_t k_five   = 0x00000005;
const uint64_t k_six    = 0x00000006;
const uint64_t k_seven  = 0x00000007;
const uint64_t k_eight  = 0x00000008;
const uint64_t k_nine   = 0x00000009;
const uint64_t k_ten    = 0x0000000A;
          
const uint64_t k_1k     = 0x00000400;
const uint64_t k_2k     = 0x00000800;
const uint64_t k_4k     = 0x00001000;
const uint64_t k_8k     = 0x00002000;
const uint64_t k_16k    = 0x00004000;
          
const uint64_t k_1M     = 0x000F4240;
const uint64_t k_1B     = 0x3B9ACA00;
const uint64_t k_4B     = 0xEE6B2800;
          
const uint64_t k_8B_00  = 0xDCD65000;
const uint64_t k_8B_01  = 0x00000001;
const uint64_t k_8B     = 0x00000001DCD65000;
const z_list   k_8B_z   = {0xDCD65000, 0x00000001};
//const z_list   k_8B_z = {0x00000001, 0xDCD65000};


const uint32_t k_16B_00 = 0xB9ACA000;
const uint32_t k_16B_01 = 0x00000003;
const uint64_t k_16B    = 0x00000003B9ACA000;
const z_list   k_16B_z  = {0xB9ACA000, 0x00000003};
//const z_list   k_16B_z = {0x00000003, 0xB9ACA000};

const uint32_t k_24B_00 = 0x9682F000;
const uint32_t k_24B_01 = 0x00000005;
const uint64_t k_24B    = 0x000000059682F000;
const z_list   k_24B_z  = {0x9682F000, 0x00000005};
//const z_list   k_24B_z = {0x00000005, 0x9682F000};

const uint32_t k_32B_00 = 0x73594000;
const uint32_t k_32B_01 = 0x00000007;
const uint64_t k_32B    = 0x0000000773594000;
const z_list   k_32B_z  = {0x73594000, 0x00000007};
//const z_list   k_32B_z = {0x00000007, 0x73594000};

const uint32_t k_64B_00 = 0xE6B28000;
const uint32_t k_64B_01 = 0x0000000E;
const uint64_t k_64B    = 0x0000000EE6B28000;
const z_list   k_64B_z  = {0xE6B28000, 0x0000000E};
//const z_list   k_64B_z = {0x0000000E, 0xE6B28000};

const uint32_t k_128B_00 = 0xCD650000;
const uint32_t k_128B_01 = 0x0000001D;
const uint64_t k_128B    = 0x0000001DCD650000;
const z_list   k_128B_z  = {0xCD650000, 0x0000001D};
//const z_list   k_128B_z = {0x0000001D, 0xCD650000};

const uint32_t k_256B_00 = 0x9ACA0000;
const uint32_t k_256B_01 = 0x0000003B;
const uint64_t k_256B = 0x0000003B9ACA0000;
const z_list   k_256B_z = {0x9ACA0000, 0x0000003B};
//const z_list   k_256B_z = {0x0000003B, 0x9ACA0000};






#endif

