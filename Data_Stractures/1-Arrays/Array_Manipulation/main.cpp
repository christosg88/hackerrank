#include <iostream>
#include <vector>

int main() {
    size_t length, num_operations;
    std::cin >> length >> num_operations;

    // instead of keeping the array itself, we will keep at each index, how much of an increment/decrement from this
    // index and later was introduced
    std::vector<size_t> ups_and_downs(length);

    while (num_operations--) {
        size_t left_index, right_index, increment;
        std::cin >> left_index >> right_index >> increment;
        left_index--; right_index--;    // turn to zero based

        ups_and_downs[left_index] += increment;
        ups_and_downs[right_index + 1] -= increment;
    }

    // now incrementally sum the array, and find the maximum value
    size_t current_sum = 0;
    size_t max = 0;
    for (size_t i = 0; i < length; ++i) {
        current_sum += ups_and_downs[i];
        if (current_sum > max) {
            max = current_sum;
        }
    }

    std::cout << max << '\n';

    return 0;
}
