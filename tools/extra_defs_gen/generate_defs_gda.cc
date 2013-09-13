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
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <build/config.h>
#include <glibmm_generate_extra_defs/generate_extra_defs.h>
#include <libgda/libgda.h>
#include <sql-parser/gda-sql-parser.h>

int main(int, char**)
{
  gda_init();

  std::cout 
    << get_defs(GDA_TYPE_BATCH)
    << get_defs(GDA_TYPE_COLUMN)
    << get_defs(GDA_TYPE_CONFIG)
    << get_defs(GDA_TYPE_CONNECTION) 
    << get_defs(GDA_TYPE_CONNECTION_EVENT)
    << get_defs(GDA_TYPE_DATA_ACCESS_WRAPPER)
    << get_defs(GDA_TYPE_DATA_COMPARATOR)
    << get_defs(GDA_TYPE_DATA_HANDLER) 
    << get_defs(GDA_TYPE_DATA_MODEL_ARRAY)
#ifdef HAVE_LIBGDA_BDB
// We don't actually seem to use this,
// so there's no point in breaking the build for it.
// TODO: Actually fix the HAVE_LIBGDA_DBD test to fix the build break properly?
//    << get_defs(GDA_TYPE_DATA_MODEL_BDB)
#endif
    << get_defs(GDA_TYPE_DATA_MODEL_DIR)
    << get_defs(GDA_TYPE_DATA_MODEL) 
    << get_defs(GDA_TYPE_DATA_MODEL_IMPORT)
    << get_defs(GDA_TYPE_DATA_MODEL_ITER) 
    << get_defs(GDA_TYPE_DATA_PROXY)
    << get_defs(GDA_TYPE_DATA_SELECT)    
    << get_defs(GDA_TYPE_HOLDER)
    << get_defs(GDA_TYPE_META_STORE)
    << get_defs(GDA_TYPE_META_STRUCT)
    << get_defs(GDA_TYPE_ROW) 
    << get_defs(GDA_TYPE_SERVER_OPERATION) 
    << get_defs(GDA_TYPE_SERVER_PROVIDER)
    << get_defs(GDA_TYPE_SET)
    << get_defs(GDA_TYPE_STATEMENT)
    << get_defs(GDA_TYPE_TRANSACTION_STATUS)
    << get_defs(GDA_TYPE_XA_TRANSACTION)
    << get_defs(GDA_TYPE_SQL_PARSER)
    << get_defs(GDA_TYPE_SQL_BUILDER);

  return 0;
}
