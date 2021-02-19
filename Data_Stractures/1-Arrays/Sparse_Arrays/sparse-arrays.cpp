#include <iostream>
#include <string>
#include <vector>

class CountedStr
{
public:
    std::string member_str;
    int count;
    CountedStr(std::string arg_str);
};

CountedStr::CountedStr(std::string arg_str) : member_str(arg_str), count(1)
{
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int num_strings;
    std::cin >> num_strings;

    std::vector<CountedStr> vec_strs;

    while (num_strings--)
    {
        std::string tmp_str;
        std::cin >> tmp_str;

        bool already_in = false;

        // check if the string is already in the vector
        for (unsigned int i = 0; i < vec_strs.size(); ++i)
        {
            // if it is increment its count
            if (!vec_strs[i].member_str.compare(tmp_str))
            {
                vec_strs[i].count++;
                already_in = true;
                break;
            }
        }

        // else add it
        if (!already_in)
        {
            vec_strs.push_back(CountedStr(tmp_str));
        }
    }

    int num_queries;
    std::cin >> num_queries;

    while(num_queries--)
    {
        std::string tmp_str;
        std::cin >> tmp_str;

        int count = 0;
        // check the number of times the string is in the vector
        for (unsigned int i = 0; i < vec_strs.size(); ++i)
        {
            // if it is change the count to output
            if (!vec_strs[i].member_str.compare(tmp_str))
            {
                count = vec_strs[i].count;
                break;
            }
        }

        std::cout << count << '\n';
    }

    return 0;
}
