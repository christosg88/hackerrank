#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	int tripletA[3];
	int tripletB[3];
	int pointsA = 0;
	int pointsB = 0;

	for (size_t i = 0; i < 3; i++)
		std::cin >> tripletA[i];
	for (size_t i = 0; i < 3; i++)
		std::cin >> tripletB[i];

	for (size_t i = 0; i < 3; i++)
	{
		if (tripletA[i] > tripletB[i])
			pointsA++;
		else if (tripletA[i] < tripletB[i])
			pointsB++;
	}

	std::cout << pointsA << ' ' << pointsB << '\n';

}