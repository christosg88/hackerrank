#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int main() {
    int num_customers;
    std::cin >> num_customers;

    // (serve_time, customer_number)
    // serve_time == order_number + preparation_time
    std::vector<std::pair<int, int>> serve_order;

    for (int customer_number = 1; customer_number <= num_customers; ++customer_number) {
        int order_number, preparation_time;
        std::cin >> order_number >> preparation_time;
        serve_order.emplace_back(order_number + preparation_time, customer_number);
    }

    std::sort(std::begin(serve_order), std::end(serve_order), [](auto const &a, auto const &b) {
        if (std::get<0>(a) < std::get<0>(b) || ((std::get<0>(a) == std::get<0>(b)) && (std::get<1>(a) < std::get<1>(b)))) {
            return true;
        }
        else {
            return false;
        }
    });

    for (auto const &customer : serve_order) {
        std::cout << std::get<1>(customer) << " ";
    }
    std::cout << "\n";

    return 0;
}
