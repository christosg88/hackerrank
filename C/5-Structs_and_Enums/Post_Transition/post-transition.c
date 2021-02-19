// https://www.hackerrank.com/challenges/post-transition

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

typedef struct package {
  char *id;
  int weight;
} package;

void free_package(package *p) {
  free(p->id);
}

typedef struct post_office {
  int min_weight;
  int max_weight;
  package *packages;
  int packages_count;
} post_office;

void free_post_office(post_office *po) {
  for (int i = 0; i < po->packages_count; ++i) {
    free_package(&po->packages[i]);
  }
  free(po->packages);
}

typedef struct town {
  char *name;
  post_office *offices;
  int offices_count;
} town;

void free_town(town *t) {
  free(t->name);
  for (int i = 0; i < t->offices_count; ++i) {
    free_post_office(&t->offices[i]);
  }
  free(t->offices);
}

void print_all_packages(town t) {
  printf("%s:\n", t.name);
  for (int i = 0; i < t.offices_count; ++i) {
    printf("\t%d:\n", i);
    post_office *po = &t.offices[i];
    for (int j = 0; j < po->packages_count; ++j) {
      printf("\t\t%s\n", po->packages[j].id);
    }
  }
}

void send_all_acceptable_packages(town *source, int source_office_index, town *target, int target_office_index) {
  post_office *source_po = &source->offices[source_office_index];
  post_office *target_po = &target->offices[target_office_index];

  int num_source_packages = source_po->packages_count;

  // make sure the target post office can hold all packages
  target_po->packages = realloc(
    target_po->packages,
    (num_source_packages + target_po->packages_count) * sizeof(package));

  // create a new array with the rejected packages, which at worst case will
  // be all the packages from the source post office
  int num_rejected = 0;
  package *rejected = malloc(num_source_packages * sizeof(package));

  for (int i = 0; i < num_source_packages; ++i) {
    int weight = source_po->packages[i].weight;
    if (weight >= target_po->min_weight && weight <= target_po->max_weight) {
      target_po->packages[target_po->packages_count++] = source_po->packages[i];
    } else {
      rejected[num_rejected++] = source_po->packages[i];
    }
  }

  free(source_po->packages);
  source_po->packages_count = num_rejected;
  source_po->packages = rejected;
}

town town_with_most_packages(town *towns, int towns_count) {
  town *max_count_packages_town;
  int max_count_packages = 0;

  for (int i = 0; i < towns_count; ++i) {
    town *t = &towns[i];
    int count_packages = 0;
    for (int j = 0; j < t->offices_count; ++j) {
      count_packages += t->offices[j].packages_count;
    }

    if (count_packages > max_count_packages) {
      max_count_packages = count_packages;
      max_count_packages_town = t;
    }
  }

  return *max_count_packages_town;
}

town *find_town(town *towns, int towns_count, char *name) {
  for (int i = 0; i < towns_count; ++i) {
    town *t = &towns[i];
    if (strcmp(t->name, name) == 0) {
      return t;
    }
  }

  return NULL;
}

int main() {
  int towns_count;
  scanf("%d", &towns_count);
  town *towns = malloc(sizeof(town) * towns_count);
  for (int i = 0; i < towns_count; i++) {
    towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
    scanf("%s", towns[i].name);
    scanf("%d", &towns[i].offices_count);
    towns[i].offices = malloc(sizeof(post_office) * towns[i].offices_count);
    for (int j = 0; j < towns[i].offices_count; j++) {
      scanf(
          "%d%d%d",
          &towns[i].offices[j].packages_count,
          &towns[i].offices[j].min_weight,
          &towns[i].offices[j].max_weight);
      towns[i].offices[j].packages = malloc(sizeof(package) * towns[i].offices[j].packages_count);
      for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
        towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].offices[j].packages[k].id);
        scanf("%d", &towns[i].offices[j].packages[k].weight);
      }
    }
  }
  int queries;
  scanf("%d", &queries);
  char town_name[MAX_STRING_LENGTH];
  while (queries--) {
    int type;
    scanf("%d", &type);
    switch (type) {
    case 1:
      scanf("%s", town_name);
      town *t = find_town(towns, towns_count, town_name);
      print_all_packages(*t);
      break;
    case 2:
      scanf("%s", town_name);
      town *source = find_town(towns, towns_count, town_name);
      int source_index;
      scanf("%d", &source_index);
      scanf("%s", town_name);
      town *target = find_town(towns, towns_count, town_name);
      int target_index;
      scanf("%d", &target_index);
      send_all_acceptable_packages(source, source_index, target, target_index);
      break;
    case 3:
      printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
      break;
    }
  }

  for (int i = 0; i < towns_count; ++i) {
    free_town(&towns[i]);
  }
  free(towns);

  return 0;
}
