import re


def count_substring(s, sub_s):
    return sum(1 for _ in re.finditer(r'(?=' + sub_s + r')', s))


if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()

    count = count_substring(string, sub_string)
    print(count)
