#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([Alchemy], [1.0], [cybercritter@off-by-one.us])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([alchemy/main.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_CHECK_PROG([bash_var], [bash], [yes],[no],, [/usr/sbin/bash])

AC_PROG_INSTALL

# Checks for libraries.
AC_SEARCH_LIBS([pthread_create], [pthread])

# Checks for header files.
AC_LANG_PUSH([C])
    AC_CHECK_HEADERS([stdio.h stdlib.h unistd.h pthread.h])
AC_LANG_PUSH([C++])
    AC_CHECK_HEADERS([iostream cstdlib vector])
    AX_CXX_COMPILE_STDCXX_11([noext], [optional])
AC_LANG_POP([C++])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 alchemy/Makefile])
AC_OUTPUT

echo \
"-------------------------------------------------------------------------------

${PACKAGE_NAME} Version: ${PACKAGE_VERSION}

Prefix: '${prefix}'
Package_features: 
	Async Execution: ${async_exec}

Now Type 'make @<:@<target>@:>@
  where the optional <target> is 
   all: 	- build all binaries
   install:     - install everything
--------------------------------------------------------------------------------"
