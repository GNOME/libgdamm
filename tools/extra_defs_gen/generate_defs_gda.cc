/* $Id$ */

/* generate_defs_gda.h
 *
 * Copyright (C) 2001 The Free Software Foundation
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "glibmm_generate_extra_defs/generate_extra_defs.h"
#include <libgda/libgda.h>
#include <libgda/gda-xql-atom.h>
#include <libgda/gda-xql-bin.h>
#include <libgda/gda-xql-column.h>
#include <libgda/gda-xql-const.h>
#include <libgda/gda-xql-delete.h>
//#include <libgda/gda-xql-dml.h>
#include <libgda/gda-xql-dual.h>
//#include <libgda/gda-xql-field.h>
#include <libgda/gda-xql-func.h>
#include <libgda/gda-xql-insert.h>
#include <libgda/gda-xql-join.h>
//#include <libgda/gda-xql-list.h>
//#include <libgda/gda-xql-query.h>
#include <libgda/gda-xql-select.h>
//#include <libgda/gda-xql-stack.h>
#include <libgda/gda-xql-target.h>
#include <libgda/gda-xql-update.h>
#include <libgda/gda-xql-value.h>
#include <libgda/gda-xql-valueref.h>
//#include <libgda/gda-server-recordset-model.h>

int main (int argc, char *argv[])
{
    gda_init("generate_extra_defs", "0.1", argc, argv);

    std::cout << get_defs(GDA_TYPE_CLIENT)
                 << get_defs(GDA_TYPE_CONNECTION)
                 << get_defs(GDA_TYPE_DATA_MODEL_ARRAY)
                 << get_defs(GDA_TYPE_DATA_MODEL_LIST)
                 << get_defs(GDA_TYPE_DATA_MODEL_BASE)
                 << get_defs(GDA_TYPE_DATA_MODEL)
//                 << get_defs(GDA_TYPE_DATA_MODEL_COLUMN_ATTRIBUTES)
                 << get_defs(GDA_TYPE_ERROR)
//                 << get_defs(GDA_TYPE_EXPORT)
//                 << get_defs(GDA_TYPE_RECORDSET)
//                 << get_defs(GDA_TYPE_SERVER_CONNECTION)
//                 << get_defs(GDA_TYPE_SERVER_PROVIDER)
//                 << get_defs(GDA_TYPE_SERVER_RECORDSET_MODEL)
//                 << get_defs(GDA_TYPE_SERVER_RECORDSET)
//                 << get_defs(GDA_TYPE_SERVER)
                 << get_defs(GDA_TYPE_TABLE)
                 << get_defs(GDA_TYPE_XML_DATABASE)
                 << get_defs(GDA_TYPE_XQL_ATOM)
                 << get_defs(GDA_TYPE_XQL_BIN)
                 << get_defs(GDA_TYPE_XQL_COLUMN)
                 << get_defs(GDA_TYPE_XQL_CONST)
                 << get_defs(GDA_TYPE_XQL_DELETE)
                 << get_defs(GDA_TYPE_XQL_DML)
                 << get_defs(GDA_TYPE_XQL_DUAL)
//                 << get_defs(GDA_TYPE_XQL_FIELD)
                 << get_defs(GDA_TYPE_XQL_FUNC)
                 << get_defs(GDA_TYPE_XQL_INSERT)
                 << get_defs(GDA_TYPE_XQL_JOIN)
//                 << get_defs(GDA_TYPE_XQL_LIST)
//                 << get_defs(GDA_TYPE_XQL_QUERY)
                 << get_defs(GDA_TYPE_XQL_SELECT)
//                 << get_defs(GDA_TYPE_XQL_STACK)
                 << get_defs(GDA_TYPE_XQL_TARGET)
//                 << get_defs(GDA_TYPE_XQL_UPDATE)
                 << get_defs(GDA_TYPE_XQL_VALUE)
                 << get_defs(GDA_TYPE_XQL_VALUEREF);
    return 0;
}
