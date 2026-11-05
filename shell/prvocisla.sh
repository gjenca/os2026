#!/bin/bash

UNTIL=100

if [ "$#" == 1 ]
then
    UNTIL="$1"
fi

for N in $(seq 2 "$UNTIL")
do
    JE_PRVOCISLO="T"
    POKIAL=$(echo "$N/2" | bc)
    for D in $(seq 2 $POKIAL)
    do
        ZVYSOK=$(echo "$N % $D" | bc)
        if test "$ZVYSOK" = "0"
        then
            JE_PRVOCISLO="F"
            break
        fi
    done
    if test "$JE_PRVOCISLO" = "T"
    then
        echo "$N"
    fi
done

