#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);

    unsigned long int num_sequences, num_queries;
    std::cin >> num_sequences >> num_queries;

    std::vector<std::vector<unsigned long int>> sequences(num_sequences);

    unsigned long int lastans = 0;
    while (num_queries--)
    {
        int type;
        unsigned long int x, y;
        std::cin >> type >> x >> y;

        if (type == 1)
        {
            sequences[(x ^ lastans) % num_sequences].push_back(y);
        }
        else
        {
            unsigned long int size = sequences[(x ^ lastans) % num_sequences].size();
            lastans = sequences[(x ^ lastans) % num_sequences][y % size];
            std::cout << lastans << '\n';
        }
    }

    return 0;
}
