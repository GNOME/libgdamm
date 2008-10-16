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
_CONVERSION(`GdaHolder*',`const Glib::RefPtr<Holder>&',`Glib::wrap($3)')
_CONVERSION(`GdaServerProvider*',`Glib::RefPtr<ServerProvider>',`Glib::wrap($3)')
_CONVERSION(`GdaServerOperation*',`Glib::RefPtr<ServerOperation>',`Glib::wrap($3)')
_CONVERSION(`GdaDataHandler*',`Glib::RefPtr<DataHandler>',`Glib::wrap($3)')
_CONVERSION(`GdaSqlParser*',`Glib::RefPtr<SqlParser>',`Glib::wrap($3)')
_CONVERSION(`GdaBatch*',`Glib::RefPtr<Batch>',`Glib::wrap($3)')
_CONVERSION(`GdaMetaStruct*',`Glib::RefPtr<MetaStruct>',`Glib::wrap($3)')
_CONVERSION(`GdaMetaStore*',`Glib::RefPtr<MetaStore>',`Glib::wrap($3)')
_CONVERSION(`GdaConfig*',`Glib::RefPtr<Config>',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<BlobOp>&', `GdaBlobOp*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataModel>&', `GdaDataModel*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataHandler>&', `GdaDataHandler*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataModelIter>&', `GdaDataModelIter*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<ServerProvider>&', `GdaServerProvider*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<ServerOperation>&', `GdaServerOperation*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<TransactionStatus>&', `GdaTransactionStatus*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Connection>&', `GdaConnection*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Statement>&', `GdaStatement*', __CONVERT_REFPTR_TO_P)
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

_CONVERSION(`GdaColumn*',`Glib::RefPtr<Column>',`Glib::wrap($3)')
_CONVERSION(`GdaColumn*',`Glib::RefPtr<const Column>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<Column>&', `GdaColumn*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Column>&', `const GdaColumn*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Column>&', `const GdaColumn*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`Error*', `GdaError*', `($3).gobj()')
_CONVERSION(`GdaError*', `Error*', `Glib::wrap($3)')

_CONVERSION(`GdaColumnIndex*',`Glib::RefPtr<ColumnIndex>',`Glib::wrap($3)')

_CONVERSION(`const DataModelIndex&', `const GdaDataModelIndex*', `($3).gobj()')

_CONVERSION(`const GObject*',`Glib::RefPtr<const Glib::Object>',`Glib::wrap(const_cast<GObject*>($3))')
_CONVERSION(`const Glib::RefPtr<Glib::Object>&', `const GObject*', `($3)->gobj()')

_CONVERSION(`Glib::ValueBase&', `GValue*', `($3).gobj()')
_CONVERSION(`Glib::ValueBase', `GValue*', `($3).gobj()')
_CONVERSION(`const Glib::ValueBase&', `const GValue*', `($3).gobj()')
_CONVERSION(`GValue*', `Glib::ValueBase', `gvalue_to_valuebase($3)')

_CONVERSION(`GdaRow*', `const Glib::RefPtr<Row>',  `Glib::wrap($3)')
_CONVERSION(`GdaRow*', `const Glib::RefPtr<const Row>',  `Glib::wrap($3)')

_CONVERSION(`GdaError*', `Error',  `Glib::wrap($3)')
_CONVERSION(`Error', `GdaError*', `(GdaError*)($3).gobj()')
_CONVERSION(`Error', `GError*', `($3).gobj()')


_CONVERSION(`const int*','const-gint*',`$3')

_CONVERSION(`long&',`glong*',`&($3)')

_CONVERSION(`Glib::ustring', `const gchar*', `($3).c_str()')

_CONVERSION(`ServerOperationNodeStatus&',`GdaServerOperationNodeStatus*',`(($2) &($3))')

#_CONVERSION(`GdaServerOperationNodeType' `ServerOperationNodeType',`(($2)($3))')

_CONV_ENUM(Gda,ConnectionFeature)
_CONV_ENUM(Gda,ConnectionSchema)
_CONV_ENUM(Gda,ConnectionOptions)
_CONV_ENUM(Gda,ClientEvent)
_CONV_ENUM(Gda,ClientSpecsType)
_CONV_ENUM(Gda,DataModelAccessFlags)
_CONV_ENUM(Gda,DataModelHint)
_CONV_ENUM(Gda,DataModelIOFormat)
_CONV_ENUM(Gda,DataModelQueryOptions)
_CONV_ENUM(Gda,ConnectionOptions)
_CONV_ENUM(Gda,ValueType)
_CONV_ENUM(Gda,TransactionIsolation)
_CONV_ENUM(Gda,Sorting)
_CONV_ENUM(Gda,ConnectionEventCode)
_CONV_ENUM(Gda,ConnectionEventType)
_CONV_ENUM(Gda,ConnectionMetaType)
_CONV_ENUM(Gda,ServerOperationType)
_CONV_ENUM(Gda,ServerOperationNodeType)
_CONV_ENUM(Gda,ServerOperationNodeStatus)
_CONV_ENUM(Gda,ValueAttribute)
_CONV_ENUM(Gda,StatementModelUsage)
_CONV_ENUM(Gda,SqlStatementType)
_CONV_ENUM(Gda,StatementSqlFlag)
_CONV_ENUM(Gda,SqlParserMode)
_CONV_ENUM(Gda,MetaStructFeature)
_CONV_ENUM(Gda,MetaDbObjectType)
_CONV_ENUM(Gda,MetaSortType)
_CONV_ENUM(Gda,MetaGraphInfo)
_CONV_ENUM(Gda,StatementSqlFlag)

# structs
_CONVERSION(`Blob&',`GdaBlob*',__FR2P)
_CONVERSION(`GdaBlob*',`Blob', Glib::wrap($3))
_CONVERSION(`QuarkList&',`GdaQuarkList*',__FR2P)
_CONVERSION(`GdaQuarkList*',`QuarkList', Glib::wrap($3))

# Lists
_CONVERSION(`GSList*',`Glib::SListHandle<Glib::ustring>',__FL2H_SHALLOW)
_CONVERSION(`const Glib::ListHandle< Glib::RefPtr<ConnectionEvent> >&',`GList*',`$3.data()')

# Arrays
_CONVERSION(`gchar**',`Glib::StringArrayHandle',`Glib::StringArrayHandle($3)')

# For signals:
_CONVERSION(`GdaConnection*',`const Glib::RefPtr<Connection>&',`Glib::wrap($3)')
