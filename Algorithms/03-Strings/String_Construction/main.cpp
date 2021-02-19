#include <iostream>
#include <set>

int main() {
    unsigned int testcases;
    std::cin >> testcases;

    while (testcases--) {
        std::string s;
        std::cin >> s;

        std::cout << std::set<char>(s.begin(), s.end()).size() << "\n";
    }

    return 0;
}
