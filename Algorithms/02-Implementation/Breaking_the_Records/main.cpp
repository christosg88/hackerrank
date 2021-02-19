#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_games;
    std::cin >> num_games;

    int min_score, max_score, score;
    int min_score_broken_count = 0, max_score_broken_count = 0;

    std::cin >> score;
    min_score = max_score = score;
    num_games--;

    for (int i = 0; i < num_games; ++i) {
        std::cin >> score;

        if (score > max_score) {
            max_score = score;
            max_score_broken_count++;
        }
        else if (score < min_score) {
            min_score = score;
            min_score_broken_count++;
        }
    }

    fout << max_score_broken_count << " " << min_score_broken_count << "\n";
    fout.close();

    return 0;
}
