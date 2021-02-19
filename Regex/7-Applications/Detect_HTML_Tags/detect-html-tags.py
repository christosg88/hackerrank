import re

tag = re.compile(r'<\s*[a-z\d]+')

final_tags = set()

N = int(input())

for i in range(N):
    S = input()
    tags = tag.finditer(S)
    for t in tags:
        final_tags.add(t.group()[1:])


final_tags = list(final_tags)
final_tags.sort()
print(';'.join(final_tags))
