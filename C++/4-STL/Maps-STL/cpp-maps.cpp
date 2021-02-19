#include <iostream>
#include <map>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int queries;
    std::cin >> queries;

    std::map<std::string, int> nums;

    for (register int i = 0; i < queries; ++i)
    {
        int q;
        std::string name;
        std::cin >> q >> name;

        if (q == 1)
        {
            int marks;
            std::cin >> marks;

            nums[name] += marks;
        }
        else if (q == 2)
        {
            nums[name] = 0;
        }
        else if (q == 3)
        {
            std::cout << nums[name] << '\n';
        }
    }

    return 0;
}
