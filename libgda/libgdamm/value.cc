/* $Id$ */
// -*- C++ -*- //

/* value.cc
 *
 * Copyright 2006 libgdamm Development Team
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

#include <libgdamm/value.h>
#include <glibmm/utility.h>
#include <libgda/gda-value.h>
#include <libgda/gda-enum-types.h>
#include <libgda/gda-util.h>

namespace
{
  // Changes the type of a given value
  void value_reinit(GValue* value, GType g_type)
  {
    if(G_IS_VALUE(value) && G_VALUE_TYPE(value) != g_type)
      g_value_unset(value);

    if(!G_IS_VALUE(value))
      g_value_init(value, g_type);
  }
}

namespace Gnome
{

namespace Gda
{

Value Value::create_as_int64(gint64 val)
{
  Value result;
  result.set_int64(val);
  return result;
}

Value Value::create_as_uint64(guint64 val)
{
  Value result;
  result.set_uint64(val);
  return result;
}

Value::Value(const guchar* val, long size)
{
  set(val, size);
}

Value::Value(const GdaBlob *val)
{
  set(val);
}

Value::Value(bool val)
{
  set(val);
}

Value::Value(const Glib::Date& val)
{
  set(val);
}

#ifndef LIBGDAMM_DISABLE_DEPRECATED
Value::Value(double val)
{
  set(val);
}
#endif //LIBGDAMM_DISABLE_DEPRECATED

Value Value::create_as_double(double val)
{
  Value result;
  result.set_double(val);
  return result;
}

Value::Value(const GeometricPoint& val)
{
  set(val);
}

Value::Value(int val)
{
  set(val);
}

Value::Value(const Numeric& val)
{
  set(val);
}

#ifndef LIBGDAMM_DISABLE_DEPRECATED
Value::Value(float val)
{
  set(val);
}
#endif //LIBGDAMM_DISABLE_DEPRECATED

Value Value::create_as_float(float val)
{
  Value result;
  result.set_float(val);
  return result;
}

Value::Value(gshort val)
{
  set(val);
}

Value::Value(gushort val)
{
  set(val);
}

Value::Value(gulong val)
{
  set(val);
}

Value::Value(const Glib::ustring& val)
{
  set(val);
}

Value::Value(const char* val)
{
  set(val);
}

Value::Value(const Glib::DateTime& val)
{
  set(val);
}

Value::Value(const Timestamp& val)
{
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
  set(val);
}

/*
Value::Value(const Glib::ustring& as_string, GType type)
{
  gobject_ = gda_value_new_from_string(as_string.c_str(), (GType)type);
}
*/

