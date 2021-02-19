#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int length;
    std::cin >> length;

    std::vector<int> nums(length);
    for (int &num : nums) {
        std::cin >> num;
    }

    std::sort(std::begin(nums), std::end(nums), std::greater<>());

    int min_abs_diff = nums[0] - nums[1];
    for (int i = 1; i < length - 1; ++i) {
        min_abs_diff = std::min(min_abs_diff, nums[i] - nums[i + 1]);
    }

    std::cout << min_abs_diff << '\n';
    return 0;
}
