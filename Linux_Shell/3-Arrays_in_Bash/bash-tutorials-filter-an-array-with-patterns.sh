#!/usr/bin/env bash

count=0
while read -r line; do
    countries[${count}]="${line}"
    ((count++))
done

countries=(${countries[@]/*[aA]*})

echo ${countries[@]}
