import re

beginning = re.compile(r"^hackerrank")
ending = re.compile(r"hackerrank$")

N = int(input())

for i in range(N):
    s = input()
    if beginning.search(s) and ending.search(s):
        print(0)
    elif beginning.search(s):
        print(1)
    elif ending.search(s):
        print(2)
    else:
        print(-1)
