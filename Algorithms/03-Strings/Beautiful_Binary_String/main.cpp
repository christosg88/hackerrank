#include <iostream>

int main() {
    size_t length;
    std::cin >> length;

    std::string s;
    std::cin >> s;

    // count the non overlapping 010
    unsigned int count = 0;
    std::string target("010");
    for (unsigned int i = 0; i < length; ++i) {
        if (s.substr(i, 3) == target) {
            ++count;
            i += 2;
        }
    }

    std::cout << count << "\n";

    return 0;
}
