#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char *a, const char *b) {
  return strcmp(a, b);
}

int lexicographic_sort_reverse(const char *a, const char *b) {
  return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char *a, const char *b) {
  int chars_a[26] = {0};
  int chars_b[26] = {0};
  int distinct_a = 0;
  int distinct_b = 0;

  int i = 0;
  while (a[i] != '\0') {
    int idx = a[i] - 'a';
    if (chars_a[idx] == 0) {
      ++distinct_a;
    }
    chars_a[idx] = 1;
    ++i;
  }

  i = 0;
  while (b[i] != '\0') {
    int idx = b[i] - 'a';
    if (chars_b[idx] == 0) {
      ++distinct_b;
    }
    chars_b[idx] = 1;
    ++i;
  }

  int diff = distinct_a - distinct_b;
  if (diff == 0) {
    return lexicographic_sort(a, b);
  } else {
    return diff;
  }
}

int sort_by_length(char const *a, char const *b) {
  int diff = strlen(a) - strlen(b);
  if (diff == 0) {
    return lexicographic_sort(a, b);
  } else {
    return diff;
  }
}

/// An implementation of quick sort for strings (not a stable sort and it fails)
void string_sort(char **arr, int len, int (*cmp_func)(char const *a, char const *b)) {
  if (len < 2) {
    return;
  }

  char const *pivot = arr[len / 2];

  int left, right;
  for (left = 0, right = len - 1;; ++left, --right) {
    while (cmp_func(arr[left], pivot) < 0) {
      ++left;
    }

    while (cmp_func(arr[right], pivot) > 0) {
      --right;
    }

    if (left >= right) {
      break;
    }

    char *tmp = arr[left];
    arr[left] = arr[right];
    arr[right] = tmp;
  }

  string_sort(arr, left, cmp_func);
  string_sort(arr + left, len - left, cmp_func);
}

int main(void) {
  int n;
  scanf("%d", &n);

  char **arr;
  arr = (char **)malloc(n * sizeof(char *));

  for (int i = 0; i < n; i++) {
    *(arr + i) = malloc(1024 * sizeof(char));
    scanf("%s", *(arr + i));
    *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
  }

  string_sort(arr, n, lexicographic_sort);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, lexicographic_sort_reverse);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_length);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  string_sort(arr, n, sort_by_number_of_distinct_characters);
  for (int i = 0; i < n; i++)
    printf("%s\n", arr[i]);
  printf("\n");

  return 0;
}
