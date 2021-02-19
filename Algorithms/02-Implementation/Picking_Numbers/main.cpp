#include <iostream>
#include <fstream>
#include <map>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_nums;
    std::cin >> num_nums;

    std::map<int, int> num_count_map;
    for (int i = 0; i < num_nums; ++i) {
        int num;
        std::cin >> num;

        num_count_map[num]++;
    }


    std::map<int, int>::iterator it, next_it;
    it = num_count_map.begin();
    next_it = std::next(it);
    int max_length = it->second;

    while (next_it != num_count_map.end()) {
        if (next_it->first - it->first <= 1) {
            int length = it->second + next_it->second;
            if (length > max_length) {
                max_length = length;
            }
        }
        else {
            if (next_it->second > max_length) {
                max_length = next_it->second;
            }
        }

        it = next_it;
        std::advance(next_it, 1);
    }

    fout << max_length << "\n";

    fout.close();
    return 0;
}
