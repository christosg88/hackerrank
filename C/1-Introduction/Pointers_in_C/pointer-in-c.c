#include <stdio.h>

void update(int *a,int *b) {
    if (*a >= *b) {
        *a =  *a + *b;
        *b = *a - 2 * *b;
    }
    else {
        *a = *a + *b;
        *b = 2 * *b - *a;
    }
}

int main() {
    int a , b;
    scanf("%d %d ", &a, &b);
    update(&a, &b);

    printf("%d\n%d\n", a, b);

    return 0;
}
