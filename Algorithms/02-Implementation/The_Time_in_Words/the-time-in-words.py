def nums_in_words(num):
    units = ['', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight',
             'nine']
    teens = ['eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen',
             'seventeen', 'eighteen', 'nineteen']
    tens = ['ten', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy',
            'eighty', 'ninety']

    if num < 10:
        return units[num]
    elif num > 10 and num < 20:
        return teens[num - 11]
    else:
        return (tens[num // 10 - 1] + ' ' + units[num % 10]).rstrip()


def minute_expression(M):
    if M == 15:
        return 'quarter past '
    elif M == 30:
        return 'half past '
    elif M == 45:
        return 'quarter to '
    elif M < 30:
        return nums_in_words(M) + ' minute' + ('s' if M > 1 else '') + ' past '
    else:
        return nums_in_words(60 - M) + ' minute' + ('s' if 60 - M > 1 else '') + ' to '


def time_in_words(H, M):
    if M == 0:
        return nums_in_words(H) + ' o\' clock'
    elif M <= 30:
        return minute_expression(M) + nums_in_words(H)
    else:
        return minute_expression(M) + nums_in_words(H % 12 + 1)

H = int(input().strip())
M = int(input().strip())

print(time_in_words(H, M))
