#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int queries;
    std::cin >> queries;

    std::set<int> nums;

    for (register int i = 0; i < queries; ++i)
    {
        int q;
        int num;
        std::cin >> q >> num;

        if (q == 1)
            nums.insert(num);
        else if (q == 2)
        {
            std::set<int>::iterator it = nums.find(num);
            if (it != nums.end())
                nums.erase(it);
        }
        else if (q == 3)
        {
            std::set<int>::iterator it = nums.find(num);
            if (it != nums.end())
                std::cout << "Yes\n";
            else
                std::cout << "No\n";
        }
    }

    return 0;
}
