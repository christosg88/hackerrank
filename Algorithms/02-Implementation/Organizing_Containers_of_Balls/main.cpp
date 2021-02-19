#include <iostream>
#include <vector>
#include <set>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_queries;
    std::cin >> num_queries;

    for (int query = 0; query < num_queries; ++query) {
        int num_containers;
        std::cin >> num_containers;

        // the number at (row, col) denotes the number of balls of type 'col',
        // into container 'row'
        std::vector<std::vector<int>> containers(num_containers, std::vector<int>(num_containers, 0));

        std::vector<int> sum_per_col(num_containers, 0);
        std::vector<int> sum_per_row(num_containers, 0);

        // fill the containers
        for (int container = 0; container < num_containers; ++container) {
            for (int type = 0; type < num_containers; ++type) {
                std::cin >> containers[container][type];
                sum_per_row[container] += containers[container][type];
                sum_per_col[type] += containers[container][type];
            }
        }

        std::multiset<int> multiset1(sum_per_row.begin(), sum_per_row.end());
        std::multiset<int> multiset2(sum_per_col.begin(), sum_per_col.end());

        if (multiset1 == multiset2) {
            fout << "Possible\n";
        }
        else {
            fout << "Impossible\n";
        }
    }

    fout.close();

    return 0;
}
