#include <stdio.h>
#include <stdlib.h>

/**
 * This stores the total number of books in each shelf.
 */
int *total_number_of_books;

/**
 * This stores the total number of pages in each book of each shelf. The rows represent the shelves and the columns
 * represent the books.
 */
int **total_number_of_pages;

int main() {
    int total_number_of_shelves;
    scanf("%d", &total_number_of_shelves);

    // initialize the number of books per shelf to 0
    total_number_of_books = calloc(total_number_of_shelves, sizeof(int));
    // initialize the number of pages per book per shelf to NULL pointers
    total_number_of_pages = calloc(total_number_of_shelves, sizeof(int *));

    int total_number_of_queries;
    scanf("%d", &total_number_of_queries);

    while (total_number_of_queries--) {
        int type_of_query;
        scanf("%d", &type_of_query);

        if (type_of_query == 1) {
            int x, y;
            scanf("%d %d", &x, &y);

            total_number_of_books[x] += 1;
            if (total_number_of_books[x] == 1) {
                total_number_of_pages[x] = malloc(1 * sizeof(int));
            }
            else {
                total_number_of_pages[x] = realloc(total_number_of_pages[x], total_number_of_books[x] * sizeof(int));
            }

            if (!total_number_of_pages[x]) {
                printf("Memory allocation failed!\n");
                exit(1);
            }

            total_number_of_pages[x][total_number_of_books[x] - 1] = y;
        }
        else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        }
        else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }

    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }

    if (total_number_of_pages) {
        free(total_number_of_pages);
    }

    return 0;
}
