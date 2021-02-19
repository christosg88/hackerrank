testcases = int(input())

for test in range(testcases):
    B, W = map(int, input().strip().split(' '))
    X, Y, Z = map(int, input().strip().split(' '))
    X = min(X, Y + Z)
    Y = min(Y, X + Z)
    print((B * X) + (W * Y))
