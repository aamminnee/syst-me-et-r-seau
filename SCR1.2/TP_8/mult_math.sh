#!/bin/bash

if [ $# -ne 2 ]; then
    echo -e "Missing argument required: ./mult_math.sh <ARG1> <ARG2>\n"
    exit 1
fi

for i in $(seq $1 $2)
do
    for j in $(seq $1 $2)
    do
        echo -n "$((i * j))   "
    done
    echo ""
done

exit 0
