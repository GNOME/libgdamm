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

Glib::ustring value_to_string(const Glib::ValueBase& value);




bool value_is_null(const Glib::ValueBase& value);
bool value_is_number(const Glib::ValueBase& value);

/*
GValue                           *gda_value_copy (const GValue *value);

G_CONST_RETURN GdaBinary         *gda_value_get_binary (const GValue *value);
void                              gda_value_set_binary (GValue *value, const GdaBinary *binary);
void                              gda_value_take_binary (GValue *value, const GdaBinary *binary);
G_CONST_RETURN GdaBlob           *gda_value_get_blob (const GValue *value);
void                              gda_value_set_blob (GValue *value, const GdaBlob *val);
G_CONST_RETURN GdaGeometricPoint *gda_value_get_geometric_point (const GValue *value);
void                              gda_value_set_geometric_point (GValue *value, const GdaGeometricPoint *val);
G_CONST_RETURN GdaValueList      *gda_value_get_list (const GValue *value);
void                              gda_value_set_list (GValue *value, const GdaValueList *val);
void                              gda_value_set_null (GValue *value);
G_CONST_RETURN GdaNumeric        *gda_value_get_numeric (const GValue *value);
void                              gda_value_set_numeric (GValue *value, const GdaNumeric *val);
gshort                            gda_value_get_short (const GValue *value);
void                              gda_value_set_short (GValue *value, const gshort val);
gushort                           gda_value_get_ushort (const GValue *value);
void                              gda_value_set_ushort (GValue *value, const gushort val);
G_CONST_RETURN GdaTime           *gda_value_get_time (const GValue *value);
void                              gda_value_set_time (GValue *value, const GdaTime *val);
G_CONST_RETURN GdaTimestamp      *gda_value_get_timestamp (const GValue *value);
void                              gda_value_set_timestamp (GValue *value, const GdaTimestamp *val);





gboolean                          gda_value_set_from_string (GValue *value, 
						             const gchar *as_string,
						             GType type);
gboolean                          gda_value_set_from_value (GValue *value, const GValue *from);
*/

int value_compare(const Glib::ValueBase& value1, const Glib::ValueBase& value2);
int value_compare_ext(const Glib::ValueBase& value1, const Glib::ValueBase& value2);
bool value_equal(const Glib::ValueBase& value1, const Glib::ValueBase& value2);


/*
xmlNodePtr                        gda_value_to_xml (const GValue *value);

gchar                            *gda_binary_to_string (const GdaBinary *bin, guint maxlen);
gboolean                          gda_string_to_binary (const gchar *str, GdaBinary *bin);


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

