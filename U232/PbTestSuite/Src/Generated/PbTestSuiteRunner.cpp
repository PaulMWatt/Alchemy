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
CxxTest::StaticSuiteDescription suiteDescription_TestMeta( "../TestMeta.h", 49, "TestMeta", suite_TestMeta, Tests_TestMeta );

static class TestDescription_suite_TestMeta_Test_value_if_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_value_if_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 82, "Test_value_if_true" ) {}
 void runTest() { suite_TestMeta.Test_value_if_true(); }
} testDescription_suite_TestMeta_Test_value_if_true;

static class TestDescription_suite_TestMeta_Test_value_if_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_value_if_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 83, "Test_value_if_false" ) {}
 void runTest() { suite_TestMeta.Test_value_if_false(); }
} testDescription_suite_TestMeta_Test_value_if_false;

static class TestDescription_suite_TestMeta_Test_one_or_zero_1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_one_or_zero_1() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 84, "Test_one_or_zero_1" ) {}
 void runTest() { suite_TestMeta.Test_one_or_zero_1(); }
} testDescription_suite_TestMeta_Test_one_or_zero_1;

static class TestDescription_suite_TestMeta_Test_one_or_zero_0 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_one_or_zero_0() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 85, "Test_one_or_zero_0" ) {}
 void runTest() { suite_TestMeta.Test_one_or_zero_0(); }
} testDescription_suite_TestMeta_Test_one_or_zero_0;

static class TestDescription_suite_TestMeta_Test_type_check : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_check() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 88, "Test_type_check" ) {}
 void runTest() { suite_TestMeta.Test_type_check(); }
} testDescription_suite_TestMeta_Test_type_check;

static class TestDescription_suite_TestMeta_Test_not_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_not_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 91, "Test_not_true" ) {}
 void runTest() { suite_TestMeta.Test_not_true(); }
} testDescription_suite_TestMeta_Test_not_true;

static class TestDescription_suite_TestMeta_Test_not_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_not_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 92, "Test_not_false" ) {}
 void runTest() { suite_TestMeta.Test_not_false(); }
} testDescription_suite_TestMeta_Test_not_false;

static class TestDescription_suite_TestMeta_Test_and_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_and_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 93, "Test_and_true" ) {}
 void runTest() { suite_TestMeta.Test_and_true(); }
} testDescription_suite_TestMeta_Test_and_true;

static class TestDescription_suite_TestMeta_Test_and_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_and_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 94, "Test_and_false" ) {}
 void runTest() { suite_TestMeta.Test_and_false(); }
} testDescription_suite_TestMeta_Test_and_false;

static class TestDescription_suite_TestMeta_Test_or_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_or_true() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 95, "Test_or_true" ) {}
 void runTest() { suite_TestMeta.Test_or_true(); }
} testDescription_suite_TestMeta_Test_or_true;

static class TestDescription_suite_TestMeta_Test_or_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_or_false() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 96, "Test_or_false" ) {}
 void runTest() { suite_TestMeta.Test_or_false(); }
} testDescription_suite_TestMeta_Test_or_false;

static class TestDescription_suite_TestMeta_Test_type_container_T : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_T() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 100, "Test_type_container_T" ) {}
 void runTest() { suite_TestMeta.Test_type_container_T(); }
} testDescription_suite_TestMeta_Test_type_container_T;

static class TestDescription_suite_TestMeta_Test_type_container_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_empty() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 103, "Test_type_container_empty" ) {}
 void runTest() { suite_TestMeta.Test_type_container_empty(); }
} testDescription_suite_TestMeta_Test_type_container_empty;

static class TestDescription_suite_TestMeta_Test_type_container_type_list : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_type_list() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 104, "Test_type_container_type_list" ) {}
 void runTest() { suite_TestMeta.Test_type_container_type_list(); }
} testDescription_suite_TestMeta_Test_type_container_type_list;

static class TestDescription_suite_TestMeta_Test_type_container_traits : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Test_type_container_traits() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 105, "Test_type_container_traits" ) {}
 void runTest() { suite_TestMeta.Test_type_container_traits(); }
} testDescription_suite_TestMeta_Test_type_container_traits;

static class TestDescription_suite_TestMeta_Testcontainer_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testcontainer_size() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 108, "Testcontainer_size" ) {}
 void runTest() { suite_TestMeta.Testcontainer_size(); }
} testDescription_suite_TestMeta_Testcontainer_size;

static class TestDescription_suite_TestMeta_Testtype_at_1_to_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testtype_at_1_to_max() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 114, "Testtype_at_1_to_max" ) {}
 void runTest() { suite_TestMeta.Testtype_at_1_to_max(); }
} testDescription_suite_TestMeta_Testtype_at_1_to_max;

