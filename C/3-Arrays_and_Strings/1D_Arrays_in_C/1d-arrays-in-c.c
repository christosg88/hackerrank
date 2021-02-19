#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d ", &size);

    int *nums = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        scanf("%d ", nums + i);
    }

    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
    }

    printf("%d\n", sum);

    free(nums);

    return 0;
}
