if __name__ == '__main__':
    lst = []
    for _ in range(int(input())):
        line = input().split()
        operation = line[0]

        if operation == 'print':
            print(lst)
        elif operation == 'sort':
            lst.sort()
        elif operation == 'pop':
            lst.pop()
        elif operation == 'reverse':
            lst.reverse()
        elif operation == 'remove':
            lst.remove(int(line[1]))
        elif operation == 'append':
            lst.append(int(line[1]))
        elif operation == 'insert':
            lst.insert(int(line[1]), int(line[2]))
