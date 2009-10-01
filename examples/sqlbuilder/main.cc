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
  ins_builder->add_field(ins_builder->add_id("e"),
                         ins_builder->add_param("p1", G_TYPE_STRING, false));
  ins_builder->add_field(ins_builder->add_id("f"),
                         ins_builder->add_expr(Gnome::Gda::Value(15)));
  ins_builder->add_field(ins_builder->add_id("g"),
                         ins_builder->add_expr(Gnome::Gda::Value("joe")));
  
  render_as_sql (ins_builder);

  // UPDATE products set ref='A0E''FESP' WHERE id = 14
  Glib::RefPtr<Gnome::Gda::SqlBuilder> up_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SQL_STATEMENT_UPDATE);
  
  up_builder->set_table("customer");
  up_builder->add_field(up_builder->add_id("ref"),
                        up_builder->add_expr(Gnome::Gda::Value("A0E'FESP")));
  guint id = up_builder->add_id("id");
  guint value = up_builder->add_expr(Gnome::Gda::Value(14));
  guint cond = up_builder->add_cond(Gnome::Gda::SQL_OPERATOR_TYPE_EQ, id, value);
  up_builder->set_where(cond);

  render_as_sql (up_builder);
  
  // reuse the same GdaSqlBuilder object to change the WHERE condition to: WHERE id = ##theid::int
  up_builder->set_where(up_builder->add_cond(Gnome::Gda::SQL_OPERATOR_TYPE_EQ,
                                         id,
                                         up_builder->add_param ("theid", G_TYPE_INT, false),
                                         0));
  render_as_sql (up_builder);

  /*
	 * The next statement shows automatic quoting of reserved SQL keywords (DATE and SELECT here)
	 *
	 * SELECT c."date", name, date AS person FROM "select" as c, orders
	 */
  Glib::RefPtr<Gnome::Gda::SqlBuilder> sel_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SQL_STATEMENT_SELECT);

  id = sel_builder->add_id("select"); // SELECT is an sql keyword
  guint target_c = sel_builder->select_add_target(id, "c");
  guint target_orders = sel_builder->select_add_target(sel_builder->add_id("orders"));
  guint join = sel_builder->select_join_targets(target_c, target_orders, Gnome::Gda::SQL_SELECT_JOIN_INNER);
  sel_builder->add_field(sel_builder->add_id("c.date"));
  sel_builder->add_field(sel_builder->add_id("name"),
                         sel_builder->add_id("person"));
  render_as_sql(sel_builder);

  // reuse the same GdaSqlBuilder object to change the INNER join's condition
  sel_builder->join_add_field (join, "id");
  render_as_sql(sel_builder);

  // SELECT myfunc (a, 5, 'Joe') FROM mytable
  Glib::RefPtr<Gnome::Gda::SqlBuilder> func_builder = 
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SQL_STATEMENT_SELECT);
  
  func_builder->select_add_target(func_builder->add_id("mytable"));

  std::vector<guint> args;
  args.push_back(func_builder->add_id("a"));
  args.push_back(func_builder->add_expr(Gnome::Gda::Value(5)));
  args.push_back(func_builder->add_expr(Gnome::Gda::Value("Joe")));
  guint func = func_builder->add_function("myfunc",
                                          args);
	func_builder->add_field (func);
	render_as_sql (func_builder);
  
  /* reuse the same GdaSqlBuilder object to have:
   * SELECT myfunc (a, 5, 'Joe'), MAX (myfunc (a, 5, 'Joe'), b, 10) FROM mytable */
	guint id_b = func_builder->add_id("b");
	guint expr_ten = func_builder->add_expr (Gnome::Gda::Value(10));
  std::vector<guint> args2;
  args2.push_back(func);
  args2.push_back(id_b);
  args2.push_back(expr_ten);

	guint func_max = func_builder->add_function ("MAX", args2);
	func_builder->add_field (func_max);

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