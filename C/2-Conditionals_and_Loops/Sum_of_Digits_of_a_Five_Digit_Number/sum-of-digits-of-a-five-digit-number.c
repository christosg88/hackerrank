#include <stdio.h>

int main() {
    int num;
    scanf("%d ", &num);

    int sum_of_digits = 0;
    while (num) {
        sum_of_digits += num % 10;
        num /= 10;
    }

    printf("%d\n", sum_of_digits);

    return 0;
}
