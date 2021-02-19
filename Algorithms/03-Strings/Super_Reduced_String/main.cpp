#include <iostream>
#include <fstream>
#include <stack>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string s;
    std::cin >> s;

    std::deque<char> char_deque;
    for (auto &c : s) {
        if (char_deque.empty() || c != char_deque.back()) {
            char_deque.push_back(c);
        }
        else {
            char_deque.pop_back();
        }
    }

    if (char_deque.empty()) {
        fout << "Empty String\n";
    }
    else {
        for (auto &c : char_deque) {
            fout << c;
        }
        fout << "\n";
    }

    fout.close();
    return 0;
}
