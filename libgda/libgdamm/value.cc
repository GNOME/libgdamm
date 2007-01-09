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



//static:
/*
Value Value::create_as_int64(gint64 val)
{
  return Value( gda_value_new_int64(val) );
}


//static:
Value Value::create_as_uint64(guint64 val)
{
  return Value( gda_value_new_uint64(val) );
}
*/


Value::Value(const guchar* val, long size)
{
  init(GDA_TYPE_BINARY);

  set(val, size);
}

Value::Value(const GdaBlob *val)
{
  init(GDA_TYPE_BLOB);
  set(val);
}

Value::Value(bool val)
{
  init( Glib::Value<bool>::value_type() );

  set(val);
}

Value::Value(const Glib::Date& val)
{
  init( Glib::Value<Glib::Date>::value_type() );

  set(val);
}

Value::Value(double val)
{
  init( Glib::Value<double>::value_type() );

  set(val);
}

Value::Value(const GeometricPoint& val)
{
  init( GDA_TYPE_GEOMETRIC_POINT );

  set(val);
}

Value::Value(int val)
{
  init( Glib::Value<int>::value_type() );

  set(val);
}

Value::Value(const GdaValueList* val)
{
  init(GDA_TYPE_LIST);

  set(val);
}

Value::Value(const GdaNumeric* val)
{
  init(GDA_TYPE_NUMERIC);

  set(val);
}

Value::Value(float val)
{
  init( Glib::Value<float>::value_type() );

  set(val);
}

Value::Value(gshort val)
{
  init(GDA_TYPE_SHORT);

  set(val);
}

Value::Value(gushort val)
{
  init(GDA_TYPE_USHORT);

  set(val);
}

Value::Value(const Glib::ustring& val)
{
  init( Glib::Value<Glib::ustring>::value_type() );

  set(val);
}

Value::Value(const char* val)
{
  init( Glib::Value<Glib::ustring>::value_type() );

  set(val);
}

Value::Value(const Time& val)
{
  init( GDA_TYPE_TIME );

  set(val);
}

Value::Value(const Timestamp& val)
{
  init( GDA_TYPE_TIMESTAMP );

  set(val);
}

/*
Value::Value(time_t val)
{
  gobject_ = gda_value_new_timestamp_from_timet(val);
}
*/

//static:
Value Value::create_as_time_t(time_t val)
{
  return Value( gda_value_new_timestamp_from_timet(val) );
}

Value::Value(guint val)
{
  init( Glib::Value<guint>::value_type() );
}

/*
Value::Value(const Glib::ustring& as_string, GType type)
{
  gobject_ = gda_value_new_from_string(as_string.c_str(), (GType)type);
}
*/

bool Value::operator==(const Value& src) const
{
  if( !gobj() && !src.gobj()) //If both are null.
    return true;

  if( !gobj() && src.gobj()) //If one is null.
    return false;

  if( gobj() && !src.gobj()) //If one is null.
    return false;

  if(get_value_type() != src.get_value_type()) //gda_value_compare() can only compare GValues of the same type.
    return false;
    
  gint test = gda_value_compare(const_cast<GValue*>(gobj()), const_cast<GValue*>(src.gobj()));   //returns 0 if both contain
  return test == 0;
}

bool Value::operator!=(const Value& src) const
{
  return !operator==(src);
}


Value::Value()
{
  //Creates a null. TODO: Is this really equivalent to gda_value_new_null()?
}

Value::Value(const Value& src)
{
  init(src.gobj());
}

Value::Value(const GValue* castitem)
{
  init(castitem);
}

Value& Value::operator=(const Value& src)
{
  init(src.gobj()); //TODO: We probably shouldn't allow this to be called twice.

  return *this;
}

Value::~Value()
{
}

GType Value::get_value_type() const
{
  return G_VALUE_TYPE(gobj());
}

bool Value::is_null() const
{
  return gda_value_is_null(const_cast<GValue*>(gobj()));
}

bool Value::is_number() const
{
  return gda_value_is_number(const_cast<GValue*>(gobj()));
}

gint64 Value::get_int64() const
{
  return g_value_get_int64(const_cast<GValue*>(gobj()));
}

void Value::set(gint64 val)
{
  g_value_set_int64(gobj(), val); 
}

guint64 Value::get_uint64() const
{
  return g_value_get_uint64(const_cast<GValue*>(gobj()));
}

void Value::set(guint64 val)
{
  g_value_set_uint64(gobj(), val); 
}

