#!/usr/bin/env bash

count=0
while read line; do
    countries[${count}]="${line}"
    ((count++))
done

echo "${countries[3]}"

exit 0
