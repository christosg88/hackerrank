#include <iostream>
#include <vector>
#include <map>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int length1;
    std::cin >> length1;
    std::map<int, int> val_count_1;
    for (int i = 0; i < length1; ++i) {
        int val;
        std::cin >> val;

        val_count_1[val]++;
    }

    int length2;
    std::cin >> length2;
    std::map<int, int> val_count_2;
    for (int i = 0; i < length2; ++i) {
        int val;
        std::cin >> val;

        val_count_2[val]++;
    }

    // find the values in the second map, missing from the first map. Each
    // number can show up many times, but even if one is missing, it must be
    // printed, but only once
    auto it_1 = val_count_1.begin();
    auto it_2 = val_count_2.begin();
    std::vector<int> missing_values;

    while (it_1 != val_count_1.end() && it_2 != val_count_2.end()) {
        if (it_1->first == it_2->first) {
            if (it_1->second < it_2->second) {
                missing_values.push_back(it_2->first);
            }
            std::advance(it_1, 1);
            std::advance(it_2, 1);
        }
        else {
            missing_values.push_back(it_2->first);
            std::advance(it_2, 1);
        }
    }

    // add the remaining values from the second map
    while (it_2 != val_count_2.end()) {
        missing_values.push_back(it_2->first);
        std::advance(it_2, 1);
    }

    // print the missing values sepparated by space
    for (int i = 0; i < missing_values.size() - 1; ++i) {
        fout << missing_values[i] << " ";
    }
    fout << missing_values.back() << "\n";
    fout.close();

    return 0;
}
