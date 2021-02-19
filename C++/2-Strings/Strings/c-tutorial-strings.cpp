#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);

    std::string a, b;
    std::cin >> a >> b;

    std::cout << a.size() << " " << b.size() << "\n";
    std::cout << a + b << "\n";

    std::swap(a[0], b[0]);
    std::cout << a << " " << b << "\n";

    return 0;
}