static class TestDescription_suite_TestMeta_Testsize_of_char : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_char() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 118, "Testsize_of_char" ) {}
 void runTest() { suite_TestMeta.Testsize_of_char(); }
} testDescription_suite_TestMeta_Testsize_of_char;

static class TestDescription_suite_TestMeta_Testsize_of_uchar : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_uchar() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 119, "Testsize_of_uchar" ) {}
 void runTest() { suite_TestMeta.Testsize_of_uchar(); }
} testDescription_suite_TestMeta_Testsize_of_uchar;

static class TestDescription_suite_TestMeta_Testsize_of_short : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_short() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 120, "Testsize_of_short" ) {}
 void runTest() { suite_TestMeta.Testsize_of_short(); }
} testDescription_suite_TestMeta_Testsize_of_short;

static class TestDescription_suite_TestMeta_Testsize_of_ushort : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_ushort() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 121, "Testsize_of_ushort" ) {}
 void runTest() { suite_TestMeta.Testsize_of_ushort(); }
} testDescription_suite_TestMeta_Testsize_of_ushort;

static class TestDescription_suite_TestMeta_Testsize_of_long : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_long() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 122, "Testsize_of_long" ) {}
 void runTest() { suite_TestMeta.Testsize_of_long(); }
} testDescription_suite_TestMeta_Testsize_of_long;

static class TestDescription_suite_TestMeta_Testsize_of_ulong : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_ulong() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 123, "Testsize_of_ulong" ) {}
 void runTest() { suite_TestMeta.Testsize_of_ulong(); }
} testDescription_suite_TestMeta_Testsize_of_ulong;

static class TestDescription_suite_TestMeta_Testsize_of_float : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_float() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 124, "Testsize_of_float" ) {}
 void runTest() { suite_TestMeta.Testsize_of_float(); }
} testDescription_suite_TestMeta_Testsize_of_float;

static class TestDescription_suite_TestMeta_Testsize_of_double : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_double() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 125, "Testsize_of_double" ) {}
 void runTest() { suite_TestMeta.Testsize_of_double(); }
} testDescription_suite_TestMeta_Testsize_of_double;

static class TestDescription_suite_TestMeta_Testsize_of_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_empty() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 128, "Testsize_of_empty" ) {}
 void runTest() { suite_TestMeta.Testsize_of_empty(); }
} testDescription_suite_TestMeta_Testsize_of_empty;

static class TestDescription_suite_TestMeta_Testsize_of_type_list : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_type_list() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 129, "Testsize_of_type_list" ) {}
 void runTest() { suite_TestMeta.Testsize_of_type_list(); }
} testDescription_suite_TestMeta_Testsize_of_type_list;

static class TestDescription_suite_TestMeta_Testsize_of_NestedNestedtype_list : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_NestedNestedtype_list() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 130, "Testsize_of_NestedNestedtype_list" ) {}
 void runTest() { suite_TestMeta.Testsize_of_NestedNestedtype_list(); }
} testDescription_suite_TestMeta_Testsize_of_NestedNestedtype_list;

static class TestDescription_suite_TestMeta_Testsize_of_BitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_BitSet() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 131, "Testsize_of_BitSet" ) {}
 void runTest() { suite_TestMeta.Testsize_of_BitSet(); }
} testDescription_suite_TestMeta_Testsize_of_BitSet;

static class TestDescription_suite_TestMeta_Testsize_of_DynamicValue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_DynamicValue() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 132, "Testsize_of_DynamicValue" ) {}
 void runTest() { suite_TestMeta.Testsize_of_DynamicValue(); }
} testDescription_suite_TestMeta_Testsize_of_DynamicValue;

static class TestDescription_suite_TestMeta_Testsize_of_NestedArray : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_of_NestedArray() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 133, "Testsize_of_NestedArray" ) {}
 void runTest() { suite_TestMeta.Testsize_of_NestedArray(); }
} testDescription_suite_TestMeta_Testsize_of_NestedArray;

static class TestDescription_suite_TestMeta_Testsize_at_1_to_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testsize_at_1_to_max() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 136, "Testsize_at_1_to_max" ) {}
 void runTest() { suite_TestMeta.Testsize_at_1_to_max(); }
} testDescription_suite_TestMeta_Testsize_at_1_to_max;

static class TestDescription_suite_TestMeta_Testoffset_of_basic : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testoffset_of_basic() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 139, "Testoffset_of_basic" ) {}
 void runTest() { suite_TestMeta.Testoffset_of_basic(); }
} testDescription_suite_TestMeta_Testoffset_of_basic;

