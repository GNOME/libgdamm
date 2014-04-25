#!/bin/bash

# Note that JHBUILD_SOURCES should be defined to contain the path to the root
# of the jhbuild sources. The script assumes that it resides in the
# tools/gen_scripts/ directory and the defs file will be placed in gtk/src.

if [ -z "$JHBUILD_SOURCES" ]; then
  echo -e "JHBUILD_SOURCES must contain the path to the jhbuild sources."
  exit 1;
fi

PREFIX="$JHBUILD_SOURCES/libgda"
ROOT_DIR="$(dirname "$0")/../.."
OUT_DIR="$ROOT_DIR/libgda/src"

ENUM_PL="$JHBUILD_SOURCES/glibmm/tools/enum.pl"
$ENUM_PL "$PREFIX"/libgda/*.h "$PREFIX"/libgda/sql-parser/*.h "$PREFIX"/libgda-report/*.h > "$OUT_DIR"/libgda_enums.defs
