N = int(input())

nums = map(int, input().strip().split())

counts = {}

for num in nums:
    if num not in counts:
        counts[num] = 1
    else:
        counts[num] = 2

for num in counts:
    if counts[num] == 1:
        print(num)
        break
