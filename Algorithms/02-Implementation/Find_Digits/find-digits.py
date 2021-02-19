testcases = int(input())

for test in range(testcases):
    str_num = input().strip()
    number = int(str_num)
    print(sum(((digit != '0') and (number % int(digit) == 0))
              for digit in str_num))
