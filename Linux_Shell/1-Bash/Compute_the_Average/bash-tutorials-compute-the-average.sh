#!/bin/bash

read num_of_nums
total=0
for (( i = 0; i < $num_of_nums; i++ )); do
    read num
    total=$(($total + $num))
done

printf "%.3f\n" $(echo "$total / $num_of_nums" | bc -l)
