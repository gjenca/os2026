#!/bin/bash

for ARG in "$@"
do
    echo "$ARG*5" | bc
    shift
done

