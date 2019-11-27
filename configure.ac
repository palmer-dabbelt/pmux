AC_INIT(pmux, 0.0.0)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE

AC_LANG(C++)
AC_PROG_CXX
AX_CXX_COMPILE_STDCXX_17([noext], [mandatory])

AC_ARG_ENABLE(
    [asan],
    [AC_HELP_STRING([--enable-asan], [Enable address sanitizer])],
    [enable_asan=$enableval]
)
if test "x$enable_asan" = "xyes"
then
    CFLAGS="${CFLAGS} -fsanitize=address -fno-omit-frame-pointer"
    CXXFLAGS="${CXXFLAGS} -fsanitize=address -fno-omit-frame-pointer"

fi

AC_ARG_ENABLE(
    [debug],
    [AC_HELP_STRING([--enable-debug], [Enable debug])],
    [enable_debug=$enableval],
    [enable_debug=$enable_asan]
)
if test "x$enable_debug" = "xyes"
then
    CFLAGS="${CFLAGS} -Og -g"
    CXXFLAGS="${CXXFLAGS} -Og -g"
fi

CFLAGS="${CFLAGS} -Isrc"
CXXFLAGS="${CXXFLAGS} -Isrc"

AC_OUTPUT(Makefile)
