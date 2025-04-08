#!/bin/bash

if [ $# == 1 ]
then
        for i in $(seq $1)
        do
            echo -e $i
        done
else
    echo -e "Syntaxe: ./my_seq.sh INT\n"
fi
exit
