#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int init_price, price_reduction, limit, cash;
    std::cin >> init_price >> price_reduction >> limit >> cash;

    int count_games = 0;
    int current_price = init_price;

    while (current_price <= cash) {
        cash -= current_price;
        count_games++;

        current_price = std::max(current_price - price_reduction, limit);
    }

    fout << count_games << "\n";
    fout.close();

    return 0;
}
