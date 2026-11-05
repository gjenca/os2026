#!/bin/bash

while test "$#" != 0
do
    echo "$1*5" | bc
    shift
done

