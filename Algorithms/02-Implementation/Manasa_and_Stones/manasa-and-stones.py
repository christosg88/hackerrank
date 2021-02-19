testcases = int(input().strip())

for test in range(testcases):
    stones = int(input().strip()) - 1
    a = int(input().strip())
    b = int(input().strip())
    if a == b:
        print(a * stones)
    else:
        if b < a:
            a, b = b, a
        endings = []
        for i in range(stones + 1):
            endings.append((a * (stones - i)) + (b * i))
        print(' '.join(map(str, endings)))
