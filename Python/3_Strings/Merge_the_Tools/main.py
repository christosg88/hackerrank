def merge_the_tools(s, k):
    for subsegment in zip(*[iter(s)] * k):
        d = dict()
        print(''.join([d.setdefault(c, c) for c in subsegment if c not in d]))


if __name__ == '__main__':
    s, k = input(), int(input())
    merge_the_tools(s, k)
