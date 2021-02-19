#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	int fact = 1;

	for (int i = n; i > 1; --i)
		fact *= i;

	std::cout << fact << '\n';

	return 0;
}