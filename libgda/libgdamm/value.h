// -*- c++ -*-
#ifndef _LIBGDAMM_VALUE_H
#define _LIBGDAMM_VALUE_H


/* $Id$ */
// -*- C++ -*- //

/* value.h
 *
 * Copyright 2003 libgdamm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <glibmm.h>
#include <glibmm/value.h>
#include <libgda/gda-value.h> //TODO: Patch libgda to use the struct _ technique.


namespace Gnome
{

namespace Gda
{

//gtkmmproc error: GValueType : enum defs lookup failed.

typedef GdaGeometricPoint GeometricPoint;

/*  TODO:
typedef struct {
	gchar *currency;
	gdouble amount;
} GdaMoney;

typedef struct {
	gchar *number;
	glong precision;
	glong width;
} GdaNumeric;
*/

Glib::ustring value_to_string(const Glib::ValueBase& value);

} //namespace Gda
} //namespaec Gnome


#endif /* _LIBGDAMM_VALUE_H */

