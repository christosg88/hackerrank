import operator

if __name__ == '__main__':
    students = int(input())
    grades = []
    for student in range(students):
        name = input()
        score = float(input())

        grades.append([name, score])

    grades.sort(key=operator.itemgetter(1, 0))

    lowest = grades[0][1]
    second_lowest = None
    second_lowest_idx = None

    for idx, pair in enumerate(grades[1:], 1):
        name, grade = pair
        if grade != lowest:
            second_lowest = grade
            second_lowest_idx = idx
            break

    for name, grade in grades[second_lowest_idx:]:
        if grade != second_lowest:
            break
        print(name)
