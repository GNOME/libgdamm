_CONVERSION(`GdaError*',`Glib::RefPtr<Error>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<Error>&', `GdaError*', `Glib::unwrap($3)')
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

_CONVERSION(`const GdaRow*',`Row',`Glib::wrap(const_cast<GdaRow*>($3), true)')
_CONVERSION(`const Row&', `const GdaRow*', `($3).gobj()')


_CONVERSION(`GdaValue*',`Value',`Glib::wrap($3)')
_CONVERSION(`const GdaValue*',`Value',`Glib::wrap(const_cast<GdaValue*>($3))')
_CONVERSION(`const Value&', `GdaValue*', `const_cast<GdaValue*>(($3).gobj())')

_CONVERSION(`GdaParameter*',`Parameter',`Glib::wrap($3)')
_CONVERSION(`const Parameter&', `GdaParameter*', `const_cast<GdaParameter*>(($3).gobj())')

_CONVERSION(`const ParameterList&', `GdaParameterList*', `const_cast<GdaParameterList*>(($3).gobj())')

_CONV_ENUM(Gda,CommandType)
_CONV_ENUM(Gda,CommandOptions)
_CONV_ENUM(Gda,ConnectionFeature)
_CONV_ENUM(Gda,ConnectionSchema)
_CONV_ENUM(Gda,ClientEvent)
_CONV_ENUM(Gda,ConnectionOptions)