#include <stdio.h>

int main() {
    int num;
    scanf("%d\n", &num);

    static char *const numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

    if (num > 0 && num < 10) {
        printf("%s\n", numbers[num - 1]);
    }
    else {
        printf("Greater than 9\n");
    }

    return 0;
}
