#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_nums;
    std::cin >> num_nums;

    std::map<int, int> num_count;
    for (int i = 0; i < num_nums; ++i) {
        int num;
        std::cin >> num;
        num_count[num]++;
    }

    int max_count = std::max_element(num_count.begin(), num_count.end(),
            [](const auto &l, const auto &r) {
        return l.second < r.second;
    })->second;

    fout << num_nums - max_count << "\n";
    fout.close();

    return 0;
}
