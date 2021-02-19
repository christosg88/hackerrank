def is_leap(year):
    return not ((year % 400) and (year % 4 or not (year % 100)))


year = int(input())
print(is_leap(year))
