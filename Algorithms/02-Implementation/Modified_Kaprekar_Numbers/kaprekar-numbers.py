from math import log10


def number_of_digits(num):
    return int(log10(num) + 1)


def is_modified_Kaprekar(num):
    sqr = num**2
    str_sqr = str(sqr)

    num_of_digits_of_sqr = number_of_digits(sqr)

    if num_of_digits_of_sqr % 2:
        num_of_digits_of_sqr += 1
        str_sqr = '0' + str_sqr

    l = str_sqr[:num_of_digits_of_sqr // 2]
    r = str_sqr[num_of_digits_of_sqr // 2:]
    if int(l) + int(r) == num:
        return True
    else:
        return False

start = int(input())
end = int(input())

kaprekars = []
for i in range(start, end + 1):
    if is_modified_Kaprekar(i):
        kaprekars.append(i)

if kaprekars == []:
    print('INVALID RANGE')
else:
    print(' '.join(map(str, kaprekars)))
