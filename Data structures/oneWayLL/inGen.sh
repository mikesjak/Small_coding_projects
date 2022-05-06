#!/bin/bash

# Script needs one parameter to know, how much numbers you want to store in LL

echo " " > in.txt

for (( i = 1; i <= "$1"; i++ )); do
    echo "$RANDOM" >> in.txt
done