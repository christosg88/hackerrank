from math import log2, floor


def print_formatted(number):
    max_num_bin_digits = int(floor(log2(number) + 1))

    for i in range(1, number + 1):
        print(
            "{:d}".format(i).rjust(max_num_bin_digits),
            "{:o}".format(i).rjust(max_num_bin_digits),
            "{:X}".format(i).rjust(max_num_bin_digits),
            "{:b}".format(i).rjust(max_num_bin_digits),
            sep=' '
        )


if __name__ == '__main__':
    n = int(input())
    print_formatted(n)
