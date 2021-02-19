actual_ret = [int(x) for x in input().strip().split(' ')]
expected_ret = [int(x) for x in input().strip().split(' ')]

years = actual_ret[2] - expected_ret[2]
months = actual_ret[1] - expected_ret[1]
days = actual_ret[0] - expected_ret[0]

if years < 0:
    print(0)
elif years > 0:
    print(10000)
else:
    if months < 0:
        print(0)
    elif months > 0:
        print(500 * months)
    else:
        if days <= 0:
            print(0)
        else:
            print(15 * days)
