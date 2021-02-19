#include <iostream>
#include <vector>

std::vector<int> get_inverse(std::vector<int> &X);

int main()
{
	std::ios_base::sync_with_stdio(false);

	size_t n;
	std::cin >> n;
	std::vector<int> X;

	for (size_t i = 0; i < n; i++)
	{
		int tmp;
		std::cin >> tmp;
		X.push_back(tmp);
	}

	std::vector<int> X_inverse = get_inverse(X);

	for (std::vector<int>::iterator it = X_inverse.begin(); it != X_inverse.end(); ++it)
		std::cout << *it << '\n';
	
	return 0;
}

std::vector<int> get_inverse(std::vector<int> &X)
{
	size_t length = X.size();
	std::vector<int> X_inverse(length, 0);

	for (size_t i = 0; i < length; i++)
	{
		X_inverse[X[i] - 1] = i + 1;
	}

	return X_inverse;
}