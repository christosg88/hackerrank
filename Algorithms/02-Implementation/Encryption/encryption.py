from math import ceil, sqrt

plaintext = input().strip()
length = len(plaintext)
rows = int(sqrt(length))
cols = int(ceil(sqrt(length)))
if cols * rows < length:
    rows += 1

encrypted = ''
for c in range(cols):
    for r in range(rows):
        if c + cols * r < length:
            encrypted += plaintext[c + cols * r]

    encrypted += ' '

print(encrypted)
