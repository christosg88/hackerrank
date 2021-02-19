#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int num_toys;
    std::cin >> num_toys;

    std::vector<int> toy_weights(num_toys);
    for (auto &toy_weight : toy_weights) {
        std::cin >> toy_weight;
    }

    std::sort(std::begin(toy_weights), std::end(toy_weights));

    int min_containers = 0;
    auto it = std::begin(toy_weights);
    while (it != std::end(toy_weights)) {
        min_containers++;
        int min_weight = *it;
        ++it;

        while (it != std::end(toy_weights) && *it - min_weight <= 4) {
            ++it;
        }
    }

    std::cout << min_containers << '\n';

    return 0;
}
