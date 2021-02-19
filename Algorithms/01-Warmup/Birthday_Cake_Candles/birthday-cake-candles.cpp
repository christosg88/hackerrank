#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);

    size_t size;
    std::cin >> size;

    unsigned int max_height = 0;
    // the maximum height of the candles

    unsigned int num_candles = 0;
    // number of candles with the maximum height

    for (size_t i = 0; i < size; i++) {
        unsigned int height;
        std::cin >> height;

        if (height > max_height) {
            max_height = height;
            num_candles = 1;
        }
        else if (height == max_height) {
            num_candles++;
        }
    }

    std::cout << num_candles << '\n';

    return 0;
}
