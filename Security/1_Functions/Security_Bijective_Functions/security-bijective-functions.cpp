#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    
    bool is_bijective = true;
    std::set<int> nums;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        std::cin >> tmp;
        
        if (nums.find(tmp) == nums.end())   // tmp not in nums
        {
            nums.insert(tmp);
        }
        else
        {
            is_bijective = false;
            break;
        }
    }
    
    if (is_bijective)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
    
    return 0;
}
