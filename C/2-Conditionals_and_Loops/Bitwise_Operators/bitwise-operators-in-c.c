#include <stdio.h>

int main() {
    int size, max_val;
    scanf("%d %d ", &size, &max_val);

    int and_max, or_max, xor_max;
    and_max = or_max = xor_max = 0;
    for (int i = 1; i < size; ++i) {
        for (int j = i + 1; j <= size; ++j) {
            int and_val = i & j;
            int or_val = i | j;
            int xor_val = i ^ j;

            if (and_val < max_val && and_val > and_max) {
                and_max = and_val;
            }
            if (or_val < max_val && or_val > or_max) {
                or_max = or_val;
            }
            if (xor_val < max_val && xor_val > xor_max) {
                xor_max = xor_val;
            }
        }
    }

    printf("%d\n%d\n%d\n", and_max, or_max, xor_max);

    return 0;
}
