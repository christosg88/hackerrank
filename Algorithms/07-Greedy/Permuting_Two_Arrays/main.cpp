#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int testcases;
    std::cin >> testcases;

    std::vector<int> nums1, nums2;
    while (testcases--) {
        int length, minimum_sum;
        std::cin >> length >> minimum_sum;

        nums1.resize(length);
        nums2.resize(length);

        for (int &num : nums1) {
            std::cin >> num;
        }

        for (int &num : nums2) {
            std::cin >> num;
        }

        std::sort(std::begin(nums1), std::end(nums1), std::less<>());
        std::sort(std::begin(nums2), std::end(nums2), std::greater<>());

        bool possible = true;
        for (int i = 0; i < length; ++i) {
            if (nums1[i] + nums2[i] < minimum_sum) {
                possible = false;
                break;
            }
        }

        if (possible) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
