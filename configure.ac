#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Alchemy], [1.0], [cybercritter@herostoybox.net],[Alchemy.tar.gz])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([Hg])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL

# Checks for libraries.

# Checks for header files.
AC_LANG_PUSH([C++])
    AC_CHECK_HEADERS([iostream cstdlib])
AC_LANG_POP([C++])

#Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 Hg/Makefile
                ])
AC_OUTPUT
