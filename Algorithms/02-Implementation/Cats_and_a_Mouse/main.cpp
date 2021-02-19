#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_queries;
    std::cin >> num_queries;

    for (int query = 0; query < num_queries; ++query) {
        int cat_position_1, cat_position_2, mouse_position;
        std::cin >> cat_position_1 >> cat_position_2 >> mouse_position;

        int dist_1 = std::abs(cat_position_1 - mouse_position);
        int dist_2 = std::abs(cat_position_2 - mouse_position);

        if (dist_1 < dist_2) {
            fout << "Cat A\n";
        }
        else if (dist_2 < dist_1) {
            fout << "Cat B\n";
        }
        else {
            fout << "Mouse C\n";
        }
    }

    fout.close();
    return 0;
}
