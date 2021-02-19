import re

txts = []

N = int(input())

for i in range(N):
    txts.append(' ' + input() + ' ')

T = int(input())

for i in range(T):
    word = input()
    match_str = " (" + word + "|" + word.replace("our", "or") + ")(?= )"
    uk_or_us = re.compile(match_str)
    count = 0
    for txt in txts:
        count += len(uk_or_us.findall(txt))
    print(count)
