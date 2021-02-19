#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_rows, num_cols;
    std::cin >> num_rows >> num_cols;

    std::vector<std::vector<int>> toy(num_rows + 2, std::vector<int>(num_cols + 2, 0));
    for (int row = 1; row < num_rows + 1; ++row) {
        for (int col = 1; col < num_cols + 1; ++col) {
            std::cin >> toy[row][col];
        }
    }

    // initialize the total area to the area of the top and bottom of the toy
    int total_area = 2 * num_rows * num_cols;
    for (int row = 1; row < num_rows + 2; ++row) {
        for (int col = 1; col < num_cols + 2; ++col) {
            total_area += std::abs(toy[row][col] - toy[row - 1][col]) +
                          std::abs(toy[row][col] - toy[row][col - 1]);
        }
    }

    fout << total_area << "\n";
    fout.close();

    return 0;
}
