#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

int count_max_alternates(std::list<int> indexes1, std::list<int> indexes2) {
    int length1 = indexes1.size();
    int length2 = indexes2.size();

    // if they two indexes lists have a difference of number of elements greater
    // than 1, it's impossible to have a perfect alternation
    if (std::abs(length1 - length2) > 1) {
        return 0;
    }

    // the top iterator is the one iterating the list which has the smallest
    // element
    std::list<int>::iterator top_begin, top_end, bot_begin, bot_end;
    if (indexes1.front() < indexes2.front()) {
        if (length1 < length2) {
            return 0;
        }
        top_begin = indexes1.begin();
        top_end = indexes1.end();
        bot_begin = indexes2.begin();
        bot_end = indexes2.end();
    }
    else {
        if (length2 < length1) {
            return 0;
        }
        top_begin = indexes2.begin();
        top_end = indexes2.end();
        bot_begin = indexes1.begin();
        bot_end = indexes1.end();
    }

    auto top_it = top_begin;
    auto bot_it = bot_begin;
    while (bot_it != bot_end) {
        if (*top_it > *bot_it) {
            return 0;
        }
        std::advance(top_it, 1);
        std::advance(bot_it, 1);
    }

    top_it = std::next(top_begin);
    bot_it = bot_begin;
    while (top_it  != top_end) {
        if (*top_it < *bot_it) {
            return 0;
        }
        std::advance(top_it, 1);
        std::advance(bot_it, 1);
    }

    return length1 + length2;
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int length;
    std::cin >> length;

    std::string s;
    std::cin >> s;

    std::map<char, std::list<int>> char_indexes;
    for (int i = 0; i < length; ++i) {
        char_indexes[s[i]].push_back(i);
    }

    int max_alternates = 0;
    auto it1 = char_indexes.begin();
    auto it1_end = std::prev(char_indexes.end(), 1);
    while (it1 != it1_end) {
        auto it2 = std::next(it1);
        while (it2 != char_indexes.end()) {
            int alternates = count_max_alternates(it1->second, it2->second);
            if (alternates > max_alternates) {
                max_alternates = alternates;
            }
            std::advance(it2, 1);
        }
        std::advance(it1, 1);
    }

    fout << max_alternates << "\n";

    fout.close();
    return 0;
}
