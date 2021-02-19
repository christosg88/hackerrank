#include <iostream>

int main()
{
    int length;
    std::cin >> length;

    int counts[100] = {0};

    for (int i = 0; i < length; ++i)
    {
        int num;
        char str[11];
        std::cin >> num >> str;

        counts[num]++;
    }

    int sum = 0;
    for (int i = 0; i < 100; ++i)
    {
        sum += counts[i];
        std::cout << sum << ' ';
    }

    std::cout << '\n';

    return 0;
}
