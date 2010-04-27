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

include $(top_srcdir)/libgda/src/filelist.am
include $(top_srcdir)/libgda/libgdamm/filelist.am

libgdamm_files_h = $(files_built_h) $(filter-out wrap_init.h,$(files_extra_h))

book_name = $(LIBGDAMM_MODULE_NAME)
doc_input = $(addprefix $(top_srcdir)/libgda/libgdamm/,$(libgdamm_files_h)) \
            $(top_srcdir)/libgda/libgdamm.h

include $(top_srcdir)/build/doc-reference.am
