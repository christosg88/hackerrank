length = int(input().strip())
string = input().strip()
key = int(input().strip())
key %= 26

for c in string:
    ascii_c = ord(c)
    if ascii_c >= ord('A') and ascii_c <= ord('Z'):
        ascii_c = (ascii_c - ord('A') + key) % 26 + ord('A')
    elif ascii_c >= ord('a') and ascii_c <= ord('z'):
        ascii_c = (ascii_c - ord('a') + key) % 26 + ord('a')
    print(chr(ascii_c), end='')

print()
