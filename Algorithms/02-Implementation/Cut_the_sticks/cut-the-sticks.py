testcases = int(input())

sticks = list(map(int, input().strip().split(' ')))

while True:
    print(len(sticks))
    min_stick = min(sticks)
    sticks = [x - min_stick for x in sticks]
    sticks = [x for x in sticks if x > 0]
    if sticks == []:
        break
