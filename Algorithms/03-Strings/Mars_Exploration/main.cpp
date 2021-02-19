#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string s;
    std::cin >> s;
    int length = s.length();

    int count_mistakes = 0;
    for (int i = 0; i < length; i += 3) {
        if (s[i] != 'S') {
            count_mistakes++;
        }
        if (s[i + 1] != 'O') {
            count_mistakes++;
        }
        if (s[i + 2] != 'S') {
            count_mistakes++;
        }
    }

    fout << count_mistakes << "\n";

    fout.close();
    return 0;
}
