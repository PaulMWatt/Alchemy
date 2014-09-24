/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ParenPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ParenPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ParenPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestByteOrder_init = false;
#include "..\TestByteOrder.h"

static TestByteOrder suite_TestByteOrder;

static CxxTest::List Tests_TestByteOrder = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestByteOrder( "../TestByteOrder.h", 47, "TestByteOrder", suite_TestByteOrder, Tests_TestByteOrder );

static class TestDescription_suite_TestByteOrder_TestEndianSwap_no_op : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_no_op() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 73, "TestEndianSwap_no_op" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_no_op(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_no_op;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_int16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_int16() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 74, "TestEndianSwap_int16" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_int16(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_int16;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_uint16 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_uint16() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 75, "TestEndianSwap_uint16" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_uint16(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_uint16;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_int32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_int32() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 76, "TestEndianSwap_int32" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_int32(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_int32;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_uint32 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_uint32() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 77, "TestEndianSwap_uint32" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_uint32(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_uint32;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_int64 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_int64() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 78, "TestEndianSwap_int64" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_int64(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_int64;

static class TestDescription_suite_TestByteOrder_TestEndianSwap_uint64 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianSwap_uint64() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 79, "TestEndianSwap_uint64" ) {}
 void runTest() { suite_TestByteOrder.TestEndianSwap_uint64(); }
} testDescription_suite_TestByteOrder_TestEndianSwap_uint64;

static class TestDescription_suite_TestByteOrder_TestEndianType_no_op : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianType_no_op() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 81, "TestEndianType_no_op" ) {}
 void runTest() { suite_TestByteOrder.TestEndianType_no_op(); }
} testDescription_suite_TestByteOrder_TestEndianType_no_op;

static class TestDescription_suite_TestByteOrder_TestEndianType_swap_order : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestEndianType_swap_order() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 82, "TestEndianType_swap_order" ) {}
 void runTest() { suite_TestByteOrder.TestEndianType_swap_order(); }
} testDescription_suite_TestByteOrder_TestEndianType_swap_order;

static class TestDescription_suite_TestByteOrder_TestHostByteOrder_to_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestHostByteOrder_to_host() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 84, "TestHostByteOrder_to_host" ) {}
 void runTest() { suite_TestByteOrder.TestHostByteOrder_to_host(); }
} testDescription_suite_TestByteOrder_TestHostByteOrder_to_host;

static class TestDescription_suite_TestByteOrder_TestHostByteOrder_to_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestHostByteOrder_to_network() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 85, "TestHostByteOrder_to_network" ) {}
 void runTest() { suite_TestByteOrder.TestHostByteOrder_to_network(); }
} testDescription_suite_TestByteOrder_TestHostByteOrder_to_network;

static class TestDescription_suite_TestByteOrder_TestNetByteOrder_to_host : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestNetByteOrder_to_host() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 86, "TestNetByteOrder_to_host" ) {}
 void runTest() { suite_TestByteOrder.TestNetByteOrder_to_host(); }
} testDescription_suite_TestByteOrder_TestNetByteOrder_to_host;

static class TestDescription_suite_TestByteOrder_TestNetByteOrder_to_network : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestByteOrder_TestNetByteOrder_to_network() : CxxTest::RealTestDescription( Tests_TestByteOrder, suiteDescription_TestByteOrder, 87, "TestNetByteOrder_to_network" ) {}
 void runTest() { suite_TestByteOrder.TestNetByteOrder_to_network(); }
} testDescription_suite_TestByteOrder_TestNetByteOrder_to_network;

#include "..\TestMeta.h"

static TestMeta suite_TestMeta;

static CxxTest::List Tests_TestMeta = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestMeta( "../TestMeta.h", 58, "TestMeta", suite_TestMeta, Tests_TestMeta );

static class TestDescription_suite_TestMeta_Test_value_if_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_value_if_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 91, "Test_value_if_true" ) {}
 void runTest() { suite_TestMeta.Test_value_if_true(); }
} testDescription_suite_TestMeta_Test_value_if_true;

static class TestDescription_suite_TestMeta_Test_value_if_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_value_if_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 92, "Test_value_if_false" ) {}
 void runTest() { suite_TestMeta.Test_value_if_false(); }
} testDescription_suite_TestMeta_Test_value_if_false;

static class TestDescription_suite_TestMeta_Test_one_or_zero_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_one_or_zero_1() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 93, "Test_one_or_zero_1" ) {}
 void runTest() { suite_TestMeta.Test_one_or_zero_1(); }
} testDescription_suite_TestMeta_Test_one_or_zero_1;

