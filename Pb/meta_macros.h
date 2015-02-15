/// @file meta_macros.h
/// 
/// @brief  Utility MACROS used to simplify the definitions for 
///         many of the TMP constructs.
///
/// MACROS:   TMP_ARRAY_X       To simplify multiple repetitive declarations
///           TMP_REPEAT_X      Repeats in the input the number of times specified
///
/// The MIT License(MIT)
/// @copyright 2014 Paul M Watt
//  ****************************************************************************
#ifndef META_MACROS_H_INCLUDED
#define META_MACROS_H_INCLUDED

/** MACRO set to simplify the declaration of many array entries **************/
#define TMP_ARRAY_1(T)    T##0
#define TMP_ARRAY_2(T)    TMP_ARRAY_1(T),  T##1
#define TMP_ARRAY_3(T)    TMP_ARRAY_2(T),  T##2
#define TMP_ARRAY_4(T)    TMP_ARRAY_3(T),  T##3
#define TMP_ARRAY_5(T)    TMP_ARRAY_4(T),  T##4
#define TMP_ARRAY_6(T)    TMP_ARRAY_5(T),  T##5
#define TMP_ARRAY_7(T)    TMP_ARRAY_6(T),  T##6
#define TMP_ARRAY_8(T)    TMP_ARRAY_7(T),  T##7
#define TMP_ARRAY_9(T)    TMP_ARRAY_8(T),  T##8
#define TMP_ARRAY_10(T)   TMP_ARRAY_9(T),  T##9
#define TMP_ARRAY_11(T)   TMP_ARRAY_10(T), T##10
#define TMP_ARRAY_12(T)   TMP_ARRAY_11(T), T##11
#define TMP_ARRAY_13(T)   TMP_ARRAY_12(T), T##12
#define TMP_ARRAY_14(T)   TMP_ARRAY_13(T), T##13
#define TMP_ARRAY_15(T)   TMP_ARRAY_14(T), T##14
#define TMP_ARRAY_16(T)   TMP_ARRAY_15(T), T##15
#define TMP_ARRAY_17(T)   TMP_ARRAY_16(T), T##16
#define TMP_ARRAY_18(T)   TMP_ARRAY_17(T), T##17
#define TMP_ARRAY_19(T)   TMP_ARRAY_18(T), T##18
#define TMP_ARRAY_20(T)   TMP_ARRAY_19(T), T##19
#define TMP_ARRAY_21(T)   TMP_ARRAY_20(T), T##20
#define TMP_ARRAY_22(T)   TMP_ARRAY_21(T), T##21
#define TMP_ARRAY_23(T)   TMP_ARRAY_22(T), T##22
#define TMP_ARRAY_24(T)   TMP_ARRAY_23(T), T##23
#define TMP_ARRAY_25(T)   TMP_ARRAY_24(T), T##24
#define TMP_ARRAY_26(T)   TMP_ARRAY_25(T), T##25
#define TMP_ARRAY_27(T)   TMP_ARRAY_26(T), T##26
#define TMP_ARRAY_28(T)   TMP_ARRAY_27(T), T##27
#define TMP_ARRAY_29(T)   TMP_ARRAY_28(T), T##28
#define TMP_ARRAY_30(T)   TMP_ARRAY_29(T), T##29
#define TMP_ARRAY_31(T)   TMP_ARRAY_30(T), T##30
#define TMP_ARRAY_32(T)   TMP_ARRAY_31(T), T##31

// Repeats a specified number of times, 32 is the current maximum.
// Note: The value N passed in must be a literal number.
#define TMP_ARRAY_N(N,T)  TMP_ARRAY_##N(T)

