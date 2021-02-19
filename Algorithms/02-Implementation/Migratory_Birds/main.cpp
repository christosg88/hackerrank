#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_birds;
    std::cin >> num_birds;

    std::vector<int> sightings(num_birds);

    for (int i = 0; i < num_birds; ++i) {
        int bird_id;
        std::cin >> bird_id;

        sightings[bird_id]++;
    }

    int id_with_max_sightings = 0;
    int max_sightings = sightings[0];

    for (int i = 1; i < num_birds; ++i) {
        if (sightings[i] > max_sightings) {
            max_sightings = sightings[i];
            id_with_max_sightings = i;
        }
    }

    fout << id_with_max_sightings << "\n";

    return 0;
}
