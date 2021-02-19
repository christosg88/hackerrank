#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of clouds
	size_t num_clouds;
	std::cin >> num_clouds;

	// the length of the jump
	size_t jump;
	std::cin >> jump;

	// the vector holding the clouds
	// (0 represents a normal cloud while 1 a thunder-cloud)
	std::vector<int> clouds(num_clouds);
	for (size_t i = 0; i < num_clouds; i++)
		std::cin >> clouds[i];

	// the energy remaining
	int energy = 100;

	// the index of the cloud
	size_t index = 0;
	do
	{
		index = (index + jump) % num_clouds;
		// decrease the energy by 1 for the jump, and by another two of the
		// landing cloud is a thunder-cloud
		energy -= (1 + (clouds[index] * 2));
	} while (index != 0);

	std::cout << energy << '\n';

	return 0;
}