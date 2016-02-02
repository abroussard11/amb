#!/bin/csh -ef

cd $PROJECT_PATH/python
setenv PYTHONPATH "$PWD"
python -B -m $argv

