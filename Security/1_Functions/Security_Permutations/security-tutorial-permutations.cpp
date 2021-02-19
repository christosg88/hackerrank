#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);

	size_t length;
	std::cin >> length;
	std::vector<int> X;

	for (size_t i = 0; i < length; i++)
	{
		int tmp;
		std::cin >> tmp;
		X.push_back(tmp);
	}

	for (size_t i = 0; i < length; i++)
	{
		std::cout << X[X[i] - 1] << '\n';
	}

	return 0;
}