import re

txts = []

N = int(raw_input())

for i in xrange(N):
    txts.append(' ' + raw_input() + ' ')

T = int(raw_input())

for i in xrange(T):
    word = raw_input()
    match_str = re.compile(r'\W' + word + r'(?=\W)')

    count = 0
    for txt in txts:
        count += len(match_str.findall(txt))
    print count
