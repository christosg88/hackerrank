num_of_stones = int(input().strip())

letters = [0] * 26

ascii_a = ord('a')
for stone in range(num_of_stones):
    string = set(list(input().strip()))
    for letter in string:
        letters[ord(letter) - ascii_a] += 1

print(letters.count(num_of_stones))
