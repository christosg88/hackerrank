#include <iostream>
#include <vector>
#include <algorithm>

bool form_triangle(size_t &a, size_t &b, size_t &c);

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of sticks
	size_t length;
	std::cin >> length;

	// a vector holding the lengths of the sticks
	std::vector<size_t> sticks(length);
	for (size_t i = 0; i < length; i++)
		std::cin >> sticks[i];

	// sort the lengths is descending order
	std::sort(sticks.begin(), sticks.end(),
		[](const size_t &a, const size_t &b)
		{
			return a > b;
		});

	for (size_t i = 0; i < length - 2; i++)
		for (size_t j = i + 1; j < length - 1; j++)
			for (size_t k = j + 1; k < length; k++)
				if (form_triangle(sticks[i], sticks[j], sticks[k]))
				{
					std::cout << sticks[k] << ' ' << sticks[j] << ' ' << sticks[i] << '\n';
					return 0;
				}

	std::cout << -1 << '\n';
	return 0;
}

/// <summary>
/// Checks if the three sides a, b and c can form a triangle.
/// </summary>
/// <param name="a">The length of the a side.</param>
/// <param name="b">The length of the b side.</param>
/// <param name="c">The length of the c side.</param>
/// <returns><c>true</c> if they can form a triangle; otherwise <c>false</c>.</returns>
bool form_triangle(size_t &a, size_t &b, size_t &c)
{
	return (a + b > c) && (a + c > b) && (b + c > a);
}