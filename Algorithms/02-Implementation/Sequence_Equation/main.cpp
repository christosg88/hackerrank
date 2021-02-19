#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> val_to_index(std::vector<int> &nums) {
    std::vector<int> nums_cpy(nums.size());
    int nums_size = nums.size();

    for (int i = 0; i < nums_size; ++i) {
        nums_cpy[nums[i] - 1] = i + 1;
    }

    return nums_cpy;
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_nums;
    std::cin >> num_nums;

    std::vector<int> nums(num_nums);
    for (int &num : nums) {
        std::cin >> num;
    }

    std::vector<int> indexes = val_to_index(nums);
    for (int i = 0; i < num_nums; ++i) {
        fout << indexes[indexes[i] - 1] << "\n";
    }
    fout.close();

    return 0;
}
