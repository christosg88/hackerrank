import re

p = re.compile(r'[a-z]{0,3}\d{2,8}[A-Z]{3,}')

N = int(input())

for i in range(N):
    s = input()
    result = p.match(s)
    if result:
        print('VALID')
    else:
        print('INVALID')

