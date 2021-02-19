import re

txts = []

N = int(input())

for i in range(N):
    txts.append(' ' + input() + ' ')

T = int(input())

for i in range(T):
    word = input()
    us = re.compile(r' ' + word + r' ')
    uk = re.compile(r' ' + word[:len(word) - 2] + 'se' + r' ')
    count = 0
    for txt in txts:
        count += len(us.findall(txt)) + len(uk.findall(txt))
    print(count)
