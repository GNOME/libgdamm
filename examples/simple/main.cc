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
    //Get a stored data source:
    const Glib::ustring data_source_name = "datasource_libgdamm_example_simple";
    Gnome::Gda::DataSourceInfo data_source = Gnome::Gda::Config::find_data_source(data_source_name);
    if(!data_source)
    {
      std::cout << "Creating the DataSource, because it does not exist yet." << std::endl;
      //Create it if it does not exist already:
      data_source = Gnome::Gda::DataSourceInfo();
      data_source.set_name(data_source_name);
      data_source.set_username("murrayc");
      data_source.set_password("murraycpw");      
      data_source.set_description("Data Source for libgdamm simple example.");
      data_source.set_provider("PostgreSQL");
      
      Gnome::Gda::Config::save_data_source(data_source);
    }

    std::cout << " Data source = " << data_source.get_name() << ", User = " << data_source.get_username() << std::endl;

    Glib::RefPtr<Gnome::Gda::Connection> gda_connection = gda_client->open_connection(data_source.get_name(), data_source.get_username(), data_source.get_password() );
    
    if(!gda_connection)
      std::cerr << "Error: Could not open connection to " << data_source.get_name();
    else
    {
      //Open database:
      gda_connection->change_database("tblTest1");

      

      /*
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
      */
    }
  } 

  
  return 0;
}


