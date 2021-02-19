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
        if str_a[i:] > str_b[j:]:
            print(str_a[i], end="")
            i += 1
        elif str_a[i:] < str_b[j:]:
            print(str_b[j], end="")
            j += 1
        else:
            print("\nPROBLEM\n", end="")
            break
        if i == len_a or j == len_b:
            break
    if i == len_a:
        print(str_b[j:], end="")
    elif j == len_b:
        print(str_a[i:], end="")
    print("")
