#include <iostream>

int main()
{
	size_t length;
	std::cin >> length;

	int sum = 0;
	for (size_t i = 0; i < length; i++)
	{
		int num;
		std::cin >> num;
		sum += num;
	}

	std::cout << sum << '\n';

	return 0;
}