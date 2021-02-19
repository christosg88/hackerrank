#include <iostream>
#include <vector>

int main() {
    int size;
    std::cin >> size;

    std::vector<int> nums(size);
    for (auto &num : nums) {
        std::cin >> num;
    }

    int count_swaps = 0;
    for (int i = 1; i < size; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (nums[i] < nums[j]) {
                ++count_swaps;
            }
        }
    }

    std::cout << count_swaps << "\n";

    return 0;
}
