#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    std::cin >> T;
    std::cout << setiosflags(ios::uppercase);
    std::cout << setw(0xf) << internal;
    while (T--)
    {
        double A, B, C;
        std::cin >> A >> B >> C;
        std::cout.setf(std::ios::showbase);
        std::cout.unsetf(std::ios::showpos);
        std::cout.unsetf(std::ios::uppercase);
        std::cout.setf(std::ios::hex, std::ios::basefield);
        std::cout.unsetf(std::ios::floatfield);
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout.width(0);
        std::cout << (unsigned long long) A << std::endl;

        std::cout.unsetf(std::ios::showbase);
        std::cout.setf(std::ios::showpos);
        std::cout.unsetf(std::ios::uppercase);
        std::cout.setf(std::ios::dec, std::ios::basefield);
        std::cout.setf(std::ios::fixed, std::ios::floatfield);
        std::cout.setf(std::ios::right, std::ios::adjustfield);
        std::cout.precision(2);
        std::cout.width(15);
        std::cout.fill('_');
        std::cout << B << std::endl;

        std::cout.unsetf(std::ios::showbase);
        std::cout.unsetf(std::ios::showpos);
        std::cout.setf(std::ios::uppercase);
        std::cout.setf(std::ios::dec, std::ios::basefield);
        std::cout.setf(std::ios::scientific, std::ios::floatfield);
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        std::cout.precision(9);
        std::cout.width(0);
        std::cout << C << std::endl;
    }

    return 0;
}
