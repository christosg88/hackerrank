#include <stdio.h>
#include <stdlib.h>

int main() {
    char *s = malloc(100 * sizeof(char));
    scanf("%99[^\n]%*c", s);

    printf("Hello, World!\n");
    printf("%s\n", s);

    free(s);

    return 0;
}
