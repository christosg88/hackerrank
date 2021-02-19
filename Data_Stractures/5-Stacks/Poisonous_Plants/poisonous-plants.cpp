// http://www.geeksforgeeks.org/the-stock-span-problem/
#include <iostream>
#include <deque>
#include <climits>

int main()
{
    std::ios_base::sync_with_stdio(false);

    // the number of plants
    unsigned long num_of_plants;
    std::cin >> num_of_plants;

    // the amount of pesticide at each plant
    std::deque<unsigned long> q1;
    std::deque<unsigned long> q2;

    // read all the pesticides
    for (unsigned long i = 0; i < num_of_plants; ++i)
    {
        unsigned long tmp;
        std::cin >> tmp;
        q1.push_front(tmp);
    }

    int choice = 0;
    unsigned long size = q1.size();
    unsigned long days = 0;

    while (true)
    {
        std::deque<unsigned long> *qptr1;
        std::deque<unsigned long> *qptr2;
        if (choice == 0)
        {
            qptr1 = &q1;
            qptr2 = &q2;
        }
        else
        {
            qptr1 = &q2;
            qptr2 = &q1;
        }

        while (!qptr1->empty())
        {
            unsigned long tmp;
            tmp = qptr1->front();
            qptr1->pop_front();
            if (tmp <= (qptr1->empty() ? ULONG_MAX : qptr1->front()))
                qptr2->push_back(tmp);
        }

        if (qptr2->size() == size)
            break;
        else
        {
            days++;
            size = qptr2->size();
            choice = (choice + 1) % 2;
        }
    }

    std::cout << days << std::endl;

    return 0;
}
