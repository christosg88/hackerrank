#include <iostream>

void quick_sort(int *nums, int left, int right);
int partition(int *nums, int left, int right);
void print_int_array(int *nums);

// the length of the array is declared as global so that the whole array can be
// printed after partitioning
int length;

int main()
{
    std::cin >> length;

    // the array
    int *nums = new int[length];
    for (int i = 0; i < length; ++i)
        std::cin >> nums[i];

    // sort the array using quick_sort
    quick_sort(nums, 0, length - 1);

    // clean up
    delete[] nums;

    return 0;
}

/**
 * Sorts the given subarray from index left to index right inclusive
 * @param nums the subarray to be sorted
 * @param left   the index of the leftmost cell for sorting (inclusive)
 * @param right   the index of the rightmost cell for sorting (inclusive)
 */
void quick_sort(int *nums, int left, int right)
{
    if (left < right)
    {
        // partition the array
        int p = partition(nums, left, right);

        // print the whole array after partitioning (just for this exercise)
        print_int_array(nums);

        // sort the partitioned subarrays
        quick_sort(nums, left, p - 1);
        quick_sort(nums, p + 1, right);

    }
}

/**
 * Partitions the subarray in place using Lomuto's partition scheme
 * @param  nums the subarray to be sorted
 * @param  left   the index of the leftmost cell for sorting (inclusive)
 * @param  right   the index of the leftmost cell for sorting (inclusive)
 * @return      the final index of the pivot, which is the index where the
 *                  subarray is partitioned into two other subarrays
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

/**
 * Print an array of int
 * @param nums the array to print
 */
void print_int_array(int *nums)
{
    for (int i = 0; i < length; ++i)
        std::cout << nums[i] << ' ';

    std::cout << '\n';
}

