import re

hi = re.compile(r'^[hH][iI] [^d]')

N = int(input())

for i in range(N):
    S = input()
    if hi.search(S):
        print(S)
