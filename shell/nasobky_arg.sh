#!/bin/bash

N="$1"
K="$2"

for I in $(seq $K)
do
    RESULT=$(echo "$I*$N" | bc)
    echo "$I*$N=$RESULT"
done 
