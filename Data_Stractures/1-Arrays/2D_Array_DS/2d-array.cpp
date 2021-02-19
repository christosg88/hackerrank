#include <iostream>
#include <climits>

const int rows = 6;
const int cols = 6;

int main()
{
    int *nums = new int[rows * cols];

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            std::cin >> nums[j + i * cols];

    int max_sum = INT_MIN;
    for (int i = 0; i < rows - 2; ++i)
    {
        for (int j = 0; j < cols - 2; ++j)
        {
            int sum = nums[j + i * cols] +
                    nums[j+1 + i * cols] +
                    nums[j+2 + i * cols] +
                    nums[j+1 + (i+1) * cols] +
                    nums[j + (i+2) * cols] +
                    nums[(j+1) + (i+2) * cols] +
                    nums[(j+2) + (i+2) * cols];

            if (sum > max_sum)
                max_sum = sum;
        }
    }

    std::cout << max_sum << '\n';

    delete[] nums;
    return 0;
}
