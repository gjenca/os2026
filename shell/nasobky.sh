#!/bin/bash

N=5
K=10

for I in $(seq $K)
do
    RESULT=$(echo "$I*$N" | bc)
    echo "$I*$N=$RESULT"
done 
