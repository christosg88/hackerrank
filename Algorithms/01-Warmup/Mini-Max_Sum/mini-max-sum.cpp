#include <iostream>
#include <limits>

typedef unsigned long long ull;

int main()
{
    std::ios::sync_with_stdio(false);

    size_t size = 5;
    ull sum = 0;
    ull min = std::numeric_limits<ull>::max();
    ull max = std::numeric_limits<ull>::min();

    for (size_t i = 0; i < size; i++)
    {
        ull num;
        std::cin >> num;

        sum += num;

        if (num < min)  min = num;

        if (num > max)  max = num;
    }

    std::cout << sum-max << ' ' << sum-min << '\n';

    return 0;
}
