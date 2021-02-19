import re

phone = re.compile(r'(\d+)[ -](\d+)[ -](\d+)')

N = int(input())

for i in range(N):
    number = input()
    n = phone.match(number)
    print('CountryCode=' + str(n.group(1)), end=',')
    print('LocalAreaCode=' + str(n.group(2)), end=',')
    print('Number=' + str(n.group(3)))
