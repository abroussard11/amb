#!/bin/tcsh -ef

if ($#argv) then
   set opts=$argv
endif

pushd .
cd $PROJECT_PATH
make $opts
popd
