#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main()
{
    long int num_of_nums;
    std::cin >> num_of_nums;

    long int *nums = new long int[num_of_nums];
    std::vector<long int> pairs_of_min(num_of_nums);

    for (long int i = 0; i < num_of_nums; ++i)
        std::cin >> nums[i];

    std::sort(nums, nums + num_of_nums);

    long int min = LONG_MAX;

    for (long int i = 1; i < num_of_nums; ++i)
    {
        long int diff = nums[i] - nums[i-1];
        if (diff < min)
        {
            min = diff;
            pairs_of_min.clear();
        }

        if (diff == min)
        {
            pairs_of_min.push_back(nums[i-1]);
            pairs_of_min.push_back(nums[i]);
        }
    }

    for (std::vector<long int>::iterator it = pairs_of_min.begin(); it != pairs_of_min.end(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';

    return 0;
}
