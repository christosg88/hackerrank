#include <iostream>

int main()
{
    int length;
    std::cin >> length;

    int counts[100] = {0};

    // count the occurrences of each number
    for (int i = 0; i < length; ++i)
    {
        int n;
        std::cin >> n;
        counts[n] += 1;
    }

    for (int i = 0; i < 100; ++i)
        std::cout << counts[i] << ' ';

    std::cout << '\n';

    return 0;
}
