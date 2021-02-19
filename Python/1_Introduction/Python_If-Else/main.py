if __name__ == '__main__':
    n = int(input())

    if n % 2:
        print('Weird')
    else:
        if 1 < n <= 5:
            print('Not Weird')
        elif 5 < n <= 20:
            print('Weird')
        else:
            print('Not Weird')
