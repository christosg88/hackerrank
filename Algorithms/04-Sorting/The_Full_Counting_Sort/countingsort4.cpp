#include <iostream>
#include <vector>
#include <string>

int main()
{
    // the maximum value in the array. Minimum is considered 0.
    const int max_value = 99;

    // turn off synchronization with stdio
    std::ios_base::sync_with_stdio(false);

    // the number of numbers and strings that will be given as input
    int length;
    std::cin >> length;

    // the frequencies of each value
    int counts[max_value + 1] = {0};
    // the numbers given as input
    std::vector<int> nums(length);
    // the string next to each number
    std::vector<std::string> strs(length, "-");
    // the sorted strings
    std::vector<std::string> sorted_strs(length);

    // read the first half numbers and strings, but store "-" instead of the
    // string
    for (int i = 0; i < length / 2; ++i)
    {
        int num;
        std::string str;

        std::cin >> num >> str;
        counts[num]++;
        nums[i] = num;
    }

    // read the second half numbers and strings
    for (int i = length / 2; i < length; ++i)
    {
        int num;
        std::string str;

        std::cin >> num >> str;
        counts[num]++;
        nums[i] = num;
        strs[i] = str;
    }

    // cumulate the sum
    for (int i = 1; i < max_value + 1; ++i)
        counts[i] += counts[i-1];

    // sort the string based on appearance of their number
    for (int i = length - 1; i >= 0; --i)
    {
        counts[nums[i]]--;
        sorted_strs[counts[nums[i]]] = strs[i];
    }

    // print the sorted strings
    for (int i = 0; i < length; ++i)
        std::cout << sorted_strs[i] << ' ';

    std::cout << '\n';

    return 0;
}
