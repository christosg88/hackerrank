#include <iostream>
#include <string>
#include <vector>

int main()
{
    int testcases;
    std::cin >> testcases;

    while (testcases--)
    {
        std::string str;
        std::cin >> str;

        int len = str.length();
        std::vector<int> ascii_str(len);

        for (int i = 0; i < len; ++i)
            ascii_str[i] = (int) str[i];

        bool is_funny = true;
        for (int i = 1; i <= len / 2; ++i)
        {
            if (abs(ascii_str[i] - ascii_str[i-1]) != abs(ascii_str[len-1-i] - ascii_str[len-i]))
            {
                is_funny = false;
                break;
            }
        }

        if (is_funny)
            std::cout << "Funny\n";
        else
            std::cout << "Not Funny\n";
    }

    return 0;
}
