testcases = int(input())

for test in range(testcases):
    money, price, wrappers_needed = list(map(int, input().strip().split(' ')))
    count = money // price
    wrappers = count
    while wrappers >= wrappers_needed:
        tmp_count = wrappers // wrappers_needed
        wrappers = wrappers % wrappers_needed + tmp_count
        count += tmp_count
    print(count)
