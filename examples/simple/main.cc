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


int main (int argc, char** argv)
{
  //Initialize libgdamm:
  Gnome::Gda::init();

  Glib::RefPtr<Gnome::Gda::Client> gda_client = Gnome::Gda::Client::create();

  //Get the list of data sources:
  typedef std::list<Glib::ustring> type_list_of_strings;
  type_list_of_strings data_sources = Gnome::Gda::Config::get_data_sources()

  //Print the information about each data source:
  for(type_list_of_strings::iterator iter = data_sources.begin(); iter != data_sources.end(); ++iter)
  {
    Gnome::Gda::DataSourceInfo info = *iter;

    std::cout << " Data source = %s, User = %s\n" << info.get_name(), info.get_username() << std::endl;

    Glib::RefPtr<Gnome::Gda::Connection> gda_connection = Gnome::Gda::Connection::open( gda_client, client, info.get_name(), nfo.get_username(), nfo.get_password() );
    if(!gda_connection)
      std::cerr << "Error: Could not open connection to " << info.get_user_name();
    else
    {
      // show provider features
      std::cout << "\tProvider capabilities..." << std::endl;
      std::cout << "\t\tAggregates: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_AGGREGATES) ? "Supported" : "Not supported";
      std::cout << "\t\tIndexes: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_INDEXES) ? "Supported" : "Not supported";
      std::cout << "\t\tNamespaces: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_NAMESPACES) ? "Supported" : "Not supported";
      std::cout << "\t\tProcedures: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_PROCEDURES) ? "Supported" : "Not supported";
      std::cout << "\t\tSequences: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_SEQUENCES) ? "Supported" : "Not supported";
      std::cout << "\t\tSQL: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_SQL) ? "Supported" : "Not supported";
      std::cout << "\t\tTransactions: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_TRANSACTIONS) ? "Supported" : "Not supported";
      std::cout << "\t\tTriggers: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_TRIGGERS) ? "Supported" : "Not supported";
      std::cout << "\t\tUsers: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_USERS) ? "Supported" : "Not supported";
      std::cout << "\t\tViews: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_VIEWS) ? "Supported" : "Not supported";
      std::cout << "\t\tXML queries: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_XML_QUERIES) ? "Supported" : "Not supported";
      std::cout << "\t\tBLOBs: %s" << std::endl <<
        gda_connection.supports(GDA_CONNECTION_FEATURE_BLOBS) ? "Supported" : "Not supported";
    }
  }
  

  
  return 0;
}


