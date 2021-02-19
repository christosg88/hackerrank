#!/bin/python3

import math
import os
import random
import re
import sys


def solve(s):
    capitalized_s = ''
    is_first_letter = True
    for c in s:
        if c == ' ':
            is_first_letter = True
            capitalized_s += c
        elif is_first_letter:
            capitalized_s += c.upper()
            is_first_letter = False
        else:
            capitalized_s += c

    return capitalized_s


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)

    fptr.write(result + '\n')

    fptr.close()
