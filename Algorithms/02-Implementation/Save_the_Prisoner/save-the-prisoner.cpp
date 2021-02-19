#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of testcases
	size_t testcases;
	std::cin >> testcases;

	for (size_t testcase = 0; testcase < testcases; testcase++)
	{
		int prisoners, sweets, start;
		std::cin >> prisoners >> sweets >> start;

		// print the number of the last prisoner to get a sweet
		std::cout << (sweets + start - 2) % prisoners + 1 << '\n';
	}
	
	return 0;
}