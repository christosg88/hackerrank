#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int length;
    std::cin >> length;

    std::vector<int> nums(length);

    for (int i = 0; i < length; ++i)
        std::cin >> nums[i];

    int queries;
    std::cin >> queries;

    for (int i = 0; i < queries; ++i)
    {
        int num;
        std::cin >> num;

        std::vector<int>::iterator it = std::lower_bound(nums.begin(), nums.end(), num);

        if (*it == num)
            std::cout << "Yes ";
        else
            std::cout << "No ";
        std::cout << it - nums.begin() + 1 << '\n';
    }

    return 0;
}
