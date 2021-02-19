#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    size_t length;
    std::cin >> length;

    long total_cash;
    std::cin >> total_cash;

    std::vector<long> prices(length);
    for (long &price : prices) {
        std::cin >> price;
    }

    std::sort(std::begin(prices), std::end(prices));

    long current_sum = 0;
    size_t count_toys = 0;

    while (current_sum <= total_cash) {
        current_sum += prices[count_toys];
        count_toys++;
    }

    // don't count the toy whose price passed the total_cash
    std::cout << count_toys - 1;

    return 0;
}
