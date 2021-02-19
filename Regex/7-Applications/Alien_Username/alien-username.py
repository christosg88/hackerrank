import re

m = re.compile(r'^[_.]\d+[a-zA-Z]*_?$')

N = int(input())

for i in range(N):
    username = input()
    p = m.match(username)
    if p:
        print('VALID')
    else:
        print('INVALID')
