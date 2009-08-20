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

AUTOMAKE_OPTIONS = subdir-objects

check_PROGRAMS = config/example simple/example

libgdamm_includes = -I$(top_builddir)/libgda $(if $(srcdir:.=),-I$(top_srcdir)/libgda)

AM_CPPFLAGS = -I$(top_builddir) $(libgdamm_includes) $(LIBGDAMM_CFLAGS)
AM_CXXFLAGS = $(LIBGDAMM_WXXFLAGS)

LDADD = $(LIBGDAMM_LIBS) $(top_builddir)/libgda/libgdamm/libgdamm-$(LIBGDAMM_API_VERSION).la

config_example_SOURCES = config/main.cc
simple_example_SOURCES = simple/main.cc
