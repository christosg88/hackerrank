#include <stdio.h>
#include <stdlib.h>

int main() {
    // read and print a char
    char c;
    scanf("%c%*c", &c);
    printf("%c\n", c);

    char *s = malloc(100 * sizeof(char));
    // read and print a string
    scanf("%99[^\n]%*c", s);
    printf("%s\n", s);

    // read and print a sentence
    scanf("%99[^\n]%*c", s);
    printf("%s\n", s);

    free(s);

    return 0;
}
