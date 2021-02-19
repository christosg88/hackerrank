import re

pan_number = re.compile(r'^[A-Z]{5}\d{4}[A-Z]$')

N = int(input())

for i in range(N):
    S = input()
    if pan_number.match(S):
        print('YES')
    else:
        print('NO')
