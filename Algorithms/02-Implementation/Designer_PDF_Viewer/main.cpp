#include <iostream>
#include <fstream>
#include <set>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int heights[26];
    for (int &height : heights) {
        std::cin >> height;
    }

    std::string str;
    std::cin >> str;

    std::set<char> char_set(str.begin(), str.end());

    int max_height = 0;
    for (const char &c : char_set) {
        if (heights[c - 'a'] > max_height) {
            max_height = heights[c - 'a'];
        }
    }

    int area = max_height * str.length();

    fout << area << "\n";
    fout.close();

    return 0;
}
