#!/usr/bin/env bash

############################
#
# Author: silentcat
# Date: 2018-12-19
# Description: A script for
# installing the library and
# keeping the directory clean.
#
#############################


if [[ $1 == "" || $1 == "help" ]]
then
  echo "Usage: ./install_library.sh [test|install|clean|dist]"
  cat <<.
test: Creates the test file in the test/ directory.
install: Creates and installs the library.
clean: Uninstalls and cleans the entire library.
dist: Makes a new package.
.
  exit
fi

touch AUTHORS COPYING INSTALL NEWS README ChangeLog
cat README.md > README
autoreconf -i

if [[ $1 == "test" ]]
then
  ./configure
  cd test && make
  cd ../
  ./make_tests.sh c
elif [[ $1 == "install" ]]
then
  ./configure && make && make install
elif [[ $1 == "clean" ]]
then
  ./make_tests.sh d
  make clean && make uninstall
  rm Makefile test/Makefile test/liberrors_test
  rm -rf config.* depcomp install-sh compile autom4te.cache missing libtool \
  aclocal.m4 *.in test/*.in test/*.o *.o liberrors.la liberrors.lo \
  configure stamp-h1 ltmain.sh
  rm AUTHORS COPYING INSTALL NEWS ChangeLog
elif [[ $1 == "dist" ]]
then
  ./configure && make dist
else
  echo "Option unknown. Use the help option to see list of commands." >&2
fi
