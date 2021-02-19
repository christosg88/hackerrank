#include <iostream>
#include <iomanip>

int main()
{
	std::ios::sync_with_stdio(false);

	size_t length;
	std::cin >> length;

	int count_pos = 0;
	int count_neg = 0;
	int count_zer = 0;

	for (size_t i = 0; i < length; i++)
	{
		int tmp;
		std::cin >> tmp;

		if (tmp > 0)
			count_pos++;
		else if (tmp < 0)
			count_neg++;
		else
			count_zer++;
	}

	std::cout << std::fixed << std::setprecision(6) << float(count_pos) / length << '\n';
	std::cout << std::fixed << std::setprecision(6) << float(count_neg) / length << '\n';
	std::cout << std::fixed << std::setprecision(6) << float(count_zer) / length << '\n';

	return 0;
}