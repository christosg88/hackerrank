string = input().strip()

letters = [0] * 26

ascii_a = ord('a')
for c in string:
    letters[ord(c) - ascii_a] += 1

not_multiples_of_2 = sum(1 for x in letters if x % 2 == 1)

if not_multiples_of_2 < 2:
    print('YES')
else:
    print('NO')
