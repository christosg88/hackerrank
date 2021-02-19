#include <iostream>
#include <deque>

void printKMax(int *nums, int length, int k);

int main()
{
    std::ios_base::sync_with_stdio(false);

    const int max_length = 10000;
    int *nums = new int[max_length];

    int testcases;
    std::cin >> testcases;

    for (int testcase = 0; testcase < testcases; ++testcase)
    {
        int length;
        int k;
        std::cin >> length >> k;

        for (register int i = 0; i < length; ++i)
            std::cin >> nums[i];

        printKMax(nums, length, k);

    }

    delete[] nums;

    return 0;
}

/**
 * Prints the maximum element for every subarray of length k, in the array nums
 * of length length, separated by space.
 * @param nums   the array in which the subarrays are
 * @param length the length of the array
 * @param k      the length of each subarray
 */
void printKMax(int *nums, int length, int k)
{
    std::deque<int> q;

    int i;
    // process the first window
    for (i = 0; i < k; ++i)
    {
        // remove all the elements that are smaller than the current
        while (!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();

        // add the index of the current at the back
        q.push_back(i);
    }

    // print the max of the first window
    std::cout << nums[q.front()] << ' ';

    // process the next windows
    for (; i < length; ++i)
    {
        // remove elements that are not in the current window (one at most for
        // each window)
        if (!q.empty() && q.front() <= i - k)
            q.pop_front();



        // remove all elements that are smaller than the current
        while (!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();

        // add the index of the current at the back
        q.push_back(i);

        // print the max of the current window
        std::cout << nums[q.front()] << ' ';
    }

    std::cout << '\n';
}
