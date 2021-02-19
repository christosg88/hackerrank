#include <iostream>

enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template<typename T>
struct Traits;

template<>
struct Traits<Color> {
    static std::string name(int index) {
        if (index < 0 || index > 2) {
            return "unknown";
        }

        switch (static_cast<Color>(index)) {
            case Color::red:
                return "red";
            case Color::green:
                return "green";
            case Color::orange:
                return "orange";
            default:
                return "unknown";
        }
    }
};

template<>
struct Traits<Fruit> {
    static std::string name(int index) {
        if (index < 0 || index > 2) {
            return "unknown";
        }

        switch (static_cast<Fruit>(index)) {
            case Fruit::apple:
                return "apple";
            case Fruit::orange:
                return "orange";
            case Fruit::pear:
                return "pear";
            default:
                return "unknown";
        }
    }
};

int main() {
    size_t testcases;
    std::cin >> testcases;

    for (size_t test = 0; test < testcases; ++test) {
        int index1, index2;
        std::cin >> index1 >> index2;
        std::cout << Traits<Color>::name(index1) << " " << Traits<Fruit>::name(index2) << "\n";
    }

    return 0;
}
