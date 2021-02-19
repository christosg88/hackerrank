#include <stdio.h>

int main() {
    int first, last;
    scanf("%d %d ", &first, &last);

    static char *const numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    for (int num = first; num <= last; ++num) {
        if (num > 0 && num < 10) {
            printf("%s\n", numbers[num - 1]);
        }
        else {
            if (num & 1) {
                printf("odd\n");
            }
            else {
                printf("even\n");
            }
        }
    }

    return 0;
}
