#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	size_t height;
	std::cin >> height;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < height - i - 1; j++)
			std::cout << ' ';

		for (size_t j = 0; j < i + 1; j++)
			std::cout << '#';

		std::cout << '\n';
	}

	return 0;
}
