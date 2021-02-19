string1 = input().strip()
string2 = input().strip()

ascii_a = ord('a')

letters1 = [0] * 26
for c in string1:
    letters1[ord(c) - ascii_a] += 1

letters2 = [0] * 26
for c in string2:
    letters2[ord(c) - ascii_a] += 1

counter = 0
for i in range(26):
    counter += abs(letters1[i] - letters2[i])

print(counter)
