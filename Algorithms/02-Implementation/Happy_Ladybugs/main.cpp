#include <iostream>
#include <fstream>
#include <map>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_games;
    std::cin >> num_games;

    for (int game = 0; game < num_games; ++game) {
        int num_chars;
        std::cin >> num_chars;

        std::string s;
        std::cin >> s;

        if (num_chars == 1 && s != "_") {
            fout << "NO\n";
            continue;
        }

        // if each ladybug already has another same color ladybug next to it,
        // they are all happy
        bool happy_ladybugs = true;
        for (int i = 0; i < num_chars; ++i) {
            if (s[i] == '_') {
                continue;
            }

            if (i == 0 && s[0] != s[1]) {
                happy_ladybugs = false;
                break;
            }
            else if (i == num_chars - 1 &&
                     s[num_chars - 1] != s[num_chars - 2]) {
                happy_ladybugs = false;
                break;
            }
            else if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
                happy_ladybugs = false;
                break;
            }
        }

        if (happy_ladybugs) {
            fout << "YES\n";
            continue;
        }

        // check if we can move them next to each other and make them happy
        std::map<char, int> char_count;
        for (char &ch : s) {
            char_count[ch]++;
        }

        happy_ladybugs = true;
        if (char_count['_'] == 0) {
            happy_ladybugs = false;
        }
        else {
            for (auto &pair : char_count) {
                if (pair.first != '_' && pair.second == 1) {
                    happy_ladybugs = false;
                    break;
                }
            }
        }

        if (happy_ladybugs) {
            fout << "YES\n";
        }
        else {
            fout << "NO\n";
        }
    }

    fout.close();

    return 0;
}
