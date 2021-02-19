#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	unsigned int people;
	std::cin >> people;

	unsigned int count_breads = 0;
	unsigned int carry = 0;

	for (size_t i = 0; i < people; i++)
	{
		unsigned int holding_breads;
		std::cin >> holding_breads;
		holding_breads += carry;

		carry = holding_breads % 2;
		if (carry == 1)
			count_breads += 2;
	}

	if (carry == 1)
		std::cout << "NO\n";
	else
		std::cout << count_breads << '\n';

	return 0;
}