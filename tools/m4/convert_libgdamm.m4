_EQUAL(glong,long)

_CONVERSION(`GdaConnectionEvent*',`Glib::RefPtr<ConnectionEvent>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<ConnectionEvent>&', `GdaConnectionEvent*', `Glib::unwrap($3)')
_CONVERSION(`GdaDataModel*',`Glib::RefPtr<DataModel>',`Glib::wrap($3)')
_CONVERSION(`GdaDataModel*',`Glib::RefPtr<const DataModel>',`Glib::wrap($3)')
_CONVERSION(`GdaConnection*',`Glib::RefPtr<Connection>',`Glib::wrap($3)')
_CONVERSION(`GdaTransaction*',`Glib::RefPtr<Transaction>',`Glib::wrap($3)')
_CONVERSION(`GdaTransaction*',`Glib::RefPtr<const Transaction>',`Glib::wrap($3)')
_CONVERSION(`GdaClient*',`Glib::RefPtr<Client>',`Glib::wrap($3)')
_CONVERSION(`GdaClient*',`Glib::RefPtr<const Client>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<DataModel>&', `GdaDataModel*', `Glib::unwrap($3)')
_CONVERSION(`const Glib::RefPtr<ServerProvider>&', `GdaServerProvider*', `Glib::unwrap($3)')
_CONVERSION(`const Glib::RefPtr<Transaction>&', `GdaTransaction*', `Glib::unwrap($3)')
_CONVERSION(`const Glib::RefPtr<Connection>&', `GdaConnection*', `Glib::unwrap($3)')

# The const_cast here is silly and should not be necessary - we should fix the wrap() methods some time:
_CONVERSION(`const Command&', `GdaCommand*', `const_cast<GdaCommand*>(($3).gobj())')

_CONVERSION(`const Row&', `const GdaRow*', `($3).gobj()')
_CONVERSION(`Row&', `GdaRow*', `($3).gobj()')

_CONVERSION(`const Value&', `GdaValue*', `const_cast<GdaValue*>(($3).gobj())')
_CONVERSION(`const Value&', `const GdaValue*', `($3).gobj()')

_CONVERSION(`GdaParameter*',`Parameter',`Glib::wrap($3)')
_CONVERSION(`const Parameter&', `GdaParameter*', `const_cast<GdaParameter*>(($3).gobj())')

_CONVERSION(`const ParameterList&', `GdaParameterList*', `const_cast<GdaParameterList*>(($3).gobj())')

_CONVERSION(`GdaColumn*',`Column',`Glib::wrap($3)')
_CONVERSION(`const Column&', `GdaColumn*', `const_cast<GdaColumn*>(($3).gobj())')
_CONVERSION(`const Column&', `const GdaColumn*', `($3).gobj()')
_CONVERSION(`Column&', `GdaColumn*', `($3).gobj()')

_CONVERSION(`GdaColumnIndex*',`Glib::RefPtr<ColumnIndex>',`Glib::wrap($3)')

_CONVERSION(`const DataModelIndex&', `const GdaDataModelIndex*', `($3).gobj()')

_CONVERSION(`const GObject*',`Glib::RefPtr<const Glib::Object>',`Glib::wrap(const_cast<GObject*>($3))')
_CONVERSION(`const Glib::RefPtr<Glib::Object>&', `const GObject*', `($3)->gobj()')


_CONVERSION(`const Glib::RefPtr<Client>&', `GdaClient*', `Glib::unwrap($3)')


_CONVERSION(`const Date&', `const GdaDate*', `&($3)')
_CONVERSION(`const GdaDate*', `Date', `*($3)')

_CONVERSION(`const Time&', `const GdaTime*', `&($3)')
_CONVERSION(`const GdaTime*', `Time', `*($3)')

_CONVERSION(`const Timestamp&', `const GdaTimestamp*', `&($3)')
_CONVERSION(`const GdaTimestamp*', `Timestamp', `*($3)')

_CONVERSION(`const GeometricPoint&', `const GdaGeometricPoint*', `&($3)')
_CONVERSION(`const GdaGeometricPoint*', `GeometricPoint', `*($3)')

_CONVERSION(`const GdaBinary&', `const GdaBinary*', `&($3)')

_CONVERSION(`const int*','const-gint*',`$3')

_CONVERSION(`long&',`glong*',`&($3)')

_CONV_ENUM(Gda,CommandType)
_CONV_ENUM(Gda,CommandOptions)
_CONV_ENUM(Gda,ConnectionFeature)
_CONV_ENUM(Gda,ConnectionSchema)
_CONV_ENUM(Gda,ClientEvent)
_CONV_ENUM(Gda,ClientSpecsType)
_CONV_ENUM(Gda,ConnectionOptions)
_CONV_ENUM(Gda,ValueType)
_CONV_ENUM(Gda,TransactionIsolation)
_CONV_ENUM(Gda,Sorting)

# For signals:
_CONVERSION(`GdaConnection*',`const Glib::RefPtr<Connection>&',`Glib::wrap($3)')
_CONVERSION(`GdaParameterList*',`const ParameterList&',`Glib::wrap($3)')
