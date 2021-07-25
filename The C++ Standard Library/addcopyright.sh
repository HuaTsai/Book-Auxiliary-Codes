#!/bin/bash

copyrightlen=9
files=./ch*/*
for x in $files; do
    head -$copyrightlen $x | diff copyright - || ((cat copyright; echo; cat $x) > /tmp/file; mv /tmp/file $x) 
done 
