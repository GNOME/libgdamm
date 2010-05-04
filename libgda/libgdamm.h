/* libgdamm - a C++ wrapper for libgda
 *
 * Copyright 1999-2001 Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef LIBGDAMM_H
#define LIBGDAMM_H

/** @mainpage libgdamm Reference Manual
 *
 * @section description Description
 *
 * libgdamm is a C++ wrapper for the <a href="http://www.gnome-db.org/">libgda</a> 
 * generic database access API.
 *
 * @section basics Basic Usage
 *
 * Include the libgdamm header:
 * @code
 * #include <libgdamm.h>
 * @endcode
 * (You may include individual headers, such as @c libgdamm/connection.h
 * instead.)
 *
 * If your source file is @c program.cc, you can compile it with:
 * @code
 * g++ program.cc -o program `pkg-config --cflags --libs libgdamm-4.0`
 * @endcode
 *
 * Alternatively, if using autoconf, use the following in @c configure.ac:
 * @code
 * PKG_CHECK_MODULES([LIBGDAMM], [libgdamm-4.0])
 * @endcode
 * Then use the generated @c LIBGDAMM_CFLAGS and @c LIBGDAMM_LIBS variables in
 * the project @c Makefile.am files. For example:
 * @code
 * program_CPPFLAGS = $(LIBGDAMM_CFLAGS)
 * program_LDADD = $(LIBGDAMM_LIBS)
 * @endcode
 */

/* libgdamm version.  */
extern const int libgdamm_major_version;
extern const int libgdamm_minor_version;
extern const int libgdamm_micro_version;

#include <glibmm.h>

#include <libgdamm/init.h>
#include <libgdamm/batch.h>
#include <libgdamm/blobop.h>
#include <libgdamm/column.h>
#include <libgdamm/config.h>
#include <libgdamm/connection.h>
#include <libgdamm/connectionevent.h>
#include <libgdamm/dataaccesswrapper.h>
#include <libgdamm/datacomparator.h>
#include <libgdamm/datahandler.h>
#include <libgdamm/datamodel.h>
#include <libgdamm/datamodelarray.h>
#include <libgdamm/datamodelimport.h>
#include <libgdamm/datamodeliter.h>
#include <libgdamm/dataproxy.h>
#include <libgdamm/dataselect.h>
#include <libgdamm/holder.h>
#include <libgdamm/metastore.h>
#include <libgdamm/metastruct.h>
#include <libgdamm/quarklist.h>
#include <libgdamm/row.h>
#include <libgdamm/serveroperation.h>
#include <libgdamm/serverprovider.h>
#include <libgdamm/set.h>
#include <libgdamm/sqlparser.h>
#include <libgdamm/sqlbuilder.h>
#include <libgdamm/statement.h>
#include <libgdamm/transactionstatus.h>
#include <libgdamm/xatransaction.h>

#endif /* #ifndef LIBGDAMM_H */
