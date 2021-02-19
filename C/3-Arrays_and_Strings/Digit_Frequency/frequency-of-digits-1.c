// https://www.hackerrank.com/challenges/frequency-of-digits-1/problem

#include <stdio.h>

int main() {
  char s[1001];
  scanf("%s", s);

  // the frequency each digit appears
  int freq[10] = {0};
  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] >= '0' && s[i] <= '9') {
      ++freq[(int)(s[i]-'0')];
    }
  }

  printf("%d", freq[0]);
  for (int i = 1; i < 10; ++i) {
    printf(" %d", freq[i]);
  }
  printf("\n");

  return 0;
}
