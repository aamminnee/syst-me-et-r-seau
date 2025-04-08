#!/bin/bash
#
# -1-any2dec-2.sh <radix> <string_representation_in_that_radix>
#

if [[ $# -lt 2 ]]
then
    echo "Usage: $0 <radix> <string_representation>"
    exit
fi
if [[ $1 -lt 2 || $1 -gt 36 ]]
then
    echo "The radix must be between 2 and 36"
    exit
fi
radix=$1
number=$2
DIGITS="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
LEGAL_DIGITS=$(expr substr $DIGITS 1 $radix)
decimal=0
length=${#number}
for (( i=0; i<length; i++ ))
do
    digit=$(expr substr $number $((i+1)) 1)
    pos=$(expr index "$LEGAL_DIGITS" "$digit")
    if [[ $pos -eq 0 ]]
    then
        echo "Authorized digits are: $LEGAL_DIGITS"
        exit
    fi
    digit_val=$((pos-1))
    decimal=$(( decimal * radix + digit_val ))
done

echo "decimal : $decimal"
