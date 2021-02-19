#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    bool is_possible = false;
    std::string message;

    int length;
    std::cin >> length;

    // reserve memory for the values, +2 for sentinels at the edges
    std::vector<int> vals(length + 2);
    vals[0] = std::numeric_limits<int>::min();
    vals[length + 1] = std::numeric_limits<int>::max();
    for (int i = 1; i < length + 1; ++i) {
        std::cin >> vals[i];
    }

    if (std::is_sorted(vals.begin(), vals.end())) {
        // if the array is already sorted, output "yes" and nothing more
        is_possible = true;
        message = "already sorted\n";
    }
    else {
        // vals[i - 1] > vals[i] < vals[i + 1]
        std::vector<int> valleys;
        // vals[i - 1] < vals[i] > vals[i + 1]
        std::vector<int> hills;

        for (int i = 1; i < length + 1; ++i) {
            if (vals[i - 1] > vals[i] && vals[i] < vals[i + 1]) {
                valleys.push_back(i);
            }
            else if (vals[i - 1] < vals[i] && vals[i] > vals[i + 1]) {
                hills.push_back(i);
            }
        }

        if (!(valleys.empty() && hills.empty())) {
            int l = *hills.begin();
            int r = *std::prev(valleys.end());

            // swap the first hill with the last valley, and check if the
            // array is not sorted
            std::swap(vals[l], vals[r]);
            if (std::is_sorted(vals.begin(), vals.end())) {
                is_possible = true;
                message = "swap " + std::to_string(l) + " " + std::to_string(r) + "\n";
            }
            else {
                // if not sorted, swap the values back to their original
                // locations, and reverse the whole range [l, r]
                std::swap(vals[l], vals[r]);
                std::reverse(std::next(vals.begin(), l),
                             std::next(vals.begin(), r + 1));

                if (std::is_sorted(vals.begin(), vals.end())) {
                    is_possible = true;
                    message = "reverse " + std::to_string(l) + " " + std::to_string(r) + "\n";
                }
            }
        }
    }

    if (is_possible) {
        fout << "yes\n";
        fout << message;
    }
    else {
        fout << "no\n";
    }

    fout.close();

    return 0;
}
