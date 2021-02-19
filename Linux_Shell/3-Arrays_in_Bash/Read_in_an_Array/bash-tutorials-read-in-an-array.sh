#!/usr/bin/env bash

count=0
while read -r line; do
    countries[${count}]="${line}"
    ((count++))
done

echo "${countries[@]}"

exit 0
