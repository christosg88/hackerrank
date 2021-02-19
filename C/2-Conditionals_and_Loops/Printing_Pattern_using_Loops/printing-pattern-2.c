#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

int main() {
    int size, double_size;
    scanf("%d", &size);

    double_size = 2 * size - 1;

    for (int row = 1; row <= double_size; ++row) {
        for (int col = 1; col <= double_size; ++col) {
            printf("%d ", 1 + max(abs(row - size), abs(col - size)));
        }
        printf("\n");
    }

    return 0;
}
