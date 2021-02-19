#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int length;
    std::cin >> length;

    std::vector<std::string> str_nums(length);
    for (std::string &s : str_nums) {
        std::cin >> s;
    }

    std::sort(str_nums.begin(), str_nums.end(), [](const std::string &s_a, const std::string &s_b) {
        int length_a = s_a.length();
        int length_b = s_b.length();
        if (length_a == length_b) {
            for (int i = 0; i < length_a; ++i) {
                if (s_a[i] == s_b[i]) {
                    continue;
                }
                return s_a[i] < s_b[i];
            }
        }
        return length_a < length_b;
    });

    for (std::string &s : str_nums) {
        fout << s << "\n";
    }

    fout.close();
    return 0;
}
