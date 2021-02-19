/**
 * The problem should be stated like so:
 * k people need to buy n items.
 * Given the price for each item, and the fact that each item's price, when bought by person p increases by as much as
 * p's previous purchases, minimize the total cost to buy all items.
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num_items, num_people;
    std::cin >> num_items >> num_people;

    std::vector<int> prices(num_items);
    for (int &price : prices) {
        std::cin >> price;
    }

    // sort in descending order, so the most expensive items are bought first
    std::sort(std::begin(prices), std::end(prices), std::greater<>());

    int total_cost = 0;
    int loop_count = -1;

    for (int i = 0; i < num_items; ++i) {
        if (i % num_people == 0) {
            loop_count++;
        }

        total_cost += (1 + loop_count) * prices[i];
    }

    std::cout << total_cost << '\n';

    return 0;
}
