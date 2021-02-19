#include <iostream>

int main()
{
    int length;
    std::cin >> length;

    int *nums = new int[length];
    for (int i = 0; i < length; ++i)
        std::cin >> nums[i];

    for (int i = length - 1; i >= 0; --i)
        std::cout << nums[i] << ' ';

    std::cout << '\n';

    delete[] nums;
    return 0;
}
