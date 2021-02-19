#include <iostream>
#include <vector>
#include <map>

int main() {
    int size, max_swaps;
    std::cin >> size >> max_swaps;

    std::vector<int> nums(size);
    for (auto &num : nums) {
        std::cin >> num;
    }

    // create a map from value to index
    std::map<int, int, std::greater<>> val_to_idx;
    for (int i = 0; i < size; ++i) {
        val_to_idx[nums[i]] = i;
    }

    int num_swaps = 0;
    int swap_idx = 0;
    for (auto &val_idx : val_to_idx) {
        if (num_swaps >= max_swaps) {
            break;
        }

        if (val_idx.second != swap_idx) {
            // swap the values
            std::swap(nums[val_idx.second], nums[swap_idx]);

            // swap the indexes of the swapped values
            // not-needed
            // val_to_idx[nums[swap_idx]] = swap_idx;
            val_to_idx[nums[val_idx.second]] = val_idx.second;

            ++num_swaps;
        }
        ++swap_idx;
    }

    for (auto &num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}
