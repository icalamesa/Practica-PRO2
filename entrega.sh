#!/usr/bin/env bash


extensions=".cc .hh"
paths=""
for i in ${extensions}
do
    paths="${paths} `find -name *${i}`"
done
echo "ivan ${paths}"
