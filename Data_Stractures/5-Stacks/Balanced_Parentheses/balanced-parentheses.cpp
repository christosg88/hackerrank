#include <iostream>
#include <string>
#include <stack>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // the number of testcases
    int testcases;
    std::cin >> testcases;

    // a string containing all possible opening parenthesis
    std::string open = "([{";

    // the string with the inputed parenthesis
    std::string s(1000, '\0');

    for (int testcase = 0; testcase < testcases; ++testcase)
    {
        // a stack that will hold all opening parenthesis met till now
        std::stack<char> stack_open;
        std::cin >> s;

        // if there is an odd number of parenthesis, then they can't be balanced
        if (s.size() % 2 == 1)
        {
            std::cout << "NO\n";
            continue;
        }

        bool is_balanced = true;

        for (std::string::iterator it = s.begin(); it != s.end(); ++it)
        {
            // if an open parenthesis was found
            if (open.find(*it) != std::string::npos)
            {
                // push it in the stack
                stack_open.push(*it);
            }
            // else a closing parenthesis was found
            else
            {
                // if the stack is empty this closing parenthesis was not
                // opened, so it's not balanced
                if (stack_open.empty())
                {
                    is_balanced = false;
                    break;
                }
                // else check if it closes the top parenthesis in the stack
                else if ((stack_open.top() == '(' && *it == ')') ||
                         (stack_open.top() == '[' && *it == ']') ||
                         (stack_open.top() == '{' && *it == '}'))
                {
                    // if it does, pop the top parenthesis from the stack
                    stack_open.pop();
                }
                // else they are not balanced
                else
                {
                    is_balanced = false;
                    break;
                }
            }
        }

        // if there are open parenthesis left, that haven't been closed, they are
        // not balanced
        if (!stack_open.empty())
            is_balanced = false;

        std::cout << (is_balanced ? "YES\n" : "NO\n");
    }

    return 0;
}
