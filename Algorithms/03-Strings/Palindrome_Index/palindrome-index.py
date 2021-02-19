testcases = int(input().strip())

for test in range(testcases):
    string = input().strip()

    palindrome = True
    length = len(string)

    for i in range(length // 2):
        if string[i] != string[length - i - 1]:
            if string[i] == string[length - i - 2] and string[i + 1] == string[length - i - 1]:
                if string[i + 1] == string[length - i - 3]:
                    print(length - i - 1)
                    palindrome = False
                    break
                elif string[i + 2] == string[length - i - 2]:
                    print(i)
                    palindrome = False
                    break
            elif string[i] == string[length - i - 2]:
                print(length - i - 1)
                palindrome = False
                break
            elif string[i + 1] == string[length - i - 1]:
                print(i)
                palindrome = False
                break

    if palindrome:
        print(-1)
