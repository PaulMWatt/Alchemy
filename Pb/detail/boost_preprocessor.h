# /* **************************************************************************
#  *                                                                          *        
#  *    The set of BOOST_PP MACROS that are included in this file are derived from
#  *    these MACROS that are used to define the HG structure format:
#  *
#  *        BOOST_PP_VARIADIC_TO_SEQ
#  *        BOOST_PP_SEQ_FOR_EACH_I
#  *        BOOST_PP_TUPLE_ELEM
#  *
#  *     (C) Copyright Housemarque Oy                                         *
#  *     (C) Copyright Edward Diener                                          *
#  *     (C) Copyright Paul Mensonides                                        *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#ifndef BOOST_PREPROCESSOR_H_INCLUDED
#define BOOST_PREPROCESSOR_H_INCLUDED

#define BOOST_PP_VARIADICS 1

//  Includes *******************************************************************
#include <Pb/detail/boost_pp_config.h>
//  ****************************************************************************
# /* BOOST_PP_CAT */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_CAT(a, b) BOOST_PP_CAT_I(a, b)
# else
#    define BOOST_PP_CAT(a, b) BOOST_PP_CAT_OO((a, b))
#    define BOOST_PP_CAT_OO(par) BOOST_PP_CAT_I ## par
# endif
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_CAT_I(a, b) a ## b
# else
#    define BOOST_PP_CAT_I(a, b) BOOST_PP_CAT_II(~, a ## b)
#    define BOOST_PP_CAT_II(p, res) res
# endif


//  ****************************************************************************
# /* BOOST_PP_SPLIT */
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_SPLIT(n, im) BOOST_PP_SPLIT_I((n, im))
#    define BOOST_PP_SPLIT_I(par) BOOST_PP_SPLIT_II ## par
#    define BOOST_PP_SPLIT_II(n, a, b) BOOST_PP_SPLIT_ ## n(a, b)
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_SPLIT(n, im) BOOST_PP_SPLIT_I(n((im)))
#    define BOOST_PP_SPLIT_I(n) BOOST_PP_SPLIT_ID(BOOST_PP_SPLIT_II_ ## n)
#    define BOOST_PP_SPLIT_II_0(s) BOOST_PP_SPLIT_ID(BOOST_PP_SPLIT_0 s)
#    define BOOST_PP_SPLIT_II_1(s) BOOST_PP_SPLIT_ID(BOOST_PP_SPLIT_1 s)
#    define BOOST_PP_SPLIT_ID(id) id
# else
#    define BOOST_PP_SPLIT(n, im) BOOST_PP_SPLIT_I(n)(im)
#    define BOOST_PP_SPLIT_I(n) BOOST_PP_SPLIT_ ## n
# endif
#
# define BOOST_PP_SPLIT_0(a, b) a
# define BOOST_PP_SPLIT_1(a, b) b


//  ****************************************************************************
# /* BOOST_PP_VARIADIC_SIZE */
#
# if BOOST_PP_VARIADICS
#    if BOOST_PP_VARIADICS_MSVC
#        define BOOST_PP_VARIADIC_SIZE(...) BOOST_PP_CAT(BOOST_PP_VARIADIC_SIZE_I(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,),)
#    else
#        define BOOST_PP_VARIADIC_SIZE(...) BOOST_PP_VARIADIC_SIZE_I(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,)
#    endif
#    define BOOST_PP_VARIADIC_SIZE_I(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63, size, ...) size
# endif


//  ****************************************************************************
# if BOOST_PP_VARIADICS
#    if BOOST_PP_VARIADICS_MSVC
#        define BOOST_PP_TUPLE_SIZE(tuple) BOOST_PP_CAT(BOOST_PP_VARIADIC_SIZE tuple,)
#    else
#        define BOOST_PP_TUPLE_SIZE(tuple) BOOST_PP_VARIADIC_SIZE tuple
#    endif
# endif


//  ****************************************************************************
# /* BOOST_PP_OVERLOAD */
#
# if BOOST_PP_VARIADICS
#    define BOOST_PP_OVERLOAD(prefix, ...) BOOST_PP_CAT(prefix, BOOST_PP_VARIADIC_SIZE(__VA_ARGS__))
# endif


//  ****************************************************************************
# /* BOOST_PP_TUPLE_TO_SEQ */
#
# if BOOST_PP_VARIADICS
#    if BOOST_PP_VARIADICS_MSVC
#        define BOOST_PP_TUPLE_TO_SEQ(...) BOOST_PP_TUPLE_TO_SEQ_I(BOOST_PP_OVERLOAD(BOOST_PP_TUPLE_TO_SEQ_O_, __VA_ARGS__), (__VA_ARGS__))
#        define BOOST_PP_TUPLE_TO_SEQ_I(m, args) BOOST_PP_TUPLE_TO_SEQ_II(m, args)
#        define BOOST_PP_TUPLE_TO_SEQ_II(m, args) BOOST_PP_CAT(m ## args,)
#    	 define BOOST_PP_TUPLE_TO_SEQ_O_1(tuple) BOOST_PP_CAT(BOOST_PP_TUPLE_TO_SEQ_, BOOST_PP_TUPLE_SIZE(tuple)) tuple
#    else
#        define BOOST_PP_TUPLE_TO_SEQ(...) BOOST_PP_OVERLOAD(BOOST_PP_TUPLE_TO_SEQ_O_, __VA_ARGS__)(__VA_ARGS__)
#    	 define BOOST_PP_TUPLE_TO_SEQ_O_1(tuple) BOOST_PP_CAT(BOOST_PP_TUPLE_TO_SEQ_, BOOST_PP_VARIADIC_SIZE tuple) tuple
#    endif
#    define BOOST_PP_TUPLE_TO_SEQ_O_2(size, tuple) BOOST_PP_TUPLE_TO_SEQ_O_1(tuple)
# else
#    if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#        define BOOST_PP_TUPLE_TO_SEQ(size, tuple) BOOST_PP_TUPLE_TO_SEQ_I(size, tuple)
#        if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#            define BOOST_PP_TUPLE_TO_SEQ_I(s, t) BOOST_PP_TUPLE_TO_SEQ_ ## s t
#        else
#            define BOOST_PP_TUPLE_TO_SEQ_I(s, t) BOOST_PP_TUPLE_TO_SEQ_II(BOOST_PP_TUPLE_TO_SEQ_ ## s t)
#            define BOOST_PP_TUPLE_TO_SEQ_II(res) res
#        endif
#    else
#        define BOOST_PP_TUPLE_TO_SEQ(size, tuple) BOOST_PP_TUPLE_TO_SEQ_OO((size, tuple))
#        define BOOST_PP_TUPLE_TO_SEQ_OO(par) BOOST_PP_TUPLE_TO_SEQ_I ## par
#        define BOOST_PP_TUPLE_TO_SEQ_I(s, t) BOOST_PP_TUPLE_TO_SEQ_ ## s ## t
#    endif
# endif


//  ****************************************************************************
/* An empty array can be passed */
# define BOOST_PP_TUPLE_TO_SEQ_0() ()
#
# define BOOST_PP_TUPLE_TO_SEQ_1(e0) (e0)
# define BOOST_PP_TUPLE_TO_SEQ_2(e0, e1) (e0)(e1)
# define BOOST_PP_TUPLE_TO_SEQ_3(e0, e1, e2) (e0)(e1)(e2)
# define BOOST_PP_TUPLE_TO_SEQ_4(e0, e1, e2, e3) (e0)(e1)(e2)(e3)
# define BOOST_PP_TUPLE_TO_SEQ_5(e0, e1, e2, e3, e4) (e0)(e1)(e2)(e3)(e4)
# define BOOST_PP_TUPLE_TO_SEQ_6(e0, e1, e2, e3, e4, e5) (e0)(e1)(e2)(e3)(e4)(e5)
# define BOOST_PP_TUPLE_TO_SEQ_7(e0, e1, e2, e3, e4, e5, e6) (e0)(e1)(e2)(e3)(e4)(e5)(e6)
# define BOOST_PP_TUPLE_TO_SEQ_8(e0, e1, e2, e3, e4, e5, e6, e7) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)
# define BOOST_PP_TUPLE_TO_SEQ_9(e0, e1, e2, e3, e4, e5, e6, e7, e8) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)
# define BOOST_PP_TUPLE_TO_SEQ_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)
# define BOOST_PP_TUPLE_TO_SEQ_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)
# define BOOST_PP_TUPLE_TO_SEQ_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)
# define BOOST_PP_TUPLE_TO_SEQ_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)
# define BOOST_PP_TUPLE_TO_SEQ_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)
# define BOOST_PP_TUPLE_TO_SEQ_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)
# define BOOST_PP_TUPLE_TO_SEQ_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)
# define BOOST_PP_TUPLE_TO_SEQ_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)
# define BOOST_PP_TUPLE_TO_SEQ_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)
# define BOOST_PP_TUPLE_TO_SEQ_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)
# define BOOST_PP_TUPLE_TO_SEQ_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)
# define BOOST_PP_TUPLE_TO_SEQ_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)
# define BOOST_PP_TUPLE_TO_SEQ_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)
# define BOOST_PP_TUPLE_TO_SEQ_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)
# define BOOST_PP_TUPLE_TO_SEQ_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)
# define BOOST_PP_TUPLE_TO_SEQ_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)
# define BOOST_PP_TUPLE_TO_SEQ_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)
# define BOOST_PP_TUPLE_TO_SEQ_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)
# define BOOST_PP_TUPLE_TO_SEQ_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)
# define BOOST_PP_TUPLE_TO_SEQ_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)
# define BOOST_PP_TUPLE_TO_SEQ_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)
# define BOOST_PP_TUPLE_TO_SEQ_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)
# define BOOST_PP_TUPLE_TO_SEQ_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)
# define BOOST_PP_TUPLE_TO_SEQ_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)
# define BOOST_PP_TUPLE_TO_SEQ_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)
# define BOOST_PP_TUPLE_TO_SEQ_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)
# define BOOST_PP_TUPLE_TO_SEQ_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)
# define BOOST_PP_TUPLE_TO_SEQ_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)
# define BOOST_PP_TUPLE_TO_SEQ_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)
# define BOOST_PP_TUPLE_TO_SEQ_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)
# define BOOST_PP_TUPLE_TO_SEQ_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)
# define BOOST_PP_TUPLE_TO_SEQ_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)
# define BOOST_PP_TUPLE_TO_SEQ_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)
# define BOOST_PP_TUPLE_TO_SEQ_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)
# define BOOST_PP_TUPLE_TO_SEQ_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)
# define BOOST_PP_TUPLE_TO_SEQ_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)
# define BOOST_PP_TUPLE_TO_SEQ_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)
# define BOOST_PP_TUPLE_TO_SEQ_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)
# define BOOST_PP_TUPLE_TO_SEQ_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)
# define BOOST_PP_TUPLE_TO_SEQ_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)
# define BOOST_PP_TUPLE_TO_SEQ_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)
# define BOOST_PP_TUPLE_TO_SEQ_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)
# define BOOST_PP_TUPLE_TO_SEQ_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)
# define BOOST_PP_TUPLE_TO_SEQ_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)
# define BOOST_PP_TUPLE_TO_SEQ_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)
# define BOOST_PP_TUPLE_TO_SEQ_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)
# define BOOST_PP_TUPLE_TO_SEQ_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)
# define BOOST_PP_TUPLE_TO_SEQ_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)
# define BOOST_PP_TUPLE_TO_SEQ_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)
# define BOOST_PP_TUPLE_TO_SEQ_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)
# define BOOST_PP_TUPLE_TO_SEQ_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)
# define BOOST_PP_TUPLE_TO_SEQ_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)
# define BOOST_PP_TUPLE_TO_SEQ_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)(e61)
# define BOOST_PP_TUPLE_TO_SEQ_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)(e61)(e62)
# define BOOST_PP_TUPLE_TO_SEQ_64(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) (e0)(e1)(e2)(e3)(e4)(e5)(e6)(e7)(e8)(e9)(e10)(e11)(e12)(e13)(e14)(e15)(e16)(e17)(e18)(e19)(e20)(e21)(e22)(e23)(e24)(e25)(e26)(e27)(e28)(e29)(e30)(e31)(e32)(e33)(e34)(e35)(e36)(e37)(e38)(e39)(e40)(e41)(e42)(e43)(e44)(e45)(e46)(e47)(e48)(e49)(e50)(e51)(e52)(e53)(e54)(e55)(e56)(e57)(e58)(e59)(e60)(e61)(e62)(e63)


//  ****************************************************************************
# /* BOOST_PP_VARIADIC_TO_SEQ */
#
# if BOOST_PP_VARIADICS
#    define BOOST_PP_VARIADIC_TO_SEQ(...) BOOST_PP_TUPLE_TO_SEQ((__VA_ARGS__))
# endif

//  ****************************************************************************
# /* BOOST_PP_DEC */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_DEC(x) BOOST_PP_DEC_I(x)
# else
#    define BOOST_PP_DEC(x) BOOST_PP_DEC_OO((x))
#    define BOOST_PP_DEC_OO(par) BOOST_PP_DEC_I ## par
# endif
#
# define BOOST_PP_DEC_I(x) BOOST_PP_DEC_ ## x
#
# define BOOST_PP_DEC_0 0
# define BOOST_PP_DEC_1 0
# define BOOST_PP_DEC_2 1
# define BOOST_PP_DEC_3 2
# define BOOST_PP_DEC_4 3
# define BOOST_PP_DEC_5 4
# define BOOST_PP_DEC_6 5
# define BOOST_PP_DEC_7 6
# define BOOST_PP_DEC_8 7
# define BOOST_PP_DEC_9 8
# define BOOST_PP_DEC_10 9
# define BOOST_PP_DEC_11 10
# define BOOST_PP_DEC_12 11
# define BOOST_PP_DEC_13 12
# define BOOST_PP_DEC_14 13
# define BOOST_PP_DEC_15 14
# define BOOST_PP_DEC_16 15
# define BOOST_PP_DEC_17 16
# define BOOST_PP_DEC_18 17
# define BOOST_PP_DEC_19 18
# define BOOST_PP_DEC_20 19
# define BOOST_PP_DEC_21 20
# define BOOST_PP_DEC_22 21
# define BOOST_PP_DEC_23 22
# define BOOST_PP_DEC_24 23
# define BOOST_PP_DEC_25 24
# define BOOST_PP_DEC_26 25
# define BOOST_PP_DEC_27 26
# define BOOST_PP_DEC_28 27
# define BOOST_PP_DEC_29 28
# define BOOST_PP_DEC_30 29
# define BOOST_PP_DEC_31 30
# define BOOST_PP_DEC_32 31
# define BOOST_PP_DEC_33 32
# define BOOST_PP_DEC_34 33
# define BOOST_PP_DEC_35 34
# define BOOST_PP_DEC_36 35
# define BOOST_PP_DEC_37 36
# define BOOST_PP_DEC_38 37
# define BOOST_PP_DEC_39 38
# define BOOST_PP_DEC_40 39
# define BOOST_PP_DEC_41 40
# define BOOST_PP_DEC_42 41
# define BOOST_PP_DEC_43 42
# define BOOST_PP_DEC_44 43
# define BOOST_PP_DEC_45 44
# define BOOST_PP_DEC_46 45
# define BOOST_PP_DEC_47 46
# define BOOST_PP_DEC_48 47
# define BOOST_PP_DEC_49 48
# define BOOST_PP_DEC_50 49
# define BOOST_PP_DEC_51 50
# define BOOST_PP_DEC_52 51
# define BOOST_PP_DEC_53 52
# define BOOST_PP_DEC_54 53
# define BOOST_PP_DEC_55 54
# define BOOST_PP_DEC_56 55
# define BOOST_PP_DEC_57 56
# define BOOST_PP_DEC_58 57
# define BOOST_PP_DEC_59 58
# define BOOST_PP_DEC_60 59
# define BOOST_PP_DEC_61 60
# define BOOST_PP_DEC_62 61
# define BOOST_PP_DEC_63 62
# define BOOST_PP_DEC_64 63
# define BOOST_PP_DEC_65 64
# define BOOST_PP_DEC_66 65
# define BOOST_PP_DEC_67 66
# define BOOST_PP_DEC_68 67
# define BOOST_PP_DEC_69 68
# define BOOST_PP_DEC_70 69
# define BOOST_PP_DEC_71 70
# define BOOST_PP_DEC_72 71
# define BOOST_PP_DEC_73 72
# define BOOST_PP_DEC_74 73
# define BOOST_PP_DEC_75 74
# define BOOST_PP_DEC_76 75
# define BOOST_PP_DEC_77 76
# define BOOST_PP_DEC_78 77
# define BOOST_PP_DEC_79 78
# define BOOST_PP_DEC_80 79
# define BOOST_PP_DEC_81 80
# define BOOST_PP_DEC_82 81
# define BOOST_PP_DEC_83 82
# define BOOST_PP_DEC_84 83
# define BOOST_PP_DEC_85 84
# define BOOST_PP_DEC_86 85
# define BOOST_PP_DEC_87 86
# define BOOST_PP_DEC_88 87
# define BOOST_PP_DEC_89 88
# define BOOST_PP_DEC_90 89
# define BOOST_PP_DEC_91 90
# define BOOST_PP_DEC_92 91
# define BOOST_PP_DEC_93 92
# define BOOST_PP_DEC_94 93
# define BOOST_PP_DEC_95 94
# define BOOST_PP_DEC_96 95
# define BOOST_PP_DEC_97 96
# define BOOST_PP_DEC_98 97
# define BOOST_PP_DEC_99 98
# define BOOST_PP_DEC_100 99
# define BOOST_PP_DEC_101 100
# define BOOST_PP_DEC_102 101
# define BOOST_PP_DEC_103 102
# define BOOST_PP_DEC_104 103
# define BOOST_PP_DEC_105 104
# define BOOST_PP_DEC_106 105
# define BOOST_PP_DEC_107 106
# define BOOST_PP_DEC_108 107
# define BOOST_PP_DEC_109 108
# define BOOST_PP_DEC_110 109
# define BOOST_PP_DEC_111 110
# define BOOST_PP_DEC_112 111
# define BOOST_PP_DEC_113 112
# define BOOST_PP_DEC_114 113
# define BOOST_PP_DEC_115 114
# define BOOST_PP_DEC_116 115
# define BOOST_PP_DEC_117 116
# define BOOST_PP_DEC_118 117
# define BOOST_PP_DEC_119 118
# define BOOST_PP_DEC_120 119
# define BOOST_PP_DEC_121 120
# define BOOST_PP_DEC_122 121
# define BOOST_PP_DEC_123 122
# define BOOST_PP_DEC_124 123
# define BOOST_PP_DEC_125 124
# define BOOST_PP_DEC_126 125
# define BOOST_PP_DEC_127 126
# define BOOST_PP_DEC_128 127
# define BOOST_PP_DEC_129 128
# define BOOST_PP_DEC_130 129
# define BOOST_PP_DEC_131 130
# define BOOST_PP_DEC_132 131
# define BOOST_PP_DEC_133 132
# define BOOST_PP_DEC_134 133
# define BOOST_PP_DEC_135 134
# define BOOST_PP_DEC_136 135
# define BOOST_PP_DEC_137 136
# define BOOST_PP_DEC_138 137
# define BOOST_PP_DEC_139 138
# define BOOST_PP_DEC_140 139
# define BOOST_PP_DEC_141 140
# define BOOST_PP_DEC_142 141
# define BOOST_PP_DEC_143 142
# define BOOST_PP_DEC_144 143
# define BOOST_PP_DEC_145 144
# define BOOST_PP_DEC_146 145
# define BOOST_PP_DEC_147 146
# define BOOST_PP_DEC_148 147
# define BOOST_PP_DEC_149 148
# define BOOST_PP_DEC_150 149
# define BOOST_PP_DEC_151 150
# define BOOST_PP_DEC_152 151
# define BOOST_PP_DEC_153 152
# define BOOST_PP_DEC_154 153
# define BOOST_PP_DEC_155 154
# define BOOST_PP_DEC_156 155
# define BOOST_PP_DEC_157 156
# define BOOST_PP_DEC_158 157
# define BOOST_PP_DEC_159 158
# define BOOST_PP_DEC_160 159
# define BOOST_PP_DEC_161 160
# define BOOST_PP_DEC_162 161
# define BOOST_PP_DEC_163 162
# define BOOST_PP_DEC_164 163
# define BOOST_PP_DEC_165 164
# define BOOST_PP_DEC_166 165
# define BOOST_PP_DEC_167 166
# define BOOST_PP_DEC_168 167
# define BOOST_PP_DEC_169 168
# define BOOST_PP_DEC_170 169
# define BOOST_PP_DEC_171 170
# define BOOST_PP_DEC_172 171
# define BOOST_PP_DEC_173 172
# define BOOST_PP_DEC_174 173
# define BOOST_PP_DEC_175 174
# define BOOST_PP_DEC_176 175
# define BOOST_PP_DEC_177 176
# define BOOST_PP_DEC_178 177
# define BOOST_PP_DEC_179 178
# define BOOST_PP_DEC_180 179
# define BOOST_PP_DEC_181 180
# define BOOST_PP_DEC_182 181
# define BOOST_PP_DEC_183 182
# define BOOST_PP_DEC_184 183
# define BOOST_PP_DEC_185 184
# define BOOST_PP_DEC_186 185
# define BOOST_PP_DEC_187 186
# define BOOST_PP_DEC_188 187
# define BOOST_PP_DEC_189 188
# define BOOST_PP_DEC_190 189
# define BOOST_PP_DEC_191 190
# define BOOST_PP_DEC_192 191
# define BOOST_PP_DEC_193 192
# define BOOST_PP_DEC_194 193
# define BOOST_PP_DEC_195 194
# define BOOST_PP_DEC_196 195
# define BOOST_PP_DEC_197 196
# define BOOST_PP_DEC_198 197
# define BOOST_PP_DEC_199 198
# define BOOST_PP_DEC_200 199
# define BOOST_PP_DEC_201 200
# define BOOST_PP_DEC_202 201
# define BOOST_PP_DEC_203 202
# define BOOST_PP_DEC_204 203
# define BOOST_PP_DEC_205 204
# define BOOST_PP_DEC_206 205
# define BOOST_PP_DEC_207 206
# define BOOST_PP_DEC_208 207
# define BOOST_PP_DEC_209 208
# define BOOST_PP_DEC_210 209
# define BOOST_PP_DEC_211 210
# define BOOST_PP_DEC_212 211
# define BOOST_PP_DEC_213 212
# define BOOST_PP_DEC_214 213
# define BOOST_PP_DEC_215 214
# define BOOST_PP_DEC_216 215
# define BOOST_PP_DEC_217 216
# define BOOST_PP_DEC_218 217
# define BOOST_PP_DEC_219 218
# define BOOST_PP_DEC_220 219
# define BOOST_PP_DEC_221 220
# define BOOST_PP_DEC_222 221
# define BOOST_PP_DEC_223 222
# define BOOST_PP_DEC_224 223
# define BOOST_PP_DEC_225 224
# define BOOST_PP_DEC_226 225
# define BOOST_PP_DEC_227 226
# define BOOST_PP_DEC_228 227
# define BOOST_PP_DEC_229 228
# define BOOST_PP_DEC_230 229
# define BOOST_PP_DEC_231 230
# define BOOST_PP_DEC_232 231
# define BOOST_PP_DEC_233 232
# define BOOST_PP_DEC_234 233
# define BOOST_PP_DEC_235 234
# define BOOST_PP_DEC_236 235
# define BOOST_PP_DEC_237 236
# define BOOST_PP_DEC_238 237
# define BOOST_PP_DEC_239 238
# define BOOST_PP_DEC_240 239
# define BOOST_PP_DEC_241 240
# define BOOST_PP_DEC_242 241
# define BOOST_PP_DEC_243 242
# define BOOST_PP_DEC_244 243
# define BOOST_PP_DEC_245 244
# define BOOST_PP_DEC_246 245
# define BOOST_PP_DEC_247 246
# define BOOST_PP_DEC_248 247
# define BOOST_PP_DEC_249 248
# define BOOST_PP_DEC_250 249
# define BOOST_PP_DEC_251 250
# define BOOST_PP_DEC_252 251
# define BOOST_PP_DEC_253 252
# define BOOST_PP_DEC_254 253
# define BOOST_PP_DEC_255 254
# define BOOST_PP_DEC_256 255


