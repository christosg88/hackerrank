#include <iostream>
#include <cmath>

/*
	For info about the sum of geometric sequences visit:
	http://www.mathsisfun.com/algebra/sequences-sums-geometric.html
*/
int main()
{
	std::ios::sync_with_stdio(false);

	// read the seconds passed
	unsigned long long int seconds;
	std::cin >> seconds;

	// the cycle that this time belongs
	unsigned int cycle = std::log2((seconds / 3) + 1) + 1;

	// the total seconds passed at the end of this timer
	unsigned long long int end_time = 3 * (pow(2, cycle) - 1);

	// print the time shown, at time seconds
	std::cout << 1 + end_time - seconds << '\n';

	return 0;
}