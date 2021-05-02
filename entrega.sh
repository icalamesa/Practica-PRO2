#!/usr/bin/env bash

extensions=".cc .hh"
paths=""
rm -fr $1
mkdir $1
for i in ${extensions}
do
    paths="${paths} `find -name *${i}`"
done
for i in ${paths}
do
    cp ${i} ${1}/
done
cp ${2} ${1}
cd ${1}
tar -cvf ../entrega.tar *
cd ..
