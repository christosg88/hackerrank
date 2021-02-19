if __name__ == '__main__':
    height, width = map(int, input().split())

    for line in range(height // 2):
        print(('.|.' * (line * 2 + 1)).center(width, '-'))

    print('WELCOME'.center(width, '-'))

    for line in range(height // 2 - 1, -1, -1):
        print(('.|.' * (line * 2 + 1)).center(width, '-'))
