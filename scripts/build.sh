#!/bin/bash -ef

if [ $#argv ]; then
   set tgt=$1
else
   set tgt="all"
fi

pushd .
cd $PROJECT_PATH
make -j $tgt
popd

