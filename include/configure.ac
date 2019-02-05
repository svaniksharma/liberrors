#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([liberrors], [1.02], [silentcat@silentcat.s])
AC_CONFIG_SRCDIR([liberrors.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([

Makefile
test/Makefile

])

LT_INIT
AM_INIT_AUTOMAKE
# Checks for programs.
AC_PROG_CC
AC_PROG_LN_S

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strerror])

AC_OUTPUT
