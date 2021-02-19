#include <iostream>
#include <vector>

void print_int_vector(std::vector<int> &nums);
void quick_sort(std::vector<int> &nums);

int main()
{
    int length;
    std::cin >> length;

    std::vector<int> nums(length);

    for (int i = 0; i < length; ++i)
        std::cin >> nums[i];

    quick_sort(nums);

    return 0;
}

void print_int_vector(std::vector<int> &nums)
{
    for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        std::cout << *it << ' ';

    std::cout << '\n';
}

void quick_sort(std::vector<int> &nums)
{
    int pivot = nums[0];
    std::vector<int> lower;
    std::vector<int> higher;

    for (std::vector<int>::iterator it = nums.begin() + 1; it != nums.end(); ++it)
    {
        if (*it <= pivot)
            lower.push_back(*it);
        else
            higher.push_back(*it);
    }

    if (lower.size() > 1)
        quick_sort(lower);

    if (higher.size() > 1)
        quick_sort(higher);

    int i = 0;
    for (std::vector<int>::iterator it = lower.begin(); it != lower.end(); ++it)
        nums[i++] = *it;

    nums[i++] = pivot;

    for (std::vector<int>::iterator it = higher.begin(); it != higher.end(); ++it)
        nums[i++] = *it;

    print_int_vector(nums);
}
