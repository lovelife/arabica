AC_DEFUN([ARABICA_HAS_WINSOCK],
[
  AC_MSG_CHECKING([for Winsock])
  AC_COMPILE_IFELSE([AC_LANG_PROGRAM([[#include <winsock.h>]],
                                     [[closesocket(1);]])],
                    [AS_VAR_SET(has_winsock, yes)],
                    [AS_VAR_SET(has_winsock, no)])
  AC_MSG_RESULT($has_winsock)
  if test $has_winsock = yes; then
    AC_DEFINE(ARABICA_USE_WINSOCK, ,[defined for Windows builds using Winsock rather than BSD-style sockets])
    PARSER_LIBS="$PARSER_LIBS -lwsock32"
  fi
])
