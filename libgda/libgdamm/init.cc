// -*- c++ -*-
/* $Id$ */

/* init.cc
 *
 * Copyright 2001      Free Software Foundation
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

#include <libgdamm/init.h>
#include <gtkmm/wrap_init.h>
#include <gtkmm/main.h>
#include <libgdammconfig.h> //For LIBGDAMM_VERSION
#include <libgdamm/wrap_init.h>
#include <libgda/libgda.h>


namespace Gnome
{

namespace Gda
{

void init(const Glib::ustring& app_id, const Glib::ustring& version, int nargs, gchar *args[])
{
  //TODO: Depend on the stand-alone glibmm, not gtkmm:
  Gtk::Main::init_gtkmm_internals(); //Sets up the g type system and the Glib::wrap() table.
  wrap_init(); //Tells the Glib::wrap() table about the C++ classes.
  gda_init(app_id.c_str(), version.c_str(), nargs, args);
}


} //namespace Gda
} //namespace Gnome
