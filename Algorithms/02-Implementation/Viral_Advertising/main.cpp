#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_days;
    std::cin >> num_days;

    int num_likes = 0;
    int num_shares = 5;
    for (int day = 0; day < num_days; ++day) {
        int additional_likes = num_shares / 2;
        num_likes += additional_likes;
        num_shares = additional_likes * 3;
    }

    fout << num_likes << "\n";
    fout.close();

    return 0;
}
