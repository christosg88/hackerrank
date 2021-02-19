#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of sticks
	size_t length;
	std::cin >> length;

	// the lengths of the sticks
	std::vector<int> sticks(length);
	for (size_t i = 0; i < length; i++)
		std::cin >> sticks[i];

	while (length > 0)
	{
		// print the number of sticks cut
		std::cout << length << '\n';

		// the currently minimum length
		int min_length = *std::min_element(sticks.begin(), sticks.end());

		// cut all sticks with the minimum length
		for (size_t i = 0; i < length; i++)
			sticks[i] -= min_length;

		// erase all stocks that now have non-positive length
		for (std::vector<int>::iterator it = sticks.begin(); it != sticks.end(); )
		{
			if (*it <= 0)
			{
				it = sticks.erase(it);
				length--;
			}
			else
			{
				++it;
			}
		}
	}

	return 0;
}