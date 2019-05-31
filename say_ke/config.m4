dnl $Id$
dnl config.m4 for extension say_ke

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(say_ke, for say_ke support,
dnl Make sure that the comment is aligned:
dnl [  --with-say_ke             Include say_ke support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(say_ke, whether to enable say_ke support,
dnl Make sure that the comment is aligned:
[  --enable-say_ke           Enable say_ke support])

if test "$PHP_SAY_KE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-say_ke -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/say_ke.h"  # you most likely want to change this
  dnl if test -r $PHP_SAY_KE/$SEARCH_FOR; then # path given as parameter
  dnl   SAY_KE_DIR=$PHP_SAY_KE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for say_ke files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SAY_KE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SAY_KE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the say_ke distribution])
  dnl fi

  dnl # --with-say_ke -> add include path
  dnl PHP_ADD_INCLUDE($SAY_KE_DIR/include)

  dnl # --with-say_ke -> check for lib and symbol presence
  dnl LIBNAME=say_ke # you may want to change this
  dnl LIBSYMBOL=say_ke # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SAY_KE_DIR/$PHP_LIBDIR, SAY_KE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SAY_KELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong say_ke lib version or lib not found])
  dnl ],[
  dnl   -L$SAY_KE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SAY_KE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(say_ke, say_ke.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
