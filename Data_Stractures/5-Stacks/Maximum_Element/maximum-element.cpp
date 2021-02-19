#include <iostream>
#include <deque>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // the number of queries
    unsigned long queries;
    std::cin >> queries;

    // the stack that will hold all the numbers pushed
    std::deque<unsigned long> nums;
    // the stack that will hold the index of the maximum number in the nums
    // stack
    std::deque<unsigned long> indx_of_maxs;

    for (unsigned long i = 0; i < queries; ++i)
    {
        int operation;
        std::cin >> operation;

        // push
        if (operation == 1)
        {
            unsigned long num;
            std::cin >> num;

            nums.push_back(num);
            if (indx_of_maxs.empty() || num > nums[indx_of_maxs.back()])
                indx_of_maxs.push_back(nums.size() - 1);
        }
        // pop
        else if (operation == 2)
        {
            nums.pop_back();
            if (nums.size() <= indx_of_maxs.back())
                indx_of_maxs.pop_back();
        }
        // output maximum
        else if (operation == 3)
        {
            std::cout << nums[indx_of_maxs.back()] << '\n';
        }
    }

    return 0;
}