//  ****************************************************************************
# /* BOOST_PP_INC */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_INC(x) BOOST_PP_INC_I(x)
# else
#    define BOOST_PP_INC(x) BOOST_PP_INC_OO((x))
#    define BOOST_PP_INC_OO(par) BOOST_PP_INC_I ## par
# endif
#
# define BOOST_PP_INC_I(x) BOOST_PP_INC_ ## x
#
# define BOOST_PP_INC_0 1
# define BOOST_PP_INC_1 2
# define BOOST_PP_INC_2 3
# define BOOST_PP_INC_3 4
# define BOOST_PP_INC_4 5
# define BOOST_PP_INC_5 6
# define BOOST_PP_INC_6 7
# define BOOST_PP_INC_7 8
# define BOOST_PP_INC_8 9
# define BOOST_PP_INC_9 10
# define BOOST_PP_INC_10 11
# define BOOST_PP_INC_11 12
# define BOOST_PP_INC_12 13
# define BOOST_PP_INC_13 14
# define BOOST_PP_INC_14 15
# define BOOST_PP_INC_15 16
# define BOOST_PP_INC_16 17
# define BOOST_PP_INC_17 18
# define BOOST_PP_INC_18 19
# define BOOST_PP_INC_19 20
# define BOOST_PP_INC_20 21
# define BOOST_PP_INC_21 22
# define BOOST_PP_INC_22 23
# define BOOST_PP_INC_23 24
# define BOOST_PP_INC_24 25
# define BOOST_PP_INC_25 26
# define BOOST_PP_INC_26 27
# define BOOST_PP_INC_27 28
# define BOOST_PP_INC_28 29
# define BOOST_PP_INC_29 30
# define BOOST_PP_INC_30 31
# define BOOST_PP_INC_31 32
# define BOOST_PP_INC_32 33
# define BOOST_PP_INC_33 34
# define BOOST_PP_INC_34 35
# define BOOST_PP_INC_35 36
# define BOOST_PP_INC_36 37
# define BOOST_PP_INC_37 38
# define BOOST_PP_INC_38 39
# define BOOST_PP_INC_39 40
# define BOOST_PP_INC_40 41
# define BOOST_PP_INC_41 42
# define BOOST_PP_INC_42 43
# define BOOST_PP_INC_43 44
# define BOOST_PP_INC_44 45
# define BOOST_PP_INC_45 46
# define BOOST_PP_INC_46 47
# define BOOST_PP_INC_47 48
# define BOOST_PP_INC_48 49
# define BOOST_PP_INC_49 50
# define BOOST_PP_INC_50 51
# define BOOST_PP_INC_51 52
# define BOOST_PP_INC_52 53
# define BOOST_PP_INC_53 54
# define BOOST_PP_INC_54 55
# define BOOST_PP_INC_55 56
# define BOOST_PP_INC_56 57
# define BOOST_PP_INC_57 58
# define BOOST_PP_INC_58 59
# define BOOST_PP_INC_59 60
# define BOOST_PP_INC_60 61
# define BOOST_PP_INC_61 62
# define BOOST_PP_INC_62 63
# define BOOST_PP_INC_63 64
# define BOOST_PP_INC_64 65
# define BOOST_PP_INC_65 66
# define BOOST_PP_INC_66 67
# define BOOST_PP_INC_67 68
# define BOOST_PP_INC_68 69
# define BOOST_PP_INC_69 70
# define BOOST_PP_INC_70 71
# define BOOST_PP_INC_71 72
# define BOOST_PP_INC_72 73
# define BOOST_PP_INC_73 74
# define BOOST_PP_INC_74 75
# define BOOST_PP_INC_75 76
# define BOOST_PP_INC_76 77
# define BOOST_PP_INC_77 78
# define BOOST_PP_INC_78 79
# define BOOST_PP_INC_79 80
# define BOOST_PP_INC_80 81
# define BOOST_PP_INC_81 82
# define BOOST_PP_INC_82 83
# define BOOST_PP_INC_83 84
# define BOOST_PP_INC_84 85
# define BOOST_PP_INC_85 86
# define BOOST_PP_INC_86 87
# define BOOST_PP_INC_87 88
# define BOOST_PP_INC_88 89
# define BOOST_PP_INC_89 90
# define BOOST_PP_INC_90 91
# define BOOST_PP_INC_91 92
# define BOOST_PP_INC_92 93
# define BOOST_PP_INC_93 94
# define BOOST_PP_INC_94 95
# define BOOST_PP_INC_95 96
# define BOOST_PP_INC_96 97
# define BOOST_PP_INC_97 98
# define BOOST_PP_INC_98 99
# define BOOST_PP_INC_99 100
# define BOOST_PP_INC_100 101
# define BOOST_PP_INC_101 102
# define BOOST_PP_INC_102 103
# define BOOST_PP_INC_103 104
# define BOOST_PP_INC_104 105
# define BOOST_PP_INC_105 106
# define BOOST_PP_INC_106 107
# define BOOST_PP_INC_107 108
# define BOOST_PP_INC_108 109
# define BOOST_PP_INC_109 110
# define BOOST_PP_INC_110 111
# define BOOST_PP_INC_111 112
# define BOOST_PP_INC_112 113
# define BOOST_PP_INC_113 114
# define BOOST_PP_INC_114 115
# define BOOST_PP_INC_115 116
# define BOOST_PP_INC_116 117
# define BOOST_PP_INC_117 118
# define BOOST_PP_INC_118 119
# define BOOST_PP_INC_119 120
# define BOOST_PP_INC_120 121
# define BOOST_PP_INC_121 122
# define BOOST_PP_INC_122 123
# define BOOST_PP_INC_123 124
# define BOOST_PP_INC_124 125
# define BOOST_PP_INC_125 126
# define BOOST_PP_INC_126 127
# define BOOST_PP_INC_127 128
# define BOOST_PP_INC_128 129
# define BOOST_PP_INC_129 130
# define BOOST_PP_INC_130 131
# define BOOST_PP_INC_131 132
# define BOOST_PP_INC_132 133
# define BOOST_PP_INC_133 134
# define BOOST_PP_INC_134 135
# define BOOST_PP_INC_135 136
# define BOOST_PP_INC_136 137
# define BOOST_PP_INC_137 138
# define BOOST_PP_INC_138 139
# define BOOST_PP_INC_139 140
# define BOOST_PP_INC_140 141
# define BOOST_PP_INC_141 142
# define BOOST_PP_INC_142 143
# define BOOST_PP_INC_143 144
# define BOOST_PP_INC_144 145
# define BOOST_PP_INC_145 146
# define BOOST_PP_INC_146 147
# define BOOST_PP_INC_147 148
# define BOOST_PP_INC_148 149
# define BOOST_PP_INC_149 150
# define BOOST_PP_INC_150 151
# define BOOST_PP_INC_151 152
# define BOOST_PP_INC_152 153
# define BOOST_PP_INC_153 154
# define BOOST_PP_INC_154 155
# define BOOST_PP_INC_155 156
# define BOOST_PP_INC_156 157
# define BOOST_PP_INC_157 158
# define BOOST_PP_INC_158 159
# define BOOST_PP_INC_159 160
# define BOOST_PP_INC_160 161
# define BOOST_PP_INC_161 162
# define BOOST_PP_INC_162 163
# define BOOST_PP_INC_163 164
# define BOOST_PP_INC_164 165
# define BOOST_PP_INC_165 166
# define BOOST_PP_INC_166 167
# define BOOST_PP_INC_167 168
# define BOOST_PP_INC_168 169
# define BOOST_PP_INC_169 170
# define BOOST_PP_INC_170 171
# define BOOST_PP_INC_171 172
# define BOOST_PP_INC_172 173
# define BOOST_PP_INC_173 174
# define BOOST_PP_INC_174 175
# define BOOST_PP_INC_175 176
# define BOOST_PP_INC_176 177
# define BOOST_PP_INC_177 178
# define BOOST_PP_INC_178 179
# define BOOST_PP_INC_179 180
# define BOOST_PP_INC_180 181
# define BOOST_PP_INC_181 182
# define BOOST_PP_INC_182 183
# define BOOST_PP_INC_183 184
# define BOOST_PP_INC_184 185
# define BOOST_PP_INC_185 186
# define BOOST_PP_INC_186 187
# define BOOST_PP_INC_187 188
# define BOOST_PP_INC_188 189
# define BOOST_PP_INC_189 190
# define BOOST_PP_INC_190 191
# define BOOST_PP_INC_191 192
# define BOOST_PP_INC_192 193
# define BOOST_PP_INC_193 194
# define BOOST_PP_INC_194 195
# define BOOST_PP_INC_195 196
# define BOOST_PP_INC_196 197
# define BOOST_PP_INC_197 198
# define BOOST_PP_INC_198 199
# define BOOST_PP_INC_199 200
# define BOOST_PP_INC_200 201
# define BOOST_PP_INC_201 202
# define BOOST_PP_INC_202 203
# define BOOST_PP_INC_203 204
# define BOOST_PP_INC_204 205
# define BOOST_PP_INC_205 206
# define BOOST_PP_INC_206 207
# define BOOST_PP_INC_207 208
# define BOOST_PP_INC_208 209
# define BOOST_PP_INC_209 210
# define BOOST_PP_INC_210 211
# define BOOST_PP_INC_211 212
# define BOOST_PP_INC_212 213
# define BOOST_PP_INC_213 214
# define BOOST_PP_INC_214 215
# define BOOST_PP_INC_215 216
# define BOOST_PP_INC_216 217
# define BOOST_PP_INC_217 218
# define BOOST_PP_INC_218 219
# define BOOST_PP_INC_219 220
# define BOOST_PP_INC_220 221
# define BOOST_PP_INC_221 222
# define BOOST_PP_INC_222 223
# define BOOST_PP_INC_223 224
# define BOOST_PP_INC_224 225
# define BOOST_PP_INC_225 226
# define BOOST_PP_INC_226 227
# define BOOST_PP_INC_227 228
# define BOOST_PP_INC_228 229
# define BOOST_PP_INC_229 230
# define BOOST_PP_INC_230 231
# define BOOST_PP_INC_231 232
# define BOOST_PP_INC_232 233
# define BOOST_PP_INC_233 234
# define BOOST_PP_INC_234 235
# define BOOST_PP_INC_235 236
# define BOOST_PP_INC_236 237
# define BOOST_PP_INC_237 238
# define BOOST_PP_INC_238 239
# define BOOST_PP_INC_239 240
# define BOOST_PP_INC_240 241
# define BOOST_PP_INC_241 242
# define BOOST_PP_INC_242 243
# define BOOST_PP_INC_243 244
# define BOOST_PP_INC_244 245
# define BOOST_PP_INC_245 246
# define BOOST_PP_INC_246 247
# define BOOST_PP_INC_247 248
# define BOOST_PP_INC_248 249
# define BOOST_PP_INC_249 250
# define BOOST_PP_INC_250 251
# define BOOST_PP_INC_251 252
# define BOOST_PP_INC_252 253
# define BOOST_PP_INC_253 254
# define BOOST_PP_INC_254 255
# define BOOST_PP_INC_255 256
# define BOOST_PP_INC_256 256


//  ****************************************************************************
# /* BOOST_PP_ERROR */
#
# if BOOST_PP_CONFIG_ERRORS
#    define BOOST_PP_ERROR(code) BOOST_PP_CAT(BOOST_PP_ERROR_, code)
# endif
#
# define BOOST_PP_ERROR_0x0000 BOOST_PP_ERROR(0x0000, BOOST_PP_INDEX_OUT_OF_BOUNDS)
# define BOOST_PP_ERROR_0x0001 BOOST_PP_ERROR(0x0001, BOOST_PP_WHILE_OVERFLOW)
# define BOOST_PP_ERROR_0x0002 BOOST_PP_ERROR(0x0002, BOOST_PP_FOR_OVERFLOW)
# define BOOST_PP_ERROR_0x0003 BOOST_PP_ERROR(0x0003, BOOST_PP_REPEAT_OVERFLOW)
# define BOOST_PP_ERROR_0x0004 BOOST_PP_ERROR(0x0004, BOOST_PP_LIST_FOLD_OVERFLOW)
# define BOOST_PP_ERROR_0x0005 BOOST_PP_ERROR(0x0005, BOOST_PP_SEQ_FOLD_OVERFLOW)
# define BOOST_PP_ERROR_0x0006 BOOST_PP_ERROR(0x0006, BOOST_PP_ARITHMETIC_OVERFLOW)
# define BOOST_PP_ERROR_0x0007 BOOST_PP_ERROR(0x0007, BOOST_PP_DIVISION_BY_ZERO)


//  ****************************************************************************
# /* BOOST_PP_IFF */
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_IIF(bit, t, f) BOOST_PP_IIF_I(bit, t, f)
# else
#    define BOOST_PP_IIF(bit, t, f) BOOST_PP_IIF_OO((bit, t, f))
#    define BOOST_PP_IIF_OO(par) BOOST_PP_IIF_I ## par
# endif
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_IIF_I(bit, t, f) BOOST_PP_IIF_ ## bit(t, f)
# else
#    define BOOST_PP_IIF_I(bit, t, f) BOOST_PP_IIF_II(BOOST_PP_IIF_ ## bit(t, f))
#    define BOOST_PP_IIF_II(id) id
# endif
#
# define BOOST_PP_IIF_0(t, f) f
# define BOOST_PP_IIF_1(t, f) t


//  ****************************************************************************
# /* BOOST_PP_IF */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_IF(cond, t, f) BOOST_PP_IIF(BOOST_PP_BOOL(cond), t, f)
# else
#    define BOOST_PP_IF(cond, t, f) BOOST_PP_IF_I(cond, t, f)
#    define BOOST_PP_IF_I(cond, t, f) BOOST_PP_IIF(BOOST_PP_BOOL(cond), t, f)
# endif


