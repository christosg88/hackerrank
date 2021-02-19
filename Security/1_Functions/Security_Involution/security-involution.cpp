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

	bool is_involution = true;
	for (size_t i = 0; i < length; i++)
	{
		if (i + 1 != X[X[i] - 1])
		{
			is_involution = false;
			break;
		}
	}

	if (is_involution)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

	return 0;
}