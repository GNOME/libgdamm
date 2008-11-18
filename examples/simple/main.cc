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

/*
 * run a non SELECT command and stops if an error occurs
 */
void
run_sql_non_select (const Glib::RefPtr<Gda::Connection>& cnc, const Glib::RefPtr<Gda::SqlParser>& parser, const Glib::ustring sql)
{

  Glib::RefPtr<Gda::Statement> stmt;
  Glib::ustring remain;
  try
  {
    stmt =  parser->parse_string (sql, remain);
  }
  catch(const Glib::Error& err)
  {
    std::cerr << "Error: " << err.what() << std::endl;
    return;
  }

  if(!remain.empty()) 
    std::cout << "REMAINS: "<< remain << std::endl;

  int nrows = 0;
  try
  {  
    nrows = cnc->statement_execute_non_select (stmt);
  }
  catch(const Glib::Error& err)
  {
    std::cerr << "Error: " << err.what() << std::endl;
    return;
  }
}

/*
 * Create a "products" table
 */
void
create_table(const Glib::RefPtr<Gda::Connection>& cnc, const Glib::RefPtr<Gda::SqlParser>& parser)
{
  run_sql_non_select (cnc, parser, "DROP table IF EXISTS products");
  run_sql_non_select (cnc, parser, "CREATE table products (ref string not null primary key, "
                                                           "name string not null, price real)");
  run_sql_non_select (cnc, parser, "INSERT INTO products VALUES ('p1', 'chair', 2.0)");
  run_sql_non_select (cnc, parser, "INSERT INTO products VALUES ('p2', 'table', 5.0)");

  run_sql_non_select (cnc, parser, "INSERT INTO products VALUES ('p3', 'glass', 1.1)");
}

/* 
 * display the contents of the 'products' table 
 */
void
display_products_contents (const Glib::RefPtr<Gda::Connection>& cnc, const Glib::RefPtr<Gda::SqlParser>& parser)
{
  const Glib::ustring sql = "SELECT ref, name, price FROM products";
  Glib::ustring remain;
  Glib::RefPtr<Gda::Statement> stmt;
  try
  {
    stmt =  parser->parse_string (sql, remain);
  }
  catch(const Glib::Error& err)
  {
    std::cerr << "Error: " << err.what() << std::endl;
    return;
  }
  Glib::RefPtr<Gda::DataModel> data_model;
  try
  {
    data_model = cnc->statement_execute_select (stmt);
  }
  catch(const Glib::Error& err)
  { 
    std::cout << "Could not get the contents of the 'products' table: " 
      << err.what() << std::endl;
    return;
  }

  std::cout << data_model->dump_as_string() << std::endl;
}

int main (int argc, char** argv)
{
  Gda::init();
  Glib::RefPtr<Gda::Connection> cnc;
  try
  {
    cnc = Gda::Connection::open_from_string ("SQLite", "DB_DIR=.;DB_NAME=example_db", "",
                                                                           Gda::CONNECTION_OPTIONS_NONE);
  }
  catch(const Glib::Error& err)
  {
    std::cerr << err.what() << std::endl;
    return 1;
  }

  /* create an SQL parser */
  Glib::RefPtr<Gda::SqlParser> parser = cnc->create_parser();
  if(!parser) /* @cnc doe snot provide its own parser => use default one */
    parser = Gda::SqlParser::create();
  
  create_table(cnc, parser);
  display_products_contents(cnc, parser);
  
  return 0;
}
