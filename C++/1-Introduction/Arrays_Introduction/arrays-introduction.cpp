#include <iostream>

int main()
{
    int length;
    std::cin >> length;

    int *nums = new int[length];
    for (register int i = 0; i < length; ++i)
        std::cin >> nums[i];
    for (register int i = length-1; i >= 0; --i)
        std::cout << nums[i] << ' ';

    delete[] nums;

    return 0;
}
