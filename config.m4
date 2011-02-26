dnl
dnl $ Id: $
dnl

PHP_ARG_ENABLE(classnameresolver, whether to enable classnameresolver functions,
[  --enable-classnameresolver         Enable classnameresolver support])

if test "$PHP_CLASSNAMERESOLVER" != "no"; then
  export OLD_CPPFLAGS="$CPPFLAGS"
  export CPPFLAGS="$CPPFLAGS $INCLUDES -DHAVE_CLASSNAMERESOLVER"

  AC_MSG_CHECKING(PHP version)
  AC_TRY_COMPILE([#include <php_version.h>], [
#if PHP_VERSION_ID < 40000
#error  this extension requires at least PHP version 4.0.0
#endif
],
[AC_MSG_RESULT(ok)],
[AC_MSG_ERROR([need at least PHP 4.0.0])])

  export CPPFLAGS="$OLD_CPPFLAGS"


  PHP_SUBST(CLASSNAMERESOLVER_SHARED_LIBADD)
  AC_DEFINE(HAVE_CLASSNAMERESOLVER, 1, [ ])

  PHP_NEW_EXTENSION(classnameresolver, classnameresolver.c , $ext_shared)

fi

