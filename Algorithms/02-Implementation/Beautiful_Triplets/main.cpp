#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_nums, difference;
    std::cin >> num_nums >> difference;

    std::vector<int> nums(num_nums);
    for (int &num : nums) {
        std::cin >> num;
    }

    int count_triplets = 0;
    for (int i = 0; i < num_nums - 2; ++i) {
        for (int j = i + 1; j < num_nums - 1; ++j) {
            if (nums[j] - nums[i] != difference) {
                continue;
            }

            for (int k = j + 1; k < num_nums; ++k) {
                if (nums[k] - nums[j] != difference) {
                    continue;
                }

                count_triplets++;
            }
        }
    }

    fout << count_triplets << "\n";
    fout.close();

    return 0;
}
