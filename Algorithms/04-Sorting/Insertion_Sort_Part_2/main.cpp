#include <iostream>
#include <vector>

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

    for (int j = 2; j <= size; ++j) {
        int inserted = nums[j - 1];
        int i = j - 2;
        while (i >= 0 && nums[i] > inserted) {
            nums[i + 1] = nums[i];
            --i;
        }
        nums[i + 1] = inserted;
        std::cout << nums;
    }

    return 0;
}
