#include <iostream>

int main() {
    int current_level = 0;
    int valleys_count = 0;

    int length;
    std::cin >> length;

    for (int i = 0; i < length; ++i) {
        char c;
        std::cin >> c;

        if (c == 'U') {
            current_level++;
        }
        else {
            if (current_level == 0) {
                valleys_count++;
            }
            current_level--;
        }
    }

    std::cout << valleys_count << "\n";

    return 0;
}