/** MACROS used to simplify the replication of an item ********************/
#define TMP_REPEAT_1(T)    T 
#define TMP_REPEAT_2(T)    TMP_REPEAT_1(T) T
#define TMP_REPEAT_3(T)    TMP_REPEAT_2(T) T
#define TMP_REPEAT_4(T)    TMP_REPEAT_3(T) T
#define TMP_REPEAT_5(T)    TMP_REPEAT_4(T) T
#define TMP_REPEAT_6(T)    TMP_REPEAT_5(T) T
#define TMP_REPEAT_7(T)    TMP_REPEAT_6(T) T
#define TMP_REPEAT_8(T)    TMP_REPEAT_7(T) T
#define TMP_REPEAT_9(T)    TMP_REPEAT_8(T) T
#define TMP_REPEAT_10(T)   TMP_REPEAT_9(T) T
#define TMP_REPEAT_11(T)   TMP_REPEAT_10(T) T
#define TMP_REPEAT_12(T)   TMP_REPEAT_11(T) T
#define TMP_REPEAT_13(T)   TMP_REPEAT_12(T) T
#define TMP_REPEAT_14(T)   TMP_REPEAT_13(T) T
#define TMP_REPEAT_15(T)   TMP_REPEAT_14(T) T
#define TMP_REPEAT_16(T)   TMP_REPEAT_15(T) T
#define TMP_REPEAT_17(T)   TMP_REPEAT_16(T) T
#define TMP_REPEAT_18(T)   TMP_REPEAT_17(T) T
#define TMP_REPEAT_19(T)   TMP_REPEAT_18(T) T
#define TMP_REPEAT_20(T)   TMP_REPEAT_19(T) T
#define TMP_REPEAT_21(T)   TMP_REPEAT_20(T) T
#define TMP_REPEAT_22(T)   TMP_REPEAT_21(T) T
#define TMP_REPEAT_23(T)   TMP_REPEAT_22(T) T
#define TMP_REPEAT_24(T)   TMP_REPEAT_23(T) T
#define TMP_REPEAT_25(T)   TMP_REPEAT_24(T) T
#define TMP_REPEAT_26(T)   TMP_REPEAT_25(T) T
#define TMP_REPEAT_27(T)   TMP_REPEAT_26(T) T
#define TMP_REPEAT_28(T)   TMP_REPEAT_27(T) T
#define TMP_REPEAT_29(T)   TMP_REPEAT_28(T) T
#define TMP_REPEAT_30(T)   TMP_REPEAT_29(T) T
#define TMP_REPEAT_31(T)   TMP_REPEAT_30(T) T
#define TMP_REPEAT_32(T)   TMP_REPEAT_31(T) T

// Repeats a specified number of times, 32 is the current maximum.
// Note: The value N passed in must be a literal number.
#define TMP_REPEAT_N(N,T)  TMP_REPEAT_##N(T)

// Evaluates the two input expressions, 
// then uses the token paste operator to fuse them together.
#define TMP_PASTE(A,B)    TMP_PASTE_DO(A,B)
#define TMP_PASTE_DO(A,B) A ## B

// Increments 1 to the supplied number, 0 to 15 are supported
#define TMP_INC(x)    TMP_INC_DO(x)
#define TMP_INC_DO(x) TMP_INC_ ## x

#define TMP_INC_0    1
#define TMP_INC_1    2
#define TMP_INC_2    3
#define TMP_INC_3    4
#define TMP_INC_4    5
#define TMP_INC_5    6
#define TMP_INC_6    7
#define TMP_INC_7    8
#define TMP_INC_8    9
#define TMP_INC_9    10
#define TMP_INC_10   11
#define TMP_INC_11   12
#define TMP_INC_12   13
#define TMP_INC_13   14
#define TMP_INC_14   15
#define TMP_INC_15   16
#define TMP_INC_16   15
#define TMP_INC_17   16
#define TMP_INC_18   17
#define TMP_INC_19   18
#define TMP_INC_20   19
#define TMP_INC_21   20
#define TMP_INC_22   21
#define TMP_INC_23   22
#define TMP_INC_24   23
#define TMP_INC_25   24
#define TMP_INC_26   25
#define TMP_INC_27   26
#define TMP_INC_28   27
#define TMP_INC_29   28
#define TMP_INC_30   29
#define TMP_INC_31   30
#define TMP_INC_32   31


// Decrements 1 from the supplied number, 16 to 1 are supported.
#define TMP_DEC(x)    TMP_DEC_DO(x)
#define TMP_DEC_DO(x) TMP_DEC_ ## x

#define TMP_DEC_1    0
#define TMP_DEC_2    1
#define TMP_DEC_3    2
#define TMP_DEC_4    3
#define TMP_DEC_5    4
#define TMP_DEC_6    5
#define TMP_DEC_7    6
#define TMP_DEC_8    7
#define TMP_DEC_9    8
#define TMP_DEC_10   9
#define TMP_DEC_11   10
#define TMP_DEC_12   11
#define TMP_DEC_13   12
#define TMP_DEC_14   13
#define TMP_DEC_15   14
#define TMP_DEC_16   15
#define TMP_DEC_17   16
#define TMP_DEC_18   17
#define TMP_DEC_19   18
#define TMP_DEC_20   19
#define TMP_DEC_21   20
#define TMP_DEC_22   21
#define TMP_DEC_23   22
#define TMP_DEC_24   23
#define TMP_DEC_25   24
#define TMP_DEC_26   25
#define TMP_DEC_27   26
#define TMP_DEC_28   27
#define TMP_DEC_29   28
#define TMP_DEC_30   29
#define TMP_DEC_31   30
#define TMP_DEC_32   31

#endif
