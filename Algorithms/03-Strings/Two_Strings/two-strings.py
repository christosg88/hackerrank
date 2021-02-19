import string
testcases = int(input().strip())

for test in range(testcases):
    string1 = input().strip()
    string2 = input().strip()

    substring = False
    for c in string.ascii_lowercase:
        if c in string1 and c in string2:
            substring = True
            break

    if substring:
        print('YES')
    else:
        print('NO')
