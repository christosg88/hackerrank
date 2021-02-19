#include <iostream>
#include <vector>

int main()
{
	std::ios::sync_with_stdio(false);

	// the number of foods ordered
	size_t foods;
	std::cin >> foods;
	// the index of the food Anna didn't eat
	size_t excluded;
	std::cin >> excluded;
	// the storage for the prices of the foods
	std::vector<int> prices(foods);
	for (size_t i = 0; i < foods; i++)
		std::cin >> prices[i];

	// the price Anna paid
	int paid;
	std::cin >> paid;

	// the price Anna should have paid
	int actual_price = 0;
	for (int &price : prices)
		actual_price += price;

	actual_price -= prices[excluded];

	actual_price /= 2;

	if (actual_price == paid)
		std::cout << "Bon Appetit\n";
	else
		std::cout << paid - actual_price << '\n';

	return 0;
}
