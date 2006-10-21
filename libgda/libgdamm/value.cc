/* $Id$ */
// -*- C++ -*- //

/* value.cc
 * 
 * Copyright 2006 libgdamm Development Team
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

#include <libgdamm/value.h>
#include <libgda/gda-value.h>
#include <libgda/gda-enum-types.h>
#include <libgda/gda-util.h>

namespace Gnome
{
  
namespace Gda
{

GType value_get_type_null()
{
  return GDA_TYPE_NULL;
}

GType value_get_type_binary()
{
  return GDA_TYPE_BINARY;
}

GType value_get_type_blob()
{
  return GDA_TYPE_BLOB;
}

GType value_get_type_geometric_point()
{
  return GDA_TYPE_GEOMETRIC_POINT;
}

GType value_get_type_list()
{
  return GDA_TYPE_LIST;
}

GType value_get_type_numeric()
{
  return GDA_TYPE_NUMERIC;
}

GType value_get_type_short()
{
  return GDA_TYPE_SHORT;
}

GType value_get_type_ushort()
{
  return GDA_TYPE_USHORT;
}

GType value_get_type_time()
{
  return GDA_TYPE_TIME;
}

GType value_get_type_timestamp()
{
  return GDA_TYPE_TIMESTAMP;
}

/*
const GType VALUE_TYPE_NULL = GDA_TYPE_NULL;
const GType VALUE_TYPE_BINARY = GDA_TYPE_BINARY;
const GType VALUE_TYPE_BLOB = GDA_TYPE_BLOB;
const GType VALUE_TYPE_GEOMETRIC_POINT = GDA_TYPE_GEOMETRIC_POINT;
const GType VALUE_TYPE_LIST = GDA_TYPE_LIST;
const GType VALUE_TYPE_NUMERIC = GDA_TYPE_NUMERIC;
const GType VALUE_TYPE_SHORT = GDA_TYPE_SHORT;
const GType VALUE_TYPE_USHORT = GDA_TYPE_USHORT;
const GType VALUE_TYPE_TIME = GDA_TYPE_TIME;
const GType VALUE_TYPE_TIMESTAMP = GDA_TYPE_TIMESTAMP;
*/



GType value_get_type(const Glib::ValueBase& value)
{
  return G_VALUE_TYPE(value.gobj());
}

Glib::ustring value_to_string(const Glib::ValueBase& value)
{
  Glib::convert_return_gchar_ptr_to_ustring( gda_value_stringify(value.gobj()) );
}

bool value_is_null(const Glib::ValueBase& value)
{
  return gda_value_is_null( value.gobj() );
}

bool value_is_number(const Glib::ValueBase& value)
{
  return gda_value_is_number( value.gobj() );
}

int value_compare(const Glib::ValueBase& value1, const Glib::ValueBase& value2)
{
  return gda_value_compare(value1.gobj(), value2.gobj());
}

int value_compare_ext(const Glib::ValueBase& value1, const Glib::ValueBase& value2)
{
  return gda_value_compare_ext(value1.gobj(), value2.gobj());
}

bool value_equal(const Glib::ValueBase& value1, const Glib::ValueBase& value2)
{
  if( !value1.gobj() && !value2.gobj()) //If both are null.
    return true;

  if( !value1.gobj() && value2.gobj()) //If one is null.
    return false;

  if( value1.gobj() && !value2.gobj()) //If one is null.
    return false;

  if(G_VALUE_TYPE(value1.gobj()) != G_VALUE_TYPE(value2.gobj())) //gda_value_compare() can only compare GdaValues of the same type.
    return false;
    
  int test = gda_value_compare(value1.gobj(), value2.gobj());
  return test == 0;
}


void value_set_char(Glib::ValueBase& value, gchar v_char)
{
  g_value_set_char(value.gobj(), v_char);
}

gchar value_get_char(const Glib::ValueBase& value)
{
  return g_value_get_char(value.gobj());
}

void value_set_uchar(Glib::ValueBase& value, guchar v_uchar)
{
  g_value_set_uchar(value.gobj(), v_uchar);
}

guchar value_get_uchar(const Glib::ValueBase& value)
{
  return g_value_get_uchar(value.gobj());
}

void value_set_boolean(Glib::ValueBase& value, bool v_boolean)
{
  g_value_set_boolean(value.gobj(), v_boolean);
}

bool value_get_boolean(const Glib::ValueBase& value)
{
  return g_value_get_boolean(value.gobj());
}

void value_set_int(Glib::ValueBase& value,  int v_int)
{
  g_value_set_int(value.gobj(), v_int);
}

