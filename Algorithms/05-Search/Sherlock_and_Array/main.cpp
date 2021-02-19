#include <iostream>
#include <fstream>
#include <numeric>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int test_cases;
    std::cin >> test_cases;

    while (test_cases--) {
        int length;
        std::cin >> length;

        int nums[length];
        for (int &num : nums) {
            std::cin >> num;
        }

        bool can_be_split = false;

        if (length <= 1) {
            can_be_split = true;
        }
        else {
            size_t right_sum = std::accumulate(nums + 1, nums + length, 0llu);
            size_t left_sum = nums[0];

            for (int i = 1; i < length - 1; ++i) {
                right_sum -= nums[i];

                if (left_sum == right_sum) {
                    can_be_split = true;
                    break;
                }

                left_sum += nums[i];
            }
        }

        if (can_be_split) {
            fout << "YES\n";
        }
        else {
            fout << "NO\n";
        }
    }

    fout.close();

    return 0;
}
