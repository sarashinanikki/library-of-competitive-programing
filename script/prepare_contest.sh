#!/bin/bash

python ~/Documents/life_shells/contest.py $1 $2 $3
code $1
letters="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
n=$(($2-1))
for i in `seq 0 $n`
do
    sleep 0.5s
    x=${letters:$i:1}
    y="${x}.cpp"
    code ./$1/$x/$y
    sleep 0.5s
done