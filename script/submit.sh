#!/bin/bash

file="${1}.cpp"
i=0
letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for url in `cat urls`
do
    le=${letters:$i:1}
    if [ $le = $1 ]; then
        echo $le
        cd $1
        oj s $url $file
        cd ..
    fi
    i=($i+1)
done