//  ****************************************************************************
# /* BOOST_PP_AUTO_REC */
#
# define BOOST_PP_AUTO_REC(pred, n) BOOST_PP_NODE_ENTRY_ ## n(pred)
#
# define BOOST_PP_NODE_ENTRY_256(p) BOOST_PP_NODE_128(p)(p)(p)(p)(p)(p)(p)(p)
# define BOOST_PP_NODE_ENTRY_128(p) BOOST_PP_NODE_64(p)(p)(p)(p)(p)(p)(p)
# define BOOST_PP_NODE_ENTRY_64(p) BOOST_PP_NODE_32(p)(p)(p)(p)(p)(p)
# define BOOST_PP_NODE_ENTRY_32(p) BOOST_PP_NODE_16(p)(p)(p)(p)(p)
# define BOOST_PP_NODE_ENTRY_16(p) BOOST_PP_NODE_8(p)(p)(p)(p)
# define BOOST_PP_NODE_ENTRY_8(p) BOOST_PP_NODE_4(p)(p)(p)
# define BOOST_PP_NODE_ENTRY_4(p) BOOST_PP_NODE_2(p)(p)
# define BOOST_PP_NODE_ENTRY_2(p) BOOST_PP_NODE_1(p)
#
# define BOOST_PP_NODE_128(p) BOOST_PP_IIF(p(128), BOOST_PP_NODE_64, BOOST_PP_NODE_192)
#    define BOOST_PP_NODE_64(p) BOOST_PP_IIF(p(64), BOOST_PP_NODE_32, BOOST_PP_NODE_96)
#        define BOOST_PP_NODE_32(p) BOOST_PP_IIF(p(32), BOOST_PP_NODE_16, BOOST_PP_NODE_48)
#            define BOOST_PP_NODE_16(p) BOOST_PP_IIF(p(16), BOOST_PP_NODE_8, BOOST_PP_NODE_24)
#                define BOOST_PP_NODE_8(p) BOOST_PP_IIF(p(8), BOOST_PP_NODE_4, BOOST_PP_NODE_12)
#                    define BOOST_PP_NODE_4(p) BOOST_PP_IIF(p(4), BOOST_PP_NODE_2, BOOST_PP_NODE_6)
#                        define BOOST_PP_NODE_2(p) BOOST_PP_IIF(p(2), BOOST_PP_NODE_1, BOOST_PP_NODE_3)
#                            define BOOST_PP_NODE_1(p) BOOST_PP_IIF(p(1), 1, 2)
#                            define BOOST_PP_NODE_3(p) BOOST_PP_IIF(p(3), 3, 4)
#                        define BOOST_PP_NODE_6(p) BOOST_PP_IIF(p(6), BOOST_PP_NODE_5, BOOST_PP_NODE_7)
#                            define BOOST_PP_NODE_5(p) BOOST_PP_IIF(p(5), 5, 6)
#                            define BOOST_PP_NODE_7(p) BOOST_PP_IIF(p(7), 7, 8)
#                    define BOOST_PP_NODE_12(p) BOOST_PP_IIF(p(12), BOOST_PP_NODE_10, BOOST_PP_NODE_14)
#                        define BOOST_PP_NODE_10(p) BOOST_PP_IIF(p(10), BOOST_PP_NODE_9, BOOST_PP_NODE_11)
#                            define BOOST_PP_NODE_9(p) BOOST_PP_IIF(p(9), 9, 10)
#                            define BOOST_PP_NODE_11(p) BOOST_PP_IIF(p(11), 11, 12)
#                        define BOOST_PP_NODE_14(p) BOOST_PP_IIF(p(14), BOOST_PP_NODE_13, BOOST_PP_NODE_15)
#                            define BOOST_PP_NODE_13(p) BOOST_PP_IIF(p(13), 13, 14)
#                            define BOOST_PP_NODE_15(p) BOOST_PP_IIF(p(15), 15, 16)
#                define BOOST_PP_NODE_24(p) BOOST_PP_IIF(p(24), BOOST_PP_NODE_20, BOOST_PP_NODE_28)
#                    define BOOST_PP_NODE_20(p) BOOST_PP_IIF(p(20), BOOST_PP_NODE_18, BOOST_PP_NODE_22)
#                        define BOOST_PP_NODE_18(p) BOOST_PP_IIF(p(18), BOOST_PP_NODE_17, BOOST_PP_NODE_19)
#                            define BOOST_PP_NODE_17(p) BOOST_PP_IIF(p(17), 17, 18)
#                            define BOOST_PP_NODE_19(p) BOOST_PP_IIF(p(19), 19, 20)
#                        define BOOST_PP_NODE_22(p) BOOST_PP_IIF(p(22), BOOST_PP_NODE_21, BOOST_PP_NODE_23)
#                            define BOOST_PP_NODE_21(p) BOOST_PP_IIF(p(21), 21, 22)
#                            define BOOST_PP_NODE_23(p) BOOST_PP_IIF(p(23), 23, 24)
#                    define BOOST_PP_NODE_28(p) BOOST_PP_IIF(p(28), BOOST_PP_NODE_26, BOOST_PP_NODE_30)
#                        define BOOST_PP_NODE_26(p) BOOST_PP_IIF(p(26), BOOST_PP_NODE_25, BOOST_PP_NODE_27)
#                            define BOOST_PP_NODE_25(p) BOOST_PP_IIF(p(25), 25, 26)
#                            define BOOST_PP_NODE_27(p) BOOST_PP_IIF(p(27), 27, 28)
#                        define BOOST_PP_NODE_30(p) BOOST_PP_IIF(p(30), BOOST_PP_NODE_29, BOOST_PP_NODE_31)
#                            define BOOST_PP_NODE_29(p) BOOST_PP_IIF(p(29), 29, 30)
#                            define BOOST_PP_NODE_31(p) BOOST_PP_IIF(p(31), 31, 32)
#            define BOOST_PP_NODE_48(p) BOOST_PP_IIF(p(48), BOOST_PP_NODE_40, BOOST_PP_NODE_56)
#                define BOOST_PP_NODE_40(p) BOOST_PP_IIF(p(40), BOOST_PP_NODE_36, BOOST_PP_NODE_44)
#                    define BOOST_PP_NODE_36(p) BOOST_PP_IIF(p(36), BOOST_PP_NODE_34, BOOST_PP_NODE_38)
#                        define BOOST_PP_NODE_34(p) BOOST_PP_IIF(p(34), BOOST_PP_NODE_33, BOOST_PP_NODE_35)
#                            define BOOST_PP_NODE_33(p) BOOST_PP_IIF(p(33), 33, 34)
#                            define BOOST_PP_NODE_35(p) BOOST_PP_IIF(p(35), 35, 36)
#                        define BOOST_PP_NODE_38(p) BOOST_PP_IIF(p(38), BOOST_PP_NODE_37, BOOST_PP_NODE_39)
#                            define BOOST_PP_NODE_37(p) BOOST_PP_IIF(p(37), 37, 38)
#                            define BOOST_PP_NODE_39(p) BOOST_PP_IIF(p(39), 39, 40)
#                    define BOOST_PP_NODE_44(p) BOOST_PP_IIF(p(44), BOOST_PP_NODE_42, BOOST_PP_NODE_46)
#                        define BOOST_PP_NODE_42(p) BOOST_PP_IIF(p(42), BOOST_PP_NODE_41, BOOST_PP_NODE_43)
#                            define BOOST_PP_NODE_41(p) BOOST_PP_IIF(p(41), 41, 42)
#                            define BOOST_PP_NODE_43(p) BOOST_PP_IIF(p(43), 43, 44)
#                        define BOOST_PP_NODE_46(p) BOOST_PP_IIF(p(46), BOOST_PP_NODE_45, BOOST_PP_NODE_47)
#                            define BOOST_PP_NODE_45(p) BOOST_PP_IIF(p(45), 45, 46)
#                            define BOOST_PP_NODE_47(p) BOOST_PP_IIF(p(47), 47, 48)
#                define BOOST_PP_NODE_56(p) BOOST_PP_IIF(p(56), BOOST_PP_NODE_52, BOOST_PP_NODE_60)
#                    define BOOST_PP_NODE_52(p) BOOST_PP_IIF(p(52), BOOST_PP_NODE_50, BOOST_PP_NODE_54)
#                        define BOOST_PP_NODE_50(p) BOOST_PP_IIF(p(50), BOOST_PP_NODE_49, BOOST_PP_NODE_51)
#                            define BOOST_PP_NODE_49(p) BOOST_PP_IIF(p(49), 49, 50)
#                            define BOOST_PP_NODE_51(p) BOOST_PP_IIF(p(51), 51, 52)
#                        define BOOST_PP_NODE_54(p) BOOST_PP_IIF(p(54), BOOST_PP_NODE_53, BOOST_PP_NODE_55)
#                            define BOOST_PP_NODE_53(p) BOOST_PP_IIF(p(53), 53, 54)
#                            define BOOST_PP_NODE_55(p) BOOST_PP_IIF(p(55), 55, 56)
#                    define BOOST_PP_NODE_60(p) BOOST_PP_IIF(p(60), BOOST_PP_NODE_58, BOOST_PP_NODE_62)
#                        define BOOST_PP_NODE_58(p) BOOST_PP_IIF(p(58), BOOST_PP_NODE_57, BOOST_PP_NODE_59)
#                            define BOOST_PP_NODE_57(p) BOOST_PP_IIF(p(57), 57, 58)
#                            define BOOST_PP_NODE_59(p) BOOST_PP_IIF(p(59), 59, 60)
#                        define BOOST_PP_NODE_62(p) BOOST_PP_IIF(p(62), BOOST_PP_NODE_61, BOOST_PP_NODE_63)
#                            define BOOST_PP_NODE_61(p) BOOST_PP_IIF(p(61), 61, 62)
#                            define BOOST_PP_NODE_63(p) BOOST_PP_IIF(p(63), 63, 64)
#        define BOOST_PP_NODE_96(p) BOOST_PP_IIF(p(96), BOOST_PP_NODE_80, BOOST_PP_NODE_112)
#            define BOOST_PP_NODE_80(p) BOOST_PP_IIF(p(80), BOOST_PP_NODE_72, BOOST_PP_NODE_88)
#                define BOOST_PP_NODE_72(p) BOOST_PP_IIF(p(72), BOOST_PP_NODE_68, BOOST_PP_NODE_76)
#                    define BOOST_PP_NODE_68(p) BOOST_PP_IIF(p(68), BOOST_PP_NODE_66, BOOST_PP_NODE_70)
#                        define BOOST_PP_NODE_66(p) BOOST_PP_IIF(p(66), BOOST_PP_NODE_65, BOOST_PP_NODE_67)
#                            define BOOST_PP_NODE_65(p) BOOST_PP_IIF(p(65), 65, 66)
#                            define BOOST_PP_NODE_67(p) BOOST_PP_IIF(p(67), 67, 68)
#                        define BOOST_PP_NODE_70(p) BOOST_PP_IIF(p(70), BOOST_PP_NODE_69, BOOST_PP_NODE_71)
#                            define BOOST_PP_NODE_69(p) BOOST_PP_IIF(p(69), 69, 70)
#                            define BOOST_PP_NODE_71(p) BOOST_PP_IIF(p(71), 71, 72)
#                    define BOOST_PP_NODE_76(p) BOOST_PP_IIF(p(76), BOOST_PP_NODE_74, BOOST_PP_NODE_78)
#                        define BOOST_PP_NODE_74(p) BOOST_PP_IIF(p(74), BOOST_PP_NODE_73, BOOST_PP_NODE_75)
#                            define BOOST_PP_NODE_73(p) BOOST_PP_IIF(p(73), 73, 74)
#                            define BOOST_PP_NODE_75(p) BOOST_PP_IIF(p(75), 75, 76)
#                        define BOOST_PP_NODE_78(p) BOOST_PP_IIF(p(78), BOOST_PP_NODE_77, BOOST_PP_NODE_79)
#                            define BOOST_PP_NODE_77(p) BOOST_PP_IIF(p(77), 77, 78)
#                            define BOOST_PP_NODE_79(p) BOOST_PP_IIF(p(79), 79, 80)
#                define BOOST_PP_NODE_88(p) BOOST_PP_IIF(p(88), BOOST_PP_NODE_84, BOOST_PP_NODE_92)
#                    define BOOST_PP_NODE_84(p) BOOST_PP_IIF(p(84), BOOST_PP_NODE_82, BOOST_PP_NODE_86)
#                        define BOOST_PP_NODE_82(p) BOOST_PP_IIF(p(82), BOOST_PP_NODE_81, BOOST_PP_NODE_83)
#                            define BOOST_PP_NODE_81(p) BOOST_PP_IIF(p(81), 81, 82)
#                            define BOOST_PP_NODE_83(p) BOOST_PP_IIF(p(83), 83, 84)
#                        define BOOST_PP_NODE_86(p) BOOST_PP_IIF(p(86), BOOST_PP_NODE_85, BOOST_PP_NODE_87)
#                            define BOOST_PP_NODE_85(p) BOOST_PP_IIF(p(85), 85, 86)
#                            define BOOST_PP_NODE_87(p) BOOST_PP_IIF(p(87), 87, 88)
#                    define BOOST_PP_NODE_92(p) BOOST_PP_IIF(p(92), BOOST_PP_NODE_90, BOOST_PP_NODE_94)
#                        define BOOST_PP_NODE_90(p) BOOST_PP_IIF(p(90), BOOST_PP_NODE_89, BOOST_PP_NODE_91)
#                            define BOOST_PP_NODE_89(p) BOOST_PP_IIF(p(89), 89, 90)
#                            define BOOST_PP_NODE_91(p) BOOST_PP_IIF(p(91), 91, 92)
#                        define BOOST_PP_NODE_94(p) BOOST_PP_IIF(p(94), BOOST_PP_NODE_93, BOOST_PP_NODE_95)
#                            define BOOST_PP_NODE_93(p) BOOST_PP_IIF(p(93), 93, 94)
#                            define BOOST_PP_NODE_95(p) BOOST_PP_IIF(p(95), 95, 96)
#            define BOOST_PP_NODE_112(p) BOOST_PP_IIF(p(112), BOOST_PP_NODE_104, BOOST_PP_NODE_120)
#                define BOOST_PP_NODE_104(p) BOOST_PP_IIF(p(104), BOOST_PP_NODE_100, BOOST_PP_NODE_108)
#                    define BOOST_PP_NODE_100(p) BOOST_PP_IIF(p(100), BOOST_PP_NODE_98, BOOST_PP_NODE_102)
#                        define BOOST_PP_NODE_98(p) BOOST_PP_IIF(p(98), BOOST_PP_NODE_97, BOOST_PP_NODE_99)
#                            define BOOST_PP_NODE_97(p) BOOST_PP_IIF(p(97), 97, 98)
#                            define BOOST_PP_NODE_99(p) BOOST_PP_IIF(p(99), 99, 100)
#                        define BOOST_PP_NODE_102(p) BOOST_PP_IIF(p(102), BOOST_PP_NODE_101, BOOST_PP_NODE_103)
#                            define BOOST_PP_NODE_101(p) BOOST_PP_IIF(p(101), 101, 102)
#                            define BOOST_PP_NODE_103(p) BOOST_PP_IIF(p(103), 103, 104)
#                    define BOOST_PP_NODE_108(p) BOOST_PP_IIF(p(108), BOOST_PP_NODE_106, BOOST_PP_NODE_110)
#                        define BOOST_PP_NODE_106(p) BOOST_PP_IIF(p(106), BOOST_PP_NODE_105, BOOST_PP_NODE_107)
#                            define BOOST_PP_NODE_105(p) BOOST_PP_IIF(p(105), 105, 106)
#                            define BOOST_PP_NODE_107(p) BOOST_PP_IIF(p(107), 107, 108)
#                        define BOOST_PP_NODE_110(p) BOOST_PP_IIF(p(110), BOOST_PP_NODE_109, BOOST_PP_NODE_111)
#                            define BOOST_PP_NODE_109(p) BOOST_PP_IIF(p(109), 109, 110)
#                            define BOOST_PP_NODE_111(p) BOOST_PP_IIF(p(111), 111, 112)
#                define BOOST_PP_NODE_120(p) BOOST_PP_IIF(p(120), BOOST_PP_NODE_116, BOOST_PP_NODE_124)
#                    define BOOST_PP_NODE_116(p) BOOST_PP_IIF(p(116), BOOST_PP_NODE_114, BOOST_PP_NODE_118)
#                        define BOOST_PP_NODE_114(p) BOOST_PP_IIF(p(114), BOOST_PP_NODE_113, BOOST_PP_NODE_115)
#                            define BOOST_PP_NODE_113(p) BOOST_PP_IIF(p(113), 113, 114)
#                            define BOOST_PP_NODE_115(p) BOOST_PP_IIF(p(115), 115, 116)
#                        define BOOST_PP_NODE_118(p) BOOST_PP_IIF(p(118), BOOST_PP_NODE_117, BOOST_PP_NODE_119)
#                            define BOOST_PP_NODE_117(p) BOOST_PP_IIF(p(117), 117, 118)
#                            define BOOST_PP_NODE_119(p) BOOST_PP_IIF(p(119), 119, 120)
#                    define BOOST_PP_NODE_124(p) BOOST_PP_IIF(p(124), BOOST_PP_NODE_122, BOOST_PP_NODE_126)
#                        define BOOST_PP_NODE_122(p) BOOST_PP_IIF(p(122), BOOST_PP_NODE_121, BOOST_PP_NODE_123)
#                            define BOOST_PP_NODE_121(p) BOOST_PP_IIF(p(121), 121, 122)
#                            define BOOST_PP_NODE_123(p) BOOST_PP_IIF(p(123), 123, 124)
#                        define BOOST_PP_NODE_126(p) BOOST_PP_IIF(p(126), BOOST_PP_NODE_125, BOOST_PP_NODE_127)
#                            define BOOST_PP_NODE_125(p) BOOST_PP_IIF(p(125), 125, 126)
#                            define BOOST_PP_NODE_127(p) BOOST_PP_IIF(p(127), 127, 128)
#    define BOOST_PP_NODE_192(p) BOOST_PP_IIF(p(192), BOOST_PP_NODE_160, BOOST_PP_NODE_224)
#        define BOOST_PP_NODE_160(p) BOOST_PP_IIF(p(160), BOOST_PP_NODE_144, BOOST_PP_NODE_176)
#            define BOOST_PP_NODE_144(p) BOOST_PP_IIF(p(144), BOOST_PP_NODE_136, BOOST_PP_NODE_152)
#                define BOOST_PP_NODE_136(p) BOOST_PP_IIF(p(136), BOOST_PP_NODE_132, BOOST_PP_NODE_140)
#                    define BOOST_PP_NODE_132(p) BOOST_PP_IIF(p(132), BOOST_PP_NODE_130, BOOST_PP_NODE_134)
#                        define BOOST_PP_NODE_130(p) BOOST_PP_IIF(p(130), BOOST_PP_NODE_129, BOOST_PP_NODE_131)
#                            define BOOST_PP_NODE_129(p) BOOST_PP_IIF(p(129), 129, 130)
#                            define BOOST_PP_NODE_131(p) BOOST_PP_IIF(p(131), 131, 132)
#                        define BOOST_PP_NODE_134(p) BOOST_PP_IIF(p(134), BOOST_PP_NODE_133, BOOST_PP_NODE_135)
#                            define BOOST_PP_NODE_133(p) BOOST_PP_IIF(p(133), 133, 134)
#                            define BOOST_PP_NODE_135(p) BOOST_PP_IIF(p(135), 135, 136)
#                    define BOOST_PP_NODE_140(p) BOOST_PP_IIF(p(140), BOOST_PP_NODE_138, BOOST_PP_NODE_142)
#                        define BOOST_PP_NODE_138(p) BOOST_PP_IIF(p(138), BOOST_PP_NODE_137, BOOST_PP_NODE_139)
#                            define BOOST_PP_NODE_137(p) BOOST_PP_IIF(p(137), 137, 138)
#                            define BOOST_PP_NODE_139(p) BOOST_PP_IIF(p(139), 139, 140)
#                        define BOOST_PP_NODE_142(p) BOOST_PP_IIF(p(142), BOOST_PP_NODE_141, BOOST_PP_NODE_143)
#                            define BOOST_PP_NODE_141(p) BOOST_PP_IIF(p(141), 141, 142)
#                            define BOOST_PP_NODE_143(p) BOOST_PP_IIF(p(143), 143, 144)
#                define BOOST_PP_NODE_152(p) BOOST_PP_IIF(p(152), BOOST_PP_NODE_148, BOOST_PP_NODE_156)
#                    define BOOST_PP_NODE_148(p) BOOST_PP_IIF(p(148), BOOST_PP_NODE_146, BOOST_PP_NODE_150)
#                        define BOOST_PP_NODE_146(p) BOOST_PP_IIF(p(146), BOOST_PP_NODE_145, BOOST_PP_NODE_147)
#                            define BOOST_PP_NODE_145(p) BOOST_PP_IIF(p(145), 145, 146)
#                            define BOOST_PP_NODE_147(p) BOOST_PP_IIF(p(147), 147, 148)
#                        define BOOST_PP_NODE_150(p) BOOST_PP_IIF(p(150), BOOST_PP_NODE_149, BOOST_PP_NODE_151)
#                            define BOOST_PP_NODE_149(p) BOOST_PP_IIF(p(149), 149, 150)
#                            define BOOST_PP_NODE_151(p) BOOST_PP_IIF(p(151), 151, 152)
#                    define BOOST_PP_NODE_156(p) BOOST_PP_IIF(p(156), BOOST_PP_NODE_154, BOOST_PP_NODE_158)
#                        define BOOST_PP_NODE_154(p) BOOST_PP_IIF(p(154), BOOST_PP_NODE_153, BOOST_PP_NODE_155)
#                            define BOOST_PP_NODE_153(p) BOOST_PP_IIF(p(153), 153, 154)
#                            define BOOST_PP_NODE_155(p) BOOST_PP_IIF(p(155), 155, 156)
#                        define BOOST_PP_NODE_158(p) BOOST_PP_IIF(p(158), BOOST_PP_NODE_157, BOOST_PP_NODE_159)
#                            define BOOST_PP_NODE_157(p) BOOST_PP_IIF(p(157), 157, 158)
#                            define BOOST_PP_NODE_159(p) BOOST_PP_IIF(p(159), 159, 160)
#            define BOOST_PP_NODE_176(p) BOOST_PP_IIF(p(176), BOOST_PP_NODE_168, BOOST_PP_NODE_184)
#                define BOOST_PP_NODE_168(p) BOOST_PP_IIF(p(168), BOOST_PP_NODE_164, BOOST_PP_NODE_172)
#                    define BOOST_PP_NODE_164(p) BOOST_PP_IIF(p(164), BOOST_PP_NODE_162, BOOST_PP_NODE_166)
#                        define BOOST_PP_NODE_162(p) BOOST_PP_IIF(p(162), BOOST_PP_NODE_161, BOOST_PP_NODE_163)
#                            define BOOST_PP_NODE_161(p) BOOST_PP_IIF(p(161), 161, 162)
#                            define BOOST_PP_NODE_163(p) BOOST_PP_IIF(p(163), 163, 164)
#                        define BOOST_PP_NODE_166(p) BOOST_PP_IIF(p(166), BOOST_PP_NODE_165, BOOST_PP_NODE_167)
#                            define BOOST_PP_NODE_165(p) BOOST_PP_IIF(p(165), 165, 166)
#                            define BOOST_PP_NODE_167(p) BOOST_PP_IIF(p(167), 167, 168)
#                    define BOOST_PP_NODE_172(p) BOOST_PP_IIF(p(172), BOOST_PP_NODE_170, BOOST_PP_NODE_174)
#                        define BOOST_PP_NODE_170(p) BOOST_PP_IIF(p(170), BOOST_PP_NODE_169, BOOST_PP_NODE_171)
#                            define BOOST_PP_NODE_169(p) BOOST_PP_IIF(p(169), 169, 170)
#                            define BOOST_PP_NODE_171(p) BOOST_PP_IIF(p(171), 171, 172)
#                        define BOOST_PP_NODE_174(p) BOOST_PP_IIF(p(174), BOOST_PP_NODE_173, BOOST_PP_NODE_175)
#                            define BOOST_PP_NODE_173(p) BOOST_PP_IIF(p(173), 173, 174)
#                            define BOOST_PP_NODE_175(p) BOOST_PP_IIF(p(175), 175, 176)
#                define BOOST_PP_NODE_184(p) BOOST_PP_IIF(p(184), BOOST_PP_NODE_180, BOOST_PP_NODE_188)
#                    define BOOST_PP_NODE_180(p) BOOST_PP_IIF(p(180), BOOST_PP_NODE_178, BOOST_PP_NODE_182)
#                        define BOOST_PP_NODE_178(p) BOOST_PP_IIF(p(178), BOOST_PP_NODE_177, BOOST_PP_NODE_179)
#                            define BOOST_PP_NODE_177(p) BOOST_PP_IIF(p(177), 177, 178)
#                            define BOOST_PP_NODE_179(p) BOOST_PP_IIF(p(179), 179, 180)
#                        define BOOST_PP_NODE_182(p) BOOST_PP_IIF(p(182), BOOST_PP_NODE_181, BOOST_PP_NODE_183)
#                            define BOOST_PP_NODE_181(p) BOOST_PP_IIF(p(181), 181, 182)
#                            define BOOST_PP_NODE_183(p) BOOST_PP_IIF(p(183), 183, 184)
#                    define BOOST_PP_NODE_188(p) BOOST_PP_IIF(p(188), BOOST_PP_NODE_186, BOOST_PP_NODE_190)
#                        define BOOST_PP_NODE_186(p) BOOST_PP_IIF(p(186), BOOST_PP_NODE_185, BOOST_PP_NODE_187)
#                            define BOOST_PP_NODE_185(p) BOOST_PP_IIF(p(185), 185, 186)
#                            define BOOST_PP_NODE_187(p) BOOST_PP_IIF(p(187), 187, 188)
#                        define BOOST_PP_NODE_190(p) BOOST_PP_IIF(p(190), BOOST_PP_NODE_189, BOOST_PP_NODE_191)
#                            define BOOST_PP_NODE_189(p) BOOST_PP_IIF(p(189), 189, 190)
#                            define BOOST_PP_NODE_191(p) BOOST_PP_IIF(p(191), 191, 192)
#        define BOOST_PP_NODE_224(p) BOOST_PP_IIF(p(224), BOOST_PP_NODE_208, BOOST_PP_NODE_240)
#            define BOOST_PP_NODE_208(p) BOOST_PP_IIF(p(208), BOOST_PP_NODE_200, BOOST_PP_NODE_216)
#                define BOOST_PP_NODE_200(p) BOOST_PP_IIF(p(200), BOOST_PP_NODE_196, BOOST_PP_NODE_204)
#                    define BOOST_PP_NODE_196(p) BOOST_PP_IIF(p(196), BOOST_PP_NODE_194, BOOST_PP_NODE_198)
#                        define BOOST_PP_NODE_194(p) BOOST_PP_IIF(p(194), BOOST_PP_NODE_193, BOOST_PP_NODE_195)
#                            define BOOST_PP_NODE_193(p) BOOST_PP_IIF(p(193), 193, 194)
#                            define BOOST_PP_NODE_195(p) BOOST_PP_IIF(p(195), 195, 196)
#                        define BOOST_PP_NODE_198(p) BOOST_PP_IIF(p(198), BOOST_PP_NODE_197, BOOST_PP_NODE_199)
#                            define BOOST_PP_NODE_197(p) BOOST_PP_IIF(p(197), 197, 198)
#                            define BOOST_PP_NODE_199(p) BOOST_PP_IIF(p(199), 199, 200)
#                    define BOOST_PP_NODE_204(p) BOOST_PP_IIF(p(204), BOOST_PP_NODE_202, BOOST_PP_NODE_206)
#                        define BOOST_PP_NODE_202(p) BOOST_PP_IIF(p(202), BOOST_PP_NODE_201, BOOST_PP_NODE_203)
#                            define BOOST_PP_NODE_201(p) BOOST_PP_IIF(p(201), 201, 202)
#                            define BOOST_PP_NODE_203(p) BOOST_PP_IIF(p(203), 203, 204)
#                        define BOOST_PP_NODE_206(p) BOOST_PP_IIF(p(206), BOOST_PP_NODE_205, BOOST_PP_NODE_207)
#                            define BOOST_PP_NODE_205(p) BOOST_PP_IIF(p(205), 205, 206)
#                            define BOOST_PP_NODE_207(p) BOOST_PP_IIF(p(207), 207, 208)
#                define BOOST_PP_NODE_216(p) BOOST_PP_IIF(p(216), BOOST_PP_NODE_212, BOOST_PP_NODE_220)
#                    define BOOST_PP_NODE_212(p) BOOST_PP_IIF(p(212), BOOST_PP_NODE_210, BOOST_PP_NODE_214)
#                        define BOOST_PP_NODE_210(p) BOOST_PP_IIF(p(210), BOOST_PP_NODE_209, BOOST_PP_NODE_211)
#                            define BOOST_PP_NODE_209(p) BOOST_PP_IIF(p(209), 209, 210)
#                            define BOOST_PP_NODE_211(p) BOOST_PP_IIF(p(211), 211, 212)
#                        define BOOST_PP_NODE_214(p) BOOST_PP_IIF(p(214), BOOST_PP_NODE_213, BOOST_PP_NODE_215)
#                            define BOOST_PP_NODE_213(p) BOOST_PP_IIF(p(213), 213, 214)
#                            define BOOST_PP_NODE_215(p) BOOST_PP_IIF(p(215), 215, 216)
#                    define BOOST_PP_NODE_220(p) BOOST_PP_IIF(p(220), BOOST_PP_NODE_218, BOOST_PP_NODE_222)
#                        define BOOST_PP_NODE_218(p) BOOST_PP_IIF(p(218), BOOST_PP_NODE_217, BOOST_PP_NODE_219)
#                            define BOOST_PP_NODE_217(p) BOOST_PP_IIF(p(217), 217, 218)
#                            define BOOST_PP_NODE_219(p) BOOST_PP_IIF(p(219), 219, 220)
#                        define BOOST_PP_NODE_222(p) BOOST_PP_IIF(p(222), BOOST_PP_NODE_221, BOOST_PP_NODE_223)
#                            define BOOST_PP_NODE_221(p) BOOST_PP_IIF(p(221), 221, 222)
#                            define BOOST_PP_NODE_223(p) BOOST_PP_IIF(p(223), 223, 224)
#            define BOOST_PP_NODE_240(p) BOOST_PP_IIF(p(240), BOOST_PP_NODE_232, BOOST_PP_NODE_248)
#                define BOOST_PP_NODE_232(p) BOOST_PP_IIF(p(232), BOOST_PP_NODE_228, BOOST_PP_NODE_236)
#                    define BOOST_PP_NODE_228(p) BOOST_PP_IIF(p(228), BOOST_PP_NODE_226, BOOST_PP_NODE_230)
#                        define BOOST_PP_NODE_226(p) BOOST_PP_IIF(p(226), BOOST_PP_NODE_225, BOOST_PP_NODE_227)
#                            define BOOST_PP_NODE_225(p) BOOST_PP_IIF(p(225), 225, 226)
#                            define BOOST_PP_NODE_227(p) BOOST_PP_IIF(p(227), 227, 228)
#                        define BOOST_PP_NODE_230(p) BOOST_PP_IIF(p(230), BOOST_PP_NODE_229, BOOST_PP_NODE_231)
#                            define BOOST_PP_NODE_229(p) BOOST_PP_IIF(p(229), 229, 230)
#                            define BOOST_PP_NODE_231(p) BOOST_PP_IIF(p(231), 231, 232)
#                    define BOOST_PP_NODE_236(p) BOOST_PP_IIF(p(236), BOOST_PP_NODE_234, BOOST_PP_NODE_238)
#                        define BOOST_PP_NODE_234(p) BOOST_PP_IIF(p(234), BOOST_PP_NODE_233, BOOST_PP_NODE_235)
#                            define BOOST_PP_NODE_233(p) BOOST_PP_IIF(p(233), 233, 234)
#                            define BOOST_PP_NODE_235(p) BOOST_PP_IIF(p(235), 235, 236)
#                        define BOOST_PP_NODE_238(p) BOOST_PP_IIF(p(238), BOOST_PP_NODE_237, BOOST_PP_NODE_239)
#                            define BOOST_PP_NODE_237(p) BOOST_PP_IIF(p(237), 237, 238)
#                            define BOOST_PP_NODE_239(p) BOOST_PP_IIF(p(239), 239, 240)
#                define BOOST_PP_NODE_248(p) BOOST_PP_IIF(p(248), BOOST_PP_NODE_244, BOOST_PP_NODE_252)
#                    define BOOST_PP_NODE_244(p) BOOST_PP_IIF(p(244), BOOST_PP_NODE_242, BOOST_PP_NODE_246)
#                        define BOOST_PP_NODE_242(p) BOOST_PP_IIF(p(242), BOOST_PP_NODE_241, BOOST_PP_NODE_243)
#                            define BOOST_PP_NODE_241(p) BOOST_PP_IIF(p(241), 241, 242)
#                            define BOOST_PP_NODE_243(p) BOOST_PP_IIF(p(243), 243, 244)
#                        define BOOST_PP_NODE_246(p) BOOST_PP_IIF(p(246), BOOST_PP_NODE_245, BOOST_PP_NODE_247)
#                            define BOOST_PP_NODE_245(p) BOOST_PP_IIF(p(245), 245, 246)
#                            define BOOST_PP_NODE_247(p) BOOST_PP_IIF(p(247), 247, 248)
#                    define BOOST_PP_NODE_252(p) BOOST_PP_IIF(p(252), BOOST_PP_NODE_250, BOOST_PP_NODE_254)
#                        define BOOST_PP_NODE_250(p) BOOST_PP_IIF(p(250), BOOST_PP_NODE_249, BOOST_PP_NODE_251)
#                            define BOOST_PP_NODE_249(p) BOOST_PP_IIF(p(249), 249, 250)
#                            define BOOST_PP_NODE_251(p) BOOST_PP_IIF(p(251), 251, 252)
#                        define BOOST_PP_NODE_254(p) BOOST_PP_IIF(p(254), BOOST_PP_NODE_253, BOOST_PP_NODE_255)
#                            define BOOST_PP_NODE_253(p) BOOST_PP_IIF(p(253), 253, 254)
#                            define BOOST_PP_NODE_255(p) BOOST_PP_IIF(p(255), 255, 256)


