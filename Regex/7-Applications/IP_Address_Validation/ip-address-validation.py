import re

ipv4 = re.compile(
    r'^(2[0-5]{2}|[0-1]?\d{1,2})\.(2[0-5]{2}|[0-1]?\d{1,2})\.(2[0-5]{2}|[0-1]?\d{1,2})\.(2[0-5]{2}|[0-1]?\d{1,2})$')

ipv6 = re.compile(
    r'^[\da-f]{1,4}:[\da-f]{1,4}:[\da-f]{1,4}:[\da-f]{1,4}:[\da-f]{1,4}:[\da-f]{1,4}:[\da-f]{1,4}:[\da-f]{1,4}$')

N = int(input())

for i in range(N):
    S = input()
    if ipv4.match(S):
        print('IPv4')
    elif ipv6.match(S):
        print('IPv6')
    else:
        print('Neither')
