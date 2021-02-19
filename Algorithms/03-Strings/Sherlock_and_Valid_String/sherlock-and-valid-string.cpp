#include <iostream>
#include <algorithm>
#include <cstring>

bool equal_frequencies(int *freq, int length);

int main()
{
    int freq[26] = {0};
    char str[100000];

    std::cin >> str;

    int len = strlen(str);

    for (int i = 0; i < len; ++i)
        freq[str[i] - 'a']++;

    // sort the frequencies in descending order
    std::sort(freq, freq + 26, std::greater<int>());

    // find the number of frequencies greater than 0
    int num_of_letters = 0;
    for (int i = 0; i < 26; ++i)
    {
        if (freq[i] > 0)
            num_of_letters++;
        else
            break;
    }

    bool is_valid = false;

    // check if you don't have to remove any letter
    if (equal_frequencies(freq, num_of_letters))
        is_valid = true;

    // if it's not valid, see if removing one letter of the most frequent will
    // make it valid
    if (!is_valid)
    {
        freq[0]--;
        if (equal_frequencies(freq, num_of_letters))
            is_valid = true;
        freq[0]++;
    }

    // finally see if you can make it valid by removing a character with
    // frequency 1 (it will be the least frequent)
    if (!is_valid && freq[num_of_letters-1] == 1)
        if (equal_frequencies(freq, num_of_letters - 1))
            is_valid = true;

    if (is_valid)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    return 0;
}

/**
 * Checks if each letter appears the same number of times
 * @param  freq   the frequencies of the letters
 * @param  length the number of frequencies greater that 0
 * @return        true if they all have the same frequency, else false
 */
bool equal_frequencies(int *freq, int length)
{
    for (int i = 0; i < length-1; ++i)
        if (freq[i] != freq[i+1])
            return false;

    return true;
}
