#include <iostream>

void insertion_sort(int *nums, int length);
void quick_sort(int *nums, int lo, int hi);
int partition(int *nums, int lo, int hi);

int insertion_swifts = 0;
int quicksort_swaps = 0;

int main()
{
    int length;
    std::cin >> length;

    int *nums1 = new int[length];
    int *nums2 = new int[length];

    for (int i = 0; i < length; ++i)
    {
        std::cin >> nums1[i];
        nums2[i] = nums1[i];
    }

    quick_sort(nums1, 0, length - 1);
    insertion_sort(nums2, length);

    std::cout << insertion_swifts - quicksort_swaps << '\n';

    delete[] nums1;
    delete[] nums2;
    return 0;
}

/**
 * Sorts the given array using insertion sort
 * @param nums   the array to be sorted
 * @param length the length of the array
 */
void insertion_sort(int *nums, int length)
{
    for (int i = 1; i < length; ++i)
    {
        int j = i;
        while (j > 0 && nums[j] < nums[j-1])
        {
            int tmp = nums[j];
            nums[j] = nums[j-1];
            nums[j-1] = tmp;
            j--;

            // just for this exercise
            insertion_swifts++;
        }
    }
}

/**
 * Sorts the given subarray from index lo to index hi inclusive using quicksort
 * @param nums the subarray to be sorted
 * @param lo   the index of the leftmost cell for sorting (inclusive)
 * @param hi   the index of the rightmost cell for sorting (inclusive)
 */
void quick_sort(int *nums, int lo, int hi)
{
    if (lo < hi)
    {
        // partition the array
        int p = partition(nums, lo, hi);

        // sort the partitioned subarrays
        quick_sort(nums, lo, p - 1);
        quick_sort(nums, p + 1, hi);

    }
}

/**
 * Partitions the subarray in place using Lomuto's partition scheme
 * @param  nums the subarray to be sorted
 * @param  lo   the index of the leftmost cell for sorting (inclusive)
 * @param  hi   the index of the leftmost cell for sorting (inclusive)
 * @return      the final index of the pivot, which is the index where the
 *                  subarray is partitioned into two other subarrays
 */
int partition(int *nums, int lo, int hi)
{
    // select the rightmost element as pivot
    int pivot = nums[hi];

    // start the wall at the leftmost element
    int pivot_index = lo;
    // from the leftmost element till before the last
    for (int j = lo; j < hi; ++j)
    {
        // if this element is less or equal to the pivot, change it with the
        // element at the wall, and move the wall forward
        if (nums[j] <= pivot)
        {
            int tmp = nums[j];
            nums[j] = nums[pivot_index];
            nums[pivot_index] = tmp;
            pivot_index++;

            // just for this exercise
            quicksort_swaps++;
        }
    }

    // place the pivot at its final position
    int tmp = nums[pivot_index];
    nums[pivot_index] = nums[hi];
    nums[hi] = tmp;

    // just for this exercise
    quicksort_swaps++;

    return pivot_index;
}
