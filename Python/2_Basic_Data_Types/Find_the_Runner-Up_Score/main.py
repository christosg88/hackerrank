if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort(reverse=True)

    max_val = arr[0]

    for val in arr[1:]:
        if val != max_val:
            print(val)
            break
