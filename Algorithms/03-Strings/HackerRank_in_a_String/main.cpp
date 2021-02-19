#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int queries;
    std::cin >> queries;

    std::string target_str("hackerrank");

    while (queries--) {
        std::string s;
        std::cin >> s;
        int length = s.length();

        std::map<char, std::list<int>> char_indexes;
        for (int idx = 0; idx < length; ++idx) {
            char_indexes[s[idx]].push_back(idx);
        }

        bool substring_exists = true;
        int last_idx = -1;
        for (char const &c : target_str) {
            auto upper_bound_it = std::upper_bound(char_indexes[c].begin(), char_indexes[c].end(), last_idx);
            if (upper_bound_it == char_indexes[c].end()) {
                substring_exists = false;
                break;
            }
            last_idx = *upper_bound_it;
        }

        if (substring_exists) {
            fout << "YES\n";
        }
        else {
            fout << "NO\n";
        }
    }

    fout.close();
    return 0;
}
