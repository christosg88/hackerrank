from itertools import islice

num_of_segments, testcases = map(int, input().strip().split(' '))

segments = [int(x) for x in input().strip().split(' ')]

for test in range(testcases):
    start, end = map(int, input().strip().split(' '))
    print(min(segments[start:end + 1]))
