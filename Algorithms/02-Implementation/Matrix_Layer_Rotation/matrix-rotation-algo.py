import collections


def from_array_to_vectors(table, rows, cols):
    num_of_vectors = min(rows, cols) // 2
    vectors = []
    for v in range(num_of_vectors):
        vector = collections.deque()
        for j in range(v, cols - v):
            vector.append(table[v][j])
        for i in range(v + 1, rows - v):
            vector.append(table[i][cols - v - 1])
        for j in range(cols - v - 2, v - 1, -1):
            vector.append(table[rows - v - 1][j])
        for i in range(rows - v - 2, v, -1):
            vector.append(table[i][v])
        vectors.append(vector)

    return vectors


def from_vectors_to_array(vectors, rows, cols):
    num_of_vectors = min(rows, cols) // 2
    table = [[0] * cols for i in range(rows)]
    for v in range(num_of_vectors):
        vector = vectors[v]
        c = 0
        for j in range(v, cols - v):
            table[v][j] = vector[c]
            c += 1
        for i in range(v + 1, rows - v):
            table[i][cols - v - 1] = vector[c]
            c += 1
        for j in range(cols - v - 2, v - 1, -1):
            table[rows - v - 1][j] = vector[c]
            c += 1
        for i in range(rows - v - 2, v, -1):
            table[i][v] = vector[c]
            c += 1

    return table


def rotate_vectors(vectors, rots):
    for vector in vectors:
        vector.rotate(-rots)

rows, cols, rots = map(int, input().strip().split(' '))

table = []
for row in range(rows):
    table.append([int(x) for x in input().strip().split(' ')])

vectors = from_array_to_vectors(table, rows, cols)

rotate_vectors(vectors, rots)

table = from_vectors_to_array(vectors, rows, cols)

for line in table:
    print(' '.join(map(str, line)))
