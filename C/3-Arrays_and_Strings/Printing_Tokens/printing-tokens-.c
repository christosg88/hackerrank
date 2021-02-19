// https://www.hackerrank.com/challenges/printing-tokens-/problem

#include <stdio.h>

int main(void) {
  char token[1001];

  while (scanf("%s", token) != EOF) {
      printf("%s\n", token);
  }

  return 0;
}

