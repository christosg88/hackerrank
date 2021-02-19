#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
std::ostream &operator<<(std::ostream &stream, std::vector<T> const &vec) {
    for (int i = 0, last = vec.size() - 1; i < last; ++i) {
        stream << vec[i] << ' ';
    }
    stream << vec.back() << '\n';

    return stream;
}

int main() {
    int size;
    std::cin >> size;

    std::vector<int> nums(size);
    for (auto &num : nums) {
        std::cin >> num;
    }

    std::sort(std::begin(nums), std::end(nums));

    std::cout << nums;

    return 0;
}
