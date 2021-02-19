#include <iostream>
#include <string>

std::string toEnglish(int num) {
    if (num == 1)
        return "one";
    else if (num == 2)
        return "two";
    else if (num == 3)
        return "three";
    else if (num == 4)
        return "four";
    else if (num == 5)
        return "five";
    else if (num == 6)
        return "six";
    else if (num == 7)
        return "seven";
    else if (num == 8)
        return "eight";
    else if (num == 9)
        return "nine";
    else
        return "Greater than 9";
}


int main() {
    std::ios::sync_with_stdio(false);

    int num;
    std::cin >> num;

    std::cout << toEnglish(num) << "\n";

    return 0;
}
