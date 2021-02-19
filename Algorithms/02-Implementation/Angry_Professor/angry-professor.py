testcases = int(input())

for i in range(testcases):
    students, threshold = map(int, input().strip().split(' '))
    arrivals = map(int, input().strip().split(' '))
    if sum(arrival <= 0 for arrival in arrivals) >= threshold:
        print('NO')
    else:
        print('YES')
