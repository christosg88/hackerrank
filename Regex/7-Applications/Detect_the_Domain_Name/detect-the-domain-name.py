import re
from urllib.parse import unquote

domain_name = re.compile(
    r'(?:https?://)(?:www.|ww2)?([a-z0-9.\-]+\.[a-z]+)(?:/|\?|")')

domains = set()

N = int(input())

for i in range(N):
    S = input()

    S = unquote(S)

    domain = domain_name.finditer(S)

    if domain:
        for d in domain:
            domains.add(d.group(1))

print(';'.join(sorted(list(domains))))
