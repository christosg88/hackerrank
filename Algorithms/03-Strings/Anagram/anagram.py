testcases = int(input().strip())

for test in range(testcases):
    string = input().strip()
    length = len(string)
    half_length = length // 2
    if length % 2:
        print(-1)
        continue

    letters1 = [0] * 26
    letters2 = [0] * 26

    ascii_a = ord('a')
    ascii_string = [ord(c) - ascii_a for c in string]

    for i in range(half_length):
        letters1[ascii_string[i]] += 1
        letters2[ascii_string[half_length + i]] += 1

    counter = 0
    for i in range(26):
        if letters1[i] > letters2[i]:
            counter += letters1[i] - letters2[i]

    print(counter)
