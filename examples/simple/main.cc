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
  Gnome::Gda::init("libgdamm example", "0.1", argc, argv);

  Glib::RefPtr<Gnome::Gda::Client> gda_client = Gnome::Gda::Client::create();
  if(gda_client)
  {
    //Get the list of data sources:
    typedef std::list<Gnome::Gda::DataSourceInfo> type_list_of_data_sources;
    type_list_of_data_sources data_sources = Gnome::Gda::Config::get_data_sources();

    //Print the information about each data source:
    for(type_list_of_data_sources::iterator iter = data_sources.begin(); iter != data_sources.end(); ++iter)
    {
      Gnome::Gda::DataSourceInfo info = *iter;

      std::cout << " Data source = " << info.get_name() << ", User = " << info.get_username() << std::endl;

      Glib::RefPtr<Gnome::Gda::Connection> gda_connection = gda_client->open_connection(info.get_name(), info.get_username(), info.get_password() );
      if(!gda_connection)
        std::cerr << "Error: Could not open connection to " << info.get_name();
      else
      {
        // show provider features
        std::cout << "\tProvider capabilities..." << std::endl;
        std::cout << "\t\tAggregates: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_AGGREGATES) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tIndexes: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_INDEXES) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tNamespaces: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_NAMESPACES) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tProcedures: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_PROCEDURES) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tSequences: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_SEQUENCES) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tSQL: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_SQL) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tTransactions: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_TRANSACTIONS) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tTriggers: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_TRIGGERS) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tUsers: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_USERS) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tViews: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_VIEWS) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tXML queries: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_XML_QUERIES) ? "Supported" : "Not supported") << std::endl;
        std::cout << "\t\tBLOBs: " << 
          (gda_connection->supports(Gnome::Gda::CONNECTION_FEATURE_BLOBS) ? "Supported" : "Not supported") << std::endl;
      }
    }
  }  

  
  return 0;
}


