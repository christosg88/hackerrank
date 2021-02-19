def contains(i, j):
    for k in range(r):
        for l in range(c):
            if grid[i + k][j + l] != pattern[k][l]:
                return False
    return True

testcases = int(input().strip())

for test in range(testcases):
    R, C = map(int, input().strip().split())

    grid = []
    for i in range(R):
        grid.append([int(x) for x in input().strip()])

    r, c = map(int, input().strip().split(' '))

    pattern = []
    for i in range(r):
        pattern.append([int(x) for x in input().strip()])

    cont = False
    for i in range(R - r + 1):
        for j in range(C - c + 1):
            if grid[i][j] == pattern[0][0]:
                if contains(i, j):
                    cont = True
                    break
        if cont:
            break

    if cont:
        print('YES')
    else:
        print('NO')
