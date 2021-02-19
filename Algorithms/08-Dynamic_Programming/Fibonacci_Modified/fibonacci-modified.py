a, b, n = map(int, input().strip().split())

while n > 2:
    tmp = b**2 + a
    a = b
    b = tmp
    n -= 1

print(b)
