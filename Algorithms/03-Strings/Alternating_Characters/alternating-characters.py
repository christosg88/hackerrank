testcases = int(input().strip())

for test in range(testcases):
    string = input().strip()
    length = len(string)
    deletions = 0
    last_char = string[0]
    for i in range(1, length):
        if string[i] == last_char:
            deletions += 1
        else:
            last_char = string[i]

    print(deletions)