static class TestDescription_suite_TestMeta_Testoffset_of_bitset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testoffset_of_bitset() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 140, "Testoffset_of_bitset" ) {}
 void runTest() { suite_TestMeta.Testoffset_of_bitset(); }
} testDescription_suite_TestMeta_Testoffset_of_bitset;

static class TestDescription_suite_TestMeta_Testoffset_of_nested : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_Testoffset_of_nested() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 141, "Testoffset_of_nested" ) {}
 void runTest() { suite_TestMeta.Testoffset_of_nested(); }
} testDescription_suite_TestMeta_Testoffset_of_nested;

static class TestDescription_suite_TestMeta_TestBitSet_constructor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_constructor() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 144, "TestBitSet_constructor" ) {}
 void runTest() { suite_TestMeta.TestBitSet_constructor(); }
} testDescription_suite_TestMeta_TestBitSet_constructor;

static class TestDescription_suite_TestMeta_TestBitSet_conversion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_conversion() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 145, "TestBitSet_conversion" ) {}
 void runTest() { suite_TestMeta.TestBitSet_conversion(); }
} testDescription_suite_TestMeta_TestBitSet_conversion;

static class TestDescription_suite_TestMeta_TestBitSet_assignment_BitSet : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_assignment_BitSet() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 146, "TestBitSet_assignment_BitSet" ) {}
 void runTest() { suite_TestMeta.TestBitSet_assignment_BitSet(); }
} testDescription_suite_TestMeta_TestBitSet_assignment_BitSet;

static class TestDescription_suite_TestMeta_TestBitSet_assignment_value_type : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_assignment_value_type() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 147, "TestBitSet_assignment_value_type" ) {}
 void runTest() { suite_TestMeta.TestBitSet_assignment_value_type(); }
} testDescription_suite_TestMeta_TestBitSet_assignment_value_type;

static class TestDescription_suite_TestMeta_TestBitSet_size : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestBitSet_size() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 148, "TestBitSet_size" ) {}
 void runTest() { suite_TestMeta.TestBitSet_size(); }
} testDescription_suite_TestMeta_TestBitSet_size;

static class TestDescription_suite_TestMeta_TestForEach : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestMeta_TestForEach() : CxxTest::RealTestDescription( Tests_TestMeta, suiteDescription_TestMeta, 151, "TestForEach" ) {}
 void runTest() { suite_TestMeta.TestForEach(); }
} testDescription_suite_TestMeta_TestForEach;

#include "..\TestOptional.h"

static TestOptional suite_TestOptional;

static CxxTest::List Tests_TestOptional = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestOptional( "../TestOptional.h", 41, "TestOptional", suite_TestOptional, Tests_TestOptional );

static class TestDescription_suite_TestOptional_TestDefaultCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptional_TestDefaultCtor() : CxxTest::RealTestDescription( Tests_TestOptional, suiteDescription_TestOptional, 67, "TestDefaultCtor" ) {}
 void runTest() { suite_TestOptional.TestDefaultCtor(); }
} testDescription_suite_TestOptional_TestDefaultCtor;

static class TestDescription_suite_TestOptional_TestValueCtor : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptional_TestValueCtor() : CxxTest::RealTestDescription( Tests_TestOptional, suiteDescription_TestOptional, 68, "TestValueCtor" ) {}
 void runTest() { suite_TestOptional.TestValueCtor(); }
} testDescription_suite_TestOptional_TestValueCtor;

static class TestDescription_suite_TestOptional_TestValueConversion : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptional_TestValueConversion() : CxxTest::RealTestDescription( Tests_TestOptional, suiteDescription_TestOptional, 69, "TestValueConversion" ) {}
 void runTest() { suite_TestOptional.TestValueConversion(); }
} testDescription_suite_TestOptional_TestValueConversion;

static class TestDescription_suite_TestOptional_Test_empty_true : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptional_Test_empty_true() : CxxTest::RealTestDescription( Tests_TestOptional, suiteDescription_TestOptional, 70, "Test_empty_true" ) {}
 void runTest() { suite_TestOptional.Test_empty_true(); }
} testDescription_suite_TestOptional_Test_empty_true;

static class TestDescription_suite_TestOptional_Test_empty_false : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptional_Test_empty_false() : CxxTest::RealTestDescription( Tests_TestOptional, suiteDescription_TestOptional, 71, "Test_empty_false" ) {}
 void runTest() { suite_TestOptional.Test_empty_false(); }
} testDescription_suite_TestOptional_Test_empty_false;

static class TestDescription_suite_TestOptional_Test_reset : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptional_Test_reset() : CxxTest::RealTestDescription( Tests_TestOptional, suiteDescription_TestOptional, 72, "Test_reset" ) {}
 void runTest() { suite_TestOptional.Test_reset(); }
} testDescription_suite_TestOptional_Test_reset;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
