string = input().lower().replace(' ', '')

letters = [0] * 26

ascii_a = ord('a')
for c in string:
    letters[ord(c) - ascii_a] += 1

if sum(1 for x in letters if x > 0) == 26:
    print('pangram')
else:
    print('not pangram')
