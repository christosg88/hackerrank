#include <iostream>
#include <vector>

int main() {
    int length, rotations, queries;
    std::cin >> length >> rotations >> queries;

    // read the numbers in the vector
    std::vector<int> nums(length);
    for (int &num : nums) {
        std::cin >> num;
    }

    // the rotations should be modulo the length of the list, since for a list
    // of 3 numbers, 3 rotations and 0 rotations are the same.
    rotations = rotations % length;

    // the new start in the array
    int start = length - rotations;

    for (int i = 0; i < queries; ++i) {
        int query;
        std::cin >> query;
        std::cout << nums[(start + query) % length] << "\n";
    }

    return 0;
}
