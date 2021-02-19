#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    unsigned long length, diff;
    std::cin >> length >> diff;

    unsigned long *nums = new unsigned long[length];

    for (unsigned long i = 0; i < length; ++i)
        std::cin >> nums[i];

    std::sort(nums, nums+length);

    unsigned long left, right;
    unsigned long pairs = 0;

    left = 0;
    right = 1;
    while (right < length)
    {
        unsigned long tmp_diff = nums[right] - nums[left];
        if (tmp_diff == diff)
        {
            pairs++;
            left++;
            right++;
        }
        else if (tmp_diff < diff)
        {
            right++;
        }
        else
        {
            left++;
            if (left == right)
                right++;
        }
    }

    std::cout << pairs << '\n';

    delete[] nums;
    return 0;
}
