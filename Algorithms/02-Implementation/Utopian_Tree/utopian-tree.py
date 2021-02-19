def utopian_tree(days):
    height = 1
    for day in range(1, days + 1):
        if day % 2 == 0:
            height += 1
        else:
            height *= 2
    return height

testcases = int(input())

for test in range(testcases):
    days = int(input())
    print(utopian_tree(days))
