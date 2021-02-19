#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int test_cases;
    std::cin >> test_cases;

    next_test_case:
    while (test_cases--) {
        int money, num_flavors;
        std::cin >> money >> num_flavors;

        int prices[num_flavors];
        for (int &price : prices) {
            std::cin >> price;
        }

        for (int i = 0; i < num_flavors - 1; ++i) {
            for (int j = i + 1; j < num_flavors; ++j) {
                if (prices[i] + prices[j] == money) {
                    fout << i + 1 << " " << j + 1 << "\n";
                    goto next_test_case;
                }
            }
        }
    }

    fout.close();

    return 0;
}
