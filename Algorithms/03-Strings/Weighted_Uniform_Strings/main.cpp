#include <iostream>
#include <fstream>
#include <string>
#include <set>

int get_weight(char const c) {
    return c - 'a' + 1;
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string s;
    std::cin >> s;

    std::set<int> weights;
    char last_char = s[0];
    int count = 1;

    auto it = std::next(s.begin());
    while (it != s.end()) {
        if (*it == last_char) {
            // count the number of consecutive same characters
            count++;
        }
        else {
            // add the weights of the consecutive characters to the set
            int weight = get_weight(last_char);
            for (int i = 1; i <= count; ++i) {
                weights.insert(i * weight);
            }

            count = 1;
            last_char = *it;
        }
        std::advance(it, 1);
    }

    // add the weights of the last consecutive characters to the set
    int weight = get_weight(last_char);
    for (int i = 1; i <= count; ++i) {
        weights.insert(i * weight);
    }

    int num_queries;
    std::cin >> num_queries;

    while (num_queries--) {
        int query;
        std::cin >> query;

        if (weights.count(query)) {
            fout << "Yes\n";
        }
        else {
            fout << "No\n";
        }
    }

    fout.close();

    return 0;
}
