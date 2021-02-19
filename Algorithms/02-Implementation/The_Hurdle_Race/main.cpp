#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_hurdles, max_jump;
    std::cin >> num_hurdles >> max_jump;

    int max_height = 0;
    for (int i = 0; i < num_hurdles; ++i) {
        int height;
        std::cin >> height;

        if (height > max_height) {
            max_height = height;
        }
    }

    int num_potions = std::max(0, max_height - max_jump);
    fout << num_potions << "\n";
    fout.close();

    return 0;
}
