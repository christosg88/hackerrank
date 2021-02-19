#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);

	int x1, v1;
	int x2, v2;

	std::cin >> x1 >> v1 >> x2 >> v2;

	if (x1 == x2 || (v1 != v2 && (x1 - x2) / (v2 - v1) > 0 && (x1 - x2) % (v2 - v1) == 0))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";

	return 0;
}