#include <iostream>

#include <vector>
#include <algorithm>

int main() {
    int testcases;
    std::cin >> testcases;

    for (int t = 0; t < testcases; ++t) {
        int size;
        std::cin >> size;

        std::vector<std::vector<char>> grid(size, std::vector<char>(size));
        for (auto &row : grid) {
            for (auto &c : row) {
                std::cin >> c;
            }
        }

        for (auto &row : grid) {
            std::sort(std::begin(row), std::end(row));
        }

        bool ascending_rows = true;
        for (int row = 1; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (grid[row][col] < grid[row-1][col]) {
                    ascending_rows = false;
                    goto print_output;
                }
            }
        }

        print_output:
        if (ascending_rows) {
            std::cout << "YES\n";
        }
        else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
