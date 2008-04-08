/* main.cc
 *
 * Copyright (C) 2008 libgdamm Development Team
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


int main (int argc, char** argv)
{
  //Initialize libgdamm:
  Gnome::Gda::init("libgdamm example", "0.1", argc, argv);

#ifndef GLIBMM_EXCEPTIONS_ENABLED
  std::auto_ptr<Glib::Error> error;
#endif // !GLIBMM_EXCEPTIONS_ENABLED

  Glib::RefPtr<Gnome::Gda::Client> gda_client = Gnome::Gda::Client::create();
  if(gda_client)
  {
    const gchar* connection_provider = "PostgreSQL";

    const gchar* connection_host = "localhost";
    const gchar* connection_table = "glom_musiccollection217";
    const Glib::ustring connection_string = Glib::ustring("PORT=5433;HOST=") + connection_host + ";DB_NAME=" + connection_table;

    const gchar* connection_username = "murrayc";
    const gchar* connection_password = "murraycpw"; 
     
    Glib::RefPtr<Gnome::Gda::Connection> gda_connection;
#ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
      gda_connection= gda_client->open_connection_from_string(connection_provider, connection_string, connection_username, connection_password);
    }
    catch(const Glib::Exception& ex)
    {
      std::cerr << "Exception caught: " << ex.what() << std::endl;
    }
#else
    gda_connection = gda_client->open_connection_from_string(connection_provider, connection_string, connection_username, connection_password, Gnome::Gda::ConnectionOptions(0), error);
    if(error.get())
    {
      std::cerr << "Exception caught: " << error->what() << std::endl;
    }
#endif // GLIBMM_EXCEPTIONS_ENABLED
    
    if(!gda_connection)
      std::cerr << "Error: Could not open connection to " << connection_string << std::endl;
    else
    {
#ifdef GLIBMM_EXCEPTIONS_ENABLED
      try
      {
        gda_connection->execute_non_select_command("SET DATESTYLE = 'ISO'");
      }
      catch(const Glib::Exception& ex)
      {
       std::cerr << "Exception caught: " << ex.what() << std::endl;
      }
#else
      gda_connection->execute_non_select_command("SET DATESTYLE = 'ISO'", error);
      if(error.get())
      {
        std::cerr << "Exception caught: " << error->what() << std::endl;
      }
#endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  } 

  
  return 0;
}


