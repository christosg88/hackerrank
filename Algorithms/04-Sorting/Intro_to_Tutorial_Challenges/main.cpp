#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int needle;
    std::cin >> needle;

    size_t length;
    std::cin >> length;
    std::vector<int> nums(length);
    for (auto &num : nums) {
        std::cin >> num;
    }

    auto needle_index = std::lower_bound(std::begin(nums), std::end(nums), needle);
    std::cout << std::distance(std::begin(nums), needle_index) << "\n";

    return 0;
}
