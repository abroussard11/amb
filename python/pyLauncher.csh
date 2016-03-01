#!/bin/csh -ef

set py = "python"
if ($argv[1] == "-3") then
  set py = "python3"
  shift
else if ($argv[1] == "-2") then
  set py = "python2"
  shift
endif

cd $PROJECT_PATH/python
setenv PYTHONPATH "$PWD"
$py -B -m $argv

