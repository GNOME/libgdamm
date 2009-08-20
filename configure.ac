## Copyright (c) 2009  Openismus GmbH  <http://www.openismus.com/>
##
## This file is part of libgdamm.
##
## libgdamm is free software: you can redistribute it and/or modify it
## under the terms of the GNU Lesser General Public License as published
## by the Free Software Foundation, either version 2.1 of the License,
## or (at your option) any later version.
##
## libgdamm is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
## See the GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this library.  If not, see <http://www.gnu.org/licenses/>.

AC_INIT([libgdamm], [3.99.16], [http://bugzilla.gnome.org/enter_bug.cgi?product=libgdamm],
        [libgdamm], [http://www.gtkmm.org/])
AC_PREREQ([2.59])

AC_CONFIG_SRCDIR([libgda/libgdamm.h])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build])
AC_CONFIG_HEADERS([build/config.h libgda/libgdammconfig.h])

MM_PREREQ([0.6])
MM_INIT_MODULE([libgdamm-4.0])

# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
AC_SUBST([LIBGDAMM_SO_VERSION], [11:0:0])

AM_INIT_AUTOMAKE([1.9 -Wno-portability dist-bzip2 no-define nostdinc tar-pax])
AM_MAINTAINER_MODE
AC_ARG_VAR([ACLOCAL_FLAGS], [aclocal flags, e.g. -I <macro dir>])

AC_PROG_CXX
AC_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

AC_SUBST([LIBGDAMM_MODULES], ['glibmm-2.4 >= 2.12.8 libgda-4.0 >= 4.0.0'])
PKG_CHECK_MODULES([LIBGDAMM], [$LIBGDAMM_MODULES])

PKG_CHECK_EXISTS([libgda-bdb-4.0], [libgdamm_have_bdb=yes], [libgdamm_have_bdb=no])
AS_IF([test "x$libgdamm_have_bdb" = xyes],
      [AC_DEFINE([HAVE_BDB], [1], [Define if the libgda-bdb plugin is available.])])
AM_CONDITIONAL([HAVE_BDB], [test "x$libgdamm_have_bdb" = xyes])

MM_PKG_CONFIG_SUBST([GMMPROC_DIR], [--variable=gmmprocdir glibmm-2.4])

AC_LANG([C++])
MM_ARG_ENABLE_WARNINGS([LIBGDAMM_WXXFLAGS],
                       [-Wall],
                       [-pedantic -Wall -Wextra],
                       [G GDA])

MM_ARG_ENABLE_DOCUMENTATION

# Temporary dummy
AM_CONDITIONAL([BUILD_REFERENCE], [false])

AC_CONFIG_FILES([
  Makefile

  libgda/libgdamm-4.0.pc
  libgda/src/Makefile
  libgda/libgdamm/Makefile

  tools/Makefile

  docs/Makefile
  docs/reference/Makefile
    docs/reference/Doxyfile

  examples/Makefile
    examples/simple/Makefile
  examples/config/Makefile
])
AC_OUTPUT
