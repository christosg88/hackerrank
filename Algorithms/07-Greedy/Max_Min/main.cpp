#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int length;
    std::cin >> length;

    int subarray_length;
    std::cin >> subarray_length;

    std::vector<long> numbers(length);
    for (long &number : numbers) {
        std::cin >> number;
    }

    std::sort(std::begin(numbers), std::end(numbers));

    long min_diff = std::numeric_limits<long>::max();
    auto it_first = std::begin(numbers);
    auto it_last = std::next(std::begin(numbers), subarray_length - 1);
    while (it_last != std::end(numbers)) {
        long diff = *it_last - *it_first;
        if (diff < min_diff) {
            min_diff = diff;
        }

        ++it_first;
        ++it_last;
    }

    std::cout << min_diff << '\n';

    return 0;
}
