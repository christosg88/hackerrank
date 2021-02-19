#!/bin/bash
read line
printf "%.3f\n" $(echo "$line" | bc -l)