static class TestDescription_suite_TestMeta_Test_one_or_zero_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_one_or_zero_0() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 94, "Test_one_or_zero_0" ) {}
 void runTest() { suite_TestMeta.Test_one_or_zero_0(); }
} testDescription_suite_TestMeta_Test_one_or_zero_0;

static class TestDescription_suite_TestMeta_Test_type_check : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_check() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 97, "Test_type_check" ) {}
 void runTest() { suite_TestMeta.Test_type_check(); }
} testDescription_suite_TestMeta_Test_type_check;

static class TestDescription_suite_TestMeta_Test_not_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_not_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 100, "Test_not_true" ) {}
 void runTest() { suite_TestMeta.Test_not_true(); }
} testDescription_suite_TestMeta_Test_not_true;

static class TestDescription_suite_TestMeta_Test_not_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_not_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 101, "Test_not_false" ) {}
 void runTest() { suite_TestMeta.Test_not_false(); }
} testDescription_suite_TestMeta_Test_not_false;

static class TestDescription_suite_TestMeta_Test_and_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_and_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 102, "Test_and_true" ) {}
 void runTest() { suite_TestMeta.Test_and_true(); }
} testDescription_suite_TestMeta_Test_and_true;

static class TestDescription_suite_TestMeta_Test_and_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_and_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 103, "Test_and_false" ) {}
 void runTest() { suite_TestMeta.Test_and_false(); }
} testDescription_suite_TestMeta_Test_and_false;

static class TestDescription_suite_TestMeta_Test_or_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_or_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 104, "Test_or_true" ) {}
 void runTest() { suite_TestMeta.Test_or_true(); }
} testDescription_suite_TestMeta_Test_or_true;

static class TestDescription_suite_TestMeta_Test_or_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_or_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 105, "Test_or_false" ) {}
 void runTest() { suite_TestMeta.Test_or_false(); }
} testDescription_suite_TestMeta_Test_or_false;

static class TestDescription_suite_TestMeta_Test_type_container_T : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_T() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 109, "Test_type_container_T" ) {}
 void runTest() { suite_TestMeta.Test_type_container_T(); }
} testDescription_suite_TestMeta_Test_type_container_T;

static class TestDescription_suite_TestMeta_Test_type_container_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_empty() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 112, "Test_type_container_empty" ) {}
 void runTest() { suite_TestMeta.Test_type_container_empty(); }
} testDescription_suite_TestMeta_Test_type_container_empty;

static class TestDescription_suite_TestMeta_Test_type_container_TypeList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_TypeList() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 113, "Test_type_container_TypeList" ) {}
 void runTest() { suite_TestMeta.Test_type_container_TypeList(); }
} testDescription_suite_TestMeta_Test_type_container_TypeList;

static class TestDescription_suite_TestMeta_Test_type_container_traits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_traits() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 114, "Test_type_container_traits" ) {}
 void runTest() { suite_TestMeta.Test_type_container_traits(); }
} testDescription_suite_TestMeta_Test_type_container_traits;

static class TestDescription_suite_TestMeta_TestContainerSize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestContainerSize() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 117, "TestContainerSize" ) {}
 void runTest() { suite_TestMeta.TestContainerSize(); }
} testDescription_suite_TestMeta_TestContainerSize;

static class TestDescription_suite_TestMeta_TestTypeAt_1_to_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestTypeAt_1_to_max() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 123, "TestTypeAt_1_to_max" ) {}
 void runTest() { suite_TestMeta.TestTypeAt_1_to_max(); }
} testDescription_suite_TestMeta_TestTypeAt_1_to_max;

static class TestDescription_suite_TestMeta_TestSizeOf_char : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_char() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 127, "TestSizeOf_char" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_char(); }
} testDescription_suite_TestMeta_TestSizeOf_char;

static class TestDescription_suite_TestMeta_TestSizeOf_uchar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_uchar() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 128, "TestSizeOf_uchar" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_uchar(); }
} testDescription_suite_TestMeta_TestSizeOf_uchar;

static class TestDescription_suite_TestMeta_TestSizeOf_short : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_short() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 129, "TestSizeOf_short" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_short(); }
} testDescription_suite_TestMeta_TestSizeOf_short;

static class TestDescription_suite_TestMeta_TestSizeOf_ushort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_ushort() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 130, "TestSizeOf_ushort" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_ushort(); }
} testDescription_suite_TestMeta_TestSizeOf_ushort;

static class TestDescription_suite_TestMeta_TestSizeOf_long : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_long() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 131, "TestSizeOf_long" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_long(); }
} testDescription_suite_TestMeta_TestSizeOf_long;

static class TestDescription_suite_TestMeta_TestSizeOf_ulong : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_ulong() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 132, "TestSizeOf_ulong" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_ulong(); }
} testDescription_suite_TestMeta_TestSizeOf_ulong;

