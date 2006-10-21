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

extern const GType VALUE_TYPE_NULL;
extern const GType VALUE_TYPE_BINARY;
extern const GType VALUE_TYPE_BLOB;
extern const GType VALUE_TYPE_GEOMETRIC_POINT;
extern const GType VALUE_TYPE_LIST;
extern const GType VALUE_TYPE_NUMERIC;
extern const GType VALUE_TYPE_SHORT;
extern const GType VALUE_TYPE_USHORT;
extern const GType VALUE_TYPE_TIME;
extern const GType VALUE_TYPE_TIMESTAMP;

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

GType value_get_type();

Glib::ustring value_to_string(const Glib::ValueBase& value);




bool value_is_null(const Glib::ValueBase& value);
bool value_is_number(const Glib::ValueBase& value);


const GdaBinary* value_get_binary(const Glib::ValueBase& value);
void value_set_binary(Glib::ValueBase& value, const GdaBinary& binary);
//void                              gda_value_take_binary(Glib::ValueBase& value, const GdaBinary& binary);

const GdaBlob* value_get_blob(const Glib::ValueBase& value);
void value_set_blob(Glib::ValueBase& value, const GdaBlob& val);

const GdaGeometricPoint* value_get_geometric_point(const Glib::ValueBase& value);
void value_set_geometric_point(Glib::ValueBase& value, const GdaGeometricPoint& val);

const GdaValueList* value_get_list(const Glib::ValueBase& value);
void value_set_list(Glib::ValueBase& value, const GdaValueList& val);

void value_set_null(Glib::ValueBase& value);

const GdaNumeric* value_get_numeric(const Glib::ValueBase& value);
void value_set_numeric(Glib::ValueBase& value, const GdaNumeric& val);

gshort value_get_short(const Glib::ValueBase& value);
void value_set_short(Glib::ValueBase& value, const gshort val);

gushort value_get_ushort(const Glib::ValueBase& value);
void value_set_ushort(Glib::ValueBase& value, const gushort val);

const GdaTime* value_get_time(const Glib::ValueBase& value);
void value_set_time(Glib::ValueBase& value, const GdaTime& val);

const GdaTimestamp* value_get_timestamp(const Glib::ValueBase& value);
void value_set_timestamp(Glib::ValueBase& value, const GdaTimestamp& val);


int value_compare(const Glib::ValueBase& value1, const Glib::ValueBase& value2);
int value_compare_ext(const Glib::ValueBase& value1, const Glib::ValueBase& value2);
bool value_equal(const Glib::ValueBase& value1, const Glib::ValueBase& value2);


/*
xmlNodePtr                        gda_value_to_xml(const Glib::ValueBase& value);

gchar                            *gda_binary_to_string(const GdaBinary& bin, guint maxlen);
gboolean                          gda_string_to_binary(const gchar *str, GdaBinary *bin);


GType                             gda_numeric_get_type (void) G_GNUC_CONST;
gpointer                          gda_numeric_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_numeric_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_time_get_type(void) G_GNUC_CONST;
gpointer                          gda_time_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_time_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_timestamp_get_type(void) G_GNUC_CONST;
gpointer                          gda_timestamp_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_timestamp_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_geometricpoint_get_type(void) G_GNUC_CONST;
gpointer                          gda_geometricpoint_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_geometricpoint_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_binary_get_type(void) G_GNUC_CONST;
gpointer                          gda_binary_copy (gpointer boxed) G_GNUC_CONST;
void                              gda_binary_free (gpointer boxed) G_GNUC_CONST;

GType                             gda_value_list_get_type (void) G_GNUC_CONST;
GType                             gda_short_get_type (void) G_GNUC_CONST;
GType                             gda_ushort_get_type (void) G_GNUC_CONST;

#define                           gda_value_new_null() (g_new0 (GValue, 1))
*/




} //namespace Gda
} //namespaec Gnome


#endif /* _LIBGDAMM_VALUE_H */

