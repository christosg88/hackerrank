#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int length;
    std::cin >> length;

    std::vector<int> calories(length);
    for (int &calorie : calories) {
        std::cin >> calorie;
    }

    std::sort(std::begin(calories), std::end(calories), std::greater<>());

    unsigned long mul = 1;
    unsigned long total_calories = 0;

    for (int const &calorie : calories) {
        total_calories += mul * calorie;
        mul <<= 1;
    }

    std::cout << total_calories << '\n';
    return 0;
}
