#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of clouds
	size_t length;
	std::cin >> length;

	// storage for the clouds
	std::vector<int> clouds(length);
	for (size_t i = 0; i < length; i++)
		std::cin >> clouds[i];

	// the current index of the clouds
	size_t index = 0;
	// the total number of steps to go from the first to the last cloud
	size_t steps = 0;
	while (index != length - 1)
	{
		// if we are at the second to last cloud, one step remains
		if (index == length - 2)
		{
			steps += 1;
			index += 1;
		}
		// else if the second from index cloud is a thundercloud
		// we need a one-step jump and a two-step jump to continue
		else if (clouds[index + 2] == 1)
		{
			steps += 2;
			index += 3;
		}
		// else we make a two-step jump
		else
		{
			steps += 1;
			index += 2;
		}
	}

	std::cout << steps << '\n';

	return 0;
}