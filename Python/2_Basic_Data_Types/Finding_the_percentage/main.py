if __name__ == '__main__':
    num_students = int(input())
    student_marks = {}
    for student in range(num_students):
        name, *line = input().split()
        scores = list(map(float, line))
        student_marks[name] = scores

    query_name = input()
    scores = student_marks[query_name]
    print('{:.2f}'.format(sum(scores) / len(scores)))
