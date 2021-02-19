def unordered_anagramatic_pairs(s):
    count = 0
    length = len(s)
    for substr_len in range(1, length):
        hashes = {}
        for i in range(length - substr_len + 1):
            str_hash = ''.join(sorted(s[i:i + substr_len]))
            if str_hash in hashes:
                hashes[str_hash] += 1
            else:
                hashes[str_hash] = 1
        for value in hashes.values():
            count += (value * (value - 1) // 2)

    return count

testcases = int(input().strip())

for test in range(testcases):
    s = input().strip()
    print(unordered_anagramatic_pairs(s))
