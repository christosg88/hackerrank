// https://www.hackerrank.com/challenges/small-triangles-large-triangles

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct triangle {
  int a;
  int b;
  int c;
} triangle;

// compare areas using Heron's formula
int triangle_area_comp(void const *a, void const *b) {
  triangle const *t1 = a;
  triangle const *t2 = b;

  float p1 = (t1->a + t1->b + t1->c) / 2.0;
  float p2 = (t2->a + t2->b + t2->c) / 2.0;

  float area1 = sqrt(p1 * (p1 - t1->a) * (p1 - t1->b) * (p1 - t1->c));
  float area2 = sqrt(p2 * (p2 - t2->a) * (p2 - t2->b) * (p2 - t2->c));

  return area1 < area2 ? -1 : 1;
}

void sort_by_area(triangle* tr, int n) {
  qsort(tr, n, sizeof(triangle), &triangle_area_comp);
}

int main() {
  int n;
  scanf("%d", &n);
  triangle* tr = malloc(n * sizeof(triangle));
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
  }
  sort_by_area(tr, n);
  for (int i = 0; i < n; i++) {
    printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
  }
  return 0;
}
