/* main.cc
 *
 * Copyright (C) 2003 gnome-vfsmm Development Team
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */


#include <libgdamm.h>
#include <iostream>

using namespace Gnome;

int main (int argc, char** argv)
{
  Gda::init();
  
  Glib::RefPtr<Gda::DataModel> model = Gda::Config::list_providers();
  Glib::RefPtr<Gda::DataModelIter> iter = model->create_iter();

  std::cout << "Name\t|\tDescription" << std::endl;
  do
  {    
    Gda::Value name = iter->get_value_at (0);
    Gda::Value desc = iter->get_value_at (1);
    std::cout << name.to_string() << " | " << desc.to_string() << std::endl;
  }
  while (iter->move_next());
  
  return 0;
}
