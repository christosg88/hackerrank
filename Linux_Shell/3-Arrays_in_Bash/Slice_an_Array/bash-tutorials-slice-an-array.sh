#!/usr/bin/env bash

count=0
while read -r line; do
    countries[${count}]="${line}"
    ((count++))
done

echo "${countries[@]:3:5}"  # slice from the 3rd index with a length of 5 (3..7)

exit 0
