/**
 * Finds the median of a list of ints using Quickselect
 * https://en.wikipedia.org/wiki/Quickselect
 */
#include <iostream>

int partition(int *nums, int left, int right);
int quick_select(int *nums, int left, int right, int n);

int main()
{
    int len;
    std::cin >> len;

    int *nums = new int[len];

    for (int i = 0; i < len; ++i)
        std::cin >> nums[i];

    std::cout << quick_select(nums, 0, len - 1, len / 2);

    delete[] nums;
    return 0;
}

/**
 * Return the n-th smallest element in nums withing [left, right]
 * @param  nums  the list where the n-th minimum is to be found
 * @param  left  the index of the leftmost cell for the selection (inclusive)
 * @param  right the index of the rightmost cell for the selection (inclusive)
 * @param  n     the n-th smallest element is to be returned
 * @return       the value of the n-th smallest element
 */
int quick_select(int *nums, int left, int right, int n)
{
    while (left <= right)
    {
        if (left == right)
            return nums[left];

        int pivot_index = partition(nums, left, right);

        if (n == pivot_index)
            return nums[n];
        else if (n < pivot_index)
            right = pivot_index - 1;
        else
            left = pivot_index + 1;
    }

    return -1;
}

/**
 * Partitions the subarray in place using Lomuto's partition scheme
 * @param  nums  the subarray to be sorted
 * @param  left  the index of the leftmost cell for sorting (inclusive)
 * @param  right the index of the leftmost cell for sorting (inclusive)
 * @return       the final index of the pivot, which is the index where the
 *                   subarray is partitioned into two other subarrays
 */
int partition(int *nums, int left, int right)
{
    // select the rightmost element as pivot
    int pivot = nums[right];

    // start the wall at the leftmost element
    int pivot_index = left;
    // from the leftmost element till before the last
    for (int j = left; j < right; ++j)
    {
        // if this element is less or equal to the pivot, change it with the
        // element at the wall, and move the wall forward
        if (nums[j] <= pivot)
        {
            int tmp = nums[j];
            nums[j] = nums[pivot_index];
            nums[pivot_index] = tmp;
            pivot_index++;
        }
    }

    // place the pivot at its final position
    int tmp = nums[pivot_index];
    nums[pivot_index] = nums[right];
    nums[right] = tmp;

    return pivot_index;
}