static class TestDescription_suite_TestMeta_TestSizeOf_float : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_float() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 133, "TestSizeOf_float" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_float(); }
} testDescription_suite_TestMeta_TestSizeOf_float;

static class TestDescription_suite_TestMeta_TestSizeOf_double : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_double() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 134, "TestSizeOf_double" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_double(); }
} testDescription_suite_TestMeta_TestSizeOf_double;

static class TestDescription_suite_TestMeta_TestSizeOf_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_empty() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 137, "TestSizeOf_empty" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_empty(); }
} testDescription_suite_TestMeta_TestSizeOf_empty;

static class TestDescription_suite_TestMeta_TestSizeOf_TypeList : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_TypeList() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 138, "TestSizeOf_TypeList" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_TypeList(); }
} testDescription_suite_TestMeta_TestSizeOf_TypeList;

static class TestDescription_suite_TestMeta_TestSizeOf_BitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_BitSet() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 139, "TestSizeOf_BitSet" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_BitSet(); }
} testDescription_suite_TestMeta_TestSizeOf_BitSet;

static class TestDescription_suite_TestMeta_TestSizeOf_DynamicValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_DynamicValue() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 140, "TestSizeOf_DynamicValue" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_DynamicValue(); }
} testDescription_suite_TestMeta_TestSizeOf_DynamicValue;

static class TestDescription_suite_TestMeta_TestSizeOf_ArrayValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeOf_ArrayValue() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 141, "TestSizeOf_ArrayValue" ) {}
 void runTest() { suite_TestMeta.TestSizeOf_ArrayValue(); }
} testDescription_suite_TestMeta_TestSizeOf_ArrayValue;

static class TestDescription_suite_TestMeta_TestSizeAt_1_to_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestSizeAt_1_to_max() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 144, "TestSizeAt_1_to_max" ) {}
 void runTest() { suite_TestMeta.TestSizeAt_1_to_max(); }
} testDescription_suite_TestMeta_TestSizeAt_1_to_max;

static class TestDescription_suite_TestMeta_TestOffsetOf_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestOffsetOf_basic() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 147, "TestOffsetOf_basic" ) {}
 void runTest() { suite_TestMeta.TestOffsetOf_basic(); }
} testDescription_suite_TestMeta_TestOffsetOf_basic;

static class TestDescription_suite_TestMeta_TestOffsetOf_bitset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestOffsetOf_bitset() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 148, "TestOffsetOf_bitset" ) {}
 void runTest() { suite_TestMeta.TestOffsetOf_bitset(); }
} testDescription_suite_TestMeta_TestOffsetOf_bitset;

static class TestDescription_suite_TestMeta_TestOffsetOf_nested : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestOffsetOf_nested() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 149, "TestOffsetOf_nested" ) {}
 void runTest() { suite_TestMeta.TestOffsetOf_nested(); }
} testDescription_suite_TestMeta_TestOffsetOf_nested;

static class TestDescription_suite_TestMeta_TestBitSet_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_constructor() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 152, "TestBitSet_constructor" ) {}
 void runTest() { suite_TestMeta.TestBitSet_constructor(); }
} testDescription_suite_TestMeta_TestBitSet_constructor;

static class TestDescription_suite_TestMeta_TestBitSet_conversion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_conversion() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 153, "TestBitSet_conversion" ) {}
 void runTest() { suite_TestMeta.TestBitSet_conversion(); }
} testDescription_suite_TestMeta_TestBitSet_conversion;

static class TestDescription_suite_TestMeta_TestBitSet_assignment_BitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_assignment_BitSet() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 154, "TestBitSet_assignment_BitSet" ) {}
 void runTest() { suite_TestMeta.TestBitSet_assignment_BitSet(); }
} testDescription_suite_TestMeta_TestBitSet_assignment_BitSet;

static class TestDescription_suite_TestMeta_TestBitSet_assignment_value_type : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_assignment_value_type() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 155, "TestBitSet_assignment_value_type" ) {}
 void runTest() { suite_TestMeta.TestBitSet_assignment_value_type(); }
} testDescription_suite_TestMeta_TestBitSet_assignment_value_type;

static class TestDescription_suite_TestMeta_TestBitSet_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_size() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 156, "TestBitSet_size" ) {}
 void runTest() { suite_TestMeta.TestBitSet_size(); }
} testDescription_suite_TestMeta_TestBitSet_size;

static class TestDescription_suite_TestMeta_TestForEach : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestForEach() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 159, "TestForEach" ) {}
 void runTest() { suite_TestMeta.TestForEach(); }
} testDescription_suite_TestMeta_TestForEach;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
