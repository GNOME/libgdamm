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

ACLOCAL_AMFLAGS = -I build ${ACLOCAL_FLAGS}
DISTCHECK_CONFIGURE_FLAGS = --enable-warnings=fatal

if MAINTAINER_MODE
src_subdirs = tools libgda/src
else
src_subdirs =
endif
if ENABLE_DOCUMENTATION
doc_subdirs = docs
else
doc_subdirs =
endif
SUBDIRS = $(src_subdirs) libgda/libgdamm examples $(doc_subdirs)

libgdamm_includedir = $(includedir)/$(LIBGDAMM_MODULE_NAME)
libgdamm_include_HEADERS = libgda/libgdamm.h
libgdamm_libincludedir = $(libdir)/$(LIBGDAMM_MODULE_NAME)/include
nodist_libgdamm_libinclude_HEADERS = libgda/libgdammconfig.h

pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = libgda/$(LIBGDAMM_MODULE_NAME).pc

dist_noinst_DATA = COPYING.examples
dist_noinst_SCRIPTS = autogen.sh

# Optional: auto-generate the ChangeLog file from the git log on make dist
include $(top_srcdir)/build/dist-changelog.am
