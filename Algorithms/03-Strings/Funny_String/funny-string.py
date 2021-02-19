# Python 3
testcases = int(input().strip())

for test in range(testcases):
    string = input().strip()
    ascii_string = [ord(c) for c in string]
    length = len(string)
    funny = True
    for i in range(1, length):
        if abs(ascii_string[i] - ascii_string[i - 1]) != abs(ascii_string[length - i - 1] - ascii_string[length - i]):
            funny = False
            break
    if funny:
        print('Funny')
    else:
        print('Not Funny')
