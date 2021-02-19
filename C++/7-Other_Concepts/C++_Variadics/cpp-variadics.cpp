#include <iostream>

template<bool digit>
int reversed_binary_value() {
    return (digit ? 1 : 0);
}

template<bool lsd, bool next_lsd, bool...digits>
int reversed_binary_value() {
    return (lsd ? 1 : 0) + (reversed_binary_value<next_lsd, digits...>() << 1);
};

template<int n, bool...digits>
struct CheckValues {
    static void check(int x, int y) {
        CheckValues<n - 1, false, digits...>::check(x, y);
        CheckValues<n - 1, true, digits...>::check(x, y);
    }
};

template<bool...digits>
struct CheckValues<0, digits...> {
    static void check(int x, int y) {
        int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x);
    }
};

int main() {
    long tests;
    std::cin >> tests;
    while (tests--) {
        int x, y;
        std::cin >> x >> y;
        CheckValues<6>::check(x, y);
        std::cout << "\n";
    }

    return 0;
}
