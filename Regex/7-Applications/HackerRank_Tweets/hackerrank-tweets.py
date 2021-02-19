import re

N = int(input())

regex = re.compile(r'hackerrank', re.I)

count = 0
for i in range(N):
    s = input()
    r = regex.search(s)
    if r:
        count += 1

print(count)