const guchar* Value::get_binary(long& size) const
{
  //Initialize output parameter:
  size = 0;

  const GdaBinary* gdabinary = gda_value_get_binary(const_cast<GValue*>(gobj()));
  if(!gdabinary)
    return 0;

  size = gdabinary->binary_length;
  return gdabinary->data;
}

void Value::set(const guchar* val, long size)
{
  GdaBinary gdabinary;
  gdabinary.data = const_cast<guchar*>(val);
  gdabinary.binary_length = size;
  gda_value_set_binary(gobj(), &gdabinary); 
}

const GdaBlob* Value::get_blob() const
{
  return gda_value_get_blob(const_cast<GValue*>(gobj()));
}

void Value::set(const GdaBlob* val)
{
  gda_value_set_blob(gobj(), val); 
}

bool Value::get_boolean() const
{
  return g_value_get_boolean(const_cast<GValue*>(gobj()));
}

void Value::set(bool val)
{
  g_value_set_boolean(gobj(), static_cast<int>(val)); 
}

Glib::Date Value::get_date() const
{
  Glib::Date result;
  const GDate* gdate = (const GDate*)g_value_get_boxed(gobj());
  if(gdate)
    result = Glib::Date(*gdate);

  return result;
}

void Value::set(const Glib::Date& val)
{
  g_value_set_boxed(gobj(), val.gobj());
}

double Value::get_double() const
{
  return g_value_get_double(const_cast<GValue*>(gobj()));
}

void Value::set(double val)
{
  g_value_set_double(gobj(), val); 
}

GeometricPoint Value::get_geometric_point() const
{
  return *(gda_value_get_geometric_point(const_cast<GValue*>(gobj())));
}

void Value::set(const GeometricPoint& val)
{
  gda_value_set_geometric_point(gobj(), &(val)); 
}

int Value::get_int() const
{
  return g_value_get_int(const_cast<GValue*>(gobj()));
}

void Value::set(int val)
{
  g_value_set_int(gobj(), val); 
}

const GdaValueList* Value::get_list()
{
  return gda_value_get_list(gobj());
}

void Value::set(const GdaValueList * val)
{
  gda_value_set_list(gobj(), val); 
}

const GdaNumeric* Value::get_numeric() const
{
  return gda_value_get_numeric(const_cast<GValue*>(gobj()));
}

void Value::set(const GdaNumeric * val)
{
  gda_value_set_numeric(gobj(), val); 
}

float Value::get_float() const
{
  return g_value_get_float(const_cast<GValue*>(gobj()));
}

void Value::set(float val)
{
  g_value_set_float(gobj(), val); 
}

gshort Value::get_short() const
{
  return gda_value_get_short(const_cast<GValue*>(gobj()));
}

void Value::set(gshort val)
{
  gda_value_set_short(gobj(), val); 
}

gushort Value::get_ushort() const
{
  return gda_value_get_ushort(const_cast<GValue*>(gobj()));
}

void Value::set(gushort val)
{
  gda_value_set_ushort(gobj(), val); 
}

Glib::ustring Value::get_string() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_value_get_string(const_cast<GValue*>(gobj())));
}

void Value::set(const Glib::ustring& val)
{
  g_value_set_string(gobj(), val.c_str()); 
}

Time Value::get_time() const
{
  return *(gda_value_get_time(const_cast<GValue*>(gobj())));
}

void Value::set(const Time& val)
{
  gda_value_set_time(gobj(), &(val)); 
}

Timestamp Value::get_timestamp() const
{
  return *(gda_value_get_timestamp(const_cast<GValue*>(gobj())));
}

void Value::set(const Timestamp& val)
{
  gda_value_set_timestamp(gobj(), &(val)); 
}

guint Value::get_uint() const
{
  return g_value_get_uint(const_cast<GValue*>(gobj()));
}

void Value::set(guint val)
{
  g_value_set_uint(gobj(), val); 
}

GType Value::get_g_type() const
{
  return g_value_get_gtype(gobj());
}

void Value::set(GType val)
{
  g_value_set_gtype(gobj(), val);
}

Glib::ustring Value::to_string() const
{
  return Glib::convert_return_gchar_ptr_to_ustring(gda_value_stringify(const_cast<GValue*>(gobj())));
}











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

  if(G_VALUE_TYPE(value1.gobj()) != G_VALUE_TYPE(value2.gobj())) //gda_value_compare() can only compare GValues of the same type.
    return false;
    
  int test = gda_value_compare(value1.gobj(), value2.gobj());
  return test == 0;
}



//Gda types:




} // namespace Gda

} // namespace Gnome


