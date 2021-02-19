#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	size_t length;
	std::cin >> length;

	unsigned long long sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		unsigned long long num;
		std::cin >> num;
		sum += num;
	}

	std::cout << sum << '\n';

	return 0;
}
