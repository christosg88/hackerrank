#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int budget, num_keyboards, num_drives;
    std::cin >> budget >> num_keyboards >> num_drives;

    int keyboards[num_keyboards];
    int drives[num_drives];

    for (int i = 0; i < num_keyboards; ++i) {
        std::cin >> keyboards[i];
    }

    for (int i = 0; i < num_drives; ++i) {
        std::cin >> drives[i];
    }

    std::sort(keyboards, keyboards + num_keyboards, std::greater<>());
    std::sort(drives, drives + num_drives);

    int max_sum = -1;
    for (int keyboard_idx = 0, drive_idx = 0; keyboard_idx < num_keyboards; ++keyboard_idx) {
        for (; drive_idx < num_drives; ++drive_idx) {
            int price_sum = keyboards[keyboard_idx] + drives[drive_idx];

            if (price_sum > budget) {
                break;
            }
            else if (price_sum > max_sum) {
                max_sum = price_sum;
            }
        }
    }

    fout << max_sum << "\n";

    fout.close();
    return 0;
}
