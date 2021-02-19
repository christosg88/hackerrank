#include <iostream>
#include <fstream>
#include <cmath>

int turnsFromFront(int page) {
    return page / 2;
}

int turnsFromBack(int num_pages, int page) {
    double turns = (num_pages - page) / 2.0;
    if (!(num_pages % 2)) {
        return static_cast<int>(std::ceil(turns));
    }
    else {
        return static_cast<int>(turns);
    }
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int num_pages, page;
    std::cin >> num_pages >> page;

    fout << std::min(turnsFromFront(page), turnsFromBack(num_pages, page)) << "\n";
    fout.close();

    return 0;
}
