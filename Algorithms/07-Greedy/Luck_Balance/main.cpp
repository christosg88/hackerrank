#include <vector>

#include <iostream>
#include <algorithm>

int main() {
    int num_contests, num_max_important_lose;
    std::cin >> num_contests >> num_max_important_lose;

    int count_total_luck = 0;
    std::vector<int> important_lucks;
    for (int i = 0; i < num_contests; ++i) {
        int luck, importance;
        std::cin >> luck >> importance;

        if (importance) {
            important_lucks.push_back(luck);
        }

        count_total_luck += luck;
    }

    std::sort(std::begin(important_lucks), std::end(important_lucks), std::greater<>());

    auto it = std::next(std::begin(important_lucks), std::min<int>(num_max_important_lose, important_lucks.size()));
    while (it != std::end(important_lucks)) {
        count_total_luck -= 2 * (*it);
        it++;
    }

    std::cout << count_total_luck << '\n';

    return 0;
}
