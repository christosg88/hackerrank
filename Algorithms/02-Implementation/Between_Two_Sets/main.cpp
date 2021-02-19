#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int len1, len2;
    std::cin >> len1 >> len2;

    int nums1[len1];
    int nums2[len2];

    for (int i = 0; i < len1; ++i) {
        std::cin >> nums1[i];
    }

    for (int i = 0; i < len2; ++i) {
        std::cin >> nums2[i];
    }

    int num_between = 0;
    for (int num = nums1[len1 - 1]; num <= nums2[0]; ++num) {
        bool is_between = true;

        for (int &num1 : nums1) {
            if (num % num1) {
                is_between = false;
                break;
            }
        }

        if (!is_between) {
            continue;
        }

        for (int &num2 : nums2) {
            if (num2 % num) {
                is_between = false;
                break;
            }
        }

        if (is_between) {
            num_between++;
        }
    }

    fout << num_between << "\n";
    fout.close();

    return 0;
}
