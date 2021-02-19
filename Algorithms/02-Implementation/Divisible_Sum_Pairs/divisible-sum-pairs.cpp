#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);

	// the length of the array
	size_t length;
	std::cin >> length;
	
	// the needed sum for the pairs
	int sum;
	std::cin >> sum;

	// read the numbers
	std::vector<int> nums(length);
	for (size_t i = 0; i < length; i++)
		std::cin >> nums[i];

	// n^2 algorithm to find all pairs
	int count = 0;
	for (size_t i = 0; i < length - 1; i++)
		for (size_t j = i + 1; j < length; j++)
			if ((nums[i] + nums[j]) % sum == 0)
				count++;

	std::cout << count << '\n';

	return 0;
}