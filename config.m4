<<<<<<< HEAD
PHP_ARG_ENABLE(classnameresolver, for classname resolver support,
[  --enable-classname-resolver          Include classname resolver support])

if test "$PHP_CLASSNAMERESOLVER" != "no"; then
  PHP_SUBST(CLASSNAMERESOLVER_SHARED_LIBADD)

  PHP_NEW_EXTENSION(classresolver, classresolver.c, $ext_shared)
  CFLAGS="$CFLAGS -Wall -g"
=======
PHP_ARG_ENABLE(functional, enable functional PHP extension,
[  --enable-functional Enable Functional PHP])

if test "$PHP_FUNCTIONAL" != "no"; then
  PHP_SUBST(FUNCTIONAL_SHARED_LIBADD)

  PHP_NEW_EXTENSION(functional, functional.c, $ext_shared)
  CFLAGS="$CFLAGS -Wall -g -O0 -pedantic -std=c99"
>>>>>>> 7b4e837bb416ae80afebe593fae3501ae1b54455
fi
