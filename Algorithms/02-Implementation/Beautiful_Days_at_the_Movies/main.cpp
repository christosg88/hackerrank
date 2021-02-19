#include <iostream>
#include <fstream>

int reverseNumber(int num) {
    int reverse_num = 0;
    while (num > 0) {
        reverse_num = reverse_num * 10 + num % 10;
        num /= 10;
    }

    return reverse_num;
}

int main() {
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int begin, end, divisor;
    std::cin >> begin >> end >> divisor;

    int count = 0;
    for (int num = begin; num <= end; ++num) {
        if (!(std::abs(num - reverseNumber(num)) % divisor)) {
            count++;
        }
    }

    fout << count << "\n";
    fout.close();

    return 0;
}
