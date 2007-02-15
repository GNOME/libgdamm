_EQUAL(glong,long)

_CONVERSION(`GdaConnectionEvent*',`Glib::RefPtr<ConnectionEvent>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<ConnectionEvent>&', `GdaConnectionEvent*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`GdaDataModel*',`Glib::RefPtr<DataModel>',`Glib::wrap($3)')
_CONVERSION(`GdaDataModel*',`Glib::RefPtr<const DataModel>',`Glib::wrap($3)')
_CONVERSION(`GdaDataModelIter*',`Glib::RefPtr<DataModelIter>',`Glib::wrap($3)')

_CONVERSION(`GdaConnection*',`Glib::RefPtr<Connection>',`Glib::wrap($3)')
_CONVERSION(`GdaTransactionStatus*',`Glib::RefPtr<TransactionStatus>',`Glib::wrap($3)')
_CONVERSION(`GdaTransactionStatus*',`Glib::RefPtr<const TransactionStatus>',`Glib::wrap($3)')
_CONVERSION(`GdaClient*',`Glib::RefPtr<Client>',`Glib::wrap($3)')
_CONVERSION(`GdaClient*',`Glib::RefPtr<const Client>',`Glib::wrap($3)')
_CONVERSION(`GdaDict*',`Glib::RefPtr<Dict>',`Glib::wrap($3)')
_CONVERSION(`GdaDictAggregate*',`Glib::RefPtr<DictAggregate>',`Glib::wrap($3)')
_CONVERSION(`GdaDictDatabase*',`Glib::RefPtr<DictDatabase>',`Glib::wrap($3)')
_CONVERSION(`GdaDictDatabase*',`Glib::RefPtr<const DictDatabase>',`Glib::wrap($3)')
_CONVERSION(`GdaDictTable*',`Glib::RefPtr<DictTable>',`Glib::wrap($3)')
_CONVERSION(`GdaDictTable*',`const Glib::RefPtr<DictTable>&',`Glib::wrap($3)')
_CONVERSION(`GdaDictField*',`Glib::RefPtr<DictField>',`Glib::wrap($3)')
_CONVERSION(`GdaDictField*',`Glib::RefPtr<const DictField>',`Glib::wrap($3)')
_CONVERSION(`GdaDictField*',`const Glib::RefPtr<DictField>&',`Glib::wrap($3)')
_CONVERSION(`GdaDictConstraint*',`Glib::RefPtr<DictConstraint>',`Glib::wrap($3)')
_CONVERSION(`GdaDictConstraint*',`const Glib::RefPtr<DictConstraint>&',`Glib::wrap($3)')
_CONVERSION(`GdaObject*',`Glib::RefPtr<Gda::Object>',`Glib::wrap($3)')
_CONVERSION(`GdaObject*',`Glib::RefPtr<Object>',`Glib::wrap($3)')
_CONVERSION(`GdaObject*',`const Glib::RefPtr<Object>',`Glib::wrap($3)')
_CONVERSION(`GObject*',`Glib::RefPtr<Parameter>',`Glib::wrap($3)')
_CONVERSION(`GdaParameter*',`Glib::RefPtr<Parameter>',`Glib::wrap($3)')
_CONVERSION(`GdaParameter*',`Glib::RefPtr<const Parameter>',`Glib::wrap($3)')
_CONVERSION(`GdaParameterList*',`Glib::RefPtr<ParameterList>',`Glib::wrap($3)')
_CONVERSION(`GdaParameterList*',`const Glib::RefPtr<ParameterList>&',`Glib::wrap($3)')
_CONVERSION(`GdaServerProvider*',`Glib::RefPtr<ServerProvider>',`Glib::wrap($3)')
_CONVERSION(`GdaServerOperation*',`Glib::RefPtr<ServerOperation>',`Glib::wrap($3)')
_CONVERSION(`GdaQuery*',`Glib::RefPtr<Query>',`Glib::wrap($3)')
_CONVERSION(`GdaQuery*',`const Glib::RefPtr<Query>&',`Glib::wrap($3)')
_CONVERSION(`GdaDataHandler*',`Glib::RefPtr<DataHandler>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryField*',`Glib::RefPtr<QueryField>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryField*',`Glib::RefPtr<const QueryField>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryTarget*',`Glib::RefPtr<QueryTarget>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryTarget*',`const Glib::RefPtr<QueryTarget>&',`Glib::wrap($3)')
_CONVERSION(`GdaQueryCondition*',`Glib::RefPtr<QueryCondition>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryCondition*',`Glib::RefPtr<const QueryCondition>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryJoin*',`Glib::RefPtr<QueryJoin>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryJoin*',`Glib::RefPtr<const QueryJoin>',`Glib::wrap($3)')
_CONVERSION(`GdaQueryJoin*',`const Glib::RefPtr<QueryJoin>&',`Glib::wrap($3)')

_CONVERSION(`const Glib::RefPtr<BlobOp>&', `GdaBlobOp*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataModel>&', `GdaDataModel*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DataModelIter>&', `GdaDataModelIter*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<ServerProvider>&', `GdaServerProvider*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<ServerOperation>&', `GdaServerOperation*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<TransactionStatus>&', `GdaTransactionStatus*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Connection>&', `GdaConnection*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Dict>&', `GdaDict*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`Glib::RefPtr<DictType>', `GdaDictType*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DictType>&', `GdaDictType*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DictField>&', `GdaDictField*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const DictField>&', `GdaDictField*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DictTable>&', `GdaDictTable*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DictConstraint>&', `GdaDictConstraint*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const DictConstraint>&', `GdaDictConstraint*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<DictDatabase>&', `GdaDictDatabase*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Object>&', `GdaObject*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Gda::Object>&', `GdaObject*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Parameter>&', `GdaParameter*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`Glib::RefPtr<Parameter>', `GdaParameter*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Parameter>&', `const GdaParameter*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Parameter>&', `GdaParameter*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<ParameterList>&', `GdaParameterList*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const ParameterList>&', `GdaParameterList*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Query>&', `GdaQuery*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<QueryField>&', `GdaQueryField*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const QueryField>&', `GdaQueryField*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<QueryTarget>&', `GdaQueryTarget*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<QueryCondition>&', `GdaQueryCondition*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<QueryJoin>&', `GdaQueryJoin*', __CONVERT_REFPTR_TO_P)


# The const_cast here is silly and should not be necessary - we should fix the wrap() methods some time:
_CONVERSION(`const Command&', `GdaCommand*', `const_cast<GdaCommand*>(($3).gobj())')

_CONVERSION(`const Glib::RefPtr<const Row>&', `const GdaRow*', `($3)->gobj()')
_CONVERSION(`const Glib::RefPtr<Row>&', `GdaRow*', `const_cast<GdaRow*>(($3)->gobj())')
_CONVERSION(`GdaRow*',`Glib::RefPtr<Row>',`Glib::wrap($3)')
_CONVERSION(`GdaRow*',`Glib::RefPtr<const Row>',`Glib::wrap($3)')

_CONVERSION(`const Value&', `GdaValue*', `const_cast<GdaValue*>(($3).gobj())')
_CONVERSION(`const Value&', `const GdaValue*', `($3).gobj()')


_CONVERSION(`GdaColumn*',`Glib::RefPtr<Column>',`Glib::wrap($3)')
_CONVERSION(`GdaColumn*',`Glib::RefPtr<const Column>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<Column>&', `GdaColumn*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Column>&', `const GdaColumn*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Column>&', `const GdaColumn*', __CONVERT_REFPTR_TO_P)
#_CONVERSION(`Column&', `GdaColumn*', `($3).gobj()')


_CONVERSION(`GdaEntityField*',`Glib::RefPtr<EntityField>',`Glib::wrap($3)')
_CONVERSION(`GdaEntityField*',`Glib::RefPtr<const EntityField>',`Glib::wrap($3)')
_CONVERSION(`const Glib::RefPtr<EntityField>&', `GdaEntityField*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const EntityField>&', `const GdaEntityField*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const EntityField>&', `GdaEntityField*', __CONVERT_CONST_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<EntityField>&', `const GdaEntityField*', __CONVERT_REFPTR_TO_P)

_CONVERSION(`GdaEntity*',`Glib::RefPtr<Entity>',`Glib::wrap($3)')
_CONVERSION(`GdaEntity*',`Glib::RefPtr<const Entity>',`Glib::wrap($3)')
_CONVERSION(`Glib::RefPtr<Entity>', `GdaEntity*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Entity>&', `GdaEntity*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<const Entity>&', `const GdaEntity*', __CONVERT_REFPTR_TO_P)
_CONVERSION(`const Glib::RefPtr<Entity>&', `const GdaEntity*', __CONVERT_REFPTR_TO_P)

_CONVERSION(`GdaDict*',`Glib::RefPtr<Dict>',`Glib::wrap($3)')
_CONVERSION(`GdaDict*',`Glib::RefPtr<const Dict>',`Glib::wrap($3)')

_CONVERSION(`GdaDictType*',`Glib::RefPtr<DictType>',`Glib::wrap($3)')
_CONVERSION(`GdaDictType*',`const Glib::RefPtr<DictType>&',`Glib::wrap($3)')
_CONVERSION(`GdaDictType*',`Glib::RefPtr<const DictType>',`Glib::wrap($3)')

_CONVERSION(`GdaColumnIndex*',`Glib::RefPtr<ColumnIndex>',`Glib::wrap($3)')

_CONVERSION(`const DataModelIndex&', `const GdaDataModelIndex*', `($3).gobj()')

_CONVERSION(`const GObject*',`Glib::RefPtr<const Glib::Object>',`Glib::wrap(const_cast<GObject*>($3))')
_CONVERSION(`const Glib::RefPtr<Glib::Object>&', `const GObject*', `($3)->gobj()')


_CONVERSION(`const Glib::RefPtr<Client>&', `GdaClient*', __CONVERT_REFPTR_TO_P)

_CONVERSION(`const Value&', `GValue*', `const_cast<GValue*>(($3).gobj())')
_CONVERSION(`const Value&', `const GValue*', `($3).gobj()')
_CONVERSION(`GValue*', `Value', `$2($3)')
_CONVERSION(`const GValue*', `Value', `$2($3)')

_CONVERSION(`GdaRow*', `const Glib::RefPtr<Row>',  `Glib::wrap($3)')
_CONVERSION(`GdaRow*', `const Glib::RefPtr<const Row>',  `Glib::wrap($3)')

_CONVERSION(`const Time&', `const GdaTime*', `&($3)')
_CONVERSION(`const GdaTime*', `Time', `*($3)')

_CONVERSION(`const Timestamp&', `const GdaTimestamp*', `&($3)')
_CONVERSION(`const GdaTimestamp*', `Timestamp', `*($3)')

_CONVERSION(`const GeometricPoint&', `const GdaGeometricPoint*', `&($3)')
_CONVERSION(`const GdaGeometricPoint*', `GeometricPoint', `*($3)')

_CONVERSION(`const GdaBinary&', `const GdaBinary*', `&($3)')
_CONVERSION(`Blob&',`GdaBlob*',__FR2P)
_CONVERSION(`GdaBlob*',`Blob', Glib::wrap($3))

_CONVERSION(`const int*','const-gint*',`$3')

_CONVERSION(`long&',`glong*',`&($3)')

_CONVERSION(`Glib::ustring', `const gchar*', `($3).c_str()')

_CONVERSION(`DictConstraintFkAction&',`GdaDictConstraintFkAction*',`(($2) &($3))')

_CONV_ENUM(Gda,CommandType)
_CONV_ENUM(Gda,CommandOptions)
_CONV_ENUM(Gda,ConnectionFeature)
_CONV_ENUM(Gda,ConnectionSchema)
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
_CONV_ENUM(Gda,ServerOperationType)
_CONV_ENUM(Gda,ServerOperationNodeType)
_CONV_ENUM(Gda,QueryType)
_CONV_ENUM(Gda,QueryConditionType)
_CONV_ENUM(Gda,QueryConditionOperator)
_CONV_ENUM(Gda,QueryJoinType)
_CONV_ENUM(Gda,QueryFieldState)
_CONV_ENUM(Gda,DictConstraintType)
_CONV_ENUM(Gda,DictConstraintFkAction)
_CONV_ENUM(Gda,DictFieldAttribute)
_CONV_ENUM(Gda,ValueAttribute)

# Lists
_CONVERSION(`const Glib::ListHandle<Value>&',`GList*',`$3.data()')
_CONVERSION(`GList*',`const Glib::ListHandle<Value>',__FL2H_SHALLOW)
_CONVERSION(`GSList*',`Glib::SListHandle<Parameter>',__FL2H_SHALLOW)
_CONVERSION(`const Glib::SListHandle<Parameter>&',`GSList*',`$3.data()')

# For signals:
_CONVERSION(`GdaParameterList*',`const ParameterList&',`Glib::wrap($3)')
_CONVERSION(`GdaConnection*',`const Glib::RefPtr<Connection>&',`Glib::wrap($3)')
