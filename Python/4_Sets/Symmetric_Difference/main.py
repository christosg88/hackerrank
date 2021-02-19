if __name__ == '__main__':
    input()
    set1 = set(list(map(int, input().split())))
    input()
    set2 = set(list(map(int, input().split())))

    for n in sorted(list(set1.symmetric_difference(set2))):
        print(n)
