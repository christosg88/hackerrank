testcases = int(input().strip())

for test in range(testcases):
    string = input().strip()
    length = len(string)

    count = 0
    for i in range(length // 2):
        count += abs(ord(string[i]) - ord(string[length - i - 1]))

    print(count)
