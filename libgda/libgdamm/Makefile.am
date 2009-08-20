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

lib_LTLIBRARIES = libgdamm-@LIBGDAMM_API_VERSION@.la

include $(srcdir)/../src/filelist.am
include $(srcdir)/filelist.am
include $(top_srcdir)/build/compile-binding.am

local_cppflags = $(binding_includes) $(binding_cppflags) -DLIBGDAMM_BUILD=1

AM_CPPFLAGS = $(local_cppflags) $(LIBGDAMM_CFLAGS)
AM_CXXFLAGS = $(LIBGDAMM_WXXFLAGS)

libgdamm_@LIBGDAMM_API_VERSION@_la_SOURCES = $(binding_sources)
libgdamm_@LIBGDAMM_API_VERSION@_la_LDFLAGS = -no-undefined -version-info $(LIBGDAMM_SO_VERSION)
libgdamm_@LIBGDAMM_API_VERSION@_la_LIBADD  = $(LIBGDAMM_LIBS)
