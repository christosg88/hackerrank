#include <sstream>
#include <vector>
#include <iostream>

std::vector<int> parseInts(const std::string &str) {
    std::vector<int> nums;
    std::stringstream ss(str);

    int num;
    while (ss >> num) {
        nums.push_back(num);
        // remove the following comma
        ss.get();
    }

    return nums;
}

int main() {
    std::string str;
    std::cin >> str;

    std::vector<int> nums = parseInts(str);
    for (auto &num : nums) {
        std::cout << num << "\n";
    }

    return 0;
}
