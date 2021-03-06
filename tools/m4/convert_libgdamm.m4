# _CONV_GNOME_GDA_ENUM(enum_name[, C_enum_name])
# Specify C_enum_name, if it's not the concatenation of GDBus+enum_name.
define(`_CONV_GNOME_GDA_ENUM',`dnl
_CONV_ENUM(`Gnome::Gda',`$1',`m4_ifelse(`$2',,`Gda$1',`$2')')
')dnl

# _CONV_GNOME_GDA_INCLASS_ENUM(class_name, enum_name[, C_enum_name])
# Specify C_enum_name, if it's not the concatenation of GDBus+class_name+enum_name.
define(`_CONV_GNOME_GDA_INCLASS_ENUM',`dnl
_CONV_INCLASS_ENUM(`Gnome::Gda',`$1',`$2',`m4_ifelse(`$3',,`Gda$1$2',`$3')')
')dnl

_EQUAL(glong,long)
_EQUAL(GdaMetaContext*, MetaContext*)
_EQUAL(GdaMetaDbObject*, MetaDbObject*)
_EQUAL(GdaMetaTable*, MetaTable*)
_EQUAL(GdaMetaTableColumn*, MetaTableColumn*)
_EQUAL(GdaServerOperationNode*, ServerOperationNode*)
_EQUAL(GdaSetGroup*, SetGroup*)
_EQUAL(GdaSetSource*, SetSource*)
_EQUAL(GdaSetNode*, SetNode*)
_EQUAL(GdaThreaderFunc, ThreaderFunc)
_EQUAL(GdaDiff*, Diff*)
_EQUAL(const GdaDiff*, const Diff*)

_CONVERSION(`bool&',`gboolean*',`(gboolean*)(&($3))')

_CONVERSION(`GdaConnectionEvent*',`Glib::RefPtr<ConnectionEvent>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<ConnectionEvent>&', `GdaConnectionEvent*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`GdaDataModel*',`Glib::RefPtr<DataModel>',`Glib::wrap($3)')
_CONVERSION(`GdaDataModel*',`Glib::RefPtr<const DataModel>',`Glib::wrap($3)')
_CONVERSION(`GdaDataModelIter*',`Glib::RefPtr<DataModelIter>',`Glib::wrap($3)')
_CONVERSION(`GdaDataModelArray*',`Glib::RefPtr<DataModelArray>',`Glib::wrap($3)')

_CONVERSION(`GdaConnection*',`Glib::RefPtr<Connection>',`Glib::wrap($3)')
_CONVERSION(`GdaStatement*',`Glib::RefPtr<Statement>',`Glib::wrap($3)')
_CONVERSION(`GdaTransactionStatus*',`Glib::RefPtr<TransactionStatus>',`Glib::wrap($3)')
_CONVERSION(`GdaTransactionStatus*',`Glib::RefPtr<const TransactionStatus>',`Glib::wrap($3)')

_CONVERSION(`GdaSet*',`Glib::RefPtr<Set>',`Glib::wrap($3)')
_CONVERSION(`GdaSet*',`Glib::RefPtr<const Set>',`Glib::wrap($3)')
_CONVERSION(`GdaHolder*',`Glib::RefPtr<Holder>',`Glib::wrap($3)')
_CONVERSION(`GdaHolder*',`Glib::RefPtr<const Holder>',`Glib::wrap($3)')
_CONVERSION(`GdaServerProvider*',`Glib::RefPtr<ServerProvider>',`Glib::wrap($3)')
_CONVERSION(`GdaServerProvider*',`Glib::RefPtr<const ServerProvider>',`Glib::wrap($3)')
_CONVERSION(`GdaServerOperation*',`Glib::RefPtr<ServerOperation>',`Glib::wrap($3)')
_CONVERSION(`GdaServerOperation*',`Glib::RefPtr<const ServerOperation>',`Glib::wrap($3)')
_CONVERSION(`GdaDataHandler*',`Glib::RefPtr<DataHandler>',`Glib::wrap($3)')
_CONVERSION(`GdaSqlParser*',`Glib::RefPtr<SqlParser>',`Glib::wrap($3)')
_CONVERSION(`GdaSqlParser*',`Glib::RefPtr<const SqlParser>',`Glib::wrap($3)')
_CONVERSION(`GdaBatch*',`Glib::RefPtr<Batch>',`Glib::wrap($3)')
_CONVERSION(`GdaBatch*',`Glib::RefPtr<const Batch>',`Glib::wrap($3)')
_CONVERSION(`GdaMetaStruct*',`Glib::RefPtr<MetaStruct>',`Glib::wrap($3)')
_CONVERSION(`GdaMetaStruct*',`Glib::RefPtr<const MetaStruct>',`Glib::wrap($3)')
_CONVERSION(`GdaMetaStore*',`Glib::RefPtr<MetaStore>',`Glib::wrap($3)')
_CONVERSION(`GdaMetaStore*',`Glib::RefPtr<const MetaStore>',`Glib::wrap($3)')
_CONVERSION(`GdaConfig*',`Glib::RefPtr<Config>',`Glib::wrap($3)')
_CONVERSION(`GdaDsnInfo*',`Glib::RefPtr<DsnInfo>',`Glib::wrap($3)')
_CONVERSION(`GdaDsnInfo*',`Glib::RefPtr<const DsnInfo>',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<BlobOp>&', `GdaBlobOp*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataModel>&', `GdaDataModel*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataHandler>&', `GdaDataHandler*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataModelIter>&', `GdaDataModelIter*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<ServerProvider>&', `GdaServerProvider*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<ServerOperation>&', `GdaServerOperation*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<TransactionStatus>&', `GdaTransactionStatus*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Connection>&', `GdaConnection*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Statement>&', `GdaStatement*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Statement>&', `GdaStatement*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Set>&', `GdaSet*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Holder>&', `GdaHolder*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Set>&', `const GdaSet*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Set>&', `GdaSet*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Batch>&', `GdaBatch*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<MetaStore>&', `GdaMetaStore*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<MetaStruct>&', `GdaMetaStruct*', __CONVERT_CONST_REFPTR_TO_P)

_CONVERSION(`const Glib::RefPtr<const Row>&', `const GdaRow*', `($3)->gobj()')
_CONVERSION(`const Glib::RefPtr<Row>&', `GdaRow*', `const_cast<GdaRow*>(($3)->gobj())')
_CONVERSION(`GdaRow*',`Glib::RefPtr<Row>',`Glib::wrap($3)')
_CONVERSION(`GdaRow*',`Glib::RefPtr<const Row>',`Glib::wrap($3)')


_CONVERSION(`GdaConnection*',`Glib::RefPtr<Connection>',`Glib::wrap($3)')
_CONVERSION(`GdaConnection*',`Glib::RefPtr<const Connection>',`Glib::wrap($3)')

_CONVERSION(`GdaColumn*',`Glib::RefPtr<Column>',`Glib::wrap($3)')
_CONVERSION(`GdaColumn*',`Glib::RefPtr<const Column>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<Column>&', `GdaColumn*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Column>&', `const GdaColumn*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Column>&', `const GdaColumn*', __CONVERT_REFPTR_TO_P)

_CONVERSION(`GdaColumnIndex*',`Glib::RefPtr<ColumnIndex>',`Glib::wrap($3)')

_CONVERSION(`const DataModelIndex&', `const GdaDataModelIndex*', `($3).gobj()')

_CONVERSION(`const GObject*',`Glib::RefPtr<const Glib::Object>',`Glib::wrap(const_cast<GObject*>($3))')
_CONVERSION(`const Glib::RefPtr<Glib::Object>&', `const GObject*', `($3)->gobj()')

_CONVERSION(`GdaRow*', `const Glib::RefPtr<Row>',  `Glib::wrap($3)')
_CONVERSION(`GdaRow*', `const Glib::RefPtr<const Row>',  `Glib::wrap($3)')

_CONVERSION(`const int*',`const-gint*',`$3')

_CONVERSION(`long&',`glong*',`&($3)')

_CONVERSION(`Glib::ustring', `const gchar*', `($3).c_str()')

_CONVERSION(`ServerOperationNodeStatus&',`GdaServerOperationNodeStatus*',`(($2) &($3))')

#_CONVERSION(`GdaServerOperationNodeType' `ServerOperationNodeType',`(($2)($3))')

_CONV_ENUM(Gda,ConnectionFeature)
_CONV_ENUM(Gda,ConnectionSchema)
_CONV_ENUM(Gda,ClientEvent)
_CONV_ENUM(Gda,ClientSpecsType)
_CONV_GNOME_GDA_INCLASS_ENUM(DataModel,AccessFlags)
_CONV_GNOME_GDA_INCLASS_ENUM(DataModel,Hint)
_CONV_GNOME_GDA_INCLASS_ENUM(DataModel,IOFormat)
_CONV_ENUM(Gda,ConnectionOptions)
_CONV_ENUM(Gda,ValueType)
_CONV_ENUM(Gda,TransactionIsolation)
_CONV_ENUM(Gda,Sorting)
_CONV_GNOME_GDA_INCLASS_ENUM(ConnectionEvent,Code)
_CONV_GNOME_GDA_INCLASS_ENUM(ConnectionEvent,Type)
_CONV_GNOME_GDA_INCLASS_ENUM(Connection,MetaType)
_CONV_GNOME_GDA_INCLASS_ENUM(Connection,Options)
_CONV_GNOME_GDA_INCLASS_ENUM(ServerOperation,Type)
_CONV_GNOME_GDA_INCLASS_ENUM(ServerOperation,NodeType)
_CONV_GNOME_GDA_INCLASS_ENUM(ServerOperation,NodeStatus)
_CONV_ENUM(Gda,ValueAttribute)
_CONV_GNOME_GDA_INCLASS_ENUM(SqlStatement,Type)
_CONV_GNOME_GDA_INCLASS_ENUM(Statement,SqlFlag)
_CONV_GNOME_GDA_INCLASS_ENUM(Statement,ModelUsage)
_CONV_ENUM(Gda,SqlParserMode)
_CONV_GNOME_GDA_INCLASS_ENUM(MetaStruct,Feature)
_CONV_ENUM(Gda,MetaDbObjectType)
_CONV_ENUM(Gda,MetaSortType)
_CONV_ENUM(Gda,MetaGraphInfo)
_CONV_ENUM(Gda,StatementSqlFlag)
_CONV_ENUM(Gda,SqlParserError)
_CONV_ENUM(Gda,SqlOperatorType)
_CONV_ENUM(Gda,SqlSelectJoinType)
_CONV_ENUM(Gda,SqlStatementType)
_CONV_ENUM(Gda,SqlIdentifierStyle)

# structs
_CONVERSION(`Blob&',`GdaBlob*',($3).gobj())
_CONVERSION(`GdaBlob*',`Blob', Glib::wrap($3))
_CONVERSION(`QuarkList&',`GdaQuarkList*',($3).gobj())
_CONVERSION(`GdaQuarkList*',`QuarkList', Glib::wrap($3))

# Value
_CONVERSION(`const Value&', `GValue*', `const_cast<GValue*>(($3).gobj())')
_CONVERSION(`const Value&', `const GValue*', `($3).gobj()')
_CONVERSION(`Value', `GValue*', `($3).gobj()')
_CONVERSION(`Value&', `GValue*', `($3).gobj()')
_CONVERSION(`GValue*', `Value', `$2($3)')
_CONVERSION(`const GValue*', `Value', `$2($3)')


_CONVERSION(`const SqlExpr&', `GdaSqlExpr*', `const_cast<GdaSqlExpr*>(($3).gobj())')
_CONVERSION(`GdaSqlExpr*', `SqlExpr', `Glib::wrap($3)')

_CONVERSION(`const SqlStatement&', `GdaSqlStatement*', `const_cast<GdaSqlStatement*>(($3).gobj())')
