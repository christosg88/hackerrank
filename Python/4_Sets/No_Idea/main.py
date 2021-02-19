from collections import Counter


if __name__ == "__main__":
    length_a, length_b = list(map(int, input().split()))

    counts = Counter(map(int, input().split()))

    set_a = set(list(map(int, input().split())))
    set_b = set(list(map(int, input().split())))

    total_happiness = 0
    for value, count in counts.items():
        if value in set_a:
            total_happiness += count
        elif value in set_b:
            total_happiness -= count

    print(total_happiness)