//  ****************************************************************************
# /* BOOST_PP_EXPR_IIF */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_EXPR_IIF(bit, expr) BOOST_PP_EXPR_IIF_I(bit, expr)
# else
#    define BOOST_PP_EXPR_IIF(bit, expr) BOOST_PP_EXPR_IIF_OO((bit, expr))
#    define BOOST_PP_EXPR_IIF_OO(par) BOOST_PP_EXPR_IIF_I ## par
# endif
#
# define BOOST_PP_EXPR_IIF_I(bit, expr) BOOST_PP_EXPR_IIF_ ## bit(expr)
#
# define BOOST_PP_EXPR_IIF_0(expr)
# define BOOST_PP_EXPR_IIF_1(expr) expr

//  ****************************************************************************
# /* BOOST_PP_FOR */
#
# if 0
#    define BOOST_PP_FOR(state, pred, op, macro)
# endif
#
# define BOOST_PP_FOR BOOST_PP_CAT(BOOST_PP_FOR_, BOOST_PP_AUTO_REC(BOOST_PP_FOR_P, 256))
#
# define BOOST_PP_FOR_P(n) BOOST_PP_CAT(BOOST_PP_FOR_CHECK_, BOOST_PP_FOR_ ## n(1, BOOST_PP_FOR_SR_P, BOOST_PP_FOR_SR_O, BOOST_PP_FOR_SR_M))
#
# define BOOST_PP_FOR_SR_P(r, s) s
# define BOOST_PP_FOR_SR_O(r, s) 0
# define BOOST_PP_FOR_SR_M(r, s) BOOST_PP_NIL
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    include "boost_for_detail_msvc.h"
# else
#    include "boost_for_detail.h"
# endif
#
# define BOOST_PP_FOR_257(s, p, o, m) BOOST_PP_ERROR(0x0002)
#
# define BOOST_PP_FOR_CHECK_BOOST_PP_NIL 1
#
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_1(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_2(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_3(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_4(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_5(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_6(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_7(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_8(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_9(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_10(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_11(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_12(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_13(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_14(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_15(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_16(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_17(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_18(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_19(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_20(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_21(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_22(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_23(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_24(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_25(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_26(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_27(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_28(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_29(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_30(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_31(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_32(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_33(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_34(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_35(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_36(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_37(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_38(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_39(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_40(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_41(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_42(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_43(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_44(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_45(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_46(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_47(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_48(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_49(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_50(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_51(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_52(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_53(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_54(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_55(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_56(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_57(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_58(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_59(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_60(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_61(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_62(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_63(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_64(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_65(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_66(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_67(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_68(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_69(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_70(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_71(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_72(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_73(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_74(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_75(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_76(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_77(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_78(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_79(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_80(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_81(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_82(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_83(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_84(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_85(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_86(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_87(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_88(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_89(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_90(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_91(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_92(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_93(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_94(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_95(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_96(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_97(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_98(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_99(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_100(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_101(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_102(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_103(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_104(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_105(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_106(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_107(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_108(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_109(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_110(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_111(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_112(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_113(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_114(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_115(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_116(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_117(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_118(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_119(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_120(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_121(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_122(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_123(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_124(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_125(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_126(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_127(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_128(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_129(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_130(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_131(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_132(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_133(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_134(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_135(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_136(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_137(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_138(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_139(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_140(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_141(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_142(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_143(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_144(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_145(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_146(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_147(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_148(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_149(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_150(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_151(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_152(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_153(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_154(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_155(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_156(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_157(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_158(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_159(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_160(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_161(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_162(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_163(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_164(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_165(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_166(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_167(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_168(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_169(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_170(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_171(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_172(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_173(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_174(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_175(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_176(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_177(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_178(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_179(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_180(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_181(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_182(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_183(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_184(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_185(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_186(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_187(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_188(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_189(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_190(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_191(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_192(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_193(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_194(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_195(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_196(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_197(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_198(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_199(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_200(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_201(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_202(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_203(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_204(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_205(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_206(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_207(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_208(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_209(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_210(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_211(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_212(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_213(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_214(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_215(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_216(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_217(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_218(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_219(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_220(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_221(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_222(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_223(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_224(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_225(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_226(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_227(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_228(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_229(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_230(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_231(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_232(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_233(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_234(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_235(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_236(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_237(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_238(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_239(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_240(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_241(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_242(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_243(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_244(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_245(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_246(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_247(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_248(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_249(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_250(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_251(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_252(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_253(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_254(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_255(s, p, o, m) 0
# define BOOST_PP_FOR_CHECK_BOOST_PP_FOR_256(s, p, o, m) 0


//  ****************************************************************************
# /* BOOST_PP_EMPTY */
#
# define BOOST_PP_EMPTY()


//  ****************************************************************************
# /* BOOST_PP_SEQ_ELEM */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_SEQ_ELEM(i, seq) BOOST_PP_SEQ_ELEM_I(i, seq)
# else
#    define BOOST_PP_SEQ_ELEM(i, seq) BOOST_PP_SEQ_ELEM_I((i, seq))
# endif
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_SEQ_ELEM_I(i, seq) BOOST_PP_SEQ_ELEM_II((BOOST_PP_SEQ_ELEM_ ## i seq))
#    define BOOST_PP_SEQ_ELEM_II(res) BOOST_PP_SEQ_ELEM_IV(BOOST_PP_SEQ_ELEM_III res)
#    define BOOST_PP_SEQ_ELEM_III(x, _) x BOOST_PP_EMPTY()
#    define BOOST_PP_SEQ_ELEM_IV(x) x
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_SEQ_ELEM_I(par) BOOST_PP_SEQ_ELEM_II ## par
#    define BOOST_PP_SEQ_ELEM_II(i, seq) BOOST_PP_SEQ_ELEM_III(BOOST_PP_SEQ_ELEM_ ## i ## seq)
#    define BOOST_PP_SEQ_ELEM_III(im) BOOST_PP_SEQ_ELEM_IV(im)
#    define BOOST_PP_SEQ_ELEM_IV(x, _) x
# else
#    if defined(__IBMC__) || defined(__IBMCPP__)
#        define BOOST_PP_SEQ_ELEM_I(i, seq) BOOST_PP_SEQ_ELEM_II(BOOST_PP_CAT(BOOST_PP_SEQ_ELEM_ ## i, seq))
#    else
#        define BOOST_PP_SEQ_ELEM_I(i, seq) BOOST_PP_SEQ_ELEM_II(BOOST_PP_SEQ_ELEM_ ## i seq)
#    endif
#    define BOOST_PP_SEQ_ELEM_II(im) BOOST_PP_SEQ_ELEM_III(im)
#    define BOOST_PP_SEQ_ELEM_III(x, _) x
# endif
#
# define BOOST_PP_SEQ_ELEM_0(x) x, BOOST_PP_NIL
# define BOOST_PP_SEQ_ELEM_1(_) BOOST_PP_SEQ_ELEM_0
# define BOOST_PP_SEQ_ELEM_2(_) BOOST_PP_SEQ_ELEM_1
# define BOOST_PP_SEQ_ELEM_3(_) BOOST_PP_SEQ_ELEM_2
# define BOOST_PP_SEQ_ELEM_4(_) BOOST_PP_SEQ_ELEM_3
# define BOOST_PP_SEQ_ELEM_5(_) BOOST_PP_SEQ_ELEM_4
# define BOOST_PP_SEQ_ELEM_6(_) BOOST_PP_SEQ_ELEM_5
# define BOOST_PP_SEQ_ELEM_7(_) BOOST_PP_SEQ_ELEM_6
# define BOOST_PP_SEQ_ELEM_8(_) BOOST_PP_SEQ_ELEM_7
# define BOOST_PP_SEQ_ELEM_9(_) BOOST_PP_SEQ_ELEM_8
# define BOOST_PP_SEQ_ELEM_10(_) BOOST_PP_SEQ_ELEM_9
# define BOOST_PP_SEQ_ELEM_11(_) BOOST_PP_SEQ_ELEM_10
# define BOOST_PP_SEQ_ELEM_12(_) BOOST_PP_SEQ_ELEM_11
# define BOOST_PP_SEQ_ELEM_13(_) BOOST_PP_SEQ_ELEM_12
# define BOOST_PP_SEQ_ELEM_14(_) BOOST_PP_SEQ_ELEM_13
# define BOOST_PP_SEQ_ELEM_15(_) BOOST_PP_SEQ_ELEM_14
# define BOOST_PP_SEQ_ELEM_16(_) BOOST_PP_SEQ_ELEM_15
# define BOOST_PP_SEQ_ELEM_17(_) BOOST_PP_SEQ_ELEM_16
# define BOOST_PP_SEQ_ELEM_18(_) BOOST_PP_SEQ_ELEM_17
# define BOOST_PP_SEQ_ELEM_19(_) BOOST_PP_SEQ_ELEM_18
# define BOOST_PP_SEQ_ELEM_20(_) BOOST_PP_SEQ_ELEM_19
# define BOOST_PP_SEQ_ELEM_21(_) BOOST_PP_SEQ_ELEM_20
# define BOOST_PP_SEQ_ELEM_22(_) BOOST_PP_SEQ_ELEM_21
# define BOOST_PP_SEQ_ELEM_23(_) BOOST_PP_SEQ_ELEM_22
# define BOOST_PP_SEQ_ELEM_24(_) BOOST_PP_SEQ_ELEM_23
# define BOOST_PP_SEQ_ELEM_25(_) BOOST_PP_SEQ_ELEM_24
# define BOOST_PP_SEQ_ELEM_26(_) BOOST_PP_SEQ_ELEM_25
# define BOOST_PP_SEQ_ELEM_27(_) BOOST_PP_SEQ_ELEM_26
# define BOOST_PP_SEQ_ELEM_28(_) BOOST_PP_SEQ_ELEM_27
# define BOOST_PP_SEQ_ELEM_29(_) BOOST_PP_SEQ_ELEM_28
# define BOOST_PP_SEQ_ELEM_30(_) BOOST_PP_SEQ_ELEM_29
# define BOOST_PP_SEQ_ELEM_31(_) BOOST_PP_SEQ_ELEM_30
# define BOOST_PP_SEQ_ELEM_32(_) BOOST_PP_SEQ_ELEM_31
# define BOOST_PP_SEQ_ELEM_33(_) BOOST_PP_SEQ_ELEM_32
# define BOOST_PP_SEQ_ELEM_34(_) BOOST_PP_SEQ_ELEM_33
# define BOOST_PP_SEQ_ELEM_35(_) BOOST_PP_SEQ_ELEM_34
# define BOOST_PP_SEQ_ELEM_36(_) BOOST_PP_SEQ_ELEM_35
# define BOOST_PP_SEQ_ELEM_37(_) BOOST_PP_SEQ_ELEM_36
# define BOOST_PP_SEQ_ELEM_38(_) BOOST_PP_SEQ_ELEM_37
# define BOOST_PP_SEQ_ELEM_39(_) BOOST_PP_SEQ_ELEM_38
# define BOOST_PP_SEQ_ELEM_40(_) BOOST_PP_SEQ_ELEM_39
# define BOOST_PP_SEQ_ELEM_41(_) BOOST_PP_SEQ_ELEM_40
# define BOOST_PP_SEQ_ELEM_42(_) BOOST_PP_SEQ_ELEM_41
# define BOOST_PP_SEQ_ELEM_43(_) BOOST_PP_SEQ_ELEM_42
# define BOOST_PP_SEQ_ELEM_44(_) BOOST_PP_SEQ_ELEM_43
# define BOOST_PP_SEQ_ELEM_45(_) BOOST_PP_SEQ_ELEM_44
# define BOOST_PP_SEQ_ELEM_46(_) BOOST_PP_SEQ_ELEM_45
# define BOOST_PP_SEQ_ELEM_47(_) BOOST_PP_SEQ_ELEM_46
# define BOOST_PP_SEQ_ELEM_48(_) BOOST_PP_SEQ_ELEM_47
# define BOOST_PP_SEQ_ELEM_49(_) BOOST_PP_SEQ_ELEM_48
# define BOOST_PP_SEQ_ELEM_50(_) BOOST_PP_SEQ_ELEM_49
# define BOOST_PP_SEQ_ELEM_51(_) BOOST_PP_SEQ_ELEM_50
# define BOOST_PP_SEQ_ELEM_52(_) BOOST_PP_SEQ_ELEM_51
# define BOOST_PP_SEQ_ELEM_53(_) BOOST_PP_SEQ_ELEM_52
# define BOOST_PP_SEQ_ELEM_54(_) BOOST_PP_SEQ_ELEM_53
# define BOOST_PP_SEQ_ELEM_55(_) BOOST_PP_SEQ_ELEM_54
# define BOOST_PP_SEQ_ELEM_56(_) BOOST_PP_SEQ_ELEM_55
# define BOOST_PP_SEQ_ELEM_57(_) BOOST_PP_SEQ_ELEM_56
# define BOOST_PP_SEQ_ELEM_58(_) BOOST_PP_SEQ_ELEM_57
# define BOOST_PP_SEQ_ELEM_59(_) BOOST_PP_SEQ_ELEM_58
# define BOOST_PP_SEQ_ELEM_60(_) BOOST_PP_SEQ_ELEM_59
# define BOOST_PP_SEQ_ELEM_61(_) BOOST_PP_SEQ_ELEM_60
# define BOOST_PP_SEQ_ELEM_62(_) BOOST_PP_SEQ_ELEM_61
# define BOOST_PP_SEQ_ELEM_63(_) BOOST_PP_SEQ_ELEM_62
# define BOOST_PP_SEQ_ELEM_64(_) BOOST_PP_SEQ_ELEM_63
# define BOOST_PP_SEQ_ELEM_65(_) BOOST_PP_SEQ_ELEM_64
# define BOOST_PP_SEQ_ELEM_66(_) BOOST_PP_SEQ_ELEM_65
# define BOOST_PP_SEQ_ELEM_67(_) BOOST_PP_SEQ_ELEM_66
# define BOOST_PP_SEQ_ELEM_68(_) BOOST_PP_SEQ_ELEM_67
# define BOOST_PP_SEQ_ELEM_69(_) BOOST_PP_SEQ_ELEM_68
# define BOOST_PP_SEQ_ELEM_70(_) BOOST_PP_SEQ_ELEM_69
# define BOOST_PP_SEQ_ELEM_71(_) BOOST_PP_SEQ_ELEM_70
# define BOOST_PP_SEQ_ELEM_72(_) BOOST_PP_SEQ_ELEM_71
# define BOOST_PP_SEQ_ELEM_73(_) BOOST_PP_SEQ_ELEM_72
# define BOOST_PP_SEQ_ELEM_74(_) BOOST_PP_SEQ_ELEM_73
# define BOOST_PP_SEQ_ELEM_75(_) BOOST_PP_SEQ_ELEM_74
# define BOOST_PP_SEQ_ELEM_76(_) BOOST_PP_SEQ_ELEM_75
# define BOOST_PP_SEQ_ELEM_77(_) BOOST_PP_SEQ_ELEM_76
# define BOOST_PP_SEQ_ELEM_78(_) BOOST_PP_SEQ_ELEM_77
# define BOOST_PP_SEQ_ELEM_79(_) BOOST_PP_SEQ_ELEM_78
# define BOOST_PP_SEQ_ELEM_80(_) BOOST_PP_SEQ_ELEM_79
# define BOOST_PP_SEQ_ELEM_81(_) BOOST_PP_SEQ_ELEM_80
# define BOOST_PP_SEQ_ELEM_82(_) BOOST_PP_SEQ_ELEM_81
# define BOOST_PP_SEQ_ELEM_83(_) BOOST_PP_SEQ_ELEM_82
# define BOOST_PP_SEQ_ELEM_84(_) BOOST_PP_SEQ_ELEM_83
# define BOOST_PP_SEQ_ELEM_85(_) BOOST_PP_SEQ_ELEM_84
# define BOOST_PP_SEQ_ELEM_86(_) BOOST_PP_SEQ_ELEM_85
# define BOOST_PP_SEQ_ELEM_87(_) BOOST_PP_SEQ_ELEM_86
# define BOOST_PP_SEQ_ELEM_88(_) BOOST_PP_SEQ_ELEM_87
# define BOOST_PP_SEQ_ELEM_89(_) BOOST_PP_SEQ_ELEM_88
# define BOOST_PP_SEQ_ELEM_90(_) BOOST_PP_SEQ_ELEM_89
# define BOOST_PP_SEQ_ELEM_91(_) BOOST_PP_SEQ_ELEM_90
# define BOOST_PP_SEQ_ELEM_92(_) BOOST_PP_SEQ_ELEM_91
# define BOOST_PP_SEQ_ELEM_93(_) BOOST_PP_SEQ_ELEM_92
# define BOOST_PP_SEQ_ELEM_94(_) BOOST_PP_SEQ_ELEM_93
# define BOOST_PP_SEQ_ELEM_95(_) BOOST_PP_SEQ_ELEM_94
# define BOOST_PP_SEQ_ELEM_96(_) BOOST_PP_SEQ_ELEM_95
# define BOOST_PP_SEQ_ELEM_97(_) BOOST_PP_SEQ_ELEM_96
# define BOOST_PP_SEQ_ELEM_98(_) BOOST_PP_SEQ_ELEM_97
# define BOOST_PP_SEQ_ELEM_99(_) BOOST_PP_SEQ_ELEM_98
# define BOOST_PP_SEQ_ELEM_100(_) BOOST_PP_SEQ_ELEM_99
# define BOOST_PP_SEQ_ELEM_101(_) BOOST_PP_SEQ_ELEM_100
# define BOOST_PP_SEQ_ELEM_102(_) BOOST_PP_SEQ_ELEM_101
# define BOOST_PP_SEQ_ELEM_103(_) BOOST_PP_SEQ_ELEM_102
# define BOOST_PP_SEQ_ELEM_104(_) BOOST_PP_SEQ_ELEM_103
# define BOOST_PP_SEQ_ELEM_105(_) BOOST_PP_SEQ_ELEM_104
# define BOOST_PP_SEQ_ELEM_106(_) BOOST_PP_SEQ_ELEM_105
# define BOOST_PP_SEQ_ELEM_107(_) BOOST_PP_SEQ_ELEM_106
# define BOOST_PP_SEQ_ELEM_108(_) BOOST_PP_SEQ_ELEM_107
# define BOOST_PP_SEQ_ELEM_109(_) BOOST_PP_SEQ_ELEM_108
# define BOOST_PP_SEQ_ELEM_110(_) BOOST_PP_SEQ_ELEM_109
# define BOOST_PP_SEQ_ELEM_111(_) BOOST_PP_SEQ_ELEM_110
# define BOOST_PP_SEQ_ELEM_112(_) BOOST_PP_SEQ_ELEM_111
# define BOOST_PP_SEQ_ELEM_113(_) BOOST_PP_SEQ_ELEM_112
# define BOOST_PP_SEQ_ELEM_114(_) BOOST_PP_SEQ_ELEM_113
# define BOOST_PP_SEQ_ELEM_115(_) BOOST_PP_SEQ_ELEM_114
# define BOOST_PP_SEQ_ELEM_116(_) BOOST_PP_SEQ_ELEM_115
# define BOOST_PP_SEQ_ELEM_117(_) BOOST_PP_SEQ_ELEM_116
# define BOOST_PP_SEQ_ELEM_118(_) BOOST_PP_SEQ_ELEM_117
# define BOOST_PP_SEQ_ELEM_119(_) BOOST_PP_SEQ_ELEM_118
# define BOOST_PP_SEQ_ELEM_120(_) BOOST_PP_SEQ_ELEM_119
# define BOOST_PP_SEQ_ELEM_121(_) BOOST_PP_SEQ_ELEM_120
# define BOOST_PP_SEQ_ELEM_122(_) BOOST_PP_SEQ_ELEM_121
# define BOOST_PP_SEQ_ELEM_123(_) BOOST_PP_SEQ_ELEM_122
# define BOOST_PP_SEQ_ELEM_124(_) BOOST_PP_SEQ_ELEM_123
# define BOOST_PP_SEQ_ELEM_125(_) BOOST_PP_SEQ_ELEM_124
# define BOOST_PP_SEQ_ELEM_126(_) BOOST_PP_SEQ_ELEM_125
# define BOOST_PP_SEQ_ELEM_127(_) BOOST_PP_SEQ_ELEM_126
# define BOOST_PP_SEQ_ELEM_128(_) BOOST_PP_SEQ_ELEM_127
# define BOOST_PP_SEQ_ELEM_129(_) BOOST_PP_SEQ_ELEM_128
# define BOOST_PP_SEQ_ELEM_130(_) BOOST_PP_SEQ_ELEM_129
# define BOOST_PP_SEQ_ELEM_131(_) BOOST_PP_SEQ_ELEM_130
# define BOOST_PP_SEQ_ELEM_132(_) BOOST_PP_SEQ_ELEM_131
# define BOOST_PP_SEQ_ELEM_133(_) BOOST_PP_SEQ_ELEM_132
# define BOOST_PP_SEQ_ELEM_134(_) BOOST_PP_SEQ_ELEM_133
# define BOOST_PP_SEQ_ELEM_135(_) BOOST_PP_SEQ_ELEM_134
# define BOOST_PP_SEQ_ELEM_136(_) BOOST_PP_SEQ_ELEM_135
# define BOOST_PP_SEQ_ELEM_137(_) BOOST_PP_SEQ_ELEM_136
# define BOOST_PP_SEQ_ELEM_138(_) BOOST_PP_SEQ_ELEM_137
# define BOOST_PP_SEQ_ELEM_139(_) BOOST_PP_SEQ_ELEM_138
# define BOOST_PP_SEQ_ELEM_140(_) BOOST_PP_SEQ_ELEM_139
# define BOOST_PP_SEQ_ELEM_141(_) BOOST_PP_SEQ_ELEM_140
# define BOOST_PP_SEQ_ELEM_142(_) BOOST_PP_SEQ_ELEM_141
# define BOOST_PP_SEQ_ELEM_143(_) BOOST_PP_SEQ_ELEM_142
# define BOOST_PP_SEQ_ELEM_144(_) BOOST_PP_SEQ_ELEM_143
# define BOOST_PP_SEQ_ELEM_145(_) BOOST_PP_SEQ_ELEM_144
# define BOOST_PP_SEQ_ELEM_146(_) BOOST_PP_SEQ_ELEM_145
# define BOOST_PP_SEQ_ELEM_147(_) BOOST_PP_SEQ_ELEM_146
# define BOOST_PP_SEQ_ELEM_148(_) BOOST_PP_SEQ_ELEM_147
# define BOOST_PP_SEQ_ELEM_149(_) BOOST_PP_SEQ_ELEM_148
# define BOOST_PP_SEQ_ELEM_150(_) BOOST_PP_SEQ_ELEM_149
# define BOOST_PP_SEQ_ELEM_151(_) BOOST_PP_SEQ_ELEM_150
# define BOOST_PP_SEQ_ELEM_152(_) BOOST_PP_SEQ_ELEM_151
# define BOOST_PP_SEQ_ELEM_153(_) BOOST_PP_SEQ_ELEM_152
# define BOOST_PP_SEQ_ELEM_154(_) BOOST_PP_SEQ_ELEM_153
# define BOOST_PP_SEQ_ELEM_155(_) BOOST_PP_SEQ_ELEM_154
# define BOOST_PP_SEQ_ELEM_156(_) BOOST_PP_SEQ_ELEM_155
# define BOOST_PP_SEQ_ELEM_157(_) BOOST_PP_SEQ_ELEM_156
# define BOOST_PP_SEQ_ELEM_158(_) BOOST_PP_SEQ_ELEM_157
# define BOOST_PP_SEQ_ELEM_159(_) BOOST_PP_SEQ_ELEM_158
# define BOOST_PP_SEQ_ELEM_160(_) BOOST_PP_SEQ_ELEM_159
# define BOOST_PP_SEQ_ELEM_161(_) BOOST_PP_SEQ_ELEM_160
# define BOOST_PP_SEQ_ELEM_162(_) BOOST_PP_SEQ_ELEM_161
# define BOOST_PP_SEQ_ELEM_163(_) BOOST_PP_SEQ_ELEM_162
# define BOOST_PP_SEQ_ELEM_164(_) BOOST_PP_SEQ_ELEM_163
# define BOOST_PP_SEQ_ELEM_165(_) BOOST_PP_SEQ_ELEM_164
# define BOOST_PP_SEQ_ELEM_166(_) BOOST_PP_SEQ_ELEM_165
# define BOOST_PP_SEQ_ELEM_167(_) BOOST_PP_SEQ_ELEM_166
# define BOOST_PP_SEQ_ELEM_168(_) BOOST_PP_SEQ_ELEM_167
# define BOOST_PP_SEQ_ELEM_169(_) BOOST_PP_SEQ_ELEM_168
# define BOOST_PP_SEQ_ELEM_170(_) BOOST_PP_SEQ_ELEM_169
# define BOOST_PP_SEQ_ELEM_171(_) BOOST_PP_SEQ_ELEM_170
# define BOOST_PP_SEQ_ELEM_172(_) BOOST_PP_SEQ_ELEM_171
# define BOOST_PP_SEQ_ELEM_173(_) BOOST_PP_SEQ_ELEM_172
# define BOOST_PP_SEQ_ELEM_174(_) BOOST_PP_SEQ_ELEM_173
# define BOOST_PP_SEQ_ELEM_175(_) BOOST_PP_SEQ_ELEM_174
# define BOOST_PP_SEQ_ELEM_176(_) BOOST_PP_SEQ_ELEM_175
# define BOOST_PP_SEQ_ELEM_177(_) BOOST_PP_SEQ_ELEM_176
# define BOOST_PP_SEQ_ELEM_178(_) BOOST_PP_SEQ_ELEM_177
# define BOOST_PP_SEQ_ELEM_179(_) BOOST_PP_SEQ_ELEM_178
# define BOOST_PP_SEQ_ELEM_180(_) BOOST_PP_SEQ_ELEM_179
# define BOOST_PP_SEQ_ELEM_181(_) BOOST_PP_SEQ_ELEM_180
# define BOOST_PP_SEQ_ELEM_182(_) BOOST_PP_SEQ_ELEM_181
# define BOOST_PP_SEQ_ELEM_183(_) BOOST_PP_SEQ_ELEM_182
# define BOOST_PP_SEQ_ELEM_184(_) BOOST_PP_SEQ_ELEM_183
# define BOOST_PP_SEQ_ELEM_185(_) BOOST_PP_SEQ_ELEM_184
# define BOOST_PP_SEQ_ELEM_186(_) BOOST_PP_SEQ_ELEM_185
# define BOOST_PP_SEQ_ELEM_187(_) BOOST_PP_SEQ_ELEM_186
# define BOOST_PP_SEQ_ELEM_188(_) BOOST_PP_SEQ_ELEM_187
# define BOOST_PP_SEQ_ELEM_189(_) BOOST_PP_SEQ_ELEM_188
# define BOOST_PP_SEQ_ELEM_190(_) BOOST_PP_SEQ_ELEM_189
# define BOOST_PP_SEQ_ELEM_191(_) BOOST_PP_SEQ_ELEM_190
# define BOOST_PP_SEQ_ELEM_192(_) BOOST_PP_SEQ_ELEM_191
# define BOOST_PP_SEQ_ELEM_193(_) BOOST_PP_SEQ_ELEM_192
# define BOOST_PP_SEQ_ELEM_194(_) BOOST_PP_SEQ_ELEM_193
# define BOOST_PP_SEQ_ELEM_195(_) BOOST_PP_SEQ_ELEM_194
# define BOOST_PP_SEQ_ELEM_196(_) BOOST_PP_SEQ_ELEM_195
# define BOOST_PP_SEQ_ELEM_197(_) BOOST_PP_SEQ_ELEM_196
# define BOOST_PP_SEQ_ELEM_198(_) BOOST_PP_SEQ_ELEM_197
# define BOOST_PP_SEQ_ELEM_199(_) BOOST_PP_SEQ_ELEM_198
# define BOOST_PP_SEQ_ELEM_200(_) BOOST_PP_SEQ_ELEM_199
# define BOOST_PP_SEQ_ELEM_201(_) BOOST_PP_SEQ_ELEM_200
# define BOOST_PP_SEQ_ELEM_202(_) BOOST_PP_SEQ_ELEM_201
# define BOOST_PP_SEQ_ELEM_203(_) BOOST_PP_SEQ_ELEM_202
# define BOOST_PP_SEQ_ELEM_204(_) BOOST_PP_SEQ_ELEM_203
# define BOOST_PP_SEQ_ELEM_205(_) BOOST_PP_SEQ_ELEM_204
# define BOOST_PP_SEQ_ELEM_206(_) BOOST_PP_SEQ_ELEM_205
# define BOOST_PP_SEQ_ELEM_207(_) BOOST_PP_SEQ_ELEM_206
# define BOOST_PP_SEQ_ELEM_208(_) BOOST_PP_SEQ_ELEM_207
# define BOOST_PP_SEQ_ELEM_209(_) BOOST_PP_SEQ_ELEM_208
# define BOOST_PP_SEQ_ELEM_210(_) BOOST_PP_SEQ_ELEM_209
# define BOOST_PP_SEQ_ELEM_211(_) BOOST_PP_SEQ_ELEM_210
# define BOOST_PP_SEQ_ELEM_212(_) BOOST_PP_SEQ_ELEM_211
# define BOOST_PP_SEQ_ELEM_213(_) BOOST_PP_SEQ_ELEM_212
# define BOOST_PP_SEQ_ELEM_214(_) BOOST_PP_SEQ_ELEM_213
# define BOOST_PP_SEQ_ELEM_215(_) BOOST_PP_SEQ_ELEM_214
# define BOOST_PP_SEQ_ELEM_216(_) BOOST_PP_SEQ_ELEM_215
# define BOOST_PP_SEQ_ELEM_217(_) BOOST_PP_SEQ_ELEM_216
# define BOOST_PP_SEQ_ELEM_218(_) BOOST_PP_SEQ_ELEM_217
# define BOOST_PP_SEQ_ELEM_219(_) BOOST_PP_SEQ_ELEM_218
# define BOOST_PP_SEQ_ELEM_220(_) BOOST_PP_SEQ_ELEM_219
# define BOOST_PP_SEQ_ELEM_221(_) BOOST_PP_SEQ_ELEM_220
# define BOOST_PP_SEQ_ELEM_222(_) BOOST_PP_SEQ_ELEM_221
# define BOOST_PP_SEQ_ELEM_223(_) BOOST_PP_SEQ_ELEM_222
# define BOOST_PP_SEQ_ELEM_224(_) BOOST_PP_SEQ_ELEM_223
# define BOOST_PP_SEQ_ELEM_225(_) BOOST_PP_SEQ_ELEM_224
# define BOOST_PP_SEQ_ELEM_226(_) BOOST_PP_SEQ_ELEM_225
# define BOOST_PP_SEQ_ELEM_227(_) BOOST_PP_SEQ_ELEM_226
# define BOOST_PP_SEQ_ELEM_228(_) BOOST_PP_SEQ_ELEM_227
# define BOOST_PP_SEQ_ELEM_229(_) BOOST_PP_SEQ_ELEM_228
# define BOOST_PP_SEQ_ELEM_230(_) BOOST_PP_SEQ_ELEM_229
# define BOOST_PP_SEQ_ELEM_231(_) BOOST_PP_SEQ_ELEM_230
# define BOOST_PP_SEQ_ELEM_232(_) BOOST_PP_SEQ_ELEM_231
# define BOOST_PP_SEQ_ELEM_233(_) BOOST_PP_SEQ_ELEM_232
# define BOOST_PP_SEQ_ELEM_234(_) BOOST_PP_SEQ_ELEM_233
# define BOOST_PP_SEQ_ELEM_235(_) BOOST_PP_SEQ_ELEM_234
# define BOOST_PP_SEQ_ELEM_236(_) BOOST_PP_SEQ_ELEM_235
# define BOOST_PP_SEQ_ELEM_237(_) BOOST_PP_SEQ_ELEM_236
# define BOOST_PP_SEQ_ELEM_238(_) BOOST_PP_SEQ_ELEM_237
# define BOOST_PP_SEQ_ELEM_239(_) BOOST_PP_SEQ_ELEM_238
# define BOOST_PP_SEQ_ELEM_240(_) BOOST_PP_SEQ_ELEM_239
# define BOOST_PP_SEQ_ELEM_241(_) BOOST_PP_SEQ_ELEM_240
# define BOOST_PP_SEQ_ELEM_242(_) BOOST_PP_SEQ_ELEM_241
# define BOOST_PP_SEQ_ELEM_243(_) BOOST_PP_SEQ_ELEM_242
# define BOOST_PP_SEQ_ELEM_244(_) BOOST_PP_SEQ_ELEM_243
# define BOOST_PP_SEQ_ELEM_245(_) BOOST_PP_SEQ_ELEM_244
# define BOOST_PP_SEQ_ELEM_246(_) BOOST_PP_SEQ_ELEM_245
# define BOOST_PP_SEQ_ELEM_247(_) BOOST_PP_SEQ_ELEM_246
# define BOOST_PP_SEQ_ELEM_248(_) BOOST_PP_SEQ_ELEM_247
# define BOOST_PP_SEQ_ELEM_249(_) BOOST_PP_SEQ_ELEM_248
# define BOOST_PP_SEQ_ELEM_250(_) BOOST_PP_SEQ_ELEM_249
# define BOOST_PP_SEQ_ELEM_251(_) BOOST_PP_SEQ_ELEM_250
# define BOOST_PP_SEQ_ELEM_252(_) BOOST_PP_SEQ_ELEM_251
# define BOOST_PP_SEQ_ELEM_253(_) BOOST_PP_SEQ_ELEM_252
# define BOOST_PP_SEQ_ELEM_254(_) BOOST_PP_SEQ_ELEM_253
# define BOOST_PP_SEQ_ELEM_255(_) BOOST_PP_SEQ_ELEM_254


//  ****************************************************************************
# /* BOOST_PP_SEQ_HEAD */
#
# define BOOST_PP_SEQ_HEAD(seq) BOOST_PP_SEQ_ELEM(0, seq)
#
# /* BOOST_PP_SEQ_TAIL */
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_SEQ_TAIL(seq) BOOST_PP_SEQ_TAIL_1((seq))
#    define BOOST_PP_SEQ_TAIL_1(par) BOOST_PP_SEQ_TAIL_2 ## par
#    define BOOST_PP_SEQ_TAIL_2(seq) BOOST_PP_SEQ_TAIL_I ## seq
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_SEQ_TAIL(seq) BOOST_PP_SEQ_TAIL_ID(BOOST_PP_SEQ_TAIL_I seq)
#    define BOOST_PP_SEQ_TAIL_ID(id) id
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_SEQ_TAIL(seq) BOOST_PP_SEQ_TAIL_D(seq)
#    define BOOST_PP_SEQ_TAIL_D(seq) BOOST_PP_SEQ_TAIL_I seq
# else
#    define BOOST_PP_SEQ_TAIL(seq) BOOST_PP_SEQ_TAIL_I seq
# endif
#
# define BOOST_PP_SEQ_TAIL_I(x)
#
# /* BOOST_PP_SEQ_NIL */
#
# define BOOST_PP_SEQ_NIL(x) (x)


//  ****************************************************************************
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_SEQ_SIZE_I((seq))
#    define BOOST_PP_SEQ_SIZE_I(par) BOOST_PP_SEQ_SIZE_II ## par
#    define BOOST_PP_SEQ_SIZE_II(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_SEQ_SIZE_0 ## seq)
# elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG() || BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_SEQ_SIZE_I(seq)
#    define BOOST_PP_SEQ_SIZE_I(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_SEQ_SIZE_0 seq)
# elif defined(__IBMC__) || defined(__IBMCPP__)
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_0, seq))
# else
#    define BOOST_PP_SEQ_SIZE(seq) BOOST_PP_CAT(BOOST_PP_SEQ_SIZE_, BOOST_PP_SEQ_SIZE_0 seq)
# endif
#
# define BOOST_PP_SEQ_SIZE_0(_) BOOST_PP_SEQ_SIZE_1
# define BOOST_PP_SEQ_SIZE_1(_) BOOST_PP_SEQ_SIZE_2
# define BOOST_PP_SEQ_SIZE_2(_) BOOST_PP_SEQ_SIZE_3
# define BOOST_PP_SEQ_SIZE_3(_) BOOST_PP_SEQ_SIZE_4
# define BOOST_PP_SEQ_SIZE_4(_) BOOST_PP_SEQ_SIZE_5
# define BOOST_PP_SEQ_SIZE_5(_) BOOST_PP_SEQ_SIZE_6
# define BOOST_PP_SEQ_SIZE_6(_) BOOST_PP_SEQ_SIZE_7
# define BOOST_PP_SEQ_SIZE_7(_) BOOST_PP_SEQ_SIZE_8
# define BOOST_PP_SEQ_SIZE_8(_) BOOST_PP_SEQ_SIZE_9
# define BOOST_PP_SEQ_SIZE_9(_) BOOST_PP_SEQ_SIZE_10
# define BOOST_PP_SEQ_SIZE_10(_) BOOST_PP_SEQ_SIZE_11
# define BOOST_PP_SEQ_SIZE_11(_) BOOST_PP_SEQ_SIZE_12
# define BOOST_PP_SEQ_SIZE_12(_) BOOST_PP_SEQ_SIZE_13
# define BOOST_PP_SEQ_SIZE_13(_) BOOST_PP_SEQ_SIZE_14
# define BOOST_PP_SEQ_SIZE_14(_) BOOST_PP_SEQ_SIZE_15
# define BOOST_PP_SEQ_SIZE_15(_) BOOST_PP_SEQ_SIZE_16
# define BOOST_PP_SEQ_SIZE_16(_) BOOST_PP_SEQ_SIZE_17
# define BOOST_PP_SEQ_SIZE_17(_) BOOST_PP_SEQ_SIZE_18
# define BOOST_PP_SEQ_SIZE_18(_) BOOST_PP_SEQ_SIZE_19
# define BOOST_PP_SEQ_SIZE_19(_) BOOST_PP_SEQ_SIZE_20
# define BOOST_PP_SEQ_SIZE_20(_) BOOST_PP_SEQ_SIZE_21
# define BOOST_PP_SEQ_SIZE_21(_) BOOST_PP_SEQ_SIZE_22
# define BOOST_PP_SEQ_SIZE_22(_) BOOST_PP_SEQ_SIZE_23
# define BOOST_PP_SEQ_SIZE_23(_) BOOST_PP_SEQ_SIZE_24
# define BOOST_PP_SEQ_SIZE_24(_) BOOST_PP_SEQ_SIZE_25
# define BOOST_PP_SEQ_SIZE_25(_) BOOST_PP_SEQ_SIZE_26
# define BOOST_PP_SEQ_SIZE_26(_) BOOST_PP_SEQ_SIZE_27
# define BOOST_PP_SEQ_SIZE_27(_) BOOST_PP_SEQ_SIZE_28
# define BOOST_PP_SEQ_SIZE_28(_) BOOST_PP_SEQ_SIZE_29
# define BOOST_PP_SEQ_SIZE_29(_) BOOST_PP_SEQ_SIZE_30
# define BOOST_PP_SEQ_SIZE_30(_) BOOST_PP_SEQ_SIZE_31
# define BOOST_PP_SEQ_SIZE_31(_) BOOST_PP_SEQ_SIZE_32
# define BOOST_PP_SEQ_SIZE_32(_) BOOST_PP_SEQ_SIZE_33
# define BOOST_PP_SEQ_SIZE_33(_) BOOST_PP_SEQ_SIZE_34
# define BOOST_PP_SEQ_SIZE_34(_) BOOST_PP_SEQ_SIZE_35
# define BOOST_PP_SEQ_SIZE_35(_) BOOST_PP_SEQ_SIZE_36
# define BOOST_PP_SEQ_SIZE_36(_) BOOST_PP_SEQ_SIZE_37
# define BOOST_PP_SEQ_SIZE_37(_) BOOST_PP_SEQ_SIZE_38
# define BOOST_PP_SEQ_SIZE_38(_) BOOST_PP_SEQ_SIZE_39
# define BOOST_PP_SEQ_SIZE_39(_) BOOST_PP_SEQ_SIZE_40
# define BOOST_PP_SEQ_SIZE_40(_) BOOST_PP_SEQ_SIZE_41
# define BOOST_PP_SEQ_SIZE_41(_) BOOST_PP_SEQ_SIZE_42
# define BOOST_PP_SEQ_SIZE_42(_) BOOST_PP_SEQ_SIZE_43
# define BOOST_PP_SEQ_SIZE_43(_) BOOST_PP_SEQ_SIZE_44
# define BOOST_PP_SEQ_SIZE_44(_) BOOST_PP_SEQ_SIZE_45
# define BOOST_PP_SEQ_SIZE_45(_) BOOST_PP_SEQ_SIZE_46
# define BOOST_PP_SEQ_SIZE_46(_) BOOST_PP_SEQ_SIZE_47
# define BOOST_PP_SEQ_SIZE_47(_) BOOST_PP_SEQ_SIZE_48
# define BOOST_PP_SEQ_SIZE_48(_) BOOST_PP_SEQ_SIZE_49
# define BOOST_PP_SEQ_SIZE_49(_) BOOST_PP_SEQ_SIZE_50
# define BOOST_PP_SEQ_SIZE_50(_) BOOST_PP_SEQ_SIZE_51
# define BOOST_PP_SEQ_SIZE_51(_) BOOST_PP_SEQ_SIZE_52
# define BOOST_PP_SEQ_SIZE_52(_) BOOST_PP_SEQ_SIZE_53
# define BOOST_PP_SEQ_SIZE_53(_) BOOST_PP_SEQ_SIZE_54
# define BOOST_PP_SEQ_SIZE_54(_) BOOST_PP_SEQ_SIZE_55
# define BOOST_PP_SEQ_SIZE_55(_) BOOST_PP_SEQ_SIZE_56
# define BOOST_PP_SEQ_SIZE_56(_) BOOST_PP_SEQ_SIZE_57
# define BOOST_PP_SEQ_SIZE_57(_) BOOST_PP_SEQ_SIZE_58
# define BOOST_PP_SEQ_SIZE_58(_) BOOST_PP_SEQ_SIZE_59
# define BOOST_PP_SEQ_SIZE_59(_) BOOST_PP_SEQ_SIZE_60
# define BOOST_PP_SEQ_SIZE_60(_) BOOST_PP_SEQ_SIZE_61
# define BOOST_PP_SEQ_SIZE_61(_) BOOST_PP_SEQ_SIZE_62
# define BOOST_PP_SEQ_SIZE_62(_) BOOST_PP_SEQ_SIZE_63
# define BOOST_PP_SEQ_SIZE_63(_) BOOST_PP_SEQ_SIZE_64
# define BOOST_PP_SEQ_SIZE_64(_) BOOST_PP_SEQ_SIZE_65
# define BOOST_PP_SEQ_SIZE_65(_) BOOST_PP_SEQ_SIZE_66
# define BOOST_PP_SEQ_SIZE_66(_) BOOST_PP_SEQ_SIZE_67
# define BOOST_PP_SEQ_SIZE_67(_) BOOST_PP_SEQ_SIZE_68
# define BOOST_PP_SEQ_SIZE_68(_) BOOST_PP_SEQ_SIZE_69
# define BOOST_PP_SEQ_SIZE_69(_) BOOST_PP_SEQ_SIZE_70
# define BOOST_PP_SEQ_SIZE_70(_) BOOST_PP_SEQ_SIZE_71
# define BOOST_PP_SEQ_SIZE_71(_) BOOST_PP_SEQ_SIZE_72
# define BOOST_PP_SEQ_SIZE_72(_) BOOST_PP_SEQ_SIZE_73
# define BOOST_PP_SEQ_SIZE_73(_) BOOST_PP_SEQ_SIZE_74
# define BOOST_PP_SEQ_SIZE_74(_) BOOST_PP_SEQ_SIZE_75
# define BOOST_PP_SEQ_SIZE_75(_) BOOST_PP_SEQ_SIZE_76
# define BOOST_PP_SEQ_SIZE_76(_) BOOST_PP_SEQ_SIZE_77
# define BOOST_PP_SEQ_SIZE_77(_) BOOST_PP_SEQ_SIZE_78
# define BOOST_PP_SEQ_SIZE_78(_) BOOST_PP_SEQ_SIZE_79
# define BOOST_PP_SEQ_SIZE_79(_) BOOST_PP_SEQ_SIZE_80
# define BOOST_PP_SEQ_SIZE_80(_) BOOST_PP_SEQ_SIZE_81
# define BOOST_PP_SEQ_SIZE_81(_) BOOST_PP_SEQ_SIZE_82
# define BOOST_PP_SEQ_SIZE_82(_) BOOST_PP_SEQ_SIZE_83
# define BOOST_PP_SEQ_SIZE_83(_) BOOST_PP_SEQ_SIZE_84
# define BOOST_PP_SEQ_SIZE_84(_) BOOST_PP_SEQ_SIZE_85
# define BOOST_PP_SEQ_SIZE_85(_) BOOST_PP_SEQ_SIZE_86
# define BOOST_PP_SEQ_SIZE_86(_) BOOST_PP_SEQ_SIZE_87
# define BOOST_PP_SEQ_SIZE_87(_) BOOST_PP_SEQ_SIZE_88
# define BOOST_PP_SEQ_SIZE_88(_) BOOST_PP_SEQ_SIZE_89
# define BOOST_PP_SEQ_SIZE_89(_) BOOST_PP_SEQ_SIZE_90
# define BOOST_PP_SEQ_SIZE_90(_) BOOST_PP_SEQ_SIZE_91
# define BOOST_PP_SEQ_SIZE_91(_) BOOST_PP_SEQ_SIZE_92
# define BOOST_PP_SEQ_SIZE_92(_) BOOST_PP_SEQ_SIZE_93
# define BOOST_PP_SEQ_SIZE_93(_) BOOST_PP_SEQ_SIZE_94
# define BOOST_PP_SEQ_SIZE_94(_) BOOST_PP_SEQ_SIZE_95
# define BOOST_PP_SEQ_SIZE_95(_) BOOST_PP_SEQ_SIZE_96
# define BOOST_PP_SEQ_SIZE_96(_) BOOST_PP_SEQ_SIZE_97
# define BOOST_PP_SEQ_SIZE_97(_) BOOST_PP_SEQ_SIZE_98
# define BOOST_PP_SEQ_SIZE_98(_) BOOST_PP_SEQ_SIZE_99
# define BOOST_PP_SEQ_SIZE_99(_) BOOST_PP_SEQ_SIZE_100
# define BOOST_PP_SEQ_SIZE_100(_) BOOST_PP_SEQ_SIZE_101
# define BOOST_PP_SEQ_SIZE_101(_) BOOST_PP_SEQ_SIZE_102
# define BOOST_PP_SEQ_SIZE_102(_) BOOST_PP_SEQ_SIZE_103
# define BOOST_PP_SEQ_SIZE_103(_) BOOST_PP_SEQ_SIZE_104
# define BOOST_PP_SEQ_SIZE_104(_) BOOST_PP_SEQ_SIZE_105
# define BOOST_PP_SEQ_SIZE_105(_) BOOST_PP_SEQ_SIZE_106
# define BOOST_PP_SEQ_SIZE_106(_) BOOST_PP_SEQ_SIZE_107
# define BOOST_PP_SEQ_SIZE_107(_) BOOST_PP_SEQ_SIZE_108
# define BOOST_PP_SEQ_SIZE_108(_) BOOST_PP_SEQ_SIZE_109
# define BOOST_PP_SEQ_SIZE_109(_) BOOST_PP_SEQ_SIZE_110
# define BOOST_PP_SEQ_SIZE_110(_) BOOST_PP_SEQ_SIZE_111
# define BOOST_PP_SEQ_SIZE_111(_) BOOST_PP_SEQ_SIZE_112
# define BOOST_PP_SEQ_SIZE_112(_) BOOST_PP_SEQ_SIZE_113
# define BOOST_PP_SEQ_SIZE_113(_) BOOST_PP_SEQ_SIZE_114
# define BOOST_PP_SEQ_SIZE_114(_) BOOST_PP_SEQ_SIZE_115
# define BOOST_PP_SEQ_SIZE_115(_) BOOST_PP_SEQ_SIZE_116
# define BOOST_PP_SEQ_SIZE_116(_) BOOST_PP_SEQ_SIZE_117
# define BOOST_PP_SEQ_SIZE_117(_) BOOST_PP_SEQ_SIZE_118
# define BOOST_PP_SEQ_SIZE_118(_) BOOST_PP_SEQ_SIZE_119
# define BOOST_PP_SEQ_SIZE_119(_) BOOST_PP_SEQ_SIZE_120
# define BOOST_PP_SEQ_SIZE_120(_) BOOST_PP_SEQ_SIZE_121
# define BOOST_PP_SEQ_SIZE_121(_) BOOST_PP_SEQ_SIZE_122
# define BOOST_PP_SEQ_SIZE_122(_) BOOST_PP_SEQ_SIZE_123
# define BOOST_PP_SEQ_SIZE_123(_) BOOST_PP_SEQ_SIZE_124
# define BOOST_PP_SEQ_SIZE_124(_) BOOST_PP_SEQ_SIZE_125
# define BOOST_PP_SEQ_SIZE_125(_) BOOST_PP_SEQ_SIZE_126
# define BOOST_PP_SEQ_SIZE_126(_) BOOST_PP_SEQ_SIZE_127
# define BOOST_PP_SEQ_SIZE_127(_) BOOST_PP_SEQ_SIZE_128
# define BOOST_PP_SEQ_SIZE_128(_) BOOST_PP_SEQ_SIZE_129
# define BOOST_PP_SEQ_SIZE_129(_) BOOST_PP_SEQ_SIZE_130
# define BOOST_PP_SEQ_SIZE_130(_) BOOST_PP_SEQ_SIZE_131
# define BOOST_PP_SEQ_SIZE_131(_) BOOST_PP_SEQ_SIZE_132
# define BOOST_PP_SEQ_SIZE_132(_) BOOST_PP_SEQ_SIZE_133
# define BOOST_PP_SEQ_SIZE_133(_) BOOST_PP_SEQ_SIZE_134
# define BOOST_PP_SEQ_SIZE_134(_) BOOST_PP_SEQ_SIZE_135
# define BOOST_PP_SEQ_SIZE_135(_) BOOST_PP_SEQ_SIZE_136
# define BOOST_PP_SEQ_SIZE_136(_) BOOST_PP_SEQ_SIZE_137
# define BOOST_PP_SEQ_SIZE_137(_) BOOST_PP_SEQ_SIZE_138
# define BOOST_PP_SEQ_SIZE_138(_) BOOST_PP_SEQ_SIZE_139
# define BOOST_PP_SEQ_SIZE_139(_) BOOST_PP_SEQ_SIZE_140
# define BOOST_PP_SEQ_SIZE_140(_) BOOST_PP_SEQ_SIZE_141
# define BOOST_PP_SEQ_SIZE_141(_) BOOST_PP_SEQ_SIZE_142
# define BOOST_PP_SEQ_SIZE_142(_) BOOST_PP_SEQ_SIZE_143
# define BOOST_PP_SEQ_SIZE_143(_) BOOST_PP_SEQ_SIZE_144
# define BOOST_PP_SEQ_SIZE_144(_) BOOST_PP_SEQ_SIZE_145
# define BOOST_PP_SEQ_SIZE_145(_) BOOST_PP_SEQ_SIZE_146
# define BOOST_PP_SEQ_SIZE_146(_) BOOST_PP_SEQ_SIZE_147
# define BOOST_PP_SEQ_SIZE_147(_) BOOST_PP_SEQ_SIZE_148
# define BOOST_PP_SEQ_SIZE_148(_) BOOST_PP_SEQ_SIZE_149
# define BOOST_PP_SEQ_SIZE_149(_) BOOST_PP_SEQ_SIZE_150
# define BOOST_PP_SEQ_SIZE_150(_) BOOST_PP_SEQ_SIZE_151
# define BOOST_PP_SEQ_SIZE_151(_) BOOST_PP_SEQ_SIZE_152
# define BOOST_PP_SEQ_SIZE_152(_) BOOST_PP_SEQ_SIZE_153
# define BOOST_PP_SEQ_SIZE_153(_) BOOST_PP_SEQ_SIZE_154
# define BOOST_PP_SEQ_SIZE_154(_) BOOST_PP_SEQ_SIZE_155
# define BOOST_PP_SEQ_SIZE_155(_) BOOST_PP_SEQ_SIZE_156
# define BOOST_PP_SEQ_SIZE_156(_) BOOST_PP_SEQ_SIZE_157
# define BOOST_PP_SEQ_SIZE_157(_) BOOST_PP_SEQ_SIZE_158
# define BOOST_PP_SEQ_SIZE_158(_) BOOST_PP_SEQ_SIZE_159
# define BOOST_PP_SEQ_SIZE_159(_) BOOST_PP_SEQ_SIZE_160
# define BOOST_PP_SEQ_SIZE_160(_) BOOST_PP_SEQ_SIZE_161
# define BOOST_PP_SEQ_SIZE_161(_) BOOST_PP_SEQ_SIZE_162
# define BOOST_PP_SEQ_SIZE_162(_) BOOST_PP_SEQ_SIZE_163
# define BOOST_PP_SEQ_SIZE_163(_) BOOST_PP_SEQ_SIZE_164
# define BOOST_PP_SEQ_SIZE_164(_) BOOST_PP_SEQ_SIZE_165
# define BOOST_PP_SEQ_SIZE_165(_) BOOST_PP_SEQ_SIZE_166
# define BOOST_PP_SEQ_SIZE_166(_) BOOST_PP_SEQ_SIZE_167
# define BOOST_PP_SEQ_SIZE_167(_) BOOST_PP_SEQ_SIZE_168
# define BOOST_PP_SEQ_SIZE_168(_) BOOST_PP_SEQ_SIZE_169
# define BOOST_PP_SEQ_SIZE_169(_) BOOST_PP_SEQ_SIZE_170
# define BOOST_PP_SEQ_SIZE_170(_) BOOST_PP_SEQ_SIZE_171
# define BOOST_PP_SEQ_SIZE_171(_) BOOST_PP_SEQ_SIZE_172
# define BOOST_PP_SEQ_SIZE_172(_) BOOST_PP_SEQ_SIZE_173
# define BOOST_PP_SEQ_SIZE_173(_) BOOST_PP_SEQ_SIZE_174
# define BOOST_PP_SEQ_SIZE_174(_) BOOST_PP_SEQ_SIZE_175
# define BOOST_PP_SEQ_SIZE_175(_) BOOST_PP_SEQ_SIZE_176
# define BOOST_PP_SEQ_SIZE_176(_) BOOST_PP_SEQ_SIZE_177
# define BOOST_PP_SEQ_SIZE_177(_) BOOST_PP_SEQ_SIZE_178
# define BOOST_PP_SEQ_SIZE_178(_) BOOST_PP_SEQ_SIZE_179
# define BOOST_PP_SEQ_SIZE_179(_) BOOST_PP_SEQ_SIZE_180
# define BOOST_PP_SEQ_SIZE_180(_) BOOST_PP_SEQ_SIZE_181
# define BOOST_PP_SEQ_SIZE_181(_) BOOST_PP_SEQ_SIZE_182
# define BOOST_PP_SEQ_SIZE_182(_) BOOST_PP_SEQ_SIZE_183
# define BOOST_PP_SEQ_SIZE_183(_) BOOST_PP_SEQ_SIZE_184
# define BOOST_PP_SEQ_SIZE_184(_) BOOST_PP_SEQ_SIZE_185
# define BOOST_PP_SEQ_SIZE_185(_) BOOST_PP_SEQ_SIZE_186
# define BOOST_PP_SEQ_SIZE_186(_) BOOST_PP_SEQ_SIZE_187
# define BOOST_PP_SEQ_SIZE_187(_) BOOST_PP_SEQ_SIZE_188
# define BOOST_PP_SEQ_SIZE_188(_) BOOST_PP_SEQ_SIZE_189
# define BOOST_PP_SEQ_SIZE_189(_) BOOST_PP_SEQ_SIZE_190
# define BOOST_PP_SEQ_SIZE_190(_) BOOST_PP_SEQ_SIZE_191
# define BOOST_PP_SEQ_SIZE_191(_) BOOST_PP_SEQ_SIZE_192
# define BOOST_PP_SEQ_SIZE_192(_) BOOST_PP_SEQ_SIZE_193
# define BOOST_PP_SEQ_SIZE_193(_) BOOST_PP_SEQ_SIZE_194
# define BOOST_PP_SEQ_SIZE_194(_) BOOST_PP_SEQ_SIZE_195
# define BOOST_PP_SEQ_SIZE_195(_) BOOST_PP_SEQ_SIZE_196
# define BOOST_PP_SEQ_SIZE_196(_) BOOST_PP_SEQ_SIZE_197
# define BOOST_PP_SEQ_SIZE_197(_) BOOST_PP_SEQ_SIZE_198
# define BOOST_PP_SEQ_SIZE_198(_) BOOST_PP_SEQ_SIZE_199
# define BOOST_PP_SEQ_SIZE_199(_) BOOST_PP_SEQ_SIZE_200
# define BOOST_PP_SEQ_SIZE_200(_) BOOST_PP_SEQ_SIZE_201
# define BOOST_PP_SEQ_SIZE_201(_) BOOST_PP_SEQ_SIZE_202
# define BOOST_PP_SEQ_SIZE_202(_) BOOST_PP_SEQ_SIZE_203
# define BOOST_PP_SEQ_SIZE_203(_) BOOST_PP_SEQ_SIZE_204
# define BOOST_PP_SEQ_SIZE_204(_) BOOST_PP_SEQ_SIZE_205
# define BOOST_PP_SEQ_SIZE_205(_) BOOST_PP_SEQ_SIZE_206
# define BOOST_PP_SEQ_SIZE_206(_) BOOST_PP_SEQ_SIZE_207
# define BOOST_PP_SEQ_SIZE_207(_) BOOST_PP_SEQ_SIZE_208
# define BOOST_PP_SEQ_SIZE_208(_) BOOST_PP_SEQ_SIZE_209
# define BOOST_PP_SEQ_SIZE_209(_) BOOST_PP_SEQ_SIZE_210
# define BOOST_PP_SEQ_SIZE_210(_) BOOST_PP_SEQ_SIZE_211
# define BOOST_PP_SEQ_SIZE_211(_) BOOST_PP_SEQ_SIZE_212
# define BOOST_PP_SEQ_SIZE_212(_) BOOST_PP_SEQ_SIZE_213
# define BOOST_PP_SEQ_SIZE_213(_) BOOST_PP_SEQ_SIZE_214
# define BOOST_PP_SEQ_SIZE_214(_) BOOST_PP_SEQ_SIZE_215
# define BOOST_PP_SEQ_SIZE_215(_) BOOST_PP_SEQ_SIZE_216
# define BOOST_PP_SEQ_SIZE_216(_) BOOST_PP_SEQ_SIZE_217
# define BOOST_PP_SEQ_SIZE_217(_) BOOST_PP_SEQ_SIZE_218
# define BOOST_PP_SEQ_SIZE_218(_) BOOST_PP_SEQ_SIZE_219
# define BOOST_PP_SEQ_SIZE_219(_) BOOST_PP_SEQ_SIZE_220
# define BOOST_PP_SEQ_SIZE_220(_) BOOST_PP_SEQ_SIZE_221
# define BOOST_PP_SEQ_SIZE_221(_) BOOST_PP_SEQ_SIZE_222
# define BOOST_PP_SEQ_SIZE_222(_) BOOST_PP_SEQ_SIZE_223
# define BOOST_PP_SEQ_SIZE_223(_) BOOST_PP_SEQ_SIZE_224
# define BOOST_PP_SEQ_SIZE_224(_) BOOST_PP_SEQ_SIZE_225
# define BOOST_PP_SEQ_SIZE_225(_) BOOST_PP_SEQ_SIZE_226
# define BOOST_PP_SEQ_SIZE_226(_) BOOST_PP_SEQ_SIZE_227
# define BOOST_PP_SEQ_SIZE_227(_) BOOST_PP_SEQ_SIZE_228
# define BOOST_PP_SEQ_SIZE_228(_) BOOST_PP_SEQ_SIZE_229
# define BOOST_PP_SEQ_SIZE_229(_) BOOST_PP_SEQ_SIZE_230
# define BOOST_PP_SEQ_SIZE_230(_) BOOST_PP_SEQ_SIZE_231
# define BOOST_PP_SEQ_SIZE_231(_) BOOST_PP_SEQ_SIZE_232
# define BOOST_PP_SEQ_SIZE_232(_) BOOST_PP_SEQ_SIZE_233
# define BOOST_PP_SEQ_SIZE_233(_) BOOST_PP_SEQ_SIZE_234
# define BOOST_PP_SEQ_SIZE_234(_) BOOST_PP_SEQ_SIZE_235
# define BOOST_PP_SEQ_SIZE_235(_) BOOST_PP_SEQ_SIZE_236
# define BOOST_PP_SEQ_SIZE_236(_) BOOST_PP_SEQ_SIZE_237
# define BOOST_PP_SEQ_SIZE_237(_) BOOST_PP_SEQ_SIZE_238
# define BOOST_PP_SEQ_SIZE_238(_) BOOST_PP_SEQ_SIZE_239
# define BOOST_PP_SEQ_SIZE_239(_) BOOST_PP_SEQ_SIZE_240
# define BOOST_PP_SEQ_SIZE_240(_) BOOST_PP_SEQ_SIZE_241
# define BOOST_PP_SEQ_SIZE_241(_) BOOST_PP_SEQ_SIZE_242
# define BOOST_PP_SEQ_SIZE_242(_) BOOST_PP_SEQ_SIZE_243
# define BOOST_PP_SEQ_SIZE_243(_) BOOST_PP_SEQ_SIZE_244
# define BOOST_PP_SEQ_SIZE_244(_) BOOST_PP_SEQ_SIZE_245
# define BOOST_PP_SEQ_SIZE_245(_) BOOST_PP_SEQ_SIZE_246
# define BOOST_PP_SEQ_SIZE_246(_) BOOST_PP_SEQ_SIZE_247
# define BOOST_PP_SEQ_SIZE_247(_) BOOST_PP_SEQ_SIZE_248
# define BOOST_PP_SEQ_SIZE_248(_) BOOST_PP_SEQ_SIZE_249
# define BOOST_PP_SEQ_SIZE_249(_) BOOST_PP_SEQ_SIZE_250
# define BOOST_PP_SEQ_SIZE_250(_) BOOST_PP_SEQ_SIZE_251
# define BOOST_PP_SEQ_SIZE_251(_) BOOST_PP_SEQ_SIZE_252
# define BOOST_PP_SEQ_SIZE_252(_) BOOST_PP_SEQ_SIZE_253
# define BOOST_PP_SEQ_SIZE_253(_) BOOST_PP_SEQ_SIZE_254
# define BOOST_PP_SEQ_SIZE_254(_) BOOST_PP_SEQ_SIZE_255
# define BOOST_PP_SEQ_SIZE_255(_) BOOST_PP_SEQ_SIZE_256
# define BOOST_PP_SEQ_SIZE_256(_) BOOST_PP_SEQ_SIZE_257
#
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_0 0
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_1 1
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_2 2
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_3 3
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_4 4
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_5 5
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_6 6
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_7 7
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_8 8
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_9 9
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_10 10
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_11 11
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_12 12
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_13 13
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_14 14
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_15 15
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_16 16
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_17 17
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_18 18
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_19 19
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_20 20
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_21 21
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_22 22
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_23 23
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_24 24
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_25 25
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_26 26
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_27 27
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_28 28
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_29 29
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_30 30
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_31 31
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_32 32
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_33 33
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_34 34
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_35 35
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_36 36
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_37 37
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_38 38
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_39 39
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_40 40
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_41 41
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_42 42
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_43 43
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_44 44
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_45 45
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_46 46
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_47 47
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_48 48
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_49 49
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_50 50
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_51 51
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_52 52
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_53 53
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_54 54
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_55 55
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_56 56
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_57 57
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_58 58
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_59 59
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_60 60
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_61 61
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_62 62
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_63 63
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_64 64
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_65 65
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_66 66
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_67 67
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_68 68
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_69 69
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_70 70
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_71 71
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_72 72
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_73 73
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_74 74
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_75 75
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_76 76
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_77 77
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_78 78
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_79 79
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_80 80
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_81 81
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_82 82
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_83 83
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_84 84
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_85 85
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_86 86
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_87 87
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_88 88
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_89 89
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_90 90
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_91 91
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_92 92
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_93 93
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_94 94
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_95 95
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_96 96
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_97 97
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_98 98
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_99 99
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_100 100
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_101 101
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_102 102
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_103 103
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_104 104
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_105 105
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_106 106
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_107 107
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_108 108
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_109 109
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_110 110
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_111 111
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_112 112
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_113 113
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_114 114
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_115 115
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_116 116
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_117 117
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_118 118
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_119 119
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_120 120
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_121 121
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_122 122
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_123 123
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_124 124
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_125 125
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_126 126
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_127 127
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_128 128
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_129 129
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_130 130
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_131 131
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_132 132
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_133 133
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_134 134
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_135 135
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_136 136
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_137 137
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_138 138
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_139 139
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_140 140
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_141 141
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_142 142
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_143 143
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_144 144
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_145 145
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_146 146
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_147 147
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_148 148
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_149 149
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_150 150
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_151 151
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_152 152
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_153 153
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_154 154
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_155 155
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_156 156
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_157 157
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_158 158
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_159 159
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_160 160
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_161 161
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_162 162
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_163 163
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_164 164
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_165 165
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_166 166
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_167 167
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_168 168
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_169 169
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_170 170
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_171 171
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_172 172
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_173 173
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_174 174
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_175 175
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_176 176
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_177 177
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_178 178
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_179 179
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_180 180
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_181 181
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_182 182
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_183 183
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_184 184
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_185 185
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_186 186
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_187 187
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_188 188
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_189 189
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_190 190
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_191 191
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_192 192
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_193 193
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_194 194
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_195 195
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_196 196
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_197 197
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_198 198
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_199 199
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_200 200
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_201 201
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_202 202
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_203 203
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_204 204
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_205 205
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_206 206
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_207 207
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_208 208
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_209 209
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_210 210
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_211 211
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_212 212
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_213 213
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_214 214
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_215 215
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_216 216
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_217 217
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_218 218
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_219 219
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_220 220
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_221 221
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_222 222
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_223 223
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_224 224
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_225 225
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_226 226
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_227 227
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_228 228
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_229 229
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_230 230
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_231 231
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_232 232
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_233 233
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_234 234
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_235 235
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_236 236
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_237 237
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_238 238
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_239 239
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_240 240
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_241 241
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_242 242
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_243 243
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_244 244
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_245 245
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_246 246
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_247 247
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_248 248
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_249 249
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_250 250
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_251 251
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_252 252
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_253 253
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_254 254
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_255 255
# define BOOST_PP_SEQ_SIZE_BOOST_PP_SEQ_SIZE_256 256


//  ****************************************************************************
# /* BOOST_PP_EXPAND */
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC() && ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_DMC()
#    define BOOST_PP_EXPAND(x) BOOST_PP_EXPAND_I(x)
# else
#    define BOOST_PP_EXPAND(x) BOOST_PP_EXPAND_OO((x))
#    define BOOST_PP_EXPAND_OO(par) BOOST_PP_EXPAND_I ## par
# endif
#
# define BOOST_PP_EXPAND_I(x) x


//  ****************************************************************************
# /* BOOST_PP_REM */
#
# if BOOST_PP_VARIADICS
# 	 if BOOST_PP_VARIADICS_MSVC
		/* To be used internally when __VA_ARGS__ could be empty ( or is a single element ) */
#    	define BOOST_PP_REM_CAT(...) BOOST_PP_CAT(__VA_ARGS__,)
# 	 endif
#    define BOOST_PP_REM(...) __VA_ARGS__
# else
#    define BOOST_PP_REM(x) x
# endif
#
# /* BOOST_PP_TUPLE_REM */
#
/*
  VC++8.0 cannot handle the variadic version of BOOST_PP_TUPLE_REM(size)
*/
# if BOOST_PP_VARIADICS && !(BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400)
# 	 if BOOST_PP_VARIADICS_MSVC
		/* To be used internally when the size could be 0 ( or 1 ) */
#    	define BOOST_PP_TUPLE_REM_CAT(size) BOOST_PP_REM_CAT
# 	 endif
#    define BOOST_PP_TUPLE_REM(size) BOOST_PP_REM
# else
#    if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#        define BOOST_PP_TUPLE_REM(size) BOOST_PP_TUPLE_REM_I(size)
#    else
#        define BOOST_PP_TUPLE_REM(size) BOOST_PP_TUPLE_REM_OO((size))
#        define BOOST_PP_TUPLE_REM_OO(par) BOOST_PP_TUPLE_REM_I ## par
#    endif
#    define BOOST_PP_TUPLE_REM_I(size) BOOST_PP_TUPLE_REM_ ## size
# endif
# define BOOST_PP_TUPLE_REM_0()
# define BOOST_PP_TUPLE_REM_1(e0) e0
# define BOOST_PP_TUPLE_REM_2(e0, e1) e0, e1
# define BOOST_PP_TUPLE_REM_3(e0, e1, e2) e0, e1, e2
# define BOOST_PP_TUPLE_REM_4(e0, e1, e2, e3) e0, e1, e2, e3
# define BOOST_PP_TUPLE_REM_5(e0, e1, e2, e3, e4) e0, e1, e2, e3, e4
# define BOOST_PP_TUPLE_REM_6(e0, e1, e2, e3, e4, e5) e0, e1, e2, e3, e4, e5
# define BOOST_PP_TUPLE_REM_7(e0, e1, e2, e3, e4, e5, e6) e0, e1, e2, e3, e4, e5, e6
# define BOOST_PP_TUPLE_REM_8(e0, e1, e2, e3, e4, e5, e6, e7) e0, e1, e2, e3, e4, e5, e6, e7
# define BOOST_PP_TUPLE_REM_9(e0, e1, e2, e3, e4, e5, e6, e7, e8) e0, e1, e2, e3, e4, e5, e6, e7, e8
# define BOOST_PP_TUPLE_REM_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9
# define BOOST_PP_TUPLE_REM_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10
# define BOOST_PP_TUPLE_REM_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11
# define BOOST_PP_TUPLE_REM_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12
# define BOOST_PP_TUPLE_REM_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13
# define BOOST_PP_TUPLE_REM_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14
# define BOOST_PP_TUPLE_REM_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15
# define BOOST_PP_TUPLE_REM_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16
# define BOOST_PP_TUPLE_REM_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17
# define BOOST_PP_TUPLE_REM_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18
# define BOOST_PP_TUPLE_REM_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19
# define BOOST_PP_TUPLE_REM_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20
# define BOOST_PP_TUPLE_REM_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21
# define BOOST_PP_TUPLE_REM_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22
# define BOOST_PP_TUPLE_REM_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23
# define BOOST_PP_TUPLE_REM_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24
# define BOOST_PP_TUPLE_REM_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25
# define BOOST_PP_TUPLE_REM_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26
# define BOOST_PP_TUPLE_REM_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27
# define BOOST_PP_TUPLE_REM_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28
# define BOOST_PP_TUPLE_REM_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29
# define BOOST_PP_TUPLE_REM_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30
# define BOOST_PP_TUPLE_REM_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31
# define BOOST_PP_TUPLE_REM_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32
# define BOOST_PP_TUPLE_REM_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33
# define BOOST_PP_TUPLE_REM_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34
# define BOOST_PP_TUPLE_REM_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35
# define BOOST_PP_TUPLE_REM_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36
# define BOOST_PP_TUPLE_REM_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37
# define BOOST_PP_TUPLE_REM_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38
# define BOOST_PP_TUPLE_REM_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39
# define BOOST_PP_TUPLE_REM_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40
# define BOOST_PP_TUPLE_REM_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41
# define BOOST_PP_TUPLE_REM_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42
# define BOOST_PP_TUPLE_REM_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43
# define BOOST_PP_TUPLE_REM_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44
# define BOOST_PP_TUPLE_REM_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45
# define BOOST_PP_TUPLE_REM_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46
# define BOOST_PP_TUPLE_REM_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47
# define BOOST_PP_TUPLE_REM_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48
# define BOOST_PP_TUPLE_REM_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49
# define BOOST_PP_TUPLE_REM_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50
# define BOOST_PP_TUPLE_REM_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51
# define BOOST_PP_TUPLE_REM_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52
# define BOOST_PP_TUPLE_REM_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53
# define BOOST_PP_TUPLE_REM_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54
# define BOOST_PP_TUPLE_REM_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55
# define BOOST_PP_TUPLE_REM_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56
# define BOOST_PP_TUPLE_REM_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57
# define BOOST_PP_TUPLE_REM_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58
# define BOOST_PP_TUPLE_REM_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59
# define BOOST_PP_TUPLE_REM_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60
# define BOOST_PP_TUPLE_REM_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61
# define BOOST_PP_TUPLE_REM_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62
# define BOOST_PP_TUPLE_REM_64(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63
#
# /* BOOST_PP_TUPLE_REM_CTOR */
#
# if BOOST_PP_VARIADICS
#    if BOOST_PP_VARIADICS_MSVC
#        define BOOST_PP_TUPLE_REM_CTOR(...) BOOST_PP_TUPLE_REM_CTOR_I(BOOST_PP_OVERLOAD(BOOST_PP_TUPLE_REM_CTOR_O_, __VA_ARGS__), (__VA_ARGS__))
#        define BOOST_PP_TUPLE_REM_CTOR_I(m, args) BOOST_PP_TUPLE_REM_CTOR_II(m, args)
#        define BOOST_PP_TUPLE_REM_CTOR_II(m, args) BOOST_PP_CAT(BOOST_PP_EXPAND(m ## args),)
#    	 define BOOST_PP_TUPLE_REM_CTOR_O_1(tuple) BOOST_PP_TUPLE_IS_SINGLE_RETURN(BOOST_PP_REM_CAT,BOOST_PP_REM,tuple) tuple
#    else
#        define BOOST_PP_TUPLE_REM_CTOR(...) BOOST_PP_OVERLOAD(BOOST_PP_TUPLE_REM_CTOR_O_, __VA_ARGS__)(__VA_ARGS__)
#    	 define BOOST_PP_TUPLE_REM_CTOR_O_1(tuple) BOOST_PP_REM tuple
#    endif
#    define BOOST_PP_TUPLE_REM_CTOR_O_2(size, tuple) BOOST_PP_TUPLE_REM_CTOR_O_1(tuple)
# else
#    if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#        define BOOST_PP_TUPLE_REM_CTOR(size, tuple) BOOST_PP_TUPLE_REM_CTOR_I(BOOST_PP_TUPLE_REM(size), tuple)
#    else
#        define BOOST_PP_TUPLE_REM_CTOR(size, tuple) BOOST_PP_TUPLE_REM_CTOR_D(size, tuple)
#        define BOOST_PP_TUPLE_REM_CTOR_D(size, tuple) BOOST_PP_TUPLE_REM_CTOR_I(BOOST_PP_TUPLE_REM(size), tuple)
#    endif
#    if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#        define BOOST_PP_TUPLE_REM_CTOR_I(ext, tuple) ext tuple
#    else
#        define BOOST_PP_TUPLE_REM_CTOR_I(ext, tuple) BOOST_PP_TUPLE_REM_CTOR_OO((ext, tuple))
#        define BOOST_PP_TUPLE_REM_CTOR_OO(par) BOOST_PP_TUPLE_REM_CTOR_II ## par
#        define BOOST_PP_TUPLE_REM_CTOR_II(ext, tuple) ext ## tuple
#    endif
# endif


//  ****************************************************************************
# /* BOOST_PP_EAT */
#
# if BOOST_PP_VARIADICS
#    define BOOST_PP_EAT(...)
# else
#    define BOOST_PP_EAT(x)
# endif
#
# /* BOOST_PP_TUPLE_EAT */
#
# if BOOST_PP_VARIADICS
#    define BOOST_PP_TUPLE_EAT(size) BOOST_PP_EAT
# else
#    if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#        define BOOST_PP_TUPLE_EAT(size) BOOST_PP_TUPLE_EAT_I(size)
#    else
#        define BOOST_PP_TUPLE_EAT(size) BOOST_PP_TUPLE_EAT_OO((size))
#        define BOOST_PP_TUPLE_EAT_OO(par) BOOST_PP_TUPLE_EAT_I ## par
#    endif
#    define BOOST_PP_TUPLE_EAT_I(size) BOOST_PP_TUPLE_EAT_ ## size
# endif
# define BOOST_PP_TUPLE_EAT_1(e0)
# define BOOST_PP_TUPLE_EAT_2(e0, e1)
# define BOOST_PP_TUPLE_EAT_3(e0, e1, e2)
# define BOOST_PP_TUPLE_EAT_4(e0, e1, e2, e3)
# define BOOST_PP_TUPLE_EAT_5(e0, e1, e2, e3, e4)
# define BOOST_PP_TUPLE_EAT_6(e0, e1, e2, e3, e4, e5)
# define BOOST_PP_TUPLE_EAT_7(e0, e1, e2, e3, e4, e5, e6)
# define BOOST_PP_TUPLE_EAT_8(e0, e1, e2, e3, e4, e5, e6, e7)
# define BOOST_PP_TUPLE_EAT_9(e0, e1, e2, e3, e4, e5, e6, e7, e8)
# define BOOST_PP_TUPLE_EAT_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9)
# define BOOST_PP_TUPLE_EAT_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10)
# define BOOST_PP_TUPLE_EAT_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11)
# define BOOST_PP_TUPLE_EAT_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12)
# define BOOST_PP_TUPLE_EAT_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13)
# define BOOST_PP_TUPLE_EAT_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14)
# define BOOST_PP_TUPLE_EAT_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15)
# define BOOST_PP_TUPLE_EAT_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16)
# define BOOST_PP_TUPLE_EAT_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17)
# define BOOST_PP_TUPLE_EAT_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18)
# define BOOST_PP_TUPLE_EAT_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19)
# define BOOST_PP_TUPLE_EAT_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20)
# define BOOST_PP_TUPLE_EAT_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21)
# define BOOST_PP_TUPLE_EAT_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22)
# define BOOST_PP_TUPLE_EAT_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23)
# define BOOST_PP_TUPLE_EAT_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24)
# define BOOST_PP_TUPLE_EAT_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25)
# define BOOST_PP_TUPLE_EAT_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26)
# define BOOST_PP_TUPLE_EAT_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27)
# define BOOST_PP_TUPLE_EAT_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28)
# define BOOST_PP_TUPLE_EAT_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29)
# define BOOST_PP_TUPLE_EAT_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30)
# define BOOST_PP_TUPLE_EAT_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31)
# define BOOST_PP_TUPLE_EAT_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32)
# define BOOST_PP_TUPLE_EAT_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33)
# define BOOST_PP_TUPLE_EAT_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34)
# define BOOST_PP_TUPLE_EAT_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35)
# define BOOST_PP_TUPLE_EAT_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36)
# define BOOST_PP_TUPLE_EAT_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37)
# define BOOST_PP_TUPLE_EAT_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38)
# define BOOST_PP_TUPLE_EAT_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39)
# define BOOST_PP_TUPLE_EAT_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40)
# define BOOST_PP_TUPLE_EAT_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41)
# define BOOST_PP_TUPLE_EAT_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42)
# define BOOST_PP_TUPLE_EAT_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43)
# define BOOST_PP_TUPLE_EAT_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44)
# define BOOST_PP_TUPLE_EAT_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45)
# define BOOST_PP_TUPLE_EAT_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46)
# define BOOST_PP_TUPLE_EAT_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47)
# define BOOST_PP_TUPLE_EAT_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48)
# define BOOST_PP_TUPLE_EAT_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49)
# define BOOST_PP_TUPLE_EAT_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50)
# define BOOST_PP_TUPLE_EAT_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51)
# define BOOST_PP_TUPLE_EAT_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52)
# define BOOST_PP_TUPLE_EAT_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53)
# define BOOST_PP_TUPLE_EAT_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54)
# define BOOST_PP_TUPLE_EAT_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55)
# define BOOST_PP_TUPLE_EAT_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56)
# define BOOST_PP_TUPLE_EAT_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57)
# define BOOST_PP_TUPLE_EAT_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58)
# define BOOST_PP_TUPLE_EAT_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59)
# define BOOST_PP_TUPLE_EAT_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60)
# define BOOST_PP_TUPLE_EAT_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61)
# define BOOST_PP_TUPLE_EAT_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62)
# define BOOST_PP_TUPLE_EAT_64(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63)


//  ****************************************************************************
# /* BOOST_PP_SEQ_FOR_EACH_I */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) BOOST_PP_FOR((macro, data, seq (nil), 0), BOOST_PP_SEQ_FOR_EACH_I_P, BOOST_PP_SEQ_FOR_EACH_I_O, BOOST_PP_SEQ_FOR_EACH_I_M)
# else
#    define BOOST_PP_SEQ_FOR_EACH_I(macro, data, seq) BOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq)
#    define BOOST_PP_SEQ_FOR_EACH_I_I(macro, data, seq) BOOST_PP_FOR((macro, data, seq (nil), 0), BOOST_PP_SEQ_FOR_EACH_I_P, BOOST_PP_SEQ_FOR_EACH_I_O, BOOST_PP_SEQ_FOR_EACH_I_M)
# endif
#
# define BOOST_PP_SEQ_FOR_EACH_I_P(r, x) BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(4, 2, x)))
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_STRICT()
#    define BOOST_PP_SEQ_FOR_EACH_I_O(r, x) BOOST_PP_SEQ_FOR_EACH_I_O_I x
# else
#    define BOOST_PP_SEQ_FOR_EACH_I_O(r, x) BOOST_PP_SEQ_FOR_EACH_I_O_I(BOOST_PP_TUPLE_ELEM(4, 0, x), BOOST_PP_TUPLE_ELEM(4, 1, x), BOOST_PP_TUPLE_ELEM(4, 2, x), BOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define BOOST_PP_SEQ_FOR_EACH_I_O_I(macro, data, seq, i) (macro, data, BOOST_PP_SEQ_TAIL(seq), BOOST_PP_INC(i))
#
# if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_STRICT()
#    define BOOST_PP_SEQ_FOR_EACH_I_M(r, x) BOOST_PP_SEQ_FOR_EACH_I_M_IM(r, BOOST_PP_TUPLE_REM_4 x)
#    define BOOST_PP_SEQ_FOR_EACH_I_M_IM(r, im) BOOST_PP_SEQ_FOR_EACH_I_M_I(r, im)
# else
#    define BOOST_PP_SEQ_FOR_EACH_I_M(r, x) BOOST_PP_SEQ_FOR_EACH_I_M_I(r, BOOST_PP_TUPLE_ELEM(4, 0, x), BOOST_PP_TUPLE_ELEM(4, 1, x), BOOST_PP_TUPLE_ELEM(4, 2, x), BOOST_PP_TUPLE_ELEM(4, 3, x))
# endif
#
# define BOOST_PP_SEQ_FOR_EACH_I_M_I(r, macro, data, seq, i) macro(r, data, i, BOOST_PP_SEQ_HEAD(seq))
#
# /* BOOST_PP_SEQ_FOR_EACH_I_R */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_EDG()
#    define BOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) BOOST_PP_FOR_ ## r((macro, data, seq (nil), 0), BOOST_PP_SEQ_FOR_EACH_I_P, BOOST_PP_SEQ_FOR_EACH_I_O, BOOST_PP_SEQ_FOR_EACH_I_M)
# else
#    define BOOST_PP_SEQ_FOR_EACH_I_R(r, macro, data, seq) BOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq)
#    define BOOST_PP_SEQ_FOR_EACH_I_R_I(r, macro, data, seq) BOOST_PP_FOR_ ## r((macro, data, seq (nil), 0), BOOST_PP_SEQ_FOR_EACH_I_P, BOOST_PP_SEQ_FOR_EACH_I_O, BOOST_PP_SEQ_FOR_EACH_I_M)
# endif


//  ****************************************************************************
# /* BOOST_PP_BOOL */
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_BOOL(x) BOOST_PP_BOOL_I(x)
# else
#    define BOOST_PP_BOOL(x) BOOST_PP_BOOL_OO((x))
#    define BOOST_PP_BOOL_OO(par) BOOST_PP_BOOL_I ## par
# endif
#
# define BOOST_PP_BOOL_I(x) BOOST_PP_BOOL_ ## x
#
# define BOOST_PP_BOOL_0 0
# define BOOST_PP_BOOL_1 1
# define BOOST_PP_BOOL_2 1
# define BOOST_PP_BOOL_3 1
# define BOOST_PP_BOOL_4 1
# define BOOST_PP_BOOL_5 1
# define BOOST_PP_BOOL_6 1
# define BOOST_PP_BOOL_7 1
# define BOOST_PP_BOOL_8 1
# define BOOST_PP_BOOL_9 1
# define BOOST_PP_BOOL_10 1
# define BOOST_PP_BOOL_11 1
# define BOOST_PP_BOOL_12 1
# define BOOST_PP_BOOL_13 1
# define BOOST_PP_BOOL_14 1
# define BOOST_PP_BOOL_15 1
# define BOOST_PP_BOOL_16 1
# define BOOST_PP_BOOL_17 1
# define BOOST_PP_BOOL_18 1
# define BOOST_PP_BOOL_19 1
# define BOOST_PP_BOOL_20 1
# define BOOST_PP_BOOL_21 1
# define BOOST_PP_BOOL_22 1
# define BOOST_PP_BOOL_23 1
# define BOOST_PP_BOOL_24 1
# define BOOST_PP_BOOL_25 1
# define BOOST_PP_BOOL_26 1
# define BOOST_PP_BOOL_27 1
# define BOOST_PP_BOOL_28 1
# define BOOST_PP_BOOL_29 1
# define BOOST_PP_BOOL_30 1
# define BOOST_PP_BOOL_31 1
# define BOOST_PP_BOOL_32 1
# define BOOST_PP_BOOL_33 1
# define BOOST_PP_BOOL_34 1
# define BOOST_PP_BOOL_35 1
# define BOOST_PP_BOOL_36 1
# define BOOST_PP_BOOL_37 1
# define BOOST_PP_BOOL_38 1
# define BOOST_PP_BOOL_39 1
# define BOOST_PP_BOOL_40 1
# define BOOST_PP_BOOL_41 1
# define BOOST_PP_BOOL_42 1
# define BOOST_PP_BOOL_43 1
# define BOOST_PP_BOOL_44 1
# define BOOST_PP_BOOL_45 1
# define BOOST_PP_BOOL_46 1
# define BOOST_PP_BOOL_47 1
# define BOOST_PP_BOOL_48 1
# define BOOST_PP_BOOL_49 1
# define BOOST_PP_BOOL_50 1
# define BOOST_PP_BOOL_51 1
# define BOOST_PP_BOOL_52 1
# define BOOST_PP_BOOL_53 1
# define BOOST_PP_BOOL_54 1
# define BOOST_PP_BOOL_55 1
# define BOOST_PP_BOOL_56 1
# define BOOST_PP_BOOL_57 1
# define BOOST_PP_BOOL_58 1
# define BOOST_PP_BOOL_59 1
# define BOOST_PP_BOOL_60 1
# define BOOST_PP_BOOL_61 1
# define BOOST_PP_BOOL_62 1
# define BOOST_PP_BOOL_63 1
# define BOOST_PP_BOOL_64 1
# define BOOST_PP_BOOL_65 1
# define BOOST_PP_BOOL_66 1
# define BOOST_PP_BOOL_67 1
# define BOOST_PP_BOOL_68 1
# define BOOST_PP_BOOL_69 1
# define BOOST_PP_BOOL_70 1
# define BOOST_PP_BOOL_71 1
# define BOOST_PP_BOOL_72 1
# define BOOST_PP_BOOL_73 1
# define BOOST_PP_BOOL_74 1
# define BOOST_PP_BOOL_75 1
# define BOOST_PP_BOOL_76 1
# define BOOST_PP_BOOL_77 1
# define BOOST_PP_BOOL_78 1
# define BOOST_PP_BOOL_79 1
# define BOOST_PP_BOOL_80 1
# define BOOST_PP_BOOL_81 1
# define BOOST_PP_BOOL_82 1
# define BOOST_PP_BOOL_83 1
# define BOOST_PP_BOOL_84 1
# define BOOST_PP_BOOL_85 1
# define BOOST_PP_BOOL_86 1
# define BOOST_PP_BOOL_87 1
# define BOOST_PP_BOOL_88 1
# define BOOST_PP_BOOL_89 1
# define BOOST_PP_BOOL_90 1
# define BOOST_PP_BOOL_91 1
# define BOOST_PP_BOOL_92 1
# define BOOST_PP_BOOL_93 1
# define BOOST_PP_BOOL_94 1
# define BOOST_PP_BOOL_95 1
# define BOOST_PP_BOOL_96 1
# define BOOST_PP_BOOL_97 1
# define BOOST_PP_BOOL_98 1
# define BOOST_PP_BOOL_99 1
# define BOOST_PP_BOOL_100 1
# define BOOST_PP_BOOL_101 1
# define BOOST_PP_BOOL_102 1
# define BOOST_PP_BOOL_103 1
# define BOOST_PP_BOOL_104 1
# define BOOST_PP_BOOL_105 1
# define BOOST_PP_BOOL_106 1
# define BOOST_PP_BOOL_107 1
# define BOOST_PP_BOOL_108 1
# define BOOST_PP_BOOL_109 1
# define BOOST_PP_BOOL_110 1
# define BOOST_PP_BOOL_111 1
# define BOOST_PP_BOOL_112 1
# define BOOST_PP_BOOL_113 1
# define BOOST_PP_BOOL_114 1
# define BOOST_PP_BOOL_115 1
# define BOOST_PP_BOOL_116 1
# define BOOST_PP_BOOL_117 1
# define BOOST_PP_BOOL_118 1
# define BOOST_PP_BOOL_119 1
# define BOOST_PP_BOOL_120 1
# define BOOST_PP_BOOL_121 1
# define BOOST_PP_BOOL_122 1
# define BOOST_PP_BOOL_123 1
# define BOOST_PP_BOOL_124 1
# define BOOST_PP_BOOL_125 1
# define BOOST_PP_BOOL_126 1
# define BOOST_PP_BOOL_127 1
# define BOOST_PP_BOOL_128 1
# define BOOST_PP_BOOL_129 1
# define BOOST_PP_BOOL_130 1
# define BOOST_PP_BOOL_131 1
# define BOOST_PP_BOOL_132 1
# define BOOST_PP_BOOL_133 1
# define BOOST_PP_BOOL_134 1
# define BOOST_PP_BOOL_135 1
# define BOOST_PP_BOOL_136 1
# define BOOST_PP_BOOL_137 1
# define BOOST_PP_BOOL_138 1
# define BOOST_PP_BOOL_139 1
# define BOOST_PP_BOOL_140 1
# define BOOST_PP_BOOL_141 1
# define BOOST_PP_BOOL_142 1
# define BOOST_PP_BOOL_143 1
# define BOOST_PP_BOOL_144 1
# define BOOST_PP_BOOL_145 1
# define BOOST_PP_BOOL_146 1
# define BOOST_PP_BOOL_147 1
# define BOOST_PP_BOOL_148 1
# define BOOST_PP_BOOL_149 1
# define BOOST_PP_BOOL_150 1
# define BOOST_PP_BOOL_151 1
# define BOOST_PP_BOOL_152 1
# define BOOST_PP_BOOL_153 1
# define BOOST_PP_BOOL_154 1
# define BOOST_PP_BOOL_155 1
# define BOOST_PP_BOOL_156 1
# define BOOST_PP_BOOL_157 1
# define BOOST_PP_BOOL_158 1
# define BOOST_PP_BOOL_159 1
# define BOOST_PP_BOOL_160 1
# define BOOST_PP_BOOL_161 1
# define BOOST_PP_BOOL_162 1
# define BOOST_PP_BOOL_163 1
# define BOOST_PP_BOOL_164 1
# define BOOST_PP_BOOL_165 1
# define BOOST_PP_BOOL_166 1
# define BOOST_PP_BOOL_167 1
# define BOOST_PP_BOOL_168 1
# define BOOST_PP_BOOL_169 1
# define BOOST_PP_BOOL_170 1
# define BOOST_PP_BOOL_171 1
# define BOOST_PP_BOOL_172 1
# define BOOST_PP_BOOL_173 1
# define BOOST_PP_BOOL_174 1
# define BOOST_PP_BOOL_175 1
# define BOOST_PP_BOOL_176 1
# define BOOST_PP_BOOL_177 1
# define BOOST_PP_BOOL_178 1
# define BOOST_PP_BOOL_179 1
# define BOOST_PP_BOOL_180 1
# define BOOST_PP_BOOL_181 1
# define BOOST_PP_BOOL_182 1
# define BOOST_PP_BOOL_183 1
# define BOOST_PP_BOOL_184 1
# define BOOST_PP_BOOL_185 1
# define BOOST_PP_BOOL_186 1
# define BOOST_PP_BOOL_187 1
# define BOOST_PP_BOOL_188 1
# define BOOST_PP_BOOL_189 1
# define BOOST_PP_BOOL_190 1
# define BOOST_PP_BOOL_191 1
# define BOOST_PP_BOOL_192 1
# define BOOST_PP_BOOL_193 1
# define BOOST_PP_BOOL_194 1
# define BOOST_PP_BOOL_195 1
# define BOOST_PP_BOOL_196 1
# define BOOST_PP_BOOL_197 1
# define BOOST_PP_BOOL_198 1
# define BOOST_PP_BOOL_199 1
# define BOOST_PP_BOOL_200 1
# define BOOST_PP_BOOL_201 1
# define BOOST_PP_BOOL_202 1
# define BOOST_PP_BOOL_203 1
# define BOOST_PP_BOOL_204 1
# define BOOST_PP_BOOL_205 1
# define BOOST_PP_BOOL_206 1
# define BOOST_PP_BOOL_207 1
# define BOOST_PP_BOOL_208 1
# define BOOST_PP_BOOL_209 1
# define BOOST_PP_BOOL_210 1
# define BOOST_PP_BOOL_211 1
# define BOOST_PP_BOOL_212 1
# define BOOST_PP_BOOL_213 1
# define BOOST_PP_BOOL_214 1
# define BOOST_PP_BOOL_215 1
# define BOOST_PP_BOOL_216 1
# define BOOST_PP_BOOL_217 1
# define BOOST_PP_BOOL_218 1
# define BOOST_PP_BOOL_219 1
# define BOOST_PP_BOOL_220 1
# define BOOST_PP_BOOL_221 1
# define BOOST_PP_BOOL_222 1
# define BOOST_PP_BOOL_223 1
# define BOOST_PP_BOOL_224 1
# define BOOST_PP_BOOL_225 1
# define BOOST_PP_BOOL_226 1
# define BOOST_PP_BOOL_227 1
# define BOOST_PP_BOOL_228 1
# define BOOST_PP_BOOL_229 1
# define BOOST_PP_BOOL_230 1
# define BOOST_PP_BOOL_231 1
# define BOOST_PP_BOOL_232 1
# define BOOST_PP_BOOL_233 1
# define BOOST_PP_BOOL_234 1
# define BOOST_PP_BOOL_235 1
# define BOOST_PP_BOOL_236 1
# define BOOST_PP_BOOL_237 1
# define BOOST_PP_BOOL_238 1
# define BOOST_PP_BOOL_239 1
# define BOOST_PP_BOOL_240 1
# define BOOST_PP_BOOL_241 1
# define BOOST_PP_BOOL_242 1
# define BOOST_PP_BOOL_243 1
# define BOOST_PP_BOOL_244 1
# define BOOST_PP_BOOL_245 1
# define BOOST_PP_BOOL_246 1
# define BOOST_PP_BOOL_247 1
# define BOOST_PP_BOOL_248 1
# define BOOST_PP_BOOL_249 1
# define BOOST_PP_BOOL_250 1
# define BOOST_PP_BOOL_251 1
# define BOOST_PP_BOOL_252 1
# define BOOST_PP_BOOL_253 1
# define BOOST_PP_BOOL_254 1
# define BOOST_PP_BOOL_255 1
# define BOOST_PP_BOOL_256 1


//  ****************************************************************************
/*  BOOST_PP_TUPLE_ELEM */
# if BOOST_PP_VARIADICS
#    if BOOST_PP_VARIADICS_MSVC
#        define BOOST_PP_TUPLE_ELEM(...) BOOST_PP_TUPLE_ELEM_I(BOOST_PP_OVERLOAD(BOOST_PP_TUPLE_ELEM_O_, __VA_ARGS__), (__VA_ARGS__))
#        define BOOST_PP_TUPLE_ELEM_I(m, args) BOOST_PP_TUPLE_ELEM_II(m, args)
#        define BOOST_PP_TUPLE_ELEM_II(m, args) BOOST_PP_CAT(BOOST_PP_EXPAND(m ## args),)
/*
  Use BOOST_PP_REM_CAT if it is a single element tuple ( which might be empty )
  else use BOOST_PP_REM. This fixes a VC++ problem with an empty tuple and BOOST_PP_TUPLE_ELEM
  functionality. See tuple_elem_bug_test.cxx.
*/
#    	 define BOOST_PP_TUPLE_ELEM_O_2(n, tuple) \
			BOOST_PP_VARIADIC_ELEM(n, BOOST_PP_TUPLE_IS_SINGLE_RETURN(BOOST_PP_REM_CAT,BOOST_PP_REM,tuple) tuple) \
			/**/
#    else
#        define BOOST_PP_TUPLE_ELEM(...) BOOST_PP_OVERLOAD(BOOST_PP_TUPLE_ELEM_O_, __VA_ARGS__)(__VA_ARGS__)
#    	 define BOOST_PP_TUPLE_ELEM_O_2(n, tuple) BOOST_PP_VARIADIC_ELEM(n, BOOST_PP_REM tuple)
#    endif
#    define BOOST_PP_TUPLE_ELEM_O_3(size, n, tuple) BOOST_PP_TUPLE_ELEM_O_2(n, tuple)
# else
#    if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#        define BOOST_PP_TUPLE_ELEM(size, n, tuple) BOOST_PP_TUPLE_ELEM_I(BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM_, n), BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM_E_, size), tuple))
#        define BOOST_PP_TUPLE_ELEM_I(m, args) BOOST_PP_TUPLE_ELEM_II(m, args)
#        define BOOST_PP_TUPLE_ELEM_II(m, args) BOOST_PP_CAT(m ## args,)
#    elif BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#        define BOOST_PP_TUPLE_ELEM(size, n, tuple) BOOST_PP_TUPLE_ELEM_I_OO((size, n, tuple))
#        define BOOST_PP_TUPLE_ELEM_I_OO(par) BOOST_PP_TUPLE_ELEM_I ## par
#        define BOOST_PP_TUPLE_ELEM_I(size, n, tuple) BOOST_PP_TUPLE_ELEM_II((n, BOOST_PP_TUPLE_ELEM_E_ ## size ## tuple))
#        define BOOST_PP_TUPLE_ELEM_II(par) BOOST_PP_TUPLE_ELEM_III_OO(par)
#        define BOOST_PP_TUPLE_ELEM_III_OO(par) BOOST_PP_TUPLE_ELEM_III ## par
#        define BOOST_PP_TUPLE_ELEM_III(n, etuple) BOOST_PP_TUPLE_ELEM_ ## n ## etuple
#    else
#        define BOOST_PP_TUPLE_ELEM(size, n, tuple) BOOST_PP_TUPLE_ELEM_I(BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM_, n) BOOST_PP_CAT(BOOST_PP_TUPLE_ELEM_E_, size) tuple)
#        define BOOST_PP_TUPLE_ELEM_I(x) x
#    endif
#    define BOOST_PP_TUPLE_ELEM_E_1(e0) (e0, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_2(e0, e1) (e0, e1, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_3(e0, e1, e2) (e0, e1, e2, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_4(e0, e1, e2, e3) (e0, e1, e2, e3, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_5(e0, e1, e2, e3, e4) (e0, e1, e2, e3, e4, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_6(e0, e1, e2, e3, e4, e5) (e0, e1, e2, e3, e4, e5, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_7(e0, e1, e2, e3, e4, e5, e6) (e0, e1, e2, e3, e4, e5, e6, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_8(e0, e1, e2, e3, e4, e5, e6, e7) (e0, e1, e2, e3, e4, e5, e6, e7, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_9(e0, e1, e2, e3, e4, e5, e6, e7, e8) (e0, e1, e2, e3, e4, e5, e6, e7, e8, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, ?, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, ?, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, ?, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, ?, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, ?, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, ?, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, ?, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, ?, ?)
#    define BOOST_PP_TUPLE_ELEM_E_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62) (e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, ?)
#    define BOOST_PP_TUPLE_ELEM_E_64
#    define BOOST_PP_TUPLE_ELEM_0(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e0
#    define BOOST_PP_TUPLE_ELEM_1(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e1
#    define BOOST_PP_TUPLE_ELEM_2(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e2
#    define BOOST_PP_TUPLE_ELEM_3(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e3
#    define BOOST_PP_TUPLE_ELEM_4(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e4
#    define BOOST_PP_TUPLE_ELEM_5(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e5
#    define BOOST_PP_TUPLE_ELEM_6(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e6
#    define BOOST_PP_TUPLE_ELEM_7(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e7
#    define BOOST_PP_TUPLE_ELEM_8(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e8
#    define BOOST_PP_TUPLE_ELEM_9(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e9
#    define BOOST_PP_TUPLE_ELEM_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e10
#    define BOOST_PP_TUPLE_ELEM_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e11
#    define BOOST_PP_TUPLE_ELEM_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e12
#    define BOOST_PP_TUPLE_ELEM_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e13
#    define BOOST_PP_TUPLE_ELEM_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e14
#    define BOOST_PP_TUPLE_ELEM_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e15
#    define BOOST_PP_TUPLE_ELEM_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e16
#    define BOOST_PP_TUPLE_ELEM_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e17
#    define BOOST_PP_TUPLE_ELEM_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e18
#    define BOOST_PP_TUPLE_ELEM_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e19
#    define BOOST_PP_TUPLE_ELEM_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e20
#    define BOOST_PP_TUPLE_ELEM_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e21
#    define BOOST_PP_TUPLE_ELEM_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e22
#    define BOOST_PP_TUPLE_ELEM_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e23
#    define BOOST_PP_TUPLE_ELEM_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e24
#    define BOOST_PP_TUPLE_ELEM_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e25
#    define BOOST_PP_TUPLE_ELEM_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e26
#    define BOOST_PP_TUPLE_ELEM_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e27
#    define BOOST_PP_TUPLE_ELEM_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e28
#    define BOOST_PP_TUPLE_ELEM_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e29
#    define BOOST_PP_TUPLE_ELEM_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e30
#    define BOOST_PP_TUPLE_ELEM_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e31
#    define BOOST_PP_TUPLE_ELEM_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e32
#    define BOOST_PP_TUPLE_ELEM_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e33
#    define BOOST_PP_TUPLE_ELEM_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e34
#    define BOOST_PP_TUPLE_ELEM_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e35
#    define BOOST_PP_TUPLE_ELEM_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e36
#    define BOOST_PP_TUPLE_ELEM_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e37
#    define BOOST_PP_TUPLE_ELEM_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e38
#    define BOOST_PP_TUPLE_ELEM_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e39
#    define BOOST_PP_TUPLE_ELEM_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e40
#    define BOOST_PP_TUPLE_ELEM_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e41
#    define BOOST_PP_TUPLE_ELEM_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e42
#    define BOOST_PP_TUPLE_ELEM_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e43
#    define BOOST_PP_TUPLE_ELEM_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e44
#    define BOOST_PP_TUPLE_ELEM_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e45
#    define BOOST_PP_TUPLE_ELEM_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e46
#    define BOOST_PP_TUPLE_ELEM_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e47
#    define BOOST_PP_TUPLE_ELEM_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e48
#    define BOOST_PP_TUPLE_ELEM_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e49
#    define BOOST_PP_TUPLE_ELEM_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e50
#    define BOOST_PP_TUPLE_ELEM_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e51
#    define BOOST_PP_TUPLE_ELEM_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e52
#    define BOOST_PP_TUPLE_ELEM_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e53
#    define BOOST_PP_TUPLE_ELEM_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e54
#    define BOOST_PP_TUPLE_ELEM_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e55
#    define BOOST_PP_TUPLE_ELEM_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e56
#    define BOOST_PP_TUPLE_ELEM_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e57
#    define BOOST_PP_TUPLE_ELEM_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e58
#    define BOOST_PP_TUPLE_ELEM_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e59
#    define BOOST_PP_TUPLE_ELEM_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e60
#    define BOOST_PP_TUPLE_ELEM_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e61
#    define BOOST_PP_TUPLE_ELEM_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e62
#    define BOOST_PP_TUPLE_ELEM_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63) e63
# endif
#
# /* directly used elsewhere in Boost... */
#
# define BOOST_PP_TUPLE_ELEM_1_0(a) a
#
# define BOOST_PP_TUPLE_ELEM_2_0(a, b) a
# define BOOST_PP_TUPLE_ELEM_2_1(a, b) b
#
# define BOOST_PP_TUPLE_ELEM_3_0(a, b, c) a
# define BOOST_PP_TUPLE_ELEM_3_1(a, b, c) b
# define BOOST_PP_TUPLE_ELEM_3_2(a, b, c) c


//  ****************************************************************************
# /* BOOST_PP_IS_EMPTY */
#
# if BOOST_PP_VARIADICS
#
# if ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC() && ~BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MWCC()
#    define BOOST_PP_IS_EMPTY(x) BOOST_PP_IS_EMPTY_I(x BOOST_PP_IS_EMPTY_HELPER)
#    define BOOST_PP_IS_EMPTY_I(contents) BOOST_PP_TUPLE_ELEM(2, 1, (BOOST_PP_IS_EMPTY_DEF_ ## contents()))
#    define BOOST_PP_IS_EMPTY_DEF_BOOST_PP_IS_EMPTY_HELPER 1, BOOST_PP_IDENTITY(1)
#    define BOOST_PP_IS_EMPTY_HELPER() , 0
# else
#    if BOOST_PP_CONFIG_FLAGS() & BOOST_PP_CONFIG_MSVC()
#        define BOOST_PP_IS_EMPTY(x) BOOST_PP_IS_EMPTY_I(BOOST_PP_IS_EMPTY_HELPER x ())
#        define BOOST_PP_IS_EMPTY_I(test) BOOST_PP_IS_EMPTY_II(BOOST_PP_SPLIT(0, BOOST_PP_CAT(BOOST_PP_IS_EMPTY_DEF_, test)))
#        define BOOST_PP_IS_EMPTY_II(id) id
#    else
#        define BOOST_PP_IS_EMPTY(x) BOOST_PP_IS_EMPTY_I((BOOST_PP_IS_EMPTY_HELPER x ()))
#        define BOOST_PP_IS_EMPTY_I(par) BOOST_PP_IS_EMPTY_II ## par
#        define BOOST_PP_IS_EMPTY_II(test) BOOST_PP_SPLIT(0, BOOST_PP_CAT(BOOST_PP_IS_EMPTY_DEF_, test))
#    endif
#    define BOOST_PP_IS_EMPTY_HELPER() 1
#    define BOOST_PP_IS_EMPTY_DEF_1 1, BOOST_PP_NIL
#    define BOOST_PP_IS_EMPTY_DEF_BOOST_PP_IS_EMPTY_HELPER 0, BOOST_PP_NIL
# endif
#
# endif /* BOOST_PP_VARIADICS */


//  ****************************************************************************
# /* BOOST_PP_IS_1 */
#
# define BOOST_PP_IS_1(x) BOOST_PP_IS_EMPTY(BOOST_PP_CAT(BOOST_PP_IS_1_HELPER_, x))
# define BOOST_PP_IS_1_HELPER_1


//  ****************************************************************************
# /* BOOST_PP_TUPLE_IS_SINGLE_RETURN */
#
# if BOOST_PP_VARIADICS && BOOST_PP_VARIADICS_MSVC
# define BOOST_PP_TUPLE_IS_SINGLE_RETURN(sr,nsr,tuple)	\
	BOOST_PP_IIF(BOOST_PP_IS_1(BOOST_PP_TUPLE_SIZE(tuple)),sr,nsr) \
	/**/
# endif /* BOOST_PP_VARIADICS && BOOST_PP_VARIADICS_MSVC */


//  ****************************************************************************


//  ****************************************************************************
#if BOOST_PP_VARIADICS_MSVC

#define BOOST_PP_DETAIL_VD_IBP_CAT(a, b) BOOST_PP_DETAIL_VD_IBP_CAT_I(a, b)
#define BOOST_PP_DETAIL_VD_IBP_CAT_I(a, b) BOOST_PP_DETAIL_VD_IBP_CAT_II(a ## b)
#define BOOST_PP_DETAIL_VD_IBP_CAT_II(res) res

#define BOOST_PP_DETAIL_IBP_SPLIT(i, ...) \
    BOOST_PP_DETAIL_VD_IBP_CAT(BOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(BOOST_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__),BOOST_PP_EMPTY()) \
/**/

#define BOOST_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1 1

#else

#define BOOST_PP_DETAIL_IBP_SPLIT(i, ...) \
    BOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(BOOST_PP_DETAIL_IBP_SPLIT_,i)(__VA_ARGS__) \
/**/

#define BOOST_PP_DETAIL_IBP_IS_VARIADIC_C(...) 1

#endif /* BOOST_PP_VARIADICS_MSVC */

#define BOOST_PP_DETAIL_IBP_SPLIT_0(a, ...) a
#define BOOST_PP_DETAIL_IBP_SPLIT_1(a, ...) __VA_ARGS__

#define BOOST_PP_DETAIL_IBP_CAT(a, ...) BOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(a,__VA_ARGS__)
#define BOOST_PP_DETAIL_IBP_PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define BOOST_PP_DETAIL_IBP_IS_VARIADIC_R_1 1,
#define BOOST_PP_DETAIL_IBP_IS_VARIADIC_R_BOOST_PP_DETAIL_IBP_IS_VARIADIC_C 0,


//  ****************************************************************************
# /* BOOST_PP_VARIADIC_ELEM */
#
# if BOOST_PP_VARIADICS
#    if BOOST_PP_VARIADICS_MSVC
#        define BOOST_PP_VARIADIC_ELEM(n, ...) BOOST_PP_VARIADIC_ELEM_I(n,__VA_ARGS__)
#        define BOOST_PP_VARIADIC_ELEM_I(n, ...) BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_VARIADIC_ELEM_, n)(__VA_ARGS__,),)
#    else
#        define BOOST_PP_VARIADIC_ELEM(n, ...) BOOST_PP_CAT(BOOST_PP_VARIADIC_ELEM_, n)(__VA_ARGS__,)
#    endif
#    define BOOST_PP_VARIADIC_ELEM_0(e0, ...) e0
#    define BOOST_PP_VARIADIC_ELEM_1(e0, e1, ...) e1
#    define BOOST_PP_VARIADIC_ELEM_2(e0, e1, e2, ...) e2
#    define BOOST_PP_VARIADIC_ELEM_3(e0, e1, e2, e3, ...) e3
#    define BOOST_PP_VARIADIC_ELEM_4(e0, e1, e2, e3, e4, ...) e4
#    define BOOST_PP_VARIADIC_ELEM_5(e0, e1, e2, e3, e4, e5, ...) e5
#    define BOOST_PP_VARIADIC_ELEM_6(e0, e1, e2, e3, e4, e5, e6, ...) e6
#    define BOOST_PP_VARIADIC_ELEM_7(e0, e1, e2, e3, e4, e5, e6, e7, ...) e7
#    define BOOST_PP_VARIADIC_ELEM_8(e0, e1, e2, e3, e4, e5, e6, e7, e8, ...) e8
#    define BOOST_PP_VARIADIC_ELEM_9(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, ...) e9
#    define BOOST_PP_VARIADIC_ELEM_10(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, ...) e10
#    define BOOST_PP_VARIADIC_ELEM_11(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, ...) e11
#    define BOOST_PP_VARIADIC_ELEM_12(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, ...) e12
#    define BOOST_PP_VARIADIC_ELEM_13(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, ...) e13
#    define BOOST_PP_VARIADIC_ELEM_14(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, ...) e14
#    define BOOST_PP_VARIADIC_ELEM_15(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, ...) e15
#    define BOOST_PP_VARIADIC_ELEM_16(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, ...) e16
#    define BOOST_PP_VARIADIC_ELEM_17(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, ...) e17
#    define BOOST_PP_VARIADIC_ELEM_18(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, ...) e18
#    define BOOST_PP_VARIADIC_ELEM_19(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, ...) e19
#    define BOOST_PP_VARIADIC_ELEM_20(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, ...) e20
#    define BOOST_PP_VARIADIC_ELEM_21(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, ...) e21
#    define BOOST_PP_VARIADIC_ELEM_22(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, ...) e22
#    define BOOST_PP_VARIADIC_ELEM_23(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, ...) e23
#    define BOOST_PP_VARIADIC_ELEM_24(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, ...) e24
#    define BOOST_PP_VARIADIC_ELEM_25(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, ...) e25
#    define BOOST_PP_VARIADIC_ELEM_26(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, ...) e26
#    define BOOST_PP_VARIADIC_ELEM_27(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, ...) e27
#    define BOOST_PP_VARIADIC_ELEM_28(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, ...) e28
#    define BOOST_PP_VARIADIC_ELEM_29(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, ...) e29
#    define BOOST_PP_VARIADIC_ELEM_30(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, ...) e30
#    define BOOST_PP_VARIADIC_ELEM_31(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, ...) e31
#    define BOOST_PP_VARIADIC_ELEM_32(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, ...) e32
#    define BOOST_PP_VARIADIC_ELEM_33(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, ...) e33
#    define BOOST_PP_VARIADIC_ELEM_34(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, ...) e34
#    define BOOST_PP_VARIADIC_ELEM_35(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, ...) e35
#    define BOOST_PP_VARIADIC_ELEM_36(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, ...) e36
#    define BOOST_PP_VARIADIC_ELEM_37(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, ...) e37
#    define BOOST_PP_VARIADIC_ELEM_38(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, ...) e38
#    define BOOST_PP_VARIADIC_ELEM_39(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, ...) e39
#    define BOOST_PP_VARIADIC_ELEM_40(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, ...) e40
#    define BOOST_PP_VARIADIC_ELEM_41(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, ...) e41
#    define BOOST_PP_VARIADIC_ELEM_42(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, ...) e42
#    define BOOST_PP_VARIADIC_ELEM_43(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, ...) e43
#    define BOOST_PP_VARIADIC_ELEM_44(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, ...) e44
#    define BOOST_PP_VARIADIC_ELEM_45(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, ...) e45
#    define BOOST_PP_VARIADIC_ELEM_46(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, ...) e46
#    define BOOST_PP_VARIADIC_ELEM_47(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, ...) e47
#    define BOOST_PP_VARIADIC_ELEM_48(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, ...) e48
#    define BOOST_PP_VARIADIC_ELEM_49(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, ...) e49
#    define BOOST_PP_VARIADIC_ELEM_50(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, ...) e50
#    define BOOST_PP_VARIADIC_ELEM_51(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, ...) e51
#    define BOOST_PP_VARIADIC_ELEM_52(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, ...) e52
#    define BOOST_PP_VARIADIC_ELEM_53(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, ...) e53
#    define BOOST_PP_VARIADIC_ELEM_54(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, ...) e54
#    define BOOST_PP_VARIADIC_ELEM_55(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, ...) e55
#    define BOOST_PP_VARIADIC_ELEM_56(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, ...) e56
#    define BOOST_PP_VARIADIC_ELEM_57(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, ...) e57
#    define BOOST_PP_VARIADIC_ELEM_58(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, ...) e58
#    define BOOST_PP_VARIADIC_ELEM_59(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, ...) e59
#    define BOOST_PP_VARIADIC_ELEM_60(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, ...) e60
#    define BOOST_PP_VARIADIC_ELEM_61(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, ...) e61
#    define BOOST_PP_VARIADIC_ELEM_62(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, ...) e62
#    define BOOST_PP_VARIADIC_ELEM_63(e0, e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12, e13, e14, e15, e16, e17, e18, e19, e20, e21, e22, e23, e24, e25, e26, e27, e28, e29, e30, e31, e32, e33, e34, e35, e36, e37, e38, e39, e40, e41, e42, e43, e44, e45, e46, e47, e48, e49, e50, e51, e52, e53, e54, e55, e56, e57, e58, e59, e60, e61, e62, e63, ...) e63
# endif


//  ****************************************************************************
# /* BOOST_PP_IDENTITY */
#
# define BOOST_PP_IDENTITY(item) item BOOST_PP_EMPTY


//  ****************************************************************************
#if BOOST_PP_VARIADICS

#if BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define BOOST_PP_IS_BEGIN_PARENS(param) \
    BOOST_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      BOOST_PP_DETAIL_IBP_CAT \
        ( \
        BOOST_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        BOOST_PP_DETAIL_IBP_IS_VARIADIC_C param \
        ) \
      ) \
/**/

#else

#define BOOST_PP_IS_BEGIN_PARENS(...) \
    BOOST_PP_DETAIL_IBP_SPLIT \
      ( \
      0, \
      BOOST_PP_DETAIL_IBP_CAT \
        ( \
        BOOST_PP_DETAIL_IBP_IS_VARIADIC_R_, \
        BOOST_PP_DETAIL_IBP_IS_VARIADIC_C __VA_ARGS__ \
        ) \
      ) \
/**/

#endif /* BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400 */
#endif /* BOOST_PP_VARIADICS */

//  ****************************************************************************
# if BOOST_PP_VARIADICS
#
#if BOOST_PP_VARIADICS_MSVC

# pragma warning(once:4002)

#define BOOST_PP_DETAIL_IS_EMPTY_IIF_0(t, b) b
#define BOOST_PP_DETAIL_IS_EMPTY_IIF_1(t, b) t

#else

#define BOOST_PP_DETAIL_IS_EMPTY_IIF_0(t, ...) __VA_ARGS__
#define BOOST_PP_DETAIL_IS_EMPTY_IIF_1(t, ...) t

#endif

#if BOOST_PP_VARIADICS_MSVC && _MSC_VER <= 1400

#define BOOST_PP_DETAIL_IS_EMPTY_PROCESS(param) \
	BOOST_PP_IS_BEGIN_PARENS \
    	( \
        BOOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C param () \
        ) \
/**/

#else

#define BOOST_PP_DETAIL_IS_EMPTY_PROCESS(...) \
	BOOST_PP_IS_BEGIN_PARENS \
        ( \
        BOOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C __VA_ARGS__ () \
        ) \
/**/

#endif

#define BOOST_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(a, b) a ## b
#define BOOST_PP_DETAIL_IS_EMPTY_IIF(bit) BOOST_PP_DETAIL_IS_EMPTY_PRIMITIVE_CAT(BOOST_PP_DETAIL_IS_EMPTY_IIF_,bit)
#define BOOST_PP_DETAIL_IS_EMPTY_NON_FUNCTION_C(...) ()

# endif /* BOOST_PP_VARIADICS */

#endif
