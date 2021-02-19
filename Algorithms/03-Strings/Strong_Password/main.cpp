#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::set<char> special_chars{'!', '@', '#', '$', '%', '^', '&', '*', '(',
                                 ')', '-', '+'};

    bool has_number = false;
    bool has_lowercase = false;
    bool has_uppercase = false;
    bool has_special = false;

    int length;
    std::cin >> length;

    std::string s;
    std::cin >> s;

    for (char const &c : s) {
        if (std::isdigit(c)) {
            has_number = true;
        }
        else if (std::islower(c)) {
            has_lowercase = true;
        }
        else if (std::isupper(c)) {
            has_uppercase = true;
        }
        else if (special_chars.count(c)) {
            has_special = true;
        }

        if (has_number && has_lowercase && has_uppercase && has_special) {
            break;
        }
    }

    int num_extra_chars = (has_number ? 0 : 1) + (has_lowercase ? 0 : 1) +
                          (has_uppercase ? 0 : 1) + (has_special ? 0 : 1);

    num_extra_chars += std::max<int>(0, 6 - (length + num_extra_chars));

    fout << num_extra_chars << "\n";

    fout.close();
    return 0;
}