int value_get_int(const Glib::ValueBase& value)
{
  return g_value_get_int(value.gobj());
}

void value_set_uint(Glib::ValueBase& value, guint v_uint)
{
  g_value_set_uint(value.gobj(), v_uint);
}

guint value_get_uint(const Glib::ValueBase& value)
{
  return g_value_get_uint(value.gobj());
}

void value_set_long(Glib::ValueBase& value, long v_long)
{
  g_value_set_long(value.gobj(), v_long);
}

long value_get_long(const Glib::ValueBase& value)
{
  return g_value_get_long(value.gobj());
}

void value_set_ulong(Glib::ValueBase& value, unsigned long v_ulong)
{
  g_value_set_ulong(value.gobj(), v_ulong);
}

unsigned long value_get_ulong(const Glib::ValueBase& value)
{
  return g_value_get_ulong(value.gobj());
}

void value_set_int64(Glib::ValueBase& value, gint64 v_int64)
{
  g_value_set_int64(value.gobj(), v_int64);
}

gint64 value_get_int64(const Glib::ValueBase& value)
{
  return g_value_get_int64(value.gobj());
}

void value_set_uint64(Glib::ValueBase& value, guint64 v_uint64)
{
  g_value_set_uint64(value.gobj(), v_uint64);
}

guint64 value_get_uint64(const Glib::ValueBase& value)
{
  return g_value_get_uint64(value.gobj());
}

void value_set_float(Glib::ValueBase& value, float v_float)
{
  g_value_set_float(value.gobj(), v_float);
}

float value_get_float(const Glib::ValueBase& value)
{
  return g_value_get_float(value.gobj());
}

void value_set_double(Glib::ValueBase& value, double v_double)
{
  g_value_set_double(value.gobj(), v_double);
}

double value_get_double(const Glib::ValueBase& value)
{
  return g_value_get_double(value.gobj());
}

void value_set_string(Glib::ValueBase& value, const Glib::ustring& v_string)
{
  g_value_set_string(value.gobj(), v_string.c_str());
}


Glib::ustring value_get_string(const Glib::ValueBase& value)
{
  return g_value_get_string(value.gobj());
}




//Gda types:

const GdaBinary* value_get_binary(const Glib::ValueBase& value)
{
  return gda_value_get_binary(value.gobj());
}

void value_set_binary(Glib::ValueBase& value, const GdaBinary& binary)
{
  gda_value_set_binary(value.gobj(), &binary);
}

const GdaBlob* value_get_blob(const Glib::ValueBase& value)
{
  return gda_value_get_blob(value.gobj());
}

void value_set_blob(Glib::ValueBase& value, const GdaBlob& val)
{
  gda_value_set_blob(value.gobj(), &val);
}

const GdaGeometricPoint* value_get_geometric_point(const Glib::ValueBase& value)
{
  return gda_value_get_geometric_point(value.gobj());
}

void value_set_geometric_point(Glib::ValueBase& value, const GdaGeometricPoint& val);

const GdaValueList* value_get_list(const Glib::ValueBase& value)
{
  return gda_value_get_list(value.gobj());
}

void value_set_list(Glib::ValueBase& value, const GdaValueList& val)
{
  gda_value_set_list(value.gobj(), &val);
}

const GdaNumeric* value_get_numeric(const Glib::ValueBase& value)
{
  return gda_value_get_numeric(value.gobj());
}

void value_set_numeric(Glib::ValueBase& value, const GdaNumeric& val)
{
  gda_value_set_numeric(value.gobj(), &val);
}

gshort value_get_short(const Glib::ValueBase& value)
{
  return gda_value_get_short(value.gobj());
}

void value_set_short(Glib::ValueBase& value, const gshort val)
{
  gda_value_set_short(value.gobj(), val);
}

gushort value_get_ushort(const Glib::ValueBase& value)
{
  return gda_value_get_ushort(value.gobj());
}

void value_set_ushort(Glib::ValueBase& value, const gushort val)
{
  gda_value_set_ushort(value.gobj(), val);
}

const GdaTime* value_get_time(const Glib::ValueBase& value)
{
  return gda_value_get_time(value.gobj());
}

void value_set_time(Glib::ValueBase& value, const GdaTime& val)
{
  gda_value_set_time(value.gobj(), &val);
}

const GdaTimestamp* value_get_timestamp(const Glib::ValueBase& value)
{
  return gda_value_get_timestamp(value.gobj());
}


void value_set_timestamp(Glib::ValueBase& value, const GdaTimestamp& val)
{
  gda_value_set_timestamp(value.gobj(), &val);
}




} // namespace Gda

} // namespace Gnome


