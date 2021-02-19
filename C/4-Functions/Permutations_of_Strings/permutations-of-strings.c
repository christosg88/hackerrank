#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// swap two strings
void swap(char **s1, char **s2) {
  char *tmp = *s1;
  *s1 = *s2;
  *s2 = tmp;
}

/// reverse the order of strings in s, from first to last (excluding)
void reverse(char **s, int first, int last) {
  int half_len = (last - first) / 2;
  for (int i = 0; i < half_len; ++i) {
    swap(&s[first+i], &s[last-1-i]);
  }
}

/// produce the next lexicographic permutation of the strings in s
/// source: https://en.cppreference.com/w/cpp/algorithm/next_permutation
int next_permutation(int n, char **s) {
  if (n < 2) {
    return 0;
  }

  int i = n - 1;
  while (1) {
    int i1, i2;
    i1 = i;
    if (strcmp(s[--i], s[i1]) < 0) {
      i2 = n;
      while (!(strcmp(s[i], s[--i2]) < 0))
        ;
      swap(&s[i], &s[i2]);
      reverse(s, i1, n);
      return 1;
    }
    if (i == 0) {
      reverse(s, 0, n);
      return 0;
    }
  }
}

int main() {
  char **s;
  int n;
  scanf("%d", &n);
  s = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    s[i] = calloc(11, sizeof(char));
    scanf("%s", s[i]);
  }
  do {
    for (int i = 0; i < n; i++)
      printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
  } while (next_permutation(n, s));
  for (int i = 0; i < n; i++)
    free(s[i]);
  free(s);
  return 0;
}

