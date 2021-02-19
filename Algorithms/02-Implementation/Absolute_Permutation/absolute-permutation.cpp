#include <iostream>

void print_flipped_by(size_t N, size_t flip);

int main()
{
	std::ios::sync_with_stdio(false);
	
	size_t testcases;
	std::cin >> testcases;

	while (testcases--)
	{
		// the number of natural numbers
		size_t N;
		std::cin >> N;
		// the difference between i and pos(i)
		size_t K;
		std::cin >> K;

		if (K == 0)
		{
			for (size_t i = 1; i <= N; i++)
				std::cout << i << ' ';
			std::cout << '\n';
		}
		else if (N % 2 == 0 && N % K == 0 && (N / K) % 2 == 0)
		{
			print_flipped_by(N, K);
		}
		else
		{
			std::cout << "-1\n";
		}
	}

	return 0;
}

/// <summary>
/// Prints all natural numbers from 1 up to and including N, flipped by groups
/// of flip.
/// Example: N = 12, flip = 3
/// 4 5 6 1 2 3 10 11 12 7 8 9
/// Example: N = 12, flip = 2
/// 3 4 1 2 7 8 5 6 11 12 9 10
/// </summary>
/// <param name="N">The n.</param>
/// <param name="flip">The flip.</param>
void print_flipped_by(size_t N, size_t flip)
{
	for (size_t i = 0; i < N / (2 * flip); i++)
	{
		size_t start = flip * (2 * i + 1) + 1;
		
		for (size_t j = 0; j < flip; j++)
			std::cout << start + j << ' ';
		
		start -= flip;

		for (size_t j = 0; j < flip; j++)
			std::cout << start + j << ' ';
	}

	std::cout << '\n';
}