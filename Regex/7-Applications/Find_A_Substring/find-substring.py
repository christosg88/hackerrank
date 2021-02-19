import re

N = int(input())

strings = []

for i in range(N):
    strings.append(input())

T = int(input())

for i in range(T):
    _sum = 0

    substr = input()

    sub_str = re.compile(r'\w' + substr + r'\w')

    for S in strings:
        k = sub_str.findall(S)
        if k:
            _sum += len(k)

    print(_sum)
