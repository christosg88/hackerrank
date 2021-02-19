#include <iostream>

int main() {
    int testcases;
    std::cin >> testcases;

    while (testcases--) {
        std::string s;
        std::cin >> s;

        size_t length = s.length();
        bool is_sequence = false;
        unsigned long long first_num;
        for (size_t first_num_length = 1; first_num_length <= length / 2; ++first_num_length) {
            unsigned long long current_num = first_num = std::stoull(s.substr(0, first_num_length));
            std::string result;
            while (result.length() < length) {
                result += std::to_string(current_num);
                size_t result_length = result.length();
                current_num += 1;

                if (s.compare(0, result_length, result, 0, result_length)) {
                    break;
                }
            }

            if (result == s) {
                is_sequence = true;
                break;
            }
        }

        if (is_sequence) {
            std::cout << "YES " << first_num << "\n";
        }
        else {
            std::cout << "NO\n";
        }

    }

    return 0;
}
