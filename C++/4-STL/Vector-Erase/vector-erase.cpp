#include <iostream>
#include <vector>

int main()
{
    unsigned int length;
    std::cin >> length;

    std::vector<int> v(length);

    for (unsigned int i = 0; i < length; ++i)
        std::cin >> v[i];

    unsigned int a, b;

    std::cin >> a;
    // subtract 1 for zero based vectors
    v.erase(v.begin() + a - 1);

    std::cin >> a >> b;
    // subtract 1 for zero based vectors
    v.erase(v.begin() + a - 1, v.begin() + b - 1);

    length = v.size();

    std::cout << length << '\n';

    for (unsigned int i = 0; i < length; ++i)
        std::cout << v[i] << ' ';
    std::cout << '\n';

    return 0;
}
