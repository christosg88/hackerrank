#include <iostream>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);

	unsigned int testcases;
	std::cin >> testcases;

	while (testcases--)
	{
		unsigned long first, second;
		std::cin >> first >> second;

		std::cout << (unsigned long)std::sqrt(second) - (unsigned long)std::sqrt(first - 1) << '\n';
	}

	return 0;
}