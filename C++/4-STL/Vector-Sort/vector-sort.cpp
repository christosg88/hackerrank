#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    unsigned int length;
    std::cin >> length;

    std::vector<int> v(length);

    for (unsigned int i = 0; i < length; ++i)
        std::cin >> v[i];

    std::sort(v.begin(), v.end());

    for (unsigned int i = 0; i < length; ++i)
        std::cout << v[i] << ' ';

    std::cout << '\n';

    return 0;
}
