#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // the number of queries that will be made
    unsigned long queries;
    std::cin >> queries;

    // the stack holding the strings to enable the undo
    std::stack<std::string> strings;
    strings.push("");

    for (unsigned long i = 0; i < queries; ++i)
    {
        int operation;
        std::cin >> operation;

        // append string to the top string and push the concatenation to the top
        if (operation == 1)
        {
            std::string tmp;
            std::cin >> tmp;
            strings.push(strings.top() + tmp);
        }
        // erase the last letters_to_delete characters from the top string and
        // push the new string to the top
        else if (operation == 2)
        {
            unsigned long letters_to_delete;
            std::cin >> letters_to_delete;
            strings.push(std::string(strings.top(), 0, strings.top().size() - letters_to_delete));
        }
        // print the index character of the top string
        else if (operation == 3)
        {
            unsigned long index;
            std::cin >> index;
            std::cout << strings.top()[index - 1] << std::endl;
        }
        // undo the last action by poping the top string
        else
        {
            strings.pop();
        }
    }

    return 0;
}
