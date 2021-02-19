#include <iostream>
#include <iomanip>

int main() {
    std::ios_base::sync_with_stdio(false);

    int my_int;
    std::cin >> my_int;
    std::cout << my_int << '\n';

    long my_long;
    std::cin >> my_long;
    std::cout << my_long << '\n';

    long long my_long_long;
    std::cin >> my_long_long;
    std::cout << my_long_long << '\n';

    char my_char;
    std::cin >> my_char;
    std::cout << my_char << '\n';

    float my_float;
    std::cin >> my_float;
    std::cout << std::fixed << std::setprecision(3) << my_float << '\n';

    double my_double;
    std::cin >> my_double;
    std::cout << std::fixed << std::setprecision(9) << my_double << '\n';

    return 0;
}
