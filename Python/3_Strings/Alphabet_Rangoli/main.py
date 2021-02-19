from string import ascii_lowercase


def print_rangoli(size):
    line_length = 4 * (size - 1) + 1

    for i in range(size - 1, -1, -1):
        s = '-'.join(ascii_lowercase[i:size])
        print((s[:0:-1] + s).center(line_length, '-'))

    for i in range(1, size):
        s = '-'.join(ascii_lowercase[i:size])
        print((s[:0:-1] + s).center(line_length, '-'))


if __name__ == '__main__':
    n = int(input())
    print_rangoli(n)
