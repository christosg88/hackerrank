#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_pieces;
    std::cin >> num_pieces;

    int pieces[num_pieces];
    for (int i = 0; i < num_pieces; ++i) {
        std::cin >> pieces[i];
    }

    int needed_sum, needed_length;
    std::cin >> needed_sum >> needed_length;

    int count_ways = 0;

    int index_first = 0, index_last = 0;
    int total_sum = 0;

    for (; index_last < needed_length; ++index_last) {
        total_sum += pieces[index_last];
    }
    if (total_sum == needed_sum) {
        count_ways++;
    }

    for (; index_last < num_pieces; ++index_first, ++index_last) {
        total_sum = total_sum + pieces[index_last] - pieces[index_first];
        if (total_sum == needed_sum) {
            count_ways++;
        }
    }

    fout << count_ways << "\n";

    return 0;
}
