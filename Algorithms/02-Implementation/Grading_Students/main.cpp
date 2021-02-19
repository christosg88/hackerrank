#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile(std::getenv("OUTPUT_PATH"));

    int num_students;
    std::cin >> num_students;

    while (num_students--) {
        int grade;
        std::cin >> grade;

        if (grade < 38) {
            outfile << grade << "\n";
        }
        else {
            int next_multiple_of_5 = (grade/5 + 1) * 5;

            outfile << (next_multiple_of_5 - grade < 3 ? next_multiple_of_5 : grade) << "\n";
        }
    }

    return 0;
}
