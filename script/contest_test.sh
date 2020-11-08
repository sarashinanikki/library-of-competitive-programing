#!/bin/bash

name=$1
cd $1
g++ "${name}.cpp"
oj t