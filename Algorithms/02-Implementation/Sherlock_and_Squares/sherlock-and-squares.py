from math import sqrt
from math import floor
from math import ceil

testcases = int(input())

for test in range(testcases):
    a, b = map(sqrt, map(int, input().strip().split(' ')))

    c = 0
    if floor(a) == ceil(a):
        c += 1

    print(c + int(floor(b) - floor(a)))
