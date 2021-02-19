size = int(input().strip())

grid = []
for line in range(size):
    grid.append([int(x) for x in input().strip()])

for i in range(size):
    for j in range(size):
        cav = grid[i][j]
        if i > 0 and i < size - 1 and j > 0 and j < size - 1:
            if grid[i - 1][j] < cav and grid[i + 1][j] < cav and grid[i][j - 1] < cav and grid[i][j + 1] < cav:
                print('X', end='')
                continue
        print(cav, end='')
    print()
