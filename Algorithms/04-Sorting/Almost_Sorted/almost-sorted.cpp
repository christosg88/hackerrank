#include <iostream>

bool is_sorted(long int *nums, long int length);

int main()
{
    long int length;
    std::cin >> length;

    long int *nums = new long int[length];
    for (long int i = 0; i < length; ++i)
        std::cin >> nums[i];

    bool sorted = false;

    // if it's already sorted, then just print "yes"
    if (is_sorted(nums, length))
    {
        std::cout << "yes\n";
        sorted = true;
    }

    // see if you can sort it with a swap
    if (!sorted)
    {
        // the index of the two anomalies to be swapped
        long int first_index = -1, second_index = -1;
        for (long int i = 0; i < length; ++i)
        {
            if (nums[i] > nums[i+1])
            {
                if (first_index == -1)
                {
                    // initialize the second index to the adjacent of the first,
                    // so that in case no other anomaly is found the two are
                    // swapped
                    first_index = i;
                    second_index = i + 1;
                    std::cout <<  first_index;
                }
                else
                {
                    second_index = i;
                    break;
                }
            }
        }

        // swap the two anomalies
        int tmp = nums[first_index];
        nums[first_index] = nums[second_index];
        nums[second_index] = tmp;

        // check if it's now sorted, else re-swap them
        if (is_sorted(nums + first_index, length - first_index))
        {
            std::cout << "yes\n";
            std::cout << "swap " << first_index + 1 << ' ' << second_index + 1 << '\n';
            sorted = true;
        }
        else
        {
            int tmp = nums[first_index];
            nums[first_index] = nums[second_index];
            nums[second_index] = tmp;
        }
    }

    // see if you can sort it with a reverse
    if (!sorted)
    {

    }

    delete[] nums;
    return 0;
}

/**
 * Checks if nums is sorted in ascending order
 * @param  nums   the array of ints
 * @param  length the length of the array
 * @return        true if the array is sorted in ascending order, else false
 */
bool is_sorted(int *nums, int length)
{
    for (int i = 0; i < length - 1; ++i)
        if (nums[i] > nums[i+1])
            return false;

    return true;
}
