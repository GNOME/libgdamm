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
      //List the databases:
      Glib::RefPtr<Gnome::Gda::DataModel> data_model_databases = gda_connection->get_schema(Gnome::Gda::CONNECTION_SCHEMA_DATABASES);
      if(data_model_databases && (data_model_databases->get_n_columns() == 0))
      {
        std::cout << " libgda reported 0 databases for the provider." << std::endl;
      }
      else if(data_model_databases)
      {
        //List the tables:
        int rows = data_model_databases->get_n_rows();
        std::cout << "Number of databases: " << rows << std::endl;

        for(int i = 0; i < rows; ++i)
        {
          Gnome::Gda::Value value = data_model_databases->get_value_at(0, i);

          //Get the table name:
          Glib::ustring database_name;
          if(value.get_value_type() ==  Gnome::Gda::VALUE_TYPE_STRING)
            database_name = value.get_string();

          std::cout << "  Database name: " <<  database_name << std::endl;
        }
      }

      std::cout << std::endl;
       
      //Open one of the databases:
      gda_connection->change_database("example_contacts");

      Gnome::Gda::ParameterList parameter_list;
      parameter_list.add_parameter( Gnome::Gda::Parameter("name", "example_contacts") ); 

      Glib::RefPtr<Gnome::Gda::DataModel> data_model_tables = gda_connection->get_schema(Gnome::Gda::CONNECTION_SCHEMA_TABLES, parameter_list);
      if(data_model_tables && (data_model_tables->get_n_columns() == 0)) 
      {
        std::cout << " libgda reported 0 tables for the database." << std::endl;
      }
      else if( data_model_tables) 
      {
        //List the tables:
        int rows = data_model_tables->get_n_rows();
        std::cout << "Number of tables: " << rows << std::endl;

        for(int i = 0; i < rows; ++i)
        {
          Gnome::Gda::Value value = data_model_tables->get_value_at(0, i);
          
          //Get the table name:
          Glib::ustring table_name;
          if(value.get_value_type() ==  Gnome::Gda::VALUE_TYPE_STRING)
            table_name = value.get_string();
          
          std::cout << "  Table name: " <<  table_name << std::endl;
           
/*
          if(!table_name.empty())
          {
             //List the fields:
             Gnome::Gda::Parameter param_table_name("name", table_name);

             Gnome::Gda::ParameterList param_list;
             param_list.add_parameter(param_table_name);

             Glib::RefPtr<Gnome::Gda::DataModel> data_model_fields = gda_connection->get_schema(Gnome::Gda::CONNECTION_SCHEMA_FIELDS, param_list);
             //Alternatively, execute a query and call DataModel::describe_column() for each column.
             
             if(data_model_fields && (data_model_fields->get_n_columns() == 0))
             {
               std::cout << " libgda reported 0 fields for the table." << std::endl;
             }
             else if(data_model_fields)
             {
               int fields_columns =  data_model_fields->get_n_columns();
               std::cout << "    Number of columns for field information: " << fields_columns << std::endl;
               for(int i = 0; i < fields_columns; ++i)
               {
                 std::cout << "      column " << i << ": " <<  data_model_fields->get_column_title(i) << std::endl;;
               }

               int rows = data_model_fields->get_n_rows();
               std::cout << "    Number of fields: " << rows << std::endl;
               
               for(int i = 0; i < rows; ++i)
               {
                 Gnome::Gda::Value value_name = data_model_fields->get_value_at(0, i);

                 //Get the field name:
                 Glib::ustring field_name;
                 if(value_name.get_value_type() ==  Gnome::Gda::VALUE_TYPE_STRING)
                   field_name = value_name.get_string();

                 std::cout << "      Field Name: " << field_name << std::endl;

                 //Get the field type:
                 Gnome::Gda::Value value_fieldtype = data_model_fields->get_value_at(1, i);
                 Glib::ustring field_type;
                 //if(value_fieldtype.get_value_type() ==  Gnome::Gda::VALUE_TYPE_STRING)
                   field_type = value_fieldtype.to_string();

                 std::cout << "      Data Type: " << field_type << std::endl;

                 //Get the default value (though this can have strange values):
                 Gnome::Gda::Value value_default = data_model_fields->get_value_at(8, i);
                 Glib::ustring value_default_string;
                 //if(value_fieldtype.get_value_type() ==  Gnome::Gda::VALUE_TYPE_STRING)
                   value_default_string = value_default.to_string();

                 std::cout << "      Default Value: " << value_default_string << std::endl;

               }
             }   
          }
*/    
        }
      }
    }
  } 

  
  return 0;
}