bool Value::operator==(const Value& src) const
{
  if( !G_IS_VALUE(gobj()) && !G_IS_VALUE(src.gobj())) //If both are null.
    return true;

  if( !G_IS_VALUE(gobj()) && G_IS_VALUE(src.gobj())) //If one is null.
    return false;

  if( G_IS_VALUE(gobj()) && !G_IS_VALUE(src.gobj())) //If one is null.
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
:
  Glib::ValueBase()
{
  init(gda_value_new_null());
}

Value::Value(const Value& src)
:
  Glib::ValueBase()
{
  if(G_IS_VALUE(src.gobj()))
    init(src.gobj());
}

Value::Value(const GValue* castitem)
:
  Glib::ValueBase()
{
  if(G_IS_VALUE(castitem))
    init(castitem);
}

Value& Value::operator=(const Value& src)
{
  if(this == &src)
    return *this;

  //Avoid doing anything if no change is necessary:
  if(gobj() == src.gobj())
    return *this;

  // Unset current value, if any
  if(G_IS_VALUE(gobj()))
    g_value_unset(gobj());

  // Set new value, if any
  if(G_IS_VALUE(src.gobj()))
    init(src.gobj());

  return *this;
}

Value::~Value()
{
  // If the value does not have a type, we just set one so that the
  // ValueBase destructor does not complain.
  if(!G_IS_VALUE(gobj()))
    init(G_TYPE_INT);
}

GType Value::get_value_type() const
{
  return G_VALUE_TYPE(gobj());
}

bool Value::is_null() const
{
  return gda_value_is_null(const_cast<GValue*>(gobj()));
}

void Value::set_null()
{
  gda_value_set_null( gobj() );
}

bool Value::is_number() const
{
  return gda_value_is_number(const_cast<GValue*>(gobj()));
}

gint64 Value::get_int64() const
{
  return g_value_get_int64(const_cast<GValue*>(gobj()));
}

void Value::set_int64(gint64 val)
{
  value_reinit(gobj(), G_TYPE_INT64);
  g_value_set_int64(gobj(), val);
}

guint64 Value::get_uint64() const
{
  return g_value_get_uint64(const_cast<GValue*>(gobj()));
}

void Value::set_uint64(guint64 val)
{
  value_reinit(gobj(), G_TYPE_UINT64);
  g_value_set_uint64(gobj(), val);
}

const guchar* Value::get_binary(long& size) const
{
  //Initialize output parameter:
  size = 0;

  const GdaBinary* gdabinary = gda_value_get_binary(const_cast<GValue*>(gobj()));
  if(!gdabinary)
    return 0;

  size = gda_binary_get_size(const_cast<GdaBinary*>(gdabinary));
  //TODO: gda_binary_get_data() returns gpointer. Should we too?
  return (guchar*)gda_binary_get_data(const_cast<GdaBinary*>(gdabinary));
}

void Value::set(const guchar* val, long size)
{
  value_reinit(gobj(), GDA_TYPE_BINARY);

  GdaBinary* gdabinary = gda_binary_new();
  gda_binary_set_data(gdabinary, const_cast<guchar*>(val), size);
  gda_value_take_binary(gobj(), gdabinary);
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
  value_reinit(gobj(), Glib::Value<bool>::value_type());
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
  //There is no Glib::Value<> specialization, so we explicitly mention G_TYPE_DATE: value_reinit(gobj(), Glib::Value<Glib::Date>::value_type());
  value_reinit(gobj(), G_TYPE_DATE);
  g_value_set_boxed(gobj(), val.gobj());
}

double Value::get_double() const
{
  return g_value_get_double(const_cast<GValue*>(gobj()));
}

#ifndef LIBGDAMM_DISABLE_DEPRECATED
void Value::set(double val)
{
  set_double(val);
}
#endif //LIBGDAMM_DISABLE_DEPRECATED

void Value::set_double(double val)
{
  value_reinit(gobj(), Glib::Value<double>::value_type());
  g_value_set_double(gobj(), val);
}

GeometricPoint Value::get_geometric_point() const
{
  const GdaGeometricPoint* cobj = gda_value_get_geometric_point(const_cast<GValue*>(gobj()));
  return Glib::wrap(const_cast<GdaGeometricPoint*>(cobj), true /* take_copy */);
}

void Value::set(const GeometricPoint& val)
{
  gda_value_set_geometric_point(gobj(), val.gobj());
}

int Value::get_int() const
{
  return g_value_get_int(const_cast<GValue*>(gobj()));
}

void Value::set(int val)
{
  value_reinit(gobj(), Glib::Value<int>::value_type());
  g_value_set_int(gobj(), val);
}

Numeric Value::get_numeric() const
{
  const GdaNumeric* cobj = gda_value_get_numeric(const_cast<GValue*>(gobj()));
  return Glib::wrap(const_cast<GdaNumeric*>(cobj), true /* take_copy */);
}

void Value::set(const Numeric& val)
{
  gda_value_set_numeric(gobj(), val.gobj());
}

float Value::get_float() const
{
  return g_value_get_float(const_cast<GValue*>(gobj()));
}

#ifndef LIBGDAMM_DISABLE_DEPRECATED
void Value::set(float val)
{
  set_float(val);
}
#endif //LIBGDAMM_DISABLE_DEPRECATED

void Value::set_float(float val)
{
  value_reinit(gobj(), Glib::Value<float>::value_type());
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

glong Value::get_long() const
{
  return g_value_get_long(const_cast<GValue*>(gobj()));
}

void Value::set(glong val)
{
  g_value_set_long(gobj(), val);
}

gulong Value::get_ulong() const
{
  return g_value_get_ulong(const_cast<GValue*>(gobj()));
}

void Value::set(gulong val)
{
  g_value_set_ulong(gobj(), val);
}

Glib::ustring Value::get_string() const
{
  return Glib::convert_const_gchar_ptr_to_ustring(g_value_get_string(const_cast<GValue*>(gobj())));
}

void Value::set(const Glib::ustring& val)
{
  value_reinit(gobj(), G_TYPE_STRING);
  g_value_set_string(gobj(), val.c_str());
}

void Value::set(const char* val)
{
  value_reinit(gobj(), G_TYPE_STRING);
  g_value_set_string(gobj(), val);
}

Glib::DateTime Value::get_time() const
{
  const GdaTime* cobj = gda_value_get_time(const_cast<GValue*>(gobj()));
  return Glib::wrap(const_cast<GdaTime*>(cobj), true /* take_copy */);
}

void Value::set(const Time& val)
{
  gda_value_set_time(gobj(), val.gobj());
}

Timestamp Value::get_timestamp() const
{
  const GdaTimestamp* cobj = gda_value_get_timestamp(const_cast<GValue*>(gobj()));
  return Glib::wrap(const_cast<GdaTimestamp*>(cobj), true /* take_copy */);
}

void Value::set(const Timestamp& val)
{
  gda_value_set_timestamp(gobj(), val.gobj());
}

guint Value::get_uint() const
{
  return g_value_get_uint(const_cast<GValue*>(gobj()));
}

void Value::set(guint val)
{
  value_reinit(gobj(), Glib::Value<unsigned int>::value_type());
  g_value_set_uint(gobj(), val);
}

GType Value::get_g_type() const
{
  return g_value_get_gtype(gobj());
}

void Value::set_g_type(GType val)
{
  value_reinit(gobj(), G_TYPE_GTYPE);
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


#if 0
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
#endif



//Gda types:




} // namespace Gda

} // namespace Gnome
