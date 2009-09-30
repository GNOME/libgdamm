#include <libgdamm.h>
#include <iostream>
#include <vector>

void render_as_sql (const Glib::RefPtr<Gnome::Gda::SqlBuilder>& builder);

int main()
{
  Gnome::Gda::init();

  // INSERT INTO customers (e, f, g) VALUES (##p1::string, 15, 'joe')
  Glib::RefPtr<Gnome::Gda::SqlBuilder> ins_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SQL_STATEMENT_INSERT);

  ins_builder->set_table("customer");
  ins_builder->add_field(ins_builder->ident(0, "e"),
                         ins_builder->param(0, "p1", G_TYPE_STRING, false));
  ins_builder->add_field(ins_builder->ident(0, "f"),
                         ins_builder->expr(0, Gnome::Gda::Value(15)));
  ins_builder->add_field(ins_builder->ident(0, "g"),
                         ins_builder->expr(0, Gnome::Gda::Value("joe")));
  
  render_as_sql (ins_builder);

  // UPDATE products set ref='A0E''FESP' WHERE id = 14
  Glib::RefPtr<Gnome::Gda::SqlBuilder> up_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SQL_STATEMENT_UPDATE);
  
  up_builder->set_table("customer");
  up_builder->add_field(up_builder->ident(0, "ref"),
                        up_builder->expr(0, Gnome::Gda::Value("A0E'FESP")));
  up_builder->ident(1, "id");
  up_builder->expr(2, Gnome::Gda::Value(14));
  up_builder->cond(3, Gnome::Gda::SQL_OPERATOR_TYPE_EQ, 1, 2, 0);
  up_builder->set_where(3);

  render_as_sql (up_builder);
  
  // reuse the same GdaSqlBuilder object to change the WHERE condition to: WHERE id = ##theid::int
  up_builder->set_where(up_builder->cond(0, Gnome::Gda::SQL_OPERATOR_TYPE_EQ,
                                         1,
                                         up_builder->param (0, "theid", G_TYPE_INT, false),
                                         0));
  render_as_sql (up_builder);

  /*
	 * The next statement shows automatic quoting of reserved SQL keywords (DATE and SELECT here)
	 *
	 * SELECT c."date", name, date AS person FROM "select" as c, orders
	 */
  Glib::RefPtr<Gnome::Gda::SqlBuilder> sel_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SQL_STATEMENT_SELECT);

  sel_builder->ident(1, "select"); // SELECT is an sql keyword
  sel_builder->select_add_target(1, 1, "c");
  sel_builder->select_add_target(2,
                                 sel_builder->ident(0, "orders"));
  sel_builder->select_join_targets(5, 1, 2, Gnome::Gda::SQL_SELECT_JOIN_INNER, 0);
  sel_builder->add_field(sel_builder->ident(0, "c.date"), 0);
  sel_builder->add_field(sel_builder->ident(0, "name"),
                          sel_builder->ident(0, "person"));
  render_as_sql(sel_builder);

  // reuse the same GdaSqlBuilder object to change the INNER join's condition
  sel_builder->join_add_field (5, "id");
  render_as_sql(sel_builder);

  // SELECT myfunc (a, 5, 'Joe') FROM mytable
  Glib::RefPtr<Gnome::Gda::SqlBuilder> func_builder = 
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SQL_STATEMENT_SELECT);
  
  func_builder->select_add_target(0, func_builder->ident(0, "mytable"));

  std::vector<guint> args;
  args.push_back(func_builder->ident(0, "a"));
  args.push_back(func_builder->expr(0, Gnome::Gda::Value(5)));
  args.push_back(func_builder->expr(0, Gnome::Gda::Value("Joe")));
  func_builder->add_function(1, "myfunc",
                             args);
	func_builder->add_field (1, 0);
	render_as_sql (func_builder);
  
  /* reuse the same GdaSqlBuilder object to have:
   * SELECT myfunc (a, 5, 'Joe'), MAX (myfunc (a, 5, 'Joe'), b, 10) FROM mytable */
  std::vector<guint> args2;
  args2.push_back(1);
  args2.push_back(3);
  args2.push_back(4);
	func_builder->ident(3, "b");
	func_builder->expr (4, Gnome::Gda::Value(10));

	func_builder->add_function (5, "MAX", args2);
	func_builder->add_field (5, 0);

	render_as_sql (func_builder);
  
  return 0;
}

void render_as_sql (const Glib::RefPtr<Gnome::Gda::SqlBuilder>& builder)
{
  Glib::RefPtr<Gnome::Gda::Statement> stmt;
  try
  {
    stmt = builder->get_statement();
  }
  catch(Gnome::Gda::SqlBuilderError& error)
  {
    std::cerr << "SqlBuilderError: " << error.what() << std::endl;
    return;
  }
  Glib::ustring sql;
  try
  {
    sql = stmt->to_sql();
  }
  catch(Gnome::Gda::StatementError& error)
  {
    std::cerr << "StatementError: " << error.what() << std::endl;
    return;
  }
  std::cout << "SQL: " << sql << std::endl;
}