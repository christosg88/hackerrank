#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);
	size_t dim;
	std::cin >> dim;

	std::vector<int> grid(dim * dim);

	for (size_t i = 0; i < dim; i++)
		for (size_t j = 0; j < dim; j++)
			std::cin >> grid[i*dim + j];

	int diagonal_sum = 0;
	int anti_diagonal_sum = 0;

	for (size_t i = 0; i < dim; i++)
	{
		diagonal_sum += grid[i*dim + i];
		anti_diagonal_sum += grid[(i + 1)*(dim - 1)];
	}

	std::cout << std::abs(diagonal_sum - anti_diagonal_sum) << '\n';

	return 0;
}