#!/bin/bash

letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
i=0
for url in `cat urls`
do
    cd ${letters:$i:1}
    oj d $url
    i=($i+1)
    cd ..
done