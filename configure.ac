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

AC_INIT([libgdamm], [4.1.2], [http://bugzilla.gnome.org/enter_bug.cgi?product=libgdamm],
        [libgdamm], [http://www.gtkmm.org/])
AC_PREREQ([2.59])

AC_CONFIG_SRCDIR([libgda/libgdamm.h])
AC_CONFIG_AUX_DIR([build])
AC_CONFIG_MACRO_DIR([build])
AC_CONFIG_HEADERS([build/config.h libgda/libgdammconfig.h])

MM_PREREQ([0.9.5])
MM_INIT_MODULE([libgdamm-4.0])

# Copy the mm-common .pl scripts into docs/,
# and use them from there,
# then dist them to avoid a tarball-build dependency.
MM_CONFIG_DOCTOOL_DIR([docs])

# http://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html
AC_SUBST([LIBGDAMM_SO_VERSION], [13:0:0])

AM_INIT_AUTOMAKE([1.9 -Wno-portability check-news dist-bzip2 no-define nostdinc tar-ustar])
AM_MAINTAINER_MODE
AC_ARG_VAR([ACLOCAL_FLAGS], [aclocal flags, e.g. -I <macro dir>])

AC_PROG_CXX
AC_DISABLE_STATIC
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL

AC_SUBST([LIBGDAMM_MODULES], ['glibmm-2.4 >= 2.27.93 libgda-4.0 >= 4.1.7'])
PKG_CHECK_MODULES([LIBGDAMM], [$LIBGDAMM_MODULES])

PKG_CHECK_EXISTS([libgda-bdb-4.0], [libgdamm_have_bdb=yes], [libgdamm_have_bdb=no])
AS_IF([test "x$libgdamm_have_bdb" = xyes],
      [AC_DEFINE([HAVE_LIBGDA_BDB], [1], [Define if the libgda-bdb plugin is available.])])

MM_PKG_CONFIG_SUBST([GMMPROC_DIR], [--variable=gmmprocdir glibmm-2.4])

AC_LANG([C++])
MM_ARG_ENABLE_WARNINGS([LIBGDAMM_WXXFLAGS],
                       [-Wall],
                       [-pedantic -Wall -Wextra -Wno-long-long -Wno-missing-field-initializers -DGSEAL_ENABLE],
                       [G GDA GLIBMM])

MM_ARG_ENABLE_DOCUMENTATION
MM_ARG_WITH_TAGFILE_DOC([libstdc++.tag], [mm-common-libstdc++])
MM_ARG_WITH_TAGFILE_DOC([libsigc++-2.0.tag], [sigc++-2.0])
MM_ARG_WITH_TAGFILE_DOC([glibmm-2.4.tag], [glibmm-2.4])

AC_CONFIG_FILES([Makefile
                 tools/Makefile
                 libgda/${LIBGDAMM_MODULE_NAME}.pc:libgda/libgdamm.pc.in
                 libgda/${LIBGDAMM_MODULE_NAME}-uninstalled.pc:libgda/libgdamm-uninstalled.pc.in
                 libgda/src/Makefile
                 libgda/libgdamm/Makefile
                 examples/Makefile
                 docs/Makefile
                 docs/reference/Doxyfile])
AC_OUTPUT
