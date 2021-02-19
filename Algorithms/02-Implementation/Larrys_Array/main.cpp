#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    std::cin >> tests;

    for (int test = 0; test < tests; ++test) {
        int length;
        std::cin >> length;

        int nums[length];
        for (int &num : nums) {
            std::cin >> num;
        }

        // the count of inversions is equal to the number of pairs i, j with i < j and nums[i] > nums[j]
        // src: https://en.wikipedia.org/wiki/Parity_of_a_permutation
        int count_inversions = 0;
        for (int i = 0; i < length - 1; ++i) {
            for (int j = i + 1; j < length; ++j) {
                if (nums[i] > nums[j]) {
                    count_inversions++;
                }
            }
        }

        if (count_inversions % 2) {
            fout << "NO\n";
        }
        else {
            fout << "YES\n";
        }
    }

    fout.close();

    return 0;
}
