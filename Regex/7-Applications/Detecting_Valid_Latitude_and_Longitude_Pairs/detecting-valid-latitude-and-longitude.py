import re

lat_long = re.compile(
    r'^\([-+]?(90(\.0+)?|([1-8][0-9]|[0-9])(\.\d+)?), [-+]?(180(\.0+)?|(1[0-7][0-9]|[0-9][0-9]|[0-9])(\.\d+)?)\)$')

N = int(input())

for i in range(N):
    S = input()
    if lat_long.match(S):
        print('Valid')
    else:
        print('Invalid')
