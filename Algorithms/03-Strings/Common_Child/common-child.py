# # https://en.wikipedia.org/wiki/Longest_common_subsequence_problem


# def longest_common_subsequence(str1, len1, str2, len2, start):
#     # we only need the last two rows to solve the problem, we will use the two
#     # rows interchangeably
#     table = [[0] * (len2 - start + 1) for i in range(2)]
#     row = 1

#     for i in range(len1 - start):
#         for j in range(len2 - start):
#             if str1[start + i] == str2[start + j]:
#                 table[row][j + 1] = table[1 - row][j] + 1
#             else:
#                 table[row][j + 1] = max(table[row][j], table[1 - row][j + 1])

#         row = (row + 1) % 2

#     return table[1 - row][len2 - start]

# str1 = input().strip()
# len1 = len(str1)
# str2 = input().strip()
# len2 = len(str2)

# count = 0
# start = 0
# while start < len1 and start < len2 and str1[start] == str2[start]:
#     count += 1
#     start += 1
# while start < len1 and start < len2 and str1[len1 - 1] == str2[len2 - 1]:
#     count += 1
#     len1 -= 1
#     len2 -= 1


# print(count + longest_common_subsequence(str1, len1, str2, len2, start))

from collections import defaultdict


def lcs(s1, s2):
    prev = defaultdict(int)
    for i in range(len(s1)):
        cur = defaultdict(int)
        for j in range(len(s2)):
            if s1[i] == s2[j]:
                cur[j] = prev[j - 1] + 1
            else:
                cur[j] = max(cur[j - 1], prev[j])
        prev = cur
    return prev[len(s2) - 1]


def main():
    s, t = input().strip(), input().strip()
    print lcs(s, t)

main()
