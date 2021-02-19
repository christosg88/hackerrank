testcases = int(input())

for i in range(testcases):
    num_of_digits = int(input())
    num_of_5s = num_of_digits
    while num_of_5s >= 0:
        if num_of_5s % 3 == 0:
            print(('5' * num_of_5s) + ('3' * (num_of_digits - num_of_5s)))
            break
        else:
            num_of_5s -= 5
    else:
        print(-1)
