#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    unsigned long num_of_seq;
    unsigned long queries;

    std::cin >> num_of_seq >> queries;

    unsigned long **sequences = new unsigned long *[num_of_seq];

    // read in the sequences
    for (unsigned long i = 0; i < num_of_seq; ++i)
    {
        unsigned long size_of_seq;
        std::cin >> size_of_seq;

        sequences[i] = new unsigned long[size_of_seq];

        for (unsigned long j = 0; j < size_of_seq; ++j)
            std::cin >> sequences[i][j];
    }

    // respond to queries
    for (unsigned long q = 0; q < queries; ++q)
    {
        unsigned long i, j;
        std::cin >> i >> j;
        std::cout << sequences[i][j] << '\n';
    }

    for (unsigned long i = 0; i < num_of_seq; ++i)
        delete[] sequences[i];

    delete[] sequences;

    return 0;
}
