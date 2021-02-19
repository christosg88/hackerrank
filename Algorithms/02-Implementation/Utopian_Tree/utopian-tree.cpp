#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
	std::ios::sync_with_stdio(false);

	unsigned int testcases;
	std::cin >> testcases;

	while (testcases--)
	{
		unsigned int days;
		std::cin >> days;

		// from https://oeis.org/A075427
		std::cout << std::fixed << std::setprecision(0) << std::pow(2, (unsigned int)((days + 3) / 2)) + (0.5 - (days % 2)) - 1.5 << '\n';

		// hacker solution
		// return ~(~1 << (days >> 1)) << days % 2;
	}

	return 0;
}

