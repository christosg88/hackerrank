#include <iostream>
#include <vector>

int main()
{
    int length;
    std::cin >> length;

    int *nums = new int[length];
    for (int i = 0; i < length; ++i)
        std::cin >> nums[i];

    int pivot = nums[0];
    std::vector<int> lower;
    std::vector<int> higher;

    for (int i = 1; i < length; ++i)
    {
        if (nums[i] <= pivot)
            lower.push_back(nums[i]);
        else
            higher.push_back(nums[i]);
    }

    lower.push_back(pivot);

    for (std::vector<int>::iterator it = lower.begin(); it != lower.end(); ++it)
        std::cout << *it << ' ';

    for (std::vector<int>::iterator it = higher.begin(); it != higher.end(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';

    delete[] nums;
    return 0;
}
