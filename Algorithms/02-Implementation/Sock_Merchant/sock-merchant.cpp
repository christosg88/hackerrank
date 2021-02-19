#include <iostream>
#include <map>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of socks
	size_t length;
	std::cin >> length;

	// a map from the color of sock to the number of socks with that color
	std::map<int, int> socks;

	for (size_t i = 0; i < length; i++)
	{
		int color;
		std::cin >> color;
		socks[color]++;
	}

	size_t pairs = 0;
	for (auto pair : socks)
		pairs += pair.second / 2;

	std::cout << pairs << '\n';

	return 0;
}