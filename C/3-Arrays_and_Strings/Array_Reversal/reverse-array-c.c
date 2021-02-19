#include <stdio.h>
#include <stdlib.h>

void reverse_array(int length, int *nums) {
    for (int i = 0; i < length / 2; ++i) {
        int tmp = nums[i];
        nums[i] = nums[length - 1 - i];
        nums[length - 1 - i] = tmp;
    }
}

int main() {
    int length;
    scanf("%d", &length);

    int *nums = malloc(length * sizeof(int));
    if (!nums) {
        printf("Couldn't allocate memory! Exiting...\n");
        return 1;
    }

    for (int i = 0; i < length; ++i) {
        scanf("%d", nums + i);
    }

    reverse_array(length, nums);

    for (int i = 0; i < length; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    free(nums);

    return 0;
}
