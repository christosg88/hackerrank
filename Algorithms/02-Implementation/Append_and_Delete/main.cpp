#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    std::string init_s, final_s;
    std::cin >> init_s >> final_s;

    int max_num_operations;
    std::cin >> max_num_operations;

    // compute the number of deletions on the initial string, to make
    // it equal to the beginning substring of the final_s
    int count_same_characters = 0;
    int min_length = std::min(init_s.length(), final_s.length());

    for (int i = 0; i < min_length; ++i) {
        if (init_s[i] != final_s[i]) {
            break;
        }
        ++count_same_characters;
    }

    int num_deletions = init_s.length() - count_same_characters;

    // compute the number of appends on the beginning substring, to make it
    // equal to the final string
    int num_appends = final_s.length() - count_same_characters;

    // we can perform more deletions, but for each deletion another append
    // must be performed, unless the initial string is reduced to the empty
    // string, and then no additional append has to be performed for each
    // deletion
    int remaining_operations = max_num_operations - num_deletions - num_appends;
    int init_s_length = init_s.length();
    if (remaining_operations >= 0
        && (remaining_operations % 2 == 0
            || num_deletions + remaining_operations / 2 >= init_s_length)) {
        fout << "Yes\n";
    }
    else {
        fout << "No\n";
    }

    fout.close();

    return 0;
}
