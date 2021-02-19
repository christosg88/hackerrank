#include <iostream>
#include <cstring>

int next_lexicographic_permutation(char *str);

int main()
{
    int testcases;
    std::cin >> testcases;

    while (testcases--)
    {
        char str[101];
        std::cin >> str;

        if (next_lexicographic_permutation(str))
            std::cout << str << '\n';
        else
            std::cout << "no answer\n";
    }

    return 0;
}

int next_lexicographic_permutation(char *str)
{
    int length = strlen(str);

    // 1. find the largest index k so that str[k] < str[k + 1]
    int k = -1;
    for (int i = 0; i < length - 1; ++i)
    {
        if (str[i] < str[i + 1])
            k = i;
    }

    // if k == -1, then there is no greater lexicographic permutation
    if (k == -1)
        return 0;

    // 2. find the largest index l greater than k such that str[k] < str[l]
    int l;
    for (int i = k + 1; i < length; ++i)
    {
        if (str[k] < str[i])
            l = i;
    }

    // 3. swap the value of str[k] with that of str[l]
    int tmp = str[k];
    str[k] = str[l];
    str[l] = tmp;

    // 4. reverse the sequence from str[k+1] up to and including the final
    // element
    int left = k + 1;
    int right = length - 1;

    while (left < right)
    {
        int tmp = str[left];
        str[left] = str[right];
        str[right] = tmp;
        left++;
        right--;
    }

    return 1;

}
