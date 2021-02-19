#include <iostream>
#include <cmath>

int main()
{
	std::ios::sync_with_stdio(false);

	unsigned int testcases;
	std::cin >> testcases;

	while (testcases--)
	{
		unsigned long num;
		std::cin >> num;

		unsigned int num_of_digits = (unsigned int) std::log10(num) + 1;
		unsigned int count_dividing_digits = 0;

		for (size_t i = 0; i < num_of_digits; i++)
		{
			unsigned int digit = (num / (unsigned long) std::pow(10, i)) % 10;
			if (digit != 0 && num % digit == 0)
				count_dividing_digits++;
		}
		std::cout << count_dividing_digits << '\n';
	}

	return 0;
}