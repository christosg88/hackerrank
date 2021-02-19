"""The implementation uses suffix arrays"""
"""more info: https://en.wikipedia.org/wiki/Suffix_array"""
from __future__ import print_function

T = int(raw_input())

for t in xrange(T):
    str_a = raw_input()
    str_b = raw_input()
    len_a = len(str_a)
    len_b = len(str_b)

    i = 0
    j = 0
    while True:
        # if the first letter of str_a is smaller than of str_b print the first
        if ord(str_a[i]) < ord(str_b[j]):
            print(str_a[i], end="")
            i += 1
        # if the first letter of str_a is bigger than of str_b print the second
        elif ord(str_a[i]) > ord(str_b[j]):
            print(str_b[j], end="")
            j += 1
        # else they are equal
        else:
            # if one of them is the last letter of the string
            if i == len_a - 1:
                if ord(str_b[j + 1])
            elif j == len_b - 1:
                # if the next letters of both str_a and str_b are bigger, print both
                # of them and continue
            if ord(str_a[i + 1]) >= ord(str_a[i]) and ord(str_b[j + 1]) >= ord(str_b[j]):
                print(2 * str_a[i], end="")
                i += 1
                j += 1

        if i == len_a:
            print(str_b[j:], end="")
            break
        elif j == len_b:
            print(str_a[i:], end="")
            break
