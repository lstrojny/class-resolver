PHP_ARG_ENABLE(classnameresolver, for classname resolver support,
[  --enable-classname-resolver          Include classname resolver support])

if test "$PHP_CLASSNAMERESOLVER" != "no"; then
  PHP_SUBST(CLASSNAMERESOLVER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(classnameresolver, classnameresolver.c, $ext_shared)
  CFLAGS="$CFLAGS -Wall -g"
fi
