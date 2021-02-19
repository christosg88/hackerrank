#include <iostream>
#include <map>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);

	size_t length;
	std::cin >> length;

	std::map<unsigned int, std::vector<unsigned int>> indexes_of_nums;

	for (size_t i = 0; i < length; i++)
	{
		unsigned int num;
		std::cin >> num;
		indexes_of_nums[num].push_back(i);
	}

	bool at_least_one_pair = false;
	unsigned int min_distance = length;

	for (auto &pair : indexes_of_nums)
	{
		size_t vec_len = pair.second.size();
		if (vec_len >= 2)
		{
			at_least_one_pair = true;
			for (size_t i = 0; i < vec_len - 1; i++)
			{
				size_t distance = pair.second[i + 1] - pair.second[i];
				if (distance < min_distance)
					min_distance = distance;
			}
		}
	}

	if (at_least_one_pair)
		std::cout << min_distance << '\n';
	else
		std::cout << -1 << '\n';

	return 0;
}