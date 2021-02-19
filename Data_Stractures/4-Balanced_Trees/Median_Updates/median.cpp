#include <iostream>
#include <iomanip>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // the number of queries that will be made
    unsigned long queries;
    std::cin >> queries;

    // one multiset for the numbers less than the median (left) and one for the
    // numbers greater than the median (right)
    std::multiset<long> left, right;

    // the sizes of the two multisets
    long size_l = 0;
    long size_r = 0;

    for (unsigned long i = 0; i < queries; ++i)
    {
        std::multiset<long>::iterator l_it;
        std::multiset<long>::iterator r_it = right.begin();

        // the operation to be made: 'a'ppend or 'r'emove
        char operation;
        long num;
        std::cin >> operation >> num;

        // append
        if (operation == 'a')
        {
            // if the given number is greater than the smallest number in right,
            // insert it in the right
            if (num > *r_it)
            {
                right.insert(num);
                size_r++;
            }
            // else insert it in the left
            else
            {
                left.insert(num);
                size_l++;
            }
        }
        // remove
        else
        {
            // if the total size is 0 output Wrong! and continue
            if (size_l + size_r == 0)
            {
                std::cout << "Wrong!\n";
                continue;
            }
            // else try to find the value
            else
            {
                // the iterator pointing at the value we will delete
                std::multiset<long>::iterator del;
                // if the number we want to delete is greater than the smallest
                // number in the right multiset
                if (num >= *r_it)
                {
                    // try to find it in the right multiset
                    del = right.find(num);
                    // if it wasn't found output Wrong! and continue
                    if (del == right.end())
                    {
                        std::cout << "Wrong!\n";
                        continue;
                    }
                    // else delete it
                    else
                    {
                        right.erase(del);
                        size_r--;
                    }
                }
                // else the number could be in the left multiset
                else
                {
                    // try to find it in the left multiset
                    del = left.find(num);
                    // if it wasn't found output Wrong! and continue
                    if (del == left.end())
                    {
                        std::cout << "Wrong!\n";
                        continue;
                    }
                    // else delete it
                    else
                    {
                        left.erase(del);
                        size_l--;
                    }
                }
            }
        }

        // if we removed the last element output Wrong! and continue
        if (size_l + size_r == 0)
        {
            std::cout << "Wrong!\n";
            continue;
        }

        // re-balancing the two multisets, if the right multiset has two more
        // elements than the left
        if (size_r > size_l + 1)
        {
            r_it = right.begin();
            left.insert(*r_it);
            right.erase(r_it);
            size_l++;
            size_r--;
        }
        // or the left multiset has two more elements than the right
        else if (size_l > size_r + 1)
        {
            l_it = left.end();
            --l_it;
            right.insert(*l_it);
            left.erase(l_it);
            size_l--;
            size_r++;
        }

        // if the two multisets have the same number of elements, then the
        // median is the average of the greatest element in the left multiset
        // and the smallest element in the right multiset
        if (size_l == size_r)
        {
            r_it = right.begin();
            l_it = left.end();
            --l_it;
            long sum = *r_it + *l_it;
            // if we can evenly divide them in two, output as integer
            if (sum % 2 == 0)
                std::cout << sum / 2 << '\n';
            // else output with one decimal point
            else
                std::cout << std::setprecision(1) << std::fixed << ((double) sum) / 2 << '\n';
        }
        // else if the left multiset is longer than the right, the median is the
        // greatest element in the left multiset
        else if (size_l > size_r)
        {
            l_it = left.end();
            --l_it;
            std::cout << *l_it << '\n';
        }
        // else the right multiset is longer than the left, and the median is
        // the smallest element in the right multiset
        else
        {
            r_it = right.begin();
            std::cout << *r_it << '\n';
        }
    }

    return 0;
}
