#!/bin/sh
export PREFIX="$HOME/rafos32/cross-compiler"
export PATH="$PREFIX/bin:$PATH"

set -e
. ./headers.sh

for PROJECT in $PROJECTS; do
  (cd $PROJECT && DESTDIR="$SYSROOT" $MAKE install)
done
