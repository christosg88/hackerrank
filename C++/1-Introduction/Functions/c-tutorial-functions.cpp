#include <iostream>
#include <algorithm>
using namespace std;

#ifndef NUM_OF_NUMS
#define NUM_OF_NUMS 4
#endif

int main()
{
    int nums[NUM_OF_NUMS];

    for (int i = 0; i < NUM_OF_NUMS; ++i)
        cin >> nums[i];

    cout << *max_element(nums, nums + NUM_OF_NUMS);

    return 0;
}
