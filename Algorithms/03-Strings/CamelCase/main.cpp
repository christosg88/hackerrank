#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string s;
    std::cin >> s;

    int num_uppercase = 0;
    for (char const &c : s) {
        if (c >= 'A' && c <= 'Z') {
            num_uppercase++;
        }
    };

    fout << (s.empty() ? 0 : 1) + num_uppercase << "\n";

    fout.close();
    return 0;
}
