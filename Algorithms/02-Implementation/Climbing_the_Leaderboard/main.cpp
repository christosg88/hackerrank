#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_players;
    std::cin >> num_players;

    std::vector<int> scores;
    int previous_score = -1;
    for (int i = 0; i < num_players; ++i) {
        int score;
        std::cin >> score;

        if (score != previous_score) {
            scores.emplace_back(score);
            previous_score = score;
        }
    }

    int num_scores = scores.size();
    int alice_place = num_scores;

    int num_alice_games;
    std::cin >> num_alice_games;
    for (int i = 0; i < num_alice_games; ++i) {
        int score;
        std::cin >> score;

        while (alice_place > 0 && scores[alice_place - 1] <= score) {
            alice_place--;
        }

        fout << alice_place + 1 << "\n";
    }

    fout.close();
    return 0;
}
