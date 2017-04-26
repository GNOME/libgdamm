#include <libgdamm.h>
#include <iostream>
#include <vector>

void render_as_sql(const Glib::RefPtr<Gnome::Gda::SqlBuilder>& builder);

int main()
{
  Gnome::Gda::init();

  // INSERT INTO customers (e, f, g) VALUES (##p1::string, 15, 'joe')
  Glib::RefPtr<Gnome::Gda::SqlBuilder> ins_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SqlStatement::Type::INSERT);

  ins_builder->set_table("customer");
  ins_builder->add_field_value_id(ins_builder->add_id("e"),
                         ins_builder->add_param("p1", G_TYPE_STRING, false));
  ins_builder->add_field_value("f", 15);
  ins_builder->add_field_value("g", "joe");

  render_as_sql(ins_builder);

  // UPDATE products set ref='A0E''FESP' WHERE id = 14
  Glib::RefPtr<Gnome::Gda::SqlBuilder> up_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SqlStatement::Type::UPDATE);

  up_builder->set_table("customer");
  up_builder->add_field_value("ref", "A0E'FESP");
  guint id = up_builder->add_id("id");
  guint value = up_builder->add_expr(Gnome::Gda::Value(14));
  guint cond = up_builder->add_cond(Gnome::Gda::SqlOperatorType::EQ, id, value);
  up_builder->set_where(cond);

  render_as_sql(up_builder);

  // reuse the same GdaSqlBuilder object to change the WHERE condition to: WHERE id = ##theid::int
  up_builder->set_where(up_builder->add_cond(Gnome::Gda::SqlOperatorType::EQ,
                                         id,
                                         up_builder->add_param ("theid", G_TYPE_INT, false),
                                         0));
  render_as_sql(up_builder);

  /*
   * The next statement shows automatic quoting of reserved SQL keywords (DATE and SELECT here)
   *
   * SELECT c."date", name, date AS person FROM "select" as c, orders
   */
  Glib::RefPtr<Gnome::Gda::SqlBuilder> sel_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SqlStatement::Type::SELECT);

  // SELECT is an sql keyword
  guint target_c = sel_builder->select_add_target("select", "c");
  guint target_orders = sel_builder->select_add_target("orders");
  guint join = sel_builder->select_join_targets(target_c, target_orders, Gnome::Gda::SqlSelectJoinType::INNER);
  sel_builder->select_add_target("c.date"); //Not sure about this. It was add add_field().
  sel_builder->add_field_value_id(sel_builder->add_id("name"),
                         sel_builder->add_id("person"));
  render_as_sql(sel_builder);

  // reuse the same GdaSqlBuilder object to change the INNER join's condition
  sel_builder->join_add_field(join, "id");
  render_as_sql(sel_builder);

  // SELECT myfunc (a, 5, 'Joe') FROM mytable
  Glib::RefPtr<Gnome::Gda::SqlBuilder> func_builder =
    Gnome::Gda::SqlBuilder::create(Gnome::Gda::SqlStatement::Type::SELECT);

  func_builder->select_add_target("mytable");

  std::vector<guint> args;
  args.push_back(func_builder->add_id("a"));
  args.push_back(func_builder->add_expr(Gnome::Gda::Value(5)));
  args.push_back(func_builder->add_expr(Gnome::Gda::Value("Joe")));
  guint func = func_builder->add_function("myfunc", args);
  func_builder->add_field_value_id(func);
  render_as_sql(func_builder);

  /* reuse the same GdaSqlBuilder object to have:
   * SELECT myfunc (a, 5, 'Joe'), MAX (myfunc (a, 5, 'Joe'), b, 10) FROM mytable */
  guint id_b = func_builder->add_id("b");
  guint expr_ten = func_builder->add_expr(Gnome::Gda::Value(10));
  std::vector<guint> args2;
  args2.push_back(func);
  args2.push_back(id_b);
  args2.push_back(expr_ten);

  guint func_max = func_builder->add_function("MAX", args2);
  func_builder->add_field_value_id(func_max);

  render_as_sql(func_builder);

  return 0;
}

void render_as_sql(const Glib::RefPtr<Gnome::Gda::SqlBuilder>& builder)
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
